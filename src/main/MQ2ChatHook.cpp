/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"
#include "MQ2Main.h"

class CChatHook
{
public:
	// ChatManagerClient::DisplaychatText(
	void Trampoline(const char* szMsg, DWORD dwColor, bool, bool, CXStr* SomeStr);
	void Detour(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, CXStr* SomeStr)
	{
		gbInChat = true;
		if (dwColor != 269)
		{
			CheckChatForEvent(szMsg);
		}

		bool Filtered = false;
		MQFilter* Filter = gpFilters;

		while (Filter && !Filtered)
		{
			if (!Filter->pEnabled || *Filter->pEnabled)
			{
				if (*Filter->FilterText == '*')
				{
					if (strstr(szMsg, Filter->FilterText + 1))
						Filtered = true;
				}
				else
				{
					if (!_strnicmp(szMsg, Filter->FilterText, Filter->Length))
						Filtered = true;
				}
			}
			Filter = Filter->pNext;
		}

		if (!Filtered)
		{
			bool SkipTrampoline = false;
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, dwColor));

			if (!SkipTrampoline)
			{
				// don't need to anonymize system messages
				if (gAnonymize && dwColor != 269)
				{
					size_t len = strlen(szMsg) + 64;
					size_t namelen = 0;

					auto pAnonMsg = std::make_unique<char[]>(len);
					char* szAnonMsg = pAnonMsg.get();

					if (pLocalPlayer)
					{
						char myName[40];
						strcpy_s(myName, ((PSPAWNINFO)pLocalPlayer)->Name);
						namelen = strlen(myName);

						strcpy_s(szAnonMsg, len, szMsg);

						while (strstr(szAnonMsg, myName))
						{
							if (char* p = strstr(szAnonMsg, myName))
							{
								for (size_t i = 1; i < namelen - 1; i++)
								{
									p[i] = '*';
								}
							}
						}
					}

					// TODO: Fix this case for when pLocalPlayer is null.
					if (char* pDest = strchr(szAnonMsg, ' '))
					{
						int len = strlen(szAnonMsg) - strlen(pDest);
						if (len >= 2)
						{
							if (szAnonMsg[0] == 0x12)
							{
								for (int i = 3; i < len - 2; i++)
								{
									szAnonMsg[i] = '*';
								}
							}
							else
							{
								if (strstr(szAnonMsg, "You have healed "))
								{
									for (size_t i = 17; i < 17 + namelen - 1; i++)
									{
										szAnonMsg[i] = '*';
									}
								}
								else if (_strnicmp(szAnonMsg, "you ", 4) && _strnicmp(szAnonMsg, "your ", 5))
								{
									for (int i = 1; i < len - 1; i++)
									{
										szAnonMsg[i] = '*';
									}
								}
							}
						}
					}

					Trampoline(szAnonMsg, dwColor, EqLog, dopercentsubst, SomeStr);
				}
				else
				{
					Trampoline(szMsg, dwColor, EqLog, dopercentsubst, SomeStr);
				}
			}
		}

		gbInChat = false;
	}

	// ChatManagerClient::DisplayTellText
	void TellWnd_Trampoline(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk);
	void TellWnd_Detour(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk)
	{
		gbInChat = true;
		bool SkipTrampoline = false;

		int len = strlen(message) + 64;
		auto pBuffer = std::make_unique<char[]>(len);
		char* szMsg = pBuffer.get();

		if (szMsg)
		{
			sprintf_s(szMsg, len, "%s tells you, '%s'", from, message);
			CheckChatForEvent(szMsg);
			Benchmark(bmPluginsIncomingChat, SkipTrampoline = PluginsIncomingChat(szMsg, color));
		}

		if (!SkipTrampoline)
		{
			if (gAnonymize)
			{
				char szNameCopy[64];
				strcpy_s(szNameCopy, 64, from);
				Anonymize(szNameCopy, 64);

				TellWnd_Trampoline(message, szNameCopy, szNameCopy, text, color, bLogOk);
			}
			else
			{
				TellWnd_Trampoline(message, from, windowtitle, text, color, bLogOk);
			}
		}

		gbInChat = false;
	}

	// CEverQuest::UniversalChatProxyNotificationFlush
	void UPCNotificationFlush_Trampoline();
	void UPCNotificationFlush_Detour()
	{
		EVERQUEST* eq = (EVERQUEST*)this;

		char szBuf[128] = { 0 };

		if (eq->ChannelQty > 0)
		{
			sprintf_s(szBuf, "* %s has %s channel ", eq->ChannelPlayerName, eq->bJoinedChannel ? "entered" : "left");

			char szTemp[MAX_STRING] = { 0 };
			int max = std::min<int>(eq->ChannelQty, 9);

			for (int index = 0; index < max; index++)
			{
				if (index)
				{
					sprintf_s(szTemp, ", %s:%d", eq->ChannelName[index], eq->ChannelNumber[index] + 1);
				}
				else
				{
					sprintf_s(szTemp, "%s:%d", eq->ChannelName[index], eq->ChannelNumber[index] + 1);
				}

				strcat_s(szBuf, szTemp);
			}

			CheckChatForEvent(szBuf);
		}

		UPCNotificationFlush_Trampoline();
	}
};

DETOUR_TRAMPOLINE_EMPTY(void CChatHook::Trampoline(const char* szMsg, DWORD dwColor, bool EqLog, bool dopercentsubst, CXStr* outStr));
DETOUR_TRAMPOLINE_EMPTY(void CChatHook::TellWnd_Trampoline(const char* message, const char* from, const char* windowtitle, const char* text, int color, bool bLogOk));
DETOUR_TRAMPOLINE_EMPTY(void CChatHook::UPCNotificationFlush_Trampoline());

void dsp_chat_no_events(const char* Text, int Color, bool doLog, bool doPercentConvert)
{
	((CChatHook*)pEverQuest)->Trampoline(Text, Color, doLog, doPercentConvert, nullptr);
}

unsigned int CALLBACK MQ2DataVariableLookup(char* VarName, char* Value, size_t ValueLen)
{
	strcpy_s(Value, ValueLen, VarName);

	if (PCHARINFO pChar = GetCharInfo())
	{
		return strlen(ParseMacroParameter(pChar->pSpawn, Value, ValueLen));
	}

	return strlen(Value);
}

void FlashOnTells(PSPAWNINFO pChar, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbFlashOnTells = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbFlashOnTells = true;
		}
	}

	if (gbFlashOnTells)
	{
		gbFlashOnTells = false;
		WriteChatColor("Flash On Tells is OFF", CONCOLOR_LIGHTBLUE);

		WritePrivateProfileString("MacroQuest", "FlashOnTells", "0", gszINIFilename);
	}
	else
	{
		gbFlashOnTells = true;
		WriteChatColor("Flash On Tells is ON", CONCOLOR_YELLOW);

		WritePrivateProfileString("MacroQuest", "FlashOnTells", "1", gszINIFilename);
	}
}

void BeepOnTells(PSPAWNINFO pChar, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbBeepOnTells = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbBeepOnTells = true;
		}
	}

	if (gbBeepOnTells)
	{
		gbBeepOnTells = false;
		WriteChatColor("Beep On Tells is OFF", CONCOLOR_LIGHTBLUE);
		WritePrivateProfileString("MacroQuest", "BeepOnTells", "0", gszINIFilename);
	}
	else
	{
		gbBeepOnTells = true;
		WriteChatColor("Beep On Tells is ON", CONCOLOR_YELLOW);
		WritePrivateProfileString("MacroQuest", "BeepOnTells", "1", gszINIFilename);
	}
}

void TimeStampChat(PSPAWNINFO pChar, char* szLine)
{
	if (szLine[0] != '\0')
	{
		if (!_stricmp(szLine, "on"))
		{
			gbTimeStampChat = false;
		}
		else if (!_stricmp(szLine, "off"))
		{
			gbTimeStampChat = true;
		}
	}

	if (gbTimeStampChat)
	{
		gbTimeStampChat = false;
		WriteChatColor("Chat Time Stamping is OFF", CONCOLOR_LIGHTBLUE);

		WritePrivateProfileString("MacroQuest", "TimeStampChat", "0", gszINIFilename);
	}
	else
	{
		gbTimeStampChat = true;
		WriteChatColor("Chat Time Stamping is ON", CONCOLOR_YELLOW);

		WritePrivateProfileString("MacroQuest", "TimeStampChat", "1", gszINIFilename);
	}
}

void InitializeChatHook()
{
	// initialize Blech
	pEventBlech = new Blech('#', '|', MQ2DataVariableLookup);
	pMQ2Blech = new Blech('#', '|', MQ2DataVariableLookup);

	EzDetourwName(CEverQuest__dsp_chat, &CChatHook::Detour, &CChatHook::Trampoline, "CEverQuest__dsp_chat");
	EzDetourwName(CEverQuest__DoTellWindow, &CChatHook::TellWnd_Detour, &CChatHook::TellWnd_Trampoline, "CEverQuest__DoTellWindow");
	EzDetourwName(CEverQuest__UPCNotificationFlush, &CChatHook::UPCNotificationFlush_Detour, &CChatHook::UPCNotificationFlush_Trampoline, "CEverQuest__UPCNotificationFlush");
	AddCommand("/timestamp", TimeStampChat);
	AddCommand("/beepontells", BeepOnTells);
	AddCommand("/flashontells", FlashOnTells);
}

void ShutdownChatHook()
{
	RemoveCommand("/flashontells");
	RemoveCommand("/beepontells");
	RemoveCommand("/timestamp");
	RemoveDetour(CEverQuest__dsp_chat);
	RemoveDetour(CEverQuest__DoTellWindow);
	RemoveDetour(CEverQuest__UPCNotificationFlush);

	delete pEventBlech;
	pEventBlech = nullptr;
	delete pMQ2Blech;
	pMQ2Blech = nullptr;
}
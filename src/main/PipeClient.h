/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#pragma once

#include "MQ2MainBase.h"
#include "common/Mailbox.h"
#include "common/ProtoPipes.h"

namespace mq {

void InitializePipeClient();
void ShutdownPipeClient();

namespace pipeclient {

MQLIB_API void NotifyCharacterLoad(const char* Profile, const char* Account, const char* Server, const char* Character);
MQLIB_API void NotifyCharacterUnload(const char* Profile, const char* Account, const char* Server, const char* Character);
MQLIB_API void NotifyCharacterUpdate(int Class, int Level);
MQLIB_API void LoginServer(const char* Login, const char* Pass, const char* Server);
MQLIB_API void LoginCharacter(const char* Login, const char* Pass, const char* Server, const char* Character);
MQLIB_API void LoginProfile(const char* Profile, const char* Server, const char* Character);

MQLIB_API uint32_t GetLauncherProcessID();

void NotifyIsForegroundWindow(bool isForeground);
void RequestActivateWindow(HWND hWnd, bool sendMessage = true);

using PipeClientPO = mailbox::PostOffice<PipeMessagePtr>;
template <typename MessageType>
bool AddMailbox(
	const std::string& localAddress,
	PipeClientPO::ParseCallback<MessageType> deliver,
	PipeClientPO::ReceiveCallback<MessageType> receive)
{
	AddMailbox(localAddress, PipeClientPO::CreateMailbox(localAddress, deliver, receive));
}

MQLIB_OBJECT bool AddMailbox(const std::string& localAddress, std::unique_ptr<PipeClientPO::MailboxConcept>&& mailbox);
MQLIB_OBJECT bool RemoveMailbox(const std::string& localAddress);

} // namespace pipeclient

} // namespace mq

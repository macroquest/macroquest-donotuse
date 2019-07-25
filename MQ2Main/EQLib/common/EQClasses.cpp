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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "EQClasses.h"
#include "Globals.h"

// Nothing apart from FUNCTION_AT_ADDRESS call should go into this file!

#pragma warning(push)
#pragma warning(disable:4740) // warning C4740: flow in or out of inline asm code suppresses global optimization
#pragma warning(disable:4530) // warning C4530: c++ exception handler used, but unwind semantics are not enabled. Specify /EHsc

// MANUAL IMPORTS
#ifdef __IsResEffectSpell_x
FUNCTION_AT_ADDRESS(bool IsResEffectSpell(int), __IsResEffectSpell);
#endif
#ifdef __ExecuteCmd_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(BOOL __cdecl EQExecuteCmd(DWORD arg1, BOOL arg2, PVOID arg3, BOOL arg4), __ExecuteCmd);
#else
FUNCTION_AT_ADDRESS(BOOL __cdecl EQExecuteCmd(DWORD arg1, BOOL arg2, PVOID arg3), __ExecuteCmd);
#endif
#endif
#ifdef EQ_Item__CreateItemTagString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char* EQ_Item::CreateItemTagString(char*, int, bool), EQ_Item__CreateItemTagString);
#else
FUNCTION_AT_ADDRESS(char* EQ_Item::CreateItemTagString(char*, int), EQ_Item__CreateItemTagString);
#endif
#endif
#ifdef EQ_Item__GetImageNum_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetImageNum() const, EQ_Item__GetImageNum);
#endif
#ifdef EQ_Item__CreateItemClient_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> EQ_Item::CreateItemClient(PBYTE*, DWORD), EQ_Item__CreateItemClient);
#endif
#ifdef CStmlWnd__AppendSTML_x
FUNCTION_AT_ADDRESS(CXSize CStmlWnd::AppendSTML(CXStr), CStmlWnd__AppendSTML);
#endif
#ifdef EQ_Item__CanDrop_x
FUNCTION_AT_ADDRESS(bool EQ_Item::CanDrop(bool, bool, bool, bool) const, EQ_Item__CanDrop);
#endif
#ifdef EQ_Character__Max_Endurance_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Endurance(bool), EQ_Character__Max_Endurance);
#endif
#ifdef EQ_Character__Max_Mana_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Mana(bool), EQ_Character__Max_Mana);
#endif 
#ifdef EQ_Character__Max_HP_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_HP(int, bool), EQ_Character__Max_HP);
#endif
#ifdef EQ_Character__doCombatAbility_x
FUNCTION_AT_ADDRESS(bool EQ_Character::DoCombatAbility(int spellID, int dummy), EQ_Character__doCombatAbility); 
#endif 

FUNCTION_AT_VIRTUAL_ADDRESS(float ActorBase::GetBoundingRadius(), 0x60);

FUNCTION_AT_VIRTUAL_ADDRESS(void CChatWindow::operator delete[](void*), 0x4);

#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::DeleteAll(), 0x17c);        // see CComboWnd__DeleteAll_x
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::Sort(), 0x184);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTotalDuration() const, 0x18c);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTimeRemaining() const, 0x190);
#else
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::DeleteAll(), 0x180);       // see CComboWnd__DeleteAll_x
FUNCTION_AT_VIRTUAL_ADDRESS(void CListWnd::Sort(), 0x188);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTotalDuration() const, 0x190);
FUNCTION_AT_VIRTUAL_ADDRESS(UINT CButtonWnd::GetCoolDownTimeRemaining() const, 0x194);
#endif

// ClientSpellManager
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::LoadSpells(const char*, const char*, const char*), 0x04);
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::LoadSpellStackingData(const char*), 0x08);
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_VIRTUAL_ADDRESS(void ClientSpellManager::PrintFailedRequirementString(int, int), 0x0c);
FUNCTION_AT_VIRTUAL_ADDRESS(int ClientSpellManager::GetSpellStackingGroupID(int), 0x10);
FUNCTION_AT_VIRTUAL_ADDRESS(int ClientSpellManager::GetSpellStackingGroupRank(int), 0x14);
FUNCTION_AT_VIRTUAL_ADDRESS(ESpellStackingRules ClientSpellManager::GetSpellStackingGroupRule(int), 0x18);
FUNCTION_AT_VIRTUAL_ADDRESS(PSPELL ClientSpellManager::GetSpellByID(int), 0x1c);
FUNCTION_AT_VIRTUAL_ADDRESS(SPELLCALCINFO* ClientSpellManager::GetSpellAffect(int), 0x20);
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::GetSpellAffectEmpty(bool), 0x24);
#else
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::DoesMeetRequirement(PlayerZoneClient*, int), 0x0c);
FUNCTION_AT_VIRTUAL_ADDRESS(void ClientSpellManager::PrintFailedRequirementString(int, int), 0x10);
FUNCTION_AT_VIRTUAL_ADDRESS(int ClientSpellManager::GetSpellStackingGroupID(int), 0x14);
FUNCTION_AT_VIRTUAL_ADDRESS(int ClientSpellManager::GetSpellStackingGroupRank(int), 0x18);
FUNCTION_AT_VIRTUAL_ADDRESS(ESpellStackingRules ClientSpellManager::GetSpellStackingGroupRule(int), 0x1c);
FUNCTION_AT_VIRTUAL_ADDRESS(PSPELL ClientSpellManager::GetSpellByID(int), 0x20);
FUNCTION_AT_VIRTUAL_ADDRESS(SPELLCALCINFO* ClientSpellManager::GetSpellAffect(int), 0x24);
FUNCTION_AT_VIRTUAL_ADDRESS(bool ClientSpellManager::GetSpellAffectEmpty(bool), 0x28);
#endif

// AUTO IMPORTS
#ifdef CAAWnd__CAAWnd_x
FUNCTION_AT_ADDRESS(CAAWnd::CAAWnd(CXWnd*), CAAWnd__CAAWnd);
#endif
#ifdef CAAWnd__Update_x
FUNCTION_AT_ADDRESS(void CAAWnd::Update(), CAAWnd__Update);
#endif
#ifdef CAAWnd__UpdateSelected_x
FUNCTION_AT_ADDRESS(void CAAWnd::UpdateSelected(), CAAWnd__UpdateSelected);
#endif
#ifdef CAAWnd__UpdateTimer_x
FUNCTION_AT_ADDRESS(void CAAWnd::UpdateTimer(), CAAWnd__UpdateTimer);
#endif
#ifdef CAAWnd__Init_x
FUNCTION_AT_ADDRESS(void CAAWnd::Init(), CAAWnd__Init);
#endif
#ifdef CAAWnd__Activate_x
FUNCTION_AT_ADDRESS(void CAAWnd::Activate(), CAAWnd__Activate);
#endif
#ifdef CAAWnd__ShowAbility_x
FUNCTION_AT_ADDRESS(void CAAWnd::ShowAbility(int), CAAWnd__ShowAbility);
#endif
#ifdef CAAWnd__SendNewPercent_x
FUNCTION_AT_ADDRESS(void CAAWnd::SendNewPercent(), CAAWnd__SendNewPercent);
#endif
#ifdef CAAWnd__ConfirmAASpend_x
FUNCTION_AT_ADDRESS(void CAAWnd::ConfirmAASpend(), CAAWnd__ConfirmAASpend);
#endif
#ifdef CUITextureInfo__CUITextureInfo_x
FUNCTION_AT_ADDRESS(CUITextureInfo::CUITextureInfo(CXStr, int), CUITextureInfo__CUITextureInfo);
#endif
#ifdef CXMLSOMNodePtr__dCXMLSOMNodePtr_x
FUNCTION_AT_ADDRESS(CXMLSOMNodePtr::~CXMLSOMNodePtr(), CXMLSOMNodePtr__dCXMLSOMNodePtr);
#endif
#ifdef CXMLSOMNode__dCXMLSOMNode_x
FUNCTION_AT_ADDRESS(CXMLSOMNode::~CXMLSOMNode(), CXMLSOMNode__dCXMLSOMNode);
#endif
#ifdef CXMLSOMAttribute__dCXMLSOMAttribute_x
FUNCTION_AT_ADDRESS(CXMLSOMAttribute::~CXMLSOMAttribute(), CXMLSOMAttribute__dCXMLSOMAttribute);
#endif
#ifdef CActionsWnd__CActionsWnd_x
FUNCTION_AT_ADDRESS(CActionsWnd::CActionsWnd(CXWnd*), CActionsWnd__CActionsWnd);
#endif
#ifdef CActionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void CActionsWnd::Activate(int), CActionsWnd__Activate);
#endif
#ifdef CActionsWnd__UpdateButtonText_x
FUNCTION_AT_ADDRESS(void CActionsWnd::UpdateButtonText(), CActionsWnd__UpdateButtonText);
#endif
#ifdef CActionsWnd__GetCurrentPageEnum_x
FUNCTION_AT_ADDRESS(int CActionsWnd::GetCurrentPageEnum() const, CActionsWnd__GetCurrentPageEnum);
#endif
#ifdef CActionsWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CActionsWnd::KeyMapUpdated(), CActionsWnd__KeyMapUpdated);
#endif
#ifdef CActionsWnd__SelectSkillForAbilityBtn_x
FUNCTION_AT_ADDRESS(void CActionsWnd::SelectSkillForAbilityBtn(int), CActionsWnd__SelectSkillForAbilityBtn);
#endif
#ifdef CActionsWnd__GetAbilityBtn_x
FUNCTION_AT_ADDRESS(CButtonWnd* CActionsWnd::GetAbilityBtn(int), CActionsWnd__GetAbilityBtn);
#endif
#ifdef CActionsWnd__SelectSkillForCombatBtn_x
FUNCTION_AT_ADDRESS(void CActionsWnd::SelectSkillForCombatBtn(int), CActionsWnd__SelectSkillForCombatBtn);
#endif
#ifdef CActionsWnd__GetCombatBtn_x
FUNCTION_AT_ADDRESS(CButtonWnd* CActionsWnd::GetCombatBtn(int), CActionsWnd__GetCombatBtn);
#endif
#ifdef CActionsWnd__GetMenuBtn_x
FUNCTION_AT_ADDRESS(CButtonWnd* CActionsWnd::GetMenuBtn(int), CActionsWnd__GetMenuBtn);
#endif
#ifdef CActionsWnd__RedirectActivateTo_x
FUNCTION_AT_ADDRESS(int CActionsWnd::RedirectActivateTo(CPageWnd*), CActionsWnd__RedirectActivateTo);
#endif
#ifdef CActionsWnd__RedirectDeactivateTo_x
FUNCTION_AT_ADDRESS(int CActionsWnd::RedirectDeactivateTo(CPageWnd*), CActionsWnd__RedirectDeactivateTo);
#endif
#ifdef CActionsWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int CActionsWnd::RedirectOnProcessFrameTo(CPageWnd*), CActionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CActionsWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int CActionsWnd::RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*), CActionsWnd__RedirectWndNotificationTo);
#endif
#ifdef CActionsWnd__MainPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageOnProcessFrame(), CActionsWnd__MainPageOnProcessFrame);
#endif
#ifdef CActionsWnd__MainPageWndNotification_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageWndNotification(CXWnd*, uint32_t, void*), CActionsWnd__MainPageWndNotification);
#endif
#ifdef CActionsWnd__AbilitiesPageActivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::AbilitiesPageActivate(), CActionsWnd__AbilitiesPageActivate);
#endif
#ifdef CActionsWnd__AbilitiesPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::AbilitiesPageDeactivate(), CActionsWnd__AbilitiesPageDeactivate);
#endif
#ifdef CActionsWnd__AbilitiesPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CActionsWnd::AbilitiesPageOnProcessFrame(), CActionsWnd__AbilitiesPageOnProcessFrame);
#endif
#ifdef CActionsWnd__AbilitiesPageWndNotification_x
FUNCTION_AT_ADDRESS(int CActionsWnd::AbilitiesPageWndNotification(CXWnd*, uint32_t, void*), CActionsWnd__AbilitiesPageWndNotification);
#endif
#ifdef CActionsWnd__CombatPageActivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::CombatPageActivate(), CActionsWnd__CombatPageActivate);
#endif
#ifdef CActionsWnd__CombatPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::CombatPageDeactivate(), CActionsWnd__CombatPageDeactivate);
#endif
#ifdef CActionsWnd__CombatPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CActionsWnd::CombatPageOnProcessFrame(), CActionsWnd__CombatPageOnProcessFrame);
#endif
#ifdef CActionsWnd__CombatPageWndNotification_x
FUNCTION_AT_ADDRESS(int CActionsWnd::CombatPageWndNotification(CXWnd*, uint32_t, void*), CActionsWnd__CombatPageWndNotification);
#endif
#ifdef CActionsWnd__SocialsPageActivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::SocialsPageActivate(), CActionsWnd__SocialsPageActivate);
#endif
#ifdef CActionsWnd__SocialsPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CActionsWnd::SocialsPageOnProcessFrame(), CActionsWnd__SocialsPageOnProcessFrame);
#endif
#ifdef CActionsWnd__SocialsPageWndNotification_x
FUNCTION_AT_ADDRESS(int CActionsWnd::SocialsPageWndNotification(CXWnd*, uint32_t, void*), CActionsWnd__SocialsPageWndNotification);
#endif
#ifdef CAlarmWnd__CAlarmWnd_x
FUNCTION_AT_ADDRESS(CAlarmWnd::CAlarmWnd(CXWnd*), CAlarmWnd__CAlarmWnd);
#endif
#ifdef CAlarmWnd__Activate_x
FUNCTION_AT_ADDRESS(void CAlarmWnd::Activate(), CAlarmWnd__Activate);
#endif
#ifdef CAlarmWnd__DoNeverButton_x
FUNCTION_AT_ADDRESS(void CAlarmWnd::DoNeverButton(), CAlarmWnd__DoNeverButton);
#endif
#ifdef CEditBaseWnd__SetMaxChars_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetMaxChars(int), CEditBaseWnd__SetMaxChars);
#endif
#ifdef CBankWnd__CBankWnd_x
FUNCTION_AT_ADDRESS(CBankWnd::CBankWnd(CXWnd*, CXStr), CBankWnd__CBankWnd);
#endif
#ifdef CBankWnd__Init_x
FUNCTION_AT_ADDRESS(void CBankWnd::Init(), CBankWnd__Init);
#endif
#ifdef CBankWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBankWnd::Activate(EQPlayer*), CBankWnd__Activate);
#endif
#ifdef CBankWnd__Deactivate_x
FUNCTION_AT_ADDRESS(void CBankWnd::Deactivate(bool), CBankWnd__Deactivate);
#endif
#ifdef CBankWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CBankWnd::ClickedMoneyButton(int, int), CBankWnd__ClickedMoneyButton);
#endif
#ifdef CBankWnd__GetBankQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CBankWnd::GetBankQtyFromCoinType(int), CBankWnd__GetBankQtyFromCoinType);
#endif
#ifdef CBankWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void CBankWnd::UpdateMoneyDisplay(), CBankWnd__UpdateMoneyDisplay);
#endif
#ifdef CBankWnd__GetNumBankSlots_x
FUNCTION_AT_ADDRESS(int CBankWnd::GetNumBankSlots() const, CBankWnd__GetNumBankSlots);
#endif
#ifdef CXRect__CenterPoint_x
FUNCTION_AT_ADDRESS(CXPoint CXRect::CenterPoint() const, CXRect__CenterPoint);
#endif
#ifdef CBazaarSearchWnd__CBazaarSearchWnd_x
FUNCTION_AT_ADDRESS(CBazaarSearchWnd::CBazaarSearchWnd(CXWnd*), CBazaarSearchWnd__CBazaarSearchWnd);
#endif
#ifdef CBazaarSearchWnd__InitListArray_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::InitListArray(), CBazaarSearchWnd__InitListArray);
#endif
#ifdef CBazaarSearchWnd__Init_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::Init(), CBazaarSearchWnd__Init);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerUpdateButton_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdatePlayerUpdateButton(bool), CBazaarSearchWnd__UpdatePlayerUpdateButton);
#endif
#ifdef CBazaarSearchWnd__UpdatePlayerCombo_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdatePlayerCombo(), CBazaarSearchWnd__UpdatePlayerCombo);
#endif
#ifdef CBazaarSearchWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::Activate(), CBazaarSearchWnd__Activate);
#endif
#ifdef CBazaarSearchWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char* CBazaarSearchWnd::GetPriceString(unsigned long), CBazaarSearchWnd__GetPriceString);
#endif
#ifdef CBazaarSearchWnd__SortItemList_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::SortItemList(int), CBazaarSearchWnd__SortItemList);
#endif
#ifdef CBazaarSearchWnd__AddItemtoList_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::AddItemtoList(char*, unsigned long, char*, int, int), CBazaarSearchWnd__AddItemtoList);
#endif
#ifdef CBazaarSearchWnd__UpdateComboButtons_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::UpdateComboButtons(), CBazaarSearchWnd__UpdateComboButtons);
#endif
#ifdef CBazaarSearchWnd__HandleBazaarMsg_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::HandleBazaarMsg(char*, int), CBazaarSearchWnd__HandleBazaarMsg);
#endif
#ifdef CBazaarSearchWnd__doQuery_x
FUNCTION_AT_ADDRESS(void CBazaarSearchWnd::doQuery(), CBazaarSearchWnd__doQuery);
#endif
#ifdef CBazaarWnd__CBazaarWnd_x
FUNCTION_AT_ADDRESS(CBazaarWnd::CBazaarWnd(CXWnd*), CBazaarWnd__CBazaarWnd);
#endif
#ifdef CBazaarWnd__Init_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::Init(), CBazaarWnd__Init);
#endif
#ifdef CBazaarWnd__CreateBZRIniFilename_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::CreateBZRIniFilename(), CBazaarWnd__CreateBZRIniFilename);
#endif
#ifdef CBazaarWnd__AddBazaarText_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::AddBazaarText(char*, int), CBazaarWnd__AddBazaarText);
#endif
#ifdef CBazaarWnd__ReturnItemByIndex_x
FUNCTION_AT_ADDRESS(EQ_Item* CBazaarWnd::ReturnItemByIndex(int), CBazaarWnd__ReturnItemByIndex);
#endif
#ifdef CBazaarWnd__GetPriceString_x
FUNCTION_AT_ADDRESS(char* CBazaarWnd::GetPriceString(unsigned long), CBazaarWnd__GetPriceString);
#endif
#ifdef CBazaarWnd__HandleTraderMsg_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::HandleTraderMsg(char*), CBazaarWnd__HandleTraderMsg);
#endif
#ifdef CBazaarWnd__RebuildItemArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::RebuildItemArray(), CBazaarWnd__RebuildItemArray);
#endif
#ifdef CBazaarWnd__BuildBazaarItemArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::BuildBazaarItemArray(), CBazaarWnd__BuildBazaarItemArray);
#endif
#ifdef CBazaarWnd__AddEquipmentToBazaarArray_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::AddEquipmentToBazaarArray(EQ_Item*, int, unsigned long), CBazaarWnd__AddEquipmentToBazaarArray);
#endif
#ifdef CBazaarWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::Activate(), CBazaarWnd__Activate);
#endif
#ifdef CBazaarWnd__UpdatePriceButtons_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::UpdatePriceButtons(), CBazaarWnd__UpdatePriceButtons);
#endif
#ifdef CBazaarWnd__StoreSelectedPrice_x
FUNCTION_AT_ADDRESS(bool CBazaarWnd::StoreSelectedPrice(), CBazaarWnd__StoreSelectedPrice);
#endif
#ifdef CBazaarWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::UpdateButtons(), CBazaarWnd__UpdateButtons);
#endif
#ifdef CBazaarWnd__SelectBazaarSlotItem_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::SelectBazaarSlotItem(int, CTextureAnimation*), CBazaarWnd__SelectBazaarSlotItem);
#endif
#ifdef CBazaarWnd__SetMoneyButton_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::SetMoneyButton(int, int), CBazaarWnd__SetMoneyButton);
#endif
#ifdef CBazaarWnd__GetQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CBazaarWnd::GetQtyFromCoinType(int), CBazaarWnd__GetQtyFromCoinType);
#endif
#ifdef CBazaarWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::ClickedMoneyButton(int, int), CBazaarWnd__ClickedMoneyButton);
#endif
#ifdef CBazaarWnd__GetPrice_x
FUNCTION_AT_ADDRESS(unsigned long CBazaarWnd::GetPrice(), CBazaarWnd__GetPrice);
#endif
#ifdef CBazaarWnd__UpdateBazaarListtoServer_x
FUNCTION_AT_ADDRESS(int CBazaarWnd::UpdateBazaarListtoServer(), CBazaarWnd__UpdateBazaarListtoServer);
#endif
#ifdef CBazaarWnd__ToggleBzrItemActive_x
FUNCTION_AT_ADDRESS(void CBazaarWnd::ToggleBzrItemActive(int, bool), CBazaarWnd__ToggleBzrItemActive);
#endif
#ifdef CBodyTintWnd__CBodyTintWnd_x
FUNCTION_AT_ADDRESS(CBodyTintWnd::CBodyTintWnd(CXWnd*), CBodyTintWnd__CBodyTintWnd);
#endif
#ifdef CBodyTintWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::Activate(), CBodyTintWnd__Activate);
#endif
#ifdef CBodyTintWnd__GetTintChangeCount_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::GetTintChangeCount(), CBodyTintWnd__GetTintChangeCount);
#endif
#ifdef CBodyTintWnd__GetReagentCount_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::GetReagentCount(), CBodyTintWnd__GetReagentCount);
#endif
#ifdef CBodyTintWnd__BuildRBGTooltip_x
FUNCTION_AT_ADDRESS(char* CBodyTintWnd::BuildRBGTooltip(unsigned long, char* const), CBodyTintWnd__BuildRBGTooltip);
#endif
#ifdef CBodyTintWnd__GetItemTint_x
FUNCTION_AT_ADDRESS(unsigned long CBodyTintWnd::GetItemTint(int), CBodyTintWnd__GetItemTint);
#endif
#ifdef CBodyTintWnd__SetSlotLabels_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::SetSlotLabels(bool), CBodyTintWnd__SetSlotLabels);
#endif
#ifdef CBodyTintWnd__UpdateLocalTintColor_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateLocalTintColor(unsigned long), CBodyTintWnd__UpdateLocalTintColor);
#endif
#ifdef CBodyTintWnd__UpdateMaterialTintLocal_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateMaterialTintLocal(unsigned long), CBodyTintWnd__UpdateMaterialTintLocal);
#endif
#ifdef CBodyTintWnd__UpdateLabelsAndButtons_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::UpdateLabelsAndButtons(), CBodyTintWnd__UpdateLabelsAndButtons);
#endif
#ifdef CBodyTintWnd__GetButtonTint_x
FUNCTION_AT_ADDRESS(unsigned long CBodyTintWnd::GetButtonTint(int), CBodyTintWnd__GetButtonTint);
#endif
#ifdef CBodyTintWnd__StoreModifiedBodyTints_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::StoreModifiedBodyTints(), CBodyTintWnd__StoreModifiedBodyTints);
#endif
#ifdef CBodyTintWnd__ResetToOrigBodyTints_x
FUNCTION_AT_ADDRESS(void CBodyTintWnd::ResetToOrigBodyTints(), CBodyTintWnd__ResetToOrigBodyTints);
#endif
#ifdef CBookWnd__CBookWnd_x
FUNCTION_AT_ADDRESS(CBookWnd::CBookWnd(CXWnd*), CBookWnd__CBookWnd);
#endif
#ifdef CBookWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBookWnd::Activate(), CBookWnd__Activate);
#endif
#ifdef CBookWnd__SetBook_x
FUNCTION_AT_ADDRESS(void CBookWnd::SetBook(char*), CBookWnd__SetBook);
#endif
#ifdef CBookWnd__CheckBook_x
FUNCTION_AT_ADDRESS(bool CBookWnd::CheckBook(EQ_Note*), CBookWnd__CheckBook);
#endif
#ifdef CBookWnd__DisplayText_x
FUNCTION_AT_ADDRESS(void CBookWnd::DisplayText(), CBookWnd__DisplayText);
#endif
#ifdef CBookWnd__CleanPages_x
FUNCTION_AT_ADDRESS(void CBookWnd::CleanPages(), CBookWnd__CleanPages);
#endif
#ifdef CBookWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void CBookWnd::ProcessText(), CBookWnd__ProcessText);
#endif
#ifdef CBookWnd__ShowButtons_x
FUNCTION_AT_ADDRESS(void CBookWnd::ShowButtons(), CBookWnd__ShowButtons);
#endif
#ifdef CBreathWnd__CBreathWnd_x
FUNCTION_AT_ADDRESS(CBreathWnd::CBreathWnd(CXWnd*), CBreathWnd__CBreathWnd);
#endif
#ifdef CBreathWnd__Init_x
FUNCTION_AT_ADDRESS(void CBreathWnd::Init(), CBreathWnd__Init);
#endif
#ifdef CBreathWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBreathWnd::Activate(), CBreathWnd__Activate);
#endif
#ifdef CTextureAnimation__operator_equal_x
FUNCTION_AT_ADDRESS(CTextureAnimation& CTextureAnimation::operator=(const CTextureAnimation&), CTextureAnimation__operator_equal);
#endif
#ifdef CBuffWindow__Init_x
FUNCTION_AT_ADDRESS(void CBuffWindow::Init(), CBuffWindow__Init);
#endif
#ifdef CBuffWindow__Activate_x
FUNCTION_AT_ADDRESS(void CBuffWindow::Activate(), CBuffWindow__Activate);
#endif
#ifdef CBuffWindow__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void CBuffWindow::HandleSpellInfoDisplay(CXWnd*), CBuffWindow__HandleSpellInfoDisplay);
#endif
#ifdef CBuffWindow__RefreshIconArrangement_x
FUNCTION_AT_ADDRESS(void CBuffWindow::RefreshIconArrangement(), CBuffWindow__RefreshIconArrangement);
#endif
#ifdef CBuffWindow__RefreshBuffDisplay_x
FUNCTION_AT_ADDRESS(void CBuffWindow::RefreshBuffDisplay(), CBuffWindow__RefreshBuffDisplay);
#endif
#ifdef CBuffWindow__SetBuffIcon_x
FUNCTION_AT_ADDRESS(void CBuffWindow::SetBuffIcon(CButtonWnd*, int, int), CBuffWindow__SetBuffIcon);
#endif
#ifdef CXRect__Move_x
FUNCTION_AT_ADDRESS(void CXRect::Move(CXPoint), CXRect__Move);
#endif
#ifdef CTreeView__CTreeView_x
FUNCTION_AT_ADDRESS(void CTreeView::GetFrameSize(CXWnd*, uint32_t, CXRect, int) , CTreeView__CTreeView);
#endif
#ifdef CTreeView__dTreeView_x
FUNCTION_AT_ADDRESS(void CTreeView:~CTreeView() , CTreeView__dTreeView);
#endif
#ifdef CTAFrameDraw__GetFrameSize_x
FUNCTION_AT_ADDRESS(CXSize CTAFrameDraw::GetFrameSize() const, CTAFrameDraw__GetFrameSize);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame_x
FUNCTION_AT_ADDRESS(STextureAnimationFrame::STextureAnimationFrame(), STextureAnimationFrame__STextureAnimationFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece_x
FUNCTION_AT_ADDRESS(CUITexturePiece::CUITexturePiece(), CUITexturePiece__CUITexturePiece);
#endif
#ifdef STextureAnimationFrame__operator_equal_x
FUNCTION_AT_ADDRESS(STextureAnimationFrame& STextureAnimationFrame::operator=(const STextureAnimationFrame&), STextureAnimationFrame__operator_equal);
#endif
#ifdef CUITexturePiece__operator_equal_x
FUNCTION_AT_ADDRESS(CUITexturePiece& CUITexturePiece::operator=(const CUITexturePiece&), CUITexturePiece__operator_equal);
#endif
#ifdef CBugReportWnd__CBugReportWnd_x
FUNCTION_AT_ADDRESS(CBugReportWnd::CBugReportWnd(CXWnd*), CBugReportWnd__CBugReportWnd);
#endif
#ifdef CBugReportWnd__Activate_x
FUNCTION_AT_ADDRESS(void CBugReportWnd::Activate(), CBugReportWnd__Activate);
#endif
#ifdef CBugReportWnd__UpdateLocation_x
FUNCTION_AT_ADDRESS(void CBugReportWnd::UpdateLocation(), CBugReportWnd__UpdateLocation);
#endif
#ifdef CCastingWnd__CCastingWnd_x
FUNCTION_AT_ADDRESS(CCastingWnd::CCastingWnd(CXWnd*), CCastingWnd__CCastingWnd);
#endif
#ifdef CCastingWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCastingWnd::Activate(), CCastingWnd__Activate);
#endif
#ifdef CVideoModesWnd__Activate_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::Activate(), CVideoModesWnd__Activate);
#endif
#ifdef CCastSpellWnd__CCastSpellWnd_x
FUNCTION_AT_ADDRESS(CCastSpellWnd::CCastSpellWnd(CXWnd*), CCastSpellWnd__CCastSpellWnd);
#endif
#ifdef CCastSpellWnd__Init_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::Init(), CCastSpellWnd__Init);
#endif
#ifdef CCastSpellWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::Activate(), CCastSpellWnd__Activate);
#endif
#ifdef CCastSpellWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellInfoDisplay(CXWnd*), CCastSpellWnd__HandleSpellInfoDisplay);
#endif
#ifdef CCastSpellWnd__HandleSpellLeftClick_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellLeftClick(int), CCastSpellWnd__HandleSpellLeftClick);
#endif
#ifdef CCastSpellWnd__Unmemorize_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::Unmemorize(int), CCastSpellWnd__Unmemorize);
#endif
#ifdef CCastSpellWnd__UnmemorizeList_x
FUNCTION_AT_ADDRESS(void __cdecl CCastSpellWnd::UnmemorizeList(int*, int), CCastSpellWnd__UnmemorizeList);
#endif
#ifdef CCastSpellWnd__HandleSpellRightClick_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::HandleSpellRightClick(int), CCastSpellWnd__HandleSpellRightClick);
#endif
#ifdef CCastSpellWnd__ForgetMemorizedSpell_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::ForgetMemorizedSpell(int), CCastSpellWnd__ForgetMemorizedSpell);
#endif
#ifdef CCastSpellWnd__IsBardSongPlaying_x
FUNCTION_AT_ADDRESS(bool CCastSpellWnd::IsBardSongPlaying(), CCastSpellWnd__IsBardSongPlaying);
#endif
#ifdef CCastSpellWnd__RefreshSpellGemButtons_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RefreshSpellGemButtons(), CCastSpellWnd__RefreshSpellGemButtons);
#endif
#ifdef CCastSpellWnd__UpdateSpellGems_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::UpdateSpellGems(int), CCastSpellWnd__UpdateSpellGems);
#endif
#ifdef CCastSpellWnd__UpdateSpellGemTooltips_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::UpdateSpellGemTooltips(int), CCastSpellWnd__UpdateSpellGemTooltips);
#endif
#ifdef CCastSpellWnd__GetSpellGemColor_x
FUNCTION_AT_ADDRESS(unsigned long CCastSpellWnd::GetSpellGemColor(EQ_Spell*), CCastSpellWnd__GetSpellGemColor);
#endif
#ifdef CCastSpellWnd__SpellBookDeactivating_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::SpellBookDeactivating(), CCastSpellWnd__SpellBookDeactivating);
#endif
#ifdef CCastSpellWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::KeyMapUpdated(), CCastSpellWnd__KeyMapUpdated);
#endif
#ifdef CCastSpellWnd__ClearSpellCategories_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::ClearSpellCategories(), CCastSpellWnd__ClearSpellCategories);
#endif
#ifdef CCastSpellWnd__RecacheCategorizedSpells_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RecacheCategorizedSpells(), CCastSpellWnd__RecacheCategorizedSpells);
#endif
#ifdef CCastSpellWnd__MakeSpellSelectMenu_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::MakeSpellSelectMenu(), CCastSpellWnd__MakeSpellSelectMenu);
#endif
#ifdef CCastSpellWnd__CategorizeSpell_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::CategorizeSpell(int, int, int, int), CCastSpellWnd__CategorizeSpell);
#endif
#ifdef CCastSpellWnd__RecacheLoadoutContextMenu_x
FUNCTION_AT_ADDRESS(void CCastSpellWnd::RecacheLoadoutContextMenu(), CCastSpellWnd__RecacheLoadoutContextMenu);
#endif
#ifdef CCharacterCreation__CCharacterCreation_x
FUNCTION_AT_ADDRESS(CCharacterCreation::CCharacterCreation(CXWnd*), CCharacterCreation__CCharacterCreation);
#endif
#ifdef CCharacterCreation__Init_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::Init(), CCharacterCreation__Init);
#endif
#ifdef CCharacterCreation__Activate_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::Activate(), CCharacterCreation__Activate);
#endif
#ifdef CCharacterCreation__NameGenerated_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::NameGenerated(char*), CCharacterCreation__NameGenerated);
#endif
#ifdef CCharacterCreation__DoBackButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoBackButton(), CCharacterCreation__DoBackButton);
#endif
#ifdef CCharacterCreation__DoNextButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoNextButton(), CCharacterCreation__DoNextButton);
#endif
#ifdef CCharacterCreation__DoStatButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::DoStatButton(int), CCharacterCreation__DoStatButton);
#endif
#ifdef CCharacterCreation__ActivateScreen_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::ActivateScreen(int), CCharacterCreation__ActivateScreen);
#endif
#ifdef CCharacterCreation__RandomizeCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::RandomizeCharacter(bool, bool), CCharacterCreation__RandomizeCharacter);
#endif
#ifdef CCharacterCreation__RandomizeFacialFeatures_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::RandomizeFacialFeatures(), CCharacterCreation__RandomizeFacialFeatures);
#endif
#ifdef CCharacterCreation__InitStats_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitStats(bool), CCharacterCreation__InitStats);
#endif
#ifdef CCharacterCreation__InitNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitNewPC(), CCharacterCreation__InitNewPC);
#endif
#ifdef CCharacterCreation__InitStartingCities_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::InitStartingCities(), CCharacterCreation__InitStartingCities);
#endif
#ifdef CCharacterCreation__SetNewPCDeityFromBtnIndex_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SetNewPCDeityFromBtnIndex(int), CCharacterCreation__SetNewPCDeityFromBtnIndex);
#endif
#ifdef CCharacterCreation__UpdatePlayerFromNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::UpdatePlayerFromNewPC(), CCharacterCreation__UpdatePlayerFromNewPC);
#endif
#ifdef CCharacterCreation__UpdateScreenZeroButtons_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::UpdateScreenZeroButtons(bool), CCharacterCreation__UpdateScreenZeroButtons);
#endif
#ifdef CCharacterCreation__GetRaceButtonIndex_x
FUNCTION_AT_ADDRESS(int CCharacterCreation::GetRaceButtonIndex(int), CCharacterCreation__GetRaceButtonIndex);
#endif
#ifdef CCharacterCreation__GetClassButtonIndex_x
FUNCTION_AT_ADDRESS(int CCharacterCreation::GetClassButtonIndex(int), CCharacterCreation__GetClassButtonIndex);
#endif
#ifdef CCharacterCreation__IsLackingExpansion_x
FUNCTION_AT_ADDRESS(bool CCharacterCreation::IsLackingExpansion(bool, bool), CCharacterCreation__IsLackingExpansion);
#endif
#ifdef CCharacterCreation__SelectStartingCity_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectStartingCity(int), CCharacterCreation__SelectStartingCity);
#endif
#ifdef CCharacterCreation__SelectedRaceButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectedRaceButton(int), CCharacterCreation__SelectedRaceButton);
#endif
#ifdef CCharacterCreation__SelectedClassButton_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SelectedClassButton(int), CCharacterCreation__SelectedClassButton);
#endif
#ifdef CCharacterCreation__SetPlayerAppearanceFromNewPC_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SetPlayerAppearanceFromNewPC(EQPlayer*, EQ_PC*, bool), CCharacterCreation__SetPlayerAppearanceFromNewPC);
#endif
#ifdef CCharacterCreation__HandleNameApprovalResponse_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::HandleNameApprovalResponse(int), CCharacterCreation__HandleNameApprovalResponse);
#endif
#ifdef CCharacterCreation__SubmitNameToWorld_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::SubmitNameToWorld(), CCharacterCreation__SubmitNameToWorld);
#endif
#ifdef CCharacterCreation__FinalizeNewPCAndSendToWorld_x
FUNCTION_AT_ADDRESS(void CCharacterCreation::FinalizeNewPCAndSendToWorld(), CCharacterCreation__FinalizeNewPCAndSendToWorld);
#endif
#ifdef CCharacterCreation__GetCharCreateText_x
FUNCTION_AT_ADDRESS(char* CCharacterCreation::GetCharCreateText(char*, int, int, int, int), CCharacterCreation__GetCharCreateText);
#endif
#ifdef CCharacterListWnd__CCharacterListWnd_x
FUNCTION_AT_ADDRESS(CCharacterListWnd::CCharacterListWnd(CXWnd*), CCharacterListWnd__CCharacterListWnd);
#endif
#ifdef CCharacterListWnd__Init_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::Init(), CCharacterListWnd__Init);
#endif
#ifdef CCharacterListWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::Activate(), CCharacterListWnd__Activate);
#endif
#ifdef CCharacterListWnd__EnableButtons_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnableButtons(bool), CCharacterListWnd__EnableButtons);
#endif
#ifdef CCharacterListWnd__EnableEqMovementCommands_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnableEqMovementCommands(bool), CCharacterListWnd__EnableEqMovementCommands);
#endif
#ifdef CCharacterListWnd__EnterWorld_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnterWorld(), CCharacterListWnd__EnterWorld);
#endif
#ifdef CCharacterListWnd__Quit_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::Quit(), CCharacterListWnd__Quit);
#endif
#ifdef CCharacterListWnd__UpdateList_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::UpdateList(bool), CCharacterListWnd__UpdateList);
#endif
#ifdef CCharacterListWnd__EnterExplorationMode_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::EnterExplorationMode(), CCharacterListWnd__EnterExplorationMode);
#endif
#ifdef CCharacterListWnd__LeaveExplorationMode_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::LeaveExplorationMode(), CCharacterListWnd__LeaveExplorationMode);
#endif
#ifdef CCharacterListWnd__IsValidCharacterSelected_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::IsValidCharacterSelected(), CCharacterListWnd__IsValidCharacterSelected);
#endif
#ifdef CCharacterListWnd__IsEmptyCharacterSlot_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::IsEmptyCharacterSlot(int), CCharacterListWnd__IsEmptyCharacterSlot);
#endif
#ifdef CCharacterListWnd__NumberOfCharacters_x
FUNCTION_AT_ADDRESS(int CCharacterListWnd::NumberOfCharacters(), CCharacterListWnd__NumberOfCharacters);
#endif
#ifdef CCharacterListWnd__IsEvil_x
FUNCTION_AT_ADDRESS(unsigned char CCharacterListWnd::IsEvil(int, int, int), CCharacterListWnd__IsEvil);
#endif
#ifdef CCharacterListWnd__SelectCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SelectCharacter(int, bool, bool), CCharacterListWnd__SelectCharacter);
#endif
#ifdef CCharacterListWnd__SetLoadZonePlayerLocation_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetLoadZonePlayerLocation(), CCharacterListWnd__SetLoadZonePlayerLocation);
#endif
#ifdef CCharacterListWnd__DeleteCharacter_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::DeleteCharacter(), CCharacterListWnd__DeleteCharacter);
#endif
#ifdef CCharacterListWnd__UpdateButtonNames_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::UpdateButtonNames(), CCharacterListWnd__UpdateButtonNames);
#endif
#ifdef CCharacterListWnd__SetLocationByClass_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetLocationByClass(EQPlayer*, bool, int), CCharacterListWnd__SetLocationByClass);
#endif
#ifdef CCharacterListWnd__CreateExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::CreateExplorationModePlayers(), CCharacterListWnd__CreateExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__RemoveExplorationModePlayers_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::RemoveExplorationModePlayers(), CCharacterListWnd__RemoveExplorationModePlayers);
#endif
#ifdef CCharacterListWnd__SetRoomLocationByIndex_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SetRoomLocationByIndex(int, EQPlayer*), CCharacterListWnd__SetRoomLocationByIndex);
#endif
#ifdef CCharacterListWnd__SwitchModel_x
FUNCTION_AT_ADDRESS(void CCharacterListWnd::SwitchModel(EQPlayer*, unsigned char, int, unsigned char, unsigned char), CCharacterListWnd__SwitchModel);
#endif
#ifdef CChatManager__CChatManager_x
FUNCTION_AT_ADDRESS(CChatManager::CChatManager(), CChatManager__CChatManager);
#endif
#ifdef CChatManager__dCChatManager_x
FUNCTION_AT_ADDRESS(CChatManager::~CChatManager(), CChatManager__dCChatManager);
#endif
#ifdef CBookWnd__Init_x
FUNCTION_AT_ADDRESS(void CBookWnd::Init(), CBookWnd__Init);
#endif
#ifdef CColorPickerWnd__Init_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::Init(), CColorPickerWnd__Init);
#endif
#ifdef CCompassWnd__Init_x
FUNCTION_AT_ADDRESS(void CCompassWnd::Init(), CCompassWnd__Init);
#endif
#ifdef CContainerWnd__Init_x
FUNCTION_AT_ADDRESS(void CContainerWnd::Init(), CContainerWnd__Init);
#endif
#ifdef CGiveWnd__Init_x
FUNCTION_AT_ADDRESS(void CGiveWnd::Init(), CGiveWnd__Init);
#endif
#ifdef CHelpWnd__Init_x
FUNCTION_AT_ADDRESS(void CHelpWnd::Init(), CHelpWnd__Init);
#endif
#ifdef CMusicPlayerWnd__Init_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::Init(), CMusicPlayerWnd__Init);
#endif
#ifdef CNoteWnd__Init_x
FUNCTION_AT_ADDRESS(void CNoteWnd::Init(), CNoteWnd__Init);
#endif
#ifdef CPetInfoWnd__Init_x
FUNCTION_AT_ADDRESS(void CPetInfoWnd::Init(), CPetInfoWnd__Init);
#endif
#ifdef CPlayerNotesWnd__Init_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::Init(), CPlayerNotesWnd__Init);
#endif
#ifdef CTargetWnd__Init_x
FUNCTION_AT_ADDRESS(void CTargetWnd::Init(), CTargetWnd__Init);
#endif
#ifdef CTargetWnd__RefreshTargetBuffs_x
FUNCTION_AT_ADDRESS(void CTargetWnd::RefreshTargetBuffs(PBYTE), CTargetWnd__RefreshTargetBuffs);
#endif
#ifdef CTargetWnd__HandleBuffRemoveRequest_x
FUNCTION_AT_ADDRESS(void CTargetWnd::HandleBuffRemoveRequest(CXWnd*), CTargetWnd__HandleBuffRemoveRequest);
#endif
#ifdef CRaid__dCRaid_x
FUNCTION_AT_ADDRESS(CRaid::~CRaid(), CRaid__dCRaid);
#endif
#ifdef EQ_Note__dEQ_Note_x
FUNCTION_AT_ADDRESS(EQ_Note::~EQ_Note(), EQ_Note__dEQ_Note);
#endif
#ifdef EQ_Skill__dEQ_Skill_x
FUNCTION_AT_ADDRESS(EQ_Skill::~EQ_Skill(), EQ_Skill__dEQ_Skill);
#endif
#ifdef EQAnimation__dEQAnimation_x
FUNCTION_AT_ADDRESS(EQAnimation::~EQAnimation(), EQAnimation__dEQAnimation);
#endif
#ifdef KeypressHandler__dKeypressHandler_x
FUNCTION_AT_ADDRESS(KeypressHandler::~KeypressHandler(), KeypressHandler__dKeypressHandler);
#endif
#ifdef CAAWnd__CancelAASpend_x
FUNCTION_AT_ADDRESS(void CAAWnd::CancelAASpend(), CAAWnd__CancelAASpend);
#endif
#ifdef CChatManager__Process_x
FUNCTION_AT_ADDRESS(void CChatManager::Process(), CChatManager__Process);
#endif
#ifdef CDisplay__DefineSoloMode_x
FUNCTION_AT_ADDRESS(void CDisplay::DefineSoloMode(), CDisplay__DefineSoloMode);
#endif
#ifdef CEverQuest__InitCommands_x
FUNCTION_AT_ADDRESS(void CEverQuest::InitCommands(), CEverQuest__InitCommands);
#endif
#ifdef CInvSlotMgr__Process_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::Process(), CInvSlotMgr__Process);
#endif
#ifdef EQMissile__LeaveTrail_x
FUNCTION_AT_ADDRESS(void EQMissile::LeaveTrail(), EQMissile__LeaveTrail);
#endif
#ifdef CChatManager__Activate_x
FUNCTION_AT_ADDRESS(void CChatManager::Activate(), CChatManager__Activate);
#endif
#ifdef CChatManager__Deactivate_x
FUNCTION_AT_ADDRESS(void CChatManager::Deactivate(), CChatManager__Deactivate);
#endif
#ifdef CChatManager__LoadChatInis_x
FUNCTION_AT_ADDRESS(void CChatManager::LoadChatInis(), CChatManager__LoadChatInis);
#endif
#ifdef CChatManager__CreateChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::CreateChatWindow(), CChatManager__CreateChatWindow);
#endif
#ifdef CChatManager__CreateChatWindow1_x
FUNCTION_AT_ADDRESS(void CChatManager::CreateChatWindow(char*, char*, int, int, int, char*, int), CChatManager__CreateChatWindow1);
#endif
#ifdef CChatManager__FreeChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::FreeChatWindow(CChatWindow*), CChatManager__FreeChatWindow);
#endif
#ifdef CChatManager__GetActiveChatWindow_x
FUNCTION_AT_ADDRESS(CChatWindow* CChatManager::GetActiveChatWindow(), CChatManager__GetActiveChatWindow);
#endif
#ifdef CChatManager__AddText_x
FUNCTION_AT_ADDRESS(void CChatManager::AddText(CXStr, int), CChatManager__AddText);
#endif
#ifdef CChatManager__SetChannelMap_x
FUNCTION_AT_ADDRESS(void CChatManager::SetChannelMap(int, CChatWindow*), CChatManager__SetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMap_x
FUNCTION_AT_ADDRESS(void CChatManager::ClearChannelMap(int), CChatManager__ClearChannelMap);
#endif
#ifdef CChatManager__GetChannelFromColor_x
FUNCTION_AT_ADDRESS(int CChatManager::GetChannelFromColor(int), CChatManager__GetChannelFromColor);
#endif
#ifdef CChatManager__GetChannelMap_x
FUNCTION_AT_ADDRESS(CChatWindow* CChatManager::GetChannelMap(int), CChatManager__GetChannelMap);
#endif
#ifdef CChatManager__ClearChannelMaps_x
FUNCTION_AT_ADDRESS(void CChatManager::ClearChannelMaps(CChatWindow*), CChatManager__ClearChannelMaps);
#endif
#ifdef CChatManager__SetActiveChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::SetActiveChatWindow(CChatWindow*), CChatManager__SetActiveChatWindow);
#endif
#ifdef CChatManager__GetRGBAFromIndex_x
FUNCTION_AT_ADDRESS(unsigned long CChatManager::GetRGBAFromIndex(int), CChatManager__GetRGBAFromIndex);
#endif
#ifdef CChatManager__InitContextMenu_x
FUNCTION_AT_ADDRESS(int CChatManager::InitContextMenu(CChatWindow*), CChatManager__InitContextMenu);
#endif
#ifdef CChatManager__UpdateContextMenus_x
FUNCTION_AT_ADDRESS(void CChatManager::UpdateContextMenus(CChatWindow*), CChatManager__UpdateContextMenus);
#endif
#ifdef CChatManager__UpdateTellMenus_x
FUNCTION_AT_ADDRESS(void CChatManager::UpdateTellMenus(CChatWindow*), CChatManager__UpdateTellMenus);
#endif
#ifdef CChatManager__GetAllVisibleText_x
FUNCTION_AT_ADDRESS(CXStr CChatManager::GetAllVisibleText(CXStr), CChatManager__GetAllVisibleText);
#endif
#ifdef CChatManager__GetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(CChatWindow* CChatManager::GetLockedActiveChatWindow(), CChatManager__GetLockedActiveChatWindow);
#endif
#ifdef CChatManager__SetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(void CChatManager::SetLockedActiveChatWindow(CChatWindow*), CChatManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatManager__CreateChatWindow_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CChatManager::CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor), CChatManager__CreateChatWindow);
#else
FUNCTION_AT_ADDRESS(void CChatManager::CreateChatWindow(char* Name, char* IniName, int Language, int DefaultChannel, int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar), CChatManager__CreateChatWindow);
#endif
#endif
#ifdef CChatWindow__GetOutputWnd_x
FUNCTION_AT_ADDRESS(CStmlWnd* CChatWindow::GetOutputWnd(), CChatWindow__GetOutputWnd);
#endif
#ifdef CContextMenuManager__GetDefaultMenuIndex_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::GetDefaultMenuIndex(), CContextMenuManager__GetDefaultMenuIndex);
#endif
#ifdef CContextMenuManager__GetMenu_x
FUNCTION_AT_ADDRESS(CContextMenu* CContextMenuManager::GetMenu(int), CContextMenuManager__GetMenu);
#endif
#ifdef CChatWindow__CChatWindow_x
CONSTRUCTOR_AT_ADDRESS(CChatWindow::CChatWindow(CXWnd*), CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText_x
FUNCTION_AT_ADDRESS(void CChatWindow::AddOutputText(PCXSTR, int), CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryBack(), CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryForward(), CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory_x
FUNCTION_AT_ADDRESS(void CChatWindow::AddHistory(CXStr Text), CChatWindow__AddHistory);
#endif
#ifdef CChatWindow__GetInputText_x
FUNCTION_AT_ADDRESS(CXStr CChatWindow::GetInputText(), CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageUp(), CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageDown(), CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont_x
FUNCTION_AT_ADDRESS(void CChatWindow::SetChatFont(int), CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear_x
FUNCTION_AT_ADDRESS(void CChatWindow::Clear(), CChatWindow__Clear);
#endif
#ifdef CStmlWnd__GetSTMLText_x
FUNCTION_AT_ADDRESS(CXStr CStmlWnd::GetSTMLText() const, CStmlWnd__GetSTMLText);
#endif
#ifdef CChatWindow__GetInputWnd_x
FUNCTION_AT_ADDRESS(CEditWnd* CChatWindow::GetInputWnd(), CChatWindow__GetInputWnd);
#endif
#ifdef CChatWindow__WndNotification_x
FUNCTION_AT_ADDRESS(int CChatWindow::WndNotification(CXWnd*, uint32_t, void*), CChatWindow__WndNotification);
#endif
#ifdef CColorPickerWnd__CColorPickerWnd_x
FUNCTION_AT_ADDRESS(CColorPickerWnd::CColorPickerWnd(CXWnd*), CColorPickerWnd__CColorPickerWnd);
#endif
#ifdef CColorPickerWnd__SetTemplateColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::SetTemplateColor(int, unsigned long), CColorPickerWnd__SetTemplateColor);
#endif
#ifdef CColorPickerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::Activate(CXWnd*, unsigned long), CColorPickerWnd__Activate);
#endif
#ifdef CColorPickerWnd__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::SetCurrentColor(unsigned long), CColorPickerWnd__SetCurrentColor);
#endif
#ifdef CColorPickerWnd__UpdateCurrentColor_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateCurrentColor(), CColorPickerWnd__UpdateCurrentColor);
#endif
#ifdef CColorPickerWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::CheckMaxEditWnd(), CColorPickerWnd__CheckMaxEditWnd);
#endif
#ifdef CColorPickerWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateEditWndFromSlider(CSliderWnd*, CEditWnd*, int*), CColorPickerWnd__UpdateEditWndFromSlider);
#endif
#ifdef CColorPickerWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void CColorPickerWnd::UpdateSliderFromEditWnd(CSliderWnd*, CEditWnd*, int*), CColorPickerWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CColorPickerWnd__Open_x
FUNCTION_AT_ADDRESS(int CColorPickerWnd::Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor), CColorPickerWnd__Open);
#endif
#ifdef CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x
FUNCTION_AT_ADDRESS(bool CCombatSkillsSelectWnd::ShouldDisplayThisSkill(int), CCombatSkillsSelectWnd__ShouldDisplayThisSkill);
#endif
#ifdef CCompassWnd__CCompassWnd_x
FUNCTION_AT_ADDRESS(CCompassWnd::CCompassWnd(CXWnd*), CCompassWnd__CCompassWnd);
#endif
#ifdef CCompassWnd__Activate_x
FUNCTION_AT_ADDRESS(void CCompassWnd::Activate(), CCompassWnd__Activate);
#endif
#ifdef CCompassWnd__PickNewTarget_x
FUNCTION_AT_ADDRESS(void CCompassWnd::PickNewTarget(), CCompassWnd__PickNewTarget);
#endif
#ifdef CCompassWnd__SetSpeed_x
FUNCTION_AT_ADDRESS(void CCompassWnd::SetSpeed(), CCompassWnd__SetSpeed);
#endif
#ifdef CCompassWnd__SenseHeading_x
FUNCTION_AT_ADDRESS(void CCompassWnd::SenseHeading(), CCompassWnd__SenseHeading);
#endif
#ifdef CConfirmationDialog__CConfirmationDialog_x
FUNCTION_AT_ADDRESS(CConfirmationDialog::CConfirmationDialog(CXWnd*), CConfirmationDialog__CConfirmationDialog);
#endif
#ifdef CConfirmationDialog__Init_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Init(), CConfirmationDialog__Init);
#endif
#ifdef CConfirmationDialog__Activate_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Activate(int, unsigned int, const char*, int, int, int, int), CConfirmationDialog__Activate);
#endif
#ifdef CConfirmationDialog__Deactivate_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::Deactivate(), CConfirmationDialog__Deactivate);
#endif
#ifdef CConfirmationDialog__ExpireCurrentDialog_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ExpireCurrentDialog(), CConfirmationDialog__ExpireCurrentDialog);
#endif
#ifdef CConfirmationDialog__HandleButtonYesPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonYesPressed(), CConfirmationDialog__HandleButtonYesPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonNoPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonNoPressed(), CConfirmationDialog__HandleButtonNoPressed);
#endif
#ifdef CConfirmationDialog__HandleButtonOkPressed_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::HandleButtonOkPressed(), CConfirmationDialog__HandleButtonOkPressed);
#endif
#ifdef CConfirmationDialog__ProcessYes_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ProcessYes(), CConfirmationDialog__ProcessYes);
#endif
#ifdef CConfirmationDialog__ResetFocusOnClose_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ResetFocusOnClose(), CConfirmationDialog__ResetFocusOnClose);
#endif
#ifdef CConfirmationDialog__ProcessNo_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::ProcessNo(int), CConfirmationDialog__ProcessNo);
#endif
#ifdef CConfirmationDialog__SetNameApprovalData_x
FUNCTION_AT_ADDRESS(void CConfirmationDialog::SetNameApprovalData(char*, char*, int, int, char*), CConfirmationDialog__SetNameApprovalData);
#endif
#ifdef CConfirmationDialog__WndNotification_x
FUNCTION_AT_ADDRESS(int CConfirmationDialog::WndNotification(CXWnd*, uint32_t, void*), CConfirmationDialog__WndNotification);
#endif
#ifdef CContainerMgr__GetFreeContainerWnd_x
FUNCTION_AT_ADDRESS(CContainerWnd* CContainerMgr::GetFreeContainerWnd(), CContainerMgr__GetFreeContainerWnd);
#endif
#ifdef CContainerMgr__OpenExperimentContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location), CContainerMgr__OpenExperimentContainer);
#endif
#ifdef CContainerMgr__CContainerMgr_x
FUNCTION_AT_ADDRESS(CContainerMgr::CContainerMgr(), CContainerMgr__CContainerMgr);
#endif
#ifdef CContainerMgr__Process_x
FUNCTION_AT_ADDRESS(void CContainerMgr::Process(), CContainerMgr__Process);
#endif
#ifdef CContainerMgr__OpenWorldContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenWorldContainer(EQ_Container*, unsigned long), CContainerMgr__OpenWorldContainer);
#endif
#ifdef CContainerMgr__SetWorldContainerItem_x
FUNCTION_AT_ADDRESS(void CContainerMgr::SetWorldContainerItem(EQ_Item*, int), CContainerMgr__SetWorldContainerItem);
#endif
#ifdef CContainerMgr__GetWorldContainerItem_x
FUNCTION_AT_ADDRESS(EQ_Item* CContainerMgr::GetWorldContainerItem(int), CContainerMgr__GetWorldContainerItem);
#endif
#ifdef CContainerMgr__ClearWorldContainerItems_x
FUNCTION_AT_ADDRESS(void CContainerMgr::ClearWorldContainerItems(), CContainerMgr__ClearWorldContainerItems);
#endif
#ifdef CContainerMgr__OpenContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::OpenContainer(EQ_Container*, int, bool), CContainerMgr__OpenContainer);
#endif
#ifdef CContainerMgr__CloseEQContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::CloseEQContainer(EQ_Container*), CContainerMgr__CloseEQContainer);
#endif
#ifdef CContainerMgr__CloseContainer_x
FUNCTION_AT_ADDRESS(void CContainerMgr::CloseContainer(EQ_Container*, bool), CContainerMgr__CloseContainer);
#endif
#ifdef CContainerMgr__CloseAllContainers_x
FUNCTION_AT_ADDRESS(bool CContainerMgr::CloseAllContainers(), CContainerMgr__CloseAllContainers);
#endif
#ifdef CContainerWnd__CContainerWnd_x
FUNCTION_AT_ADDRESS(CContainerWnd::CContainerWnd(CXWnd*), CContainerWnd__CContainerWnd);
#endif
#ifdef CContainerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CContainerWnd::Activate(), CContainerWnd__Activate);
#endif
#ifdef CHelpWnd__Activate_x
FUNCTION_AT_ADDRESS(void CHelpWnd::Activate(), CHelpWnd__Activate);
#endif
#ifdef CContainerWnd__HandleCombine_x
FUNCTION_AT_ADDRESS(void CContainerWnd::HandleCombine(), CContainerWnd__HandleCombine);
#endif
#ifdef CContainerWnd__SetContainer_x
FUNCTION_AT_ADDRESS(void CContainerWnd::SetContainer(PCONTENTS& pContainer, const ItemGlobalIndex& location), CContainerWnd__SetContainer);
#endif
#ifdef CContainerWnd__CheckCloseable_x
FUNCTION_AT_ADDRESS(void CContainerWnd::CheckCloseable(), CContainerWnd__CheckCloseable);
#endif
#ifdef CContainerWnd__ContainsNoDrop_x
FUNCTION_AT_ADDRESS(bool CContainerWnd::ContainsNoDrop(), CContainerWnd__ContainsNoDrop);
#endif
#ifdef CXRect__operator_or_x
FUNCTION_AT_ADDRESS(CXRect CXRect::operator|(CXRect) const, CXRect__operator_or);
#endif
#ifdef CContextMenu__CContextMenu_x
CONSTRUCTOR_AT_ADDRESS(CContextMenu::CContextMenu(CXWnd* pParent, uint32_t MenuID, const CXRect& rect), CContextMenu__CContextMenu);
#endif
#ifdef CContextMenu__dCContextMenu_x
FUNCTION_AT_ADDRESS(CContextMenu::~CContextMenu(), CContextMenu__dCContextMenu);
#endif
#ifdef CContextMenu__AddMenuItem_x
FUNCTION_AT_ADDRESS(int CContextMenu::AddMenuItem(const CXStr&, unsigned int, bool, COLORREF, bool), CContextMenu__AddMenuItem);
#endif
#ifdef CContextMenu__AddSeparator_x
FUNCTION_AT_ADDRESS(int CContextMenu::AddSeparator(), CContextMenu__AddSeparator);
#endif
#ifdef CContextMenu__RemoveAllMenuItems_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveAllMenuItems(), CContextMenu__RemoveAllMenuItems);
#endif
#ifdef CContextMenu__RemoveMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::RemoveMenuItem(int), CContextMenu__RemoveMenuItem);
#endif
#ifdef CContextMenu__EnableMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::EnableMenuItem(int, bool), CContextMenu__EnableMenuItem);
#endif
#ifdef CContextMenu__CheckMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::CheckMenuItem(int, bool, bool), CContextMenu__CheckMenuItem);
#endif
#ifdef CContextMenu__Activate_x
FUNCTION_AT_ADDRESS(void CContextMenu::Activate(CXPoint, int, int), CContextMenu__Activate);
#endif
#ifdef CContextMenu__SetMenuItem_x
FUNCTION_AT_ADDRESS(void CContextMenu::SetMenuItem(int, const CXStr&, bool, COLORREF, bool), CContextMenu__SetMenuItem);
#endif
#ifdef CContextMenuManager__CContextMenuManager_x
FUNCTION_AT_ADDRESS(CContextMenuManager::CContextMenuManager(CXWnd*, uint32_t, CXRect), CContextMenuManager__CContextMenuManager);
#endif
#ifdef CContextMenuManager__RemoveMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::RemoveMenu(int, bool), CContextMenuManager__RemoveMenu);
#endif
#ifdef CContextMenuManager__AddMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::AddMenu(CContextMenu*), CContextMenuManager__AddMenu);
#endif
#ifdef CContextMenuManager__PopupMenu_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::PopupMenu(int, CXPoint const&, CXWnd*), CContextMenuManager__PopupMenu);
#endif
#ifdef CContextMenuManager__Flush_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::Flush(), CContextMenuManager__Flush);
#endif
#ifdef CContextMenuManager__CreateDefaultMenu_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::CreateDefaultMenu(), CContextMenuManager__CreateDefaultMenu);
#endif
#ifdef CContextMenuManager__WarnDefaultMenu_x
FUNCTION_AT_ADDRESS(void CContextMenuManager::WarnDefaultMenu(CXWnd*), CContextMenuManager__WarnDefaultMenu);
#endif
#ifdef CContextMenuManager__HandleWindowMenuCommands_x
FUNCTION_AT_ADDRESS(int CContextMenuManager::HandleWindowMenuCommands(CXWnd*, int), CContextMenuManager__HandleWindowMenuCommands);
#endif
#ifdef CXRect__Width_x
FUNCTION_AT_ADDRESS(int CXRect::Width() const, CXRect__Width);
#endif
#ifdef CCursorAttachment__CCursorAttachment_x
FUNCTION_AT_ADDRESS(CCursorAttachment::CCursorAttachment(CXWnd*), CCursorAttachment__CCursorAttachment);
#endif
#ifdef CCursorAttachment__Init_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::Init(), CCursorAttachment__Init);
#endif
#ifdef CCursorAttachment__Activate_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::Activate(CTextureAnimation*, int, int, int), CCursorAttachment__Activate);
#endif
#ifdef CCursorAttachment__DrawButtonText_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::DrawButtonText() const, CCursorAttachment__DrawButtonText);
#endif
#ifdef CCursorAttachment__DrawQuantity_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::DrawQuantity() const, CCursorAttachment__DrawQuantity);
#endif
#ifdef CCursorAttachment__IsOkToActivate_x
FUNCTION_AT_ADDRESS(bool CCursorAttachment::IsOkToActivate(int), CCursorAttachment__IsOkToActivate);
#endif
#ifdef CCursorAttachment__RemoveAttachment_x
FUNCTION_AT_ADDRESS(bool CCursorAttachment::RemoveAttachment(), CCursorAttachment__RemoveAttachment);
#endif
#ifdef CCursorAttachment__AttachToCursor_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const char* Assigned_Name, const char* Name, int Qty, int IconID), CCursorAttachment__AttachToCursor);
#else
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const char* Name, int Qty), CCursorAttachment__AttachToCursor);
#endif
#endif
#ifdef CCursorAttachment__AttachToCursor1_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char* Assigned_Name, const char* Name, int Qty, int IconID), CCursorAttachment__AttachToCursor1);
#else
FUNCTION_AT_ADDRESS(void CCursorAttachment::AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index, const EqItemGuid& ItemGuid, int ItemID, const char* Name, int Qty), CCursorAttachment__AttachToCursor1);
#endif
#endif
#ifdef CCursorAttachment__Deactivate_x
FUNCTION_AT_ADDRESS(void CCursorAttachment::Deactivate(), CCursorAttachment__Deactivate);
#endif
#ifdef CTextureAnimation__Reset_x
FUNCTION_AT_ADDRESS(void CTextureAnimation::Reset(), CTextureAnimation__Reset);
#endif
#ifdef CEditLabelWnd__CEditLabelWnd_x
FUNCTION_AT_ADDRESS(CEditLabelWnd::CEditLabelWnd(CXWnd*), CEditLabelWnd__CEditLabelWnd);
#endif
#ifdef CEditLabelWnd__Activate_x
FUNCTION_AT_ADDRESS(void CEditLabelWnd::Activate(CXWnd*, char*, int, unsigned long), CEditLabelWnd__Activate);
#endif
#ifdef CEQSuiteTextureLoader__dCEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS(CEQSuiteTextureLoader::~CEQSuiteTextureLoader(), CEQSuiteTextureLoader__dCEQSuiteTextureLoader);
#endif
#ifdef CEQSuiteTextureLoader__CreateTexture_x
FUNCTION_AT_ADDRESS(unsigned int CEQSuiteTextureLoader::CreateTexture(const CUITextureInfo&), CEQSuiteTextureLoader__CreateTexture);
#endif
#ifdef CEQSuiteTextureLoader__UnloadAllTextures_x
FUNCTION_AT_ADDRESS(void CEQSuiteTextureLoader::UnloadAllTextures(), CEQSuiteTextureLoader__UnloadAllTextures);
#endif
#ifdef CEQSuiteTextureLoader__GetTexture_x
FUNCTION_AT_ADDRESS(BMI* CEQSuiteTextureLoader::GetTexture(const CUITextureInfo2& ti), CEQSuiteTextureLoader__GetTexture);
#endif
#ifdef CEQSuiteTextureLoader__GetDefaultUIPath_x
FUNCTION_AT_ADDRESS(const CXStr& CEQSuiteTextureLoader::GetDefaultUIPath(int DirType) const, CEQSuiteTextureLoader__GetDefaultUIPath);
#endif
#ifdef CUITextureInfo__GetName_x
FUNCTION_AT_ADDRESS(CXStr CUITextureInfo::GetName() const, CUITextureInfo__GetName);
#endif
#ifdef CEQSuiteTextureLoader__CEQSuiteTextureLoader_x
FUNCTION_AT_ADDRESS(CEQSuiteTextureLoader::CEQSuiteTextureLoader(), CEQSuiteTextureLoader__CEQSuiteTextureLoader);
#endif
#ifdef CExploreModeWnd__CExploreModeWnd_x
FUNCTION_AT_ADDRESS(CExploreModeWnd::CExploreModeWnd(CXWnd*), CExploreModeWnd__CExploreModeWnd);
#endif
#ifdef CExploreModeWnd__Activate_x
FUNCTION_AT_ADDRESS(void CExploreModeWnd::Activate(), CExploreModeWnd__Activate);
#endif
#ifdef CFacePick__CFacePick_x
FUNCTION_AT_ADDRESS(CFacePick::CFacePick(CXWnd*), CFacePick__CFacePick);
#endif
#ifdef CFacePick__Init_x
FUNCTION_AT_ADDRESS(void CFacePick::Init(), CFacePick__Init);
#endif
#ifdef CFacePick__ShowButtonGroup_x
FUNCTION_AT_ADDRESS(void CFacePick::ShowButtonGroup(int, bool), CFacePick__ShowButtonGroup);
#endif
#ifdef CFacePick__Activate_x
FUNCTION_AT_ADDRESS(void CFacePick::Activate(), CFacePick__Activate);
#endif
#ifdef CFacePick__SetFaceSelectionsFromPlayer_x
FUNCTION_AT_ADDRESS(void CFacePick::SetFaceSelectionsFromPlayer(), CFacePick__SetFaceSelectionsFromPlayer);
#endif
#ifdef CFacePick__CycleThroughFHEB_x
FUNCTION_AT_ADDRESS(void CFacePick::CycleThroughFHEB(int, int), CFacePick__CycleThroughFHEB);
#endif
#ifdef CFactionWnd__CFactionWnd1_x
FUNCTION_AT_ADDRESS(CFactionWnd::CFactionWnd(CXWnd*), CFactionWnd__CFactionWnd);
#endif
#ifdef CFindItemWnd__CFindItemWnd_x
CONSTRUCTOR_AT_ADDRESS(CFindItemWnd::CFindItemWnd(CXWnd*), CFindItemWnd__CFindItemWnd);
#endif
#ifdef CFindItemWnd__Update_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::Update(), CFindItemWnd__Update);
#endif
#ifdef CFindItemWnd__PickupSelectedItem_x
FUNCTION_AT_ADDRESS(void CFindItemWnd::PickupSelectedItem(), CFindItemWnd__PickupSelectedItem);
#endif
#ifdef IString__Append_x
FUNCTION_AT_ADDRESS(void IString2::Append(char* c), IString__Append);
#endif
#ifdef LootFiltersManager__AddItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::AddItemLootFilter(int, int, const char*, int, bool), LootFiltersManager__AddItemLootFilter);
#endif
#ifdef LootFiltersManager__GetItemFilterData_x
FUNCTION_AT_ADDRESS(const ItemFilterData* LootFiltersManager::GetItemFilterData(int), LootFiltersManager__GetItemFilterData);
#endif
#ifdef LootFiltersManager__RemoveItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::RemoveItemLootFilter(int, int), LootFiltersManager__RemoveItemLootFilter);
#endif
#ifdef LootFiltersManager__SetItemLootFilter_x
FUNCTION_AT_ADDRESS(bool LootFiltersManager::SetItemLootFilter(int, int, const char*, int, bool, bool), LootFiltersManager__SetItemLootFilter);
#endif
#ifdef CFeedbackWnd__CFeedbackWnd_x
FUNCTION_AT_ADDRESS(CFeedbackWnd::CFeedbackWnd(CXWnd*), CFeedbackWnd__CFeedbackWnd);
#endif
#ifdef CFeedbackWnd__Activate_x
FUNCTION_AT_ADDRESS(void CFeedbackWnd::Activate(), CFeedbackWnd__Activate);
#endif
#ifdef CFileSelectionWnd__CFileSelectionWnd_x
FUNCTION_AT_ADDRESS(CFileSelectionWnd::CFileSelectionWnd(CXWnd*), CFileSelectionWnd__CFileSelectionWnd);
#endif
#ifdef CFileSelectionWnd__Activate_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::Activate(CXWnd*, int), CFileSelectionWnd__Activate);
#endif
#ifdef CFileSelectionWnd__Callback_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::Callback(bool), CFileSelectionWnd__Callback);
#endif
#ifdef CFileSelectionWnd__MakeFilePath_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::MakeFilePath(), CFileSelectionWnd__MakeFilePath);
#endif
#ifdef CFileSelectionWnd__GoSubdirectory_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::GoSubdirectory(struct _ITEMIDLIST*), CFileSelectionWnd__GoSubdirectory);
#endif
#ifdef CFileSelectionWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::UpdateButtons(), CFileSelectionWnd__UpdateButtons);
#endif
#ifdef CFileSelectionWnd__DirectoryEmpty_x
FUNCTION_AT_ADDRESS(bool CFileSelectionWnd::DirectoryEmpty(IShellFolder*, struct _ITEMIDLIST*), CFileSelectionWnd__DirectoryEmpty);
#endif
#ifdef CFileSelectionWnd__UpdateFileList_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::UpdateFileList(), CFileSelectionWnd__UpdateFileList);
#endif
#ifdef CFileSelectionWnd__ClearFileList_x
FUNCTION_AT_ADDRESS(void CFileSelectionWnd::ClearFileList(), CFileSelectionWnd__ClearFileList);
#endif
#ifdef CFileSelectionWnd__GetPath_x
FUNCTION_AT_ADDRESS(unsigned long CFileSelectionWnd::GetPath(IShellFolder*, struct _ITEMIDLIST*, bool, CXStr&), CFileSelectionWnd__GetPath);
#endif
#ifdef CFileSelectionWnd__GetSelectedFileCount_x
FUNCTION_AT_ADDRESS(int CFileSelectionWnd::GetSelectedFileCount(), CFileSelectionWnd__GetSelectedFileCount);
#endif
#ifdef CFileSelectionWnd__GetSelectedFile_x
FUNCTION_AT_ADDRESS(CXStr CFileSelectionWnd::GetSelectedFile(int), CFileSelectionWnd__GetSelectedFile);
#endif
#ifdef CFriendsWnd__CFriendsWnd_x
FUNCTION_AT_ADDRESS(CFriendsWnd::CFriendsWnd(CXWnd*), CFriendsWnd__CFriendsWnd);
#endif
#ifdef CFriendsWnd__UpdateFriendsList_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::UpdateFriendsList(), CFriendsWnd__UpdateFriendsList);
#endif
#ifdef CFriendsWnd__UpdateIgnoreList_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::UpdateIgnoreList(), CFriendsWnd__UpdateIgnoreList);
#endif
#ifdef CFriendsWnd__Activate_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::Activate(), CFriendsWnd__Activate);
#endif
#ifdef CFriendsWnd__AddFriend_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::AddFriend(), CFriendsWnd__AddFriend);
#endif
#ifdef CFriendsWnd__AddIgnore_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::AddIgnore(), CFriendsWnd__AddIgnore);
#endif
#ifdef CFriendsWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CFriendsWnd::UpdateButtons(), CFriendsWnd__UpdateButtons);
#endif
#ifdef CGemsGameWnd__CGemsGameWnd_x
FUNCTION_AT_ADDRESS(CGemsGameWnd::CGemsGameWnd(CXWnd*), CGemsGameWnd__CGemsGameWnd);
#endif
#ifdef CGemsGameWnd__Init_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Init(), CGemsGameWnd__Init);
#endif
#ifdef CGemsGameWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Activate(), CGemsGameWnd__Activate);
#endif
#ifdef CGemsGameWnd__Restart_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Restart(), CGemsGameWnd__Restart);
#endif
#ifdef CGemsGameWnd__AdvanceToNextWave_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::AdvanceToNextWave(), CGemsGameWnd__AdvanceToNextWave);
#endif
#ifdef CGemsGameWnd__DoMatchScore_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::DoMatchScore(int), CGemsGameWnd__DoMatchScore);
#endif
#ifdef CGemsGameWnd__DrawSpellGem_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::DrawSpellGem(int, CXRect, int, bool) const, CGemsGameWnd__DrawSpellGem);
#endif
#ifdef CGemsGameWnd__SetPause_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::SetPause(bool), CGemsGameWnd__SetPause);
#endif
#ifdef CGemsGameWnd__TogglePause_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::TogglePause(), CGemsGameWnd__TogglePause);
#endif
#ifdef CGemsGameWnd__SetNextUpdate_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::SetNextUpdate(), CGemsGameWnd__SetNextUpdate);
#endif
#ifdef CGemsGameWnd__GetRndBlockImage_x
FUNCTION_AT_ADDRESS(int CGemsGameWnd::GetRndBlockImage(), CGemsGameWnd__GetRndBlockImage);
#endif
#ifdef CGemsGameWnd__BadSpecial_x
FUNCTION_AT_ADDRESS(bool CGemsGameWnd::BadSpecial(int) const, CGemsGameWnd__BadSpecial);
#endif
#ifdef CGemsGameWnd__ActivateSpecialMode_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ActivateSpecialMode(int), CGemsGameWnd__ActivateSpecialMode);
#endif
#ifdef CGemsGameWnd__GetNextBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::GetNextBlock(), CGemsGameWnd__GetNextBlock);
#endif
#ifdef CGemsGameWnd__MoveCurBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MoveCurBlock(int), CGemsGameWnd__MoveCurBlock);
#endif
#ifdef CGemsGameWnd__ProcessMoveCurBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ProcessMoveCurBlock(int), CGemsGameWnd__ProcessMoveCurBlock);
#endif
#ifdef CGemsGameWnd__LegalBlockMove_x
FUNCTION_AT_ADDRESS(bool CGemsGameWnd::LegalBlockMove(int, int, int, int, bool), CGemsGameWnd__LegalBlockMove);
#endif
#ifdef CGemsGameWnd__MarkHigherBlocksFalling_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MarkHigherBlocksFalling(int, int), CGemsGameWnd__MarkHigherBlocksFalling);
#endif
#ifdef CGemsGameWnd__ClearBlock_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ClearBlock(struct _GemsBlock*), CGemsGameWnd__ClearBlock);
#endif
#ifdef CGemsGameWnd__ClearHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ClearHighScores(), CGemsGameWnd__ClearHighScores);
#endif
#ifdef CGemsGameWnd__ReadHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ReadHighScores(), CGemsGameWnd__ReadHighScores);
#endif
#ifdef CGemsGameWnd__WriteHighScores_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::WriteHighScores(), CGemsGameWnd__WriteHighScores);
#endif
#ifdef CGemsGameWnd__CheckForNewHighScore_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::CheckForNewHighScore(), CGemsGameWnd__CheckForNewHighScore);
#endif
#ifdef CGemsGameWnd__ProcessMatches_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::ProcessMatches(int), CGemsGameWnd__ProcessMatches);
#endif
#ifdef CGemsGameWnd__CheckForMatches_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::CheckForMatches(int, int), CGemsGameWnd__CheckForMatches);
#endif
#ifdef CGemsGameWnd__MakeBlockDrop_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::MakeBlockDrop(int, int, int), CGemsGameWnd__MakeBlockDrop);
#endif
#ifdef CGemsGameWnd__Update_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::Update(), CGemsGameWnd__Update);
#endif
#ifdef CGemsGameWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void CGemsGameWnd::UpdateDisplay(), CGemsGameWnd__UpdateDisplay);
#endif
#ifdef CGiveWnd__CGiveWnd_x
FUNCTION_AT_ADDRESS(CGiveWnd::CGiveWnd(CXWnd*), CGiveWnd__CGiveWnd);
#endif
#ifdef CGiveWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGiveWnd::Activate(), CGiveWnd__Activate);
#endif
#ifdef CGiveWnd__UpdateGiveDisplay_x
FUNCTION_AT_ADDRESS(void CGiveWnd::UpdateGiveDisplay(), CGiveWnd__UpdateGiveDisplay);
#endif
#ifdef CGroupSearchFiltersWnd__CGroupSearchFiltersWnd_x
FUNCTION_AT_ADDRESS(CGroupSearchFiltersWnd::CGroupSearchFiltersWnd(CXWnd*), CGroupSearchFiltersWnd__CGroupSearchFiltersWnd);
#endif
#ifdef CGroupSearchFiltersWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::Activate(), CGroupSearchFiltersWnd__Activate);
#endif
#ifdef CGroupSearchFiltersWnd__ClearUiPointers_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::ClearUiPointers(), CGroupSearchFiltersWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__FetchUiPointers_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::FetchUiPointers(), CGroupSearchFiltersWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchFiltersWnd__InitPieces_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::InitPieces(), CGroupSearchFiltersWnd__InitPieces);
#endif
#ifdef CGroupSearchFiltersWnd__ShouldFilterPlayer_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::ShouldFilterPlayer(const char*, const char*) const, CGroupSearchFiltersWnd__ShouldFilterPlayer);
#endif
#ifdef CGroupSearchFiltersWnd__UseExclusiveSearchMode_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::UseExclusiveSearchMode() const, CGroupSearchFiltersWnd__UseExclusiveSearchMode);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseIgnoreListSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleUseIgnoreListSelected(), CGroupSearchFiltersWnd__HandleUseIgnoreListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleUseFriendsListSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleUseFriendsListSelected(), CGroupSearchFiltersWnd__HandleUseFriendsListSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleExcludeGuildsSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleExcludeGuildsSelected(), CGroupSearchFiltersWnd__HandleExcludeGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleDesiredGuildsSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleDesiredGuildsSelected(), CGroupSearchFiltersWnd__HandleDesiredGuildsSelected);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddExcludedGuild_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleAddExcludedGuild(), CGroupSearchFiltersWnd__HandleAddExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveExcludedGuild_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleRemoveExcludedGuild(), CGroupSearchFiltersWnd__HandleRemoveExcludedGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleRemoveAllExcludedGuilds(), CGroupSearchFiltersWnd__HandleRemoveAllExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__HandleAddDesiredGuild_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleAddDesiredGuild(), CGroupSearchFiltersWnd__HandleAddDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveDesiredGuild_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleRemoveDesiredGuild(), CGroupSearchFiltersWnd__HandleRemoveDesiredGuild);
#endif
#ifdef CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::HandleRemoveAllDesiredGuilds(), CGroupSearchFiltersWnd__HandleRemoveAllDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseIgnoreList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::UseIgnoreList() const, CGroupSearchFiltersWnd__UseIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__UseFriendsList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::UseFriendsList() const, CGroupSearchFiltersWnd__UseFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__UseExcludedGuilds_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::UseExcludedGuilds() const, CGroupSearchFiltersWnd__UseExcludedGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__UseDesiredGuilds_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::UseDesiredGuilds() const, CGroupSearchFiltersWnd__UseDesiredGuilds);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInIgnoreList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::NameIsInIgnoreList(const char*) const, CGroupSearchFiltersWnd__NameIsInIgnoreList);
#endif
#ifdef CGroupSearchFiltersWnd__NameIsInFriendsList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::NameIsInFriendsList(const char*) const, CGroupSearchFiltersWnd__NameIsInFriendsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::GuildIsInExcludedGuildsList(const char*) const, CGroupSearchFiltersWnd__GuildIsInExcludedGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::GuildIsInDesiredGuildsList(const char*) const, CGroupSearchFiltersWnd__GuildIsInDesiredGuildsList);
#endif
#ifdef CGroupSearchFiltersWnd__Save_x
FUNCTION_AT_ADDRESS(void CGroupSearchFiltersWnd::Save() const, CGroupSearchFiltersWnd__Save);
#endif
#ifdef CGroupSearchFiltersWnd__Load_x
FUNCTION_AT_ADDRESS(bool CGroupSearchFiltersWnd::Load(), CGroupSearchFiltersWnd__Load);
#endif
#ifdef CGroupSearchWnd__CGroupSearchWnd_x
FUNCTION_AT_ADDRESS(CGroupSearchWnd::CGroupSearchWnd(CXWnd*), CGroupSearchWnd__CGroupSearchWnd);
#endif
#ifdef CGroupSearchWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::Activate(int), CGroupSearchWnd__Activate);
#endif
#ifdef CGroupSearchWnd__ClearUiPointers_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::ClearUiPointers(), CGroupSearchWnd__ClearUiPointers);
#endif
#ifdef CGroupSearchWnd__FetchUiPointers_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::FetchUiPointers(), CGroupSearchWnd__FetchUiPointers);
#endif
#ifdef CGroupSearchWnd__ResetGroupList_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::ResetGroupList(), CGroupSearchWnd__ResetGroupList);
#endif
#ifdef CGroupSearchWnd__AddGroupResult_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::AddGroupResult(struct LfgGroupResult const*), CGroupSearchWnd__AddGroupResult);
#endif
#ifdef CUITextureInfo__dCUITextureInfo_x
FUNCTION_AT_ADDRESS(CUITextureInfo::~CUITextureInfo(), CUITextureInfo__dCUITextureInfo);
#endif
#ifdef CUITexturePiece__dCUITexturePiece_x
FUNCTION_AT_ADDRESS(CUITexturePiece::~CUITexturePiece(), CUITexturePiece__dCUITexturePiece);
#endif
#ifdef STextureAnimationFrame__dSTextureAnimationFrame_x
FUNCTION_AT_ADDRESS(STextureAnimationFrame::~STextureAnimationFrame(), STextureAnimationFrame__dSTextureAnimationFrame);
#endif
#ifdef CGroupSearchWnd__ResetPlayerList_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::ResetPlayerList(), CGroupSearchWnd__ResetPlayerList);
#endif
#ifdef CGroupSearchWnd__AddPlayerResult_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::AddPlayerResult(struct LfgPlayerResult const*), CGroupSearchWnd__AddPlayerResult);
#endif
#ifdef CGroupSearchWnd__InitLfg_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::InitLfg(), CGroupSearchWnd__InitLfg);
#endif
#ifdef CGroupSearchWnd__InitLfp_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::InitLfp(), CGroupSearchWnd__InitLfp);
#endif
#ifdef CGroupSearchWnd__UpdatePlayerLabel_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::UpdatePlayerLabel(), CGroupSearchWnd__UpdatePlayerLabel);
#endif
#ifdef CGroupSearchWnd__UpdateGroupLabel_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::UpdateGroupLabel(), CGroupSearchWnd__UpdateGroupLabel);
#endif
#ifdef CGroupSearchWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::RedirectOnProcessFrameTo(CPageWnd*), CGroupSearchWnd__RedirectOnProcessFrameTo);
#endif
#ifdef CGroupSearchWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*), CGroupSearchWnd__RedirectWndNotificationTo);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageWndNotification_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::PlayerInfoPageWndNotification(CXWnd*, uint32_t, void*), CGroupSearchWnd__PlayerInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageWndNotification_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GroupInfoPageWndNotification(CXWnd*, uint32_t, void*), CGroupSearchWnd__GroupInfoPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerListPageWndNotification_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::PlayerListPageWndNotification(CXWnd*, uint32_t, void*), CGroupSearchWnd__PlayerListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__GroupListPageWndNotification_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GroupListPageWndNotification(CXWnd*, uint32_t, void*), CGroupSearchWnd__GroupListPageWndNotification);
#endif
#ifdef CGroupSearchWnd__PlayerInfoPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::PlayerInfoPageOnProcessFrame(), CGroupSearchWnd__PlayerInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__GroupInfoPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GroupInfoPageOnProcessFrame(), CGroupSearchWnd__GroupInfoPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoPost_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandlePlayerInfoPost(), CGroupSearchWnd__HandlePlayerInfoPost);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoUpdate_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandlePlayerInfoUpdate(), CGroupSearchWnd__HandlePlayerInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandlePlayerInfoRemove_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandlePlayerInfoRemove(), CGroupSearchWnd__HandlePlayerInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoPost_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupInfoPost(), CGroupSearchWnd__HandleGroupInfoPost);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoUpdate_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupInfoUpdate(), CGroupSearchWnd__HandleGroupInfoUpdate);
#endif
#ifdef CGroupSearchWnd__HandleGroupInfoRemove_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupInfoRemove(), CGroupSearchWnd__HandleGroupInfoRemove);
#endif
#ifdef CGroupSearchWnd__HandleSelectAllClasses_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleSelectAllClasses(), CGroupSearchWnd__HandleSelectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleDeselectAllClasses_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleDeselectAllClasses(), CGroupSearchWnd__HandleDeselectAllClasses);
#endif
#ifdef CGroupSearchWnd__HandleOpenFiltersWindow_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleOpenFiltersWindow(), CGroupSearchWnd__HandleOpenFiltersWindow);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForGroups_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleQueryingForGroups(), CGroupSearchWnd__HandleQueryingForGroups);
#endif
#ifdef CGroupSearchWnd__HandleQueryingForPlayers_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleQueryingForPlayers(), CGroupSearchWnd__HandleQueryingForPlayers);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOn_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::SendServerLfgOn(), CGroupSearchWnd__SendServerLfgOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfgOff_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::SendServerLfgOff(), CGroupSearchWnd__SendServerLfgOff);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOn_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::SendServerLfpOn(), CGroupSearchWnd__SendServerLfpOn);
#endif
#ifdef CGroupSearchWnd__SendServerLfpOff_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::SendServerLfpOff(), CGroupSearchWnd__SendServerLfpOff);
#endif
#ifdef CGroupSearchWnd__ShowGroupDetails_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::ShowGroupDetails(struct LfgGroupResult const*), CGroupSearchWnd__ShowGroupDetails);
#endif
#ifdef CGroupSearchWnd__PlayerShouldBeFiltered_x
FUNCTION_AT_ADDRESS(bool CGroupSearchWnd::PlayerShouldBeFiltered(struct LfgPlayerData const*) const, CGroupSearchWnd__PlayerShouldBeFiltered);
#endif
#ifdef CGroupSearchWnd__FilterOutBadWords_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::FilterOutBadWords(const char*, char*) const, CGroupSearchWnd__FilterOutBadWords);
#endif
#ifdef CGroupSearchWnd__LockQueryButtonAtTime_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::LockQueryButtonAtTime(long), CGroupSearchWnd__LockQueryButtonAtTime);
#endif
#ifdef CGroupSearchWnd__UpdateRemainingQueryLockedTime_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::UpdateRemainingQueryLockedTime(long), CGroupSearchWnd__UpdateRemainingQueryLockedTime);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultColSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupResultColSelected(int), CGroupSearchWnd__HandleGroupResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandlePlayerResultColSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandlePlayerResultColSelected(int), CGroupSearchWnd__HandlePlayerResultColSelected);
#endif
#ifdef CGroupSearchWnd__HandleGroupResultRowSelected_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupResultRowSelected(int), CGroupSearchWnd__HandleGroupResultRowSelected);
#endif
#ifdef CGroupSearchWnd__HandleDoubleClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleDoubleClickedOnPlayer(const char*), CGroupSearchWnd__HandleDoubleClickedOnPlayer);
#endif
#ifdef CGroupSearchWnd__HandleNumericSort_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleNumericSort(SListWndSortInfo*), CGroupSearchWnd__HandleNumericSort);
#endif
#ifdef CGroupSearchWnd__HandleGroupMakeupChanged_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::HandleGroupMakeupChanged(), CGroupSearchWnd__HandleGroupMakeupChanged);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::CheckIfCurrentLfgInfoIsValid() const, CGroupSearchWnd__CheckIfCurrentLfgInfoIsValid);
#endif
#ifdef CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::CheckIfCurrentLfpInfoIsValid() const, CGroupSearchWnd__CheckIfCurrentLfpInfoIsValid);
#endif
#ifdef CGroupSearchWnd__UpdateLfgPostingStatus_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::UpdateLfgPostingStatus(), CGroupSearchWnd__UpdateLfgPostingStatus);
#endif
#ifdef CGroupSearchWnd__UpdateLfpPostingStatus_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::UpdateLfpPostingStatus(), CGroupSearchWnd__UpdateLfpPostingStatus);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMinLevel_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetDesiredPlayerMinLevel() const, CGroupSearchWnd__GetDesiredPlayerMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfgLevelRange_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::GetDefaultLfgLevelRange(EQ_PC const*, int*, int*) const, CGroupSearchWnd__GetDefaultLfgLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDefaultLfpLevelRange_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::GetDefaultLfpLevelRange(EQ_PC const*, int*, int*) const, CGroupSearchWnd__GetDefaultLfpLevelRange);
#endif
#ifdef CGroupSearchWnd__GetDesiredPlayerMaxLevel_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetDesiredPlayerMaxLevel() const, CGroupSearchWnd__GetDesiredPlayerMaxLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMinLevel_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetDesiredGroupMinLevel() const, CGroupSearchWnd__GetDesiredGroupMinLevel);
#endif
#ifdef CGroupSearchWnd__GetDesiredGroupMaxLevel_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetDesiredGroupMaxLevel() const, CGroupSearchWnd__GetDesiredGroupMaxLevel);
#endif
#ifdef CGroupSearchWnd__IsLevelRangeValid_x
FUNCTION_AT_ADDRESS(bool CGroupSearchWnd::IsLevelRangeValid(int, int) const, CGroupSearchWnd__IsLevelRangeValid);
#endif
#ifdef CGroupSearchWnd__GetDesiredClassesFlag_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetDesiredClassesFlag() const, CGroupSearchWnd__GetDesiredClassesFlag);
#endif
#ifdef CGroupSearchWnd__GetEqClassType_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GetEqClassType(int) const, CGroupSearchWnd__GetEqClassType);
#endif
#ifdef CGroupSearchWnd__PopUpErrorMessage_x
FUNCTION_AT_ADDRESS(void CGroupSearchWnd::PopUpErrorMessage(int) const, CGroupSearchWnd__PopUpErrorMessage);
#endif
#ifdef Util__SetBit_x
FUNCTION_AT_ADDRESS(int __cdecl Util::SetBit(int, void*, int), Util__SetBit);
#endif
#ifdef _partyGroup__getNumMembers_x
FUNCTION_AT_ADDRESS(int _partyGroup::getNumMembers() const, _partyGroup__getNumMembers);
#endif
#ifdef CGroupWnd__CGroupWnd_x
FUNCTION_AT_ADDRESS(CGroupWnd::CGroupWnd(CXWnd*), CGroupWnd__CGroupWnd);
#endif
#ifdef CGroupWnd__Init_x
FUNCTION_AT_ADDRESS(void CGroupWnd::Init(), CGroupWnd__Init);
#endif
#ifdef CGroupWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGroupWnd::Activate(), CGroupWnd__Activate);
#endif
#ifdef CGroupWnd__SetInvited_x
FUNCTION_AT_ADDRESS(void CGroupWnd::SetInvited(bool), CGroupWnd__SetInvited);
#endif
#ifdef CGroupWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateButtons(), CGroupWnd__UpdateButtons);
#endif
#ifdef CGroupWnd__UpdateDisplay_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits), CGroupWnd__UpdateDisplay);
#endif
#ifdef CGroupWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CGroupWnd::KeyMapUpdated(), CGroupWnd__KeyMapUpdated);
#endif
#ifdef CGroupWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void CGroupWnd::CreateLocalMenu(), CGroupWnd__CreateLocalMenu);
#endif
#ifdef CGroupWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void CGroupWnd::UpdateContextMenu(), CGroupWnd__UpdateContextMenu);
#endif
#ifdef CGuildMgmtWnd__CGuildMgmtWnd_x
FUNCTION_AT_ADDRESS(CGuildMgmtWnd::CGuildMgmtWnd(CXWnd*), CGuildMgmtWnd__CGuildMgmtWnd);
#endif
#ifdef CGuildMgmtWnd__Init_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Init(), CGuildMgmtWnd__Init);
#endif
#ifdef CGuildMgmtWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::UpdateButtons(), CGuildMgmtWnd__UpdateButtons);
#endif
#ifdef CGuildMgmtWnd__Clean_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Clean(), CGuildMgmtWnd__Clean);
#endif
#ifdef CGuildMgmtWnd__SetMOTD_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetMOTD(char*, char*), CGuildMgmtWnd__SetMOTD);
#endif
#ifdef CGuildMgmtWnd__SetPlayerCount_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetPlayerCount(int), CGuildMgmtWnd__SetPlayerCount);
#endif
#ifdef CGuildMgmtWnd__CreatePersonalNotesFilename_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::CreatePersonalNotesFilename(), CGuildMgmtWnd__CreatePersonalNotesFilename);
#endif
#ifdef CGuildMgmtWnd__LoadPersonalNotes_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::LoadPersonalNotes(), CGuildMgmtWnd__LoadPersonalNotes);
#endif
#ifdef CGuildMgmtWnd__SavePersonalNotes_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SavePersonalNotes(), CGuildMgmtWnd__SavePersonalNotes);
#endif
#ifdef CGuildMgmtWnd__GetPersonalNote_x
FUNCTION_AT_ADDRESS(char* CGuildMgmtWnd::GetPersonalNote(char*), CGuildMgmtWnd__GetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__SetPersonalNote_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SetPersonalNote(char*, char*), CGuildMgmtWnd__SetPersonalNote);
#endif
#ifdef CGuildMgmtWnd__AddMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::AddMember(GuildMember*), CGuildMgmtWnd__AddMember);
#endif
#ifdef CGuildMgmtWnd__RemoveMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::RemoveMember(GuildMember*), CGuildMgmtWnd__RemoveMember);
#endif
#ifdef CGuildMgmtWnd__RenameMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::RenameMember(char*, char*), CGuildMgmtWnd__RenameMember);
#endif
#ifdef CGuildMgmtWnd__UpdateListMember_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::UpdateListMember(GuildMember*, int), CGuildMgmtWnd__UpdateListMember);
#endif
#ifdef CGuildMgmtWnd__FindListMember_x
FUNCTION_AT_ADDRESS(int CGuildMgmtWnd::FindListMember(GuildMember*), CGuildMgmtWnd__FindListMember);
#endif
#ifdef CGuildMgmtWnd__Activate_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::Activate(), CGuildMgmtWnd__Activate);
#endif
#ifdef CGuildMgmtWnd__CleanAndRefillListWnd_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::CleanAndRefillListWnd(bool), CGuildMgmtWnd__CleanAndRefillListWnd);
#endif
#ifdef CGuildMgmtWnd__SortList_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::SortList(int, bool), CGuildMgmtWnd__SortList);
#endif
#ifdef CGuildMgmtWnd__DumpToFile_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::DumpToFile(char*), CGuildMgmtWnd__DumpToFile);
#endif
#ifdef CGuildMgmtWnd__LoadINI_x
FUNCTION_AT_ADDRESS(void CGuildMgmtWnd::LoadINI(), CGuildMgmtWnd__LoadINI);
#endif
#ifdef CGuild__GetGuildMotd_x
FUNCTION_AT_ADDRESS(char* CGuild::GetGuildMotd(), CGuild__GetGuildMotd);
#endif
#ifdef CGuild__GetGuildMotdAuthor_x
FUNCTION_AT_ADDRESS(char* CGuild::GetGuildMotdAuthor(), CGuild__GetGuildMotdAuthor);
#endif
#ifdef EQPlayer__GetGuild_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetGuild() const, EQPlayer__GetGuild);
#endif
#ifdef CHelpWnd__CHelpWnd_x
FUNCTION_AT_ADDRESS(CHelpWnd::CHelpWnd(CXWnd*), CHelpWnd__CHelpWnd);
#endif
#ifdef CHelpWnd__SetFile_x
FUNCTION_AT_ADDRESS(void CHelpWnd::SetFile(CXStr), CHelpWnd__SetFile);
#endif
#ifdef CHotButtonWnd__CHotButtonWnd_x
FUNCTION_AT_ADDRESS(CHotButtonWnd::CHotButtonWnd(CXWnd*), CHotButtonWnd__CHotButtonWnd);
#endif
#ifdef CHotButtonWnd__Init_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::Init(), CHotButtonWnd__Init);
#endif
#ifdef CHotButtonWnd__Activate_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::Activate(), CHotButtonWnd__Activate);
#endif
#ifdef CHotButtonWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::UpdatePage(), CHotButtonWnd__UpdatePage);
#endif
#ifdef CHotButtonWnd__DoHotButton_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButton(int, int, int), CHotButtonWnd__DoHotButton);
#else
FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButton(int, int), CHotButtonWnd__DoHotButton);
#endif
#endif
#ifdef CHotButton__SetButtonSize_x
FUNCTION_AT_ADDRESS(void CHotButton::SetButtonSize(int percent, bool bUpdateParent), CHotButton__SetButtonSize);
#endif
#ifdef CHotButtonWnd__DoHotButtonRightClick_x
FUNCTION_AT_ADDRESS(void CHotButtonWnd::DoHotButtonRightClick(int), CHotButtonWnd__DoHotButtonRightClick);
#endif
#ifdef CInspectWnd__CInspectWnd_x
FUNCTION_AT_ADDRESS(CInspectWnd::CInspectWnd(CXWnd*), CInspectWnd__CInspectWnd);
#endif
#ifdef CInspectWnd__Init_x
FUNCTION_AT_ADDRESS(void CInspectWnd::Init(), CInspectWnd__Init);
#endif
#ifdef CInspectWnd__Activate_x
FUNCTION_AT_ADDRESS(void CInspectWnd::Activate(struct _inspect*), CInspectWnd__Activate);
#endif
#ifdef CInspectWnd__AcceptInspectText_x
FUNCTION_AT_ADDRESS(void CInspectWnd::AcceptInspectText(), CInspectWnd__AcceptInspectText);
#endif
#ifdef CInspectWnd__PlayerBeingDeleted_x
FUNCTION_AT_ADDRESS(void CInspectWnd::PlayerBeingDeleted(EQPlayer*), CInspectWnd__PlayerBeingDeleted);
#endif
#ifdef CInventoryWnd__CInventoryWnd_x
FUNCTION_AT_ADDRESS(CInventoryWnd::CInventoryWnd(CXWnd*), CInventoryWnd__CInventoryWnd);
#endif
#ifdef CInventoryWnd__Init_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::Init(), CInventoryWnd__Init);
#endif
#ifdef CInventoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::Activate(), CInventoryWnd__Activate);
#endif
#ifdef CInventoryWnd__DestroyHeld_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::DestroyHeld(), CInventoryWnd__DestroyHeld);
#endif
#ifdef CInventoryWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::ClickedMoneyButton(int, int), CInventoryWnd__ClickedMoneyButton);
#endif
#ifdef CInventoryWnd__GetInventoryQtyFromCoinType_x
FUNCTION_AT_ADDRESS(long CInventoryWnd::GetInventoryQtyFromCoinType(int), CInventoryWnd__GetInventoryQtyFromCoinType);
#endif
#ifdef CInventoryWnd__UpdateMoneyDisplay_x
FUNCTION_AT_ADDRESS(void CInventoryWnd::UpdateMoneyDisplay(), CInventoryWnd__UpdateMoneyDisplay);
#endif
#ifdef CInvSlot__CInvSlot_x
FUNCTION_AT_ADDRESS(CInvSlot::CInvSlot(), CInvSlot__CInvSlot);
#endif
#ifdef CInvSlot__GetItemBase_x
FUNCTION_AT_ADDRESS(void CInvSlot::GetItemBase(CONTENTS**), CInvSlot__GetItemBase);
#endif
#ifdef CInvSlot__UpdateItem_x
FUNCTION_AT_ADDRESS(void CInvSlot::UpdateItem(), CInvSlot__UpdateItem);
#endif
#ifdef CInvSlot__SetInvSlotWnd_x
FUNCTION_AT_ADDRESS(void CInvSlot::SetInvSlotWnd(CInvSlotWnd*), CInvSlot__SetInvSlotWnd);
#endif
#ifdef CInvSlot__SetItem_x
FUNCTION_AT_ADDRESS(void CInvSlot::SetItem(EQ_Item*), CInvSlot__SetItem);
#endif
#ifdef CInvSlot__SliderComplete_x
FUNCTION_AT_ADDRESS(void CInvSlot::SliderComplete(int), CInvSlot__SliderComplete);
#endif
#ifdef CInvSlot__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonUp(CXPoint, bool), CInvSlot__HandleLButtonUp);
#endif
#ifdef CInvSlot__HandleLButtonHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonHeld(CXPoint), CInvSlot__HandleLButtonHeld);
#endif
#ifdef CInvSlot__DoDrinkEatPoison_x
FUNCTION_AT_ADDRESS(void CInvSlot::DoDrinkEatPoison(EQ_Item*, int), CInvSlot__DoDrinkEatPoison);
#endif
#ifdef CInvSlot__HandleRButtonUp_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonUp(const CXPoint&), CInvSlot__HandleRButtonUp);
#endif
#ifdef CInvSlot__HandleRButtonHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonHeld(CXPoint), CInvSlot__HandleRButtonHeld);
#endif
#ifdef CInvSlot__HandleRButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonUpAfterHeld(CXPoint), CInvSlot__HandleRButtonUpAfterHeld);
#endif
#ifdef CInvSlot__IllegalBigBank_x
FUNCTION_AT_ADDRESS(bool CInvSlot::IllegalBigBank(int), CInvSlot__IllegalBigBank);
#endif
#ifdef CInvSlotMgr__CInvSlotMgr_x
FUNCTION_AT_ADDRESS(CInvSlotMgr::CInvSlotMgr(), CInvSlotMgr__CInvSlotMgr);
#endif
#ifdef CInvSlotMgr__MoveItem_x
FUNCTION_AT_ADDRESS(bool CInvSlotMgr::MoveItem(ItemGlobalIndex* from, ItemGlobalIndex* to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag, bool MoveToIntoFromBag), CInvSlotMgr__MoveItem);
#endif
#ifdef CInvSlotMgr__CreateInvSlot_x
FUNCTION_AT_ADDRESS(CInvSlot* CInvSlotMgr::CreateInvSlot(CInvSlotWnd*), CInvSlotMgr__CreateInvSlot);
#endif
#ifdef CInvSlotMgr__FindInvSlot_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(CInvSlot* CInvSlotMgr::FindInvSlot(int, int, int, bool), CInvSlotMgr__FindInvSlot);
#else
FUNCTION_AT_ADDRESS(CInvSlot* CInvSlotMgr::FindInvSlot(int, int), CInvSlotMgr__FindInvSlot);
#endif
#endif
#ifdef CInvSlotMgr__SelectSlot_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::SelectSlot(CInvSlot*), CInvSlotMgr__SelectSlot);
#endif
#ifdef CInvSlotMgr__UpdateSlots_x
FUNCTION_AT_ADDRESS(void CInvSlotMgr::UpdateSlots(), CInvSlotMgr__UpdateSlots);
#endif
#ifdef CItemDisplayWnd__UpdateStrings_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::UpdateStrings(), CItemDisplayWnd__UpdateStrings);
#endif
#ifdef CItemDisplayWnd__InsertAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::InsertAugmentRequest(int AugSlot), CItemDisplayWnd__InsertAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RemoveAugmentRequest_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RemoveAugmentRequest(int AugSlot), CItemDisplayWnd__RemoveAugmentRequest);
#endif
#ifdef CItemDisplayWnd__RequestConvertItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::RequestConvertItem(), CItemDisplayWnd__RequestConvertItem);
#endif
#ifdef CItemDisplayWnd__CItemDisplayWnd_x
CONSTRUCTOR_AT_ADDRESS(CItemDisplayWnd::CItemDisplayWnd(CXWnd*), CItemDisplayWnd__CItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__dCItemDisplayWnd_x
FUNCTION_AT_ADDRESS(CItemDisplayWnd::~CItemDisplayWnd(), CItemDisplayWnd__dCItemDisplayWnd);
#endif
#ifdef CItemDisplayWnd__SetItem_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetItem(PCONTENTS* pCont, int flags), CItemDisplayWnd__SetItem);
#endif
#ifdef CItemDisplayWnd__AboutToShow_x
FUNCTION_AT_ADDRESS(bool CItemDisplayWnd::AboutToShow(), CItemDisplayWnd__AboutToShow);
#endif
#ifdef CItemDisplayWnd__WndNotification_x
FUNCTION_AT_ADDRESS(int CItemDisplayWnd::WndNotification(CXWnd*, uint32_t, void*), CItemDisplayWnd__WndNotification);
#endif
#ifdef CItemDisplayWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetItemText(char*), CItemDisplayWnd__SetItemText);
#endif
#ifdef CItemDisplayWnd__GetSizeString_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::GetSizeString(int, char*), CItemDisplayWnd__GetSizeString);
#endif
#ifdef CItemDisplayWnd__CreateRaceString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateRaceString(EQ_Equipment*), CItemDisplayWnd__CreateRaceString);
#endif
#ifdef CItemDisplayWnd__CreateClassString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateClassString(EQ_Equipment*), CItemDisplayWnd__CreateClassString);
#endif
#ifdef CItemDisplayWnd__CreateMealSizeString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateMealSizeString(EQ_Equipment*), CItemDisplayWnd__CreateMealSizeString);
#endif
#ifdef CItemDisplayWnd__CreateModString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateModString(EQ_Equipment*, int, int, int*), CItemDisplayWnd__CreateModString);
#endif
#ifdef CItemDisplayWnd__CreateEquipmentStatusString_x
FUNCTION_AT_ADDRESS(CXStr CItemDisplayWnd::CreateEquipmentStatusString(EQ_Item*), CItemDisplayWnd__CreateEquipmentStatusString);
#endif
#ifdef CItemDisplayWnd__SetSpell_x
FUNCTION_AT_ADDRESS(void CItemDisplayWnd::SetSpell(int SpellID, bool HasSpellDescr, int), CItemDisplayWnd__SetSpell);
#endif
#ifdef CJournalCatWnd__CJournalCatWnd_x
FUNCTION_AT_ADDRESS(CJournalCatWnd::CJournalCatWnd(CXWnd*), CJournalCatWnd__CJournalCatWnd);
#endif
#ifdef CJournalCatWnd__Init_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::Init(), CJournalCatWnd__Init);
#endif
#ifdef CJournalCatWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::UpdateAll(bool), CJournalCatWnd__UpdateAll);
#endif
#ifdef CJournalCatWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::UpdateButtons(), CJournalCatWnd__UpdateButtons);
#endif
#ifdef CJournalCatWnd__SelectCategory_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::SelectCategory(int), CJournalCatWnd__SelectCategory);
#endif
#ifdef CJournalCatWnd__Clean_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::Clean(), CJournalCatWnd__Clean);
#endif
#ifdef CJournalCatWnd__BuildList_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::BuildList(), CJournalCatWnd__BuildList);
#endif
#ifdef CJournalCatWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::UpdateListWnd(bool), CJournalCatWnd__UpdateListWnd);
#endif
#ifdef CJournalCatWnd__Activate_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::Activate(), CJournalCatWnd__Activate);
#endif
#ifdef CJournalCatWnd__SortList_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::SortList(int, bool), CJournalCatWnd__SortList);
#endif
#ifdef CJournalCatWnd__LoadINI_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::LoadINI(), CJournalCatWnd__LoadINI);
#endif
#ifdef CJournalCatWnd__StoreINI_x
FUNCTION_AT_ADDRESS(void CJournalCatWnd::StoreINI(), CJournalCatWnd__StoreINI);
#endif
#ifdef CJournalNPCWnd__CJournalNPCWnd_x
FUNCTION_AT_ADDRESS(CJournalNPCWnd::CJournalNPCWnd(CXWnd*), CJournalNPCWnd__CJournalNPCWnd);
#endif
#ifdef CJournalNPCWnd__Init_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::Init(), CJournalNPCWnd__Init);
#endif
#ifdef CJournalNPCWnd__Activate_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::Activate(), CJournalNPCWnd__Activate);
#endif
#ifdef CJournalNPCWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::UpdateAll(bool), CJournalNPCWnd__UpdateAll);
#endif
#ifdef CJournalNPCWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::UpdateListWnd(bool), CJournalNPCWnd__UpdateListWnd);
#endif
#ifdef CJournalNPCWnd__SelectNPCIndex_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::SelectNPCIndex(int), CJournalNPCWnd__SelectNPCIndex);
#endif
#ifdef CJournalNPCWnd__UpdateCategories_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::UpdateCategories(), CJournalNPCWnd__UpdateCategories);
#endif
#ifdef CJournalNPCWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::UpdateButtons(), CJournalNPCWnd__UpdateButtons);
#endif
#ifdef CJournalNPCWnd__EnterIntoJournal_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::EnterIntoJournal(char*, float, float, float, char*), CJournalNPCWnd__EnterIntoJournal);
#endif
#ifdef CJournalNPCWnd__DoBackups_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::DoBackups(CXStr), CJournalNPCWnd__DoBackups);
#endif
#ifdef CJournalNPCWnd__LoadJournal_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::LoadJournal(int), CJournalNPCWnd__LoadJournal);
#endif
#ifdef CJournalNPCWnd__SaveJournal_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::SaveJournal(), CJournalNPCWnd__SaveJournal);
#endif
#ifdef CJournalNPCWnd__BuildList_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::BuildList(), CJournalNPCWnd__BuildList);
#endif
#ifdef CJournalNPCWnd__SortList_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::SortList(int, bool), CJournalNPCWnd__SortList);
#endif
#ifdef CJournalNPCWnd__GetLogState_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::GetLogState(), CJournalNPCWnd__GetLogState);
#endif
#ifdef CJournalNPCWnd__StoreLogState_x
FUNCTION_AT_ADDRESS(void CJournalNPCWnd::StoreLogState(), CJournalNPCWnd__StoreLogState);
#endif
#ifdef CJournalTextWnd__CJournalTextWnd_x
FUNCTION_AT_ADDRESS(CJournalTextWnd::CJournalTextWnd(CXWnd*), CJournalTextWnd__CJournalTextWnd);
#endif
#ifdef CJournalTextWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::UpdateAll(bool), CJournalTextWnd__UpdateAll);
#endif
#ifdef CJournalTextWnd__UpdateCategories_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::UpdateCategories(), CJournalTextWnd__UpdateCategories);
#endif
#ifdef CJournalTextWnd__Activate_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::Activate(), CJournalTextWnd__Activate);
#endif
#ifdef CJournalTextWnd__SetSearch_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::SetSearch(CXStr), CJournalTextWnd__SetSearch);
#endif
#ifdef CJournalTextWnd__Clear_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::Clear(), CJournalTextWnd__Clear);
#endif
#ifdef CJournalTextWnd__UpdateListWnd_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::UpdateListWnd(bool), CJournalTextWnd__UpdateListWnd);
#endif
#ifdef CJournalTextWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::UpdateButtons(), CJournalTextWnd__UpdateButtons);
#endif
#ifdef CJournalTextWnd__DisplayNPC_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::DisplayNPC(JournalNPC*), CJournalTextWnd__DisplayNPC);
#endif
#ifdef CJournalTextWnd__BuildList_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::BuildList(), CJournalTextWnd__BuildList);
#endif
#ifdef CJournalTextWnd__SelectEntryIndex_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::SelectEntryIndex(int), CJournalTextWnd__SelectEntryIndex);
#endif
#ifdef CJournalTextWnd__SortList_x
FUNCTION_AT_ADDRESS(void CJournalTextWnd::SortList(int, bool), CJournalTextWnd__SortList);
#endif
#ifdef CLoadskinWnd__CLoadskinWnd_x
FUNCTION_AT_ADDRESS(CLoadskinWnd::CLoadskinWnd(CXWnd*), CLoadskinWnd__CLoadskinWnd);
#endif
#ifdef CLoadskinWnd__UpdateSkinList_x
FUNCTION_AT_ADDRESS(void CLoadskinWnd::UpdateSkinList(), CLoadskinWnd__UpdateSkinList);
#endif
#ifdef CLoadskinWnd__Activate_x
FUNCTION_AT_ADDRESS(void CLoadskinWnd::Activate(), CLoadskinWnd__Activate);
#endif
#ifdef CLootWnd__CLootWnd_x
FUNCTION_AT_ADDRESS(CLootWnd::CLootWnd(CXWnd*), CLootWnd__CLootWnd);
#endif
#ifdef CLootWnd__Init_x
FUNCTION_AT_ADDRESS(void CLootWnd::Init(), CLootWnd__Init);
#endif
#ifdef CLootWnd__Activate_x
FUNCTION_AT_ADDRESS(void CLootWnd::Activate(unsigned char, long, long, long, long), CLootWnd__Activate);
#endif
#ifdef CLootWnd__Deactivate1_x
FUNCTION_AT_ADDRESS(void CLootWnd::Deactivate(bool), CLootWnd__Deactivate1);
#endif
#ifdef CLootWnd__LootAll_x
FUNCTION_AT_ADDRESS(void CLootWnd::LootAll(bool), CLootWnd__LootAll);
#endif
#ifdef CLootWnd__FinalizeLoot_x
FUNCTION_AT_ADDRESS(void CLootWnd::FinalizeLoot(), CLootWnd__FinalizeLoot);
#endif
#ifdef CLootWnd__AddEquipmentToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddEquipmentToLootArray(EQ_Item*), CLootWnd__AddEquipmentToLootArray);
#endif
#ifdef CLootWnd__AddNoteToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddNoteToLootArray(EQ_Item*), CLootWnd__AddNoteToLootArray);
#endif
#ifdef CLootWnd__AddContainerToLootArray_x
FUNCTION_AT_ADDRESS(void CLootWnd::AddContainerToLootArray(EQ_Item*), CLootWnd__AddContainerToLootArray);
#endif
#ifdef CLootWnd__RequestLootSlot_x
FUNCTION_AT_ADDRESS(void CLootWnd::RequestLootSlot(int, bool), CLootWnd__RequestLootSlot);
#endif
#ifdef CLootWnd__SlotLooted_x
FUNCTION_AT_ADDRESS(void CLootWnd::SlotLooted(int), CLootWnd__SlotLooted);
#endif
#ifdef CMapToolbarWnd__CMapToolbarWnd_x
FUNCTION_AT_ADDRESS(CMapToolbarWnd::CMapToolbarWnd(CXWnd*), CMapToolbarWnd__CMapToolbarWnd);
#endif
#ifdef CMapToolbarWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMapToolbarWnd::Activate(), CMapToolbarWnd__Activate);
#endif
#ifdef CMapToolbarWnd__SetAutoMapButton_x
FUNCTION_AT_ADDRESS(void CMapToolbarWnd::SetAutoMapButton(bool), CMapToolbarWnd__SetAutoMapButton);
#endif
#ifdef CEditLabelWnd__GetLabelText_x
FUNCTION_AT_ADDRESS(CXStr CEditLabelWnd::GetLabelText(), CEditLabelWnd__GetLabelText);
#endif
#ifdef CMapViewWnd__IsMappingEnabled_x
FUNCTION_AT_ADDRESS(bool CMapViewWnd::IsMappingEnabled(), CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd_x
CONSTRUCTOR_AT_ADDRESS(CMapViewWnd::CMapViewWnd(CXWnd*), CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Init(), CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Activate(), CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::ActivateAutoMapping(), CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::DeactivateAutoMapping(), CMapViewWnd__DeactivateAutoMapping);
#endif
#ifdef CMapViewWnd__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int CMapViewWnd::HandleLButtonDown(const CXPoint&, uint32_t), CMapViewWnd__HandleLButtonDown);
#endif
#ifdef CMapViewWnd__GetWorldCoordinates_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::GetWorldCoordinates(float*), CMapViewWnd__GetWorldCoordinates);
#endif
#ifdef MapViewMap__MapViewMap_x
FUNCTION_AT_ADDRESS(MapViewMap::MapViewMap(), MapViewMap__MapViewMap);
#endif
#ifdef MapViewMap__dMapViewMap_x
FUNCTION_AT_ADDRESS(MapViewMap::~MapViewMap(), MapViewMap__dMapViewMap);
#endif
#ifdef MapViewMap__Clear_x
FUNCTION_AT_ADDRESS(void MapViewMap::Clear(), MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::StartLine(float, float, float), MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::EndLine(float, float, float), MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(), MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddPoint(float, float, float), MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddLabel(float, float, float, unsigned long, int, char*), MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::RecalcLabelExtents(struct _mapviewlabel*), MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(), MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::MoveLabel(struct _mapviewlabel*, float, float, float), MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets_x
FUNCTION_AT_ADDRESS(void MapViewMap::CalcLabelRenderOffsets(CXRect), MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible_x
FUNCTION_AT_ADDRESS(bool MapViewMap::IsLayerVisible(int), MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea_x
FUNCTION_AT_ADDRESS(bool MapViewMap::PointInMapViewArea(CXPoint, CXRect), MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues_x
FUNCTION_AT_ADDRESS(void MapViewMap::PreCalcRenderValues(), MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::TransformPoint(struct T3D_XYZ*), MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw_x
FUNCTION_AT_ADDRESS(void MapViewMap::Draw(CXRect), MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine_x
FUNCTION_AT_ADDRESS(bool MapViewMap::DrawClippedLine(struct T3D_XYZ*, struct T3D_RGB, CXRect), MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save_x
FUNCTION_AT_ADDRESS(void MapViewMap::Save(char*), MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx_x
FUNCTION_AT_ADDRESS(void MapViewMap::SaveEx(char*, int), MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load_x
FUNCTION_AT_ADDRESS(void MapViewMap::Load(char*), MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx_x
FUNCTION_AT_ADDRESS(bool MapViewMap::LoadEx(char*, int), MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetCurrentColor(), MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetCurrentColor(unsigned long), MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLine(struct _mapviewline*), MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLineColor(unsigned long), MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetMarkedLineColor(), MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer_x
FUNCTION_AT_ADDRESS(void MapViewMap::ClearActiveLayer(), MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(struct _mapviewline*), MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(struct _mapviewlabel*), MapViewMap__RemoveLabel1);
#endif
#ifdef CXRect__Normalize_x
FUNCTION_AT_ADDRESS(void CXRect::Normalize(), CXRect__Normalize);
#endif
#ifdef CXRect__operator_and_x
FUNCTION_AT_ADDRESS(CXRect CXRect::operator&(CXRect) const, CXRect__operator_and);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect_x
FUNCTION_AT_ADDRESS(void MapViewMap::JoinLinesAtIntersect(bool), MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoneExtents(int, int, int, int), MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoom(float), MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMinZ(), MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMaxZ(), MapViewMap__GetMaxZ);
#endif
#ifdef CMerchantWnd__CMerchantWnd_x
FUNCTION_AT_ADDRESS(CMerchantWnd::CMerchantWnd(CXWnd*), CMerchantWnd__CMerchantWnd);
#endif
#ifdef CMerchantWnd__Init_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::Init(), CMerchantWnd__Init);
#endif
#ifdef CMerchantWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::Activate(EQPlayer*, float), CMerchantWnd__Activate);
#endif
#ifdef CMerchantWnd__HandleBuy_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::HandleBuy(int), CMerchantWnd__HandleBuy);
#endif
#ifdef CMerchantWnd__HandleSell_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::HandleSell(int), CMerchantWnd__HandleSell);
#endif
#ifdef CMerchantWnd__UpdateBuySellButtons_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::UpdateBuySellButtons(), CMerchantWnd__UpdateBuySellButtons);
#endif
#ifdef CMerchantWnd__SelectBuySellSlot_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex*, int Unknown), CMerchantWnd__SelectBuySellSlot);
#else
FUNCTION_AT_ADDRESS(int CMerchantWnd::SelectBuySellSlot(ItemGlobalIndex*), CMerchantWnd__SelectBuySellSlot);
#endif
#endif
#ifdef CMerchantWnd__DisplayBuyOrSellPrice_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::DisplayBuyOrSellPrice(bool, EQ_Item*), CMerchantWnd__DisplayBuyOrSellPrice);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestGetItem_x
FUNCTION_AT_ADDRESS(bool CMerchantWnd::PurchasePageHandler::RequestGetItem(int), CMerchantWnd__PurchasePageHandler__RequestGetItem);
#endif
#ifdef CMerchantWnd__FinishBuyingItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::FinishBuyingItem(struct _sell_msg*), CMerchantWnd__FinishBuyingItem);
#endif
#ifdef CMerchantWnd__PurchasePageHandler__RequestPutItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::PurchasePageHandler::RequestPutItem(int), CMerchantWnd__PurchasePageHandler__RequestPutItem);
#endif
#ifdef CMerchantWnd__FinishSellingItem_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::FinishSellingItem(struct _sell_msg*), CMerchantWnd__FinishSellingItem);
#endif
#ifdef CMerchantWnd__AddEquipmentToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddEquipmentToMercArray(EQ_Equipment*), CMerchantWnd__AddEquipmentToMercArray);
#endif
#ifdef CMerchantWnd__AddNoteToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddNoteToMercArray(EQ_Note*), CMerchantWnd__AddNoteToMercArray);
#endif
#ifdef CMerchantWnd__AddContainerToMercArray_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::AddContainerToMercArray(EQ_Container*), CMerchantWnd__AddContainerToMercArray);
#endif
#ifdef CMerchantWnd__ClearMerchantSlot_x
FUNCTION_AT_ADDRESS(void CMerchantWnd::ClearMerchantSlot(int), CMerchantWnd__ClearMerchantSlot);
#endif
#ifdef CMusicPlayerWnd__CMusicPlayerWnd_x
FUNCTION_AT_ADDRESS(CMusicPlayerWnd::CMusicPlayerWnd(CXWnd*), CMusicPlayerWnd__CMusicPlayerWnd);
#endif
#ifdef CMusicPlayerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::Activate(), CMusicPlayerWnd__Activate);
#endif
#ifdef CMusicPlayerWnd__AutoStart_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::AutoStart(), CMusicPlayerWnd__AutoStart);
#endif
#ifdef CMusicPlayerWnd__Update_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::Update(), CMusicPlayerWnd__Update);
#endif
#ifdef CMusicPlayerWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CMusicPlayerWnd::UpdateButtons(), CMusicPlayerWnd__UpdateButtons);
#endif
#ifdef CNoteWnd__CNoteWnd_x
FUNCTION_AT_ADDRESS(CNoteWnd::CNoteWnd(CXWnd*), CNoteWnd__CNoteWnd);
#endif
#ifdef CNoteWnd__Activate_x
FUNCTION_AT_ADDRESS(void CNoteWnd::Activate(), CNoteWnd__Activate);
#endif
#ifdef CNoteWnd__CheckNote_x
FUNCTION_AT_ADDRESS(bool CNoteWnd::CheckNote(EQ_Note*), CNoteWnd__CheckNote);
#endif
#ifdef CNoteWnd__SetNote_x
FUNCTION_AT_ADDRESS(void CNoteWnd::SetNote(char*), CNoteWnd__SetNote);
#endif
#ifdef COptionsWnd__FillChatFilterList_x
FUNCTION_AT_ADDRESS(void COptionsWnd::FillChatFilterList(), COptionsWnd__FillChatFilterList);
#endif
#ifdef COptionsWnd__COptionsWnd_x
FUNCTION_AT_ADDRESS(COptionsWnd::COptionsWnd(CXWnd*), COptionsWnd__COptionsWnd);
#endif
#ifdef COptionsWnd__SyncGeneralPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncGeneralPage(), COptionsWnd__SyncGeneralPage);
#endif
#ifdef COptionsWnd__SyncDisplayPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncDisplayPage(), COptionsWnd__SyncDisplayPage);
#endif
#ifdef COptionsWnd__SyncMousePage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncMousePage(), COptionsWnd__SyncMousePage);
#endif
#ifdef COptionsWnd__SyncChatPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncChatPage(), COptionsWnd__SyncChatPage);
#endif
#ifdef COptionsWnd__SyncColorPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SyncColorPage(), COptionsWnd__SyncColorPage);
#endif
#ifdef COptionsWnd__InitKeyboardPage_x
FUNCTION_AT_ADDRESS(void COptionsWnd::InitKeyboardPage(), COptionsWnd__InitKeyboardPage);
#endif
#ifdef COptionsWnd__InitKeyboardAssignments_x
FUNCTION_AT_ADDRESS(void COptionsWnd::InitKeyboardAssignments(), COptionsWnd__InitKeyboardAssignments);
#endif
#ifdef COptionsWnd__RefreshCurrentKeyboardAssignmentList_x
FUNCTION_AT_ADDRESS(void COptionsWnd::RefreshCurrentKeyboardAssignmentList(), COptionsWnd__RefreshCurrentKeyboardAssignmentList);
#endif
#ifdef COptionsWnd__AddKeyboardAssignment_x
FUNCTION_AT_ADDRESS(void COptionsWnd::AddKeyboardAssignment(int, int, int), COptionsWnd__AddKeyboardAssignment);
#endif
#ifdef COptionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void COptionsWnd::Activate(), COptionsWnd__Activate);
#endif
#ifdef COptionsWnd__ResetKeysToDefault_x
FUNCTION_AT_ADDRESS(void COptionsWnd::ResetKeysToDefault(), COptionsWnd__ResetKeysToDefault);
#endif
#ifdef COptionsWnd__RedirectOnProcessFrameTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectOnProcessFrameTo(CPageWnd*), COptionsWnd__RedirectOnProcessFrameTo);
#endif
#ifdef COptionsWnd__RedirectWndNotificationTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*), COptionsWnd__RedirectWndNotificationTo);
#endif
#ifdef COptionsWnd__RedirectHandleKeyboardMsgTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectHandleKeyboardMsgTo(CPageWnd*, uint32_t, uint32_t, bool), COptionsWnd__RedirectHandleKeyboardMsgTo);
#endif
#ifdef COptionsWnd__RedirectDeactivateTo_x
FUNCTION_AT_ADDRESS(int COptionsWnd::RedirectDeactivateTo(CPageWnd*), COptionsWnd__RedirectDeactivateTo);
#endif
#ifdef COptionsWnd__GeneralPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::GeneralPageOnProcessFrame(), COptionsWnd__GeneralPageOnProcessFrame);
#endif
#ifdef COptionsWnd__GeneralPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::GeneralPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__GeneralPageWndNotification);
#endif
#ifdef COptionsWnd__DisplayPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::DisplayPageOnProcessFrame(), COptionsWnd__DisplayPageOnProcessFrame);
#endif
#ifdef COptionsWnd__DisplayPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::DisplayPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__DisplayPageWndNotification);
#endif
#ifdef COptionsWnd__MousePageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::MousePageOnProcessFrame(), COptionsWnd__MousePageOnProcessFrame);
#endif
#ifdef COptionsWnd__MousePageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::MousePageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__MousePageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__KeyboardPageWndNotification);
#endif
#ifdef COptionsWnd__KeyboardPageHandleKeyboardMsg_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageHandleKeyboardMsg(uint32_t, uint32_t, bool), COptionsWnd__KeyboardPageHandleKeyboardMsg);
#endif
#ifdef COptionsWnd__KeyboardPageDeactivate_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageDeactivate(), COptionsWnd__KeyboardPageDeactivate);
#endif
#ifdef COptionsWnd__KeyboardPageCancelKeypressAssignment_x
FUNCTION_AT_ADDRESS(void COptionsWnd::KeyboardPageCancelKeypressAssignment(), COptionsWnd__KeyboardPageCancelKeypressAssignment);
#endif
#ifdef COptionsWnd__ChatPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ChatPageOnProcessFrame(), COptionsWnd__ChatPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ColorPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ColorPageOnProcessFrame(), COptionsWnd__ColorPageOnProcessFrame);
#endif
#ifdef COptionsWnd__ChatPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ChatPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__ChatPageWndNotification);
#endif
#ifdef COptionsWnd__ColorPageWndNotification_x
FUNCTION_AT_ADDRESS(int COptionsWnd::ColorPageWndNotification(CXWnd*, uint32_t, void*), COptionsWnd__ColorPageWndNotification);
#endif
#ifdef COptionsWnd__RestoreDefaultColors_x
FUNCTION_AT_ADDRESS(void COptionsWnd::RestoreDefaultColors(), COptionsWnd__RestoreDefaultColors);
#endif
#ifdef COptionsWnd__SetBagOptions_x
FUNCTION_AT_ADDRESS(void COptionsWnd::SetBagOptions(int, int), COptionsWnd__SetBagOptions);
#endif
#ifdef CPetInfoWnd__CPetInfoWnd_x
FUNCTION_AT_ADDRESS(CPetInfoWnd::CPetInfoWnd(CXWnd*), CPetInfoWnd__CPetInfoWnd);
#endif
#ifdef CPetInfoWnd__Activate_x
FUNCTION_AT_ADDRESS(void CPetInfoWnd::Activate(), CPetInfoWnd__Activate);
#endif
#ifdef CPetInfoWnd__SetShowOnSummon_x
FUNCTION_AT_ADDRESS(void CPetInfoWnd::SetShowOnSummon(bool), CPetInfoWnd__SetShowOnSummon);
#endif
#ifdef CPetInfoWnd__Update_x
FUNCTION_AT_ADDRESS(void CPetInfoWnd::Update(), CPetInfoWnd__Update);
#endif
#ifdef CPetInfoWnd__GetButton_x
FUNCTION_AT_ADDRESS(CButtonWnd* CPetInfoWnd::GetButton(int), CPetInfoWnd__GetButton);
#endif
#ifdef CPetitionQWnd__CPetitionQWnd_x
FUNCTION_AT_ADDRESS(CPetitionQWnd::CPetitionQWnd(CXWnd*), CPetitionQWnd__CPetitionQWnd);
#endif
#ifdef CPetitionQWnd__UpdatePetitions_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::UpdatePetitions(), CPetitionQWnd__UpdatePetitions);
#endif
#ifdef CPetitionQWnd__Activate_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::Activate(), CPetitionQWnd__Activate);
#endif
#ifdef CPetitionQWnd__SetPriorityDisplay_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::SetPriorityDisplay(), CPetitionQWnd__SetPriorityDisplay);
#endif
#ifdef CPetitionQWnd__AddGMText_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::AddGMText(), CPetitionQWnd__AddGMText);
#endif
#ifdef CPetitionQWnd__CheckedOut_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::CheckedOut(struct petitionQtype const*, int), CPetitionQWnd__CheckedOut);
#endif
#ifdef CPetitionQWnd__UndoCheckout_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::UndoCheckout(), CPetitionQWnd__UndoCheckout);
#endif
#ifdef CPetitionQWnd__ClearCurrentPet_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::ClearCurrentPet(), CPetitionQWnd__ClearCurrentPet);
#endif
#ifdef CPetitionQWnd__FillFields_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::FillFields(), CPetitionQWnd__FillFields);
#endif
#ifdef CPetitionQWnd__SetButtonsForPetition_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::SetButtonsForPetition(bool, bool), CPetitionQWnd__SetButtonsForPetition);
#endif
#ifdef CPetitionQWnd__LogPetitionText_x
FUNCTION_AT_ADDRESS(void CPetitionQWnd::LogPetitionText(), CPetitionQWnd__LogPetitionText);
#endif
#ifdef CPetitionQWnd__GetCurrentPetitionersName_x
FUNCTION_AT_ADDRESS(char* CPetitionQWnd::GetCurrentPetitionersName(), CPetitionQWnd__GetCurrentPetitionersName);
#endif
#ifdef CPlayerNotesWnd__CPlayerNotesWnd_x
FUNCTION_AT_ADDRESS(CPlayerNotesWnd::CPlayerNotesWnd(CXWnd*), CPlayerNotesWnd__CPlayerNotesWnd);
#endif
#ifdef CPlayerNotesWnd__Activate_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::Activate(), CPlayerNotesWnd__Activate);
#endif
#ifdef CPlayerNotesWnd__SaveNotes_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::SaveNotes(), CPlayerNotesWnd__SaveNotes);
#endif
#ifdef CPlayerNotesWnd__AppendText_x
FUNCTION_AT_ADDRESS(void CPlayerNotesWnd::AppendText(char*), CPlayerNotesWnd__AppendText);
#endif
#ifdef CPlayerWnd__CPlayerWnd_x
FUNCTION_AT_ADDRESS(CPlayerWnd::CPlayerWnd(CXWnd*), CPlayerWnd__CPlayerWnd);
#endif
#ifdef CPlayerWnd__Init_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::Init(), CPlayerWnd__Init);
#endif
#ifdef CPlayerWnd__Activate_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::Activate(), CPlayerWnd__Activate);
#endif
#ifdef CPlayerWnd__CreateLocalMenu_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::CreateLocalMenu(), CPlayerWnd__CreateLocalMenu);
#endif
#ifdef CPlayerWnd__UpdateContextMenu_x
FUNCTION_AT_ADDRESS(void CPlayerWnd::UpdateContextMenu(), CPlayerWnd__UpdateContextMenu);
#endif
#ifdef CQuantityWnd__CQuantityWnd_x
FUNCTION_AT_ADDRESS(CQuantityWnd::CQuantityWnd(CXWnd*), CQuantityWnd__CQuantityWnd);
#endif
#ifdef CQuantityWnd__Activate_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::Activate(CXWnd*, int, int, int, int, bool), CQuantityWnd__Activate);
#endif
#ifdef CQuantityWnd__CheckMaxEditWnd_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::CheckMaxEditWnd(), CQuantityWnd__CheckMaxEditWnd);
#endif
#ifdef CQuantityWnd__Open_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::Open(CXWnd*, int, int, int, int, int, int, bool), CQuantityWnd__Open);
#endif
#ifdef CQuantityWnd__UpdateEditWndFromSlider_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::UpdateEditWndFromSlider(), CQuantityWnd__UpdateEditWndFromSlider);
#endif
#ifdef CQuantityWnd__UpdateSliderFromEditWnd_x
FUNCTION_AT_ADDRESS(void CQuantityWnd::UpdateSliderFromEditWnd(), CQuantityWnd__UpdateSliderFromEditWnd);
#endif
#ifdef CRaidOptionsWnd__CRaidOptionsWnd_x
FUNCTION_AT_ADDRESS(CRaidOptionsWnd::CRaidOptionsWnd(CXWnd*), CRaidOptionsWnd__CRaidOptionsWnd);
#endif
#ifdef CRaidOptionsWnd__Init_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::Init(), CRaidOptionsWnd__Init);
#endif
#ifdef CRaidOptionsWnd__Activate_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::Activate(), CRaidOptionsWnd__Activate);
#endif
#ifdef CRaidOptionsWnd__AddLooterToList_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::AddLooterToList(char*), CRaidOptionsWnd__AddLooterToList);
#endif
#ifdef CRaidOptionsWnd__ClearLooterList_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::ClearLooterList(), CRaidOptionsWnd__ClearLooterList);
#endif
#ifdef CRaidOptionsWnd__UpdateComponents_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::UpdateComponents(), CRaidOptionsWnd__UpdateComponents);
#endif
#ifdef CRaidOptionsWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void CRaidOptionsWnd::InitializeClassColors(), CRaidOptionsWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__CRaidWnd_x
FUNCTION_AT_ADDRESS(CRaidWnd::CRaidWnd(CXWnd*), CRaidWnd__CRaidWnd);
#endif
#ifdef CRaidWnd__Init_x
FUNCTION_AT_ADDRESS(void CRaidWnd::Init(), CRaidWnd__Init);
#endif
#ifdef CRaidWnd__Activate_x
FUNCTION_AT_ADDRESS(void CRaidWnd::Activate(), CRaidWnd__Activate);
#endif
#ifdef CRaidWnd__AddPlayertoList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::AddPlayertoList(char*, char*, char*, char*, int, int, bool), CRaidWnd__AddPlayertoList);
#endif
#ifdef CRaidWnd__RemovePlayerFromList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::RemovePlayerFromList(char*, int), CRaidWnd__RemovePlayerFromList);
#endif
#ifdef CRaidWnd__SetRaidCount_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidCount(int), CRaidWnd__SetRaidCount);
#endif
#ifdef CRaidWnd__ClearPlayerList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ClearPlayerList(), CRaidWnd__ClearPlayerList);
#endif
#ifdef CRaidWnd__AddSeparator_x
FUNCTION_AT_ADDRESS(void CRaidWnd::AddSeparator(), CRaidWnd__AddSeparator);
#endif
#ifdef CRaidWnd__SetRaidMemberRank_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidMemberRank(char*, char*, int), CRaidWnd__SetRaidMemberRank);
#endif
#ifdef CRaidWnd__ChangePosition_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ChangePosition(char*, int, int, int, bool), CRaidWnd__ChangePosition);
#endif
#ifdef CRaidWnd__ChangeRaidGroupLeader_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ChangeRaidGroupLeader(char*, int, char*), CRaidWnd__ChangeRaidGroupLeader);
#endif
#ifdef CRaidWnd__UpdateMemberName_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateMemberName(char*, char*, int), CRaidWnd__UpdateMemberName);
#endif
#ifdef CRaidWnd__SetRaidTarget_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetRaidTarget(char*, int, char*, int), CRaidWnd__SetRaidTarget);
#endif
#ifdef CRaidWnd__UpdateLevelAverage_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateLevelAverage(int), CRaidWnd__UpdateLevelAverage);
#endif
#ifdef CRaidWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CRaidWnd::UpdateButtons(), CRaidWnd__UpdateButtons);
#endif
#ifdef CRaidWnd__InitializeClassColors_x
FUNCTION_AT_ADDRESS(void CRaidWnd::InitializeClassColors(), CRaidWnd__InitializeClassColors);
#endif
#ifdef CRaidWnd__SetPlayerClassColor_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetPlayerClassColor(int, int, int), CRaidWnd__SetPlayerClassColor);
#endif
#ifdef CRaidWnd__SetPlayerClassColor1_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetPlayerClassColor(char*, int, int), CRaidWnd__SetPlayerClassColor1);
#endif
#ifdef CRaidWnd__SetClassColor_x
FUNCTION_AT_ADDRESS(void CRaidWnd::SetClassColor(int, unsigned long), CRaidWnd__SetClassColor);
#endif
#ifdef CRaidWnd__ResortRaidGroupList_x
FUNCTION_AT_ADDRESS(void CRaidWnd::ResortRaidGroupList(int, int), CRaidWnd__ResortRaidGroupList);
#endif
#ifdef CRaidWnd__FindOpenIndexInGroup_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindOpenIndexInGroup(int), CRaidWnd__FindOpenIndexInGroup);
#endif
#ifdef CRaidWnd__FindIndexNotInGroupList_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindIndexNotInGroupList(char*), CRaidWnd__FindIndexNotInGroupList);
#endif
#ifdef CRaidWnd__FindPlayerIndexInGroup_x
FUNCTION_AT_ADDRESS(int CRaidWnd::FindPlayerIndexInGroup(char*, int), CRaidWnd__FindPlayerIndexInGroup);
#endif
#ifdef CSelectorWnd__CSelectorWnd_x
FUNCTION_AT_ADDRESS(CSelectorWnd::CSelectorWnd(CXWnd*), CSelectorWnd__CSelectorWnd);
#endif
#ifdef CSelectorWnd__Activate_x
FUNCTION_AT_ADDRESS(void CSelectorWnd::Activate(), CSelectorWnd__Activate);
#endif
#ifdef CSelectorWnd__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CSelectorWnd::KeyMapUpdated(), CSelectorWnd__KeyMapUpdated);
#endif
#ifdef CSkillsSelectWnd__CSkillsSelectWnd_x
FUNCTION_AT_ADDRESS(CSkillsSelectWnd::CSkillsSelectWnd(CXWnd*), CSkillsSelectWnd__CSkillsSelectWnd);
#endif
#ifdef CSkillsSelectWnd__Refresh_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::Refresh(), CSkillsSelectWnd__Refresh);
#endif
#ifdef CSkillsSelectWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::UpdateAll(), CSkillsSelectWnd__UpdateAll);
#endif
#ifdef CSkillsSelectWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::UpdateSkill(int), CSkillsSelectWnd__UpdateSkill);
#endif
#ifdef CSkillsSelectWnd__SetTypesToDisplay_x
FUNCTION_AT_ADDRESS(void CSkillsSelectWnd::SetTypesToDisplay(int), CSkillsSelectWnd__SetTypesToDisplay);
#endif
#ifdef CSkillsWnd__CSkillsWnd_x
FUNCTION_AT_ADDRESS(CSkillsWnd::CSkillsWnd(CXWnd*), CSkillsWnd__CSkillsWnd);
#endif
#ifdef CSkillsWnd__Activate_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::Activate(), CSkillsWnd__Activate);
#endif
#ifdef CSkillsWnd__SkillImproveOccurred_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::SkillImproveOccurred(int), CSkillsWnd__SkillImproveOccurred);
#endif
#ifdef CSkillsWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::UpdateAll(), CSkillsWnd__UpdateAll);
#endif
#ifdef CSkillsWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CSkillsWnd::UpdateSkill(int), CSkillsWnd__UpdateSkill);
#endif
#ifdef CSocialEditWnd__CSocialEditWnd_x
FUNCTION_AT_ADDRESS(CSocialEditWnd::CSocialEditWnd(CXWnd*), CSocialEditWnd__CSocialEditWnd);
#endif
#ifdef CSocialEditWnd__Init_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::Init(), CSocialEditWnd__Init);
#endif
#ifdef CSocialEditWnd__Activate_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::Activate(int), CSocialEditWnd__Activate);
#endif
#ifdef CSocialEditWnd__ClickedAccept_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedAccept(), CSocialEditWnd__ClickedAccept);
#endif
#ifdef CSocialEditWnd__ClickedClear_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedClear(), CSocialEditWnd__ClickedClear);
#endif
#ifdef CSocialEditWnd__ClickedTextColorButton_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::ClickedTextColorButton(int), CSocialEditWnd__ClickedTextColorButton);
#endif
#ifdef CSocialEditWnd__GetSocialTextColor_x
FUNCTION_AT_ADDRESS(unsigned long CSocialEditWnd::GetSocialTextColor(int), CSocialEditWnd__GetSocialTextColor);
#endif
#ifdef CSocialEditWnd__UpdateControlsFromSocial_x
FUNCTION_AT_ADDRESS(void CSocialEditWnd::UpdateControlsFromSocial(), CSocialEditWnd__UpdateControlsFromSocial);
#endif
#ifdef CSpellBookWnd__CSpellBookWnd_x
FUNCTION_AT_ADDRESS(CSpellBookWnd::CSpellBookWnd(CXWnd*), CSpellBookWnd__CSpellBookWnd);
#endif
#ifdef CSpellBookWnd__Init_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::Init(), CSpellBookWnd__Init);
#endif
#ifdef CSpellBookWnd__Activate_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::Activate(), CSpellBookWnd__Activate);
#endif
#ifdef CSpellBookWnd__GetBookSlot_x
FUNCTION_AT_ADDRESS(int __cdecl CSpellBookWnd::GetBookSlot(int), CSpellBookWnd__GetBookSlot);
#endif
#ifdef CSpellBookWnd__MemorizeSet_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::MemorizeSet(int*, int), CSpellBookWnd__MemorizeSet);
#endif
#ifdef CSpellBookWnd__ContinueSetMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::ContinueSetMem(), CSpellBookWnd__ContinueSetMem);
#endif
#ifdef CSpellBookWnd__DelayedSpellMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DelayedSpellMem(int, int, int), CSpellBookWnd__DelayedSpellMem);
#endif
#ifdef CSpellBookWnd__EndSetMem_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::EndSetMem(), CSpellBookWnd__EndSetMem);
#endif
#ifdef CSpellBookWnd__AutoMemSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::AutoMemSpell(int, int), CSpellBookWnd__AutoMemSpell);
#endif
#ifdef CSpellBookWnd__HandleLeftClickOnSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleLeftClickOnSpell(int), CSpellBookWnd__HandleLeftClickOnSpell);
#endif
#ifdef CSpellBookWnd__HandleRightClickOnSpell_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleRightClickOnSpell(int), CSpellBookWnd__HandleRightClickOnSpell);
#endif
#ifdef CSpellBookWnd__CanStartMemming_x
FUNCTION_AT_ADDRESS(bool CSpellBookWnd::CanStartMemming(int), CSpellBookWnd__CanStartMemming);
#endif
#ifdef CSpellBookWnd__StartSpellMemorizationDrag_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StartSpellMemorizationDrag(int, CButtonWnd*), CSpellBookWnd__StartSpellMemorizationDrag);
#endif
#ifdef CSpellBookWnd__StartSpellMemorization_x
FUNCTION_AT_ADDRESS(bool CSpellBookWnd::StartSpellMemorization(int, int, bool), CSpellBookWnd__StartSpellMemorization);
#endif
#ifdef CSpellBookWnd__FinishMemorizing_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::FinishMemorizing(int, int), CSpellBookWnd__FinishMemorizing);
#endif
#ifdef CSpellBookWnd__GetSpellMemTicksLeft_x
FUNCTION_AT_ADDRESS(int CSpellBookWnd::GetSpellMemTicksLeft(), CSpellBookWnd__GetSpellMemTicksLeft);
#endif
#ifdef CSpellBookWnd__StartSpellScribe_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StartSpellScribe(int), CSpellBookWnd__StartSpellScribe);
#endif
#ifdef CSpellBookWnd__FinishScribing_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::FinishScribing(int, int), CSpellBookWnd__FinishScribing);
#endif
#ifdef CSpellBookWnd__GetSpellScribeTicksLeft_x
FUNCTION_AT_ADDRESS(int CSpellBookWnd::GetSpellScribeTicksLeft(), CSpellBookWnd__GetSpellScribeTicksLeft);
#endif
#ifdef CSpellBookWnd__SwapSpellBookSlots_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::SwapSpellBookSlots(int, int), CSpellBookWnd__SwapSpellBookSlots);
#endif
#ifdef CSpellBookWnd__HandleSpellInfoDisplay_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::HandleSpellInfoDisplay(CXWnd*), CSpellBookWnd__HandleSpellInfoDisplay);
#endif
#ifdef CSpellBookWnd__DisplaySpellInfo_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DisplaySpellInfo(int), CSpellBookWnd__DisplaySpellInfo);
#endif
#ifdef CSpellBookWnd__TurnToPage_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::TurnToPage(int), CSpellBookWnd__TurnToPage);
#endif
#ifdef CSpellBookWnd__UpdateSpellBookDisplay_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::UpdateSpellBookDisplay(), CSpellBookWnd__UpdateSpellBookDisplay);
#endif
#ifdef CSpellBookWnd__StopSpellBookAction_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::StopSpellBookAction(), CSpellBookWnd__StopSpellBookAction);
#endif
#ifdef CSpellBookWnd__GetSpellDeletionConfirmation_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::GetSpellDeletionConfirmation(int), CSpellBookWnd__GetSpellDeletionConfirmation);
#endif
#ifdef CSpellBookWnd__RequestSpellDeletion_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::RequestSpellDeletion(int), CSpellBookWnd__RequestSpellDeletion);
#endif
#ifdef CSpellBookWnd__DeleteSpellFromBook_x
FUNCTION_AT_ADDRESS(void CSpellBookWnd::DeleteSpellFromBook(int, int), CSpellBookWnd__DeleteSpellFromBook);
#endif
#ifdef CTargetRing__Cast_x
FUNCTION_AT_ADDRESS(int CTargetRing::Cast(CVector3*), CTargetRing__Cast);
#endif
#ifdef CTargetWnd__CTargetWnd_x
FUNCTION_AT_ADDRESS(CTargetWnd::CTargetWnd(CXWnd*), CTargetWnd__CTargetWnd);
#endif
#ifdef CTargetWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTargetWnd::Activate(), CTargetWnd__Activate);
#endif
#ifdef CTargetWnd__GetBuffCaster_x
FUNCTION_AT_ADDRESS(CXStr* CTargetWnd::GetBuffCaster(int), CTargetWnd__GetBuffCaster);
#endif
#ifdef CTaskWnd__UpdateTaskTimers_x
FUNCTION_AT_ADDRESS(int CTaskWnd::UpdateTaskTimers(unsigned long), CTaskWnd__UpdateTaskTimers);
#endif
#ifdef CTaskManager__GetEntry_x
FUNCTION_AT_ADDRESS(CTaskEntry* CTaskManager::GetEntry(int Index, int System, bool bCheckEmpty), CTaskManager__GetEntry);
#endif
#ifdef CTextEntryWnd__CTextEntryWnd_x
FUNCTION_AT_ADDRESS(CTextEntryWnd::CTextEntryWnd(CXWnd*), CTextEntryWnd__CTextEntryWnd);
#endif
#ifdef CTextEntryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::Activate(CXWnd*, int, char*, int, int, char*), CTextEntryWnd__Activate);
#endif
#ifdef CTextEntryWnd__Callback_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::Callback(bool), CTextEntryWnd__Callback);
#endif
#ifdef CTextEntryWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CTextEntryWnd::UpdateButtons(), CTextEntryWnd__UpdateButtons);
#endif
#ifdef CTextEntryWnd__GetEntryText_x
FUNCTION_AT_ADDRESS(CXStr CTextEntryWnd::GetEntryText(), CTextEntryWnd__GetEntryText);
#endif
#ifdef CTimeLeftWnd__CTimeLeftWnd_x
FUNCTION_AT_ADDRESS(CTimeLeftWnd::CTimeLeftWnd(long), CTimeLeftWnd__CTimeLeftWnd);
#endif
#ifdef CTimeLeftWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTimeLeftWnd::Activate(), CTimeLeftWnd__Activate);
#endif
#ifdef CTipWnd__CTipWnd_x
FUNCTION_AT_ADDRESS(CTipWnd::CTipWnd(CXWnd*, int), CTipWnd__CTipWnd);
#endif
#ifdef CTipWnd__Activate_x
FUNCTION_AT_ADDRESS(bool CTipWnd::Activate(int, bool), CTipWnd__Activate);
#endif
#ifdef CTipWnd__UpdateButtons_x
FUNCTION_AT_ADDRESS(void CTipWnd::UpdateButtons(), CTipWnd__UpdateButtons);
#endif
#ifdef CTipWnd__InitializeTipSettings_x
FUNCTION_AT_ADDRESS(void CTipWnd::InitializeTipSettings(), CTipWnd__InitializeTipSettings);
#endif
#ifdef CTipWnd__CleanDayTips_x
FUNCTION_AT_ADDRESS(void CTipWnd::CleanDayTips(), CTipWnd__CleanDayTips);
#endif
#ifdef CTipWnd__SelectRandomTip_x
FUNCTION_AT_ADDRESS(int CTipWnd::SelectRandomTip(), CTipWnd__SelectRandomTip);
#endif
#ifdef CTipWnd__SetTOTD_x
FUNCTION_AT_ADDRESS(void CTipWnd::SetTOTD(int), CTipWnd__SetTOTD);
#endif
#ifdef CTipWnd__IsRecentTOTD_x
FUNCTION_AT_ADDRESS(bool CTipWnd::IsRecentTOTD(int), CTipWnd__IsRecentTOTD);
#endif
#ifdef CTipWnd__AddContextTip_x
FUNCTION_AT_ADDRESS(void CTipWnd::AddContextTip(int), CTipWnd__AddContextTip);
#endif
#ifdef CTipWnd__ShowHistoryTip_x
FUNCTION_AT_ADDRESS(void CTipWnd::ShowHistoryTip(int), CTipWnd__ShowHistoryTip);
#endif
#ifdef CTipWnd__LoadINISettings_x
FUNCTION_AT_ADDRESS(void CTipWnd::LoadINISettings(), CTipWnd__LoadINISettings);
#endif
#ifdef CTipWnd__LoadDayTips_x
FUNCTION_AT_ADDRESS(void CTipWnd::LoadDayTips(), CTipWnd__LoadDayTips);
#endif
#ifdef CTrackingWnd__CTrackingWnd_x
FUNCTION_AT_ADDRESS(CTrackingWnd::CTrackingWnd(CXWnd*), CTrackingWnd__CTrackingWnd);
#endif
#ifdef CTrackingWnd__Init_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::Init(), CTrackingWnd__Init);
#endif
#ifdef CTrackingWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::Activate(), CTrackingWnd__Activate);
#endif
#ifdef CTrackingWnd__NotifyServerOfTrackingTarget_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::NotifyServerOfTrackingTarget(int), CTrackingWnd__NotifyServerOfTrackingTarget);
#endif
#ifdef CTrackingWnd__UpdateTrackingControls_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::UpdateTrackingControls(), CTrackingWnd__UpdateTrackingControls);
#endif
#ifdef CTrackingWnd__GetTrackColor_x
FUNCTION_AT_ADDRESS(unsigned long CTrackingWnd::GetTrackColor(int), CTrackingWnd__GetTrackColor);
#endif
#ifdef CTrackingWnd__UpdateTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::UpdateTrackingList(bool), CTrackingWnd__UpdateTrackingList);
#endif
#ifdef CTrackingWnd__GenerateTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::GenerateTrackingList(), CTrackingWnd__GenerateTrackingList);
#endif
#ifdef CTrackingWnd__SetTrackingList_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::SetTrackingList(struct TrackingHit*, int), CTrackingWnd__SetTrackingList);
#endif
#ifdef CTrackingWnd__DoTrackSort_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::DoTrackSort(bool), CTrackingWnd__DoTrackSort);
#endif
#ifdef CTrackingWnd__DoTrackFilter_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::DoTrackFilter(bool), CTrackingWnd__DoTrackFilter);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemovePlayerFromTracking(EQPlayer*), CTrackingWnd__RemovePlayerFromTracking);
#endif
#ifdef CTrackingWnd__RemovePlayerFromTracking1_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemovePlayerFromTracking(int), CTrackingWnd__RemovePlayerFromTracking1);
#endif
#ifdef CTrackingWnd__RemoveFromListWndByData_x
FUNCTION_AT_ADDRESS(void CTrackingWnd::RemoveFromListWndByData(unsigned int), CTrackingWnd__RemoveFromListWndByData);
#endif
#ifdef CTrackingWnd__GetListIdByData_x
FUNCTION_AT_ADDRESS(int CTrackingWnd::GetListIdByData(unsigned int), CTrackingWnd__GetListIdByData);
#endif
#ifdef CTradeWnd__CTradeWnd_x
FUNCTION_AT_ADDRESS(CTradeWnd::CTradeWnd(CXWnd*), CTradeWnd__CTradeWnd);
#endif
#ifdef CTradeWnd__Init_x
FUNCTION_AT_ADDRESS(void CTradeWnd::Init(), CTradeWnd__Init);
#endif
#ifdef CTradeWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTradeWnd::Activate(EQPlayer*, bool), CTradeWnd__Activate);
#endif
#ifdef CTradeWnd__ClickedCancelButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedCancelButton(), CTradeWnd__ClickedCancelButton);
#endif
#ifdef CTradeWnd__ClickedTradeButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedTradeButton(), CTradeWnd__ClickedTradeButton);
#endif
#ifdef CTradeWnd__ClickedMoneyButton_x
FUNCTION_AT_ADDRESS(void CTradeWnd::ClickedMoneyButton(int), CTradeWnd__ClickedMoneyButton);
#endif
#ifdef CTradeWnd__UpdateTradeDisplay_x
FUNCTION_AT_ADDRESS(void CTradeWnd::UpdateTradeDisplay(), CTradeWnd__UpdateTradeDisplay);
#endif
#ifdef CTradeWnd__IsMyTradeSlot_x
FUNCTION_AT_ADDRESS(bool CTradeWnd::IsMyTradeSlot(int, bool*), CTradeWnd__IsMyTradeSlot);
#endif
#ifdef CTradeWnd__TradeItemChanged_x
FUNCTION_AT_ADDRESS(void CTradeWnd::TradeItemChanged(int, int), CTradeWnd__TradeItemChanged);
#endif
#ifdef CTradeWnd__CompleteTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::CompleteTrade(), CTradeWnd__CompleteTrade);
#endif
#ifdef CTradeWnd__AddEquipmentToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddEquipmentToHisTradeArray(EQ_Equipment*), CTradeWnd__AddEquipmentToHisTradeArray);
#endif
#ifdef CTradeWnd__AddNoteToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddNoteToHisTradeArray(EQ_Note*), CTradeWnd__AddNoteToHisTradeArray);
#endif
#ifdef CTradeWnd__AddContainerToHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::AddContainerToHisTradeArray(EQ_Container*), CTradeWnd__AddContainerToHisTradeArray);
#endif
#ifdef CTradeWnd__DeleteItemFromHisTradeArray_x
FUNCTION_AT_ADDRESS(void CTradeWnd::DeleteItemFromHisTradeArray(int), CTradeWnd__DeleteItemFromHisTradeArray);
#endif
#ifdef CTradeWnd__DropItemIntoTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::DropItemIntoTrade(), CTradeWnd__DropItemIntoTrade);
#endif
#ifdef CTradeWnd__SetMyReadyTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetMyReadyTrade(bool), CTradeWnd__SetMyReadyTrade);
#endif
#ifdef CTradeWnd__SetHisReadyTrade_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetHisReadyTrade(bool), CTradeWnd__SetHisReadyTrade);
#endif
#ifdef CTradeWnd__SetHisMoney_x
FUNCTION_AT_ADDRESS(void CTradeWnd::SetHisMoney(int, long), CTradeWnd__SetHisMoney);
#endif
#ifdef CTrainWnd__CTrainWnd_x
FUNCTION_AT_ADDRESS(CTrainWnd::CTrainWnd(CXWnd*), CTrainWnd__CTrainWnd);
#endif
#ifdef CTrainWnd__Activate_x
FUNCTION_AT_ADDRESS(void CTrainWnd::Activate(), CTrainWnd__Activate);
#endif
#ifdef CTrainWnd__UpdateRight_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateRight(), CTrainWnd__UpdateRight);
#endif
#ifdef CTrainWnd__UpdateAll_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateAll(bool), CTrainWnd__UpdateAll);
#endif
#ifdef CTrainWnd__SkillName_x
FUNCTION_AT_ADDRESS(char* CTrainWnd::SkillName(int), CTrainWnd__SkillName);
#endif
#ifdef CTrainWnd__SkillValue_x
FUNCTION_AT_ADDRESS(int CTrainWnd::SkillValue(int), CTrainWnd__SkillValue);
#endif
#ifdef CTrainWnd__SwapSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SwapSkill(int, int), CTrainWnd__SwapSkill);
#endif
#ifdef CTrainWnd__SortNames_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SortNames(int), CTrainWnd__SortNames);
#endif
#ifdef CTrainWnd__SortSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SortSkill(int), CTrainWnd__SortSkill);
#endif
#ifdef CTrainWnd__UpdateSkill_x
FUNCTION_AT_ADDRESS(void CTrainWnd::UpdateSkill(int), CTrainWnd__UpdateSkill);
#endif
#ifdef CTrainWnd__SkillChanged_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SkillChanged(int), CTrainWnd__SkillChanged);
#endif
#ifdef CTrainWnd__SetGMData_x
FUNCTION_AT_ADDRESS(void CTrainWnd::SetGMData(int*, unsigned char*, float), CTrainWnd__SetGMData);
#endif
#ifdef CTrainWnd__Train_x
FUNCTION_AT_ADDRESS(void CTrainWnd::Train(), CTrainWnd__Train);
#endif
#ifdef CVideoModesWnd__CVideoModesWnd_x
FUNCTION_AT_ADDRESS(CVideoModesWnd::CVideoModesWnd(CXWnd*), CVideoModesWnd__CVideoModesWnd);
#endif
#ifdef CVideoModesWnd__Init_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::Init(), CVideoModesWnd__Init);
#endif
#ifdef CVideoModesWnd__Update_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::Update(), CVideoModesWnd__Update);
#endif
#ifdef CVideoModesWnd__UpdateSelection_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::UpdateSelection(unsigned int), CVideoModesWnd__UpdateSelection);
#endif
#ifdef CVideoModesWnd__RestoreOldMode_x
FUNCTION_AT_ADDRESS(void CVideoModesWnd::RestoreOldMode(), CVideoModesWnd__RestoreOldMode);
#endif
#ifdef CGuild__CGuild_x
FUNCTION_AT_ADDRESS(CGuild::CGuild(), CGuild__CGuild);
#endif
#ifdef CGuild__GetGuildName_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char* CGuild::GetGuildName(int64_t), CGuild__GetGuildName);
#else
FUNCTION_AT_ADDRESS(char* CGuild::GetGuildName(DWORD), CGuild__GetGuildName);
#endif
#endif
#ifdef CGuild__GetGuildIndex_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int64_t CGuild::GetGuildIndex(char*), CGuild__GetGuildIndex);
#else
FUNCTION_AT_ADDRESS(int CGuild::GetGuildIndex(char*), CGuild__GetGuildIndex);
#endif
#endif
#ifdef CGuild__ValidGuildName_x
FUNCTION_AT_ADDRESS(bool CGuild::ValidGuildName(int), CGuild__ValidGuildName);
#endif
#ifdef CGuild__SendPublicCommentChange_x
FUNCTION_AT_ADDRESS(void CGuild::SendPublicCommentChange(char*, char*), CGuild__SendPublicCommentChange);
#endif
#ifdef CGuild__DemoteMember_x
FUNCTION_AT_ADDRESS(void CGuild::DemoteMember(GuildMember*), CGuild__DemoteMember);
#endif
#ifdef CGuild__SetGuildMotd_x
FUNCTION_AT_ADDRESS(void CGuild::SetGuildMotd(guildmotdSet*), CGuild__SetGuildMotd);
#endif
#ifdef CGuild__HandleGuildMessage_x
FUNCTION_AT_ADDRESS(void CGuild::HandleGuildMessage(connection_t*, uint32_t, char*, uint32_t), CGuild__HandleGuildMessage);
#endif
#ifdef CGuild__InitializeFromDump_x
FUNCTION_AT_ADDRESS(void CGuild::InitializeFromDump(char*), CGuild__InitializeFromDump);
#endif
#ifdef CGuild__AddGuildMember_x
FUNCTION_AT_ADDRESS(void CGuild::AddGuildMember(GuildMember*), CGuild__AddGuildMember);
#endif
#ifdef CGuild__DeleteAllMembers_x
FUNCTION_AT_ADDRESS(void CGuild::DeleteAllMembers(), CGuild__DeleteAllMembers);
#endif
#ifdef CGuild__HandleGuildInvite_x
FUNCTION_AT_ADDRESS(void CGuild::HandleGuildInvite(connection_t*, uint32_t, char*, uint32_t), CGuild__HandleGuildInvite);
#endif
#ifdef CGuild__HandleAddGuildMember_x
FUNCTION_AT_ADDRESS(void CGuild::HandleAddGuildMember(char*, int), CGuild__HandleAddGuildMember);
#endif
#ifdef CGuild__HandleRemoveGuildMember_x
FUNCTION_AT_ADDRESS(void CGuild::HandleRemoveGuildMember(char*, int), CGuild__HandleRemoveGuildMember);
#endif
#ifdef CGuild__HandleDeleteGuildResponse_x
FUNCTION_AT_ADDRESS(void CGuild::HandleDeleteGuildResponse(char*), CGuild__HandleDeleteGuildResponse);
#endif
#ifdef CGuild__UpdatePublicComment_x
FUNCTION_AT_ADDRESS(void CGuild::UpdatePublicComment(char*), CGuild__UpdatePublicComment);
#endif
#ifdef CGuild__UpdateMemberStatus_x
FUNCTION_AT_ADDRESS(void CGuild::UpdateMemberStatus(char*), CGuild__UpdateMemberStatus);
#endif
#ifdef CGuild__HandleMemberLevelUpdate_x
FUNCTION_AT_ADDRESS(void CGuild::HandleMemberLevelUpdate(char*), CGuild__HandleMemberLevelUpdate);
#endif
#ifdef CGuild__UpdateGuildMemberOnWindow_x
FUNCTION_AT_ADDRESS(void CGuild::UpdateGuildMemberOnWindow(GuildMember*), CGuild__UpdateGuildMemberOnWindow);
#endif
#ifdef CGuild__ChangeGuildMemberName_x
FUNCTION_AT_ADDRESS(void CGuild::ChangeGuildMemberName(char*), CGuild__ChangeGuildMemberName);
#endif
#ifdef CGuild__FindMemberByName_x
FUNCTION_AT_ADDRESS(GuildMember* CGuild::FindMemberByName(char*), CGuild__FindMemberByName);
#endif
#ifdef GuildMember__GuildMember_x
FUNCTION_AT_ADDRESS(GuildMember::GuildMember(), GuildMember__GuildMember);
#endif
#ifdef CharacterBase__GetMemorizedSpell_x
FUNCTION_AT_ADDRESS(LONG CharacterBase::GetMemorizedSpell(int), CharacterBase__GetMemorizedSpell);
#endif
#ifdef CharacterBase__CreateItemGlobalIndex_x
FUNCTION_AT_ADDRESS(ItemGlobalIndex CharacterBase::CreateItemGlobalIndex(int, int, int), CharacterBase__CreateItemGlobalIndex);
#endif
#ifdef CharacterBase__CreateItemIndex_x
FUNCTION_AT_ADDRESS(ItemIndex CharacterBase::CreateItemIndex(int, int, int), CharacterBase__CreateItemIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const, CharacterBase__GetItemByGlobalIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex1_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const, CharacterBase__GetItemByGlobalIndex1);
#endif
#ifdef CharacterBase__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemPossession(const ItemIndex& lIndex) const, CharacterBase__GetItemPossession);
#endif
#ifdef BaseProfile__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> BaseProfile::GetItemPossession(const ItemIndex& lIndex) const, BaseProfile__GetItemPossession);
#endif
#ifdef AggroMeterManagerClient__Instance_x
FUNCTION_AT_ADDRESS(AggroMeterManagerClient& AggroMeterManagerClient::Instance(), AggroMeterManagerClient__Instance);
#endif
#ifdef ClientSOIManager__GetSingleton_x
FUNCTION_AT_ADDRESS(ClientSOIManager* ClientSOIManager::GetSingleton(), ClientSOIManager__GetSingleton);
#endif
#ifdef MercenaryAlternateAdvancementManagerClient__Instance_x
FUNCTION_AT_ADDRESS(MercenaryAlternateAdvancementManagerClient& MercenaryAlternateAdvancementManagerClient::Instance(), MercenaryAlternateAdvancementManagerClient__Instance);
#endif
#ifdef CTargetManager__Get_x
FUNCTION_AT_ADDRESS(CTargetManager* CTargetManager::Get(), CTargetManager__Get);
#endif
#ifdef CBroadcast__Get_x
FUNCTION_AT_ADDRESS(CBroadcast* CBroadcast::Get(), CBroadcast__Get);
#endif
#ifdef EQGroundItemListManager__Instance_x
FUNCTION_AT_ADDRESS(EQGroundItemListManager& EQGroundItemListManager::Instance(), EQGroundItemListManager__Instance);
#endif
#ifdef ArrayClass__DeleteElement_x
FUNCTION_AT_ADDRESS(void ArrayClass_RO<SListWndColumn_RO>::DeleteElement(int index), ArrayClass__DeleteElement);
#endif
#if !defined(ROF2EMU) && !defined(UFEMU)
#ifdef ItemBase__IsLoreEquipped_x
FUNCTION_AT_ADDRESS(bool ItemBase::IsLoreEquipped(bool bIncludeSockets) const, ItemBase__IsLoreEquipped);
#endif
#endif
#ifdef ItemBase__IsLore_x
FUNCTION_AT_ADDRESS(bool ItemBase::IsLore(bool bIncludeSockets) const, ItemBase__IsLore);
#endif
#ifdef ItemGlobalIndex__IsKeyRingLocation_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsKeyRingLocation(), ItemGlobalIndex__IsKeyRingLocation);
#endif
#ifdef ItemGlobalIndex__IsEquippedLocation_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsEquippedLocation(), ItemGlobalIndex__IsEquippedLocation);
#endif
#ifdef ItemGlobalIndex__IsValidIndex_x
FUNCTION_AT_ADDRESS(bool ItemGlobalIndex::IsValidIndex(), ItemGlobalIndex__IsValidIndex);
#endif
#ifdef ItemGlobalIndex__ItemGlobalIndex_x
FUNCTION_AT_ADDRESS(ItemGlobalIndex::ItemGlobalIndex(), ItemGlobalIndex__ItemGlobalIndex);
#endif
#ifdef IconCache__IconCache_x
FUNCTION_AT_ADDRESS(IconCache::IconCache(), IconCache__IconCache);
#endif
#ifdef IconCache__dIconCache_x
FUNCTION_AT_ADDRESS(IconCache::~IconCache(), IconCache__dIconCache);
#endif
#ifdef IconCache__GetIcon_x
FUNCTION_AT_ADDRESS(CTextureAnimation* IconCache::GetIcon(int), IconCache__GetIcon);
#endif
#ifdef JournalNPC__JournalNPC_x
FUNCTION_AT_ADDRESS(JournalNPC::JournalNPC(), JournalNPC__JournalNPC);
#endif
#ifdef JournalNPC__dJournalNPC_x
FUNCTION_AT_ADDRESS(JournalNPC::~JournalNPC(), JournalNPC__dJournalNPC);
#endif
#ifdef JournalNPC__AllocateArray_x
FUNCTION_AT_ADDRESS(void JournalNPC::AllocateArray(), JournalNPC__AllocateArray);
#endif
#ifdef JournalNPC__CleanEntries_x
FUNCTION_AT_ADDRESS(void JournalNPC::CleanEntries(), JournalNPC__CleanEntries);
#endif
#ifdef JournalNPC__GetText_x
FUNCTION_AT_ADDRESS(char* __cdecl JournalNPC::GetText(int), JournalNPC__GetText);
#endif
#ifdef JournalNPC__GetEntry_x
FUNCTION_AT_ADDRESS(JournalEntry* JournalNPC::GetEntry(int), JournalNPC__GetEntry);
#endif
#ifdef JournalNPC__FindEntryByHash_x
FUNCTION_AT_ADDRESS(JournalEntry* JournalNPC::FindEntryByHash(int), JournalNPC__FindEntryByHash);
#endif
#ifdef JournalNPC__FindEntryByCategory_x
FUNCTION_AT_ADDRESS(JournalEntry* JournalNPC::FindEntryByCategory(int, int), JournalNPC__FindEntryByCategory);
#endif
#ifdef JournalNPC__FindThisText_x
FUNCTION_AT_ADDRESS(int JournalNPC::FindThisText(char*, bool, int), JournalNPC__FindThisText);
#endif
#ifdef JournalNPC__AddEntry_x
FUNCTION_AT_ADDRESS(int JournalNPC::AddEntry(long, float, float, float, int, int), JournalNPC__AddEntry);
#endif
#ifdef JournalNPC__AddEntry1_x
FUNCTION_AT_ADDRESS(int JournalNPC::AddEntry(long, float, float, float, char*, int), JournalNPC__AddEntry1);
#endif
#ifdef JournalNPC__DeleteEntryByIndex_x
FUNCTION_AT_ADDRESS(int JournalNPC::DeleteEntryByIndex(int), JournalNPC__DeleteEntryByIndex);
#endif
#ifdef JournalNPC__DeleteEntryByHash_x
FUNCTION_AT_ADDRESS(int JournalNPC::DeleteEntryByHash(int), JournalNPC__DeleteEntryByHash);
#endif
#ifdef JournalNPC__ConvertCategory_x
FUNCTION_AT_ADDRESS(void JournalNPC::ConvertCategory(int, int), JournalNPC__ConvertCategory);
#endif
#ifdef JournalNPC__ComputeLatestTime_x
FUNCTION_AT_ADDRESS(void JournalNPC::ComputeLatestTime(), JournalNPC__ComputeLatestTime);
#endif
#ifdef ConversationJournal__ConversationJournal_x
FUNCTION_AT_ADDRESS(ConversationJournal::ConversationJournal(), ConversationJournal__ConversationJournal);
#endif
#ifdef ConversationJournal__dConversationJournal_x
FUNCTION_AT_ADDRESS(ConversationJournal::~ConversationJournal(), ConversationJournal__dConversationJournal);
#endif
#ifdef ConversationJournal__Clean_x
FUNCTION_AT_ADDRESS(void ConversationJournal::Clean(), ConversationJournal__Clean);
#endif
#ifdef ConversationJournal__AllocateNPCArray_x
FUNCTION_AT_ADDRESS(void ConversationJournal::AllocateNPCArray(), ConversationJournal__AllocateNPCArray);
#endif
#ifdef ConversationJournal__AllocateCatArray_x
FUNCTION_AT_ADDRESS(void ConversationJournal::AllocateCatArray(), ConversationJournal__AllocateCatArray);
#endif
#ifdef ConversationJournal__GetNPC_x
FUNCTION_AT_ADDRESS(JournalNPC* ConversationJournal::GetNPC(int), ConversationJournal__GetNPC);
#endif
#ifdef ConversationJournal__FindNPCByNameZone_x
FUNCTION_AT_ADDRESS(JournalNPC* ConversationJournal::FindNPCByNameZone(char*, int), ConversationJournal__FindNPCByNameZone);
#endif
#ifdef ConversationJournal__DeleteNPC_x
FUNCTION_AT_ADDRESS(int ConversationJournal::DeleteNPC(char*, int), ConversationJournal__DeleteNPC);
#endif
#ifdef ConversationJournal__AddNPC_x
FUNCTION_AT_ADDRESS(JournalNPC* ConversationJournal::AddNPC(char*, int), ConversationJournal__AddNPC);
#endif
#ifdef ConversationJournal__AddEntry_x
FUNCTION_AT_ADDRESS(int ConversationJournal::AddEntry(char*, int, long, float, float, float, char*, int), ConversationJournal__AddEntry);
#endif
#ifdef ConversationJournal__AddCategory_x
FUNCTION_AT_ADDRESS(JournalCategory* ConversationJournal::AddCategory(int), ConversationJournal__AddCategory);
#endif
#ifdef ConversationJournal__FindFreeID_x
FUNCTION_AT_ADDRESS(int ConversationJournal::FindFreeID(), ConversationJournal__FindFreeID);
#endif
#ifdef ConversationJournal__AddCategory1_x
FUNCTION_AT_ADDRESS(JournalCategory* ConversationJournal::AddCategory(char*, char*, int), ConversationJournal__AddCategory1);
#endif
#ifdef ConversationJournal__DeleteCategory_x
FUNCTION_AT_ADDRESS(void ConversationJournal::DeleteCategory(int), ConversationJournal__DeleteCategory);
#endif
#ifdef ConversationJournal__GetCategory_x
FUNCTION_AT_ADDRESS(JournalCategory* ConversationJournal::GetCategory(int), ConversationJournal__GetCategory);
#endif
#ifdef ConversationJournal__GetCategory1_x
FUNCTION_AT_ADDRESS(JournalCategory* ConversationJournal::GetCategory(char*), ConversationJournal__GetCategory1);
#endif
#ifdef ConversationJournal__GetCategoryList_x
FUNCTION_AT_ADDRESS(JournalCategory** ConversationJournal::GetCategoryList(), ConversationJournal__GetCategoryList);
#endif
#ifdef ConversationJournal__Save_x
FUNCTION_AT_ADDRESS(int ConversationJournal::Save(char*), ConversationJournal__Save);
#endif
#ifdef ConversationJournal__Load_x
FUNCTION_AT_ADDRESS(int ConversationJournal::Load(char*), ConversationJournal__Load);
#endif
#ifdef ConversationJournal__ReadCategory_x
FUNCTION_AT_ADDRESS(void ConversationJournal::ReadCategory(_iobuf*), ConversationJournal__ReadCategory);
#endif
#ifdef JournalNPC__ReadEntry_x
FUNCTION_AT_ADDRESS(int JournalNPC::ReadEntry(_iobuf*), JournalNPC__ReadEntry);
#endif
#ifdef ConversationJournal__ReadNPC_x
FUNCTION_AT_ADDRESS(JournalNPC* ConversationJournal::ReadNPC(_iobuf*), ConversationJournal__ReadNPC);
#endif
#ifdef CRaid__CRaid_x
FUNCTION_AT_ADDRESS(CRaid::CRaid(), CRaid__CRaid);
#endif
#ifdef CRaid__HandleS2CRaidMessage_x
FUNCTION_AT_ADDRESS(void CRaid::HandleS2CRaidMessage(char*), CRaid__HandleS2CRaidMessage);
#endif
#ifdef CRaid__HandleC2SRaidMessage_x
FUNCTION_AT_ADDRESS(void CRaid::HandleC2SRaidMessage(char*), CRaid__HandleC2SRaidMessage);
#endif
#ifdef CRaid__IsInRaid_x
FUNCTION_AT_ADDRESS(bool CRaid::IsInRaid(), CRaid__IsInRaid);
#endif
#ifdef CRaid__IsInvited_x
FUNCTION_AT_ADDRESS(bool CRaid::IsInvited(), CRaid__IsInvited);
#endif
#ifdef CRaid__ClearInvitedState_x
FUNCTION_AT_ADDRESS(void CRaid::ClearInvitedState(), CRaid__ClearInvitedState);
#endif
#ifdef CRaid__IsRaidLeader_x
FUNCTION_AT_ADDRESS(bool CRaid::IsRaidLeader(), CRaid__IsRaidLeader);
#endif
#ifdef CRaid__IsRaidGroupLeader_x
FUNCTION_AT_ADDRESS(bool CRaid::IsRaidGroupLeader(), CRaid__IsRaidGroupLeader);
#endif
#ifdef CRaid__SetTargetRaidPlayer_x
FUNCTION_AT_ADDRESS(void CRaid::SetTargetRaidPlayer(char*), CRaid__SetTargetRaidPlayer);
#endif
#ifdef CRaid__InitializeRaid_x
FUNCTION_AT_ADDRESS(void CRaid::InitializeRaid(char*), CRaid__InitializeRaid);
#endif
#ifdef CRaid__RaidCreated_x
FUNCTION_AT_ADDRESS(void CRaid::RaidCreated(CreateRaidMessage*), CRaid__RaidCreated);
#endif
#ifdef CRaid__AddRaidMember_x
FUNCTION_AT_ADDRESS(void CRaid::AddRaidMember(RaidAddMember*), CRaid__AddRaidMember);
#endif
#ifdef CRaid__DeleteRaidMember_x
FUNCTION_AT_ADDRESS(void CRaid::DeleteRaidMember(SCRaidMessage*), CRaid__DeleteRaidMember);
#endif
#ifdef CRaid__ChangeLeadership_x
FUNCTION_AT_ADDRESS(void CRaid::ChangeLeadership(char*), CRaid__ChangeLeadership);
#endif
#ifdef CRaid__RenameMember_x
FUNCTION_AT_ADDRESS(void CRaid::RenameMember(RenameRaidMember*), CRaid__RenameMember);
#endif
#ifdef CRaid__HandlePositionChange_x
FUNCTION_AT_ADDRESS(void CRaid::HandlePositionChange(SCRaidMessage*), CRaid__HandlePositionChange);
#endif
#ifdef CRaid__RaidGroupLeaderChange_x
FUNCTION_AT_ADDRESS(void CRaid::RaidGroupLeaderChange(SCRaidMessage*), CRaid__RaidGroupLeaderChange);
#endif
#ifdef CRaid__SetLootTypeResponse_x
FUNCTION_AT_ADDRESS(void CRaid::SetLootTypeResponse(SCRaidMessage*), CRaid__SetLootTypeResponse);
#endif
#ifdef CRaid__HandleSetLootType_x
FUNCTION_AT_ADDRESS(void CRaid::HandleSetLootType(int), CRaid__HandleSetLootType);
#endif
#ifdef CRaid__HandleAddLooter_x
FUNCTION_AT_ADDRESS(void CRaid::HandleAddLooter(char*), CRaid__HandleAddLooter);
#endif
#ifdef CRaid__HandleRemoveLooter_x
FUNCTION_AT_ADDRESS(void CRaid::HandleRemoveLooter(char*), CRaid__HandleRemoveLooter);
#endif
#ifdef CRaid__CreateInviteRaid_x
FUNCTION_AT_ADDRESS(void CRaid::CreateInviteRaid(), CRaid__CreateInviteRaid);
#endif
#ifdef CRaid__SendInviteResponse_x
FUNCTION_AT_ADDRESS(void CRaid::SendInviteResponse(bool), CRaid__SendInviteResponse);
#endif
#ifdef CRaid__SendLeadershipChange_x
FUNCTION_AT_ADDRESS(void CRaid::SendLeadershipChange(char*), CRaid__SendLeadershipChange);
#endif
#ifdef CRaid__RemoveRaidMember_x
FUNCTION_AT_ADDRESS(void CRaid::RemoveRaidMember(), CRaid__RemoveRaidMember);
#endif
#ifdef CRaid__SetLootType_x
FUNCTION_AT_ADDRESS(void CRaid::SetLootType(char*), CRaid__SetLootType);
#endif
#ifdef CRaid__GetLootType_x
FUNCTION_AT_ADDRESS(int CRaid::GetLootType(), CRaid__GetLootType);
#endif
#ifdef CRaid__AddRaidLooter_x
FUNCTION_AT_ADDRESS(void CRaid::AddRaidLooter(), CRaid__AddRaidLooter);
#endif
#ifdef CRaid__RemoveRaidLooter_x
FUNCTION_AT_ADDRESS(void CRaid::RemoveRaidLooter(), CRaid__RemoveRaidLooter);
#endif
#ifdef CRaid__SendRaidChat_x
FUNCTION_AT_ADDRESS(void CRaid::SendRaidChat(char*), CRaid__SendRaidChat);
#endif
#ifdef CRaid__ResetWindow_x
FUNCTION_AT_ADDRESS(void CRaid::ResetWindow(), CRaid__ResetWindow);
#endif
#ifdef CRaid__UpdateClassColor_x
FUNCTION_AT_ADDRESS(void CRaid::UpdateClassColor(int, unsigned long), CRaid__UpdateClassColor);
#endif
#ifdef CRaid__HandleCreateInviteRaid_x
FUNCTION_AT_ADDRESS(void CRaid::HandleCreateInviteRaid(CSRaidMessage*), CRaid__HandleCreateInviteRaid);
#endif
#ifdef CRaid__GetNumRaidMembers_x
FUNCTION_AT_ADDRESS(int CRaid::GetNumRaidMembers(), CRaid__GetNumRaidMembers);
#endif
#ifdef CRaid__GetRaidMemberAt_x
FUNCTION_AT_ADDRESS(RaidMember* CRaid::GetRaidMemberAt(int), CRaid__GetRaidMemberAt);
#endif
#ifdef CRaid__SetRaidLeader_x
FUNCTION_AT_ADDRESS(void CRaid::SetRaidLeader(char*), CRaid__SetRaidLeader);
#endif
#ifdef CRaid__FindPlayerIndex_x
FUNCTION_AT_ADDRESS(int CRaid::FindPlayerIndex(char*), CRaid__FindPlayerIndex);
#endif
#ifdef CRaid__IsRaidMember_x
FUNCTION_AT_ADDRESS(bool CRaid::IsRaidMember(char*), CRaid__IsRaidMember);
#endif
#ifdef CRaid__FindOpenIndex_x
FUNCTION_AT_ADDRESS(int CRaid::FindOpenIndex(), CRaid__FindOpenIndex);
#endif
#ifdef CRaid__FindRaidGroupLeader_x
FUNCTION_AT_ADDRESS(int CRaid::FindRaidGroupLeader(int), CRaid__FindRaidGroupLeader);
#endif
#ifdef CRaid__ResetRaid_x
FUNCTION_AT_ADDRESS(void CRaid::ResetRaid(), CRaid__ResetRaid);
#endif
#ifdef CRaid__DetermineRaidChanges_x
FUNCTION_AT_ADDRESS(void CRaid::DetermineRaidChanges(char*), CRaid__DetermineRaidChanges);
#endif
#ifdef CRaid__SendRaidMsg_x
FUNCTION_AT_ADDRESS(void CRaid::SendRaidMsg(int, char*, char*, int), CRaid__SendRaidMsg);
#endif
#ifdef CRaid__UpdateOptionsWindow_x
FUNCTION_AT_ADDRESS(void CRaid::UpdateOptionsWindow(), CRaid__UpdateOptionsWindow);
#endif
#ifdef CRaid__IsRaidLooter_x
FUNCTION_AT_ADDRESS(bool CRaid::IsRaidLooter(char*), CRaid__IsRaidLooter);
#endif
#ifdef CRaid__UpdateLevelAverage_x
FUNCTION_AT_ADDRESS(void CRaid::UpdateLevelAverage(), CRaid__UpdateLevelAverage);
#endif
#ifdef CDisplay__CDisplay_x
FUNCTION_AT_ADDRESS(CDisplay::CDisplay(HWND), CDisplay__CDisplay);
#endif
#ifdef CDisplay__dCDisplay_x
FUNCTION_AT_ADDRESS(CDisplay::~CDisplay(), CDisplay__dCDisplay);
#endif
#ifdef CDisplay__ResetRenderWindow_x
FUNCTION_AT_ADDRESS(void CDisplay::ResetRenderWindow(), CDisplay__ResetRenderWindow);
#endif
#ifdef CDisplay__SetCCreateCamera_x
FUNCTION_AT_ADDRESS(void CDisplay::SetCCreateCamera(int), CDisplay__SetCCreateCamera);
#endif
#ifdef CDisplay__SetBoneSpriteTint_x
FUNCTION_AT_ADDRESS(int CDisplay::SetBoneSpriteTint(T3D_DAG*, T3D_RGB*), CDisplay__SetBoneSpriteTint);
#endif
#ifdef CDisplay__ReplaceMaterial_x
FUNCTION_AT_ADDRESS(int CDisplay::ReplaceMaterial(char*, char*, T3D_HIERARCHICALSPRITEINSTANCE*, T3D_RGB*, int), CDisplay__ReplaceMaterial);
#endif
#ifdef CDisplay__ReplaceCloakMaterials_x
FUNCTION_AT_ADDRESS(int CDisplay::ReplaceCloakMaterials(int, T3D_HIERARCHICALSPRITEINSTANCE*, T3D_RGB*), CDisplay__ReplaceCloakMaterials);
#endif
#ifdef CDisplay__ReloadUI_x
FUNCTION_AT_ADDRESS(void CDisplay::ReloadUI(bool), CDisplay__ReloadUI);
#endif
#ifdef CDisplay__HandleMaterial_x
FUNCTION_AT_ADDRESS(void CDisplay::HandleMaterial(EQ_PC*, int, EQ_Item*, EQ_Item*), CDisplay__HandleMaterial);
#endif
#ifdef CDisplay__FixHeading_x
FUNCTION_AT_ADDRESS(float CDisplay::FixHeading(float), CDisplay__FixHeading);
#endif
#ifdef CDisplay__GetFloorHeight_x
FUNCTION_AT_ADDRESS(float CDisplay::GetFloorHeight(float, float, float, float, CVector3&, CActorApplicationData*, EActorType, float), CDisplay__GetFloorHeight);
#endif
#ifdef CDisplay__HeadingDiff_x
FUNCTION_AT_ADDRESS(float CDisplay::HeadingDiff(float, float, float*), CDisplay__HeadingDiff);
#endif
#ifdef CDisplay__DeleteParticleCloudInstance_x
FUNCTION_AT_ADDRESS(void CDisplay::DeleteParticleCloudInstance(T3D_PARTICLECLOUDINSTANCE**), CDisplay__DeleteParticleCloudInstance);
#endif
#ifdef CDisplay__ProcessParticleEmitter_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessParticleEmitter(EQSwitch*), CDisplay__ProcessParticleEmitter);
#endif
#ifdef CDisplay__SlideSwitchLeftRight_x
FUNCTION_AT_ADDRESS(bool CDisplay::SlideSwitchLeftRight(EQSwitch*, float, int, float), CDisplay__SlideSwitchLeftRight);
#endif
#ifdef CDisplay__ProcessSwitches_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessSwitches(), CDisplay__ProcessSwitches);
#endif
#ifdef CDisplay__default_cameras_x
FUNCTION_AT_ADDRESS(void CDisplay::default_cameras(), CDisplay__default_cameras);
#endif
#ifdef CDisplay__is_3dON_x
FUNCTION_AT_ADDRESS(int CDisplay::is_3dON(), CDisplay__is_3dON);
#endif
#ifdef CDisplay__is_ParticleSystemON_x
FUNCTION_AT_ADDRESS(int CDisplay::is_ParticleSystemON(), CDisplay__is_ParticleSystemON);
#endif
#ifdef CDisplay__InitCommonLights_x
FUNCTION_AT_ADDRESS(void CDisplay::InitCommonLights(), CDisplay__InitCommonLights);
#endif
#ifdef CDisplay__GetNewPCIniFlag_x
FUNCTION_AT_ADDRESS(int CDisplay::GetNewPCIniFlag(int, int), CDisplay__GetNewPCIniFlag);
#endif
#ifdef CDisplay__ShouldLoadNewPcModel_x
FUNCTION_AT_ADDRESS(int CDisplay::ShouldLoadNewPcModel(int, int), CDisplay__ShouldLoadNewPcModel);
#endif
#ifdef CDisplay__GetIniRaceName_x
FUNCTION_AT_ADDRESS(char* CDisplay::GetIniRaceName(int), CDisplay__GetIniRaceName);
#endif
#ifdef CDisplay__InitWorld_x
FUNCTION_AT_ADDRESS(void CDisplay::InitWorld(), CDisplay__InitWorld);
#endif
#ifdef CDisplay__InitDDraw_x
FUNCTION_AT_ADDRESS(void CDisplay::InitDDraw(), CDisplay__InitDDraw);
#endif
#ifdef CDisplay__InitNewUI_x
FUNCTION_AT_ADDRESS(void CDisplay::InitNewUI(), CDisplay__InitNewUI);
#endif
#ifdef CXWndDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate& CXWndDrawTemplate::operator=(const CXWndDrawTemplate&), CXWndDrawTemplate__operator_equal);
#endif
#ifdef CButtonDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate& CButtonDrawTemplate::operator=(const CButtonDrawTemplate&), CButtonDrawTemplate__operator_equal);
#endif
#ifdef CScrollbarTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CScrollbarTemplate& CScrollbarTemplate::operator=(const CScrollbarTemplate&), CScrollbarTemplate__operator_equal);
#endif
#ifdef CTAFrameDraw__operator_equal_x
FUNCTION_AT_ADDRESS(CTAFrameDraw& CTAFrameDraw::operator=(const CTAFrameDraw&), CTAFrameDraw__operator_equal);
#endif
#ifdef CDisplay__InitCharSelectUI_x
FUNCTION_AT_ADDRESS(void CDisplay::InitCharSelectUI(), CDisplay__InitCharSelectUI);
#endif
#ifdef CDisplay__InitGameUI_x
FUNCTION_AT_ADDRESS(void CDisplay::InitGameUI(), CDisplay__InitGameUI);
#endif
#ifdef CDisplay__CleanCharSelectUI_x
FUNCTION_AT_ADDRESS(void CDisplay::CleanCharSelectUI(), CDisplay__CleanCharSelectUI);
#endif
#ifdef CDisplay__CleanGameUI_x
FUNCTION_AT_ADDRESS(void CDisplay::CleanGameUI(), CDisplay__CleanGameUI);
#endif
#ifdef CDisplay__CleanUpNewUI_x
FUNCTION_AT_ADDRESS(void CDisplay::CleanUpNewUI(), CDisplay__CleanUpNewUI);
#endif
#ifdef CDisplay__ActivateMainUI_x
FUNCTION_AT_ADDRESS(void CDisplay::ActivateMainUI(bool), CDisplay__ActivateMainUI);
#endif
#ifdef CDisplay__DeactivateMainUI_x
FUNCTION_AT_ADDRESS(void CDisplay::DeactivateMainUI(), CDisplay__DeactivateMainUI);
#endif
#ifdef CDisplay__NewUIProcessEscape_x
FUNCTION_AT_ADDRESS(void CDisplay::NewUIProcessEscape(), CDisplay__NewUIProcessEscape);
#endif
#ifdef CDisplay__KeyMapUpdated_x
FUNCTION_AT_ADDRESS(void CDisplay::KeyMapUpdated(), CDisplay__KeyMapUpdated);
#endif
#ifdef CDisplay__GetWorldFilePath_x
FUNCTION_AT_ADDRESS(bool const CDisplay::GetWorldFilePath(char*, const char*), CDisplay__GetWorldFilePath);
#endif
#ifdef CDisplay__LoadWorldFile_x
FUNCTION_AT_ADDRESS(unsigned char CDisplay::LoadWorldFile(char*, char*, int, unsigned char), CDisplay__LoadWorldFile);
#endif
#ifdef CDisplay__LoadNPCFromS3D_x
FUNCTION_AT_ADDRESS(unsigned char CDisplay::LoadNPCFromS3D(char*, char*, char*), CDisplay__LoadNPCFromS3D);
#endif
#ifdef CDisplay__LoadBMPFile_x
FUNCTION_AT_ADDRESS(unsigned char CDisplay::LoadBMPFile(), CDisplay__LoadBMPFile);
#endif
#ifdef CDisplay__StartWorldDisplay_Bailout_x
FUNCTION_AT_ADDRESS(void CDisplay::StartWorldDisplay_Bailout(const char*), CDisplay__StartWorldDisplay_Bailout);
#endif
#ifdef CDisplay__StopWorldDisplay_x
FUNCTION_AT_ADDRESS(void CDisplay::StopWorldDisplay(), CDisplay__StopWorldDisplay);
#endif
#ifdef CDisplay__SetGammaCorrection_x
FUNCTION_AT_ADDRESS(void CDisplay::SetGammaCorrection(float), CDisplay__SetGammaCorrection);
#endif
#ifdef CDisplay__SetPCloudDensity_x
FUNCTION_AT_ADDRESS(void CDisplay::SetPCloudDensity(int), CDisplay__SetPCloudDensity);
#endif
#ifdef CDisplay__CleanUpDDraw_x
FUNCTION_AT_ADDRESS(void CDisplay::CleanUpDDraw(), CDisplay__CleanUpDDraw);
#endif
#ifdef CDisplay__IsShield_x
FUNCTION_AT_ADDRESS(unsigned int CDisplay::IsShield(int) const, CDisplay__IsShield);
#endif
#ifdef CDisplay__GetItemType_x
FUNCTION_AT_ADDRESS(int CDisplay::GetItemType(int), CDisplay__GetItemType);
#endif
#ifdef CDisplay__GetUserDefinedColor_x
FUNCTION_AT_ADDRESS(unsigned long CDisplay::GetUserDefinedColor(int), CDisplay__GetUserDefinedColor);
#endif
#ifdef CDisplay__SetUserDefinedColor_x
FUNCTION_AT_ADDRESS(void CDisplay::SetUserDefinedColor(int, int, int, int), CDisplay__SetUserDefinedColor);
#endif
#ifdef CDisplay__InitUserDefinedColors_x
FUNCTION_AT_ADDRESS(void CDisplay::InitUserDefinedColors(), CDisplay__InitUserDefinedColors);
#endif
#ifdef CDisplay__WriteTextHD2_x
FUNCTION_AT_ADDRESS(int CDisplay::WriteTextHD2(const char*, int, int, int), CDisplay__WriteTextHD2);
#endif
#ifdef CXWndManager__GetDisplayWidth_x
FUNCTION_AT_ADDRESS(uint32_t CXWndManager::GetDisplayWidth() const, CXWndManager__GetDisplayWidth);
#endif
#ifdef CXWndManager__GetFont_x
FUNCTION_AT_ADDRESS(CTextureFont* CXWndManager::GetFont(int) const, CXWndManager__GetFont);
#endif
#ifdef CDisplay__SetActorScaleFactor_x
FUNCTION_AT_ADDRESS(void CDisplay::SetActorScaleFactor(struct T3D_tagACTORINSTANCE*, float, unsigned char), CDisplay__SetActorScaleFactor);
#endif
#ifdef CDisplay__ShowDisplay_x
FUNCTION_AT_ADDRESS(void CDisplay::ShowDisplay(), CDisplay__ShowDisplay);
#endif
#ifdef CDisplay__CheckForScreenModeToggle_x
FUNCTION_AT_ADDRESS(void CDisplay::CheckForScreenModeToggle(), CDisplay__CheckForScreenModeToggle);
#endif
#ifdef CDisplay__Render_World_x
FUNCTION_AT_ADDRESS(void CDisplay::Render_World(), CDisplay__Render_World);
#endif
#ifdef CDisplay__SetGenericEnvironment_x
FUNCTION_AT_ADDRESS(void CDisplay::SetGenericEnvironment(), CDisplay__SetGenericEnvironment);
#endif
#ifdef CDisplay__SetupEmitterEnvironment_x
FUNCTION_AT_ADDRESS(void CDisplay::SetupEmitterEnvironment(), CDisplay__SetupEmitterEnvironment);
#endif
#ifdef CDisplay__UpdateMobileEmitterLocations_x
FUNCTION_AT_ADDRESS(void CDisplay::UpdateMobileEmitterLocations(), CDisplay__UpdateMobileEmitterLocations);
#endif
#ifdef CDisplay__RealRender_World_x
FUNCTION_AT_ADDRESS(void CDisplay::RealRender_World(), CDisplay__RealRender_World);
#endif
#ifdef CDisplay__Render_MinWorld_x
FUNCTION_AT_ADDRESS(void CDisplay::Render_MinWorld(), CDisplay__Render_MinWorld);
#endif
#ifdef CDisplay__StartWeather_x
FUNCTION_AT_ADDRESS(void CDisplay::StartWeather(int, unsigned char), CDisplay__StartWeather);
#endif
#ifdef CDisplay__ProcessWeather_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessWeather(), CDisplay__ProcessWeather);
#endif
#ifdef CDisplay__StopWeather_x
FUNCTION_AT_ADDRESS(void CDisplay::StopWeather(int, unsigned char), CDisplay__StopWeather);
#endif
#ifdef CDisplay__LightningStrike_x
FUNCTION_AT_ADDRESS(void CDisplay::LightningStrike(), CDisplay__LightningStrike);
#endif
#ifdef CDisplay__GetNearestPlayerInView_x
FUNCTION_AT_ADDRESS(EQPlayer* CDisplay::GetNearestPlayerInView(float, bool), CDisplay__GetNearestPlayerInView);
#endif
#ifdef CDisplay__ProcessEffects_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessEffects(), CDisplay__ProcessEffects);
#endif
#ifdef CDisplay__ProcessCloud_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessCloud(), CDisplay__ProcessCloud);
#endif
#ifdef CDisplay__DDrawUpdateDisplay_x
FUNCTION_AT_ADDRESS(void CDisplay::DDrawUpdateDisplay(), CDisplay__DDrawUpdateDisplay);
#endif
#ifdef CDisplay__SetViewActor_x
FUNCTION_AT_ADDRESS(void CDisplay::SetViewActor(CActorInterface*), CDisplay__SetViewActor);
#endif
#ifdef CDisplay__SetRenderWindow_x
FUNCTION_AT_ADDRESS(void CDisplay::SetRenderWindow(int mode), CDisplay__SetRenderWindow);
#endif
#ifdef CDisplay__ToggleScreenshotMode_x
FUNCTION_AT_ADDRESS(void CDisplay::ToggleScreenshotMode(), CDisplay__ToggleScreenshotMode);
#endif
#ifdef CDisplay__SwitchToDefaultCameraMode_x
FUNCTION_AT_ADDRESS(void CDisplay::SwitchToDefaultCameraMode(), CDisplay__SwitchToDefaultCameraMode);
#endif
#ifdef CDisplay__SetYon_x
FUNCTION_AT_ADDRESS(void CDisplay::SetYon(float), CDisplay__SetYon);
#endif
#ifdef CDisplay__SetActorYon_x
FUNCTION_AT_ADDRESS(void CDisplay::SetActorYon(float), CDisplay__SetActorYon);
#endif
#ifdef CDisplay__SetViewAngle_x
FUNCTION_AT_ADDRESS(void CDisplay::SetViewAngle(int), CDisplay__SetViewAngle);
#endif
#ifdef CDisplay__UpdateCameraAfterModeSwitch_x
FUNCTION_AT_ADDRESS(void CDisplay::UpdateCameraAfterModeSwitch(), CDisplay__UpdateCameraAfterModeSwitch);
#endif
#ifdef CDisplay__ChangeVideoMode_x
FUNCTION_AT_ADDRESS(void CDisplay::ChangeVideoMode(), CDisplay__ChangeVideoMode);
#endif
#ifdef CDisplay__ToggleView_x
FUNCTION_AT_ADDRESS(void CDisplay::ToggleView(), CDisplay__ToggleView);
#endif
#ifdef CDisplay__SetFog_x
FUNCTION_AT_ADDRESS(void CDisplay::SetFog(bool, float, float, unsigned char, unsigned char, unsigned char), CDisplay__SetFog);
#endif
#ifdef CDisplay__ClearScreen_x
FUNCTION_AT_ADDRESS(void CDisplay::ClearScreen(), CDisplay__ClearScreen);
#endif
#ifdef CDisplay__CreatePlayerActor_x
FUNCTION_AT_ADDRESS(void CDisplay::CreatePlayerActor(EQPlayer*), CDisplay__CreatePlayerActor);
#endif
#ifdef CDisplay__SetActorUserData_x
FUNCTION_AT_ADDRESS(void CDisplay::SetActorUserData(struct T3D_tagACTORINSTANCE*, void*), CDisplay__SetActorUserData);
#endif
#ifdef CDisplay__CreateLight_x
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT* CDisplay::CreateLight(unsigned char, float, float, float, float), CDisplay__CreateLight);
#endif
#ifdef CDisplay__GetIntensity_x
FUNCTION_AT_ADDRESS(unsigned char CDisplay::GetIntensity(unsigned char), CDisplay__GetIntensity);
#endif
#ifdef CDisplay__DeleteLight_x
FUNCTION_AT_ADDRESS(void CDisplay::DeleteLight(struct T3D_POINTLIGHT*), CDisplay__DeleteLight);
#endif
#ifdef CDisplay__PlaySoundAtLocation_x
FUNCTION_AT_ADDRESS(void CDisplay::PlaySoundAtLocation(float, float, float, int), CDisplay__PlaySoundAtLocation);
#endif
#ifdef CDisplay__SetUserRender_x
FUNCTION_AT_ADDRESS(long CDisplay::SetUserRender(int), CDisplay__SetUserRender);
#endif
#ifdef CDisplay__GetClickedActor_x
FUNCTION_AT_ADDRESS(CActorInterface* CDisplay::GetClickedActor(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2), CDisplay__GetClickedActor);
#endif
#ifdef CDisplay__CreateActor_x
FUNCTION_AT_ADDRESS(CActorInterface* CDisplay::CreateActor(char*, float, float, float, float, float, float, bool, bool), CDisplay__CreateActor);
#endif
#ifdef CDisplay__SetActorBoundingRadius_x
FUNCTION_AT_ADDRESS(float CDisplay::SetActorBoundingRadius(struct T3D_tagACTORINSTANCE*, float, float), CDisplay__SetActorBoundingRadius);
#endif
#ifdef CDisplay__DeleteActor_x
FUNCTION_AT_ADDRESS(void CDisplay::DeleteActor(struct T3D_tagACTORINSTANCE*), CDisplay__DeleteActor);
#endif
#ifdef CDisplay__dupActorHierarchicalSprite_x
FUNCTION_AT_ADDRESS(struct T3D_HIERARCHICALSPRITEINSTANCE* CDisplay::dupActorHierarchicalSprite(struct T3D_tagACTORINSTANCE*), CDisplay__dupActorHierarchicalSprite);
#endif
#ifdef CDisplay__ToggleCharacterNameSprites_x
FUNCTION_AT_ADDRESS(void CDisplay::ToggleCharacterNameSprites(bool), CDisplay__ToggleCharacterNameSprites);
#endif
#ifdef CDisplay__ToggleNpcNameSprites_x
FUNCTION_AT_ADDRESS(void CDisplay::ToggleNpcNameSprites(bool), CDisplay__ToggleNpcNameSprites);
#endif
#ifdef CDisplay__TurnInfravisionEffectOn_x
FUNCTION_AT_ADDRESS(int CDisplay::TurnInfravisionEffectOn(), CDisplay__TurnInfravisionEffectOn);
#endif
#ifdef CDisplay__TurnInfravisionEffectOff_x
FUNCTION_AT_ADDRESS(int CDisplay::TurnInfravisionEffectOff(), CDisplay__TurnInfravisionEffectOff);
#endif
#ifdef CDisplay__SpurtBloodOnDag_x
FUNCTION_AT_ADDRESS(void CDisplay::SpurtBloodOnDag(struct T3D_DAG*), CDisplay__SpurtBloodOnDag);
#endif
#ifdef CDisplay__SetDayPeriod_x
FUNCTION_AT_ADDRESS(void CDisplay::SetDayPeriod(unsigned char), CDisplay__SetDayPeriod);
#endif
#ifdef CDisplay__SetSkyLayer_x
FUNCTION_AT_ADDRESS(void CDisplay::SetSkyLayer(int), CDisplay__SetSkyLayer);
#endif
#ifdef CDisplay__GetSkyTime_x
FUNCTION_AT_ADDRESS(int CDisplay::GetSkyTime(int*, int*), CDisplay__GetSkyTime);
#endif
#ifdef CDisplay__SetSunLight_x
FUNCTION_AT_ADDRESS(void CDisplay::SetSunLight(), CDisplay__SetSunLight);
#endif
#ifdef CDisplay__SetSkyBackground_x
FUNCTION_AT_ADDRESS(void CDisplay::SetSkyBackground(), CDisplay__SetSkyBackground);
#endif
#ifdef CDisplay__ProcessSky_x
FUNCTION_AT_ADDRESS(void CDisplay::ProcessSky(), CDisplay__ProcessSky);
#endif
#ifdef CDisplay__SimpleDistance_x
FUNCTION_AT_ADDRESS(float CDisplay::SimpleDistance(float, float, float, float, float, float, float), CDisplay__SimpleDistance);
#endif
#ifdef CDisplay__TrueDistance_x
FUNCTION_AT_ADDRESS(float CDisplay::TrueDistance(float, float, float, float, float, float, float), CDisplay__TrueDistance);
#endif
#ifdef CDisplay__PlayerSimpleDistance_x
FUNCTION_AT_ADDRESS(float CDisplay::PlayerSimpleDistance(EQPlayer*, EQPlayer*, float), CDisplay__PlayerSimpleDistance);
#endif
#ifdef CDisplay__PlayerDistance_x
FUNCTION_AT_ADDRESS(float CDisplay::PlayerDistance(EQPlayer*, EQPlayer*, float), CDisplay__PlayerDistance);
#endif
#ifdef CDisplay__hideGrassObjects_x
FUNCTION_AT_ADDRESS(void CDisplay::hideGrassObjects(), CDisplay__hideGrassObjects);
#endif
#ifdef CDisplay__updateGrassObjects_x
FUNCTION_AT_ADDRESS(void CDisplay::updateGrassObjects(), CDisplay__updateGrassObjects);
#endif
#ifdef CDisplay__loadGrassObjects_x
FUNCTION_AT_ADDRESS(void CDisplay::loadGrassObjects(char*), CDisplay__loadGrassObjects);
#endif
#ifdef CDisplay__SetAmbientLight_x
FUNCTION_AT_ADDRESS(void CDisplay::SetAmbientLight(float), CDisplay__SetAmbientLight);
#endif
#ifdef CDisplay__SetViewActorByName_x
FUNCTION_AT_ADDRESS(void CDisplay::SetViewActorByName(char*), CDisplay__SetViewActorByName);
#endif
#ifdef CDisplay__SetActorSpriteTint_x
FUNCTION_AT_ADDRESS(void CDisplay::SetActorSpriteTint(struct _EQRGB*, struct T3D_tagACTORINSTANCE*), CDisplay__SetActorSpriteTint);
#endif
#ifdef CDisplay__FreeAllItemLists_x
FUNCTION_AT_ADDRESS(void CDisplay::FreeAllItemLists(), CDisplay__FreeAllItemLists);
#endif
#ifdef CActionsWnd__MainPageActivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageActivate(), CActionsWnd__MainPageActivate);
#endif
#ifdef CActionsWnd__MainPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::MainPageDeactivate(), CActionsWnd__MainPageDeactivate);
#endif
#ifdef CActionsWnd__SocialsPageDeactivate_x
FUNCTION_AT_ADDRESS(int CActionsWnd::SocialsPageDeactivate(), CActionsWnd__SocialsPageDeactivate);
#endif
#ifdef CGroupSearchWnd__GroupListPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::GroupListPageOnProcessFrame(), CGroupSearchWnd__GroupListPageOnProcessFrame);
#endif
#ifdef CGroupSearchWnd__PlayerListPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int CGroupSearchWnd::PlayerListPageOnProcessFrame(), CGroupSearchWnd__PlayerListPageOnProcessFrame);
#endif
#ifdef COptionsWnd__KeyboardPageOnProcessFrame_x
FUNCTION_AT_ADDRESS(int COptionsWnd::KeyboardPageOnProcessFrame(), COptionsWnd__KeyboardPageOnProcessFrame);
#endif
#ifdef CDisplay__GenericSphereColl_x
FUNCTION_AT_ADDRESS(bool CDisplay::GenericSphereColl(float, float, float, float, float, float, float*, float*, float*, unsigned char), CDisplay__GenericSphereColl);
#endif
#ifdef CDisplay__FindZoneTopZ_x
FUNCTION_AT_ADDRESS(float CDisplay::FindZoneTopZ(float, float, float), CDisplay__FindZoneTopZ);
#endif
#ifdef CDisplay__GetEnvironment_x
FUNCTION_AT_ADDRESS(unsigned char CDisplay::GetEnvironment(float, float, float, int*), CDisplay__GetEnvironment);
#endif
#ifdef CDisplay__MoveLocalPlayerToSafeCoords_x
FUNCTION_AT_ADDRESS(void CDisplay::MoveLocalPlayerToSafeCoords(), CDisplay__MoveLocalPlayerToSafeCoords);
#endif
#ifdef CDisplay__SetupEQPlayers_x
FUNCTION_AT_ADDRESS(void CDisplay::SetupEQPlayers(), CDisplay__SetupEQPlayers);
#endif
#ifdef CDisplay__MoveLight_x
FUNCTION_AT_ADDRESS(void CDisplay::MoveLight(struct T3D_POINTLIGHT*, struct _physicsinfo*), CDisplay__MoveLight);
#endif
#ifdef CDistillerInfo__GetIDFromRecordNum_x
FUNCTION_AT_ADDRESS(int CDistillerInfo::GetIDFromRecordNum(int ID, bool bWhat), CDistillerInfo__GetIDFromRecordNum);
#endif
#ifdef CDistillerInfo__Instance_x
FUNCTION_AT_ADDRESS(CDistillerInfo& CDistillerInfo::Instance(), CDistillerInfo__Instance);
#endif
#ifdef CAdvancedLootWnd__DoAdvLootAction_x
FUNCTION_AT_ADDRESS(DWORD CAdvancedLootWnd::DoAdvLootAction(int, const CXStr&, DWORD, int), CAdvancedLootWnd__DoAdvLootAction);
#endif
#ifdef CAdvancedLootWnd__DoSharedAdvLootAction_x
FUNCTION_AT_ADDRESS(DWORD CAdvancedLootWnd::DoSharedAdvLootAction(PLOOTITEM pLootItem, const CXStr& Assignee, DWORD Action, int Quantity), CAdvancedLootWnd__DoSharedAdvLootAction);
#endif
#ifdef CAltAbilityData__GetMercCurrentRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMercCurrentRank(int), CAltAbilityData__GetMercCurrentRank);
#endif
#ifdef CAltAbilityData__GetMercMaxRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMercMaxRank(int), CAltAbilityData__GetMercMaxRank);
#endif
#ifdef CAltAbilityData__GetMaxRank_x
FUNCTION_AT_ADDRESS(int CAltAbilityData::GetMaxRank(), CAltAbilityData__GetMaxRank);
#endif
#ifdef EQ_AltAbility__EQ_AltAbility_x
FUNCTION_AT_ADDRESS(EQ_AltAbility::EQ_AltAbility(int), EQ_AltAbility__EQ_AltAbility);
#endif
#ifdef AltAdvManager__AltAdvManager_x
FUNCTION_AT_ADDRESS(AltAdvManager::AltAdvManager(), AltAdvManager__AltAdvManager);
#endif
#ifdef AltAdvManager__GetAAById_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(ALTABILITY* AltAdvManager::GetAAById(int, int), AltAdvManager__GetAAById);
#else
FUNCTION_AT_ADDRESS(ALTABILITY* AltAdvManager::GetAAById(int), AltAdvManager__GetAAById);
#endif
#endif
#ifdef AltAdvManager__IsAbilityReady_x
FUNCTION_AT_ADDRESS(bool AltAdvManager::IsAbilityReady(PcZoneClient*, ALTABILITY*, int*, int*), AltAdvManager__IsAbilityReady);
#endif
#ifdef AltAdvManager__CalculateHideTimeReduce_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateHideTimeReduce(EQ_PC*), AltAdvManager__CalculateHideTimeReduce);
#endif
#ifdef AltAdvManager__GetCalculatedTimer_x
FUNCTION_AT_ADDRESS(unsigned long AltAdvManager::GetCalculatedTimer(PcZoneClient*, ALTABILITY*), AltAdvManager__GetCalculatedTimer);
#endif
#ifdef AltAdvManager__GetNextAbilityCost_x
FUNCTION_AT_ADDRESS(int AltAdvManager::GetNextAbilityCost(int, int), AltAdvManager__GetNextAbilityCost);
#endif
#ifdef AltAdvManager__TotalPointsInSkill_x
FUNCTION_AT_ADDRESS(int AltAdvManager::TotalPointsInSkill(int, int), AltAdvManager__TotalPointsInSkill);
#endif
#ifdef AltAdvManager__CalculateStalwartEnduranceChance_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateStalwartEnduranceChance(EQ_PC*), AltAdvManager__CalculateStalwartEnduranceChance);
#endif
#ifdef AltAdvManager__CalculateLoHHarmTouchReuseTimer_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateLoHHarmTouchReuseTimer(EQ_PC*, int), AltAdvManager__CalculateLoHHarmTouchReuseTimer);
#endif
#ifdef AltAdvManager__CalculateSingingMasteryMod_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateSingingMasteryMod(EQ_PC*, int), AltAdvManager__CalculateSingingMasteryMod);
#endif
#ifdef AltAdvManager__CalculateInstrumentMasteryMod_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateInstrumentMasteryMod(EQ_PC*), AltAdvManager__CalculateInstrumentMasteryMod);
#endif
#ifdef AltAdvManager__CalculateFleetOfFoot_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateFleetOfFoot(EQ_PC*), AltAdvManager__CalculateFleetOfFoot);
#endif
#ifdef AltAdvManager__CalculateNimbleEvasionChance_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateNimbleEvasionChance(EQ_PC*), AltAdvManager__CalculateNimbleEvasionChance);
#endif
#ifdef AltAdvManager__CalculateDoubleAttackChance_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateDoubleAttackChance(EQ_PC*, int, unsigned char), AltAdvManager__CalculateDoubleAttackChance);
#endif
#ifdef AltAdvManager__CalculateMitigationBoost_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateMitigationBoost(EQ_PC*, int), AltAdvManager__CalculateMitigationBoost);
#endif
#ifdef AltAdvManager__CalculateSpellCastingMastery_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateSpellCastingMastery(EQ_PC*), AltAdvManager__CalculateSpellCastingMastery);
#endif
#ifdef AltAdvManager__CalculateMaxHPAA_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateMaxHPAA(EQ_PC*, int), AltAdvManager__CalculateMaxHPAA);
#endif
#ifdef AltAdvManager__CalculateMaxStatAA_x
FUNCTION_AT_ADDRESS(int AltAdvManager::CalculateMaxStatAA(EQ_PC*, int), AltAdvManager__CalculateMaxStatAA);
#endif
#ifdef AltAdvManager__GetAbilityTitle_x
FUNCTION_AT_ADDRESS(int AltAdvManager::GetAbilityTitle(EQPlayer*), AltAdvManager__GetAbilityTitle);
#endif
#ifdef AltAdvManager__AltSkillReqs_x
FUNCTION_AT_ADDRESS(int AltAdvManager::AltSkillReqs(EQ_PC*, int), AltAdvManager__AltSkillReqs);
#endif
#ifdef AltAdvManager__GetAALevelNeeded_x
FUNCTION_AT_ADDRESS(int AltAdvManager::GetAALevelNeeded(EQ_PC*, int), AltAdvManager__GetAALevelNeeded);
#endif
#ifdef AltAdvManager__MeetsPoPLevelReqs_x
FUNCTION_AT_ADDRESS(int AltAdvManager::MeetsPoPLevelReqs(EQ_PC*, int, int), AltAdvManager__MeetsPoPLevelReqs);
#endif
#ifdef AltAdvManager__CanTrainAbility_x
FUNCTION_AT_ADDRESS(bool AltAdvManager::CanTrainAbility(PcZoneClient*, CAltAbilityData*, bool, bool, bool), AltAdvManager__CanTrainAbility);
#endif
#ifdef AltAdvManager__CanSeeAbility_x
FUNCTION_AT_ADDRESS(bool AltAdvManager::CanSeeAbility(PcZoneClient*, CAltAbilityData*), AltAdvManager__CanSeeAbility);
#endif
#ifdef AltAdvManager__AbilitiesByClass_x
FUNCTION_AT_ADDRESS(int AltAdvManager::AbilitiesByClass(int, int), AltAdvManager__AbilitiesByClass);
#endif
#ifdef AltAdvManager__GetAbilityReqs_x
FUNCTION_AT_ADDRESS(void AltAdvManager::GetAbilityReqs(char*, int), AltAdvManager__GetAbilityReqs);
#endif
#ifdef EQ_CharacterData__EQ_CharacterDataResetAllMembers_x
FUNCTION_AT_ADDRESS(void EQ_CharacterData::EQ_CharacterDataResetAllMembers(), EQ_CharacterData__EQ_CharacterDataResetAllMembers);
#endif
#ifdef EQ_Affect__Reset_x
FUNCTION_AT_ADDRESS(void EQ_Affect::Reset(), EQ_Affect__Reset);
#endif
#ifdef EQ_Affect__GetAffectData_x
FUNCTION_AT_ADDRESS(int EQ_Affect::GetAffectData(int) const, EQ_Affect__GetAffectData);
#endif
#ifdef EQ_Character__EQ_Character_x
FUNCTION_AT_ADDRESS(EQ_Character::EQ_Character(), EQ_Character__EQ_Character);
#endif
#ifdef EQ_Character__dEQ_Character_x
FUNCTION_AT_ADDRESS(EQ_Character::~EQ_Character(), EQ_Character__dEQ_Character);
#endif
#ifdef EQ_Character__EQ_CharacterResetAllMembers_x
FUNCTION_AT_ADDRESS(void EQ_Character::EQ_CharacterResetAllMembers(), EQ_Character__EQ_CharacterResetAllMembers);
#endif
#ifdef EQ_Character__ModifyCurHP_x
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(void EQ_Character::ModifyCurHP(int32_t modification, PlayerZoneClient* resposibleplayer, int skilltype), EQ_Character__ModifyCurHP);
#else
FUNCTION_AT_ADDRESS(void EQ_Character::ModifyCurHP(int64_t modification, PlayerZoneClient* resposibleplayer, int skilltype), EQ_Character__ModifyCurHP);
#endif
#endif
#ifdef EQ_Character__normal_to_special_x
FUNCTION_AT_ADDRESS(int __cdecl EQ_Character::normal_to_special(int), EQ_Character__normal_to_special);
#endif
#ifdef EQ_Character__IsSpellcaster_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsSpellcaster(), EQ_Character__IsSpellcaster);
#endif
#ifdef EQ_Character__DoLight_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoLight(unsigned char), EQ_Character__DoLight);
#endif
#ifdef EQ_Character__Skill_x
FUNCTION_AT_ADDRESS(int EQ_Character::Skill(int), EQ_Character__Skill);
#endif
#ifdef EQ_Character__HasSpell_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasSpell(int), EQ_Character__HasSpell);
#endif
#ifdef EQ_Character__ResetCur_HP_x
FUNCTION_AT_ADDRESS(void EQ_Character::ResetCur_HP(int), EQ_Character__ResetCur_HP);
#endif
#ifdef EQ_Character__GetEnduranceRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat), EQ_Character__GetEnduranceRegen);
#endif
#ifdef EQ_Character__GetHPRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetHPRegen(bool bIncItemsAndBuffs, bool* bIsBleeding, bool bCombat), EQ_Character__GetHPRegen);
#endif
#ifdef EQ_Character__GetManaRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetManaRegen(bool bincItemsAndBuffs, bool bCombat), EQ_Character__GetManaRegen);
#endif
#ifdef EQ_Character__Cur_HP_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Cur_HP(int SpawnType, bool bCapAtMax), EQ_Character__Cur_HP);
#endif
#ifdef EQ_Character__GetHPFromStamina_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetHPFromStamina(int), EQ_Character__GetHPFromStamina);
#endif
#ifdef EQ_Character__Cur_Mana_x
FUNCTION_AT_ADDRESS(int EQ_Character::Cur_Mana(bool bCapAtMax), EQ_Character__Cur_Mana);
#endif
#ifdef EQ_Character__IsMage_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsMage(), EQ_Character__IsMage);
#endif
#ifdef EQ_Character__GetClassACBonus_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetClassACBonus(int), EQ_Character__GetClassACBonus);
#endif
#ifdef EQ_Character__ac_x
FUNCTION_AT_ADDRESS(int EQ_Character::ac(bool), EQ_Character__ac);
#endif
#ifdef EQ_Character__compute_tohit_x
FUNCTION_AT_ADDRESS(int EQ_Character::compute_tohit(unsigned char), EQ_Character__compute_tohit);
#endif
#ifdef EQ_Character__defense_agility_bonus_x
FUNCTION_AT_ADDRESS(int EQ_Character::defense_agility_bonus(), EQ_Character__defense_agility_bonus);
#endif
#ifdef EQ_Character__compute_defense_x
FUNCTION_AT_ADDRESS(int EQ_Character::compute_defense(), EQ_Character__compute_defense);
#endif
#ifdef EQ_Character__offense_x
FUNCTION_AT_ADDRESS(int EQ_Character::offense(unsigned char), EQ_Character__offense);
#endif
#ifdef EQ_Character__HasSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasSkill(unsigned char), EQ_Character__HasSkill);
#endif
#ifdef EQ_Character__HasInnateSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasInnateSkill(unsigned char, int), EQ_Character__HasInnateSkill);
#endif
#ifdef EQ_Character__InitMyLanguages_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitMyLanguages(), EQ_Character__InitMyLanguages);
#endif
#ifdef EQ_Character__BaneDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::BaneDamage(EQ_Equipment*), EQ_Character__BaneDamage);
#endif
#ifdef EQ_Character__ElementResistDmg_x
FUNCTION_AT_ADDRESS(int EQ_Character::ElementResistDmg(EQ_Equipment*, int), EQ_Character__ElementResistDmg);
#endif
#ifdef EQ_Character__save_bash_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_bash(int), EQ_Character__save_bash);
#endif
#ifdef EQ_Character__CapStat_x
FUNCTION_AT_ADDRESS(int EQ_Character::CapStat(int, int), EQ_Character__CapStat);
#endif
#ifdef EQ_Character__CalcFoodDrinkBonus_x
FUNCTION_AT_ADDRESS(void EQ_Character::CalcFoodDrinkBonus(int), EQ_Character__CalcFoodDrinkBonus);
#endif
#ifdef EQ_Character__basesave_magic_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_magic(), EQ_Character__basesave_magic);
#endif
#ifdef EQ_Character__save_magic_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_magic(), EQ_Character__save_magic);
#endif
#ifdef EQ_Character__basesave_fire_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_fire(), EQ_Character__basesave_fire);
#endif
#ifdef EQ_Character__save_fire_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_fire(), EQ_Character__save_fire);
#endif
#ifdef EQ_Character__basesave_cold_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_cold(), EQ_Character__basesave_cold);
#endif
#ifdef EQ_Character__save_cold_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_cold(), EQ_Character__save_cold);
#endif
#ifdef EQ_Character__basesave_disease_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_disease(), EQ_Character__basesave_disease);
#endif
#ifdef EQ_Character__save_disease_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_disease(), EQ_Character__save_disease);
#endif
#ifdef EQ_Character__basesave_poison_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_poison(), EQ_Character__basesave_poison);
#endif
#ifdef EQ_Character__save_poison_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_poison(), EQ_Character__save_poison);
#endif
#ifdef EQ_Character__Str_x
FUNCTION_AT_ADDRESS(int EQ_Character::Str(), EQ_Character__Str);
#endif
#ifdef EQ_Character__Sta_x
FUNCTION_AT_ADDRESS(int EQ_Character::Sta(), EQ_Character__Sta);
#endif
#ifdef EQ_Character__Cha_x
FUNCTION_AT_ADDRESS(int EQ_Character::Cha(), EQ_Character__Cha);
#endif
#ifdef EQ_Character__Dex_x
FUNCTION_AT_ADDRESS(int EQ_Character::Dex(), EQ_Character__Dex);
#endif
#ifdef EQ_Character__Int_x
FUNCTION_AT_ADDRESS(int EQ_Character::Int(), EQ_Character__Int);
#endif
#ifdef EQ_Character__Agi_x
FUNCTION_AT_ADDRESS(int EQ_Character::Agi(), EQ_Character__Agi);
#endif
#ifdef EQ_Character__Wis_x
FUNCTION_AT_ADDRESS(int EQ_Character::Wis(), EQ_Character__Wis);
#endif
#ifdef EQ_Character__ApplyFatigue_x
FUNCTION_AT_ADDRESS(int EQ_Character::ApplyFatigue(int), EQ_Character__ApplyFatigue);
#endif
#ifdef EQ_Character__max_encumbrance_x
FUNCTION_AT_ADDRESS(int EQ_Character::max_encumbrance(), EQ_Character__max_encumbrance);
#endif
#ifdef EQ_Character__CanUseItem_x
FUNCTION_AT_ADDRESS(bool EQ_Character1::CanUseItem(PCONTENTS*, bool, bool), EQ_Character__CanUseItem);
#endif
#ifdef EQ_Character__encum_factor_x
FUNCTION_AT_ADDRESS(float EQ_Character::encum_factor(), EQ_Character__encum_factor);
#endif
#ifdef EQ_Character__cur_encumbrance_x
FUNCTION_AT_ADDRESS(int EQ_Character::cur_encumbrance(), EQ_Character__cur_encumbrance);
#endif
#ifdef EQ_Character__Race_x
FUNCTION_AT_ADDRESS(char* EQ_Character::Race(int), EQ_Character__Race);
#endif
#ifdef EQ_Character__Class_x
FUNCTION_AT_ADDRESS(char* EQ_Character::Class(int), EQ_Character__Class);
#endif
#ifdef EQ_Character__KunarkClass_x
FUNCTION_AT_ADDRESS(char* EQ_Character::KunarkClass(int, int, int, bool), EQ_Character__KunarkClass);
#endif
#ifdef EQ_Character__ClassMin_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ClassMin(int, int, unsigned char), EQ_Character__ClassMin);
#endif
#ifdef EQ_Character__CheckClass_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CheckClass(int, int), EQ_Character__CheckClass);
#endif
#ifdef EQ_Character__CanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanWorship(int, int, unsigned char), EQ_Character__CanWorship);
#endif
#ifdef EQ_Character__HumanCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HumanCanWorship(unsigned char, unsigned char), EQ_Character__HumanCanWorship);
#endif
#ifdef EQ_Character__BarbarianCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::BarbarianCanWorship(unsigned char, unsigned char), EQ_Character__BarbarianCanWorship);
#endif
#ifdef EQ_Character__EruditeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::EruditeCanWorship(unsigned char, unsigned char), EQ_Character__EruditeCanWorship);
#endif
#ifdef EQ_Character__ElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ElfCanWorship(unsigned char, unsigned char), EQ_Character__ElfCanWorship);
#endif
#ifdef EQ_Character__HighElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HighElfCanWorship(unsigned char, unsigned char), EQ_Character__HighElfCanWorship);
#endif
#ifdef EQ_Character__DarkElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::DarkElfCanWorship(unsigned char, unsigned char), EQ_Character__DarkElfCanWorship);
#endif
#ifdef EQ_Character__HalfElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HalfElfCanWorship(unsigned char, unsigned char), EQ_Character__HalfElfCanWorship);
#endif
#ifdef EQ_Character__DwarfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::DwarfCanWorship(unsigned char, unsigned char), EQ_Character__DwarfCanWorship);
#endif
#ifdef EQ_Character__TrollCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::TrollCanWorship(unsigned char, unsigned char), EQ_Character__TrollCanWorship);
#endif
#ifdef EQ_Character__OgreCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::OgreCanWorship(unsigned char, unsigned char), EQ_Character__OgreCanWorship);
#endif
#ifdef EQ_Character__HalflingCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HalflingCanWorship(unsigned char, unsigned char), EQ_Character__HalflingCanWorship);
#endif
#ifdef EQ_Character__GnomeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::GnomeCanWorship(unsigned char, unsigned char), EQ_Character__GnomeCanWorship);
#endif
#ifdef EQ_Character__IksarCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::IksarCanWorship(unsigned char, unsigned char), EQ_Character__IksarCanWorship);
#endif
#ifdef EQ_Character__VahShirCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::VahShirCanWorship(unsigned char, unsigned char), EQ_Character__VahShirCanWorship);
#endif
#ifdef EQ_Character__FroglockCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FroglockCanWorship(unsigned char, unsigned char), EQ_Character__FroglockCanWorship);
#endif
#ifdef EQ_Character__CityCanStart_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CityCanStart(int, int, int, int), EQ_Character__CityCanStart);
#endif
#ifdef EQ_Character__BaseAttr_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::BaseAttr(int, unsigned char), EQ_Character__BaseAttr);
#endif
#ifdef EQ_Character__InitSkills_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitSkills(unsigned char, unsigned int), EQ_Character__InitSkills);
#endif
#ifdef EQ_Character__InitInnates_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitInnates(unsigned int, unsigned int), EQ_Character__InitInnates);
#endif
#ifdef EQ_Character__IsSpecialBazaarSpot_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsSpecialBazaarSpot(EQPlayer*), EQ_Character__IsSpecialBazaarSpot);
#endif
#ifdef EQ_Character__CanSecondaryAttack_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanSecondaryAttack(EQPlayer*), EQ_Character__CanSecondaryAttack);
#endif
#ifdef EQ_Character__CanDoubleAttack_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanDoubleAttack(EQPlayer*, unsigned char), EQ_Character__CanDoubleAttack);
#endif
#ifdef EQ_Character__AntiTwinkAdj_x
FUNCTION_AT_ADDRESS(int EQ_Character::AntiTwinkAdj(EQ_Equipment*, int, int), EQ_Character__AntiTwinkAdj);
#endif
#ifdef EQ_Character__GetSkillBaseDamage_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::GetSkillBaseDamage(unsigned char, EQPlayer*), EQ_Character__GetSkillBaseDamage);
#endif
#ifdef EQ_Character__UseSkill_x
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(void EQ_Character1::UseSkill(unsigned char skill, PlayerZoneClient* target), EQ_Character__UseSkill);
#else
FUNCTION_AT_ADDRESS(void EQ_Character1::UseSkill(unsigned char skill, PlayerZoneClient* Target, bool bAuto), EQ_Character__UseSkill);
#endif
#endif
#ifdef EQ_Character__DoIntimidationEvent_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoIntimidationEvent(), EQ_Character__DoIntimidationEvent);
#endif
#ifdef EQ_Character__DoFishingEvent_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoFishingEvent(), EQ_Character__DoFishingEvent);
#endif
#ifdef EQ_Character__FindClosest_x
FUNCTION_AT_ADDRESS(EQPlayer* EQ_Character::FindClosest(int, int, int, int, int), EQ_Character__FindClosest);
#endif
#ifdef EQ_Character__IAmDead_x
FUNCTION_AT_ADDRESS(void EQ_Character::IAmDead(struct _EQMissileHitinfo*, int), EQ_Character__IAmDead);
#endif
#ifdef EQ_Character__TotalOnPerson_x
FUNCTION_AT_ADDRESS(long EQ_Character::TotalOnPerson(), EQ_Character__TotalOnPerson);
#endif
#ifdef EQ_Character__ItemSold_x
FUNCTION_AT_ADDRESS(void EQ_Character::ItemSold(long), EQ_Character__ItemSold);
#endif
#ifdef EQ_Character__TakeFallDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::TakeFallDamage(float), EQ_Character__TakeFallDamage);
#endif
#ifdef EQ_Character__IHaveSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::IHaveSkill(unsigned char), EQ_Character__IHaveSkill);
#endif
#ifdef EQ_Character__NoMezMe_x
FUNCTION_AT_ADDRESS(int EQ_Character::NoMezMe(int, EQPlayer*, EQ_Spell*), EQ_Character__NoMezMe);
#endif
#ifdef EQ_Character__NoBashMe_x
FUNCTION_AT_ADDRESS(int EQ_Character::NoBashMe(int), EQ_Character__NoBashMe);
#endif
#ifdef EQ_Character__StunMe_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StunMe(unsigned int, bool, bool, bool), EQ_Character__StunMe);
#endif
#ifdef EQ_Character__UnStunMe_x
FUNCTION_AT_ADDRESS(void EQ_Character1::UnStunMe(), EQ_Character__UnStunMe);
#endif
#ifdef EQ_Character__ApplyDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::ApplyDamage(int, struct _EQMissileHitinfo*, bool, HateListEntry*, bool), EQ_Character__ApplyDamage);
#endif
#ifdef EQ_Character__NotifyPCAffectChange_x
FUNCTION_AT_ADDRESS(void EQ_Character::NotifyPCAffectChange(int, int), EQ_Character__NotifyPCAffectChange);
#endif
#ifdef EQ_Character__UpdateMyVisibleStatus_x
FUNCTION_AT_ADDRESS(void EQ_Character::UpdateMyVisibleStatus(), EQ_Character__UpdateMyVisibleStatus);
#endif
#ifdef EQ_Character__CanISeeInvis_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanISeeInvis(), EQ_Character__CanISeeInvis);
#endif
#ifdef EQ_Character__CanIBreathe_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanIBreathe(), EQ_Character__CanIBreathe);
#endif
#ifdef EQ_Character__ProcessEnvironment_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessEnvironment(), EQ_Character__ProcessEnvironment);
#endif
#ifdef EQ_Character__ProcessHungerandThirst_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessHungerandThirst(unsigned int), EQ_Character__ProcessHungerandThirst);
#endif
#ifdef EQ_Character__ItemSpellAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::ItemSpellAffects(int), EQ_Character__ItemSpellAffects);
#endif
#ifdef EQ_Character__ProcessAllStats_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessAllStats(), EQ_Character__ProcessAllStats);
#endif
#ifdef EQ_Character__DoPassageOfTime_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoPassageOfTime(), EQ_Character__DoPassageOfTime);
#endif
#ifdef EQ_Character__FindItemByClass_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FindItemByClass(int, int*, int*), EQ_Character__FindItemByClass);
#endif
#ifdef CharacterZoneClient__FindItemByGuid_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot), CharacterZoneClient__FindItemByGuid);
#endif
#ifdef CharacterZoneClient__FindItemByRecord_x
FUNCTION_AT_ADDRESS(BYTE CharacterZoneClient::FindItemByRecord(int ItemNumber /*recordnum*/, int* pos_slot, int* con_slot, bool bReverseLookup), CharacterZoneClient__FindItemByRecord);
#endif
#ifdef EQ_Character__FindItemQty_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FindItemQty(int, int), EQ_Character__FindItemQty);
#endif
#ifdef EQ_Character__CanMedOnHorse_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanMedOnHorse(), EQ_Character__CanMedOnHorse);
#endif
#ifdef EQ_Character__ExpendItemCharge_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ExpendItemCharge(int, int), EQ_Character__ExpendItemCharge);
#endif
#ifdef EQ_Character__AutoEat_x
FUNCTION_AT_ADDRESS(int EQ_Character::AutoEat(unsigned char), EQ_Character__AutoEat);
#endif
#ifdef EQ_Character__CheckFoodAndWater_x
FUNCTION_AT_ADDRESS(int EQ_Character::CheckFoodAndWater(), EQ_Character__CheckFoodAndWater);
#endif
#ifdef EQ_Character__DoMeditation_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoMeditation(), EQ_Character__DoMeditation);
#endif
#ifdef EQ_Character__SetLocalVar_x
FUNCTION_AT_ADDRESS(int EQ_Character::SetLocalVar(char*, int), EQ_Character__SetLocalVar);
#endif
#ifdef EQ_Character__GetIndexSkillMinDamageMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetIndexSkillMinDamageMod(int), EQ_Character__GetIndexSkillMinDamageMod);
#endif
#ifdef EQ_Character__GetFocusConserveRegChance_x
FUNCTION_AT_ADDRESS(int const EQ_Character::GetFocusConserveRegChance(EQ_Spell const*, EQ_Equipment**), EQ_Character__GetFocusConserveRegChance);
#endif
#ifdef EQ_Character__GetFocusCastingTimeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetFocusCastingTimeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut, bool bEvalOnly), EQ_Character__GetFocusCastingTimeModifier);
#endif
#ifdef EQ_Character__GetFocusRangeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut), EQ_Character__GetFocusRangeModifier);
#endif
#ifdef EQ_Character__IsExpansionFlag_x
FUNCTION_AT_ADDRESS(int EQ_Character1::IsExpansionFlag(int), EQ_Character__IsExpansionFlag);
#endif
#ifdef EQ_Character__GetFocusItem_x
FUNCTION_AT_ADDRESS(EQ_Equipment* EQ_Character::GetFocusItem(EQ_Spell const*, int), EQ_Character__GetFocusItem);
#endif
#ifdef EQ_Character__GetFocusEffect_x
FUNCTION_AT_ADDRESS(EQ_Spell* EQ_Character::GetFocusEffect(EQ_Spell const*, int), EQ_Character__GetFocusEffect);
#endif
#ifdef EQ_Character__DoesSpellMatchFocusFilters_x
FUNCTION_AT_ADDRESS(bool EQ_Character::DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*), EQ_Character__DoesSpellMatchFocusFilters);
#endif
#ifdef EQ_Character__GetMyPetPlayer_x
FUNCTION_AT_ADDRESS(EQPlayer* EQ_Character::GetMyPetPlayer(), EQ_Character__GetMyPetPlayer);
#endif
#ifdef CharacterZoneClient__GetMaxEffects_x
FUNCTION_AT_ADDRESS(unsigned char CharacterZoneClient::GetMaxEffects() const, CharacterZoneClient__GetMaxEffects);
#endif
#ifdef CharacterZoneClient__GetEffect_x
FUNCTION_AT_ADDRESS(EQ_Affect& CharacterZoneClient::GetEffect(int) const, CharacterZoneClient__GetEffect);
#endif
#ifdef CharacterZoneClient__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetOpenEffectSlot(bool, bool, int), CharacterZoneClient__GetOpenEffectSlot);
#endif
#ifdef CharacterZoneClient__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetFirstEffectSlot(bool, bool), CharacterZoneClient__GetFirstEffectSlot);
#endif
#ifdef CharacterZoneClient__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetLastEffectSlot(bool, bool, bool), CharacterZoneClient__GetLastEffectSlot);
#endif
#ifdef CharacterBase__GetEffectId_x
FUNCTION_AT_ADDRESS(unsigned int CharacterBase::GetEffectId(int), CharacterBase__GetEffectId);
#endif
#ifdef EQ_Character__SetEffectId_x
FUNCTION_AT_ADDRESS(void EQ_Character1::SetEffectId(unsigned char, unsigned int), EQ_Character__SetEffectId);
#endif
#ifdef EQ_Character__CastSpell_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character1::CastSpell(unsigned char gemid, int spellid, EQ_Item** ppItem, CEQItemLocation* ppitemloc, enum ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10), EQ_Character__CastSpell); 
#endif
#ifdef EQ_Character__GetBardInstrumentMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetBardInstrumentMod(int), EQ_Character__GetBardInstrumentMod);
#endif
#ifdef EQ_Character__CalculateBardSongMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::CalculateBardSongMod(int), EQ_Character__CalculateBardSongMod);
#endif
#ifdef EQ_Character__CastingRequirementsMet_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CastingRequirementsMet(int), EQ_Character__CastingRequirementsMet);
#endif
#ifdef EQ_Character__GetCastingTimeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetCastingTimeModifier(const EQ_Spell*), EQ_Character__GetCastingTimeModifier);
#endif
#ifdef CharacterZoneClient__BardCastBard_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::BardCastBard(const EQ_Spell*, signed int) const, CharacterZoneClient__BardCastBard);
#endif
#ifdef EQ_Character__IsValidAffect_x
FUNCTION_AT_ADDRESS(bool EQ_Character::IsValidAffect(int), EQ_Character__IsValidAffect);
#endif
#ifdef EQ_Character__LaunchSpell_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::LaunchSpell(unsigned char, int, EQ_Item**), EQ_Character__LaunchSpell);
#endif
#ifdef EQ_Character__HandleSpecialPCAffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::HandleSpecialPCAffects(int), EQ_Character__HandleSpecialPCAffects);
#endif
#ifdef CharacterZoneClient__CalcAffectChange_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChange(const EQ_Spell* spell, BYTE, BYTE, const EQ_Affect*, int, PlayerZoneClient*, bool, int, bool), CharacterZoneClient__CalcAffectChange);
#endif
#ifdef CharacterZoneClient__CalcAffectChangeGeneric_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE, BYTE, const EQ_Affect*, int, bool), CharacterZoneClient__CalcAffectChangeGeneric);
#endif
#ifdef CharacterZoneClient__GetFocusReuseMod_x
FUNCTION_AT_ADDRESS(const int CharacterZoneClient::GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem), CharacterZoneClient__GetFocusReuseMod);
#endif
#ifdef EQ_Character__GetPCSpellAffect_x
FUNCTION_AT_ADDRESS(EQ_Affect* EQ_Character::GetPCSpellAffect(int theaffect, int* slotnum, int* spaslot) const, EQ_Character__GetPCSpellAffect);
#endif
#ifdef EQ_Character__TotalSpellAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::TotalSpellAffects(unsigned char, bool, int*), EQ_Character__TotalSpellAffects);
#endif
#ifdef EQ_Character__IsSpellAffectingPC_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::IsSpellAffectingPC(int, int), EQ_Character__IsSpellAffectingPC);
#endif
#ifdef EQ_Character__SpellFizzled_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::SpellFizzled(unsigned char, EQ_Spell*), EQ_Character__SpellFizzled);
#endif
#ifdef EQ_Character__ProcessAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::ProcessAffects(), EQ_Character__ProcessAffects);
#endif
#ifdef CharacterZoneClient__FindAffectSlot_x
FUNCTION_AT_ADDRESS(EQ_Affect* CharacterZoneClient::FindAffectSlot(int, PSPAWNINFO, int*, bool, int, EQ_Affect*, int, bool), CharacterZoneClient__FindAffectSlot);
#endif
#ifdef EQ_Character__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetOpenEffectSlot(bool, int), EQ_Character__GetOpenEffectSlot);
#endif
#ifdef EQ_Character__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetFirstEffectSlot(bool), EQ_Character__GetFirstEffectSlot);
#endif
#ifdef EQ_Character__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetLastEffectSlot(bool), EQ_Character__GetLastEffectSlot);
#endif
#ifdef CharacterZoneClient__IsStackBlocked_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::IsStackBlocked(const EQ_Spell*, PSPAWNINFO, EQ_Affect*, int, bool), CharacterZoneClient__IsStackBlocked);
#else
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::IsStackBlocked(const EQ_Spell*, PSPAWNINFO, EQ_Affect*, int), CharacterZoneClient__IsStackBlocked);
#endif
#endif
#ifdef CharacterZoneClient__CanUseMemorizedSpellSlot_x
FUNCTION_AT_ADDRESS(bool EQ_Character::CanUseMemorizedSpellSlot(int), CharacterZoneClient__CanUseMemorizedSpellSlot);
#endif
#ifdef EQ_Character__IsSpellTooPowerfull_x
FUNCTION_AT_ADDRESS(bool EQ_Character::IsSpellTooPowerfull(EQ_Spell*, EQ_Character*), EQ_Character__IsSpellTooPowerfull);
#endif
#ifdef EQ_Character__HitBySpell_x
FUNCTION_AT_ADDRESS(void EQ_Character::HitBySpell(struct _EQMissileHitinfo*), EQ_Character__HitBySpell);
#endif
#ifdef EQ_Spell__IsStackableDot_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsStackableDot() const, EQ_Spell__IsStackableDot);
#endif
#ifdef EQ_Spell__IsStackable_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsStackable() const, EQ_Spell__IsStackable);
#endif
#ifdef EQ_Spell__GetSpellAffectBySlot_x
FUNCTION_AT_ADDRESS(const SPELLCALCINFO* EQ_Spell::GetSpellAffectBySlot(int) const, EQ_Spell__GetSpellAffectBySlot);
#endif
#ifdef EQ_Spell__GetSpellAffectByIndex_x
FUNCTION_AT_ADDRESS(const SPELLCALCINFO* EQ_Spell::GetSpellAffectByIndex(int) const, EQ_Spell__GetSpellAffectByIndex);
#endif
#ifdef EQ_Spell__IsSPAStacking_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsSPAStacking(int) , EQ_Spell__IsSPAStacking);
#endif
#ifdef EQ_Spell__IsSPAIgnoredByStacking_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsSPAIgnoredByStacking(int) , EQ_Spell__IsSPAIgnoredByStacking);
#endif
#ifdef EQ_Spell__IsNoRemove_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsNoRemove() const, EQ_Spell__IsNoRemove);
#endif
#ifdef EQ_Spell__IsDegeneratingLevelMod_x
FUNCTION_AT_ADDRESS(bool EQ_Spell::IsDegeneratingLevelMod(int) , EQ_Spell__IsDegeneratingLevelMod);
#endif
#ifdef EQ_Character__EQSPA_Feign_Death_x
FUNCTION_AT_ADDRESS(void EQ_Character::EQSPA_Feign_Death(int), EQ_Character__EQSPA_Feign_Death);
#endif
#ifdef EQ_Character__SpellDuration_x
FUNCTION_AT_ADDRESS(int EQ_Character::SpellDuration(EQ_Spell const*, unsigned char, unsigned char), EQ_Character__SpellDuration);
#endif
#ifdef EQ_Character__eqspa_change_form_x
FUNCTION_AT_ADDRESS(int EQ_Character::eqspa_change_form(EQ_Spell*, int, int, EQ_Affect*), EQ_Character__eqspa_change_form);
#endif
#ifdef EQ_Character__eqspa_movement_rate_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_movement_rate(int), EQ_Character__eqspa_movement_rate);
#endif
#ifdef EQ_Character__eqspa_levitation_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_levitation(), EQ_Character__eqspa_levitation);
#endif
#ifdef EQ_Character__eqspa_hp_x
FUNCTION_AT_ADDRESS(int EQ_Character::eqspa_hp(unsigned int, EQ_Affect*, int, EQ_Spell*), EQ_Character__eqspa_hp);
#endif
#ifdef EQ_Character__eqspa_locate_corpse_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_locate_corpse(), EQ_Character__eqspa_locate_corpse);
#endif
#ifdef EQ_Character__InSpecialBindSpot_x
FUNCTION_AT_ADDRESS(int EQ_Character::InSpecialBindSpot(EQPlayer*), EQ_Character__InSpecialBindSpot);
#endif
#ifdef EQ_Character__RemovePCAffect_x
FUNCTION_AT_ADDRESS(void EQ_Character::RemovePCAffect(EQ_Affect*), EQ_Character__RemovePCAffect);
#endif
#ifdef EQ_Character__RemovePCAffectex_x
FUNCTION_AT_ADDRESS(void EQ_Character::RemovePCAffectex(EQ_Affect*, int), EQ_Character__RemovePCAffectex);
#endif
#ifdef EQ_Character__StopSpellCast_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StopSpellCast(unsigned char), EQ_Character__StopSpellCast);
#endif
#ifdef EQ_Character__StopSpellCast1_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StopSpellCast(unsigned char, int), EQ_Character__StopSpellCast1);
#endif
#ifdef EQ_Character__ReCachSpellEffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::ReCachSpellEffects(), EQ_Character__ReCachSpellEffects);
#endif
#ifdef EQ_Character__ReCachItemEffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::ReCachItemEffects(), EQ_Character__ReCachItemEffects);
#endif
#ifdef EQ_Character__GetCachEQSPA_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetCachEQSPA(int), EQ_Character__GetCachEQSPA);
#endif
#ifdef EQ_Character__GetConLevel_x
FUNCTION_AT_ADDRESS(unsigned long EQ_Character::GetConLevel(const PlayerClient*), EQ_Character__GetConLevel);
#endif
#ifdef EQ_Character__TotalEffect_x
FUNCTION_AT_ADDRESS(int EQ_Character1::TotalEffect(int, bool, int, bool, bool), EQ_Character__TotalEffect);
#endif
#ifdef EQ_Character__GetAdjustedSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetAdjustedSkill(int), EQ_Character__GetAdjustedSkill);
#endif
#ifdef EQ_Character__GetBaseSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetBaseSkill(int), EQ_Character__GetBaseSkill);
#endif
#ifdef EQ_Container__EQ_Container_x
FUNCTION_AT_ADDRESS(EQ_Container::EQ_Container(), EQ_Container__EQ_Container);
#endif
#ifdef EQ_Container__dEQ_Container_x
FUNCTION_AT_ADDRESS(EQ_Container::~EQ_Container(), EQ_Container__dEQ_Container);
#endif
#ifdef EQ_Container__Open_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Container::Open(), EQ_Container__Open);
#endif
#ifdef EQ_Container__Close_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Container::Close(), EQ_Container__Close);
#endif
#ifdef EQ_Container__IsOpen_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Container::IsOpen(), EQ_Container__IsOpen);
#endif
#ifdef EQ_Equipment__EQ_Equipment_x
FUNCTION_AT_ADDRESS(EQ_Equipment::EQ_Equipment(), EQ_Equipment__EQ_Equipment);
#endif
#ifdef EQ_Equipment__IsWeapon_x
FUNCTION_AT_ADDRESS(int EQ_Equipment::IsWeapon(), EQ_Equipment__IsWeapon);
#endif
#ifdef EQ_Equipment__IsInstrument_x
FUNCTION_AT_ADDRESS(int EQ_Equipment::IsInstrument(), EQ_Equipment__IsInstrument);
#endif
#ifdef EQ_Equipment__SendTextRequestMsg_x
FUNCTION_AT_ADDRESS(void EQ_Equipment::SendTextRequestMsg(), EQ_Equipment__SendTextRequestMsg);
#endif
#ifdef EQ_Item__Platinum_x
FUNCTION_AT_ADDRESS(int EQ_Item::Platinum(), EQ_Item__Platinum);
#endif
#ifdef EQ_Item__Gold_x
FUNCTION_AT_ADDRESS(int EQ_Item::Gold(), EQ_Item__Gold);
#endif
#ifdef EQ_Item__Silver_x
FUNCTION_AT_ADDRESS(int EQ_Item::Silver(), EQ_Item__Silver);
#endif
#ifdef EQ_Item__Copper_x
FUNCTION_AT_ADDRESS(int EQ_Item::Copper(), EQ_Item__Copper);
#endif
#ifdef EQ_Item__GetItemValue_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetItemValue(bool) const, EQ_Item__GetItemValue); 
#endif
#ifdef EQ_Item__IsKeyRingItem_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsKeyRingItem(KeyRingType) const, EQ_Item__IsKeyRingItem); 
#endif
#ifdef EQ_Item__CanGoInBag_x
FUNCTION_AT_ADDRESS(bool EQ_Item::CanGoInBag(PCONTENTS* pCont, int unused, bool mustbefalse) const, EQ_Item__CanGoInBag); 
#endif
#ifdef EQ_Item__IsEmpty_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsEmpty() const, EQ_Item__IsEmpty); 
#endif
#ifdef EQ_Item__ValueSellMerchant_x
FUNCTION_AT_ADDRESS(long EQ_Item::ValueSellMerchant(float, long) const, EQ_Item__ValueSellMerchant);
#endif
#ifdef EQ_Item__GetAugmentFitBySlot_x
FUNCTION_AT_ADDRESS(int EQ_Item::GetAugmentFitBySlot(PCONTENTS*, int, bool, bool index) const, EQ_Item__GetAugmentFitBySlot); 
#endif
#ifdef EQ_Item__ValueSSell_x
FUNCTION_AT_ADDRESS(char* EQ_Item::ValueSSell(float, long), EQ_Item__ValueSSell);
#endif
#ifdef EQ_Item__ValueSBuy_x
FUNCTION_AT_ADDRESS(char* EQ_Item::ValueSBuy(float, long), EQ_Item__ValueSBuy);
#endif
#ifdef EQ_Item__ValueSRent_x
FUNCTION_AT_ADDRESS(char* EQ_Item::ValueSRent(), EQ_Item__ValueSRent);
#endif
#ifdef EQ_Item__IsSpecialNoDrop_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsSpecialNoDrop(), EQ_Item__IsSpecialNoDrop);
#endif
#ifdef EQ_Item__IsStackable_x
FUNCTION_AT_ADDRESS(bool EQ_Item::IsStackable(), EQ_Item__IsStackable); 
#endif 
#ifdef EQ_LoadingS__EQ_LoadingS_x
FUNCTION_AT_ADDRESS(EQ_LoadingS::EQ_LoadingS(), EQ_LoadingS__EQ_LoadingS);
#endif
#ifdef EQ_LoadingS__dEQ_LoadingS_x
FUNCTION_AT_ADDRESS(EQ_LoadingS::~EQ_LoadingS(), EQ_LoadingS__dEQ_LoadingS);
#endif
#ifdef EQ_LoadingS__DrawBackground_x
FUNCTION_AT_ADDRESS(void EQ_LoadingS::DrawBackground(), EQ_LoadingS__DrawBackground);
#endif
#ifdef EQ_LoadingS__draw_x
FUNCTION_AT_ADDRESS(void EQ_LoadingS::draw(), EQ_LoadingS__draw);
#endif
#ifdef EQ_LoadingS__WriteTextHD_x
FUNCTION_AT_ADDRESS(void EQ_LoadingS::WriteTextHD(char*, int, int, int), EQ_LoadingS__WriteTextHD);
#endif
#ifdef EQ_LoadingS__SetProgressBar_x
FUNCTION_AT_ADDRESS(void EQ_LoadingS::SetProgressBar(int, const char*), EQ_LoadingS__SetProgressBar);
#endif
#ifdef EQ_Note__EQ_Note_x
FUNCTION_AT_ADDRESS(EQ_Note::EQ_Note(), EQ_Note__EQ_Note);
#endif
#ifdef EQ_Note__SendTextRequestMsg_x
FUNCTION_AT_ADDRESS(void EQ_Note::SendTextRequestMsg(), EQ_Note__SendTextRequestMsg);
#endif
#ifdef EQ_PC__EQ_PC_x
FUNCTION_AT_ADDRESS(EQ_PC::EQ_PC(EQ_PC*), EQ_PC__EQ_PC);
#endif
#ifdef EQ_PC__dEQ_PC_x
FUNCTION_AT_ADDRESS(EQ_PC::~EQ_PC(), EQ_PC__dEQ_PC);
#endif
#ifdef EQ_PC__ClearSharedVault_x
FUNCTION_AT_ADDRESS(void EQ_PC::ClearSharedVault(), EQ_PC__ClearSharedVault);
#endif
#ifdef EQ_PC__IsAGroupMember_x
FUNCTION_AT_ADDRESS(int EQ_PC::IsAGroupMember(char*), EQ_PC__IsAGroupMember);
#endif
#ifdef EQ_PC__CheckForGroupChanges_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckForGroupChanges(), EQ_PC__CheckForGroupChanges);
#endif
#ifdef EQ_PC__UnpackMyNetPC_x
FUNCTION_AT_ADDRESS(void EQ_PC::UnpackMyNetPC(char*, int), EQ_PC__UnpackMyNetPC);
#endif
#ifdef EQ_PC__AlertInventoryChanged_x
FUNCTION_AT_ADDRESS(void EQ_PC::AlertInventoryChanged(), EQ_PC__AlertInventoryChanged);
#endif
#ifdef EQ_PC__InitPlayerStart_x
FUNCTION_AT_ADDRESS(void EQ_PC::InitPlayerStart(unsigned int, unsigned char, int), EQ_PC__InitPlayerStart);
#endif
#ifdef EQ_PC__EmptyPossessionSlots_x
FUNCTION_AT_ADDRESS(void EQ_PC::EmptyPossessionSlots(), EQ_PC__EmptyPossessionSlots);
#endif
#ifdef EQ_PC__RefreshMe_x
FUNCTION_AT_ADDRESS(void EQ_PC::RefreshMe(int), EQ_PC__RefreshMe);
#endif
#ifdef EQ_PC__PrepareForRepop_x
FUNCTION_AT_ADDRESS(void EQ_PC::PrepareForRepop(int), EQ_PC__PrepareForRepop);
#endif
#ifdef EQ_PC__RefitNewbieEQ_x
FUNCTION_AT_ADDRESS(void EQ_PC::RefitNewbieEQ(), EQ_PC__RefitNewbieEQ);
#endif
#ifdef EQ_PC__RemoveMyAffect_x
FUNCTION_AT_ADDRESS(unsigned char EQ_PC::RemoveMyAffect(int), EQ_PC__RemoveMyAffect);
#endif
#ifdef EQ_PC__ProcessFatigue_x
FUNCTION_AT_ADDRESS(void EQ_PC::ProcessFatigue(), EQ_PC__ProcessFatigue);
#endif
#ifdef EQ_PC__DelLoreItemDup_x
FUNCTION_AT_ADDRESS(int EQ_PC::DelLoreItemDup(int, int, int, EQ_Item*), EQ_PC__DelLoreItemDup);
#endif
#ifdef EQ_PC__CheckDupLoreItems_x
FUNCTION_AT_ADDRESS(int EQ_PC::CheckDupLoreItems(), EQ_PC__CheckDupLoreItems);
#endif
#ifdef EQ_PC__CostToTrain_x
FUNCTION_AT_ADDRESS(int EQ_PC::CostToTrain(int, float, int), EQ_PC__CostToTrain);
#endif
#ifdef EQ_PC__checkLang_x
FUNCTION_AT_ADDRESS(int EQ_PC::checkLang(int), EQ_PC__checkLang);
#endif
#ifdef EQ_PC__BitchCanTrain_x
FUNCTION_AT_ADDRESS(int EQ_PC::BitchCanTrain(int, int, int), EQ_PC__BitchCanTrain);
#endif
#ifdef EQ_PC__HandleMoney_x
FUNCTION_AT_ADDRESS(int EQ_PC::HandleMoney(long), EQ_PC__HandleMoney);
#endif
#ifdef EQ_PC__DetermineQuestExpGained_x
FUNCTION_AT_ADDRESS(void EQ_PC::DetermineQuestExpGained(int), EQ_PC__DetermineQuestExpGained);
#endif
#ifdef EQ_PC__ProcessAirSupply_x
FUNCTION_AT_ADDRESS(void EQ_PC::ProcessAirSupply(), EQ_PC__ProcessAirSupply);
#endif
#ifdef EQ_PC__MaxAirSupply_x
FUNCTION_AT_ADDRESS(int EQ_PC::MaxAirSupply(), EQ_PC__MaxAirSupply);
#endif
#ifdef EQ_PC__SetFatigue_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetFatigue(int), EQ_PC__SetFatigue);
#endif
#ifdef EQ_PC__numInParty_x
FUNCTION_AT_ADDRESS(int EQ_PC::numInParty(), EQ_PC__numInParty);
#endif
#ifdef EQ_PC__AtSkillLimit_x
FUNCTION_AT_ADDRESS(unsigned char EQ_PC::AtSkillLimit(int), EQ_PC__AtSkillLimit);
#endif
#ifdef EQ_PC__GetItemRecastTimer_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype), EQ_PC__GetItemRecastTimer);
#else
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetItemRecastTimer(EQ_Item* item), EQ_PC__GetItemRecastTimer);
#endif
#endif
#ifdef EQ_PC__GetAlternateAbilityId_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetAlternateAbilityId(int), EQ_PC__GetAlternateAbilityId);
#endif
#ifdef EQ_PC__GetCombatAbility_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetCombatAbility(int), EQ_PC__GetCombatAbility);
#endif
#ifdef EQ_PC__GetPcZoneClient_x
FUNCTION_AT_ADDRESS(PcZoneClient* EQ_PC::GetPcZoneClient() const, EQ_PC__GetPcZoneClient);
#endif
#ifdef EQ_PC__GetCombatAbilityTimer_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetCombatAbilityTimer(int, int), EQ_PC__GetCombatAbilityTimer);
#else
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetCombatAbilityTimer(int), EQ_PC__GetCombatAbilityTimer);
#endif
#endif
#ifdef EQ_PC__HasLoreItem_x
FUNCTION_AT_ADDRESS(bool EQ_PC::HasLoreItem(EQ_Item*, int, int, int, int), EQ_PC__HasLoreItem);
#endif
#ifdef EQ_PC__GetItemContainedRealEstateIds_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate>&, bool, bool, bool), EQ_PC__GetItemContainedRealEstateIds);
#endif
#ifdef EQ_PC__GetNonArchivedOwnedRealEstates_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetNonArchivedOwnedRealEstates(ArrayClass<int>&), EQ_PC__GetNonArchivedOwnedRealEstates);
#endif
#ifdef CInvSlot__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonDown(CXPoint), CInvSlot__HandleLButtonDown);
#endif
#ifdef CInvSlot__HandleLButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleLButtonUpAfterHeld(CXPoint), CInvSlot__HandleLButtonUpAfterHeld);
#endif
#ifdef CInvSlot__HandleRButtonDown_x
FUNCTION_AT_ADDRESS(void CInvSlot::HandleRButtonDown(CXPoint), CInvSlot__HandleRButtonDown);
#endif
#ifdef EQ_PC__CheckForLanguageImprovement_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckForLanguageImprovement(unsigned char, unsigned char), EQ_PC__CheckForLanguageImprovement);
#endif
#ifdef EQ_PC__CheckSkillImprove_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckSkillImprove(int, float), EQ_PC__CheckSkillImprove);
#endif
#ifdef EQ_PC__GetBodyTint_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetBodyTint(int), EQ_PC__GetBodyTint);
#endif
#ifdef EQ_PC__SetAltAbilityIndex_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetAltAbilityIndex(int, int), EQ_PC__SetAltAbilityIndex);
#endif
#ifdef EQ_PC__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetArmorTint(int), EQ_PC__GetArmorTint);
#endif
#ifdef EQ_PC__SetArmorTint_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetArmorTint(int, unsigned long), EQ_PC__SetArmorTint);
#endif
#ifdef EQ_PC__GetArmorType_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetArmorType(int), EQ_PC__GetArmorType);
#endif
#ifdef EQ_PC__SetArmorType_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetArmorType(int, int), EQ_PC__SetArmorType);
#endif
#ifdef EQ_PC__InitializeNewPCVariables_x
FUNCTION_AT_ADDRESS(void EQ_PC::InitializeNewPCVariables(int), EQ_PC__InitializeNewPCVariables);
#endif
#ifdef EQ_PC__DestroyHeldItemOrMoney_x
FUNCTION_AT_ADDRESS(void EQ_PC::DestroyHeldItemOrMoney(), EQ_PC__DestroyHeldItemOrMoney);
#endif
#ifdef ProfileManager__GetCurrentProfile_x
FUNCTION_AT_ADDRESS(BaseProfile* ProfileManager::GetCurrentProfile(), ProfileManager__GetCurrentProfile);
#endif
#ifdef EQ_Skill__EQ_Skill_x
FUNCTION_AT_ADDRESS(EQ_Skill::EQ_Skill(int), EQ_Skill__EQ_Skill);
#endif
#ifdef EqSoundManager__dEqSoundManager_x
FUNCTION_AT_ADDRESS(EqSoundManager::~EqSoundManager(), EqSoundManager__dEqSoundManager);
#endif
#ifdef EqSoundManager__LoadGlobalEmitters_x
FUNCTION_AT_ADDRESS(void EqSoundManager::LoadGlobalEmitters(), EqSoundManager__LoadGlobalEmitters);
#endif
#ifdef EqSoundManager__GetMusicId_x
FUNCTION_AT_ADDRESS(int EqSoundManager::GetMusicId(), EqSoundManager__GetMusicId);
#endif
#ifdef EqSoundManager__LoadGlobalWaves_x
FUNCTION_AT_ADDRESS(void EqSoundManager::LoadGlobalWaves(), EqSoundManager__LoadGlobalWaves);
#endif
#ifdef EqSoundManager__LoadListOfWaveFiles_x
FUNCTION_AT_ADDRESS(void EqSoundManager::LoadListOfWaveFiles(char**, int), EqSoundManager__LoadListOfWaveFiles);
#endif
#ifdef EqSoundManager__WaveLoad_x
FUNCTION_AT_ADDRESS(void EqSoundManager::WaveLoad(char*, int, bool), EqSoundManager__WaveLoad);
#endif
#ifdef EqSoundManager__WaveIsPlaying_x
FUNCTION_AT_ADDRESS(bool EqSoundManager::WaveIsPlaying(int), EqSoundManager__WaveIsPlaying);
#endif
#ifdef EqSoundManager__WavePlay_x
FUNCTION_AT_ADDRESS(void EqSoundManager::WavePlay(int, SoundControl*), EqSoundManager__WavePlay);
#endif
#ifdef EqSoundManager__WaveStop_x
FUNCTION_AT_ADDRESS(void EqSoundManager::WaveStop(int), EqSoundManager__WaveStop);
#endif
#ifdef EqSoundManager__WaveGet_x
FUNCTION_AT_ADDRESS(SoundAsset* EqSoundManager::WaveGet(int), EqSoundManager__WaveGet);
#endif
#ifdef EqSoundManager__LoadGlobalMusic_x
FUNCTION_AT_ADDRESS(void EqSoundManager::LoadGlobalMusic(), EqSoundManager__LoadGlobalMusic);
#endif
#ifdef EqSoundManager__SetMusicSelection_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetMusicSelection(int, bool), EqSoundManager__SetMusicSelection);
#endif
#ifdef EqSoundManager__GiveTime_x
FUNCTION_AT_ADDRESS(void EqSoundManager::GiveTime(), EqSoundManager__GiveTime);
#endif
#ifdef EqSoundManager__SetCurrentZone_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetCurrentZone(char*), EqSoundManager__SetCurrentZone);
#endif
#ifdef EqSoundManager__LoadOldEmitters_x
FUNCTION_AT_ADDRESS(void EqSoundManager::LoadOldEmitters(), EqSoundManager__LoadOldEmitters);
#endif
#ifdef EqSoundManager__GetAsset_x
FUNCTION_AT_ADDRESS(SoundAsset* EqSoundManager::GetAsset(char*), EqSoundManager__GetAsset);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificMidi_x
FUNCTION_AT_ADDRESS(void EqSoundManager::ReleaseZoneSpecificMidi(), EqSoundManager__ReleaseZoneSpecificMidi);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificWaves_x
FUNCTION_AT_ADDRESS(void EqSoundManager::ReleaseZoneSpecificWaves(), EqSoundManager__ReleaseZoneSpecificWaves);
#endif
#ifdef EqSoundManager__ReleaseZoneSpecificEmitters_x
FUNCTION_AT_ADDRESS(void EqSoundManager::ReleaseZoneSpecificEmitters(), EqSoundManager__ReleaseZoneSpecificEmitters);
#endif
#ifdef EqSoundManager__SetEffectsLevel_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetEffectsLevel(float), EqSoundManager__SetEffectsLevel);
#endif
#ifdef EqSoundManager__SetMixAhead_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetMixAhead(int), EqSoundManager__SetMixAhead);
#endif
#ifdef EqSoundManager__SetWaveVolume_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetWaveVolume(float), EqSoundManager__SetWaveVolume);
#endif
#ifdef EqSoundManager__SetMusicVolume_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetMusicVolume(float), EqSoundManager__SetMusicVolume);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentLow_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetListenerEnvironmentLow(), EqSoundManager__SetListenerEnvironmentLow);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentHigh_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetListenerEnvironmentHigh(), EqSoundManager__SetListenerEnvironmentHigh);
#endif
#ifdef EqSoundManager__SetListenerEnvironmentOutside_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetListenerEnvironmentOutside(), EqSoundManager__SetListenerEnvironmentOutside);
#endif
#ifdef EqSoundManager__SetListenerLocation_x
FUNCTION_AT_ADDRESS(void EqSoundManager::SetListenerLocation(float, float, float, float), EqSoundManager__SetListenerLocation);
#endif
#ifdef EqSoundManager__EmitterSetRaining_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterSetRaining(bool), EqSoundManager__EmitterSetRaining);
#endif
#ifdef EqSoundManager__EmitterSetWind_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterSetWind(bool), EqSoundManager__EmitterSetWind);
#endif
#ifdef EqSoundManager__EmitterSetNight_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterSetNight(bool), EqSoundManager__EmitterSetNight);
#endif
#ifdef EqSoundManager__EmitterSetUserDisabled_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterSetUserDisabled(bool), EqSoundManager__EmitterSetUserDisabled);
#endif
#ifdef EqSoundManager__EmitterSetIndoors_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterSetIndoors(bool), EqSoundManager__EmitterSetIndoors);
#endif
#ifdef EqSoundManager__UpdateEmitterStates_x
FUNCTION_AT_ADDRESS(void EqSoundManager::UpdateEmitterStates(), EqSoundManager__UpdateEmitterStates);
#endif
#ifdef EqSoundManager__OldMp3ClearSelections_x
FUNCTION_AT_ADDRESS(void EqSoundManager::OldMp3ClearSelections(), EqSoundManager__OldMp3ClearSelections);
#endif
#ifdef EqSoundManager__OldMp3Init_x
FUNCTION_AT_ADDRESS(void EqSoundManager::OldMp3Init(), EqSoundManager__OldMp3Init);
#endif
#ifdef EqSoundManager__OldMp3Terminate_x
FUNCTION_AT_ADDRESS(void EqSoundManager::OldMp3Terminate(), EqSoundManager__OldMp3Terminate);
#endif
#ifdef EqSoundManager__OldMp3GetSelection_x
FUNCTION_AT_ADDRESS(SoundAsset* EqSoundManager::OldMp3GetSelection(int), EqSoundManager__OldMp3GetSelection);
#endif
#ifdef EqSoundManager__PlayScriptMp3_x
FUNCTION_AT_ADDRESS(void EqSoundManager::PlayScriptMp3(char* Name, float Vol), EqSoundManager__PlayScriptMp3);
#endif
#ifdef EqSoundManager__EmitterLoad_x
FUNCTION_AT_ADDRESS(bool EqSoundManager::EmitterLoad(char*), EqSoundManager__EmitterLoad);
#endif
#ifdef EqSoundManager__EmitterAdd_x
FUNCTION_AT_ADDRESS(void EqSoundManager::EmitterAdd(EqEmitterData*), EqSoundManager__EmitterAdd);
#endif
#ifdef EqMobileEmitter__EqMobileEmitter_x
FUNCTION_AT_ADDRESS(EqMobileEmitter::EqMobileEmitter(EqSoundManager*), EqMobileEmitter__EqMobileEmitter);
#endif
#ifdef EqMobileEmitter__dEqMobileEmitter_x
FUNCTION_AT_ADDRESS(EqMobileEmitter::~EqMobileEmitter(), EqMobileEmitter__dEqMobileEmitter);
#endif
#ifdef EqMobileEmitter__Move_x
FUNCTION_AT_ADDRESS(void EqMobileEmitter::Move(float, float, float), EqMobileEmitter__Move);
#endif
#ifdef EqMobileEmitter__SetWave_x
FUNCTION_AT_ADDRESS(void EqMobileEmitter::SetWave(int, char*), EqMobileEmitter__SetWave);
#endif
#ifdef EqMobileEmitter__SetNpcHeight_x
FUNCTION_AT_ADDRESS(void EqMobileEmitter::SetNpcHeight(float), EqMobileEmitter__SetNpcHeight);
#endif
#ifdef EqEmitterData__EqEmitterData_x
FUNCTION_AT_ADDRESS(EqEmitterData::EqEmitterData(), EqEmitterData__EqEmitterData);
#endif
#ifdef EqEmitterData__SetLoadString_x
FUNCTION_AT_ADDRESS(void EqEmitterData::SetLoadString(char*), EqEmitterData__SetLoadString);
#endif
#ifdef EQ_Spell__SpellUsesDragonBreathEffect_x
FUNCTION_AT_ADDRESS(int EQ_Spell::SpellUsesDragonBreathEffect(), EQ_Spell__SpellUsesDragonBreathEffect);
#endif
#ifdef EQ_Spell__EQ_Spell_x
FUNCTION_AT_ADDRESS(EQ_Spell::EQ_Spell(char*), EQ_Spell__EQ_Spell);
#endif
#ifdef EQ_Spell__dEQ_Spell_x
FUNCTION_AT_ADDRESS(EQ_Spell::~EQ_Spell(), EQ_Spell__dEQ_Spell);
#endif
#ifdef EQ_Spell__SpellAffects_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Spell::SpellAffects(int) const, EQ_Spell__SpellAffects);
#endif
#ifdef EQ_Spell__IsPermIllusionSpell_x
FUNCTION_AT_ADDRESS(int EQ_Spell::IsPermIllusionSpell() const, EQ_Spell__IsPermIllusionSpell);
#endif
#ifdef EQ_Spell__GetSpellLevelNeeded_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Spell::GetSpellLevelNeeded(int) const, EQ_Spell__GetSpellLevelNeeded);
#endif
#ifdef EQ_Spell__SpellAffectBase_x
FUNCTION_AT_ADDRESS(int EQ_Spell::SpellAffectBase(int) const, EQ_Spell__SpellAffectBase);
#endif
#ifdef EQAnimation__EQAnimation_x
FUNCTION_AT_ADDRESS(EQAnimation::EQAnimation(), EQAnimation__EQAnimation);
#endif
#ifdef EQPlayer__DoCamAi_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoCamAi(), EQPlayer__DoCamAi);
#endif
#ifdef CVector3__Normalize_x
FUNCTION_AT_ADDRESS(void CVector3::Normalize(), CVector3__Normalize);
#endif
#ifdef CVector3__GetLength_x
FUNCTION_AT_ADDRESS(float CVector3::GetLength() const, CVector3__GetLength);
#endif
#ifdef CVector3__NormalizeAndReturnLength_x
FUNCTION_AT_ADDRESS(float CVector3::NormalizeAndReturnLength(), CVector3__NormalizeAndReturnLength);
#endif
#ifdef EQEffect__EQEffect_x
FUNCTION_AT_ADDRESS(EQEffect::EQEffect(EQEffect*, char*, int, EQLOC*, PlayerZoneClient*, EQMissile*, EQRGB*, float, int, int, float, float), EQEffect__EQEffect);
#endif
#ifdef EQEffect__dEQEffect_x
FUNCTION_AT_ADDRESS(EQEffect::~EQEffect(), EQEffect__dEQEffect);
#endif
#ifdef CEverQuest__msgStartIcon_x
FUNCTION_AT_ADDRESS(int CEverQuest::msgStartIcon(void*), CEverQuest__msgStartIcon);
#endif
#ifdef CEverQuest__msgStartInotes_x
FUNCTION_AT_ADDRESS(int CEverQuest::msgStartInotes(void*), CEverQuest__msgStartInotes);
#endif
#ifdef CEverQuest__msgStartIeq_x
FUNCTION_AT_ADDRESS(int CEverQuest::msgStartIeq(void*), CEverQuest__msgStartIeq);
#endif
#ifdef CEverQuest__HandleItems_x
FUNCTION_AT_ADDRESS(int CEverQuest::HandleItems(void*, int), CEverQuest__HandleItems);
#endif
#ifdef CEverQuest__HandleWorldMessage_x
FUNCTION_AT_ADDRESS(unsigned char CEverQuest::HandleWorldMessage(struct connection_t*, uint32_t, char*, uint32_t), CEverQuest__HandleWorldMessage);
#endif
#ifdef EQItemList__EQItemList_x
FUNCTION_AT_ADDRESS(EQItemList::EQItemList(), EQItemList__EQItemList);
#endif
#ifdef EQItemList__dEQItemList_x
FUNCTION_AT_ADDRESS(EQItemList::~EQItemList(), EQItemList__dEQItemList);
#endif
#ifdef EQItemList__get_item_x
FUNCTION_AT_ADDRESS(EQItemList* EQItemList::get_item(long), EQItemList__get_item);
#endif
#ifdef EQItemList__is_item_actor_x
FUNCTION_AT_ADDRESS(EQItemList* EQItemList::is_item_actor(struct T3D_tagACTORINSTANCE*), EQItemList__is_item_actor);
#endif
#ifdef EQMissile__EQMissile_x
FUNCTION_AT_ADDRESS(EQMissile::EQMissile(EQ_Equipment*, PlayerZoneClient*, EQMissile*, char*, unsigned char, unsigned int), EQMissile__EQMissile);
#endif
#ifdef EQMissile__dEQMissile_x
FUNCTION_AT_ADDRESS(EQMissile::~EQMissile(), EQMissile__dEQMissile);
#endif
#ifdef EQMissile__CleanUpMyEffects_x
FUNCTION_AT_ADDRESS(void EQMissile::CleanUpMyEffects(), EQMissile__CleanUpMyEffects);
#endif
#ifdef EQMissile__is_missile_actor_x
FUNCTION_AT_ADDRESS(EQMissile* EQMissile::is_missile_actor(struct T3D_tagACTORINSTANCE*), EQMissile__is_missile_actor);
#endif
#ifdef EQMissile__HitActor_x
FUNCTION_AT_ADDRESS(void EQMissile::HitActor(struct T3D_tagACTORINSTANCE*, bool), EQMissile__HitActor);
#endif
#ifdef EQMissile__ProcessMissile_x
FUNCTION_AT_ADDRESS(void EQMissile::ProcessMissile(), EQMissile__ProcessMissile);
#endif
#ifdef EQMissile__MissileAI_x
FUNCTION_AT_ADDRESS(void EQMissile::MissileAI(), EQMissile__MissileAI);
#endif
#ifdef EQMoneyList__EQMoneyList_x
FUNCTION_AT_ADDRESS(EQMoneyList::EQMoneyList(), EQMoneyList__EQMoneyList);
#endif
#ifdef EQMoneyList__dEQMoneyList_x
FUNCTION_AT_ADDRESS(EQMoneyList::~EQMoneyList(), EQMoneyList__dEQMoneyList);
#endif
#ifdef EQMoneyList__get_money_x
FUNCTION_AT_ADDRESS(EQMoneyList* EQMoneyList::get_money(long), EQMoneyList__get_money);
#endif
#ifdef CDisplay__MoveMissile_x
FUNCTION_AT_ADDRESS(int CDisplay::MoveMissile(EQMissile*), CDisplay__MoveMissile);
#endif
#ifdef CDisplay__GetOnActor_x
FUNCTION_AT_ADDRESS(void CDisplay::GetOnActor(CActorInterface*, PlayerZoneClient*), CDisplay__GetOnActor);
#endif
#ifdef EQPlayer__CanIFitHere_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::CanIFitHere(const CVector3&, bool), EQPlayer__CanIFitHere);
#endif
#ifdef EQPlayer__MovePlayer_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::MovePlayer(), EQPlayer__MovePlayer);
#endif
#ifdef EQObject__EQObject_x
FUNCTION_AT_ADDRESS(EQObject::EQObject(EQObject*, PlayerZoneClient*, char*, char*), EQObject__EQObject);
#endif
#ifdef EQObject__dEQObject_x
FUNCTION_AT_ADDRESS(EQObject::~EQObject(), EQObject__dEQObject);
#endif
#ifdef ChatManagerClient__Instance_x
FUNCTION_AT_ADDRESS(ChatManagerClient& ChatManagerClient::Instance(), ChatManagerClient__Instance);
#endif
#ifdef EQPlacedItemManager__Instance_x
FUNCTION_AT_ADDRESS(EQPlacedItemManager& EQPlacedItemManager::Instance(), EQPlacedItemManager__Instance);
#endif
#ifdef EQPlacedItemManager__GetItemByGuid_x
FUNCTION_AT_ADDRESS(EQPlacedItem* EQPlacedItemManager::GetItemByGuid(const EqItemGuid& ItemGuid), EQPlacedItemManager__GetItemByGuid);
#endif
#ifdef EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x
FUNCTION_AT_ADDRESS(EQPlacedItem* EQPlacedItemManager::GetItemByRealEstateAndRealEstateItemIds(int RealEstateID, int RealEstateItemID), EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds);
#endif
#ifdef RealEstateManagerClient__Instance_x
FUNCTION_AT_ADDRESS(RealEstateManagerClient& RealEstateManagerClient::Instance(), RealEstateManagerClient__Instance)
#endif
#ifdef RealEstateManagerClient__GetItemByRealEstateAndItemIds_x
FUNCTION_AT_ADDRESS(const RealEstateItemClient* RealEstateManagerClient::GetItemByRealEstateAndItemIds(int realEstateID, int realEstateItemID) const, RealEstateManagerClient__GetItemByRealEstateAndItemIds)
#endif
#ifdef FactionManagerClient__Instance_x
FUNCTION_AT_ADDRESS(FactionManagerClient& FactionManagerClient::Instance(), FactionManagerClient__Instance)
#endif
#ifdef FactionManagerClient__HandleFactionMessage_x
FUNCTION_AT_ADDRESS(void FactionManagerClient::HandleFactionMessage(UINT MessageID, PCHAR pData, unsigned int DataLength), FactionManagerClient__HandleFactionMessage)
#endif
#ifdef EQPlayer__EQPlayer_x
FUNCTION_AT_ADDRESS(void PlayerClient::Initialize(PlayerClient*, unsigned char, unsigned int, unsigned char, char*), EQPlayer__EQPlayer);
#endif
#ifdef EQPlayer__dEQPlayer_x
FUNCTION_AT_ADDRESS(PlayerClient::~PlayerClient(), EQPlayer__dEQPlayer);
#endif
#ifdef EQPlayer__ResetVariables_x
FUNCTION_AT_ADDRESS(void EQPlayer::ResetVariables(), EQPlayer__ResetVariables);
#endif
#ifdef EQPlayer__do_change_form_x
FUNCTION_AT_ADDRESS(void EQPlayer::do_change_form(struct chngForm*), EQPlayer__do_change_form);
#endif
#ifdef EQPlayer__DisplayWeaponsAndArmor_x
FUNCTION_AT_ADDRESS(void EQPlayer::DisplayWeaponsAndArmor(), EQPlayer__DisplayWeaponsAndArmor);
#endif
#ifdef EQPlayer__CleanUpTarget_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpTarget(), EQPlayer__CleanUpTarget);
#endif
#ifdef EQPlayer__FollowPlayerAI_x
FUNCTION_AT_ADDRESS(void EQPlayer::FollowPlayerAI(), EQPlayer__FollowPlayerAI);
#endif
#ifdef EQPlayer__TurnOffAutoFollow_x
FUNCTION_AT_ADDRESS(void EQPlayer::TurnOffAutoFollow(), EQPlayer__TurnOffAutoFollow);
#endif
#ifdef EQPlayer__AimAtTarget_x
FUNCTION_AT_ADDRESS(int EQPlayer::AimAtTarget(EQPlayer*, EQMissile*), EQPlayer__AimAtTarget);
#endif
#ifdef EQPlayer__FacePlayer_x
FUNCTION_AT_ADDRESS(void EQPlayer::FacePlayer(EQPlayer*), EQPlayer__FacePlayer);
#endif
#ifdef EQPlayer__CleanUpVehicle_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpVehicle(), EQPlayer__CleanUpVehicle);
#endif
#ifdef EQPlayer__CleanUpMyEffects_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpMyEffects(), EQPlayer__CleanUpMyEffects);
#endif
#ifdef EQPlayer__GetPlayerFromName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetPlayerFromName(const char*), EQPlayer__GetPlayerFromName);
#endif
#ifdef EQPlayer__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetPlayerFromPartialName(char*), EQPlayer__GetPlayerFromPartialName);
#endif
#ifdef EQPlayer__GetClosestPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetClosestPlayerFromPartialName(char*, EQPlayer*), EQPlayer__GetClosestPlayerFromPartialName);
#endif
#ifdef EQPlayer__IsPlayerActor_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE*), EQPlayer__IsPlayerActor);
#endif
#ifdef EQPlayer__TackOnNeuterChar_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::TackOnNeuterChar(char*, unsigned int), EQPlayer__TackOnNeuterChar);
#endif
#ifdef EQPlayer__GetActorTag_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetActorTag(char*), EQPlayer__GetActorTag);
#endif
#ifdef EQPlayer__GetPCActorTag_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::GetPCActorTag(char*, unsigned int, unsigned char), EQPlayer__GetPCActorTag);
#endif
#ifdef EQPlayer__NotOnSameDeity_x
FUNCTION_AT_ADDRESS(int EQPlayer::NotOnSameDeity(EQPlayer*, EQ_Spell*), EQPlayer__NotOnSameDeity);
#endif
#ifdef EQPlayer__SetAnimVariation_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAnimVariation(), EQPlayer__SetAnimVariation);
#endif
#ifdef EQPlayer__SetAfk_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAfk(int), EQPlayer__SetAfk);
#endif
#ifdef EQPlayer__AllowedToAttack_x
FUNCTION_AT_ADDRESS(bool EQPlayer::AllowedToAttack(EQPlayer*, int), EQPlayer__AllowedToAttack);
#endif
#ifdef EQPlayer__CanIHit_x
FUNCTION_AT_ADDRESS(bool EQPlayer::CanIHit(EQPlayer*, float), EQPlayer__CanIHit);
#endif
#ifdef EQPlayer__CanSee_x
FUNCTION_AT_ADDRESS(bool PlayerBase::CanSee(const PlayerBase&), EQPlayer__CanSee);
#endif
#ifdef EQPlayer__CanSee1_x
FUNCTION_AT_ADDRESS(bool PlayerBase::CanSee(const CVector3& pos), EQPlayer__CanSee1);
#endif
#ifdef EQPlayer__ModifyAttackSpeed_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::ModifyAttackSpeed(unsigned int, int), EQPlayer__ModifyAttackSpeed);
#endif
#ifdef EQPlayer__DoAttack_x
#if defined(ROF2EMU) || defined(UFEMU)
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::DoAttack(BYTE, BYTE, PlayerZoneClient*), EQPlayer__DoAttack);
#else
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::DoAttack(BYTE, BYTE, PlayerZoneClient*, bool, bool, bool), EQPlayer__DoAttack);
#endif
#endif
#ifdef EQPlayer__HandleAmmo_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HandleAmmo(), EQPlayer__HandleAmmo);
#endif
#ifdef EQPlayer__TriggerSpellEffect_x
FUNCTION_AT_ADDRESS(void EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo*), EQPlayer__TriggerSpellEffect);
#endif
#ifdef EQPlayer__IWasHit_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IWasHit(struct _EQMissileHitinfo*), EQPlayer__IWasHit);
#endif
#ifdef EQPlayer__GetConscious_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetConscious(), EQPlayer__GetConscious);
#endif
#ifdef EQPlayer__KnockedOut_x
FUNCTION_AT_ADDRESS(void EQPlayer::KnockedOut(), EQPlayer__KnockedOut);
#endif
#ifdef EQPlayer__IDied_x
FUNCTION_AT_ADDRESS(void EQPlayer::IDied(struct _EQPlayerDeath*), EQPlayer__IDied);
#endif
#ifdef EQPlayer__HandoverControlToZoneserver_x
FUNCTION_AT_ADDRESS(void EQPlayer::HandoverControlToZoneserver(), EQPlayer__HandoverControlToZoneserver);
#endif
#ifdef EQPlayer__TouchingSwitch_x
FUNCTION_AT_ADDRESS(void EQPlayer::TouchingSwitch(), EQPlayer__TouchingSwitch);
#endif
#ifdef EQPlayer__MyFeetAreOnGround_x
FUNCTION_AT_ADDRESS(bool EQPlayer::MyFeetAreOnGround(), EQPlayer__MyFeetAreOnGround);
#endif
#ifdef EQPlayer__IHaveFallen_x
FUNCTION_AT_ADDRESS(void EQPlayer::IHaveFallen(float), EQPlayer__IHaveFallen);
#endif
#ifdef EQPlayer__SkillUsed_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::SkillUsed(unsigned char), EQPlayer__SkillUsed);
#endif
#ifdef EQPlayer__BodyEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::BodyEnvironmentChange(unsigned char), EQPlayer__BodyEnvironmentChange);
#endif
#ifdef EQPlayer__FeetEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::FeetEnvironmentChange(unsigned char), EQPlayer__FeetEnvironmentChange);
#endif
#ifdef EQPlayer__HeadEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::HeadEnvironmentChange(unsigned char), EQPlayer__HeadEnvironmentChange);
#endif
#ifdef PlayerZoneClient__LegalPlayerRace_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::LegalPlayerRace(int), PlayerZoneClient__LegalPlayerRace);
#endif
#ifdef EQPlayer__DeleteMyMissiles_x
FUNCTION_AT_ADDRESS(void EQPlayer::DeleteMyMissiles(), EQPlayer__DeleteMyMissiles);
#endif
#ifdef EQPlayer__ChangePosition_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangePosition(unsigned char), EQPlayer__ChangePosition);
#endif
#ifdef EQPlayer__ChangeHeight_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeHeight(float), EQPlayer__ChangeHeight);
#endif
#ifdef EQPlayer__PositionOnFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::PositionOnFloor(), EQPlayer__PositionOnFloor);
#endif
#ifdef EQPlayer__IsRoleplaying_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsRoleplaying(), EQPlayer__IsRoleplaying);
#endif
#ifdef EQPlayer__IsInvited_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsInvited(), EQPlayer__IsInvited);
#endif
#ifdef EQPlayer__SetInvited_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetInvited(bool), EQPlayer__SetInvited);
#endif
#ifdef EQPlayer__PlaySoundA_x
FUNCTION_AT_ADDRESS(void EQPlayer::PlaySoundA(int), EQPlayer__PlaySoundA);
#endif
#ifdef EQPlayer__SetSounds_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetSounds(), EQPlayer__SetSounds);
#endif
#ifdef EQPlayer__SetCurrentLoopSound_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetCurrentLoopSound(int), EQPlayer__SetCurrentLoopSound);
#endif
#ifdef EQPlayer__IsFlyer_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsFlyer(), EQPlayer__IsFlyer);
#endif
#ifdef EQPlayer__InitSneakMod_x
FUNCTION_AT_ADDRESS(void EQPlayer::InitSneakMod(), EQPlayer__InitSneakMod);
#endif
#ifdef EQPlayer__SetHeights_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetHeights(), EQPlayer__SetHeights);
#endif
#ifdef EQPMInfo__SetApplyGravity_x
FUNCTION_AT_ADDRESS(void EQPMInfo::SetApplyGravity(bool), EQPMInfo__SetApplyGravity);
#endif
#ifdef EQPlayer__GetDefaultHeight_x
FUNCTION_AT_ADDRESS(float EQPlayer::GetDefaultHeight(int, unsigned char), EQPlayer__GetDefaultHeight);
#endif
#ifdef EQPlayer__ComputeSpecialHeights_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::ComputeSpecialHeights(int, float*, float*, float*, float*, bool), EQPlayer__ComputeSpecialHeights);
#endif
#ifdef EQPlayer__IsUntexturedHorse_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsUntexturedHorse(), EQPlayer__IsUntexturedHorse);
#endif
#ifdef EQPlayer__HasInvalidRiderTexture_x
FUNCTION_AT_ADDRESS(bool const EQPlayer::HasInvalidRiderTexture() const, EQPlayer__HasInvalidRiderTexture);
#endif
#ifdef EQPlayer__ForceInvisible_x
FUNCTION_AT_ADDRESS(void EQPlayer::ForceInvisible(bool), EQPlayer__ForceInvisible);
#endif
#ifdef EQPlayer__MountableRace_x
FUNCTION_AT_ADDRESS(int EQPlayer::MountableRace(), EQPlayer__MountableRace);
#endif
#ifdef EQPlayer__MakeRiderMountUp_x
FUNCTION_AT_ADDRESS(void EQPlayer::MakeRiderMountUp(), EQPlayer__MakeRiderMountUp);
#endif
#ifdef EQPlayer__MountEQPlayer_x
FUNCTION_AT_ADDRESS(void EQPlayer::MountEQPlayer(EQPlayer*), EQPlayer__MountEQPlayer);
#endif
#ifdef EQPlayer__Dismount_x
FUNCTION_AT_ADDRESS(void EQPlayer::Dismount(), EQPlayer__Dismount);
#endif
#ifdef EQPlayer__GetArmorType_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetArmorType(int), EQPlayer__GetArmorType);
#endif
#ifdef EQPlayer__SetArmorType_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetArmorType(int, int), EQPlayer__SetArmorType);
#endif
#ifdef EQPlayer__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long EQPlayer::GetArmorTint(int), EQPlayer__GetArmorTint);
#endif
#ifdef EQPlayer__SetArmorTint_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetArmorTint(int, unsigned long), EQPlayer__SetArmorTint);
#endif
#ifdef EQPlayer__SetAccel_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAccel(float, int), EQPlayer__SetAccel);
#endif
#ifdef EQPlayer__SetToRandomRace_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetToRandomRace(), EQPlayer__SetToRandomRace);
#endif
#ifdef EQPlayer__GetBaseFaceNbr_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetBaseFaceNbr(int, unsigned char*), EQPlayer__GetBaseFaceNbr);
#endif
#ifdef EQPlayer__HasAttachedBeard_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HasAttachedBeard(), EQPlayer__HasAttachedBeard);
#endif
#ifdef EQPlayer__HasAttachedHair_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HasAttachedHair(), EQPlayer__HasAttachedHair);
#endif
#ifdef EQPlayer__SetDefaultFacialFeaturesByFace_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char), EQPlayer__SetDefaultFacialFeaturesByFace);
#endif
#ifdef EQPlayer__GetAllowedHairColorIndexRange_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetAllowedHairColorIndexRange(int, int*, int*), EQPlayer__GetAllowedHairColorIndexRange);
#endif
#ifdef EQPlayer__CanBeBald_x
FUNCTION_AT_ADDRESS(int EQPlayer::CanBeBald(), EQPlayer__CanBeBald);
#endif
#ifdef EQPlayer__ChangeNoGravity_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeNoGravity(int), EQPlayer__ChangeNoGravity);
#endif
#ifdef EQPlayer__IdUsed_x
FUNCTION_AT_ADDRESS(int EQPlayer::IdUsed(unsigned int), EQPlayer__IdUsed);
#endif
#ifdef EQPlayer__GetUnusedID_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::GetUnusedID(), EQPlayer__GetUnusedID);
#endif
#ifdef EQPlayer__SetAndReserveID_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAndReserveID(unsigned int), EQPlayer__SetAndReserveID);
#endif
#ifdef EQPlayer__InitializeIDArray_x
FUNCTION_AT_ADDRESS(void EQPlayer::InitializeIDArray(), EQPlayer__InitializeIDArray);
#endif
#ifdef PlayerZoneClient__GetLevel_x
FUNCTION_AT_ADDRESS(unsigned char PlayerZoneClient::GetLevel() const, PlayerZoneClient__GetLevel);
#endif
#ifdef EQPlayer__Levitating_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::Levitating(), EQPlayer__Levitating);
#endif
#ifdef EQPlayer__SetRace_x
FUNCTION_AT_ADDRESS(void PlayerZoneClient::SetRace(int), EQPlayer__SetRace);
#endif
#ifdef EQPlayer__CanChangeForm_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::CanChangeForm(int Race, BYTE Sex, float Height), EQPlayer__CanChangeForm);
#endif
#ifdef EQPlayer__SetNameSpriteState_x
FUNCTION_AT_ADDRESS(int PlayerClient::SetNameSpriteState(bool), EQPlayer__SetNameSpriteState);
#endif
#ifdef EQPlayer__ChangeBoneStringSprite_x
FUNCTION_AT_ADDRESS(void PlayerClient::ChangeBoneStringSprite(int, char*), EQPlayer__ChangeBoneStringSprite);
#endif
#ifdef EQPlayer__SetNameSpriteTint_x
FUNCTION_AT_ADDRESS(bool PlayerClient::SetNameSpriteTint(), EQPlayer__SetNameSpriteTint);
#endif
#ifdef PlayerClient__GetPcClient_x
FUNCTION_AT_ADDRESS(PcClient* PlayerClient::GetPcClient() const, PlayerClient__GetPcClient);
#endif
#ifdef PcClient__PcClient_x
FUNCTION_AT_ADDRESS(PcClient::PcClient(), PcClient__PcClient);
#endif
#ifdef EQPlayer__UpdateNameSprite_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateNameSprite(), EQPlayer__UpdateNameSprite);
#endif
#ifdef EQPlayer__UpdateBonePointers_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateBonePointers(), EQPlayer__UpdateBonePointers);
#endif
#ifdef EQPlayer__FindDefaultEyeMaterialIndexes_x
FUNCTION_AT_ADDRESS(void EQPlayer::FindDefaultEyeMaterialIndexes(), EQPlayer__FindDefaultEyeMaterialIndexes);
#endif
#ifdef EQPlayer__CalcAnimLength_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::CalcAnimLength(int), EQPlayer__CalcAnimLength);
#endif
#ifdef EQPlayer__GetAlternateTrackNumber_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetAlternateTrackNumber(int, unsigned char*), EQPlayer__GetAlternateTrackNumber);
#endif
#ifdef EQPlayer__GetAlternateAnimVariation_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetAlternateAnimVariation(int, unsigned char), EQPlayer__GetAlternateAnimVariation);
#endif
#ifdef EQPlayer__GetRaceSexITOffset_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetRaceSexITOffset(), EQPlayer__GetRaceSexITOffset);
#endif
#ifdef EQPlayer__UpdatePlayerVisibility_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdatePlayerVisibility(), EQPlayer__UpdatePlayerVisibility);
#endif
#ifdef EQPlayer__UpdateAllPlayersVisibility_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::UpdateAllPlayersVisibility(), EQPlayer__UpdateAllPlayersVisibility);
#endif
#ifdef PlayerBase__HasProperty_j_x
FUNCTION_AT_ADDRESS(bool PlayerBase::HasProperty(unsigned int, int, int), PlayerBase__HasProperty_j);
#endif
#ifdef PlayerBase__GetVisibilityLineSegment_x
FUNCTION_AT_ADDRESS(CLineSegment PlayerBase::GetVisibilityLineSegment(const PlayerBase&, unsigned int), PlayerBase__GetVisibilityLineSegment);
#endif
#ifdef EQPlayer__SetEyeMaterial_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetEyeMaterial(unsigned char, int), EQPlayer__SetEyeMaterial);
#endif
#ifdef EQPlayer__HideOrShowAttachedHair_x
FUNCTION_AT_ADDRESS(void EQPlayer::HideOrShowAttachedHair(), EQPlayer__HideOrShowAttachedHair);
#endif
#ifdef EQPlayer__SetFHEB_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetFHEB(unsigned char, unsigned char), EQPlayer__SetFHEB);
#endif
#ifdef EQPlayer__SetFHEB_Color_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetFHEB_Color(unsigned char, unsigned char), EQPlayer__SetFHEB_Color);
#endif
#ifdef EQPlayer__SetHairOrBeard_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetHairOrBeard(int), EQPlayer__SetHairOrBeard);
#endif
#ifdef EQPlayer__GetBonePointerByITS_x
FUNCTION_AT_ADDRESS(struct T3D_DAG* EQPlayer::GetBonePointerByITS(int, int), EQPlayer__GetBonePointerByITS);
#endif
#ifdef EQPlayer__UpdateAppearance_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateAppearance(), EQPlayer__UpdateAppearance);
#endif
#ifdef EQPlayer__SetDefaultITAttachments_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetDefaultITAttachments(int), EQPlayer__SetDefaultITAttachments);
#endif
#ifdef EQPlayer__SwapMaterial_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapMaterial(int, int, int, int, unsigned char), EQPlayer__SwapMaterial);
#endif
#ifdef EQPlayer__SwapFace_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapFace(int, int), EQPlayer__SwapFace);
#endif
#ifdef EQPlayer__GetAttachedHelmITNum_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetAttachedHelmITNum(int, int*), EQPlayer__GetAttachedHelmITNum);
#endif
#ifdef EQPlayer__SetPlayerConstantAmbient_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB*), EQPlayer__SetPlayerConstantAmbient);
#endif
#ifdef EQPlayer__SwapHead_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapHead(int, int, unsigned long, int), EQPlayer__SwapHead);
#endif
#ifdef EQPlayer__SetPlayerPitchType_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetPlayerPitchType(), EQPlayer__SetPlayerPitchType);
#endif
#ifdef PlayerZoneClient__IsValidTeleport_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::IsValidTeleport(float X, float Y, float Z, float Heading, float Distance), PlayerZoneClient__IsValidTeleport);
#endif
#ifdef EQPlayer__ReplaceSpecialCloakMaterials_x
FUNCTION_AT_ADDRESS(int EQPlayer::ReplaceSpecialCloakMaterials(), EQPlayer__ReplaceSpecialCloakMaterials);
#endif
#ifdef EQPlayer__SwapBody_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapBody(int, int), EQPlayer__SwapBody);
#endif
#ifdef EQPlayer__HandleMaterialEx_x
FUNCTION_AT_ADDRESS(void EQPlayer::HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int), EQPlayer__HandleMaterialEx);
#endif
#ifdef EQPlayer__UpdateItemSlot_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::UpdateItemSlot(unsigned char, char*, int), EQPlayer__UpdateItemSlot);
#endif
#ifdef EQPlayer__SwapNPCMaterials_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapNPCMaterials(), EQPlayer__SwapNPCMaterials);
#endif
#ifdef EQPlayer__PutPlayerOnFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::PutPlayerOnFloor(), EQPlayer__PutPlayerOnFloor);
#endif
#ifdef EQPlayer__CheckForUnderFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::CheckForUnderFloor(), EQPlayer__CheckForUnderFloor);
#endif
#ifdef EQPlayer__DoFloorCheck_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoFloorCheck(), EQPlayer__DoFloorCheck);
#endif
#ifdef EQPlayer__DoSwimJump_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoSwimJump(unsigned char), EQPlayer__DoSwimJump);
#endif
#ifdef EQPlayer__PushAlongHeading_x
FUNCTION_AT_ADDRESS(void EQPlayer::PushAlongHeading(float), EQPlayer__PushAlongHeading);
#endif
#ifdef EQPlayer__DoTeleport_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::DoTeleport(char*, int), EQPlayer__DoTeleport);
#endif
#ifdef EQPlayer__ChangeLight_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeLight(), EQPlayer__ChangeLight);
#endif
#ifdef EQPlayer__GetBoneCoords_x
FUNCTION_AT_ADDRESS(bool EQPlayer::GetBoneCoords(struct T3D_DAG*, struct _EQLOC*), EQPlayer__GetBoneCoords);
#endif
#ifdef EQPlayer__CheckForJump_x
FUNCTION_AT_ADDRESS(int EQPlayer::CheckForJump(), EQPlayer__CheckForJump);
#endif
#ifdef EQPlayer__GetPlayerFloorHeight_x
FUNCTION_AT_ADDRESS(float EQPlayer::GetPlayerFloorHeight(float, float, float, unsigned char), EQPlayer__GetPlayerFloorHeight);
#endif
#ifdef EQPlayer__UpdatePlayerActor_x
FUNCTION_AT_ADDRESS(bool EQPlayer::UpdatePlayerActor(), EQPlayer__UpdatePlayerActor);
#endif
#ifdef EQPlayer__GetNearestActorTag_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetNearestActorTag(char*, void*), EQPlayer__GetNearestActorTag);
#endif
#ifdef EQPlayer__DoItemSlot_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoItemSlot(int), EQPlayer__DoItemSlot);
#endif
#ifdef EQPlayer__DoClassRandomAnimation_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoClassRandomAnimation(), EQPlayer__DoClassRandomAnimation);
#endif
#ifdef EQPlayer__CreateUserLight_x
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT* EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION*, int), EQPlayer__CreateUserLight);
#endif
#ifdef EQPlayer__AttachPlayerToPlayerBone_x
FUNCTION_AT_ADDRESS(int EQPlayer::AttachPlayerToPlayerBone(EQPlayer*, struct T3D_DAG*), EQPlayer__AttachPlayerToPlayerBone);
#endif
#ifdef EQPlayer__IsInvisible_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsInvisible(EQPlayer*), EQPlayer__IsInvisible);
#endif
#ifdef EQPlayer__IsAMount_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsAMount(), EQPlayer__IsAMount);
#endif
#ifdef EQPlayerManager__GetSpawnByID_x
FUNCTION_AT_ADDRESS(PlayerClient* EQPlayerManager::GetSpawnByID(int), EQPlayerManager__GetSpawnByID);
#endif
#ifdef EQPlayerManager__GetSpawnByName_x
FUNCTION_AT_ADDRESS(PlayerClient* EQPlayerManager::GetSpawnByName(char*), EQPlayerManager__GetSpawnByName);
#endif
#ifdef EQPlayerManager__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(PlayerClient* EQPlayerManager::GetPlayerFromPartialName(const char*, PlayerBase*), EQPlayerManager__GetPlayerFromPartialName);
#endif
#ifdef EQPMInfo__EQPMInfo_x
FUNCTION_AT_ADDRESS(EQPMInfo::EQPMInfo(char*), EQPMInfo__EQPMInfo);
#endif
#ifdef EQPMInfo__dEQPMInfo_x
FUNCTION_AT_ADDRESS(EQPMInfo::~EQPMInfo(), EQPMInfo__dEQPMInfo);
#endif
#ifdef EQSwitch__EQSwitch_x
FUNCTION_AT_ADDRESS(EQSwitch::EQSwitch(char*, bool), EQSwitch__EQSwitch);
#endif
#ifdef EQSwitch__EQSwitch1_x
FUNCTION_AT_ADDRESS(EQSwitch::EQSwitch(struct OldDiskSwitch*, bool), EQSwitch__EQSwitch1);
#endif
#ifdef EQSwitch__EQSwitch2_x
FUNCTION_AT_ADDRESS(EQSwitch::EQSwitch(struct _EQClientSwitch*), EQSwitch__EQSwitch2);
#endif
#ifdef EQSwitch__PreInit_x
FUNCTION_AT_ADDRESS(void EQSwitch::PreInit(), EQSwitch__PreInit);
#endif
#ifdef EQSwitch__PostInit_x
FUNCTION_AT_ADDRESS(void EQSwitch::PostInit(), EQSwitch__PostInit);
#endif
#ifdef EQSwitch__dEQSwitch_x
FUNCTION_AT_ADDRESS(EQSwitch::~EQSwitch(), EQSwitch__dEQSwitch);
#endif
#ifdef EQSwitch__ResetSwitchState_x
FUNCTION_AT_ADDRESS(void EQSwitch::ResetSwitchState(unsigned char), EQSwitch__ResetSwitchState);
#endif
#ifdef EQSwitch__RepopSwitch_x
FUNCTION_AT_ADDRESS(void EQSwitch::RepopSwitch(), EQSwitch__RepopSwitch);
#endif
#ifdef EQSwitch__TopSpeed_x
FUNCTION_AT_ADDRESS(float EQSwitch::TopSpeed(float*), EQSwitch__TopSpeed);
#endif
#ifdef EQSwitch__RepopFrequency_x
FUNCTION_AT_ADDRESS(unsigned int EQSwitch::RepopFrequency(), EQSwitch__RepopFrequency);
#endif
#ifdef EQSwitch__GetSwitchDamage_x
FUNCTION_AT_ADDRESS(int EQSwitch::GetSwitchDamage(), EQSwitch__GetSwitchDamage);
#endif
#ifdef EQSwitch__ChangeState_x
FUNCTION_AT_ADDRESS(void EQSwitch::ChangeState(unsigned char, EQPlayer*, bool), EQSwitch__ChangeState);
#endif
#ifdef EQSwitch__SwitchWasOpened_x
FUNCTION_AT_ADDRESS(unsigned char EQSwitch::SwitchWasOpened(int, int, EQPlayer*, bool*), EQSwitch__SwitchWasOpened);
#endif
#ifdef EQSwitch__SwitchWasOpenedActual_x
FUNCTION_AT_ADDRESS(unsigned char EQSwitch::SwitchWasOpenedActual(int, int, EQPlayer*, bool*), EQSwitch__SwitchWasOpenedActual);
#endif
#ifdef EQSwitch__SwitchIsNotUsable_x
FUNCTION_AT_ADDRESS(unsigned char EQSwitch::SwitchIsNotUsable(int), EQSwitch__SwitchIsNotUsable);
#endif
#ifdef EQSwitch__UseSwitch_x
FUNCTION_AT_ADDRESS(void EQSwitch::UseSwitch(UINT, int, int, const CVector3*), EQSwitch__UseSwitch);
#endif
#ifdef EQSwitch__LoadSwitchSounds_x
FUNCTION_AT_ADDRESS(void EQSwitch::LoadSwitchSounds(int), EQSwitch__LoadSwitchSounds);
#endif
#ifdef EQSwitch__GetCustomMoveDistance_x
FUNCTION_AT_ADDRESS(float EQSwitch::GetCustomMoveDistance(), EQSwitch__GetCustomMoveDistance);
#endif
#ifdef EqSwitchManager__EqSwitchManager_x
FUNCTION_AT_ADDRESS(EqSwitchManager::EqSwitchManager(), EqSwitchManager__EqSwitchManager);
#endif
#ifdef EqSwitchManager__dEqSwitchManager_x
FUNCTION_AT_ADDRESS(EqSwitchManager::~EqSwitchManager(), EqSwitchManager__dEqSwitchManager);
#endif
#ifdef EqSwitchManager__DeleteAll_x
FUNCTION_AT_ADDRESS(void EqSwitchManager::DeleteAll(), EqSwitchManager__DeleteAll);
#endif
#ifdef EqSwitchManager__Load_x
FUNCTION_AT_ADDRESS(void EqSwitchManager::Load(char*, bool), EqSwitchManager__Load);
#endif
#ifdef EqSwitchManager__LoadOld_x
FUNCTION_AT_ADDRESS(void EqSwitchManager::LoadOld(char*, bool), EqSwitchManager__LoadOld);
#endif
#ifdef EqSwitchManager__GetCount_x
FUNCTION_AT_ADDRESS(int EqSwitchManager::GetCount(), EqSwitchManager__GetCount);
#endif
#ifdef EqSwitchManager__GetSwitchByActor_x
FUNCTION_AT_ADDRESS(EQSwitch* EqSwitchManager::GetSwitchByActor(struct T3D_tagACTORINSTANCE*), EqSwitchManager__GetSwitchByActor);
#endif
#ifdef EqSwitchManager__GetSwitch_x
FUNCTION_AT_ADDRESS(EQSwitch* EqSwitchManager::GetSwitch(int), EqSwitchManager__GetSwitch);
#endif
#ifdef EqSwitchManager__GetSwitchById_x
FUNCTION_AT_ADDRESS(EQSwitch* EqSwitchManager::GetSwitchById(int, bool), EqSwitchManager__GetSwitchById);
#endif
#ifdef EqSwitchManager__AddSwitch_x
FUNCTION_AT_ADDRESS(void EqSwitchManager::AddSwitch(EQSwitch*), EqSwitchManager__AddSwitch);
#endif
#ifdef Util__GetNextToken_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char*, int*, char*), Util__GetNextToken);
#endif
#ifdef Util__GetNextToken1_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char*, short*, char*), Util__GetNextToken1);
#endif
#ifdef Util__GetNextToken2_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char*, char*, char*), Util__GetNextToken2);
#endif
#ifdef Util__GetNextToken3_x
FUNCTION_AT_ADDRESS(int __cdecl Util::GetNextToken(char*, unsigned char*, char*), Util__GetNextToken3);
#endif
#ifdef EQUtil__FormatCharName_x
FUNCTION_AT_ADDRESS(char* __cdecl EQUtil::FormatCharName(char*, char*, int), EQUtil__FormatCharName);
#endif
#ifdef EQWorldData__EQWorldData_x
FUNCTION_AT_ADDRESS(EQWorldData::EQWorldData(), EQWorldData__EQWorldData);
#endif
#ifdef EQWorldData__AdvanceTime_x
FUNCTION_AT_ADDRESS(void EQWorldData::AdvanceTime(unsigned int), EQWorldData__AdvanceTime);
#endif
#ifdef EQWorldData__CurrentGameTime_x
FUNCTION_AT_ADDRESS(void EQWorldData::CurrentGameTime(char*), EQWorldData__CurrentGameTime);
#endif
#ifdef CEverQuest__ChatServerGiveTime_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerGiveTime(), CEverQuest__ChatServerGiveTime);
#endif
#ifdef CEverQuest__ChatServerNotificationAdd_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerNotificationAdd(bool, char*, char*, int), CEverQuest__ChatServerNotificationAdd);
#endif
#ifdef CEverQuest__ChatServerNotificationFlush_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerNotificationFlush(), CEverQuest__ChatServerNotificationFlush);
#endif
#ifdef CEverQuest__ChatServerConnect_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerConnect(char*, int, char*, char*), CEverQuest__ChatServerConnect);
#endif
#ifdef CEverQuest__ChatServerMessage_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerMessage(char*), CEverQuest__ChatServerMessage);
#endif
#ifdef CEverQuest__ChatServerDisconnect_x
FUNCTION_AT_ADDRESS(void CEverQuest::ChatServerDisconnect(), CEverQuest__ChatServerDisconnect);
#endif
#ifdef CEverQuest__ResetVisionRGBs_x
FUNCTION_AT_ADDRESS(void CEverQuest::ResetVisionRGBs(), CEverQuest__ResetVisionRGBs);
#endif
#ifdef CEverQuest__GetMaxLightRadius_x
FUNCTION_AT_ADDRESS(float CEverQuest::GetMaxLightRadius(), CEverQuest__GetMaxLightRadius);
#endif
#ifdef CEverQuest__LoadStringTables_x
FUNCTION_AT_ADDRESS(void CEverQuest::LoadStringTables(), CEverQuest__LoadStringTables);
#endif
#ifdef CEverQuest__CEverQuest_x
FUNCTION_AT_ADDRESS(CEverQuest::CEverQuest(struct HWND__*), CEverQuest__CEverQuest);
#endif
#ifdef CEverQuest__dCEverQuest_x
FUNCTION_AT_ADDRESS(CEverQuest::~CEverQuest(), CEverQuest__dCEverQuest);
#endif
#ifdef CEverQuest__ProcessMBox_x
FUNCTION_AT_ADDRESS(int CEverQuest::ProcessMBox(), CEverQuest__ProcessMBox);
#endif
#ifdef CEverQuest__UseCharge_x
FUNCTION_AT_ADDRESS(void CEverQuest::UseCharge(unsigned long), CEverQuest__UseCharge);
#endif
#ifdef CEverQuest__LeaveGuildMaster_x
FUNCTION_AT_ADDRESS(void CEverQuest::LeaveGuildMaster(), CEverQuest__LeaveGuildMaster);
#endif
#ifdef CEverQuest__LeaveBankMode_x
FUNCTION_AT_ADDRESS(void CEverQuest::LeaveBankMode(bool), CEverQuest__LeaveBankMode);
#endif
#ifdef CEverQuest__ReportDeath_x
FUNCTION_AT_ADDRESS(void CEverQuest::ReportDeath(struct _EQPlayerDeath*), CEverQuest__ReportDeath);
#endif
#ifdef CEverQuest__SetDefaultDamageDescByRace_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetDefaultDamageDescByRace(char*, int, unsigned char), CEverQuest__SetDefaultDamageDescByRace);
#endif
#ifdef CEverQuest__ReportSuccessfulHit_x
FUNCTION_AT_ADDRESS(void CEverQuest::ReportSuccessfulHit(EQSuccessfulHit* pHit, unsigned char bOutputText, int ActualHeal), CEverQuest__ReportSuccessfulHit);
#endif
#ifdef CEverQuest__GetCombatSound_x
FUNCTION_AT_ADDRESS(int CEverQuest::GetCombatSound(EQPlayer*, EQPlayer*), CEverQuest__GetCombatSound);
#endif
#ifdef CEverQuest__LocalDeath_x
FUNCTION_AT_ADDRESS(void CEverQuest::LocalDeath(struct _EQPlayerDeath*, unsigned char), CEverQuest__LocalDeath);
#endif
#ifdef CEverQuest__PrepareLocalPCForRepop_x
FUNCTION_AT_ADDRESS(void CEverQuest::PrepareLocalPCForRepop(), CEverQuest__PrepareLocalPCForRepop);
#endif
#ifdef CEverQuest__SavePCForce_x
FUNCTION_AT_ADDRESS(void CEverQuest::SavePCForce(int), CEverQuest__SavePCForce);
#endif
#ifdef CEverQuest__StartCasting_x
FUNCTION_AT_ADDRESS(void CEverQuest::StartCasting(void*), CEverQuest__StartCasting);
#endif
#ifdef CEverQuest__Consider_x
FUNCTION_AT_ADDRESS(void CEverQuest::Consider(EQPlayer*, void*), CEverQuest__Consider);
#endif
#ifdef CEverQuest__GetClassDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetClassDesc(int), CEverQuest__GetClassDesc);
#endif
#ifdef CEverQuest__GetClassThreeLetterCode_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetClassThreeLetterCode(int), CEverQuest__GetClassThreeLetterCode);
#endif
#ifdef CEverQuest__GetItemClassDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetItemClassDesc(int), CEverQuest__GetItemClassDesc);
#endif
#ifdef CEverQuest__GetBodyTypeDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetBodyTypeDesc(int), CEverQuest__GetBodyTypeDesc);
#endif
#ifdef CEverQuest__GetLangDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetLangDesc(int), CEverQuest__GetLangDesc);
#endif
#ifdef CEverQuest__GetRaceDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetRaceDesc(int), CEverQuest__GetRaceDesc);
#endif
#ifdef CEverQuest__GetDeityDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetDeityDesc(int), CEverQuest__GetDeityDesc);
#endif
#ifdef CEverQuest__GuildInvite_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildInvite(char*, char*), CEverQuest__GuildInvite);
#endif
#ifdef CEverQuest__GuildRemove_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildRemove(char*), CEverQuest__GuildRemove);
#endif
#ifdef CEverQuest__GuildDelete_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildDelete(), CEverQuest__GuildDelete);
#endif
#ifdef CEverQuest__GuildStatus_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildStatus(char*), CEverQuest__GuildStatus);
#endif
#ifdef CEverQuest__GuildLeader_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildLeader(char*), CEverQuest__GuildLeader);
#endif
#ifdef CEverQuest__GuildSay_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildSay(char*), CEverQuest__GuildSay);
#endif
#ifdef CEverQuest__Who_x
FUNCTION_AT_ADDRESS(void CEverQuest::Who(char*), CEverQuest__Who);
#endif
#ifdef CEverQuest__GetInnateDesc_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetInnateDesc(int), CEverQuest__GetInnateDesc);
#endif
#ifdef CEverQuest__InviteOk_x
FUNCTION_AT_ADDRESS(void CEverQuest::InviteOk(char*), CEverQuest__InviteOk);
#endif
#ifdef CEverQuest__doUnInvite_x
FUNCTION_AT_ADDRESS(void CEverQuest::doUnInvite(char*), CEverQuest__doUnInvite);
#endif
#ifdef CEverQuest__Invite_x
FUNCTION_AT_ADDRESS(void CEverQuest::Invite(int), CEverQuest__Invite);
#endif
#ifdef CEverQuest__doInvite_x
FUNCTION_AT_ADDRESS(void CEverQuest::doInvite(uint32_t, char*), CEverQuest__doInvite);
#endif
#ifdef CEverQuest__Follow_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CEverQuest::Follow(int), CEverQuest__Follow);
#else
FUNCTION_AT_ADDRESS(int CEverQuest::Follow(), CEverQuest__Follow);
#endif
#endif
#ifdef CEverQuest__Disband_x
FUNCTION_AT_ADDRESS(void CEverQuest::Disband(), CEverQuest__Disband);
#endif
#ifdef CEverQuest__GuildWar_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildWar(char*, int), CEverQuest__GuildWar);
#endif
#ifdef CEverQuest__GuildPeace_x
FUNCTION_AT_ADDRESS(void CEverQuest::GuildPeace(char*), CEverQuest__GuildPeace);
#endif
#ifdef CEverQuest__Sit_x
FUNCTION_AT_ADDRESS(void CEverQuest::Sit(), CEverQuest__Sit);
#endif
#ifdef CEverQuest__Camp_x
FUNCTION_AT_ADDRESS(void CEverQuest::Camp(), CEverQuest__Camp);
#endif
#ifdef CEverQuest__DropHeldItemOnGround_x
FUNCTION_AT_ADDRESS(void CEverQuest::DropHeldItemOnGround(int), CEverQuest__DropHeldItemOnGround);
#endif
#ifdef CEverQuest__MoveMoney_x
FUNCTION_AT_ADDRESS(int CEverQuest::MoveMoney(int, int, int, int, int, bool), CEverQuest__MoveMoney);
#endif
#ifdef CEverQuest__DropHeldMoneyOnGround_x
FUNCTION_AT_ADDRESS(void CEverQuest::DropHeldMoneyOnGround(int), CEverQuest__DropHeldMoneyOnGround);
#endif
#ifdef CEverQuest__LMouseUp_x
FUNCTION_AT_ADDRESS(void CEverQuest::LMouseUp(int, int), CEverQuest__LMouseUp);
#endif
#ifdef CEverQuest__LeftClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void CEverQuest::LeftClickedOnPlayer(PlayerClient*), CEverQuest__LeftClickedOnPlayer);
#endif
#ifdef CEverQuest__DropItemOrMoneyOnPlayer_x
FUNCTION_AT_ADDRESS(void CEverQuest::DropItemOrMoneyOnPlayer(PlayerClient*), CEverQuest__DropItemOrMoneyOnPlayer);
#endif
#ifdef CEverQuest__RightClickedOnPlayer_x
FUNCTION_AT_ADDRESS(void CEverQuest::RightClickedOnPlayer(PlayerClient*, int), CEverQuest__RightClickedOnPlayer);
#endif
#ifdef CEverQuest__send_social_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_social(int, char*, char*), CEverQuest__send_social);
#endif
#ifdef CEverQuest__SavePC_x
FUNCTION_AT_ADDRESS(void CEverQuest::SavePC(int, int, unsigned char), CEverQuest__SavePC);
#endif
#ifdef CEverQuest__send_tell_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_tell(char*, char*), CEverQuest__send_tell);
#endif
#ifdef CEverQuest__send_petition_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_petition(), CEverQuest__send_petition);
#endif
#ifdef CEverQuest__send_private_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_private(), CEverQuest__send_private);
#endif
#ifdef CEverQuest__WriteIntToClientINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteIntToClientINI(int, char*, char*), CEverQuest__WriteIntToClientINI);
#endif
#ifdef CEverQuest__WriteFloatToClientINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteFloatToClientINI(float, char*, char*), CEverQuest__WriteFloatToClientINI);
#endif
#ifdef CEverQuest__WriteBoolToClientINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteBoolToClientINI(bool, char*, char*), CEverQuest__WriteBoolToClientINI);
#endif
#ifdef CEverQuest__WriteStringToClientINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteStringToClientINI(char*, char*, char*), CEverQuest__WriteStringToClientINI);
#endif
#ifdef CEverQuest__ReadClientINIString_x
FUNCTION_AT_ADDRESS(char* CEverQuest::ReadClientINIString(char*, char*, char*, char*, int), CEverQuest__ReadClientINIString);
#endif
#ifdef CEverQuest__ReadClientINIInt_x
FUNCTION_AT_ADDRESS(int CEverQuest::ReadClientINIInt(char*, char*, int), CEverQuest__ReadClientINIInt);
#endif
#ifdef CEverQuest__ReadClientINIFloat_x
FUNCTION_AT_ADDRESS(float CEverQuest::ReadClientINIFloat(char*, char*, float), CEverQuest__ReadClientINIFloat);
#endif
#ifdef CEverQuest__ReadClientINIBool_x
FUNCTION_AT_ADDRESS(bool CEverQuest::ReadClientINIBool(char*, char*, bool), CEverQuest__ReadClientINIBool);
#endif
#ifdef CEverQuest__WriteIntToUIINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteIntToUIINI(int, char*, char*), CEverQuest__WriteIntToUIINI);
#endif
#ifdef CEverQuest__WriteBoolToUIINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteBoolToUIINI(bool, char*, char*), CEverQuest__WriteBoolToUIINI);
#endif
#ifdef CEverQuest__WriteStringToUIINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::WriteStringToUIINI(char*, char*, char*), CEverQuest__WriteStringToUIINI);
#endif
#ifdef CEverQuest__ReadUIINIString_x
FUNCTION_AT_ADDRESS(char* CEverQuest::ReadUIINIString(char*, char*, char*, char*, int), CEverQuest__ReadUIINIString);
#endif
#ifdef CEverQuest__ReadUIINIInt_x
FUNCTION_AT_ADDRESS(int CEverQuest::ReadUIINIInt(char*, char*, int), CEverQuest__ReadUIINIInt);
#endif
#ifdef CEverQuest__ReadUIINIBool_x
FUNCTION_AT_ADDRESS(bool CEverQuest::ReadUIINIBool(char*, char*, bool), CEverQuest__ReadUIINIBool);
#endif
#ifdef CEverQuest__SaveCamerasToINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::SaveCamerasToINI(), CEverQuest__SaveCamerasToINI);
#endif
#ifdef CEverQuest__saveOptions_x
FUNCTION_AT_ADDRESS(void CEverQuest::saveOptions(), CEverQuest__saveOptions);
#endif
#ifdef CEverQuest__saveOptions2_x
FUNCTION_AT_ADDRESS(void CEverQuest::saveOptions2(), CEverQuest__saveOptions2);
#endif
#ifdef CEverQuest__send_update_filters_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_update_filters(), CEverQuest__send_update_filters);
#endif
#ifdef CEverQuest__loadOptions_x
FUNCTION_AT_ADDRESS(void CEverQuest::loadOptions(), CEverQuest__loadOptions);
#endif
#ifdef CEverQuest__DoSplit_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoSplit(char*), CEverQuest__DoSplit);
#endif
#ifdef CEverQuest__BeingIgnored_x
FUNCTION_AT_ADDRESS(int CEverQuest::BeingIgnored(char*), CEverQuest__BeingIgnored);
#endif
#ifdef CEverQuest__IsFriend_x
FUNCTION_AT_ADDRESS(int CEverQuest::IsFriend(const char*), CEverQuest__IsFriend);
#endif
#ifdef CEverQuest__ToggleAutoSplit_x
FUNCTION_AT_ADDRESS(void CEverQuest::ToggleAutoSplit(), CEverQuest__ToggleAutoSplit);
#endif
#ifdef CEverQuest__procMouse_x
FUNCTION_AT_ADDRESS(void CEverQuest::procMouse(int), CEverQuest__procMouse);
#endif
#ifdef CEverQuest__StripShipName_x
FUNCTION_AT_ADDRESS(char* CEverQuest::StripShipName(char*, char*), CEverQuest__StripShipName);
#endif
#ifdef CEverQuest__trimName_x
FUNCTION_AT_ADDRESS(char* CEverQuest::trimName(char*), CEverQuest__trimName);
#endif
#ifdef CEverQuest__CancelSneakHide_x
FUNCTION_AT_ADDRESS(void CEverQuest::CancelSneakHide(), CEverQuest__CancelSneakHide);
#endif
#ifdef CEverQuest__stripName_x
FUNCTION_AT_ADDRESS(char* CEverQuest::stripName(char*), CEverQuest__stripName);
#endif
#ifdef CEverQuest__clr_chat_input_x
FUNCTION_AT_ADDRESS(void CEverQuest::clr_chat_input(), CEverQuest__clr_chat_input);
#endif
#ifdef CEverQuest__dsp_chat_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CEverQuest::dsp_chat(const char* line, int color, bool bLogIsOk, bool bConvertPercent, char* SomeStr), CEverQuest__dsp_chat);
#else
FUNCTION_AT_ADDRESS(void CEverQuest::dsp_chat(const char* line, int color, bool bLogIsOk, bool bConvertPercent), CEverQuest__dsp_chat);
#endif
#endif
#ifdef CEverQuest__OutputTextToLog_x
FUNCTION_AT_ADDRESS(void CEverQuest::OutputTextToLog(const char* Text), CEverQuest__OutputTextToLog);
#endif
#ifdef CEverQuest__DoTellWindow_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoTellWindow(char* message, char* name, char* name2, void* unknown, int color, bool b), CEverQuest__DoTellWindow);
#endif
#ifdef CEverQuest__dsp_chat1_x
FUNCTION_AT_ADDRESS(void CEverQuest::dsp_chat(const char*), CEverQuest__dsp_chat1);
#endif
#ifdef CEverQuest__DoPercentConvert_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoPercentConvert(char*, bool), CEverQuest__DoPercentConvert);
#endif
#ifdef CEverQuest__Emote_x
FUNCTION_AT_ADDRESS(void CEverQuest::Emote(), CEverQuest__Emote);
#endif
#ifdef CEverQuest__send_broadcast_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_broadcast(), CEverQuest__send_broadcast);
#endif
#ifdef CEverQuest__send_chat_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_chat(), CEverQuest__send_chat);
#endif
#ifdef CEverQuest__send_gsay_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_gsay(), CEverQuest__send_gsay);
#endif
#ifdef CEverQuest__reqChannel_x
FUNCTION_AT_ADDRESS(void CEverQuest::reqChannel(), CEverQuest__reqChannel);
#endif
#ifdef CEverQuest__send_shout_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_shout(), CEverQuest__send_shout);
#endif
#ifdef CEverQuest__send_auction_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_auction(), CEverQuest__send_auction);
#endif
#ifdef CEverQuest__send_ooc_x
FUNCTION_AT_ADDRESS(void CEverQuest::send_ooc(), CEverQuest__send_ooc);
#endif
#ifdef CEverQuest__GetCurrentLanguage_x
FUNCTION_AT_ADDRESS(int CEverQuest::GetCurrentLanguage() const, CEverQuest__GetCurrentLanguage);
#endif
#ifdef CEverQuest__SendNewText_x
FUNCTION_AT_ADDRESS(void CEverQuest::SendNewText(int, char*, char*), CEverQuest__SendNewText);
#endif
#ifdef CEverQuest__DisplayScreen_x
FUNCTION_AT_ADDRESS(void CEverQuest::DisplayScreen(char*), CEverQuest__DisplayScreen);
#endif
#ifdef CEverQuest__IsValidName_x
FUNCTION_AT_ADDRESS(int CEverQuest::IsValidName(char*), CEverQuest__IsValidName);
#endif
#ifdef CEverQuest__DoNewCharacterCreation_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoNewCharacterCreation(), CEverQuest__DoNewCharacterCreation);
#endif
#ifdef CEverQuest__RemoveCharacterOptionFile_x
FUNCTION_AT_ADDRESS(void CEverQuest::RemoveCharacterOptionFile(char*), CEverQuest__RemoveCharacterOptionFile);
#endif
#ifdef CEverQuest__SetDefaultGameValues_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetDefaultGameValues(), CEverQuest__SetDefaultGameValues);
#endif
#ifdef CEverQuest__SetPlayerAppearanceFromPInfo_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetPlayerAppearanceFromPInfo(EQPlayer*, int, bool), CEverQuest__SetPlayerAppearanceFromPInfo);
#endif
#ifdef CEverQuest__DoCharacterSelection_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoCharacterSelection(), CEverQuest__DoCharacterSelection);
#endif
#ifdef CEverQuest__DoLogin_x
FUNCTION_AT_ADDRESS(int CEverQuest::DoLogin(struct HWND__*, struct HINSTANCE__*), CEverQuest__DoLogin);
#endif
#ifdef CEverQuest__SetupCharSelectCamera_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetupCharSelectCamera(), CEverQuest__SetupCharSelectCamera);
#endif
#ifdef CEverQuest__CreateDataSubdirectories_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateDataSubdirectories(), CEverQuest__CreateDataSubdirectories);
#endif
#ifdef CEverQuest__CreateFilenameServerCode_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateFilenameServerCode(char*), CEverQuest__CreateFilenameServerCode);
#endif
#ifdef CEverQuest__CreateIniFilenames_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateIniFilenames(), CEverQuest__CreateIniFilenames);
#endif
#ifdef CEverQuest__StartNetworkGame_x
FUNCTION_AT_ADDRESS(void CEverQuest::StartNetworkGame(struct HWND__*, struct HINSTANCE__*, char*), CEverQuest__StartNetworkGame);
#endif
#ifdef CEverQuest__GetZoneInfoFromNetwork_x
FUNCTION_AT_ADDRESS(void CEverQuest::GetZoneInfoFromNetwork(char*), CEverQuest__GetZoneInfoFromNetwork);
#endif
#ifdef CEverQuest__EnterZone_x
FUNCTION_AT_ADDRESS(void CEverQuest::EnterZone(struct HWND__*), CEverQuest__EnterZone);
#endif
#ifdef CEverQuest__Surname_x
FUNCTION_AT_ADDRESS(void CEverQuest::Surname(char*), CEverQuest__Surname);
#endif
#ifdef CEverQuest__Kill_x
FUNCTION_AT_ADDRESS(void CEverQuest::Kill(char*, char*), CEverQuest__Kill);
#endif
#ifdef CEverQuest__UpdateMyAppearance_x
FUNCTION_AT_ADDRESS(void CEverQuest::UpdateMyAppearance(), CEverQuest__UpdateMyAppearance);
#endif
#ifdef CEverQuest__IFoundMyVehicle_x
FUNCTION_AT_ADDRESS(unsigned char CEverQuest::IFoundMyVehicle(), CEverQuest__IFoundMyVehicle);
#endif
#ifdef CEverQuest__ProcessLocalPCIni_x
FUNCTION_AT_ADDRESS(void CEverQuest::ProcessLocalPCIni(int), CEverQuest__ProcessLocalPCIni);
#endif
#ifdef CEverQuest__DoMainLoop_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoMainLoop(struct HWND__*), CEverQuest__DoMainLoop);
#endif
#ifdef CEverQuest__ProcessControls_x
FUNCTION_AT_ADDRESS(void CEverQuest::ProcessControls(), CEverQuest__ProcessControls);
#endif
#ifdef CEverQuest__TypingMode_x
FUNCTION_AT_ADDRESS(int CEverQuest::TypingMode(), CEverQuest__TypingMode);
#endif
#ifdef CEverQuest__IsInTypingMode_x
FUNCTION_AT_ADDRESS(bool CEverQuest::IsInTypingMode(), CEverQuest__IsInTypingMode);
#endif
#ifdef CEverQuest__doInspect_x
FUNCTION_AT_ADDRESS(void CEverQuest::doInspect(EQPlayer*), CEverQuest__doInspect);
#endif
#ifdef __do_loot_x
FUNCTION_AT_ADDRESS(void CEverQuest::doLoot(), __do_loot);
#endif
#ifdef CEverQuest__SendLightInfo_x
FUNCTION_AT_ADDRESS(void CEverQuest::SendLightInfo(EQPlayer*, unsigned char), CEverQuest__SendLightInfo);
#endif
#ifdef CEverQuest__SetTimedFog_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetTimedFog(int), CEverQuest__SetTimedFog);
#endif
#ifdef CEverQuest__ProcessGame_x
FUNCTION_AT_ADDRESS(void CEverQuest::ProcessGame(struct HWND__*, struct HINSTANCE__*), CEverQuest__ProcessGame);
#endif
#ifdef CEverQuest__DoLoadScreenProgressBar_x
FUNCTION_AT_ADDRESS(void __cdecl CEverQuest::DoLoadScreenProgressBar(int, const char*, ...), CEverQuest__DoLoadScreenProgressBar);
#endif
#ifdef CEverQuest__DoLoadScreen_x
FUNCTION_AT_ADDRESS(void CEverQuest::DoLoadScreen(int), CEverQuest__DoLoadScreen);
#endif
#ifdef CEverQuest__CleanupBadFiles_x
FUNCTION_AT_ADDRESS(void CEverQuest::CleanupBadFiles(), CEverQuest__CleanupBadFiles);
#endif
#ifdef CEverQuest__CreateInitialActors_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateInitialActors(), CEverQuest__CreateInitialActors);
#endif
#ifdef CEverQuest__CreateTargetIndicator_x
FUNCTION_AT_ADDRESS(void CEverQuest::CreateTargetIndicator(int Slot, PSPELL pSpell, const ItemGlobalIndex& ItemLoc, ItemSpellTypes spelltype), CEverQuest__CreateTargetIndicator);
#endif
#ifdef CEverQuest__DeleteTargetIndicator_x
FUNCTION_AT_ADDRESS(int CEverQuest::DeleteTargetIndicator(), CEverQuest__DeleteTargetIndicator);
#endif
#ifdef CEverQuest__GetSndDriver_x
FUNCTION_AT_ADDRESS(void CEverQuest::GetSndDriver(), CEverQuest__GetSndDriver);
#endif
#ifdef CEverQuest__InterpretCmd_x
FUNCTION_AT_ADDRESS(void CEverQuest::InterpretCmd(PlayerClient*, char*), CEverQuest__InterpretCmd);
#endif
#ifdef CEverQuest__GrabFirstWord_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GrabFirstWord(char*, char*), CEverQuest__GrabFirstWord);
#endif
#ifdef CEverQuest__GrabFirstWord2_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GrabFirstWord2(char*, char*, int), CEverQuest__GrabFirstWord2);
#endif
#ifdef CEverQuest__CopyFirstWord_x
FUNCTION_AT_ADDRESS(void CEverQuest::CopyFirstWord(char*, char*), CEverQuest__CopyFirstWord);
#endif
#ifdef CEverQuest__ApplyPoison_x
FUNCTION_AT_ADDRESS(void CEverQuest::ApplyPoison(unsigned long), CEverQuest__ApplyPoison);
#endif
#ifdef CEverQuest__DeacSpellScreen_x
FUNCTION_AT_ADDRESS(void CEverQuest::DeacSpellScreen(), CEverQuest__DeacSpellScreen);
#endif
#ifdef CEverQuest__MoveToZone_x
FUNCTION_AT_ADDRESS(void CEverQuest::MoveToZone(int EQZoneIndex, char*, int, int ZONE_REQ_REASON, float, float, float, int), CEverQuest__MoveToZone);
#endif
#ifdef CEverQuest__LMouseDown_x
FUNCTION_AT_ADDRESS(void CEverQuest::LMouseDown(int, int), CEverQuest__LMouseDown);
#endif
#ifdef CEverQuest__RMouseDown_x
FUNCTION_AT_ADDRESS(void CEverQuest::RMouseDown(int, int), CEverQuest__RMouseDown);
#endif
#ifdef CEverQuest__RMouseUp_x
FUNCTION_AT_ADDRESS(void CEverQuest::RMouseUp(int, int), CEverQuest__RMouseUp);
#endif
#ifdef CEverQuest__MouseWheelScrolled_x
FUNCTION_AT_ADDRESS(void CEverQuest::MouseWheelScrolled(int), CEverQuest__MouseWheelScrolled);
#endif
#ifdef CEverQuest__ClickedSwitch_x
FUNCTION_AT_ADDRESS(EQSwitch* CEverQuest::ClickedSwitch(int, int), CEverQuest__ClickedSwitch);
#endif
#ifdef CEverQuest__ClickedPlayer_x
FUNCTION_AT_ADDRESS(PlayerClient* CEverQuest::ClickedPlayer(int, int), CEverQuest__ClickedPlayer);
#endif
#ifdef CEverQuest__WhatTimeIsIt_x
FUNCTION_AT_ADDRESS(void CEverQuest::WhatTimeIsIt(), CEverQuest__WhatTimeIsIt);
#endif
#ifdef CEverQuest__FreeSwitches_x
FUNCTION_AT_ADDRESS(void CEverQuest::FreeSwitches(), CEverQuest__FreeSwitches);
#endif
#ifdef CEverQuest__SetLfgPlayerStatus_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetLfgPlayerStatus(struct LfgPlayerStatus*), CEverQuest__SetLfgPlayerStatus);
#endif
#ifdef CEverQuest__SetLfgGroupStatus_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetLfgGroupStatus(struct LfgGroupStatus*), CEverQuest__SetLfgGroupStatus);
#endif
#ifdef CEverQuest__IssueLfgPlayerQuery_x
FUNCTION_AT_ADDRESS(void CEverQuest::IssueLfgPlayerQuery(struct LfgPlayerQuery*), CEverQuest__IssueLfgPlayerQuery);
#endif
#ifdef CEverQuest__IssueLfgGroupQuery_x
FUNCTION_AT_ADDRESS(void CEverQuest::IssueLfgGroupQuery(struct LfgGroupQuery*), CEverQuest__IssueLfgGroupQuery);
#endif
#ifdef CEverQuest__IssuePetCommand_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CEverQuest::IssuePetCommand(ePetCommandType, int, bool, bool), CEverQuest__IssuePetCommand);
#else
FUNCTION_AT_ADDRESS(void CEverQuest::IssuePetCommand(ePetCommandType, int, bool), CEverQuest__IssuePetCommand);
#endif
#endif
#ifdef CEverQuest__LootCorpse_x
FUNCTION_AT_ADDRESS(int CEverQuest::LootCorpse(EQPlayer*, int), CEverQuest__LootCorpse);
#endif
#ifdef CEverQuest__loadSoundsGame_x
FUNCTION_AT_ADDRESS(void CEverQuest::loadSoundsGame(), CEverQuest__loadSoundsGame);
#endif
#ifdef CEverQuest__GetSingleMessage_x
FUNCTION_AT_ADDRESS(char* CEverQuest::GetSingleMessage(uint32_t, int, int*, char*), CEverQuest__GetSingleMessage);
#endif
#ifdef CEverQuest__SetGameState_x
FUNCTION_AT_ADDRESS(void CEverQuest::SetGameState(int), CEverQuest__SetGameState);
#endif
#ifdef CEverQuest__IsOkToTransact_x
FUNCTION_AT_ADDRESS(bool CEverQuest::IsOkToTransact(), CEverQuest__IsOkToTransact);
#endif
#ifdef CEverQuest__SortSpellLoadouts_x
FUNCTION_AT_ADDRESS(void CEverQuest::SortSpellLoadouts(), CEverQuest__SortSpellLoadouts);
#endif
#ifdef CEverQuest__saveCustom_x
FUNCTION_AT_ADDRESS(void CEverQuest::saveCustom(), CEverQuest__saveCustom);
#endif
#ifdef CEverQuest__loadCustomFromINI_x
FUNCTION_AT_ADDRESS(void CEverQuest::loadCustomFromINI(char*), CEverQuest__loadCustomFromINI);
#endif
#ifdef CEverQuest__loadCustom_x
FUNCTION_AT_ADDRESS(void CEverQuest::loadCustom(), CEverQuest__loadCustom);
#endif
#ifdef CEverQuest__initCustom_x
FUNCTION_AT_ADDRESS(void CEverQuest::initCustom(), CEverQuest__initCustom);
#endif
#ifdef _EverQuestinfo__SetAutoAttack_x
FUNCTION_AT_ADDRESS(void _EverQuestinfo::SetAutoAttack(bool), _EverQuestinfo__SetAutoAttack);
#endif
#ifdef KeypressHandler__KeypressHandler_x
FUNCTION_AT_ADDRESS(KeypressHandler::KeypressHandler(), KeypressHandler__KeypressHandler);
#endif
#ifdef KeypressHandler__AttachKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::AttachKeyToEqCommand(const KeyCombo&, unsigned int), KeypressHandler__AttachKeyToEqCommand);
#endif
#ifdef KeypressHandler__AttachAltKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::AttachAltKeyToEqCommand(const KeyCombo&, unsigned int), KeypressHandler__AttachAltKeyToEqCommand);
#endif
#ifdef KeypressHandler__HandleKeyDown_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::HandleKeyDown(const KeyCombo&), KeypressHandler__HandleKeyDown);
#endif
#ifdef KeypressHandler__HandleKeyUp_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::HandleKeyUp(const KeyCombo&), KeypressHandler__HandleKeyUp);
#endif
#ifdef KeypressHandler__Get_x
FUNCTION_AT_ADDRESS(KeypressHandler& KeypressHandler::Get(), KeypressHandler__Get);
#endif
#ifdef KeypressHandler__GetKeyAttachedToEqCommand_x
FUNCTION_AT_ADDRESS(const KeyCombo& KeypressHandler::GetKeyAttachedToEqCommand(unsigned int) const, KeypressHandler__GetKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__GetAltKeyAttachedToEqCommand_x
FUNCTION_AT_ADDRESS(const KeyCombo& KeypressHandler::GetAltKeyAttachedToEqCommand(unsigned int) const, KeypressHandler__GetAltKeyAttachedToEqCommand);
#endif
#ifdef KeypressHandler__ResetKeysToEqDefaults_x
FUNCTION_AT_ADDRESS(void KeypressHandler::ResetKeysToEqDefaults(), KeypressHandler__ResetKeysToEqDefaults);
#endif
#ifdef KeypressHandler__MapKeyToEqCommand_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::MapKeyToEqCommand(const KeyCombo&, int, unsigned int), KeypressHandler__MapKeyToEqCommand);
#endif
#ifdef KeypressHandler__IsReservedKey_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::IsReservedKey(const KeyCombo&) const, KeypressHandler__IsReservedKey);
#endif
#ifdef KeypressHandler__LoadAndSetKeymappings_x
FUNCTION_AT_ADDRESS(void KeypressHandler::LoadAndSetKeymappings(), KeypressHandler__LoadAndSetKeymappings);
#endif
#ifdef KeypressHandler__LoadKeymapping_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::LoadKeymapping(unsigned int, int, KeyCombo*), KeypressHandler__LoadKeymapping);
#endif
#ifdef KeypressHandler__SaveKeymapping_x
FUNCTION_AT_ADDRESS(void KeypressHandler::SaveKeymapping(unsigned int, KeyCombo const&, int), KeypressHandler__SaveKeymapping);
#endif
#ifdef KeypressHandler__GetEqCommandSaveName_x
FUNCTION_AT_ADDRESS(CXStr KeypressHandler::GetEqCommandSaveName(unsigned int, int) const, KeypressHandler__GetEqCommandSaveName);
#endif
#ifdef KeypressHandler__LoadAndConvertOldKeymappingFormat_x
FUNCTION_AT_ADDRESS(bool KeypressHandler::LoadAndConvertOldKeymappingFormat(unsigned int, int, KeyCombo*), KeypressHandler__LoadAndConvertOldKeymappingFormat);
#endif
#ifdef KeypressHandler__ClearCommandStateArray_x
FUNCTION_AT_ADDRESS(void KeypressHandler::ClearCommandStateArray(), KeypressHandler__ClearCommandStateArray);
#endif
#ifdef CResolutionHandler__Init_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::Init(), CResolutionHandler__Init);
#endif
#ifdef CResolutionHandler__Shutdown_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::Shutdown(), CResolutionHandler__Shutdown);
#endif
#ifdef CResolutionHandler__SaveSettings_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::SaveSettings(), CResolutionHandler__SaveSettings);
#endif
#ifdef CResolutionHandler__ToggleScreenMode_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ToggleScreenMode(), CResolutionHandler__ToggleScreenMode);
#endif
#ifdef CResolutionHandler__ChangeToResolution_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::ChangeToResolution(int, int, int, int, int), CResolutionHandler__ChangeToResolution);
#endif
#ifdef CResolutionHandler__UpdateWindowPosition_x
FUNCTION_AT_ADDRESS(void __cdecl CResolutionHandler::UpdateWindowPosition(), CResolutionHandler__UpdateWindowPosition);
#endif
#ifdef CResolutionHandler__UpdateResolution_x
FUNCTION_AT_ADDRESS(void CResolutionHandler::UpdateResolution(ResolutionUpdateData& data), CResolutionHandler__UpdateResolution);
#endif
#ifdef CResolutionHandler__GetWindowedStyle_x
FUNCTION_AT_ADDRESS(DWORD CResolutionHandler::GetWindowedStyle() const, CResolutionHandler__GetWindowedStyle);
#endif
#ifdef CResolutionHandler__GetDesktopWidth_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopWidth(), CResolutionHandler__GetDesktopWidth);
#endif
#ifdef CResolutionHandler__GetDesktopHeight_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopHeight(), CResolutionHandler__GetDesktopHeight);
#endif
#ifdef CResolutionHandler__GetDesktopBitsPerPixel_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopBitsPerPixel(), CResolutionHandler__GetDesktopBitsPerPixel);
#endif
#ifdef CResolutionHandler__GetDesktopRefreshRate_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetDesktopRefreshRate(), CResolutionHandler__GetDesktopRefreshRate);
#endif
#ifdef CResolutionHandler__GetWidth_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetWidth(), CResolutionHandler__GetWidth);
#endif
#ifdef CResolutionHandler__GetHeight_x
FUNCTION_AT_ADDRESS(int __cdecl CResolutionHandler::GetHeight(), CResolutionHandler__GetHeight);
#endif
#ifdef CResolutionHandler__IsFullscreenAvailable_x
FUNCTION_AT_ADDRESS(bool __cdecl CResolutionHandler::IsFullscreenAvailable(), CResolutionHandler__IsFullscreenAvailable);
#endif
#ifdef Util__AllocateString_x
FUNCTION_AT_ADDRESS(char* __cdecl Util::AllocateString(char*), Util__AllocateString);
#endif
#ifdef SoundManager__dSoundManager_x
FUNCTION_AT_ADDRESS(SoundManager::~SoundManager(), SoundManager__dSoundManager);
#endif
#ifdef SoundManager__GiveTime_x
FUNCTION_AT_ADDRESS(void SoundManager::GiveTime(), SoundManager__GiveTime);
#endif
#ifdef SoundManager__SetMixAhead_x
FUNCTION_AT_ADDRESS(void SoundManager::SetMixAhead(int), SoundManager__SetMixAhead);
#endif
#ifdef SoundManager__SetListenerLocation_x
FUNCTION_AT_ADDRESS(void SoundManager::SetListenerLocation(float, float, float, float), SoundManager__SetListenerLocation);
#endif
#ifdef SoundManager__GetListenerLocation_x
FUNCTION_AT_ADDRESS(void SoundManager::GetListenerLocation(float*, float*, float*, float*), SoundManager__GetListenerLocation);
#endif
#ifdef SoundManager__ReturnInstance_x
FUNCTION_AT_ADDRESS(void SoundManager::ReturnInstance(SoundInstance*), SoundManager__ReturnInstance);
#endif
#ifdef SoundManager__AssetGiveTime_x
FUNCTION_AT_ADDRESS(void SoundManager::AssetGiveTime(), SoundManager__AssetGiveTime);
#endif
#ifdef SoundManager__AssetAdd_x
FUNCTION_AT_ADDRESS(void SoundManager::AssetAdd(SoundAsset*), SoundManager__AssetAdd);
#endif
#ifdef SoundManager__AssetRemove_x
FUNCTION_AT_ADDRESS(void SoundManager::AssetRemove(SoundAsset*), SoundManager__AssetRemove);
#endif
#ifdef SoundManager__AssetGet_x
FUNCTION_AT_ADDRESS(SoundAsset* SoundManager::AssetGet(char*), SoundManager__AssetGet);
#endif
#ifdef SoundManager__StreamingPlay_x
FUNCTION_AT_ADDRESS(void SoundManager::StreamingPlay(char*), SoundManager__StreamingPlay);
#endif
#ifdef SoundManager__StreamingPause_x
FUNCTION_AT_ADDRESS(void SoundManager::StreamingPause(), SoundManager__StreamingPause);
#endif
#ifdef SoundManager__StreamingStop_x
FUNCTION_AT_ADDRESS(void SoundManager::StreamingStop(), SoundManager__StreamingStop);
#endif
#ifdef SoundManager__StreamingSetVolumeLevel_x
FUNCTION_AT_ADDRESS(void SoundManager::StreamingSetVolumeLevel(float), SoundManager__StreamingSetVolumeLevel);
#endif
#ifdef SoundManager__StreamingGetVolumeLevel_x
FUNCTION_AT_ADDRESS(float SoundManager::StreamingGetVolumeLevel(), SoundManager__StreamingGetVolumeLevel);
#endif
#ifdef SoundManager__StreamingSetSongPosition_x
FUNCTION_AT_ADDRESS(void SoundManager::StreamingSetSongPosition(int), SoundManager__StreamingSetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongPosition_x
FUNCTION_AT_ADDRESS(int SoundManager::StreamingGetSongPosition(), SoundManager__StreamingGetSongPosition);
#endif
#ifdef SoundManager__StreamingGetSongLength_x
FUNCTION_AT_ADDRESS(int SoundManager::StreamingGetSongLength(), SoundManager__StreamingGetSongLength);
#endif
#ifdef WaveInstance__WaveInstance_x
FUNCTION_AT_ADDRESS(WaveInstance::WaveInstance(SoundManager*), WaveInstance__WaveInstance);
#endif
#ifdef Wave3dInstance__Wave3dInstance_x
FUNCTION_AT_ADDRESS(Wave3dInstance::Wave3dInstance(SoundManager*), Wave3dInstance__Wave3dInstance);
#endif
#ifdef Mp3Manager__Mp3Manager_x
FUNCTION_AT_ADDRESS(Mp3Manager::Mp3Manager(SoundManager*, MusicManager*), Mp3Manager__Mp3Manager);
#endif
#ifdef Mp3Manager__dMp3Manager_x
FUNCTION_AT_ADDRESS(Mp3Manager::~Mp3Manager(), Mp3Manager__dMp3Manager);
#endif
#ifdef Mp3Manager__Stop_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Stop(), Mp3Manager__Stop);
#endif
#ifdef Mp3Manager__Play_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Play(), Mp3Manager__Play);
#endif
#ifdef Mp3Manager__Pause_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Pause(), Mp3Manager__Pause);
#endif
#ifdef Mp3Manager__GiveTime_x
FUNCTION_AT_ADDRESS(void Mp3Manager::GiveTime(), Mp3Manager__GiveTime);
#endif
#ifdef Mp3Manager__Next_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Next(), Mp3Manager__Next);
#endif
#ifdef Mp3Manager__Back_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Back(), Mp3Manager__Back);
#endif
#ifdef Mp3Manager__GetSongLength_x
FUNCTION_AT_ADDRESS(int Mp3Manager::GetSongLength(), Mp3Manager__GetSongLength);
#endif
#ifdef Mp3Manager__GetSongPosition_x
FUNCTION_AT_ADDRESS(int Mp3Manager::GetSongPosition(), Mp3Manager__GetSongPosition);
#endif
#ifdef Mp3Manager__SetSongPosition_x
FUNCTION_AT_ADDRESS(void Mp3Manager::SetSongPosition(int), Mp3Manager__SetSongPosition);
#endif
#ifdef Mp3Manager__GetName_x
FUNCTION_AT_ADDRESS(char* Mp3Manager::GetName(int), Mp3Manager__GetName);
#endif
#ifdef Mp3Manager__Count_x
FUNCTION_AT_ADDRESS(int Mp3Manager::Count(), Mp3Manager__Count);
#endif
#ifdef Mp3Manager__SetPosition_x
FUNCTION_AT_ADDRESS(void Mp3Manager::SetPosition(int), Mp3Manager__SetPosition);
#endif
#ifdef Mp3Manager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void Mp3Manager::SetVolumeLevel(float), Mp3Manager__SetVolumeLevel);
#endif
#ifdef Mp3Manager__GetVolumeLevel_x
FUNCTION_AT_ADDRESS(float Mp3Manager::GetVolumeLevel(), Mp3Manager__GetVolumeLevel);
#endif
#ifdef Mp3Manager__DeleteAll_x
FUNCTION_AT_ADDRESS(void Mp3Manager::DeleteAll(), Mp3Manager__DeleteAll);
#endif
#ifdef Mp3Manager__Delete_x
FUNCTION_AT_ADDRESS(void Mp3Manager::Delete(int), Mp3Manager__Delete);
#endif
#ifdef Mp3Manager__SaveList_x
FUNCTION_AT_ADDRESS(void Mp3Manager::SaveList(char*), Mp3Manager__SaveList);
#endif
#ifdef Mp3Manager__Add_x
FUNCTION_AT_ADDRESS(int Mp3Manager::Add(char*), Mp3Manager__Add);
#endif
#ifdef Mp3Manager__InternalAdd_x
FUNCTION_AT_ADDRESS(int Mp3Manager::InternalAdd(char*, char*, int), Mp3Manager__InternalAdd);
#endif
#ifdef ActorClient__GetPosition_x
FUNCTION_AT_ADDRESS(const CVector3& ActorClient::GetPosition() const, ActorClient__GetPosition);
#endif
#ifdef ActorClient__GetPosition1_x
FUNCTION_AT_ADDRESS(void ActorClient::GetPosition(CVector3*) const, ActorClient__GetPosition1);
#endif
#ifdef EmitterManager__EmitterManager_x
FUNCTION_AT_ADDRESS(EmitterManager::EmitterManager(SoundManager*), EmitterManager__EmitterManager);
#endif
#ifdef EmitterManager__dEmitterManager_x
FUNCTION_AT_ADDRESS(EmitterManager::~EmitterManager(), EmitterManager__dEmitterManager);
#endif
#ifdef EmitterManager__GiveTime_x
FUNCTION_AT_ADDRESS(void EmitterManager::GiveTime(), EmitterManager__GiveTime);
#endif
#ifdef EmitterManager__GetEffectsLevel_x
FUNCTION_AT_ADDRESS(float EmitterManager::GetEffectsLevel(), EmitterManager__GetEffectsLevel);
#endif
#ifdef EmitterManager__GetVolumeLevel_x
FUNCTION_AT_ADDRESS(float EmitterManager::GetVolumeLevel(), EmitterManager__GetVolumeLevel);
#endif
#ifdef EmitterManager__SetEffectsLevel_x
FUNCTION_AT_ADDRESS(void EmitterManager::SetEffectsLevel(float), EmitterManager__SetEffectsLevel);
#endif
#ifdef EmitterManager__GetListenerLocation_x
FUNCTION_AT_ADDRESS(void EmitterManager::GetListenerLocation(float*, float*, float*, float*), EmitterManager__GetListenerLocation);
#endif
#ifdef MusicManager__MusicManager_x
FUNCTION_AT_ADDRESS(MusicManager::MusicManager(), MusicManager__MusicManager);
#endif
#ifdef MusicManager__dMusicManager_x
FUNCTION_AT_ADDRESS(MusicManager::~MusicManager(), MusicManager__dMusicManager);
#endif
#ifdef MusicManager__GiveTime_x
FUNCTION_AT_ADDRESS(void MusicManager::GiveTime(), MusicManager__GiveTime);
#endif
#ifdef MusicManager__Clear_x
FUNCTION_AT_ADDRESS(void MusicManager::Clear(SoundAsset*), MusicManager__Clear);
#endif
#ifdef MusicManager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void MusicManager::SetVolumeLevel(float), MusicManager__SetVolumeLevel);
#endif
#ifdef MusicManager__Clear1_x
FUNCTION_AT_ADDRESS(void MusicManager::Clear(int), MusicManager__Clear1);
#endif
#ifdef MusicManager__Set_x
FUNCTION_AT_ADDRESS(void MusicManager::Set(int, SoundAsset*, int, float, int, int, int, int, int, int), MusicManager__Set);
#endif
#ifdef MusicManager__Play_x
FUNCTION_AT_ADDRESS(void MusicManager::Play(int), MusicManager__Play);
#endif
#ifdef MusicManager__Stop_x
FUNCTION_AT_ADDRESS(void MusicManager::Stop(int), MusicManager__Stop);
#endif
#ifdef MusicManager__Enable_x
FUNCTION_AT_ADDRESS(void MusicManager::Enable(bool), MusicManager__Enable);
#endif
#ifdef SpellManager__SpellManager_x
FUNCTION_AT_ADDRESS(SpellManager::SpellManager(char*), SpellManager__SpellManager);
#endif
#ifdef SpellManager__dSpellManager_x
FUNCTION_AT_ADDRESS(SpellManager::~SpellManager(), SpellManager__dSpellManager);
#endif
#ifdef SpellManager__GetSpellByGroupAndRank_x
FUNCTION_AT_ADDRESS(const EQ_Spell* SpellManager::GetSpellByGroupAndRank(int Group, int SubGroup, int Rank, bool bLesserRanksOk), SpellManager__GetSpellByGroupAndRank);
#endif
#ifdef CStoryWnd__CStoryWnd_x
FUNCTION_AT_ADDRESS(CStoryWnd::CStoryWnd(CXWnd*), CStoryWnd__CStoryWnd);
#endif
#ifdef CStoryWnd__Init_x
FUNCTION_AT_ADDRESS(void CStoryWnd::Init(), CStoryWnd__Init);
#endif
#ifdef CStoryWnd__SaveIni_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SaveIni(), CStoryWnd__SaveIni);
#endif
#ifdef CStoryWnd__ShowAuto_x
FUNCTION_AT_ADDRESS(bool CStoryWnd::ShowAuto(), CStoryWnd__ShowAuto);
#endif
#ifdef CStoryWnd__HasNew_x
FUNCTION_AT_ADDRESS(bool CStoryWnd::HasNew(), CStoryWnd__HasNew);
#endif
#ifdef CStoryWnd__Activate_x
FUNCTION_AT_ADDRESS(void CStoryWnd::Activate(), CStoryWnd__Activate);
#endif
#ifdef CStoryWnd__SelectOldestNew_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SelectOldestNew(), CStoryWnd__SelectOldestNew);
#endif
#ifdef CStoryWnd__SelectIndex_x
FUNCTION_AT_ADDRESS(void CStoryWnd::SelectIndex(int), CStoryWnd__SelectIndex);
#endif
#ifdef StringTable__getString_x
FUNCTION_AT_ADDRESS(char* StringTable::getString(unsigned long, bool*), StringTable__getString);
#endif
#ifdef Mp3Manager__GetPosition_x
FUNCTION_AT_ADDRESS(int Mp3Manager::GetPosition(), Mp3Manager__GetPosition);
#endif
#ifdef EmitterManager__SetVolumeLevel_x
FUNCTION_AT_ADDRESS(void EmitterManager::SetVolumeLevel(float), EmitterManager__SetVolumeLevel);
#endif
#ifdef CRadioGroup__CRadioGroup_x
FUNCTION_AT_ADDRESS(CRadioGroup::CRadioGroup(CXStr), CRadioGroup__CRadioGroup);
#endif
#ifdef CRadioGroup__GetName_x
FUNCTION_AT_ADDRESS(CXStr CRadioGroup::GetName() const, CRadioGroup__GetName);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate::CXWndDrawTemplate(), CXWndDrawTemplate__CXWndDrawTemplate);
#endif
#ifdef CUITextureInfo__CUITextureInfo1_x
FUNCTION_AT_ADDRESS(CUITextureInfo::CUITextureInfo(), CUITextureInfo__CUITextureInfo1);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate::CButtonDrawTemplate(), CButtonDrawTemplate__CButtonDrawTemplate);
#endif
#ifdef CScrollbarTemplate__dCScrollbarTemplate_x
FUNCTION_AT_ADDRESS(CScrollbarTemplate::~CScrollbarTemplate(), CScrollbarTemplate__dCScrollbarTemplate);
#endif
#ifdef CXWndDrawTemplate__dCXWndDrawTemplate_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate::~CXWndDrawTemplate(), CXWndDrawTemplate__dCXWndDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__GetSize_x
FUNCTION_AT_ADDRESS(CXSize CButtonDrawTemplate::GetSize() const, CButtonDrawTemplate__GetSize);
#endif
#ifdef CXRect__CXRect_x
FUNCTION_AT_ADDRESS(CXRect::CXRect(int, int, int, int), CXRect__CXRect);
#endif
#ifdef CXRect__operator_equal_x
FUNCTION_AT_ADDRESS(CXRect& CXRect::operator=(const CXRect&), CXRect__operator_equal);
#endif
#ifdef CXPoint__operator_equal_x
FUNCTION_AT_ADDRESS(CXPoint CXPoint::operator=(CXPoint), CXPoint__operator_equal);
#endif
#ifdef CMutexSyncCounted__CMutexSyncCounted_x
FUNCTION_AT_ADDRESS(CMutexSyncCounted::CMutexSyncCounted(), CMutexSyncCounted__CMutexSyncCounted);
#endif
#ifdef CMutexSyncCounted__dCMutexSyncCounted_x
FUNCTION_AT_ADDRESS(CMutexSyncCounted::~CMutexSyncCounted(), CMutexSyncCounted__dCMutexSyncCounted);
#endif
#ifdef CMutexLockCounted__dCMutexLockCounted_x
FUNCTION_AT_ADDRESS(CMutexLockCounted::~CMutexLockCounted(), CMutexLockCounted__dCMutexLockCounted);
#endif
#ifdef CListWnd__CListWnd_x
CONSTRUCTOR_AT_ADDRESS(CListWnd::CListWnd(CXWnd*, uint32_t, CXRect const&), CListWnd__CListWnd);
#endif
#ifdef CListWnd__dCListWnd_x
FUNCTION_AT_ADDRESS(CListWnd::~CListWnd(), CListWnd__dCListWnd);
#endif
#ifdef CListWnd__GetCurSel_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurSel() const, CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurCol() const, CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData_x
#if !defined(ROF2EMU) && !defined(UFEMU) 
FUNCTION_AT_ADDRESS(uint64_t CListWnd::GetItemData(int) const, CListWnd__GetItemData);
#else
FUNCTION_AT_ADDRESS(uint32_t CListWnd::GetItemData(int) const, CListWnd__GetItemData);
#endif
#endif
#ifdef CListWnd__GetItemText_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetItemText(const CXStr&, int, int) const, CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetItemIcon(int, int) const, CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor_x
FUNCTION_AT_ADDRESS(unsigned long CListWnd::GetItemColor(int, int) const, CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags_x
FUNCTION_AT_ADDRESS(uint32_t CListWnd::GetColumnFlags(int) const, CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnWidth(int) const, CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnWidth(int, int), CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator_x
FUNCTION_AT_ADDRESS(void CListWnd::ShiftColumnSeparator(int, int), CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnMinWidth(int) const, CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnTooltip_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnTooltip(int) const, CListWnd__GetColumnTooltip);
#endif
#ifdef CListWnd__GetColumnJustification_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnJustification(int) const, CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnJustification(int, int), CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnLabel(int) const, CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimation(int) const, CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationSelected(int) const, CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationMouseOver(int) const, CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine_x
FUNCTION_AT_ADDRESS(int CListWnd::AddLine(SListWndLine*), CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CListWnd::AddString(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr), CListWnd__AddString);
#else
FUNCTION_AT_ADDRESS(int CListWnd::AddString(const CXStr& Str, COLORREF Color, uint32_t Data, const CTextureAnimation* pTa, const char* TooltipStr), CListWnd__AddString);
#endif
#endif
#ifdef CListWnd__RemoveString_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveString(int), CListWnd__RemoveString);
#endif
#ifdef CListWnd__InsertLine_x
FUNCTION_AT_ADDRESS(void CListWnd::InsertLine(int ID, SListWndLine* rEntry), CListWnd__InsertLine);
#endif
#ifdef CListWnd__RemoveLine_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveLine(int), CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetCurSel(int), CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ToggleSel(int), CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ExtendSel(int), CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearAllSel(), CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearSel(int), CListWnd__ClearSel);
#endif
#ifdef CListWnd__DrawColumnSeparators_x
FUNCTION_AT_ADDRESS(int CListWnd::DrawColumnSeparators() const, CListWnd__DrawColumnSeparators);
#endif
#ifdef CListWnd__SetColumnsSizable_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnsSizable(bool), CListWnd__SetColumnsSizable);
#endif
#ifdef CListWnd__GetItemWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CListWnd::GetItemWnd(int Index, int SubItem) const, CListWnd__GetItemWnd);
#endif
#ifdef CListWnd__SetItemIcon_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation* pTA), CListWnd__SetItemIcon);
#endif
#ifdef CListWnd__CalculateCustomWindowPositions_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateCustomWindowPositions(), CListWnd__CalculateCustomWindowPositions);
#endif
#ifdef CListWnd__SetVScrollPos_x
FUNCTION_AT_ADDRESS(int CListWnd::SetVScrollPos(int), CListWnd__SetVScrollPos);
#endif
#ifdef CListWnd__SetItemWnd_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd* pWnd), CListWnd__SetItemWnd);
#endif
#ifdef CListWnd__SetItemData_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CListWnd::SetItemData(int, uint64_t), CListWnd__SetItemData);
#else
FUNCTION_AT_ADDRESS(void CListWnd::SetItemData(int, uint32_t), CListWnd__SetItemData);
#endif
#endif
#ifdef CListWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemText(int, int, const CXStr&), CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemColor(int, int, unsigned long), CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled_x
FUNCTION_AT_ADDRESS(bool CListWnd::IsLineEnabled(int) const, CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine_x
FUNCTION_AT_ADDRESS(void CListWnd::EnableLine(int, bool), CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr&, int, uint32_t, uint32_t), CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr& Label, CTextureAnimation* pTA, int Width, uint32_t Flags, CXStr Tooltip, uint32_t Type, CTextureAnimation* pTASelected, CTextureAnimation* pTAMouseOver, bool bResizeable, tagSIZE TextureSize, tagPOINT TextureOffset), CListWnd__AddColumn1);
#endif
#ifdef CListWnd__SetColumnLabel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnLabel(int, CXStr), CListWnd__SetColumnLabel);
#endif
#ifdef CXRect__CXRect1_x
FUNCTION_AT_ADDRESS(CXRect::CXRect(), CXRect__CXRect1);
#endif
#ifdef CListWnd__GetItemHeight_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemHeight(int) const, CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateLineHeights(), CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateVSBRange(), CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateFirstVisibleLine(), CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible_x
FUNCTION_AT_ADDRESS(void CListWnd::EnsureVisible(int), CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetItemRect(int, int) const, CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemAtPoint(const CXPoint&) const, CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1_x
FUNCTION_AT_ADDRESS(void CListWnd::GetItemAtPoint(const CXPoint&, int*, int*) const, CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow_x
FUNCTION_AT_ADDRESS(void CListWnd::CloseAndUpdateEditWindow(), CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColors(unsigned long, unsigned long, unsigned long), CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetSeparatorRect(int) const, CListWnd__GetSeparatorRect);
#endif
#ifdef SListWndSortInfo__dSListWndSortInfo_x
FUNCTION_AT_ADDRESS(SListWndSortInfo::~SListWndSortInfo(), SListWndSortInfo__dSListWndSortInfo);
#endif
#ifdef CListWnd__GetHeaderRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetHeaderRect(int) const, CListWnd__GetHeaderRect);
#endif
#ifdef CScreenPieceTemplate__CScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate::CScreenPieceTemplate(CParamScreenPiece*), CScreenPieceTemplate__CScreenPieceTemplate);
#endif
#ifdef CScreenPieceTemplate__IsType_x
FUNCTION_AT_ADDRESS(bool CScreenPieceTemplate::IsType(uint32_t) const, CScreenPieceTemplate__IsType);
#endif
#ifdef CStaticScreenPieceTemplate__CStaticScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(CStaticScreenPieceTemplate::CStaticScreenPieceTemplate(CParamStaticScreenPiece*), CStaticScreenPieceTemplate__CStaticScreenPieceTemplate);
#endif
#ifdef CStaticAnimationTemplate__CStaticAnimationTemplate_x
FUNCTION_AT_ADDRESS(CStaticAnimationTemplate::CStaticAnimationTemplate(CParamStaticAnimation*), CStaticAnimationTemplate__CStaticAnimationTemplate);
#endif
#ifdef CStaticTextTemplate__CStaticTextTemplate_x
FUNCTION_AT_ADDRESS(CStaticTextTemplate::CStaticTextTemplate(CParamStaticText*), CStaticTextTemplate__CStaticTextTemplate);
#endif
#ifdef CStaticTextTemplate__SetText_x
FUNCTION_AT_ADDRESS(CXStr CStaticTextTemplate::SetText(CXStr), CStaticTextTemplate__SetText);
#endif
#ifdef CStaticFrameTemplate__CStaticFrameTemplate_x
FUNCTION_AT_ADDRESS(CStaticFrameTemplate::CStaticFrameTemplate(CParamStaticFrame*), CStaticFrameTemplate__CStaticFrameTemplate);
#endif
#ifdef CStaticHeaderTemplate__CStaticHeaderTemplate_x
FUNCTION_AT_ADDRESS(CStaticHeaderTemplate::CStaticHeaderTemplate(CParamStaticHeader*), CStaticHeaderTemplate__CStaticHeaderTemplate);
#endif
#ifdef CControlTemplate__CControlTemplate_x
FUNCTION_AT_ADDRESS(CControlTemplate::CControlTemplate(CParamControl*), CControlTemplate__CControlTemplate);
#endif
#ifdef CListboxColumnTemplate__CListboxColumnTemplate_x
FUNCTION_AT_ADDRESS(CListboxColumnTemplate::CListboxColumnTemplate(CParamListboxColumn*), CListboxColumnTemplate__CListboxColumnTemplate);
#endif
#ifdef CListboxTemplate__CListboxTemplate_x
FUNCTION_AT_ADDRESS(CListboxTemplate::CListboxTemplate(CParamListbox*), CListboxTemplate__CListboxTemplate);
#endif
#ifdef CListboxColumnTemplate__dCListboxColumnTemplate_x
FUNCTION_AT_ADDRESS(CListboxColumnTemplate::~CListboxColumnTemplate(), CListboxColumnTemplate__dCListboxColumnTemplate);
#endif
#ifdef CButtonTemplate__CButtonTemplate_x
FUNCTION_AT_ADDRESS(CButtonTemplate::CButtonTemplate(CParamButton*), CButtonTemplate__CButtonTemplate);
#endif
#ifdef CGaugeTemplate__CGaugeTemplate_x
FUNCTION_AT_ADDRESS(CGaugeTemplate::CGaugeTemplate(CParamGauge*), CGaugeTemplate__CGaugeTemplate);
#endif
#ifdef CSpellGemTemplate__CSpellGemTemplate_x
FUNCTION_AT_ADDRESS(CSpellGemTemplate::CSpellGemTemplate(CParamSpellGem*), CSpellGemTemplate__CSpellGemTemplate);
#endif
#ifdef CInvSlotTemplate__CInvSlotTemplate_x
FUNCTION_AT_ADDRESS(CInvSlotTemplate::CInvSlotTemplate(CParamInvSlot*), CInvSlotTemplate__CInvSlotTemplate);
#endif
#ifdef CEditboxTemplate__CEditboxTemplate_x
FUNCTION_AT_ADDRESS(CEditboxTemplate::CEditboxTemplate(CParamEditbox*), CEditboxTemplate__CEditboxTemplate);
#endif
#ifdef CSliderTemplate__CSliderTemplate_x
FUNCTION_AT_ADDRESS(CSliderTemplate::CSliderTemplate(CParamSlider*), CSliderTemplate__CSliderTemplate);
#endif
#ifdef CLabelTemplate__CLabelTemplate_x
FUNCTION_AT_ADDRESS(CLabelTemplate::CLabelTemplate(CParamLabel*), CLabelTemplate__CLabelTemplate);
#endif
#ifdef CLargeDialogWnd__Open_x
FUNCTION_AT_ADDRESS(void CLargeDialogWnd::Open(bool bYesNoEnabled, CXStr DialogText, unsigned long closeTimer/*0 means never*/, CXStr DialogTitle, bool bShowVolumeControls, CXStr YesText, CXStr NoText), CLargeDialogWnd__Open);
#endif
#ifdef CWndDisplayManager__FindWindowA_x
FUNCTION_AT_ADDRESS(int CWndDisplayManager::FindWindow(bool bNewWnd), CWndDisplayManager__FindWindowA);
#endif
#ifdef CItemDisplayManager__CreateWindowInstance_x
FUNCTION_AT_ADDRESS(int CItemDisplayManager::CreateWindowInstance(), CItemDisplayManager__CreateWindowInstance);
#endif
#ifdef CSTMLboxTemplate__CSTMLboxTemplate_x
FUNCTION_AT_ADDRESS(CSTMLboxTemplate::CSTMLboxTemplate(CParamSTMLbox*), CSTMLboxTemplate__CSTMLboxTemplate);
#endif
#ifdef CComboboxTemplate__CComboboxTemplate_x
FUNCTION_AT_ADDRESS(CComboboxTemplate::CComboboxTemplate(CParamCombobox*), CComboboxTemplate__CComboboxTemplate);
#endif
#ifdef CPageTemplate__CPageTemplate_x
FUNCTION_AT_ADDRESS(CPageTemplate::CPageTemplate(CParamPage*), CPageTemplate__CPageTemplate);
#endif
#ifdef CTabBoxTemplate__CTabBoxTemplate_x
FUNCTION_AT_ADDRESS(CTabBoxTemplate::CTabBoxTemplate(CParamTabBox*), CTabBoxTemplate__CTabBoxTemplate);
#endif
#ifdef CScreenTemplate__CScreenTemplate_x
FUNCTION_AT_ADDRESS(CScreenTemplate::CScreenTemplate(CParamScreen*), CScreenTemplate__CScreenTemplate);
#endif
#ifdef CStmlWnd__CStmlWnd_x
FUNCTION_AT_ADDRESS(CStmlWnd::CStmlWnd(CXWnd*, uint32_t, CXRect), CStmlWnd__CStmlWnd);
#endif
#ifdef CStmlWnd__InitializeTextLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeTextLine(SParseVariables*, int), CStmlWnd__InitializeTextLine);
#endif
#ifdef CStmlWnd__AddTextPieceToLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::AddTextPieceToLine(SParseVariables*), CStmlWnd__AddTextPieceToLine);
#endif
#ifdef CStmlWnd__MakeStmlColorTag_x
FUNCTION_AT_ADDRESS(CXStr __cdecl CStmlWnd::MakeStmlColorTag(unsigned long), CStmlWnd__MakeStmlColorTag);
#endif
#ifdef CTextureAnimation__GetName_x
FUNCTION_AT_ADDRESS(CXStr CTextureAnimation::GetName() const, CTextureAnimation__GetName);
#endif
#ifdef CStmlWnd__MakeWndNotificationTag_x
FUNCTION_AT_ADDRESS(CXStr CStmlWnd::MakeWndNotificationTag(uint32_t, const CXStr&, const CXStr&), CStmlWnd__MakeWndNotificationTag);
#endif
#ifdef CStmlWnd__ParseTagColor_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseTagColor(CXStr, unsigned long*) const, CStmlWnd__ParseTagColor);
#endif
#ifdef CStmlWnd__ParseTagFace_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseTagFace(CXStr, CTextureFont const**) const, CStmlWnd__ParseTagFace);
#endif
#ifdef SAmpersandEntry__SAmpersandEntry_x
FUNCTION_AT_ADDRESS(SAmpersandEntry::SAmpersandEntry(CXStr, char), SAmpersandEntry__SAmpersandEntry);
#endif
#ifdef CButtonDrawTemplate__dCButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate::~CButtonDrawTemplate(), CButtonDrawTemplate__dCButtonDrawTemplate);
#endif
#ifdef CGaugeDrawTemplate__dCGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS(CGaugeDrawTemplate::~CGaugeDrawTemplate(), CGaugeDrawTemplate__dCGaugeDrawTemplate);
#endif
#ifdef CSpellGemDrawTemplate__dCSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS(CSpellGemDrawTemplate::~CSpellGemDrawTemplate(), CSpellGemDrawTemplate__dCSpellGemDrawTemplate);
#endif
#ifdef CTAFrameDraw__dCTAFrameDraw_x
FUNCTION_AT_ADDRESS(CTAFrameDraw::~CTAFrameDraw(), CTAFrameDraw__dCTAFrameDraw);
#endif
#ifdef SAmpersandEntry__dSAmpersandEntry_x
FUNCTION_AT_ADDRESS(SAmpersandEntry::~SAmpersandEntry(), SAmpersandEntry__dSAmpersandEntry);
#endif
#ifdef CStmlWnd__ParseAmpersand_x
FUNCTION_AT_ADDRESS(bool CStmlWnd::ParseAmpersand(CXStr&, char*) const, CStmlWnd__ParseAmpersand);
#endif
#ifdef CStmlWnd__FastForwardPastSpaces_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastSpaces(CXStr&, int*), CStmlWnd__FastForwardPastSpaces);
#endif
#ifdef CStmlWnd__FastForwardPastSpacesAndQuotes_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastSpacesAndQuotes(CXStr&, int*), CStmlWnd__FastForwardPastSpacesAndQuotes);
#endif
#ifdef CStmlWnd__GetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetNextTagPiece(const CXStr&, CXStr*, int*, bool (*)(unsigned short), bool), CStmlWnd__GetNextTagPiece);
#endif
#ifdef CStmlWnd__IsCharacterNotQuotes_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotQuotes(unsigned short), CStmlWnd__IsCharacterNotQuotes);
#endif
#ifdef CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardPastQuotesAndGetNextTagPiece(CXStr&, CXStr*, int*, bool), CStmlWnd__FastForwardPastQuotesAndGetNextTagPiece);
#endif
#ifdef CStmlWnd__FastForwardToEndOfTag_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::FastForwardToEndOfTag(const CXStr&, CXStr*, int*, char), CStmlWnd__FastForwardToEndOfTag);
#endif
#ifdef CStmlWnd__InitializeTempVariables_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeTempVariables(SParseVariables*, CXRect), CStmlWnd__InitializeTempVariables);
#endif
#ifdef CStmlWnd__InitializeWindowVariables_x
FUNCTION_AT_ADDRESS(void CStmlWnd::InitializeWindowVariables(), CStmlWnd__InitializeWindowVariables);
#endif
#ifdef CStmlWnd__ResetTempVariablesForNewLine_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ResetTempVariablesForNewLine(SParseVariables*), CStmlWnd__ResetTempVariablesForNewLine);
#endif
#ifdef CStmlWnd__GetNextChar_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetNextChar(int*, CXStr&), CStmlWnd__GetNextChar);
#endif
#ifdef CStmlWnd__GetThisChar_x
FUNCTION_AT_ADDRESS(unsigned short CStmlWnd::GetThisChar(int, CXStr&), CStmlWnd__GetThisChar);
#endif
#ifdef CStmlWnd__IsCharacterNotEquals_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotEquals(unsigned short), CStmlWnd__IsCharacterNotEquals);
#endif
#ifdef CStmlWnd__IsCharacterNotASpaceAndNotNULL_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::IsCharacterNotASpaceAndNotNULL(unsigned short), CStmlWnd__IsCharacterNotASpaceAndNotNULL);
#endif
#ifdef CStmlWnd__ParseSTMLHead_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLHead(CXStr&), CStmlWnd__ParseSTMLHead);
#endif
#ifdef CStmlWnd__ParseSTMLTable_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLTable(CXStr&, int*, CXStr&, SParseVariables*), CStmlWnd__ParseSTMLTable);
#endif
#ifdef CStmlWnd__ParseSTMLTableAttributes_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ParseSTMLTableAttributes(CXStr, STable*), CStmlWnd__ParseSTMLTableAttributes);
#endif
#ifdef CStmlWnd__GetVisibleText_x
FUNCTION_AT_ADDRESS(CXStr CStmlWnd::GetVisibleText(CXStr, const CXRect&) const, CStmlWnd__GetVisibleText);
#endif
#ifdef CStmlWnd__ForceParseNow_x
FUNCTION_AT_ADDRESS(void CStmlWnd::ForceParseNow(), CStmlWnd__ForceParseNow);
#endif
#ifdef CStmlWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CalculateVSBRange(int), CStmlWnd__CalculateVSBRange);
#endif
#ifdef CStmlWnd__CalculateHSBRange_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CalculateHSBRange(int), CStmlWnd__CalculateHSBRange);
#endif
#ifdef CStmlReport__GetReport_x
FUNCTION_AT_ADDRESS(CXStr CStmlReport::GetReport() const, CStmlReport__GetReport);
#endif
#ifdef CStmlWnd__CompleteParse_x
FUNCTION_AT_ADDRESS(void CStmlWnd::CompleteParse(), CStmlWnd__CompleteParse);
#endif
#ifdef CStmlWnd__StripFirstSTMLLines_x
FUNCTION_AT_ADDRESS(void CStmlWnd::StripFirstSTMLLines(int), CStmlWnd__StripFirstSTMLLines);
#endif
#ifdef CStmlWnd__CanBreakAtCharacter_x
FUNCTION_AT_ADDRESS(bool __cdecl CStmlWnd::CanBreakAtCharacter(unsigned short), CStmlWnd__CanBreakAtCharacter);
#endif
#ifdef CStmlWnd__UpdateHistoryString_x
FUNCTION_AT_ADDRESS(void CStmlWnd::UpdateHistoryString(int32_t, const CXStr&), CStmlWnd__UpdateHistoryString);
#endif
#ifdef CStmlWnd__SetSTMLText_x
FUNCTION_AT_ADDRESS(void CStmlWnd::SetSTMLText(CXStr, bool, SLinkInfo*), CStmlWnd__SetSTMLText);
#endif
#ifdef CStmlWnd__SetSTMLTextWithoutHistory_x
FUNCTION_AT_ADDRESS(void CStmlWnd::SetSTMLTextWithoutHistory(CXStr), CStmlWnd__SetSTMLTextWithoutHistory);
#endif
#ifdef CStmlWnd__GoToBackHistoryLink_x
FUNCTION_AT_ADDRESS(void CStmlWnd::GoToBackHistoryLink(), CStmlWnd__GoToBackHistoryLink);
#endif
#ifdef CStmlWnd__CanGoBackward_x
FUNCTION_AT_ADDRESS(bool CStmlWnd::CanGoBackward(), CStmlWnd__CanGoBackward);
#endif
#ifdef STextLine__STextLine_x
FUNCTION_AT_ADDRESS(STextLine::STextLine(), STextLine__STextLine);
#endif
#ifdef STextLine__dSTextLine_x
FUNCTION_AT_ADDRESS(STextLine::~STextLine(), STextLine__dSTextLine);
#endif
#ifdef STextLine__operator_equal_x
FUNCTION_AT_ADDRESS(STextLine& STextLine::operator=(const STextLine&), STextLine__operator_equal);
#endif
#ifdef CTabWnd__CTabWnd_x
FUNCTION_AT_ADDRESS(CTabWnd::CTabWnd(CXWnd* pParent, UINT uId, RECT* rect, CTabBoxTemplate* pTabContents), CTabWnd__CTabWnd);
#endif
#ifdef CTabWnd__GetNumTabs_x
FUNCTION_AT_ADDRESS(int CTabWnd::GetNumTabs() const, CTabWnd__GetNumTabs);
#endif
#ifdef CTabWnd__GetCurrentPage_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetCurrentPage() const, CTabWnd__GetCurrentPage);
#endif
#ifdef CTabWnd__GetTabRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetTabRect(int) const, CTabWnd__GetTabRect);
#endif
#ifdef CTabWnd__GetTabInnerRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetTabInnerRect(int) const, CTabWnd__GetTabInnerRect);
#endif
#ifdef CTabWnd__GetPageClientRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetPageClientRect() const, CTabWnd__GetPageClientRect);
#endif
#ifdef CTabWnd__GetPageInnerRect_x
FUNCTION_AT_ADDRESS(CXRect CTabWnd::GetPageInnerRect() const, CTabWnd__GetPageInnerRect);
#endif
#ifdef CTabWnd__SetPage_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(void CTabWnd::SetPage(int, bool, bool, bool), CTabWnd__SetPage);
#else
FUNCTION_AT_ADDRESS(void CTabWnd::SetPage(int, bool), CTabWnd__SetPage);
#endif
#endif
#ifdef CTabWnd__SetPage1_x
FUNCTION_AT_ADDRESS(void CTabWnd::SetPage(CPageWnd*, bool), CTabWnd__SetPage1);
#endif
#ifdef CTabWnd__InsertPage_x
FUNCTION_AT_ADDRESS(void CTabWnd::InsertPage(CPageWnd*, int), CTabWnd__InsertPage);
#endif
#ifdef CTabWnd__SetPageRect_x
FUNCTION_AT_ADDRESS(void CTabWnd::SetPageRect(const CXRect&), CTabWnd__SetPageRect);
#endif
#ifdef CTabWnd__UpdatePage_x
FUNCTION_AT_ADDRESS(void CTabWnd::UpdatePage(), CTabWnd__UpdatePage);
#endif
#ifdef CTabWnd__GetPageFromTabIndex_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetPageFromTabIndex(int) const, CTabWnd__GetPageFromTabIndex);
#endif
#ifdef CTabWnd__GetCurrentTabIndex_x
FUNCTION_AT_ADDRESS(int CTabWnd::GetCurrentTabIndex() const, CTabWnd__GetCurrentTabIndex);
#endif
#ifdef CTabWnd__IndexInBounds_x
FUNCTION_AT_ADDRESS(bool CTabWnd::IndexInBounds(int) const, CTabWnd__IndexInBounds);
#endif
#ifdef CTabWnd__GetPageFromTabPoint_x
FUNCTION_AT_ADDRESS(CPageWnd* CTabWnd::GetPageFromTabPoint(CXPoint) const, CTabWnd__GetPageFromTabPoint);
#endif
#ifdef CTabWnd__DrawTab_x
FUNCTION_AT_ADDRESS(int CTabWnd::DrawTab(int) const, CTabWnd__DrawTab);
#endif
#ifdef CTabWnd__DrawCurrentPage_x
FUNCTION_AT_ADDRESS(int CTabWnd::DrawCurrentPage() const, CTabWnd__DrawCurrentPage);
#endif
#ifdef CPageWnd__GetTabText_x
	FUNCTION_AT_ADDRESS(CXStr CPageWnd::GetTabText(bool) const, CPageWnd__GetTabText);
#endif
#ifdef CPageWnd__SetTabText_x
FUNCTION_AT_ADDRESS(void CPageWnd::SetTabText(CXStr&) const, CPageWnd__SetTabText);
#endif
#ifdef CWebManager__CreateHtmlWnd_x
FUNCTION_AT_ADDRESS(CHtmlWnd* CWebManager::CreateHtmlWnd(const char*, const char*, const char*, bool, const char*), CWebManager__CreateHtmlWnd);
#endif
#ifdef CHtmlWnd__SetClientCallbacks_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::SetClientCallbacks(void*), CHtmlWnd__SetClientCallbacks);
#endif
#ifdef CHtmlWnd__AddObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::AddObserver(IObserver*), CHtmlWnd__AddObserver);
#endif
#ifdef CHtmlWnd__RemoveObserver_x
FUNCTION_AT_ADDRESS(void CHtmlWnd::RemoveObserver(IObserver*), CHtmlWnd__RemoveObserver);
#endif
#ifdef Window__getProgress_x
FUNCTION_AT_ADDRESS(float libMozilla::Window::getProgress(bool& bIsLoading), Window__getProgress);
#endif
#ifdef Window__getStatus_x
FUNCTION_AT_ADDRESS(const wchar_t* libMozilla::Window::getStatus() const, Window__getStatus);
#endif
#ifdef Window__getURI_x
FUNCTION_AT_ADDRESS(const char* libMozilla::Window::getURI() const, Window__getURI);
#endif
#ifdef CXMLSOMDocumentBase__Init_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::Init(), CXMLSOMDocumentBase__Init);
#endif
#ifdef CXMLSOMDocumentBase__CursorInit_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::CursorInit(), CXMLSOMDocumentBase__CursorInit);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewChild_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::CursorNewChild(), CXMLSOMDocumentBase__CursorNewChild);
#endif
#ifdef CXMLSOMDocumentBase__CursorNewSibling_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::CursorNewSibling(), CXMLSOMDocumentBase__CursorNewSibling);
#endif
#ifdef CXMLSOMDocumentBase__CursorSetPtr_x
//FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::CursorSetPtr(CXMLSOMNodePtr), CXMLSOMDocumentBase__CursorSetPtr);
#endif
#ifdef CXMLSOMDocumentBase__CursorPush_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorPush(), CXMLSOMDocumentBase__CursorPush);
#endif
#ifdef CXMLSOMDocumentBase__CursorPop_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorPop(), CXMLSOMDocumentBase__CursorPop);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextSibling_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorNextSibling(), CXMLSOMDocumentBase__CursorNextSibling);
#endif
#ifdef CXMLSOMDocumentBase__CursorNextInOrder_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorNextInOrder(), CXMLSOMDocumentBase__CursorNextInOrder);
#endif
#ifdef CXMLSOMDocumentBase__CursorFind_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorFind(CXStr), CXMLSOMDocumentBase__CursorFind);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr_x
FUNCTION_AT_ADDRESS(CXStr CXMLSOMDocumentBase::GetAttrValueStr(CXStr), CXMLSOMDocumentBase__GetAttrValueStr);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueStr1_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::GetAttrValueStr(CXStr, CXStr&), CXMLSOMDocumentBase__GetAttrValueStr1);
#endif
#ifdef CXMLSOMDocumentBase__GetAttrValueInt_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::GetAttrValueInt(CXStr, int32_t&), CXMLSOMDocumentBase__GetAttrValueInt);
#endif
#ifdef CXMLSOMDocumentBase__CursorFieldFind_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::CursorFieldFind(CXStr), CXMLSOMDocumentBase__CursorFieldFind);
#endif
#ifdef CXMLSOMDocumentBase__GetValue_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::GetValue(CXStr, CXStr&), CXMLSOMDocumentBase__GetValue);
#endif
#ifdef CXMLSOMDocumentBase__GetValue1_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::GetValue(CXStr, int32_t&), CXMLSOMDocumentBase__GetValue1);
#endif
#ifdef CXMLSOMDocumentBase__GetValue2_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::GetValue(CXStr, bool&), CXMLSOMDocumentBase__GetValue2);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseClassItem_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::FieldParseClassItem(CXStr, CXStr&, CXStr&), CXMLSOMDocumentBase__FieldParseClassItem);
#endif
#ifdef CXMLSOMDocumentBase__FieldParseItemOfClass_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::FieldParseItemOfClass(CXStr, CXStr, int32_t&, int32_t&), CXMLSOMDocumentBase__FieldParseItemOfClass);
#endif
#ifdef CXMLSOMDocumentBase__SetValue_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::SetValue(CXStr, CXStr), CXMLSOMDocumentBase__SetValue);
#endif
#ifdef CXMLSOMDocumentBase__SetValue1_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::SetValue(CXStr, int32_t), CXMLSOMDocumentBase__SetValue1);
#endif
#ifdef CXMLSOMDocumentBase__SetValue2_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::SetValue(CXStr, bool), CXMLSOMDocumentBase__SetValue2);
#endif
#ifdef CXMLSOMDocumentBase__XMLReadNoValidate_x
FUNCTION_AT_ADDRESS(int CXMLSOMDocumentBase::XMLReadNoValidate(CXStr, CXStr, CXStr), CXMLSOMDocumentBase__XMLReadNoValidate);
#endif
#ifdef CXMLSOMDocumentBase__XMLRead_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::XMLRead(const CXStr&, const CXStr&, const CXStr&), CXMLSOMDocumentBase__XMLRead);
#endif
#ifdef CXMLSOMDocumentBase__XMLProcessComposite_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::XMLProcessComposite(CXStr, CXStr), CXMLSOMDocumentBase__XMLProcessComposite);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsg_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::SetErrorMsg(CXStr), CXMLSOMDocumentBase__SetErrorMsg);
#endif
#ifdef CXMLSOMDocumentBase__GetErrorMsg_x
FUNCTION_AT_ADDRESS(CXStr CXMLSOMDocumentBase::GetErrorMsg() const, CXMLSOMDocumentBase__GetErrorMsg);
#endif
#ifdef CXMLSOMDocumentBase__XMLMerge_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::XMLMerge(CXMLSOMDocumentBase&), CXMLSOMDocumentBase__XMLMerge);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtLine_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::SetErrorMsgAtLine(CXStr, int, CXStr), CXMLSOMDocumentBase__SetErrorMsgAtLine);
#endif
#ifdef CXMLSOMDocumentBase__SetErrorMsgAtCursor_x
FUNCTION_AT_ADDRESS(void CXMLSOMDocumentBase::SetErrorMsgAtCursor(CXStr), CXMLSOMDocumentBase__SetErrorMsgAtCursor);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaSimpleTypeNode(CXMLSOMSimpleType&), CXMLSOMDocumentBase__ValidateSchemaSimpleTypeNode);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaElementType_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaElementType(), CXMLSOMDocumentBase__ValidateSchemaElementType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaSimpleType_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaSimpleType(), CXMLSOMDocumentBase__ValidateSchemaSimpleType);
#endif
#ifdef CXMLSOMSimpleType__dCXMLSOMSimpleType_x
FUNCTION_AT_ADDRESS(CXMLSOMSimpleType::~CXMLSOMSimpleType(), CXMLSOMSimpleType__dCXMLSOMSimpleType);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaDefinition_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaDefinition(), CXMLSOMDocumentBase__ValidateSchemaDefinition);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaCategories_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaCategories(), CXMLSOMDocumentBase__ValidateSchemaCategories);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchemaTypeRefs_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchemaTypeRefs(), CXMLSOMDocumentBase__ValidateSchemaTypeRefs);
#endif
#ifdef CXMLSOMDocumentBase__ValidateSchema_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateSchema(), CXMLSOMDocumentBase__ValidateSchema);
#endif
#ifdef CXMLSOMDocumentBase__ValidateDataElements_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateDataElements(CXMLSOMElementType&), CXMLSOMDocumentBase__ValidateDataElements);
#endif
#ifdef CXMLSOMDocumentBase__ValidateData_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocumentBase::ValidateData(), CXMLSOMDocumentBase__ValidateData);
#endif
#ifdef CMutexLock__dCMutexLock_x
FUNCTION_AT_ADDRESS(CMutexLock::~CMutexLock(), CMutexLock__dCMutexLock);
#endif
#ifdef CKeyCXStrValueInt32__CKeyCXStrValueInt32_x
FUNCTION_AT_ADDRESS(CKeyCXStrValueInt32::CKeyCXStrValueInt32(), CKeyCXStrValueInt32__CKeyCXStrValueInt32);
#endif
#ifdef KeyCombo__KeyCombo_x
FUNCTION_AT_ADDRESS(KeyCombo::KeyCombo(), KeyCombo__KeyCombo);
#endif
#ifdef KeyCombo__KeyCombo1_x
FUNCTION_AT_ADDRESS(KeyCombo::KeyCombo(unsigned char, bool, bool, bool), KeyCombo__KeyCombo1);
#endif
#ifdef KeyCombo__KeyCombo2_x
FUNCTION_AT_ADDRESS(KeyCombo::KeyCombo(int), KeyCombo__KeyCombo2);
#endif
#ifdef KeyCombo__KeyCombo3_x
FUNCTION_AT_ADDRESS(KeyCombo::KeyCombo(unsigned int, unsigned int, bool, bool, bool), KeyCombo__KeyCombo3);
#endif
#ifdef KeyCombo__GetKey_x
FUNCTION_AT_ADDRESS(unsigned int KeyCombo::GetKey() const, KeyCombo__GetKey);
#endif
#ifdef KeyCombo__UsesCtrl_x
FUNCTION_AT_ADDRESS(bool KeyCombo::UsesCtrl() const, KeyCombo__UsesCtrl);
#endif
#ifdef KeyCombo__UsesShift_x
FUNCTION_AT_ADDRESS(bool KeyCombo::UsesShift() const, KeyCombo__UsesShift);
#endif
#ifdef KeyCombo__UsesAlt_x
FUNCTION_AT_ADDRESS(bool KeyCombo::UsesAlt() const, KeyCombo__UsesAlt);
#endif
#ifdef KeyCombo__GetTextDescription_x
FUNCTION_AT_ADDRESS(CXStr KeyCombo::GetTextDescription() const, KeyCombo__GetTextDescription);
#endif
#ifdef KeyCombo__GetPrintableLetter_x
FUNCTION_AT_ADDRESS(bool KeyCombo::GetPrintableLetter(unsigned short*) const, KeyCombo__GetPrintableLetter);
#endif
#ifdef KeyCombo__operator_equal_equal_x
FUNCTION_AT_ADDRESS(int KeyCombo::operator==(const KeyCombo&) const, KeyCombo__operator_equal_equal);
#endif
#ifdef KeyCombo__operator_equal_x
FUNCTION_AT_ADDRESS(const KeyCombo& KeyCombo::operator=(int), KeyCombo__operator_equal);
#endif
#ifdef KeyCombo__operator_int_x
//FUNCTION_AT_ADDRESS(KeyCombo::operator int() const, KeyCombo__operator_int);
#endif
#ifdef KeyCombo__GetVirtualKeyFromScanCode_x
FUNCTION_AT_ADDRESS(bool KeyCombo::GetVirtualKeyFromScanCode(unsigned char, int*) const, KeyCombo__GetVirtualKeyFromScanCode);
#endif
#ifdef KeyCombo__GetPrintableLetterFromScanCode_x
FUNCTION_AT_ADDRESS(bool KeyCombo::GetPrintableLetterFromScanCode(unsigned char, bool, bool, unsigned short*) const, KeyCombo__GetPrintableLetterFromScanCode);
#endif
#ifdef KeyCombo__GetScanCodeFromVirtualKey_x
FUNCTION_AT_ADDRESS(bool KeyCombo::GetScanCodeFromVirtualKey(unsigned int, unsigned int, unsigned char*) const, KeyCombo__GetScanCodeFromVirtualKey);
#endif
#ifdef KeyCombo__GetPrintableLetterFromVirtualKey_x
FUNCTION_AT_ADDRESS(bool KeyCombo::GetPrintableLetterFromVirtualKey(unsigned int, unsigned int, bool, bool, unsigned short*) const, KeyCombo__GetPrintableLetterFromVirtualKey);
#endif
//#ifdef CButtonWnd__CButtonWnd_x
//FUNCTION_AT_ADDRESS(CButtonWnd::CButtonWnd(CXWnd*, uint32_t, CXRect, class CXPoint, CXSize, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*), CButtonWnd__CButtonWnd);
//#endif
#ifdef CButtonWnd__SetCheck_x
FUNCTION_AT_ADDRESS(void CButtonWnd::SetCheck(bool), CButtonWnd__SetCheck);
#endif
#ifdef CComboWnd__CComboWnd_x
//FUNCTION_AT_ADDRESS(CComboWnd::CComboWnd(CXWnd*, uint32_t, CXRect, int, class CButtonDrawTemplate, CListWnd*), CComboWnd__CComboWnd);
#endif

#ifdef CComboWnd__GetListRect_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetListRect(bool) const, CComboWnd__GetListRect);
#else
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetListRect() const, CComboWnd__GetListRect);
#endif
#endif
#ifdef CComboWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetColors(unsigned long, unsigned long, unsigned long), CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::InsertChoice(const CXStr&, unsigned long), CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetChoice(int), CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetItemCount(), CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetCurChoice() const, CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText_x
FUNCTION_AT_ADDRESS(CXStr CComboWnd::GetCurChoiceText() const, CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll_x
FUNCTION_AT_ADDRESS(void CComboWnd::DeleteAll(), CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetButtonRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetButtonRect() const, CComboWnd__GetButtonRect);
#endif
#ifdef CComboWnd__GetTextRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetTextRect() const, CComboWnd__GetTextRect);
#endif
#ifdef CXWndManager__CXWndManager_x
FUNCTION_AT_ADDRESS(CXWndManager::CXWndManager(CSidlManager*), CXWndManager__CXWndManager);
#endif
#ifdef CXWndManager__DestroyAllWindows_x
FUNCTION_AT_ADDRESS(void CXWndManager::DestroyAllWindows(), CXWndManager__DestroyAllWindows);
#endif
#ifdef CXWndManager__DrawWindows_x
FUNCTION_AT_ADDRESS(int CXWndManager::DrawWindows() const, CXWndManager__DrawWindows);
#endif
#ifdef CXWndManager__DrawCursor_x
FUNCTION_AT_ADDRESS(int CXWndManager::DrawCursor() const, CXWndManager__DrawCursor);
#endif
#ifdef CXWndManager__AddWnd_x
FUNCTION_AT_ADDRESS(int CXWndManager::AddWnd(CXWnd*), CXWndManager__AddWnd);
#endif
#ifdef CXWndManager__RemoveWnd_x
FUNCTION_AT_ADDRESS(int CXWndManager::RemoveWnd(CXWnd*), CXWndManager__RemoveWnd);
#endif
#ifdef CXWndManager__CheckInvalidateLastFoundWnd_x
FUNCTION_AT_ADDRESS(void CXWndManager::CheckInvalidateLastFoundWnd(), CXWndManager__CheckInvalidateLastFoundWnd);
#endif
#ifdef CXWndManager__GetKeyboardFlags_x
FUNCTION_AT_ADDRESS(uint32_t CXWndManager::GetKeyboardFlags() const, CXWndManager__GetKeyboardFlags);
#endif
#ifdef CXWndManager__FlushKeyboardFlags_x
FUNCTION_AT_ADDRESS(void CXWndManager::FlushKeyboardFlags(), CXWndManager__FlushKeyboardFlags);
#endif
#ifdef CXWndManager__UpdateChildAndSiblingInfo_x
FUNCTION_AT_ADDRESS(void CXWndManager::UpdateChildAndSiblingInfo(), CXWndManager__UpdateChildAndSiblingInfo);
#endif
#ifdef CXWndManager__HandleKeyboardMsg_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleKeyboardMsg(uint32_t, bool), CXWndManager__HandleKeyboardMsg);
#endif
#ifdef CXWndManager__OkayToSendMouseMessage_x
FUNCTION_AT_ADDRESS(bool CXWndManager::OkayToSendMouseMessage(CXWnd*) const, CXWndManager__OkayToSendMouseMessage);
#endif
#ifdef CXWndManager__HandleMouseMove_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleMouseMove(CXPoint), CXWndManager__HandleMouseMove);
#endif
#ifdef CXWndManager__HandleWheelMove_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleWheelMove(int), CXWndManager__HandleWheelMove);
#endif
#ifdef CXWndManager__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleLButtonDown(CXPoint), CXWndManager__HandleLButtonDown);
#endif
#ifdef CXWndManager__IsWindowPieceDown_x
FUNCTION_AT_ADDRESS(bool CXWndManager::IsWindowPieceDown(CXWnd const*, int) const, CXWndManager__IsWindowPieceDown);
#endif
#ifdef CXWndManager__OnWindowCloseBox_x
FUNCTION_AT_ADDRESS(int CXWndManager::OnWindowCloseBox(CXWnd*), CXWndManager__OnWindowCloseBox);
#endif
#ifdef CXWndManager__OnWindowMinimizeBox_x
FUNCTION_AT_ADDRESS(int CXWndManager::OnWindowMinimizeBox(CXWnd*), CXWndManager__OnWindowMinimizeBox);
#endif
#ifdef CXWndManager__OnWindowTileBox_x
FUNCTION_AT_ADDRESS(int CXWndManager::OnWindowTileBox(CXWnd*), CXWndManager__OnWindowTileBox);
#endif
#ifdef CXWndManager__HandleLButtonHeld_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleLButtonHeld(CXPoint), CXWndManager__HandleLButtonHeld);
#endif
#ifdef CXWndManager__HandleLButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleLButtonUpAfterHeld(CXPoint), CXWndManager__HandleLButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleRButtonHeld_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleRButtonHeld(CXPoint), CXWndManager__HandleRButtonHeld);
#endif
#ifdef CXWndManager__HandleRButtonUpAfterHeld_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleRButtonUpAfterHeld(CXPoint), CXWndManager__HandleRButtonUpAfterHeld);
#endif
#ifdef CXWndManager__HandleLButtonUp_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleLButtonUp(CXPoint), CXWndManager__HandleLButtonUp);
#endif
#ifdef CXWndManager__HandleRButtonDown_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleRButtonDown(CXPoint), CXWndManager__HandleRButtonDown);
#endif
#ifdef CXWndManager__HandleRButtonUp_x
FUNCTION_AT_ADDRESS(int CXWndManager::HandleRButtonUp(CXPoint), CXWndManager__HandleRButtonUp);
#endif
#ifdef CXWndManager__FindWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWndManager::FindWnd(CXPoint, int*) const, CXWndManager__FindWnd);
#endif
#ifdef CXWndManager__GetCursorToDisplay_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CXWndManager::GetCursorToDisplay() const, CXWndManager__GetCursorToDisplay);
#endif
#ifdef CXWndManager__SetFocusWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWndManager::SetFocusWnd(CXWnd*), CXWndManager__SetFocusWnd);
#endif
#ifdef CXWndManager__GetFocusWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWndManager::GetFocusWnd() const, CXWndManager__GetFocusWnd);
#endif
#ifdef CXWndManager__ProcessFrame_x
FUNCTION_AT_ADDRESS(int CXWndManager::ProcessFrame(), CXWndManager__ProcessFrame);
#endif
#ifdef CXWndManager__OnWindowShown_x
FUNCTION_AT_ADDRESS(void CXWndManager::OnWindowShown(CXWnd*, bool), CXWndManager__OnWindowShown);
#endif
#ifdef CXWndManager__BringWndToTop_x
FUNCTION_AT_ADDRESS(void CXWndManager::BringWndToTop(CXWnd*, bool), CXWndManager__BringWndToTop);
#endif
#ifdef CXWndManager__NotifyAllWindows_x
FUNCTION_AT_ADDRESS(int CXWndManager::NotifyAllWindows(CXWnd*, uint32_t, void*), CXWndManager__NotifyAllWindows);
#endif
#ifdef CXWndManager__CleanupWindows_x
FUNCTION_AT_ADDRESS(void CXWndManager::CleanupWindows(), CXWndManager__CleanupWindows);
#endif
#ifdef CXWndManager__GetFirstChildWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWndManager::GetFirstChildWnd(CXWnd const*) const, CXWndManager__GetFirstChildWnd);
#endif
#ifdef CXWndManager__GetNextSib_x
FUNCTION_AT_ADDRESS(CXWnd* CXWndManager::GetNextSib(CXWnd const*) const, CXWndManager__GetNextSib);
#endif
#ifdef CXWndManager__ActivateWnd_x
FUNCTION_AT_ADDRESS(int CXWndManager::ActivateWnd(CXWnd*), CXWndManager__ActivateWnd);
#endif
#ifdef CXWndManager__IsWindowActive_x
FUNCTION_AT_ADDRESS(bool CXWndManager::IsWindowActive(CXWnd const*) const, CXWndManager__IsWindowActive);
#endif
#ifdef CXWndManager__IsWindowMovingOrSizing_x
FUNCTION_AT_ADDRESS(bool CXWndManager::IsWindowMovingOrSizing(CXWnd*) const, CXWndManager__IsWindowMovingOrSizing);
#endif
#ifdef CXWndManager__AddFont_x
FUNCTION_AT_ADDRESS(int CXWndManager::AddFont(CTextureFont*), CXWndManager__AddFont);
#endif
#ifdef CXWndManager__GetFont1_x
FUNCTION_AT_ADDRESS(CTextureFont* CXWndManager::GetFont(CXStr), CXWndManager__GetFont1);
#endif
#ifdef CXWndManager__SetSystemFont_x
FUNCTION_AT_ADDRESS(void CXWndManager::SetSystemFont(CTextureFont*), CXWndManager__SetSystemFont);
#endif
#ifdef CXWndManager__SetGlobalFadeDuration_x
FUNCTION_AT_ADDRESS(void CXWndManager::SetGlobalFadeDuration(uint32_t), CXWndManager__SetGlobalFadeDuration);
#endif
#ifdef CXWndManager__GetGlobalFadeDuration_x
FUNCTION_AT_ADDRESS(uint32_t CXWndManager::GetGlobalFadeDuration() const, CXWndManager__GetGlobalFadeDuration);
#endif
#ifdef CXWndManager__SetGlobalFadeDelay_x
FUNCTION_AT_ADDRESS(void CXWndManager::SetGlobalFadeDelay(unsigned long), CXWndManager__SetGlobalFadeDelay);
#endif
#ifdef CXWndManager__GetGlobalFadeDelay_x
FUNCTION_AT_ADDRESS(unsigned long CXWndManager::GetGlobalFadeDelay() const, CXWndManager__GetGlobalFadeDelay);
#endif
#ifdef CXWndManager__SetGlobalAlpha_x
FUNCTION_AT_ADDRESS(void CXWndManager::SetGlobalAlpha(unsigned char), CXWndManager__SetGlobalAlpha);
#endif
#ifdef CXWndManager__GetGlobalAlpha_x
FUNCTION_AT_ADDRESS(unsigned char CXWndManager::GetGlobalAlpha() const, CXWndManager__GetGlobalAlpha);
#endif
#ifdef CXWndManager__SetGlobalFadeToAlpha_x
FUNCTION_AT_ADDRESS(void CXWndManager::SetGlobalFadeToAlpha(unsigned char), CXWndManager__SetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__GetGlobalFadeToAlpha_x
FUNCTION_AT_ADDRESS(unsigned char CXWndManager::GetGlobalFadeToAlpha() const, CXWndManager__GetGlobalFadeToAlpha);
#endif
#ifdef CXWndManager__IsAllValid_x
FUNCTION_AT_ADDRESS(bool CXWndManager::IsAllValid(), CXWndManager__IsAllValid);
#endif
#ifdef CEditWnd__CEditWnd_x
//FUNCTION_AT_ADDRESS(CEditWnd::CEditWnd(CXWnd*, uint32_t, CXRect, uint32_t), CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineForPrintableChar(int) const, CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineLength(int) const, CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray_x
FUNCTION_AT_ADDRESS(void CEditWnd::FillIndexArray(CXStr) const, CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint_x
FUNCTION_AT_ADDRESS(int CEditWnd::SelectableCharFromPoint(CXPoint) const, CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag_x
FUNCTION_AT_ADDRESS(void CEditWnd::AddItemTag(int, char*, int), CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void CEditWnd::ProcessText(), CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetCharIndexPt(int) const, CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelStartPt() const, CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelEndPt() const, CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr_x
FUNCTION_AT_ADDRESS(void CEditWnd::FilterInputStr(CXStr&), CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__ReplaceSelection_x
FUNCTION_AT_ADDRESS(void CEditWnd::ReplaceSelection(CXStr, bool), CEditWnd__ReplaceSelection);
#endif
#ifdef CEditWnd__ReplaceSelection1_x
FUNCTION_AT_ADDRESS(void CEditWnd::ReplaceSelection(char, bool), CEditWnd__ReplaceSelection1);
#endif
#ifdef CEditWnd__CalculateScrollRange_x
FUNCTION_AT_ADDRESS(void CEditWnd::CalculateScrollRange(), CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible_x
FUNCTION_AT_ADDRESS(void CEditWnd::EnsureCaretVisible(), CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetEditable(bool), CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText_x
FUNCTION_AT_ADDRESS(CXStr CEditWnd::GetSTMLSafeText(), CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__SetWindowTextA_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetWindowTextA(const CXStr& Str), CEditWnd__SetWindowTextA);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexPrintableToTagged(int), CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexTaggedToPrintable(int), CEditWnd__ConvertIndexTaggedToPrintable);
#endif
#ifdef CTextureFont__GetWidth_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetWidth(unsigned short) const, CTextureFont__GetWidth);
#endif
#ifdef CTextureFont__GetKerning_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetKerning(unsigned short, unsigned short) const, CTextureFont__GetKerning);
#endif
#ifdef CTextureFont__GetTextExtent_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int CTextureFont::GetTextExtent(const CXStr&), CTextureFont__GetTextExtent);
#else
FUNCTION_AT_ADDRESS(int CTextureFont::GetTextExtent(), CTextureFont__GetTextExtent);
#endif
#endif
#ifdef CTextureFont__GetHeight_x
FUNCTION_AT_ADDRESS(int CTextureFont::GetHeight() const, CTextureFont__GetHeight);
#endif
#ifdef CTextureFont__GetName_x
FUNCTION_AT_ADDRESS(CXStr CTextureFont::GetName() const, CTextureFont__GetName);
#endif
#ifdef CTextureFont__DrawWrappedText_x
FUNCTION_AT_ADDRESS(int CTextureFont::DrawWrappedText(const CXStr&, int, int, int, const CXRect&, COLORREF, WORD, int) const, CTextureFont__DrawWrappedText);
#endif
#ifdef CTextureFont__DrawWrappedText1_x
FUNCTION_AT_ADDRESS(int CTextureFont::DrawWrappedText(const CXStr&, const CXRect&, const CXRect&, unsigned long, unsigned short, int) const, CTextureFont__DrawWrappedText1);
#endif
#ifdef CTextureAnimation__CTextureAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation::CTextureAnimation(), CTextureAnimation__CTextureAnimation);
#endif
#ifdef CTextureAnimation__CTextureAnimation1_x
FUNCTION_AT_ADDRESS(CTextureAnimation::CTextureAnimation(CXStr), CTextureAnimation__CTextureAnimation1);
#endif
#ifdef CUITexturePiece__CUITexturePiece1_x
FUNCTION_AT_ADDRESS(CUITexturePiece::CUITexturePiece(const CUITexturePiece&), CUITexturePiece__CUITexturePiece1);
#endif
#ifdef CTextureAnimation__AddFrame_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::AddFrame(CUITextureInfo const*, CXRect, uint32_t, class CXPoint), CTextureAnimation__AddFrame);
#endif
#ifdef CUITexturePiece__CUITexturePiece2_x
//FUNCTION_AT_ADDRESS(CUITexturePiece::CUITexturePiece(CUITextureInfo, CXRect), CUITexturePiece__CUITexturePiece2);
#endif
#ifdef CUITextureInfo__CUITextureInfo2_x
FUNCTION_AT_ADDRESS(CUITextureInfo::CUITextureInfo(const CUITextureInfo&), CUITextureInfo__CUITextureInfo2);
#endif
#ifdef CTextureAnimation__AddFrame1_x
//FUNCTION_AT_ADDRESS(int CTextureAnimation::AddFrame(CUITexturePiece, uint32_t, CXPoint), CTextureAnimation__AddFrame1);
#endif
#ifdef STextureAnimationFrame__STextureAnimationFrame1_x
FUNCTION_AT_ADDRESS(STextureAnimationFrame::STextureAnimationFrame(CUITexturePiece, uint32_t, CXPoint), STextureAnimationFrame__STextureAnimationFrame1);
#endif
#ifdef CUITextureInfo__CUITextureInfo3_x
FUNCTION_AT_ADDRESS(CUITextureInfo::CUITextureInfo(uint32_t, int), CUITextureInfo__CUITextureInfo3);
#endif
#ifdef CTextureAnimation__AddBlankFrame_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::AddBlankFrame(uint32_t, CXPoint), CTextureAnimation__AddBlankFrame);
#endif
#ifdef CTextureAnimation__SetCurFrame_x
FUNCTION_AT_ADDRESS(void CTextureAnimation::SetCurFrame(int), CTextureAnimation__SetCurFrame);
#endif
#ifdef CTextureAnimation__GetCurFrame_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::GetCurFrame() const, CTextureAnimation__GetCurFrame);
#endif
#ifdef CTextureAnimation__Draw_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::Draw(CXRect, CXRect, unsigned long, unsigned long) const, CTextureAnimation__Draw);
#endif
#ifdef CTextureAnimation__Draw1_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::Draw(CXPoint, CXRect, unsigned long, unsigned long) const, CTextureAnimation__Draw1);
#endif
#ifdef CTextureAnimation__GetHotspot_x
FUNCTION_AT_ADDRESS(CXPoint CTextureAnimation::GetHotspot() const, CTextureAnimation__GetHotspot);
#endif
#ifdef CTextureAnimation__SetCurCell_x
FUNCTION_AT_ADDRESS(void CTextureAnimation::SetCurCell(int), CTextureAnimation__SetCurCell);
#endif
#ifdef CTextureAnimation__Preload_x
FUNCTION_AT_ADDRESS(int CTextureAnimation::Preload(), CTextureAnimation__Preload);
#endif
#ifdef CUITextureInfo__operator_equal_x
FUNCTION_AT_ADDRESS(CUITextureInfo& CUITextureInfo::operator=(const CUITextureInfo&), CUITextureInfo__operator_equal);
#endif
#ifdef CSidlManager__CSidlManager_x
FUNCTION_AT_ADDRESS(CSidlManager::CSidlManager(), CSidlManager__CSidlManager);
#endif
#ifdef CSidlManager__GetPointFromParamPoint_x
FUNCTION_AT_ADDRESS(CXPoint __cdecl CSidlManager::GetPointFromParamPoint(const CParamPoint&), CSidlManager__GetPointFromParamPoint);
#endif
#ifdef CSidlManager__GetSizeFromParamSize_x
FUNCTION_AT_ADDRESS(CXSize __cdecl CSidlManager::GetSizeFromParamSize(const CParamSize&), CSidlManager__GetSizeFromParamSize);
#endif
#ifdef CSidlManager__GetRectFromParamPointSize_x
FUNCTION_AT_ADDRESS(CXRect __cdecl CSidlManager::GetRectFromParamPointSize(const CParamPoint&, CParamSize const&), CSidlManager__GetRectFromParamPointSize);
#endif
#ifdef CSidlManager__GetD3DCOLOR_x
FUNCTION_AT_ADDRESS(unsigned long __cdecl CSidlManager::GetD3DCOLOR(const CParamRGB&), CSidlManager__GetD3DCOLOR);
#endif
#ifdef CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate CSidlManager::GetButtonDrawTemplateFromParamButtonDrawTemplate(const CParamButtonDrawTemplate&) const, CSidlManager__GetButtonDrawTemplateFromParamButtonDrawTemplate);
#endif
#ifdef CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS(CGaugeDrawTemplate CSidlManager::GetGaugeDrawTemplateFromParamGaugeDrawTemplate(const CParamGaugeDrawTemplate&) const, CSidlManager__GetGaugeDrawTemplateFromParamGaugeDrawTemplate);
#endif
#ifdef CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS(CSpellGemDrawTemplate CSidlManager::GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(const CParamSpellGemDrawTemplate&) const, CSidlManager__GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate);
#endif
#ifdef CSidlManager__DeleteContents_x
FUNCTION_AT_ADDRESS(void CSidlManager::DeleteContents(), CSidlManager__DeleteContents);
#endif
#ifdef CParamScrollbarDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamScrollbarDrawTemplate& CParamScrollbarDrawTemplate::operator=(const CParamScrollbarDrawTemplate&), CParamScrollbarDrawTemplate__operator_equal);
#endif
#ifdef CParamFrameTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamFrameTemplate& CParamFrameTemplate::operator=(const CParamFrameTemplate&), CParamFrameTemplate__operator_equal);
#endif
#ifdef CParamButtonDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamButtonDrawTemplate& CParamButtonDrawTemplate::operator=(const CParamButtonDrawTemplate&), CParamButtonDrawTemplate__operator_equal);
#endif
#ifdef CParamClass__operator_equal_x
FUNCTION_AT_ADDRESS(CParamClass& CParamClass::operator=(const CParamClass&), CParamClass__operator_equal);
#endif
#ifdef CParamRGB__operator_equal_x
FUNCTION_AT_ADDRESS(CParamRGB& CParamRGB::operator=(const CParamRGB&), CParamRGB__operator_equal);
#endif
#ifdef CParam__operator_equal_x
FUNCTION_AT_ADDRESS(CParam& CParam::operator=(const CParam&), CParam__operator_equal);
#endif
#ifdef CXMLData__operator_equal_x
FUNCTION_AT_ADDRESS(CXMLData& CXMLData::operator=(const CXMLData&), CXMLData__operator_equal);
#endif
#ifdef CTAFrameDraw__GetName_x
FUNCTION_AT_ADDRESS(CXStr CTAFrameDraw::GetName() const, CTAFrameDraw__GetName);
#endif
#ifdef CScreenPieceTemplate__GetName_x
FUNCTION_AT_ADDRESS(CXStr CScreenPieceTemplate::GetName() const, CScreenPieceTemplate__GetName);
#endif
#ifdef CSidlManager__LoadSidl_x
FUNCTION_AT_ADDRESS(void CSidlManager::LoadSidl(const CXStr&, CXStr const&, CXStr const&, CXStr const&), CSidlManager__LoadSidl);
#endif
#ifdef CUITextureInfo__CUITextureInfo4_x
FUNCTION_AT_ADDRESS(CUITextureInfo::CUITextureInfo(CXStr, CXSize), CUITextureInfo__CUITextureInfo4);
#endif
#ifdef CSidlManager__CreateTextureAnimationFromSidlAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation CSidlManager::CreateTextureAnimationFromSidlAnimation(CParamUi2DAnimation const*) const, CSidlManager__CreateTextureAnimationFromSidlAnimation);
#endif
#ifdef CSidlManager__CreateTAFrameDrawFromSidlFrame_x
FUNCTION_AT_ADDRESS(CTAFrameDraw CSidlManager::CreateTAFrameDrawFromSidlFrame(CParamFrameTemplate const*) const, CSidlManager__CreateTAFrameDrawFromSidlFrame);
#endif
#ifdef CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate_x
FUNCTION_AT_ADDRESS(CScrollbarTemplate CSidlManager::GetScrollbarTemplateFromParamScrollbarTemplate(const CParamScrollbarDrawTemplate&) const, CSidlManager__GetScrollbarTemplateFromParamScrollbarTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate_x
FUNCTION_AT_ADDRESS(CScrollbarTemplate::CScrollbarTemplate(const CScrollbarTemplate&), CScrollbarTemplate__CScrollbarTemplate);
#endif
#ifdef CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(CSliderDrawTemplate CSidlManager::GetSliderDrawTemplateFromParamSliderDrawTemplate(const CParamSliderDrawTemplate&) const, CSidlManager__GetSliderDrawTemplateFromParamSliderDrawTemplate);
#endif
#ifdef CButtonDrawTemplate__CButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate::CButtonDrawTemplate(const CButtonDrawTemplate&), CButtonDrawTemplate__CButtonDrawTemplate1);
#endif
#ifdef CSliderDrawTemplate__dCSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(CSliderDrawTemplate::~CSliderDrawTemplate(), CSliderDrawTemplate__dCSliderDrawTemplate);
#endif
#ifdef CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate CSidlManager::CreateDrawTemplateFromParamWindowDrawTemplate(CParamWindowDrawTemplate const*) const, CSidlManager__CreateDrawTemplateFromParamWindowDrawTemplate);
#endif
#ifdef CScrollbarTemplate__CScrollbarTemplate1_x
FUNCTION_AT_ADDRESS(CScrollbarTemplate::CScrollbarTemplate(), CScrollbarTemplate__CScrollbarTemplate1);
#endif
#ifdef CXWndDrawTemplate__CXWndDrawTemplate1_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate::CXWndDrawTemplate(const CXWndDrawTemplate&), CXWndDrawTemplate__CXWndDrawTemplate1);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw_x
FUNCTION_AT_ADDRESS(CTAFrameDraw::CTAFrameDraw(const CTAFrameDraw&), CTAFrameDraw__CTAFrameDraw);
#endif
#ifdef CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManager::CreateScreenPieceTemplateFromParamScreenPiece(CParamScreenPiece const*) const, CSidlManager__CreateScreenPieceTemplateFromParamScreenPiece);
#endif
#ifdef CSidlManager__GetParsingErrorMsg_x
FUNCTION_AT_ADDRESS(CXStr CSidlManager::GetParsingErrorMsg() const, CSidlManager__GetParsingErrorMsg);
#endif
#ifdef CSidlManager__GetScreenPieceEnum_x
//FUNCTION_AT_ADDRESS(enum EStaticScreenPieceClasses CSidlManager::GetScreenPieceEnum(CScreenPieceTemplate*) const, CSidlManager__GetScreenPieceEnum);
#endif
#ifdef CSidlManager__FindAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation* CSidlManager::FindAnimation(uint32_t) const, CSidlManager__FindAnimation);
#endif
#ifdef CSidlManager__FindAnimation1_x
FUNCTION_AT_ADDRESS(CTextureAnimation* CSidlManager::FindAnimation(const CXStr&) const, CSidlManager__FindAnimation1);
#endif
#ifdef CSidlManager__FindFrameDraw_x
FUNCTION_AT_ADDRESS(CTAFrameDraw* CSidlManager::FindFrameDraw(uint32_t) const, CSidlManager__FindFrameDraw);
#endif
#ifdef CSidlManager__FindDrawTemplate_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate* CSidlManager::FindDrawTemplate(uint32_t) const, CSidlManager__FindDrawTemplate);
#endif
#ifdef CSidlManager__FindDrawTemplate1_x
FUNCTION_AT_ADDRESS(CXWndDrawTemplate* CSidlManager::FindDrawTemplate(CXStr) const, CSidlManager__FindDrawTemplate1);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(uint32_t) const, CSidlManager__FindScreenPieceTemplate);
#endif
#ifdef CSidlManager__FindScreenPieceTemplate1_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManager::FindScreenPieceTemplate(const CXStr&) const, CSidlManager__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManager__AddAnimationInOrder_x
FUNCTION_AT_ADDRESS(void CSidlManager::AddAnimationInOrder(CTextureAnimation*), CSidlManager__AddAnimationInOrder);
#endif
#ifdef CSidlManager__AddDrawTemplateInOrder_x
FUNCTION_AT_ADDRESS(void CSidlManager::AddDrawTemplateInOrder(CXWndDrawTemplate*), CSidlManager__AddDrawTemplateInOrder);
#endif
#ifdef CSidlManager__AddTAFrameDrawInOrder_x
FUNCTION_AT_ADDRESS(void CSidlManager::AddTAFrameDrawInOrder(CTAFrameDraw*), CSidlManager__AddTAFrameDrawInOrder);
#endif
#ifdef CSidlManager__AddScreenPieceTemplateInOrder_x
FUNCTION_AT_ADDRESS(void CSidlManager::AddScreenPieceTemplateInOrder(CScreenPieceTemplate*), CSidlManager__AddScreenPieceTemplateInOrder);
#endif
#ifdef CSidlManager__FindTexture_x
FUNCTION_AT_ADDRESS(CUITextureInfo* CSidlManager::FindTexture(CXStr) const, CSidlManager__FindTexture);
#endif
#ifdef CSidlManager__FindTexture1_x
FUNCTION_AT_ADDRESS(CUITextureInfo* CSidlManager::FindTexture(uint32_t) const, CSidlManager__FindTexture1);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManager::FindButtonDrawTemplate(uint32_t) const, CSidlManagerBase__FindButtonDrawTemplate);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManager::FindButtonDrawTemplate(const CXStr& Name) const, CSidlManagerBase__FindButtonDrawTemplate1);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(CSliderDrawTemplate* CSidlManager::FindSliderDrawTemplate(CXStr) const, CSidlManager__FindSliderDrawTemplate);
#endif
#ifdef CSidlManager__FindSliderDrawTemplate1_x
FUNCTION_AT_ADDRESS(CSliderDrawTemplate* CSidlManager::FindSliderDrawTemplate(uint32_t) const, CSidlManager__FindSliderDrawTemplate1);
#endif
#ifdef CSidlManager__CreateXWndFromTemplate_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateXWndFromTemplate(CXWnd*, CControlTemplate*, bool), CSidlManager__CreateXWndFromTemplate);
#else
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateXWndFromTemplate(CXWnd*, CControlTemplate*), CSidlManager__CreateXWndFromTemplate);
#endif
#endif
#ifdef CSidlManager__CreateXWndFromTemplate1_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateXWndFromTemplate(CXWnd*, const CXStr&), CSidlManager__CreateXWndFromTemplate1);
#endif
#ifdef CSidlManager__CreateXWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateXWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManager__CreateXWnd);
#endif
#ifdef CSidlManager__CreateHotButtonWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManager__CreateHotButtonWnd);
#endif
#ifdef CTAFrameDraw__GetAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation* CTAFrameDraw::GetAnimation(int) const, CTAFrameDraw__GetAnimation);
#endif
#ifdef CSidlManager__TranslateString_x
FUNCTION_AT_ADDRESS(CXStr __cdecl CSidlManager::TranslateString(CXStr), CSidlManager__TranslateString);
#endif
#ifdef CXMLEnumInfo__dCXMLEnumInfo_x
FUNCTION_AT_ADDRESS(CXMLEnumInfo::~CXMLEnumInfo(), CXMLEnumInfo__dCXMLEnumInfo);
#endif
#ifdef CXMLDataClass__dCXMLDataClass_x
FUNCTION_AT_ADDRESS(CXMLDataClass::~CXMLDataClass(), CXMLDataClass__dCXMLDataClass);
#endif
#ifdef CTAFrameDraw__CTAFrameDraw1_x
FUNCTION_AT_ADDRESS(CTAFrameDraw::CTAFrameDraw(CXStr), CTAFrameDraw__CTAFrameDraw1);
#endif
#ifdef CTAFrameDraw__Set_x
FUNCTION_AT_ADDRESS(void CTAFrameDraw::Set(CTextureAnimation** const), CTAFrameDraw__Set);
#endif
#ifdef CTAFrameDraw__Draw_x
FUNCTION_AT_ADDRESS(int CTAFrameDraw::Draw(CXRect, CXRect) const, CTAFrameDraw__Draw);
#endif
#ifdef CTAFrameDraw__Draw1_x
FUNCTION_AT_ADDRESS(int CTAFrameDraw::Draw(CXRect, CXRect, int) const, CTAFrameDraw__Draw1);
#endif
#ifdef CTAFrameDraw__GetHitTestRect_x
FUNCTION_AT_ADDRESS(CXRect CTAFrameDraw::GetHitTestRect(CXRect, int) const, CTAFrameDraw__GetHitTestRect);
#endif
#ifdef CTAFrameDraw__GetPieceRect_x
FUNCTION_AT_ADDRESS(CXRect CTAFrameDraw::GetPieceRect(CXRect, int) const, CTAFrameDraw__GetPieceRect);
#endif
#ifdef CTAFrameDraw__IsHorizontal_x
FUNCTION_AT_ADDRESS(bool CTAFrameDraw::IsHorizontal() const, CTAFrameDraw__IsHorizontal);
#endif
#ifdef CTAFrameDraw__IsVertical_x
FUNCTION_AT_ADDRESS(bool CTAFrameDraw::IsVertical() const, CTAFrameDraw__IsVertical);
#endif
#ifdef CTAFrameDraw__GetExtent_x
FUNCTION_AT_ADDRESS(int CTAFrameDraw::GetExtent() const, CTAFrameDraw__GetExtent);
#endif
#ifdef CTAFrameDraw__GetMinLength_x
FUNCTION_AT_ADDRESS(int CTAFrameDraw::GetMinLength() const, CTAFrameDraw__GetMinLength);
#endif
#ifdef CTAFrameDraw__GetInnerRect_x
FUNCTION_AT_ADDRESS(CXRect CTAFrameDraw::GetInnerRect(CXRect) const, CTAFrameDraw__GetInnerRect);
#endif
#ifdef CSpellGemWnd__CSpellGemWnd_x
FUNCTION_AT_ADDRESS(CSpellGemWnd::CSpellGemWnd(CXWnd*, uint32_t, CXRect, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, int, unsigned long), CSpellGemWnd__CSpellGemWnd);
#endif
#ifdef CSpellGemWnd__Init_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::Init(), CSpellGemWnd__Init);
#endif
#ifdef CSpellGemWnd__SetSpellIconIndex_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetSpellIconIndex(int), CSpellGemWnd__SetSpellIconIndex);
#endif
#ifdef CSpellGemWnd__SetSpellGemTint_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetSpellGemTint(unsigned long), CSpellGemWnd__SetSpellGemTint);
#endif
#ifdef CSpellGemWnd__SetGemTintStage_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetGemTintStage(int), CSpellGemWnd__SetGemTintStage);
#endif
#ifdef CSpellGemWnd__SetCheck_x
FUNCTION_AT_ADDRESS(void CSpellGemWnd::SetCheck(bool), CSpellGemWnd__SetCheck);
#endif
#ifdef CSliderWnd__CSliderWnd_x
FUNCTION_AT_ADDRESS(CSliderWnd::CSliderWnd(CXWnd*, uint32_t, CXRect, CSliderTemplate*), CSliderWnd__CSliderWnd);
#endif
#ifdef CSliderWnd__SetValue_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetValue(int), CSliderWnd__SetValue);
#endif
#ifdef CSliderWnd__SetNumTicks_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetNumTicks(int), CSliderWnd__SetNumTicks);
#endif
#ifdef CSliderWnd__UpdateThumb_x
FUNCTION_AT_ADDRESS(void CSliderWnd::UpdateThumb(), CSliderWnd__UpdateThumb);
#endif
#ifdef CSliderWnd__UpdateMiddleRange_x
FUNCTION_AT_ADDRESS(void CSliderWnd::UpdateMiddleRange(), CSliderWnd__UpdateMiddleRange);
#endif
#ifdef CSliderWnd__GetValue_x
FUNCTION_AT_ADDRESS(int CSliderWnd::GetValue() const, CSliderWnd__GetValue);
#endif
#ifdef CSliderWnd__GetMiddleRangeRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetMiddleRangeRect() const, CSliderWnd__GetMiddleRangeRect);
#endif
#ifdef CSliderWnd__GetEndCapLeftRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetEndCapLeftRect() const, CSliderWnd__GetEndCapLeftRect);
#endif
#ifdef CSliderWnd__GetEndCapRightRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetEndCapRightRect() const, CSliderWnd__GetEndCapRightRect);
#endif
#ifdef CSliderWnd__GetThumbRect_x
FUNCTION_AT_ADDRESS(CXRect CSliderWnd::GetThumbRect() const, CSliderWnd__GetThumbRect);
#endif
#ifdef CSliderWnd__SetThumbToOffset_x
FUNCTION_AT_ADDRESS(void CSliderWnd::SetThumbToOffset(int), CSliderWnd__SetThumbToOffset);
#endif
#ifdef CSliderWnd__DrawMiddleRange_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawMiddleRange() const, CSliderWnd__DrawMiddleRange);
#endif
#ifdef CSliderWnd__DrawEndCapLeft_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawEndCapLeft() const, CSliderWnd__DrawEndCapLeft);
#endif
#ifdef CSliderWnd__DrawEndCapRight_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawEndCapRight() const, CSliderWnd__DrawEndCapRight);
#endif
#ifdef CSliderWnd__DrawThumb_x
FUNCTION_AT_ADDRESS(int CSliderWnd::DrawThumb() const, CSliderWnd__DrawThumb);
#endif
#ifdef CEditBaseWnd__SetSel_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetSel(int, int), CEditBaseWnd__SetSel);
#endif
#ifdef CInvSlotWnd__CInvSlotWnd_x
CONSTRUCTOR_AT_ADDRESS(CInvSlotWnd::CInvSlotWnd(CXWnd* pParent, uint32_t ID, CXRect rect,
	CTextureAnimation* ptaBackground, const ItemGlobalIndex& itemLocation, int ItemOffsetX, int ItemOffsetY), CInvSlotWnd__CInvSlotWnd);
#endif
#ifdef CInvSlotWnd__SetInvSlot_x
FUNCTION_AT_ADDRESS(void CInvSlotWnd::SetInvSlot(CInvSlot*), CInvSlotWnd__SetInvSlot);
#endif
#ifdef CInvSlotWnd__DrawTooltip_x
FUNCTION_AT_ADDRESS(int CInvSlotWnd::DrawTooltip(const CXWnd*) const, CInvSlotWnd__DrawTooltip);
#endif
#ifdef CLabel__CLabel_x
FUNCTION_AT_ADDRESS(CLabel::CLabel(CXWnd*, uint32_t, CXRect*, int), CLabel__CLabel);
#endif
#ifdef CLabel__SetNoWrap_x
FUNCTION_AT_ADDRESS(void CLabel::SetNoWrap(bool), CLabel__SetNoWrap);
#endif
#ifdef CLabel__SetAlignRight_x
FUNCTION_AT_ADDRESS(void CLabel::SetAlignRight(bool), CLabel__SetAlignRight);
#endif
#ifdef CLabel__SetAlignCenter_x
FUNCTION_AT_ADDRESS(void CLabel::SetAlignCenter(bool), CLabel__SetAlignCenter);
#endif
#ifdef CIMEManager__CIMEManager_x
FUNCTION_AT_ADDRESS(CIMEManager::CIMEManager(struct HWND__*), CIMEManager__CIMEManager);
#endif
#ifdef CIMEManager__dCIMEManager_x
FUNCTION_AT_ADDRESS(CIMEManager::~CIMEManager(), CIMEManager__dCIMEManager);
#endif
#ifdef CIMEManager__handleWndProc_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleWndProc(unsigned int, unsigned int, long), CIMEManager__handleWndProc);
#endif
#ifdef CIMEManager__handleAddChar_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleAddChar(unsigned short), CIMEManager__handleAddChar);
#endif
#ifdef CIMEManager__handleInputComposition_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleInputComposition(long), CIMEManager__handleInputComposition);
#endif
#ifdef CIMEManager__handleEndComposition_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleEndComposition(), CIMEManager__handleEndComposition);
#endif
#ifdef CIMEManager__handleStartComposition_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleStartComposition(), CIMEManager__handleStartComposition);
#endif
#ifdef CIMEManager__handleOpenCandidates_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleOpenCandidates(), CIMEManager__handleOpenCandidates);
#endif
#ifdef CIMEManager__handleChangeCandidates_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleChangeCandidates(), CIMEManager__handleChangeCandidates);
#endif
#ifdef CIMEManager__handleCloseCandidates_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleCloseCandidates(), CIMEManager__handleCloseCandidates);
#endif
#ifdef CIMEManager__handleImeStatusChanged_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleImeStatusChanged(), CIMEManager__handleImeStatusChanged);
#endif
#ifdef CIMEManager__handleImeChanged_x
FUNCTION_AT_ADDRESS(int CIMEManager::handleImeChanged(), CIMEManager__handleImeChanged);
#endif
#ifdef CIMEManager__setInputEditWnd_x
FUNCTION_AT_ADDRESS(int CIMEManager::setInputEditWnd(CEditWnd*), CIMEManager__setInputEditWnd);
#endif
#ifdef CIMEManager__turnImeOn_x
FUNCTION_AT_ADDRESS(void CIMEManager::turnImeOn(), CIMEManager__turnImeOn);
#endif
#ifdef CIMEManager__turnImeOff_x
FUNCTION_AT_ADDRESS(void CIMEManager::turnImeOff(), CIMEManager__turnImeOff);
#endif
#ifdef CIMEManager__imeIsOn_x
FUNCTION_AT_ADDRESS(bool CIMEManager::imeIsOn() const, CIMEManager__imeIsOn);
#endif
#ifdef CIMEManager__imeIsOff_x
FUNCTION_AT_ADDRESS(bool CIMEManager::imeIsOff() const, CIMEManager__imeIsOff);
#endif
#ifdef CIMEManager__enableIme_x
FUNCTION_AT_ADDRESS(void CIMEManager::enableIme(bool), CIMEManager__enableIme);
#endif
#ifdef CIMEManager__queryImeLanguage_x
FUNCTION_AT_ADDRESS(int CIMEManager::queryImeLanguage() const, CIMEManager__queryImeLanguage);
#endif
#ifdef CIMEManager__queryImeProperties_x
FUNCTION_AT_ADDRESS(int CIMEManager::queryImeProperties() const, CIMEManager__queryImeProperties);
#endif
#ifdef CIMEManager__setInputState_x
FUNCTION_AT_ADDRESS(void CIMEManager::setInputState(int), CIMEManager__setInputState);
#endif
#ifdef CIMEManager__getInputState_x
FUNCTION_AT_ADDRESS(int CIMEManager::getInputState() const, CIMEManager__getInputState);
#endif
#ifdef CIMEManager__getInputLanguage_x
FUNCTION_AT_ADDRESS(int CIMEManager::getInputLanguage() const, CIMEManager__getInputLanguage);
#endif
#ifdef CIMEManager__getImeProperties_x
FUNCTION_AT_ADDRESS(int CIMEManager::getImeProperties() const, CIMEManager__getImeProperties);
#endif
#ifdef CIMEManager__getWindowHandle_x
FUNCTION_AT_ADDRESS(struct HWND__* CIMEManager::getWindowHandle() const, CIMEManager__getWindowHandle);
#endif
#ifdef CUITextureInfo__Draw_x
FUNCTION_AT_ADDRESS(int CUITextureInfo::Draw(CXRect, CXRect, class CXRect, unsigned long, unsigned long) const, CUITextureInfo__Draw);
#endif
#ifdef CUITextureInfo__Draw1_x
FUNCTION_AT_ADDRESS(int CUITextureInfo::Draw(CXRect, CXRect, class CXRect, unsigned long*, unsigned long*) const, CUITextureInfo__Draw1);
#endif
#ifdef CUITexturePiece__Draw_x
FUNCTION_AT_ADDRESS(int CUITexturePiece::Draw(CXRect, CXRect, unsigned long, unsigned long) const, CUITexturePiece__Draw);
#endif
#ifdef CUITexturePiece__Draw1_x
FUNCTION_AT_ADDRESS(int CUITexturePiece::Draw(CXRect, CXRect, class CXRect, unsigned long, unsigned long) const, CUITexturePiece__Draw1);
#endif
#ifdef CUITextureInfo__Tile_x
FUNCTION_AT_ADDRESS(int CUITextureInfo::Tile(CXRect, unsigned long, unsigned long) const, CUITextureInfo__Tile);
#endif
#ifdef CUITextureInfo__Tile1_x
FUNCTION_AT_ADDRESS(int CUITextureInfo::Tile(CXRect, unsigned long*, unsigned long*) const, CUITextureInfo__Tile1);
#endif
#ifdef CUITextureInfo__Preload_x
FUNCTION_AT_ADDRESS(int CUITextureInfo::Preload(), CUITextureInfo__Preload);
#endif
#ifdef CXMLDataPtr__SetNewPtr_x
FUNCTION_AT_ADDRESS(void CXMLDataPtr::SetNewPtr(CXMLData*), CXMLDataPtr__SetNewPtr);
#endif
#ifdef CXMLEnumInfo__GetStreamSize_x
FUNCTION_AT_ADDRESS(int CXMLEnumInfo::GetStreamSize(), CXMLEnumInfo__GetStreamSize);
#endif
#ifdef CXMLEnumInfo__ReadFromStream_x
FUNCTION_AT_ADDRESS(void CXMLEnumInfo::ReadFromStream(CMemoryStream&), CXMLEnumInfo__ReadFromStream);
#endif
#ifdef CMemoryStream__GetString_x
FUNCTION_AT_ADDRESS(void CMemoryStream::GetString(CXStr&), CMemoryStream__GetString);
#endif
#ifdef CXMLEnumInfo__WriteToStream_x
FUNCTION_AT_ADDRESS(void CXMLEnumInfo::WriteToStream(CMemoryStream&), CXMLEnumInfo__WriteToStream);
#endif
#ifdef CXMLDataClass__GetNumLeaf_x
FUNCTION_AT_ADDRESS(int CXMLDataClass::GetNumLeaf(), CXMLDataClass__GetNumLeaf);
#endif
#ifdef CXMLDataClass__GetStreamSize_x
FUNCTION_AT_ADDRESS(int CXMLDataClass::GetStreamSize(), CXMLDataClass__GetStreamSize);
#endif
#ifdef CXMLDataClass__ReadFromStream_x
FUNCTION_AT_ADDRESS(void CXMLDataClass::ReadFromStream(CMemoryStream&, CXMLDataManager&), CXMLDataClass__ReadFromStream);
#endif
#ifdef CXMLDataClass__WriteToStream_x
FUNCTION_AT_ADDRESS(void CXMLDataClass::WriteToStream(CMemoryStream&), CXMLDataClass__WriteToStream);
#endif
#ifdef CXMLDataManager__CXMLDataManager_x
FUNCTION_AT_ADDRESS(CXMLDataManager::CXMLDataManager(), CXMLDataManager__CXMLDataManager);
#endif
#ifdef CXMLDataManager__GetXMLData_x
FUNCTION_AT_ADDRESS(CXMLData* CXMLDataManager::GetXMLData(int, int), CXMLDataManager__GetXMLData);
#endif
#ifdef CXMLDataManager__GetXMLData1_x
FUNCTION_AT_ADDRESS(CXMLData* CXMLDataManager::GetXMLData(CXStr, CXStr), CXMLDataManager__GetXMLData1);
#endif
#ifdef CXMLDataManager__GetNumClass_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetNumClass(), CXMLDataManager__GetNumClass);
#endif
#ifdef CXMLDataManager__GetNumItem_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetNumItem(int), CXMLDataManager__GetNumItem);
#endif
#ifdef CXMLDataManager__GetClassIdx_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetClassIdx(CXStr), CXMLDataManager__GetClassIdx);
#endif
#ifdef CXMLDataManager__GetItemIdx_x
FUNCTION_AT_ADDRESS(int CXMLDataManager::GetItemIdx(int, CXStr), CXMLDataManager__GetItemIdx);
#endif
#ifdef CXMLDataPtr__Free_x
FUNCTION_AT_ADDRESS(void CXMLDataPtr::Free(), CXMLDataPtr__Free);
#endif
#ifdef CXMLDataManager__AddToSuperType_x
//FUNCTION_AT_ADDRESS(void CXMLDataManager::AddToSuperType(CXStr, CXMLDataPtr), CXMLDataManager__AddToSuperType);
#endif
#ifdef CXMLDataPtr__operator_equal_x
FUNCTION_AT_ADDRESS(CXMLDataPtr& CXMLDataPtr::operator=(const CXMLDataPtr&), CXMLDataPtr__operator_equal);
#endif
#ifdef CXMLDataManager__IsDerivedFrom_x
FUNCTION_AT_ADDRESS(bool CXMLDataManager::IsDerivedFrom(int, int), CXMLDataManager__IsDerivedFrom);
#endif
#ifdef CXMLDataManager__SetEnumHash_x
FUNCTION_AT_ADDRESS(void CXMLDataManager::SetEnumHash(), CXMLDataManager__SetEnumHash);
#endif
#ifdef CXMLDataManager__ReadFromXMLSOM_x
FUNCTION_AT_ADDRESS(bool CXMLDataManager::ReadFromXMLSOM(CXMLSOMDocument&), CXMLDataManager__ReadFromXMLSOM);
#endif
#ifdef CXMLDataPtr__CXMLDataPtr_x
FUNCTION_AT_ADDRESS(CXMLDataPtr::CXMLDataPtr(), CXMLDataPtr__CXMLDataPtr);
#endif
#ifdef CXMLDataClass__CXMLDataClass_x
FUNCTION_AT_ADDRESS(CXMLDataClass::CXMLDataClass(), CXMLDataClass__CXMLDataClass);
#endif
#ifdef CXMLEnumInfo__CXMLEnumInfo_x
FUNCTION_AT_ADDRESS(CXMLEnumInfo::CXMLEnumInfo(), CXMLEnumInfo__CXMLEnumInfo);
#endif
#ifdef CStmlReport__CreateReport_x
FUNCTION_AT_ADDRESS(CStmlReport* __cdecl CStmlReport::CreateReport(CXStr), CStmlReport__CreateReport);
#endif
#ifdef CXFileXML__Load_x
FUNCTION_AT_ADDRESS(bool CXFileXML::Load(char*), CXFileXML__Load);
#endif
#ifdef CXMLSOMParser__ParseProcess_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseProcess(), CXMLSOMParser__ParseProcess);
#endif
#ifdef CXMLSOMParser__ParseNameSpaceToken_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseNameSpaceToken(CXStr&), CXMLSOMParser__ParseNameSpaceToken);
#endif
#ifdef CXMLSOMParser__ParseStartTag_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseStartTag(bool&), CXMLSOMParser__ParseStartTag);
#endif
#ifdef CXMLSOMParser__ParseEndTag_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseEndTag(CXStr), CXMLSOMParser__ParseEndTag);
#endif
#ifdef CXMLSOMParser__ParseNodeList_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseNodeList(), CXMLSOMParser__ParseNodeList);
#endif
#ifdef CXMLSOMParser__ParseNode_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseNode(), CXMLSOMParser__ParseNode);
#endif
#ifdef CXMLSOMParser__ParseDocument_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseDocument(), CXMLSOMParser__ParseDocument);
#endif
#ifdef CXFileXML__dCXFileXML_x
FUNCTION_AT_ADDRESS(CXFileXML::~CXFileXML(), CXFileXML__dCXFileXML);
#endif
#ifdef CXMLSOMParser__ParseFile_x
FUNCTION_AT_ADDRESS(bool CXMLSOMParser::ParseFile(CXStr), CXMLSOMParser__ParseFile);
#endif
#ifdef CXMLSOMParser__dCXMLSOMParser_x
FUNCTION_AT_ADDRESS(CXMLSOMParser::~CXMLSOMParser(), CXMLSOMParser__dCXMLSOMParser);
#endif
#ifdef CClickStickInfo__CClickStickInfo_x
FUNCTION_AT_ADDRESS(CClickStickInfo::CClickStickInfo(), CClickStickInfo__CClickStickInfo);
#endif
#ifdef CHashCXStrInt32__CHashCXStrInt32_x
FUNCTION_AT_ADDRESS(CHashCXStrInt32::CHashCXStrInt32(), CHashCXStrInt32__CHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__dCHashCXStrInt32_x
FUNCTION_AT_ADDRESS(CHashCXStrInt32::~CHashCXStrInt32(), CHashCXStrInt32__dCHashCXStrInt32);
#endif
#ifdef CHashCXStrInt32__KeyToBin_x
FUNCTION_AT_ADDRESS(int CHashCXStrInt32::KeyToBin(const CXStr&) const, CHashCXStrInt32__KeyToBin);
#endif
#ifdef CHashCXStrInt32__LookUp_x
FUNCTION_AT_ADDRESS(bool CHashCXStrInt32::LookUp(const CXStr&, int&) const, CHashCXStrInt32__LookUp);
#endif
#ifdef CHashCXStrInt32__Insert_x
FUNCTION_AT_ADDRESS(bool CHashCXStrInt32::Insert(const CXStr&, int), CHashCXStrInt32__Insert);
#endif
#ifdef CHashCXStrInt32__Reset_x
FUNCTION_AT_ADDRESS(void CHashCXStrInt32::Reset(), CHashCXStrInt32__Reset);
#endif
#ifdef CParamPoint__operator_equal_x
FUNCTION_AT_ADDRESS(CParamPoint& CParamPoint::operator=(const CParamPoint&), CParamPoint__operator_equal);
#endif
#ifdef CParamSize__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSize& CParamSize::operator=(const CParamSize&), CParamSize__operator_equal);
#endif
#ifdef CParamGaugeDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamGaugeDrawTemplate& CParamGaugeDrawTemplate::operator=(const CParamGaugeDrawTemplate&), CParamGaugeDrawTemplate__operator_equal);
#endif
#ifdef CParamSpellGemDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSpellGemDrawTemplate& CParamSpellGemDrawTemplate::operator=(const CParamSpellGemDrawTemplate&), CParamSpellGemDrawTemplate__operator_equal);
#endif
#ifdef CParamScreenPiece__operator_equal_x
FUNCTION_AT_ADDRESS(CParamScreenPiece& CParamScreenPiece::operator=(const CParamScreenPiece&), CParamScreenPiece__operator_equal);
#endif
#ifdef CParamControl__operator_equal_x
FUNCTION_AT_ADDRESS(CParamControl& CParamControl::operator=(const CParamControl&), CParamControl__operator_equal);
#endif
#ifdef CParamSliderDrawTemplate__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSliderDrawTemplate& CParamSliderDrawTemplate::operator=(const CParamSliderDrawTemplate&), CParamSliderDrawTemplate__operator_equal);
#endif
#ifdef CParamStaticText__operator_equal_x
FUNCTION_AT_ADDRESS(CParamStaticText& CParamStaticText::operator=(const CParamStaticText&), CParamStaticText__operator_equal);
#endif
#ifdef CParamStaticAnimation__operator_equal_x
FUNCTION_AT_ADDRESS(CParamStaticAnimation& CParamStaticAnimation::operator=(const CParamStaticAnimation&), CParamStaticAnimation__operator_equal);
#endif
#ifdef CParamStaticFrame__operator_equal_x
FUNCTION_AT_ADDRESS(CParamStaticFrame& CParamStaticFrame::operator=(const CParamStaticFrame&), CParamStaticFrame__operator_equal);
#endif
#ifdef CParamStaticHeader__operator_equal_x
FUNCTION_AT_ADDRESS(CParamStaticHeader& CParamStaticHeader::operator=(const CParamStaticHeader&), CParamStaticHeader__operator_equal);
#endif
#ifdef CParamListboxColumn__operator_equal_x
FUNCTION_AT_ADDRESS(CParamListboxColumn& CParamListboxColumn::operator=(const CParamListboxColumn&), CParamListboxColumn__operator_equal);
#endif
#ifdef CParamListbox__operator_equal_x
FUNCTION_AT_ADDRESS(CParamListbox& CParamListbox::operator=(const CParamListbox&), CParamListbox__operator_equal);
#endif
#ifdef CParamButton__operator_equal_x
FUNCTION_AT_ADDRESS(CParamButton& CParamButton::operator=(const CParamButton&), CParamButton__operator_equal);
#endif
#ifdef CParamGauge__operator_equal_x
FUNCTION_AT_ADDRESS(CParamGauge& CParamGauge::operator=(const CParamGauge&), CParamGauge__operator_equal);
#endif
#ifdef CParamSpellGem__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSpellGem& CParamSpellGem::operator=(const CParamSpellGem&), CParamSpellGem__operator_equal);
#endif
#ifdef CParamInvSlot__operator_equal_x
FUNCTION_AT_ADDRESS(CParamInvSlot& CParamInvSlot::operator=(const CParamInvSlot&), CParamInvSlot__operator_equal);
#endif
#ifdef CParamEditbox__operator_equal_x
FUNCTION_AT_ADDRESS(CParamEditbox& CParamEditbox::operator=(const CParamEditbox&), CParamEditbox__operator_equal);
#endif
#ifdef CParamSlider__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSlider& CParamSlider::operator=(const CParamSlider&), CParamSlider__operator_equal);
#endif
#ifdef CParamLabel__operator_equal_x
FUNCTION_AT_ADDRESS(CParamLabel& CParamLabel::operator=(const CParamLabel&), CParamLabel__operator_equal);
#endif
#ifdef CParamCombobox__operator_equal_x
FUNCTION_AT_ADDRESS(CParamCombobox& CParamCombobox::operator=(const CParamCombobox&), CParamCombobox__operator_equal);
#endif
#ifdef CParamPage__operator_equal_x
FUNCTION_AT_ADDRESS(CParamPage& CParamPage::operator=(const CParamPage&), CParamPage__operator_equal);
#endif
#ifdef CParamTabBox__operator_equal_x
FUNCTION_AT_ADDRESS(CParamTabBox& CParamTabBox::operator=(const CParamTabBox&), CParamTabBox__operator_equal);
#endif
#ifdef CParamScreen__operator_equal_x
FUNCTION_AT_ADDRESS(CParamScreen& CParamScreen::operator=(const CParamScreen&), CParamScreen__operator_equal);
#endif
#ifdef CParamSuiteDefaults__operator_equal_x
FUNCTION_AT_ADDRESS(CParamSuiteDefaults& CParamSuiteDefaults::operator=(const CParamSuiteDefaults&), CParamSuiteDefaults__operator_equal);
#endif
#ifdef CParamClass__CParamClass_x
FUNCTION_AT_ADDRESS(CParamClass::CParamClass(), CParamClass__CParamClass);
#endif
#ifdef CParamRGB__CParamRGB_x
FUNCTION_AT_ADDRESS(CParamRGB::CParamRGB(), CParamRGB__CParamRGB);
#endif
#ifdef CParamPoint__CParamPoint_x
FUNCTION_AT_ADDRESS(CParamPoint::CParamPoint(), CParamPoint__CParamPoint);
#endif
#ifdef CParamSize__CParamSize_x
FUNCTION_AT_ADDRESS(CParamSize::CParamSize(), CParamSize__CParamSize);
#endif
#ifdef CParamTextureInfo__CParamTextureInfo_x
FUNCTION_AT_ADDRESS(CParamTextureInfo::CParamTextureInfo(), CParamTextureInfo__CParamTextureInfo);
#endif
#ifdef CParamFrame__CParamFrame_x
FUNCTION_AT_ADDRESS(CParamFrame::CParamFrame(), CParamFrame__CParamFrame);
#endif
#ifdef CParamUi2DAnimation__CParamUi2DAnimation_x
FUNCTION_AT_ADDRESS(CParamUi2DAnimation::CParamUi2DAnimation(), CParamUi2DAnimation__CParamUi2DAnimation);
#endif
#ifdef CParamButtonDrawTemplate__CParamButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamButtonDrawTemplate::CParamButtonDrawTemplate(), CParamButtonDrawTemplate__CParamButtonDrawTemplate);
#endif
#ifdef CParamGaugeDrawTemplate__CParamGaugeDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamGaugeDrawTemplate::CParamGaugeDrawTemplate(), CParamGaugeDrawTemplate__CParamGaugeDrawTemplate);
#endif
#ifdef CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamSpellGemDrawTemplate::CParamSpellGemDrawTemplate(), CParamSpellGemDrawTemplate__CParamSpellGemDrawTemplate);
#endif
#ifdef CParamFrameTemplate__CParamFrameTemplate_x
FUNCTION_AT_ADDRESS(CParamFrameTemplate::CParamFrameTemplate(), CParamFrameTemplate__CParamFrameTemplate);
#endif
#ifdef CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamScrollbarDrawTemplate::CParamScrollbarDrawTemplate(), CParamScrollbarDrawTemplate__CParamScrollbarDrawTemplate);
#endif
#ifdef CParamWindowDrawTemplate__CParamWindowDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamWindowDrawTemplate::CParamWindowDrawTemplate(), CParamWindowDrawTemplate__CParamWindowDrawTemplate);
#endif
#ifdef CParamSliderDrawTemplate__CParamSliderDrawTemplate_x
FUNCTION_AT_ADDRESS(CParamSliderDrawTemplate::CParamSliderDrawTemplate(), CParamSliderDrawTemplate__CParamSliderDrawTemplate);
#endif
#ifdef CParamScreenPiece__CParamScreenPiece_x
FUNCTION_AT_ADDRESS(CParamScreenPiece::CParamScreenPiece(), CParamScreenPiece__CParamScreenPiece);
#endif
#ifdef CParamStaticScreenPiece__CParamStaticScreenPiece_x
FUNCTION_AT_ADDRESS(CParamStaticScreenPiece::CParamStaticScreenPiece(), CParamStaticScreenPiece__CParamStaticScreenPiece);
#endif
#ifdef CParamStaticAnimation__CParamStaticAnimation_x
FUNCTION_AT_ADDRESS(CParamStaticAnimation::CParamStaticAnimation(), CParamStaticAnimation__CParamStaticAnimation);
#endif
#ifdef CParamStaticText__CParamStaticText_x
FUNCTION_AT_ADDRESS(CParamStaticText::CParamStaticText(), CParamStaticText__CParamStaticText);
#endif
#ifdef CParamStaticFrame__CParamStaticFrame_x
FUNCTION_AT_ADDRESS(CParamStaticFrame::CParamStaticFrame(), CParamStaticFrame__CParamStaticFrame);
#endif
#ifdef CParamStaticHeader__CParamStaticHeader_x
FUNCTION_AT_ADDRESS(CParamStaticHeader::CParamStaticHeader(), CParamStaticHeader__CParamStaticHeader);
#endif
#ifdef CParamControl__CParamControl_x
FUNCTION_AT_ADDRESS(CParamControl::CParamControl(), CParamControl__CParamControl);
#endif
#ifdef CParamListboxColumn__CParamListboxColumn_x
FUNCTION_AT_ADDRESS(CParamListboxColumn::CParamListboxColumn(), CParamListboxColumn__CParamListboxColumn);
#endif
#ifdef CParamListbox__CParamListbox_x
FUNCTION_AT_ADDRESS(CParamListbox::CParamListbox(), CParamListbox__CParamListbox);
#endif
#ifdef CParamButton__CParamButton_x
FUNCTION_AT_ADDRESS(CParamButton::CParamButton(), CParamButton__CParamButton);
#endif
#ifdef CParamGauge__CParamGauge_x
FUNCTION_AT_ADDRESS(CParamGauge::CParamGauge(), CParamGauge__CParamGauge);
#endif
#ifdef CParamSpellGem__CParamSpellGem_x
FUNCTION_AT_ADDRESS(CParamSpellGem::CParamSpellGem(), CParamSpellGem__CParamSpellGem);
#endif
#ifdef CParamInvSlot__CParamInvSlot_x
FUNCTION_AT_ADDRESS(CParamInvSlot::CParamInvSlot(), CParamInvSlot__CParamInvSlot);
#endif
#ifdef CParamEditbox__CParamEditbox_x
FUNCTION_AT_ADDRESS(CParamEditbox::CParamEditbox(), CParamEditbox__CParamEditbox);
#endif
#ifdef CParamSlider__CParamSlider_x
FUNCTION_AT_ADDRESS(CParamSlider::CParamSlider(), CParamSlider__CParamSlider);
#endif
#ifdef CParamLabel__CParamLabel_x
FUNCTION_AT_ADDRESS(CParamLabel::CParamLabel(), CParamLabel__CParamLabel);
#endif
#ifdef CParamSTMLbox__CParamSTMLbox_x
FUNCTION_AT_ADDRESS(CParamSTMLbox::CParamSTMLbox(), CParamSTMLbox__CParamSTMLbox);
#endif
#ifdef CParamCombobox__CParamCombobox_x
FUNCTION_AT_ADDRESS(CParamCombobox::CParamCombobox(), CParamCombobox__CParamCombobox);
#endif
#ifdef CParamPage__CParamPage_x
FUNCTION_AT_ADDRESS(CParamPage::CParamPage(), CParamPage__CParamPage);
#endif
#ifdef CParamTabBox__CParamTabBox_x
FUNCTION_AT_ADDRESS(CParamTabBox::CParamTabBox(), CParamTabBox__CParamTabBox);
#endif
#ifdef CParamScreen__CParamScreen_x
FUNCTION_AT_ADDRESS(CParamScreen::CParamScreen(), CParamScreen__CParamScreen);
#endif
#ifdef CParamSuiteDefaults__CParamSuiteDefaults_x
FUNCTION_AT_ADDRESS(CParamSuiteDefaults::CParamSuiteDefaults(), CParamSuiteDefaults__CParamSuiteDefaults);
#endif
#ifdef CXMLData__CXMLData_x
FUNCTION_AT_ADDRESS(CXMLData::CXMLData(), CXMLData__CXMLData);
#endif
#ifdef CPageWnd__CPageWnd_x
FUNCTION_AT_ADDRESS(CPageWnd::CPageWnd(CXWnd*, uint32_t, CXRect, class CXStr, CPageTemplate*), CPageWnd__CPageWnd);
#endif
#ifdef CGaugeWnd__CGaugeWnd_x
FUNCTION_AT_ADDRESS(CGaugeWnd::CGaugeWnd(CXWnd*, uint32_t, CXRect, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, unsigned long, unsigned long, bool, int, int, int, int), CGaugeWnd__CGaugeWnd);
#endif
#ifdef CGaugeWnd__CalcFillRect_x
FUNCTION_AT_ADDRESS(CXRect CGaugeWnd::CalcFillRect(CXRect*, int) const, CGaugeWnd__CalcFillRect);
#endif
#ifdef CGaugeWnd__CalcLinesFillRect_x
FUNCTION_AT_ADDRESS(CXRect CGaugeWnd::CalcLinesFillRect(CXRect*, int) const, CGaugeWnd__CalcLinesFillRect);
#endif
#ifdef CGaugeWnd__SpecialToolTip_x
FUNCTION_AT_ADDRESS(void CGaugeWnd::SpecialToolTip(), CGaugeWnd__SpecialToolTip);
#endif
#ifdef CCheckBoxWnd__CCheckBoxWnd_x
FUNCTION_AT_ADDRESS(CCheckBoxWnd::CCheckBoxWnd(CXWnd*, uint32_t, CXRect, class CXPoint, CXSize, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*), CCheckBoxWnd__CCheckBoxWnd);
#endif
#ifdef CCheckBoxWnd__SetRadioLook_x
FUNCTION_AT_ADDRESS(void CCheckBoxWnd::SetRadioLook(), CCheckBoxWnd__SetRadioLook);
#endif
#ifdef CMemoryStream__GetStringSize_x
FUNCTION_AT_ADDRESS(int __cdecl CMemoryStream::GetStringSize(CXStr&), CMemoryStream__GetStringSize);
#endif
#ifdef CMemoryStream__PutString_x
FUNCTION_AT_ADDRESS(void CMemoryStream::PutString(CXStr&), CMemoryStream__PutString);
#endif
#ifdef CMemoryStream__GetString1_x
FUNCTION_AT_ADDRESS(CXStr CMemoryStream::GetString(), CMemoryStream__GetString1);
#endif
#ifdef CXMLSOMDocument__GetValueObjectId_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocument::GetValueObjectId(CXStr, CXStr, uint32_t&), CXMLSOMDocument__GetValueObjectId);
#endif
#ifdef CXMLSOMDocument__SetValueObjectId_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocument::SetValueObjectId(CXStr, CXStr, uint32_t), CXMLSOMDocument__SetValueObjectId);
#endif
#ifdef CXMLSOMDocument__FieldParseItemOfClass_x
FUNCTION_AT_ADDRESS(bool CXMLSOMDocument::FieldParseItemOfClass(CXStr, CXStr, uint32_t&), CXMLSOMDocument__FieldParseItemOfClass);
#endif
#ifdef CTextOverlay__DisplayText_x
//this is really:
//EQLIB_OBJECT void CBroadcast::BroadcastString(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime);
FUNCTION_AT_ADDRESS(void CTextOverlay::DisplayText(const char* Str, int TextColor, int Priority, int MaxAlpha, UINT FadeInTime, UINT FadeOutTime, UINT DisplayTime), CTextOverlay__DisplayText);
#endif
#ifdef CDBStr__GetString_x
// GetString(index, subindex, &success)
FUNCTION_AT_ADDRESS(const char* CDBStr::GetString(int, int, bool*), CDBStr__GetString);
#endif
#ifdef EQMisc__GetActiveFavorCost_x
FUNCTION_AT_ADDRESS(int EQMisc::GetActiveFavorCost(), EQMisc__GetActiveFavorCost);
#endif
#ifdef CSkillMgr__GetNameToken_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetNameToken(int), CSkillMgr__GetNameToken);
#endif
#ifdef CSkillMgr__IsCombatSkill_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsCombatSkill(int), CSkillMgr__IsCombatSkill);
#endif
#ifdef CSkillMgr__GetSkillCap_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetSkillCap(EQ_Character*, int, int, int, bool, bool, bool), CSkillMgr__GetSkillCap)
#endif
#ifdef CSkillMgr__SkillAvailableAtLevel_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::SkillAvailableAtLevel(int, int), CSkillMgr__SkillAvailableAtLevel);
#endif
#ifdef CSkillMgr__IsActivatedSkill_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsActivatedSkill(int), CSkillMgr__IsActivatedSkill);
#endif
#ifdef CSkillMgr__GetBaseDamage_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetBaseDamage(int), CSkillMgr__GetBaseDamage);
#endif
#ifdef CSkillMgr__GetReuseTime_x
FUNCTION_AT_ADDRESS(unsigned long CSkillMgr::GetReuseTime(int), CSkillMgr__GetReuseTime);
#endif
#ifdef CSkillMgr__IsAvailable_x
FUNCTION_AT_ADDRESS(bool CSkillMgr::IsAvailable(int), CSkillMgr__IsAvailable);
#endif
#ifdef CChatService__GetNumberOfFriends_x
FUNCTION_AT_ADDRESS(int CChatService::GetNumberOfFriends(), CChatService__GetNumberOfFriends);
#endif
#ifdef CChatService__GetFriendName_x
FUNCTION_AT_ADDRESS(char* CChatService::GetFriendName(int), CChatService__GetFriendName);
#endif
#ifdef PlayerPointManager__GetAltCurrency_x
FUNCTION_AT_ADDRESS(unsigned long PlayerPointManager::GetAltCurrency(unsigned long, unsigned long), PlayerPointManager__GetAltCurrency);
#endif
#ifdef CharacterZoneClient__CharacterZoneClient_x
FUNCTION_AT_ADDRESS(CharacterZoneClient::CharacterZoneClient(), CharacterZoneClient__CharacterZoneClient);
#endif
#ifdef CharacterZoneClient__HasSkill_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::HasSkill(int), CharacterZoneClient__HasSkill);
#endif
#ifdef CharacterZoneClient__MakeMeVisible_x
FUNCTION_AT_ADDRESS(void CharacterZoneClient::MakeMeVisible(int, bool), CharacterZoneClient__MakeMeVisible);
#endif
#ifdef CharacterZoneClient__GetItemCountWorn_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountWorn(int), CharacterZoneClient__GetItemCountWorn);
#endif
#ifdef CharacterZoneClient__GetItemCountInInventory_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountInInventory(int), CharacterZoneClient__GetItemCountInInventory);
#endif
#ifdef CharacterZoneClient__GetCursorItemCount_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetCursorItemCount(int), CharacterZoneClient__GetCursorItemCount);
#endif
#ifdef CharacterZoneClient__ApplyDamage_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::ApplyDamage(int, int, int, int, int, int), CharacterZoneClient__ApplyDamage);
#endif
#ifdef PcZoneClient__GetPcSkillLimit_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetPcSkillLimit(int), PcZoneClient__GetPcSkillLimit);
#endif
#ifdef PcZoneClient__HasCombatAbility_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasCombatAbility(int), PcZoneClient__HasCombatAbility);
#endif
#ifdef PcZoneClient__RemovePetEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemovePetEffect(int), PcZoneClient__RemovePetEffect);
#endif
#ifdef PcZoneClient__HasAlternateAbility_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasAlternateAbility(int aaindex, int*, bool, bool), PcZoneClient__HasAlternateAbility);
#else
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasAlternateAbility(int aaindex, int*, bool), PcZoneClient__HasAlternateAbility);
#endif
#endif
#ifdef PcZoneClient__GetItemByID_x
FUNCTION_AT_ADDRESS(PCONTENTS* PcZoneClient::GetItemByID(PCONTENTS* contOut, int itemid, ItemIndex*), PcZoneClient__GetItemByID);
#endif
#ifdef PcZoneClient__GetItemByItemClass_x
FUNCTION_AT_ADDRESS(PCONTENTS* PcZoneClient::GetItemByItemClass(PCONTENTS* contOut, int itemclass, ItemIndex*), PcZoneClient__GetItemByItemClass);
#endif
#ifdef PcZoneClient__CanEquipItem_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::CanEquipItem(PCONTENTS* pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel), PcZoneClient__CanEquipItem);
#endif
#ifdef PcZoneClient__GetCurrentMod_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetCurrentMod(int index), PcZoneClient__GetCurrentMod);
#endif
#ifdef PcZoneClient__GetModCap_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(int PcZoneClient::GetModCap(int index, bool bToggle), PcZoneClient__GetModCap);
#else
FUNCTION_AT_ADDRESS(int PcZoneClient::GetModCap(int index), PcZoneClient__GetModCap);
#endif
#endif
#ifdef PcZoneClient__RemoveBuffEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemoveBuffEffect(int Index, int SpawnID), PcZoneClient__RemoveBuffEffect);
#endif
#ifdef PcZoneClient__BandolierSwap_x
FUNCTION_AT_ADDRESS(void PcZoneClient::BandolierSwap(int index), PcZoneClient__BandolierSwap);
#endif
#ifdef PcZoneClient__GetLinkedSpellReuseTimer_x
FUNCTION_AT_ADDRESS(UINT PcZoneClient::GetLinkedSpellReuseTimer(int index), PcZoneClient__GetLinkedSpellReuseTimer);
#endif
#ifdef EQSpellStrings__GetString_x
#if !defined(ROF2EMU) && !defined(UFEMU)
FUNCTION_AT_ADDRESS(char* EQSpellStrings::GetString(int SpellID, int StrIndex), EQSpellStrings__GetString);
#endif
#endif

#pragma warning(pop)
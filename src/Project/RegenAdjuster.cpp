#include "RegenAdjuster.h"

void Loki::RegenAdjuster::ActorUpdateF(RE::Actor* a_actor, float a_zPos, RE::TESObjectCELL* a_cell) {

	auto ptr = Loki::RegenAdjuster::GetSingleton();

	a_actor->SetActorValue(RE::ActorValue::kCombatHealthRegenMultiply, ptr->CombatHealRate);
	SetGMST("fCombatMagickaRegenRateMult", ptr->CombatMagickaRate);
	SetGMST("fCombatStaminaRegenRateMult", ptr->CombatStaminaRate);

	SetGMST("fPowerAttackStaminaPenalty", ptr->PowerAttackStaminaPenalty);

	SetGMST("fSprintStaminaDrainMult", ptr->SprintStaminaDrainMult);
	SetGMST("fSprintStaminaWeightBase", ptr->SprintStaminaWeightBase);
	SetGMST("fSprintStaminaWeightMult", ptr->SprintStaminaWeightMult);

	SetGMST("fHealthRegenDelayMax", ptr->HealthRegenDelay);
	SetGMST("fDamagedHealthRegenDelay", ptr->DmgHealthRegenDelay);

	SetGMST("fStaminaRegenDelayMax", ptr->StaminaRegenDelay);
	SetGMST("fDamagedStaminaRegenDelay", ptr->DmgStaminaRegenDelay);

	SetGMST("fMagickaRegenDelayMax", ptr->MagickaRegenDelay);
	SetGMST("fDamagedMagickaRegenDelay", ptr->DmgMagickaRegenDelay);

	SetGMST("fOutOfBreathStaminaRegenDelay", ptr->OutOfBreath);

	float hRate = ptr->HealRate, sRate = ptr->StaminaRate, mRate = ptr->MagickaRate;

	if (a_actor->IsSneaking()) {
		hRate = ptr->IdleHealRate, sRate = ptr->IdleStaminaRate, mRate = ptr->IdleMagickaRate;
	}
	if (a_actor->IsRunning()) {
		hRate = ptr->RunHealRate, sRate = ptr->RunStaminaRate, mRate = ptr->RunMagickaRate;
	}
	if (a_actor->actorState2.wantBlocking) {
		hRate = ptr->BlockHealRate, sRate = ptr->BlockStaminaRate, mRate = ptr->BlockMagickaRate;
	}
	if (a_actor->IsSprinting()) {
		hRate = ptr->SprintHealRate, mRate = ptr->SprintMagickaRate;
	}
	if (a_actor->IsSwimming()) {
		hRate = ptr->SwimHealRate, sRate = ptr->SwimStaminaRate, mRate = ptr->SwimMagickaRate;
	}

	a_actor->SetActorValue(RE::ActorValue::kHealRate, hRate);
	a_actor->SetActorValue(RE::ActorValue::StaminaRate, sRate);
	a_actor->SetActorValue(RE::ActorValue::kMagickaRate, mRate);

	return _ActorUpdateF(a_actor, a_zPos, a_cell);

};
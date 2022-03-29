#pragma once
#include "C:/dev/simpleini-master/SimpleIni.h"
#include "Project/GMST/GMST.h"

namespace Loki {

	class RegenAdjuster {
	
	public:
        RegenAdjuster() {
            CSimpleIniA ini;
            ini.SetUnicode();
            auto filename = L"Data/SKSE/Plugins/RegenAdjuster.ini";
            SI_Error rc = ini.LoadFile(filename);

            HealRate = ini.GetDoubleValue("BASE", "fHealRate", -1.00f);
            StaminaRate = ini.GetDoubleValue("BASE", "fStaminaRate", -1.00f);
            MagickaRate = ini.GetDoubleValue("BASE", "fMagickaRate", -1.00f);

            HealthRegenDelay = ini.GetDoubleValue("BASE", "fHealthRegenDelayMax", -1.00f);
            DmgHealthRegenDelay = ini.GetDoubleValue("BASE", "fDamagedHealthRegenDelay", -1.00f);

            StaminaRegenDelay = ini.GetDoubleValue("BASE", "fStaminaRegenDelayMax", -1.00f);
            DmgStaminaRegenDelay = ini.GetDoubleValue("BASE", "fDamagedStaminaRegenDelay", -1.00f);

            MagickaRegenDelay = ini.GetDoubleValue("BASE", "fMagickaRegenDelayMax", -1.00f);
            DmgMagickaRegenDelay = ini.GetDoubleValue("BASE", "fDamagedMagickaRegenDelay", -1.00f);

            PowerAttackStaminaPenalty = ini.GetDoubleValue("BASE", "fPowerAttackStaminaPenalty", -1.00f);

            SprintStaminaDrainMult = ini.GetDoubleValue("BASE", "fSprintStaminaDrainMult", -1.00f);
            SprintStaminaWeightBase = ini.GetDoubleValue("BASE", "fSprintStaminaWeightBase", -1.00f);
            SprintStaminaWeightMult = ini.GetDoubleValue("BASE", "fSprintStaminaWeightMult", -1.00f);

            OutOfBreath = ini.GetDoubleValue("BASE", "fOutOfBreathStaminaRegenDelay", -1.00f);

            IdleHealRate = ini.GetDoubleValue("CONDITIONS", "fSneakHealRate", -1.00f);
            IdleStaminaRate = ini.GetDoubleValue("CONDITIONS", "fSneakStaminaRate", -1.00f);
            IdleMagickaRate = ini.GetDoubleValue("CONDITIONS", "fSneakMagickaRate", -1.00f);

            RunHealRate = ini.GetDoubleValue("CONDITIONS", "fRunHealRate", -1.00f);
            RunStaminaRate = ini.GetDoubleValue("CONDITIONS", "fRunStaminaRate", -1.00f);
            RunMagickaRate = ini.GetDoubleValue("CONDITIONS", "fRunMagickaRate", -1.00f);

            BlockHealRate = ini.GetDoubleValue("CONDITIONS", "fBlockHealRate", -1.00f);
            BlockStaminaRate = ini.GetDoubleValue("CONDITIONS", "fBlockStaminaRate", -1.00f);
            BlockMagickaRate = ini.GetDoubleValue("CONDITIONS", "fBlockMagickaRate", -1.00f);

            SprintHealRate = ini.GetDoubleValue("CONDITIONS", "fSprintHealRate", -1.00f);
            SprintMagickaRate = ini.GetDoubleValue("CONDITIONS", "fSprintMagickaRate", -1.00f);

            SwimHealRate = ini.GetDoubleValue("CONDITIONS", "fSwimHealRate", -1.00f);
            SwimStaminaRate = ini.GetDoubleValue("CONDITIONS", "fSwimStaminaRate", -1.00f);
            SwimMagickaRate = ini.GetDoubleValue("CONDITIONS", "fSwimMagickaRate", -1.00f);

            CombatHealRate = ini.GetDoubleValue("CONDITIONS", "fCombatHealRateMult", -1.00f);
            CombatStaminaRate = ini.GetDoubleValue("CONDITIONS", "fCombatStaminaRateMult", -1.00f);
            CombatMagickaRate = ini.GetDoubleValue("CONDITIONS", "fCombatMagickaRateMult", -1.00f);
        }
        virtual ~RegenAdjuster() {
        }
        static RegenAdjuster* GetSingleton() {
            static RegenAdjuster singleton;
            return &singleton;
        }

        float HealRate, StaminaRate, MagickaRate,
        IdleHealRate, IdleStaminaRate, IdleMagickaRate,
        RunHealRate, RunStaminaRate, RunMagickaRate,
        CombatHealRate, CombatStaminaRate, CombatMagickaRate,
        PowerAttackStaminaPenalty,
        SprintStaminaDrainMult, SprintStaminaWeightBase, SprintStaminaWeightMult,
        BlockHealRate, BlockStaminaRate, BlockMagickaRate,
        SprintHealRate, SprintMagickaRate,
        SwimHealRate, SwimStaminaRate, SwimMagickaRate,
        HealthRegenDelay, StaminaRegenDelay, MagickaRegenDelay,
        DmgHealthRegenDelay, DmgStaminaRegenDelay, DmgMagickaRegenDelay,
        OutOfBreath;

	private:

	protected:
        static void ActorUpdateF(RE::Actor* a_actor, float a_zPos, RE::TESObjectCELL* a_cell);
        static inline REL::Relocation<decltype(ActorUpdateF)> _ActorUpdateF;
	
	};

};
#include "ScriptMgr.h"
#include "Unit.h"
#include "Map.h"
#include "MapManager.h"
#include "Player.h"
#include "Chat.h"

class AutoBalance_UnitScript : public UnitScript
{
public:
    AutoBalance_UnitScript() : UnitScript("AutoBalance_UnitScript")
    {
    }

    void ModifyPeriodicDamageAurasTick(Unit *target, Unit *attacker, uint32 &damage) override
    {
        damage = ModifyDamage(target, attacker, damage);
    }

    void ModifySpellDamageTaken(Unit *target, Unit *attacker, int32 &damage) override
    {
        damage = ModifyDamage(target, attacker, damage);
    }

    void ModifyMeleeDamage(Unit *target, Unit *attacker, uint32 &damage) override
    {
        damage = ModifyDamage(target, attacker, damage);
    }

    uint32 ModifyDamage(Unit *target, Unit *attacker, uint32 damage)
    {
        if (!attacker || attacker->GetTypeId() == TYPEID_PLAYER || !attacker->IsInWorld())
        {
            return damage;
        }

        if (!(target && target->GetMap() && target->GetMap()->IsDungeon()) || !(attacker->GetMap() && attacker->GetMap()->IsDungeon()))
        {
            return damage;
        }

        if ((attacker->IsHunterPet() || attacker->IsPet() || attacker->IsSummon()) && attacker->IsControlledByPlayer())
        {
            return damage;
        }

        InstanceMap* instanceMap = ((InstanceMap*)sMapMgr->FindMap(attacker->GetMapId(), attacker->GetInstanceId()));
        float multiplier = instanceMap->GetOffensiveMultiplier();

        return damage * multiplier;
    }
};

void AddSC_AutoBalance()
{
    new AutoBalance_UnitScript;
}

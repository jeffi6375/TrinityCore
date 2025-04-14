// @hearthwards-begin
#include "ScriptMgr.h"
#include "Unit.h"
#include "Map.h"
#include "MapManager.h"
#include "Creature.h"

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

        if (attacker->IsCreature() && !attacker->ToCreature()->isElite())
        {
            return damage;
        }

        InstanceMap* instanceMap = ((InstanceMap*)sMapMgr->FindMap(attacker->GetMapId(), attacker->GetInstanceId()));
        float multiplier = instanceMap->GetOffensiveMultiplier();

        return damage * multiplier;
    }

    void ModifyHealReceived(Unit* target, Unit* healer, uint32& heal) override
    {
        heal = ModifyHeal(target, healer, heal);
    }

    void ModifyPeriodicHealAurasTick(Unit *target, Unit *healer, uint32 &heal) override
    {
        heal = ModifyHeal(target, healer, heal);
    }

    uint32 ModifyHeal(Unit *target, Unit *healer, uint32 heal)
    {
        if (!healer || healer->GetTypeId() == TYPEID_PLAYER || !healer->IsInWorld())
        {
            return heal;
        }

        if (!(target && target->GetMap() && target->GetMap()->IsDungeon()) || !(healer->GetMap() && healer->GetMap()->IsDungeon()))
        {
            return heal;
        }

        if ((healer->IsHunterPet() || healer->IsPet() || healer->IsSummon()) && healer->IsControlledByPlayer())
        {
            return heal;
        }

        if (healer->IsCreature() && !healer->ToCreature()->isElite())
        {
            return heal;
        }

        InstanceMap* instanceMap = ((InstanceMap*)sMapMgr->FindMap(healer->GetMapId(), healer->GetInstanceId()));
        float multiplier = instanceMap->GetDefensiveMultiplier();

        return heal * multiplier;
    }
};

void AddSC_AutoBalance()
{
    new AutoBalance_UnitScript;
}
// @hearthwards-end

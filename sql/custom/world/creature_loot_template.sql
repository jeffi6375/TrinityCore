-- Remove Plans: Copper Chain Vest from Siltfin Murloc and add reference loot table for plans
DELETE FROM `creature_loot_template` WHERE `Entry` = 17190 AND (`Item` = 3609 OR `Item` = 24700);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`)
VALUES (17190,24700,24700,1.0,0,1,1,1,1,NULL);

--
-- Base hit points reduced significantly
--

-- Warrior
UPDATE player_classlevelstats SET basehp = 10 WHERE class = 1 AND level = 1;
UPDATE player_classlevelstats SET basehp = 10 + 6 * (level - 1) WHERE class = 1 AND level > 1;

-- Paladin
UPDATE player_classlevelstats SET basehp = 10 WHERE class = 2 AND level = 1;
UPDATE player_classlevelstats SET basehp = 10 + 6 * (level - 1) WHERE class = 2 AND level > 1;

-- Hunter
UPDATE player_classlevelstats SET basehp = 10 WHERE class = 3 AND level = 1;
UPDATE player_classlevelstats SET basehp = 10 + 6 * (level - 1) WHERE class = 3 AND level > 1;

-- Rogue
UPDATE player_classlevelstats SET basehp = 8 WHERE class = 4 AND level = 1;
UPDATE player_classlevelstats SET basehp = 8 + 5 * (level - 1) WHERE class = 4 AND level > 1;

-- Priest
UPDATE player_classlevelstats SET basehp = 8 WHERE class = 5 AND level = 1;
UPDATE player_classlevelstats SET basehp = 8 + 5 * (level - 1) WHERE class = 5 AND level > 1;

-- Death Knight
UPDATE player_classlevelstats SET basehp = 10 WHERE class = 6 AND level = 1;
UPDATE player_classlevelstats SET basehp = 10 + 6 * (level - 1) WHERE class = 6 AND level > 1;

-- Shaman
UPDATE player_classlevelstats SET basehp = 8 WHERE class = 7 AND level = 1;
UPDATE player_classlevelstats SET basehp = 8 + 5 * (level - 1) WHERE class = 7 AND level > 1;

-- Mage
UPDATE player_classlevelstats SET basehp = 6 WHERE class = 8 AND level = 1;
UPDATE player_classlevelstats SET basehp = 6 + 4 * (level - 1) WHERE class = 8 AND level > 1;

-- Warlock
UPDATE player_classlevelstats SET basehp = 8 WHERE class = 9 AND level = 1;
UPDATE player_classlevelstats SET basehp = 8 + 5 * (level - 1) WHERE class = 9 AND level > 1;

-- Druid
UPDATE player_classlevelstats SET basehp = 8 WHERE class = 11 AND level = 1;
UPDATE player_classlevelstats SET basehp = 8 + 5 * (level - 1) WHERE class = 11 AND level > 1;

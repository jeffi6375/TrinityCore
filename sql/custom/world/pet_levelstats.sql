--
-- Base HP of permanent pets significantly reduced
-- (Stats unchanged because you can't equip pets with gear)
--

UPDATE `pet_levelstats` SET `hp` = 5 * `level`
WHERE `creature_entry` IN (
    1,      -- Hunter pets
    416,    -- Imp
    417,    -- Felhunter
    1860,   -- Voidwalker
    1863,   -- Succubus
    17252   -- Felguard
);

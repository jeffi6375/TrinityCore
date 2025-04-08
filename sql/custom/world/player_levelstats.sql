--
-- Stats don't change on level up
--

UPDATE player_levelstats AS L1, player_levelstats AS L2
SET L1.str = L2.str, L1.agi = L2.agi, L1.sta = L2.sta, L1.inte = L2.inte, L1.spi = L2.spi
WHERE L1.class = L2.class AND L2.level = 1

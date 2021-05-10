#include "../include/map.h"
Block blocks[20];
void initmap(Block *blocks)
{
    initblock(blocks, false, "0", 100, 100, 700, 200, 1300, 600);
    initblock(blocks + 1, false, "0", 100, 100, 1200, 300, 3000, 1900);
    initblock(blocks + 2, false, "0", 100, 100, 900, 200, 1100, 500);
    initblock(blocks + 3, false, "0", 100, 100, 1100, 300, 1900, 1200);
    initblock(blocks + 4, false, "0", 100, 100, 500, 100, 1800, 1100);
    initblock(blocks + 5, false, "0", 100, 100, 1000, 200, 2300, 1000);
    initblock(blocks + 6, false, "0", 100, 100, 900, 100, 3300, 1500);
    initblock(blocks + 7, false, "0", 100, 100, 800, 200, 2600, 1700);
    initblock(blocks + 8, false, "0", 100, 100, 1100, 300, 2200, 900);
    initblock(blocks + 9, false, "0", 100, 100, 600, 200, 1400, 500);
    initblock(blocks + 10, false, "0", 100, 100, 1100, 200, 1900, 1200);
    initblock(blocks + 11, false, "0", 100, 100, 1100, 200, 1100, 600);
    initblock(blocks + 12, false, "0", 100, 100, 1300, 400, 2700, 900);
    initblock(blocks + 13, false, "0", 100, 100, 1400, 300, 2400, 1200);
    initblock(blocks + 14, false, "0", 100, 100, 1100, 300, 2800, 1300);
    initblock(blocks + 15, false, "0", 100, 100, 1100, 300, 2200, 1300);
    initblock(blocks + 16, false, "0", 100, 100, 900, 200, 1800, 1000);
    initblock(blocks + 17, false, "0", 100, 100, 1400, 300, 1600, 900);
    initblock(blocks + 18, false, "0", 100, 100, 500, 100, 3200, 1600);
    initblock(blocks + 19, false, "0", 100, 100, 1200, 200, 2700, 1100);
}
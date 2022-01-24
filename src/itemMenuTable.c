#include "itemMenuTable.h"

const ItemMenuTableEntry gItemMenuTable[] = {
    [MENU_SLOT_SWORD] = { MENU_SLOT_BOTTLE0, MENU_SLOT_SHIELD, MENU_SLOT_BOOMERANG, MENU_SLOT_GUST_JAR, 0x01, 0x0c,
                          0x42, 0x33 },
    [MENU_SLOT_GUST_JAR] = { MENU_SLOT_BOTTLE1, MENU_SLOT_MOLE_MITTS, MENU_SLOT_SWORD, MENU_SLOT_CANE, 0x01, 0x10, 0x66,
                             0x33 },
    [MENU_SLOT_CANE] = { MENU_SLOT_BOTTLE3, MENU_SLOT_LANTERN, MENU_SLOT_GUST_JAR, MENU_SLOT_BOOMERANG, 0x01, 0x14,
                         0x8a, 0x33 },
    [MENU_SLOT_BOOMERANG] = { MENU_SLOT_SAVE_BUTTON, MENU_SLOT_BOMBS, MENU_SLOT_CANE, MENU_SLOT_SWORD, 0x01, 0x15, 0xae,
                              0x33 },
    [MENU_SLOT_SHIELD] = { MENU_SLOT_SWORD, MENU_SLOT_PEGASUS_BOOTS, MENU_SLOT_BOMBS, MENU_SLOT_MOLE_MITTS, 0x01, 0x16,
                           0x42, 0x4b },
    [MENU_SLOT_MOLE_MITTS] = { MENU_SLOT_GUST_JAR, MENU_SLOT_ROCS_CAPE, MENU_SLOT_SHIELD, MENU_SLOT_LANTERN, 0x01, 0x17,
                               0x66, 0x4b },
    [MENU_SLOT_LANTERN] = { MENU_SLOT_CANE, MENU_SLOT_OCARINA, MENU_SLOT_MOLE_MITTS, MENU_SLOT_BOMBS, 0x01, 0x00, 0x8a,
                            0x4b },
    [MENU_SLOT_BOMBS] = { MENU_SLOT_BOOMERANG, MENU_SLOT_BOW, MENU_SLOT_LANTERN, MENU_SLOT_SHIELD, 0x01, 0x00, 0xae,
                          0x4b },
    [MENU_SLOT_PEGASUS_BOOTS] = { MENU_SLOT_SHIELD, MENU_SLOT_BOTTLE0, MENU_SLOT_BOW, MENU_SLOT_ROCS_CAPE, 0x01, 0x00,
                                  0x42, 0x63 },
    [MENU_SLOT_ROCS_CAPE] = { MENU_SLOT_MOLE_MITTS, MENU_SLOT_BOTTLE1, MENU_SLOT_PEGASUS_BOOTS, MENU_SLOT_OCARINA, 0x01,
                              0x00, 0x66, 0x63 },
    [MENU_SLOT_OCARINA] = { MENU_SLOT_LANTERN, MENU_SLOT_BOTTLE3, MENU_SLOT_ROCS_CAPE, MENU_SLOT_BOW, 0x01, 0x00, 0x8a,
                            0x63 },
    [MENU_SLOT_BOW] = { MENU_SLOT_BOMBS, MENU_SLOT_SAVE_BUTTON, MENU_SLOT_OCARINA, MENU_SLOT_PEGASUS_BOOTS, 0x01, 0x00,
                        0xae, 0x63 },
    [MENU_SLOT_BOTTLE0] = { MENU_SLOT_PEGASUS_BOOTS, MENU_SLOT_SWORD, MENU_SLOT_SAVE_BUTTON, MENU_SLOT_BOTTLE1, 0x01,
                            0x00, 0x42, 0x7b },
    [MENU_SLOT_BOTTLE1] = { MENU_SLOT_ROCS_CAPE, MENU_SLOT_GUST_JAR, MENU_SLOT_BOTTLE0, MENU_SLOT_BOTTLE2, 0x01, 0x00,
                            0x5a, 0x7b },
    [MENU_SLOT_BOTTLE2] = { MENU_SLOT_ROCS_CAPE, MENU_SLOT_GUST_JAR, MENU_SLOT_BOTTLE1, MENU_SLOT_BOTTLE3, 0x01, 0x00,
                            0x72, 0x7b },
    [MENU_SLOT_BOTTLE3] = { MENU_SLOT_OCARINA, MENU_SLOT_CANE, MENU_SLOT_BOTTLE2, MENU_SLOT_SAVE_BUTTON, 0x01, 0x00,
                            0x8a, 0x7b },
    [MENU_SLOT_SAVE_BUTTON] = { MENU_SLOT_BOW, MENU_SLOT_BOOMERANG, MENU_SLOT_BOTTLE3, MENU_SLOT_BOTTLE0, 0x03, 0x00,
                                0xb5, 0x75 },
    { MENU_SLOT_BOW, MENU_SLOT_BOOMERANG, MENU_SLOT_BOTTLE3, MENU_SLOT_BOTTLE0, 0x05, 0x00, 0xb5, 0x75 },
};

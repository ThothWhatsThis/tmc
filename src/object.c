#include "entity.h"
#include "object.h"

void (*const gObjectFunctions[])(Entity*) = {
    [GROUND_ITEM] = ItemOnGround,
    [DEATH_FX] = DeathFx,
    [SHOP_ITEM] = ItemForSale,
    [BUTTON] = Button,
    [MINISH_EMOTICON] = MinishEmoticon,
    [POT] = Pot,
    [EZLO_CAP] = EzloCap,
    [PUSHED_BLOCK] = BlockPushed,
    [LOCKED_DOOR] = LockedDoor,
    [CAMERA_TARGET] = CameraTarget,
    [OBJECT_A] = ObjectA,
    [LINK_HOLDING_ITEM] = LinkHoldingItem,
    [CHEST_SPAWNER] = ChestSpawner,
    [UNUSED_SKULL] = UnusedSkull,
    [CRACKING_GROUND] = CrackingGround,
    [SPECIAL_FX] = SpecialFx,
    [PLAYER_CLONE] = PlayerClone,
    [BUSH] = Bush,
    [LIGHT_DOOR] = LightDoor,
    [RAILTRACK] = Railtrack,
    [LILYPAD_LARGE] = LilypadLarge,
    [CHUCHU_BOSS_PARTICLE] = ChuchuBossParticle,
    [FLOATING_PLATFORM] = FloatingPlatform,
    [GUST_JAR_PARTICLE] = GustJarParticle,
    [EVIL_SPIRIT] = EvilSpirit,
    [HOUSE_DOOR_EXT] = HouseDoorExterior,
    [RUPEE_OBJECT] = Rupee,
    [GREAT_FAIRY] = GreatFairy,
    [HOUSE_SIGN] = HouseSign,
    [OBJECT_1D] = Object1D,
    [MOLE_MITTS_PARTICLE] = MoleMittsParticle,
    [OBJECT_1F] = Object1F,
    [SMOKE_PARTICLE] = SmokeParticle,
    [DIRT_PARTICLE] = DirtParticle,
    [FIGURINE_DEVICE] = FigurineDevice,
    [EYE_SWITCH] = EyeSwitch,
    [PRESSURE_PLATE] = PressurePlate,
    [BIG_BARREL] = BigBarrel,
    [BARREL_INSIDE] = BarrelInside,
    [PUSHABLE_STATUE] = PushableStatue,
    [PARALLAX_ROOM_VIEW] = ParallaxRoomView,
    [AMBIENT_CLOUDS] = AmbientClouds,
    [FLAME] = Flame,
    [LILYPAD_LARGE_FALLING] = LilypadLargeFalling,
    [BEANSTALK] = Beanstalk,
    [SMOKE] = Smoke,
    [PUSHABLE_ROCK] = PushableRock,
    [HITTABLE_LEVER] = HittableLever,
    [OBJECT_30] = Object30,
    [FROZEN_FLOWER] = FrozenFlower,
    [PULLABLE_MUSHROOM] = PullableMushroom,
    [BOLLARD] = Bollard,
    [WARP_POINT] = WarpPoint,
    [CARLOV_OBJECT] = CarlovObject,
    [BARREL_SPIDERWEB] = BarrelSpiderweb,
    [OBJECT_37] = Object37,
    [JAR_PORTAL] = JarPortal,
    [BOSS_DOOR] = BossDoor,
    [WHITE_TRIANGLE_EFFECT] = WhiteTriangleEffect,
    [PORTAL_MUSHROOM_STALKS] = MacroMushroomStalk,
    [PORTAL_FALLING_PLAYER] = MacroPlayer,
    [MINISH_PORTAL_CLOSEUP] = MinishPortalCloseup,
    [MINISH_VILLAGE_OBJECT] = MinishVillageObject,
    [GIANT_LEAF] = GiantLeaf,
    [FAIRY] = Fairy,
    [LADDER_UP] = LadderUp,
    [LINK_FIRE] = LinkFire,
    [SWORD_PARTICLE] = SwordParticle,
    [ROTATING_TRAPDOOR] = RotatingTrapdoor,
    [LAMP_PARTICLE] = LampParticle,
    [GIANT_BOOK_LADDER] = GiantBookLadder,
    [HEART_CONTAINER] = HeartContainer,
    [FILE_SCREEN_OBJECTS] = FileScreenObjects,
    [CHUCHU_BOSS_START_PARTICLE] = ChuchuBossStartParticle,
    [BACKGROUND_CLOUD] = BackgroundCloud,
    [CHUCHU_BOSS_CUTSCENE] = ChuchuBossCutscene,
    [PUSHABLE_FURNITURE] = PushableFurniture,
    [FURNITURE] = Furniture,
    [MINISH_SIZED_ENTRANCE] = MinishSizedEntrance,
    [ARCHWAY] = Archway,
    [GIANT_ROCK] = GiantRock,
    [GIANT_ROCK2] = GiantRock2,
    [SPECIAL_CHEST] = SpecialChest,
    [OBJECT_53] = Object53,
    [PULLABLE_LEVER] = PullableLever,
    [MINECART] = Minecart,
    [THOUGHT_BUBBLE] = ThoughtBubble,
    [HIDDEN_LADDER_DOWN] = HiddenLadderDown,
    [GENTARI_CURTAIN] = GentariCurtain,
    [LAVA_PLATFORM] = LavaPlatform,
    [PAPER] = Paper,
    [BED_COVER] = BedCover,
    [MASK] = Mask,
    [HOUSE_DOOR_INT] = HouseDoorInterior,
    [WHIRLWIND] = Whirlwind,
    [OBJECT_BLOCKING_STAIRS] = ObjectBlockingStairs,
    [SWORDSMAN_NEWSLETTER] = SwordsmanNewsletter,
    [EZLO_CAP_FLYING] = EzloCapFlying,
    [GIANT_TWIG] = GiantTwig,
    [OBJECT_63] = Object63,
    [THUNDERBOLT] = Thunderbolt,
    [LADDER_HOLE] = LadderHoleInBookshelf,
    [WATER_DROP_OBJECT] = WaterDropObject,
    [GLEEROK_PARTICLE] = GleerokParticle,
    [LINK_EMPTYING_BOTTLE] = LinkEmptyingBottle,
    [CUTSCENE_ORCHESTRATOR] = CutsceneOrchestrator,
    [CUTSCENE_MISC_OBJECT] = CutsceneMiscObject,
    [CRENEL_BEAN_SPROUT] = CrenelBeanSprout,
    [MINECART_DOOR] = MinecartDoor,
    [OBJECT_ON_PILLAR] = ObjectOnPillar,
    [MINERAL_WATER_SOURCE] = MineralWaterSource,
    [MINISH_SIZED_ARCHWAY] = MinishSizedArchway,
    [OBJECT_70] = Object70,
    [PUSHABLE_GRAVE] = PushableGrave,
    [STONE_TABLET] = StoneTablet,
    [LILYPAD_SMALL] = LilypadSmall,
    [MINISH_PORTAL_STONE] = MinishPortalStone,
    [MACRO_CRYSTAL] = MacroCrystal,
    [MACRO_LEAF] = MacroLeaf,
    [BELL] = Bell,
    [HUGE_DECORATION] = MacroDecoration,
    [SHRINKING_HIEROGLYPHS] = ShrinkingHieroglyphs,
    [STEAM] = Steam,
    [PUSHABLE_LEVER] = PushableLever,
    [HUGE_SHOES] = MacroShoe,
    [OBJECT_ON_BEETLE] = ObjectOnSpinyBeetle,
    [MAZAAL_OBJECT] = MazaalObject,
    [PICO_BLOOM] = PicoBloom,
    [BOARD] = Board,
    [BENCH] = Bench,
    [BIG_VORTEX] = BigVortex,
    [BIG_PUSHABLE_LEVER] = BigPushableLever,
    [SMALL_ICE_BLOCK] = SmallIceBlock,
    [BIG_ICE_BLOCK] = BigIceBlock,
    [TRAPDOOR] = Trapdoor,
    [OCTOROK_BOSS_OBJECT] = OctorokBossObject,
    [HUGE_BOOK] = MacroBook,
    [MAZAAL_BOSS_OBJECT] = MazaalBossObject,
    [CABIN_FURNITURE] = CabinFurniture,
    [DOUBLE_BOOKSHELF] = DoubleBookshelf,
    [BOOK] = Book,
    [FIREPLACE] = Fireplace,
    [LIGHT_RAY] = LightRay,
    [FROZEN_WATER_ELEMENT] = FrozenWaterElement,
    [WATER_ELEMENT] = WaterElement,
    [FROZEN_OCTOROK] = FrozenOctorok,
    [BAKER_OVEN] = BakerOven,
    [LAMP] = Lamp,
    [WIND_TRIBE_FLAG] = WindTribeFlag,
    [BIRD] = Bird,
    [GRAVEYARD_KEY] = GraveyardKey,
    [KEY_STEALING_TAKKURI] = KeyStealingTakkuri,
    [GURUGURU_BAR] = GuruguruBar,
    [HIT_SWITCH] = HitSwitch,
    [HUGE_ACORN] = MacroAcorn,
    [VAATI2_PARTICLE] = Vaati2Particle,
    [TREE_HIDING_PORTAL] = TreeHidingPortal,
    [LIGHTABLE_SWITCH] = LightableSwitch,
    [TREE_THORNS] = TreeThorns,
    [FAN] = Fan,
    [ANGRY_STATUE] = AngryStatue,
    [PALACE_ARCHWAY] = PalaceArchway,
    [OBJECT_A2] = ObjectA2,
    [CLOUD] = Cloud,
    [MINISH_LIGHT] = MinishLight,
    [FIREBALL_CHAIN] = FireballChain,
    [SANCTUARY_STONE_TABLET] = SanctuaryStoneTablet,
    [OBJECT_A7] = ObjectA7,
    [OBJECT_A8] = ObjectA8,
    [MULLDOZER_SPAWN_POINT] = MulldozerSpawnPoint,
    [WATERFALL_OPENING] = WaterfallOpening,
    [VAATI1_PORTAL] = Vaati1Portal,
    [FOUR_ELEMENTS] = FourElements,
    [ELEMENTS_BACKGROUND] = ElementsBackground,
    [FLOATING_BLOCK] = FloatingBlock,
    [VAATI3_ARM] = Vaati3Arm,
    [METAL_DOOR] = MetalDoor,
    [JAIL_BARS] = JailBars,
    [FAN_WIND] = FanWind,
    [KINSTONE_SPARK] = KinstoneSpark,
    [JAPANESE_SUBTITLE] = JapaneseSubtitle,
    [VAATI3_PLAYER_OBJECT] = Vaati3PlayerObject,
    [VAATI3_DEATH] = Vaati3Death,
    [WELL] = Well,
    [WIND_TRIBE_TELEPORTER] = WindTribeTeleporter,
    [CUCCO_MINIGAME] = CuccoMinigame,
    [GYORG_BOSS_OBJECT] = GyorgBossObject,
    [WINDCREST] = Windcrest,
    [LIT_AREA] = LitArea,
    [TITLE_SCREEN_OBJECT] = TitleScreenObject,
    [PINWHEEL] = Pinwheel,
    [OBJECT_BF] = ObjectBF,
    [ENEMY_ITEM] = EnemyItem,
    [LINK_ANIMATION] = LinkAnimation,
};

void ObjectInit(Entity*);

void ObjectUpdate(Entity* this) {
    if ((this->flags & ENT_DID_INIT) == 0 && this->action == 0)
        ObjectInit(this);
    if (this->iframes != 0)
        this->iframes++;
    if (!EntityIsDeleted(this)) {
        gObjectFunctions[this->id](this);
        this->contactFlags &= ~0x80;
    }
    DrawEntity(this);
}

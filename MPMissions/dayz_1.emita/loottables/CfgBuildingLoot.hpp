#include "CfgLoot.hpp"

class CfgBuildingLoot {
	class Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_suit1","z_suit2","z_worker1","z_worker2","z_worker3","z_villager1","z_villager2","z_villager3"};
		lootChance = 1;
		lootPos[] = {};

		lootPosSmall[] = {};
		lootPosZombie[] = {};
		
		itemType[] = {};

		itemChance[] = {};
		lootTypeSmall[] = {};
		itemChanceSmall[] = {};

		hangPos[] = {};
		vehPos[] = {};
	};
	
	class Castle: Default {
		lootChance = 0.2;
		lootPos[] = {};
		lootType[] = {
		//one spawn
		//tools
			//{"ItemMatchbox","weapon",0.01},
			{"ItemKnife","weapon",0.01},
			{"ItemMap","generic",0.01},
			{"ItemCompass","weapon",0.01},
			{"ItemFlashlight","weapon",0.01},
		//weapons
			{"WeaponHolder_ItemHatchet","object",0.01},
		//special
			{"WeaponHolder_ItemTent","object",0.01},
			//{"WeaponHolder_DomeTentStorage","object",0.01},
		//mags special
			{"PartWoodPile","magazine",0.04},
		//bags
			//{"DZ_Patrol_Pack_EP1","object",0.01},
		//Multiple spawns
			//{"","Residential",0.60},
			{"","generic",0.40}
		};
	};

	class Residential: Default {
		zombieChance = 0.3;
		maxRoaming = 2;
		zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_villager1","z_villager2","z_villager3"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"ItemWatch","generic",0.04},
			{"ItemCompass","generic",0.03},
			{"ItemMap","weapon",0.02},
			{"ItemFlashlight","generic",0.01},
			{"ItemKnife","generic",0.04},
			{"ItemMatchbox_DZE","generic",0.01},
			{"","generic",0.32},
			{"backpacks","backpacks",0.04},
			{"tents","tents",0.01},
			{"","military",0.02},
			{"","trash",0.17},
			{"Binocular","weapon",0.02},
			{"PartPlywoodPack","magazine",0.02},
			{"clothes","clothes",0.01},
			{"specialclothes","specialclothes",0.01},
			{"WeaponHolder_MeleeCrowbar","object",0.03},
			{"pistols", "cfglootweapon", 0.04 },
			{"shotgunsingleshot", "cfglootweapon", 0.04 }
		};
		lootTypeSmall[] = {
			{ "ItemSodaMdew","magazine",0.01 },
			{ "ItemSodaRbull","magazine",0.01 },
			{ "ItemSodaOrangeSherbet","magazine",0.02 },
			{ "ItemWatch","weapon",0.05 },
			{ "ItemCompass","weapon",0.04 },
			{ "ItemMap","weapon",0.03 },
			{ "pistols","cfglootweapon",0.12 },
			{ "ItemFlashlight","weapon",0.02 },
			{ "ItemKnife","weapon",0.04 },
			{ "ItemMatchbox_DZE","weapon",0.03 },
			{ "","generic",0.38 },
			{ "","military",0.04 },
			{ "","trash",0.17 },
			{ "Binocular","weapon",0.02 },
			{ "clothes","single",0.01},
			{ "specialclothes","single",0.01 }
		};
	};

	class Church: Residential {
		zombieChance = 0.3;
		minRoaming = 1;
		maxRoaming = 3;
		zombieClass[] = {"z_priest","z_priest","z_priest"};
		lootChance = 1;
	};
	
	class HouseRoaming: Residential { 
		lootChance = 1; 
		zombieChance = 0.2; 
		maxRoaming = 2; 
	}; 

	class Estate: Default {
		zombieChance = 0.4;
		maxRoaming = 4;
		zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_villager1","z_villager2","z_villager3"};
		lootChance = 1;
		lootPos[] = {};		
		itemType[] =	{
			
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
			{"ItemSodaMdew","magazine",0.01},
			{"ItemWatch","generic",0.05},
			{"ItemCompass","generic",0.05},
			{"Makarov","weapon",0.04},
			{"Colt1911","weapon",0.04},
			
			//Epoch Chainsaw
			{"Chainsaw","weapon",0.02},
			{"CSGAS","magazine",0.04},
			
			{"ItemBandage","magazine",0.08},
			//Unleashed
			{"kpfs_glock17","weapon",0.03},
			{"KPFS_P38","weapon",0.03},
			{"p226sf","weapon",0.03},
			{"KPFS_8Rnd_9x19_P1","magazine",0.04},
			{"17Rnd_9x19_glock17","magazine",0.04},
			{"15Rnd_9x19_LUGER","magazine",0.04},
			{"KPFS_KarS","weapon",0.03},
			{"KPFS_10Rnd_762x39_SKS","magazine",0.03},
			{"militaryclothes","militaryclothes",0.08},
			//Unleashed end
			
			{"ItemKnife","generic",0.07},
			{"ItemMatchbox","generic",0.06},
			{"LeeEnfield","weapon",0.03},
			{"revolver_EP1","weapon",0.04},
			{"DZ_ALICE_Pack_EP1","object",0.01}, // 16
			{"DZ_TK_Assault_Pack_EP1","object",0.02}, // 16
			{"Winchester1866","weapon",0.03},
			{"MeleeBaseBallBat","weapon",0.05},
			{"MeleeBaseBallBatNails","weapon",0.05},
			{"MeleeBaseBallBatBarbed","weapon",0.05},
			{"Crossbow_DZ","weapon",0.01},
			{"Binocular","weapon",0.06},
			{"PartWoodPile","magazine",0.06},
			{"WeaponHolder_ItemCrowbar","object",0.08},
			{"MR43","weapon",0.03},
			{"","food",0.40},
			{"","military",0.15}
		};			
	};

	class Office: Default {
		maxRoaming = 3;
		zombieClass[] = {"z_suit1","z_suit2"};
		zombieChance = 0.3;
		lootChance = 0.8;
		lootPos[] = {};
		lootType[] = {
			{"ItemWatch","generic",0.04},
			{"ItemCompass","generic",0.03},
			{"ItemMap","weapon",0.02},
			{"ItemFlashlight","generic",0.01},
			{"ItemKnife","generic",0.04},
			{"ItemMatchbox_DZE","generic",0.01},
			{"","generic",0.31},
			{"backpacks","backpacks",0.04},
			{"tents","tents",0.01},
			{"","military",0.02},
			{"","trash",0.21},
			{"Binocular","weapon",0.02},
			{"PartPlywoodPack","magazine",0.02},
			{"clothes","clothes",0.01},
			{"specialclothes","specialclothes",0.01},
			{"WeaponHolder_MeleeCrowbar","object",0.03},
			{"ItemBriefcaseEmpty","magazine",0.01},
			{ "shotgunsingleshot", "cfglootweapon", 0.05}
		};
		lootTypeSmall[] = {
			{ "ItemSodaMdew","magazine",0.01 },
			{ "ItemSodaRbull","magazine",0.01 },
			{ "ItemSodaOrangeSherbet","magazine",0.02 },
			{ "ItemWatch","weapon",0.05 },
			{ "ItemCompass","weapon",0.04 },
			{ "ItemMap","weapon",0.03 },
			{ "pistols","cfglootweapon",0.15 },
			{ "ItemFlashlight","weapon",0.02 },
			{ "ItemKnife","weapon",0.05 },
			{ "ItemMatchbox_DZE","weapon",0.03 },
			{ "","generic",0.31 },			
			{ "","military",0.04 },
			{ "","trash",0.03 },
			{ "Binocular","weapon",0.02 },
			{ "clothes","single",0.16 },
			{ "specialclothes","single",0.02 },
			{ "ItemDocument","magazine",0.01 }
		};
	};

	class Industrial: Default {
		zombieChance = 0.4;
		zombieClass[] = {"z_worker1","z_worker2","z_worker3"};
		maxRoaming = 2;
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"ItemGenerator","magazine",0.01},
			{"ItemFuelBarrelEmpty","magazine",0.01},
			{"","generic",0.17},
			{"","trash",0.25},
			{"","military",0.04},
			{"PartGeneric","magazine",0.04},
			{"PartWheel","magazine",0.05},
			{"PartFueltank","magazine",0.02},
			{"PartEngine","magazine",0.02},
			{"PartGlass","magazine",0.04},
			{"PartVRotor","magazine",0.01},
			{"ItemJerrycan","magazine",0.04},
			{"WeaponHolder_ItemHatchet_DZE","object",0.07},
			{"ItemKnife","military",0.07},
			{"ItemToolbox","weapon",0.06},
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
			{"ItemKeyKit","weapon",0.01},
			{"CinderBlocks","magazine",0.03},
			{"MortarBucket","magazine",0.01}
		};
		lootTypeSmall[] = {
			{ "","generic",0.5 },
			{ "","trash",0.28 },
			{ "","military",0.14 },
			{ "ItemKnife","weapon",0.07 },
			{ "ItemKeyKit","weapon",0.01 }
		};
	};

	class IndustrialFuel: Default {
		zombieChance = 0.4;
		zombieClass[] = {"z_worker1","z_worker2","z_worker3"};
		maxRoaming = 2;
		lootChance = 0.8;
		lootPos[] = {};
		lootType[] = {
			{"ItemGenerator","magazine",0.01},
			{"fuel_pump_kit","magazine",0.01},
			{"","generic",0.18},
			{"","trash",0.28},
			{"","military",0.04},
			{"PartGeneric","magazine",0.04},
			{"PartWheel","magazine",0.05},
			{"PartFueltank","magazine",0.02},
			{"PartEngine","magazine",0.02},
			{"PartGlass","magazine",0.04},
			{"PartVRotor","magazine",0.01},
			{"ItemJerrycan","magazine",0.04},
			{"WeaponHolder_ItemHatchet_DZE","object",0.07},
			{"ItemKnife","military",0.07},
			{"ItemToolbox","weapon",0.06},
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
			{"ItemKeyKit","weapon",0.01}
		};
		lootTypeSmall[] = {
			{ "","generic",0.5 },
			{ "","trash",0.28 },
			{ "","military",0.14 },
			{ "ItemKnife","weapon",0.07 },
			{ "ItemKeyKit","weapon",0.01 }
		};
	};

	class InfectedCamps: Default { //5
		lootPos[] = {};
		lootType[] = {
			{"PartGeneric","magazine",0.04},
			{"PartWheel","magazine",0.05},
			{"PartFueltank","magazine",0.02},
			{"PartEngine","magazine",0.02},
			{"PartGlass","magazine",0.04},
			{"ItemJerrycan","magazine",0.04},
			{"ItemWire","magazine",0.01},
			{"ItemTankTrap","magazine",0.04},
			{"ItemSodaMdew","magazine",0.01},
			
			{"ItemWatch","generic",0.05},
			{"ItemCompass","generic",0.05},
			{"Makarov","weapon",0.04},
			{"Colt1911","weapon",0.04},
			{"Chainsaw","weapon",0.05},
			{"CSGAS","magazine",0.02},
			{"","food",0.40},
			//Unleashed
			{"kpfs_glock17","weapon",0.03},
			{"KPFS_P38","weapon",0.03},
			{"p226sf","weapon",0.03},
			{"KPFS_8Rnd_9x19_P1","magazine",0.04},
			{"17Rnd_9x19_glock17","magazine",0.04},
			{"15Rnd_9x19_LUGER","magazine",0.04},
			{"KPFS_10Rnd_762x39_SKS","magazine",0.03},
			{"militaryclothes","militaryclothes",0.08},
			//Unleashed end
			{"KPFS_KarS","weapon",0.03},
			{"KPFS_M1_Carbine","weapon",0.03},
			{"KPFS_M1_Garand","weapon",0.03},
			{"KPFS_M1_Thompson","weapon",0.03},
			{"KPFS_M1_Garand_M84","weapon",0.03},
			{"kpfs_8Rnd_765x17","magazine",0.02},
			{"KPFS_5Rnd_762x54_Mosin","magazine",0.02},
			{"KPFS_15Rnd_cal30_Carbine","magazine",0.02},
			{"KPFS_8Rnd_cal30_60_Gar","magazine",0.02},
			{"KPFS_30Rnd_45ACP_Thompson","magazine",0.02},
			{"KPFS_MP44","weapon",0.03},
			{"KPFS_P220","weapon",0.02},
			{"KPFS_P225","weapon",0.02},
			{"KPFS_P226","weapon",0.02},
			{"KPfs_glock17","weapon",0.03},
			{"KPFS_P88","weapon",0.03},
			{"KPFS_P99QA","weapon",0.01},
			{"KPFS_HKP30","weapon",0.01},
			{"KPFS_P2000","weapon",0.01},
			{"KPFS_MP5A3","weapon",0.03},
			{"KPFS_P1","weapon",0.03},
			{"KPFS_P12","weapon",0.03},
			{"KPfs_g36a1","weapon",0.03},
			{"KPfs_g36a2","weapon",0.01},
			{"KPfs_g36a4","weapon",0.01},
			{"KPFS_Makarov","weapon",0.03},
			{"KPFS_MPi_KM_72","weapon",0.02},
			{"KPFS_MPi_KMS_72","weapon",0.01},
			{"KPFS_MPi_AK_74","weapon",0.05},
			{"KPFS_MPi_AKS_74","weapon",0.02},
			{"KPFS_MPi_AKS_74K","weapon",0.02},
			{"KPFS_MPi_KMKIX","weapon",0.03},
			{"DZ_British_ACU","object",0.05}, // 18
			{"ItemBandage","magazine",0.08},
			{"ItemKnife","generic",0.07},
			{"ItemMatchbox","generic",0.06},
			{"LeeEnfield","weapon",0.03},
			{"revolver_EP1","weapon",0.04},
			{"DZ_ALICE_Pack_EP1","object",0.01}, // 16
			{"DZ_TK_Assault_Pack_EP1","object",0.02}, // 16
			{"Winchester1866","weapon",0.03},
			{"Crossbow_DZ","weapon",0.01},
			{"Binocular","weapon",0.06},
			{"MR43","weapon",0.03},
			{"","military",0.10},
			{"","generic",0.60}
		};
	};

	class Farm: Default {
		zombieChance = 0.3;
		maxRoaming = 3;
		zombieClass[] = {"zZombie_Base","z_hunter","z_hunter","z_hunter","z_villager1","z_villager2","z_villager3"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"ItemJerrycan","magazine",0.05},
			{"","generic",0.3},
			{"","trash",0.11},
			{"PartPlankPack","magazine",0.06},
			{"WeaponHolder_ItemHatchet_DZE","object",0.05},
			{"ItemFuelBarrelEmpty","magazine",0.01},
			{"WeaponHolder_ItemMachete","object",0.03},
			{"ItemFishingPole","weapon",0.02},
			{"ItemLightBulb","magazine",0.02},
			{"ItemSledgeHandle","magazine",0.02},
			{ "farmweapons", "cfglootweapon", 0.15}
		};
		lootTypeSmall[] = {
			{ "","generic", 0.79},
			{ "","trash",0.14 },
			{ "","military",0.05},
			{ "ItemLightBulb","magazine",0.01},
			{ "ItemSledgeHead","magazine",0.01}
		};
	};
	class Supermarket: Default {
		lootChance = 0.6;
		minRoaming = 2;
		maxRoaming = 6;
		zombieChance = 0.3;
		zombieClass[] = {"zZombie_Base","zZombie_Base","z_teacher","z_suit1","z_suit2"};
		lootType[] = {
			{"ItemSodaMdew","magazine",0.01},
			{"ItemSodaRbull","magazine",0.01},
			{"ItemSodaOrangeSherbet","magazine",0.03},
			{"ItemWatch","generic",0.07},
			{"ItemCompass","generic",0.02},
			{"ItemMap","weapon",0.04},
			{"ItemFlashlight","generic",0.01},
			{"ItemKnife","generic",0.02},
			{"ItemMatchbox_DZE","generic",0.04},
			{"","generic",0.04},
			{"backpacks","backpacks",0.07},
			{"tents","tents",0.01},
			{"","food",0.3},
			{"","trash",0.17},
			{"Binocular","weapon",0.05},
			{"PartPlywoodPack","magazine",0.02},
			{ "pistols", "cfglootweapon", 0.04},
			{ "shotgunsingleshot", "cfglootweapon", 0.04}
		};
		lootTypeSmall[] = {
			{ "ItemSodaMdew","magazine",0.01 },
			{ "ItemSodaRbull","magazine",0.01 },
			{ "ItemSodaOrangeSherbet","magazine",0.03 },
			{ "ItemWatch","weapon",0.07 },
			{ "ItemCompass","weapon",0.03 },
			{ "ItemMap","weapon",0.05 },
			{ "pistols","cfglootweapon",0.08 },
			{ "ItemFlashlight","weapon",0.01 },
			{ "ItemKnife","weapon",0.02 },
			{ "ItemMatchbox_DZE","weapon",0.04 },
			{ "","generic",0.21 },
			{ "","food",0.24 },
			{ "","trash",0.16 },
			{ "Binocular","weapon",0.02 },
			{ "ItemMixOil", "magazine",0.02}
		};
	};
	class HeliCrash: Default {
		zombieChance = 0.4;
		maxRoaming = 2;
		zombieClass[] = {"z_soldier_pilot"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{ "assaultrifles", "cfglootweapon", 0.10 },
			{ "submachinegun", "cfglootweapon", 0.04 },
			{ "sniperrifles", "cfglootweapon", 0.17 },
			{ "machineguns", "cfglootweapon", 0.16 },
			{"","military",0.30},
			{"","medical",0.10},
			{"MAAWS","weapon",0.02},
			{"MedBox0","object",0.05},
			{"NVGoggles","weapon",0.01},
			{"AmmoBoxSmall_556","object",0.03},
			{"AmmoBoxSmall_762","object",0.03},
			{"militaryclothes","militaryclothes",0.05},
			{"militaryammo","militaryammo",0.09}
		};
	};

	class HeliCrash_No50s: Default {
		zombieChance = 0.4;
		maxRoaming = 2;
		zombieClass[] = {"z_soldier_pilot"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{ "assaultrifles", "cfglootweapon", 0.10 },
			{ "submachinegun", "cfglootweapon", 0.04 },
			{ "sniperrifles", "cfglootweapon", 0.17 },
			{ "machineguns", "cfglootweapon", 0.16 },
			{ "", "military", 0.3 },
			{ "", "medical", 0.18 },
			{ "MAAWS", "weapon", 0.02 },
			{ "MedBox0", "object", 0.05 },
			{ "NVGoggles", "weapon", 0.01 },
			{ "AmmoBoxSmall_556", "object", 0.03 },
			{ "AmmoBoxSmall_762", "object", 0.03 },
			{ "militaryclothes", "militaryclothes", 0.05 },
			{ "militaryammo", "militaryammo", 0.06 }
		};
	};
	class Hospital: Default {
		zombieChance = 0.4;
		minRoaming = 2;
		maxRoaming = 6;
		zombieClass[] = {"z_doctor","z_doctor","z_doctor"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"","trash",0.1},
			{"","hospital",0.7},
			{"MedBox0","object",0.2}
		};
		lootTypeSmall[] = {
			{ "","trash",0.1 },
			{ "","hospital",0.9 }
		};
	};
	class Military: Default {
		zombieChance = 0.3;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_policeman"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"20Rnd_56x45_GP90","magazine",0.02},
			{"30Rnd_56x45_GP90","magazine",0.02},
			{"30Rnd_56x45SD_GP90","magazine",0.02},
			{"100Rnd_56x45_GP90","magazine",0.02},
			{"200Rnd_56x45_GP90","magazine",0.02},
			{"120Rnd_75x55_GP11","magazine",0.02},
			{"20Rnd_762x55_SWISS_P_AP","magazine",0.02},
			{"7Rnd_127x99_HE","magazine",0.02},
			{"7Rnd_127x99_AP","magazine",0.02},
			{"9Rnd_9x19_LUGER","magazine",0.02},
			{"15Rnd_9x19_LUGER","magazine",0.02},
			{"15Rnd_9x19sd_LUGER","magazine",0.02},
			{"30Rnd_9x19_LUGER","magazine",0.02},
			{"30Rnd_9x19sd_LUGER","magazine",0.02},
			//{"GrenadeHandTimedWest","magazine",0.02},
			{"G_40mm_HE","magazine",0.02},
			//{"HandGrenade_dm41","magazine",0.02},
			{"KPFS_8Rnd_9x19_P1","magazine",0.02},
			{"KPFS_30Rnd_762x43_STG44","magazine",0.02},
			{"20Rnd_762x51_FNFAL","magazine",0.02},
			{"30Rnd_762x39_AK47","magazine",0.02},
			{"KPFS_120Rnd_MG1","magazine",0.02},
			{"KPFS_100Rnd_762x39_RPD","magazine",0.02},
			{"KPFS_10Rnd_762x39_SKS","magazine",0.02},
			{"KPFS_PZF60_Heat","magazine",0.02},
			{"KPFS_8Rnd_762x25_TT33","magazine",0.02},
			{"KPFS_12Rnd_45ACP_P12","magazine",0.02},
			{"30Rnd_556x45_G36","magazine",0.02},
			{"30Rnd_556x45_Stanag","magazine",0.02},
			{"SCAR_L_CQC","weapon",0.02},    
			{"SCAR_L_CQC_Holo","weapon",0.02}, 
			{"SCAR_L_CQC_EGLM_Holo","weapon",0.02},
			{"SCAR_L_STD_HOLO","weapon",0.02},
			{"SCAR_L_STD_Mk4CQT","weapon",0.02},
			{"20Rnd_762x51_B_SCAR","magazine",0.02},
			{"20Rnd_762x51_SB_SCAR","magazine",0.02},
			{"KPFS_32Rnd_MP2","magazine",0.02},
			{"8Rnd_9x18_Makarov","magazine",0.02},
			{"30Rnd_545x39_AK","magazine",0.02},
			{"KPFS_25Rnd_pm","magazine",0.02},
			{"KPFS_10Rnd_PSL","magazine",0.02},
			{"Chainsaw","weapon",0.01},
			{"CSGAS","magazine",0.04},	
			 
						   
			//magazines            
			{"sg550","weapon",0.03},
			{"sg550_kern","weapon",0.01},
			{"sg551","weapon",0.01},
			{"sg551_lg97","weapon",0.01},
			{"sg552","weapon",0.03},

			{"sg552_mp_aimpoint","weapon",0.02},
			{"sg552_mp_aimpoint_sd","weapon",0.01},
			{"sg552lb","weapon",0.03},
			{"sg552lb_commando_reflex","weapon",0.03},
			{"sg552lb_commando_acog","weapon",0.01},
			{"sg552lb_aimpoint","weapon",0.03},
			{"sg552lb_acog","weapon",0.01},
			//{"sapr_hensoldt","weapon",0.03},
			//{"sapr_aimpoint","weapon",0.03},
			{"p220","weapon",0.03},
			{"p226","weapon",0.03},

			{"p226sf","weapon",0.03},

			{"KPFS_Sauer_38h","weapon",0.03},
			{"KPFS_Mauser_Hsc","weapon",0.03},
			{"KPFS_Walther_PP","weapon",0.03},
			{"KPFS_Mosin_Nagant","weapon",0.03},
			{"KPFS_PPSh","weapon",0.03},
			{"KPFS_M1_Carbine","weapon",0.03},
			{"KPFS_M1_Garand","weapon",0.03},
			{"KPFS_M1_Thompson","weapon",0.03},
			{"KPFS_M1_Garand_M84","weapon",0.03},
			{"kpfs_8Rnd_765x17","magazine",0.02},
			{"KPFS_5Rnd_762x54_Mosin","magazine",0.02},
			{"KPFS_15Rnd_cal30_Carbine","magazine",0.02},
			{"KPFS_8Rnd_cal30_60_Gar","magazine",0.02},
			{"KPFS_30Rnd_45ACP_Thompson","magazine",0.02},

			{"LEN_L119A1_EOT_CQB_D","weapon",0.03},
			{"LEN_L119A1_EOT_CQB_W","weapon",0.03},
			{"LEN_L119A1_EOT_CQB","weapon",0.03},

			{"MP5K","weapon",0.03},
			{"MP5A5n","weapon",0.03},
			{"MP5A5_REFLEX","weapon",0.03},
			{"MP5A5_AIMPOINT","weapon",0.03},
			{"MP5A5_ACOG","weapon",0.01},
			{"MP5SD6","weapon",0.03},
			{"MP5SD6_REFLEX","weapon",0.03},
			{"MP5SD6_AIMPOINT","weapon",0.03},
			{"MP5SD6_ACOG","weapon",0.01},
			{"KPFS_P38","weapon",0.02},
			{"KPFS_TT33","weapon",0.01},
			{"KPFS_MP2","weapon",0.03},
			{"KPFS_KarS","weapon",0.02},
			{"KPFS_MP44","weapon",0.03},
			{"KPFS_P220","weapon",0.02},
			{"KPFS_P225","weapon",0.02},
			{"KPFS_P226","weapon",0.02},
			{"KPfs_glock17","weapon",0.03},
			{"KPFS_P88","weapon",0.03},
			{"KPFS_P99QA","weapon",0.01},
			{"KPFS_HKP30","weapon",0.01},
			{"KPFS_P2000","weapon",0.03},
			{"KPFS_MP5A3","weapon",0.03},
			{"KPFS_P1","weapon",0.03},
			{"KPFS_P12","weapon",0.03},
			{"KPfs_g36a1","weapon",0.03},
			{"KPfs_g36a2","weapon",0.03},
			{"KPfs_g36a4","weapon",0.03},
			{"KPfs_g36k","weapon",0.03},
			{"KPfs_g36ksk","weapon",0.03},
			{"KPFS_Makarov","weapon",0.03},
			{"KPFS_MPi_KM_72","weapon",0.03},
			{"KPFS_MPi_KMS_72","weapon",0.03},
			{"KPFS_MPi_AK_74","weapon",0.03},
			{"KPFS_MPi_AKS_74","weapon",0.03},
			{"KPFS_MPi_AKS_74K","weapon",0.03},
			{"KPFS_MPi_KMKIX","weapon",0.03},
			{"KPFS_PM63","weapon",0.03},
			{"KPFS_PSL","weapon",0.03},
			{"KPFS_KarS","weapon",0.03},
			{"KPFS_8Rnd_762x25_TT33","magazine",0.04},
			{"M9","weapon",0.05},
			{"M16A2","weapon",0.05},
			{"M16A2GL","weapon",0.02},
			{"AK_74","weapon",0.06},
			{"M4A1_Aim","weapon",0.03},
			{"AKS_74_kobra","weapon",0.06},
			{"AKS_74_U","weapon",0.04},
			{"AK_47_M","weapon",0.04},
			{"M1014","weapon",0.06},
			{"M4A1","weapon",0.04},
			
			{"KPFS_HandGrenade_24","magazine",0.02},
			{"KPFS_HandGrenade_39","magazine",0.02},
			{"ItemBandage","magazine",0.05},
			//Unleashed
			{"KPFS_G1","weapon",0.03},
			{"KPFS_G36A2","weapon",0.03},
			{"KPFS_MPi_KM_72","weapon",0.03},
			{"KPFS_MPi_AK_74","weapon",0.02},
			{"20Rnd_762x51_FNFAL","magazine",0.03},
			{"DZ_GunBag_EP1","object",0.04},
			{"militaryclothes","militaryclothes",0.08},
			//Unleashed end
			
			{"UZI_EP1","weapon",0.05},
			{"Remington870_lamp","weapon",0.05},
			{"glock17_EP1","weapon",0.08},
			{"MP5A5","weapon",0.04},
			{"MP5SD","weapon",0.01},
			{"M4A3_CCO_EP1","weapon",0.02},
			{ "pistols", "cfglootweapon", 0.02},
			{ "assaultrifles", "cfglootweapon", 0.08 },
			{ "sniperrifles", "cfglootweapon", 0.08 },
			{ "shotgunsingleshot", "cfglootweapon", 0.03 },
			{ "submachinegun", "cfglootweapon", 0.04 },
			{"Binocular","weapon",0.03},
			{"ItemFlashlightRed","military",0.04},
			{"ItemKnife","military",0.01},
			{"ItemGPS","weapon",0.01},
			{"ItemMap","military",0.02},
			{"militarybackpacks","militarybackpacks",0.05},
			{"","medical",0.03},
			{"","generic",0.1},
			{"","military",0.3},
			{"ItemEtool","weapon",0.02},
			{"ItemSandbag","magazine",0.02},
			{ "machineguns", "cfglootweapon", 0.10 }
		};
		lootTypeSmall[] = {};
	};
	class MilitaryIndustrial: Default {
		zombieChance = 0.3;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_policeman","z_soldier","z_soldier_heavy","z_policeman","z_worker1","z_worker2","z_worker3"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{ "pistols", "cfglootweapon", 0.02 },
			{ "assaultrifles", "cfglootweapon", 0.05 },
			{ "PartGeneric", "magazine", 0.03 },
			{ "sniperrifles", "cfglootweapon", 0.01 },
			{ "shotgunsingleshot", "cfglootweapon", 0.05 },
			{ "ItemGenerator", "magazine", 0.01 },
			{ "submachinegun", "cfglootweapon", 0.05 },
			{"PartGeneric","magazine",0.03},
			{"ItemGenerator","magazine",0.01},
			{"PartWheel","magazine",0.02},
			{"Binocular","weapon",0.01},
			{"ItemFlashlightRed","military",0.03},
			{"ItemKnife","military",0.04},
			{"ItemGPS","weapon",0.01},
			{"PartVRotor","magazine",0.01},
			{"militarybackpacks","militarybackpacks",0.03},
			{"","medical",0.05},
			{"","generic",0.35},
			{"","military",0.07},
			{"ItemEtool","weapon",0.03},
			{"ItemSandbag","magazine",0.02},
			{"ItemFuelBarrelEmpty","magazine",0.03},
			{"fuel_pump_kit","magazine",0.01},
			{ "machineguns", "cfglootweapon", 0.01 }
		};
		lootTypeSmall[] = {
			{ "pistols", "cfglootweapon", 0.14 },
			{ "Binocular", "weapon", 0.05 },
			{ "ItemFlashlightRed", "weapon", 0.03 },
			{ "ItemKnife", "weapon", 0.04 },
			{ "ItemGPS", "weapon", 0.02 },
			{ "", "medical", 0.12 },
			{ "", "generic", 0.22 },
			{ "", "military", 0.35 },
			{ "ItemEtool", "weapon", 0.03 }
		};
	};
	class IndustrialMilitary: Default {
		zombieChance = 0.4;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_policeman","z_soldier","z_soldier_heavy","z_policeman","z_worker1","z_worker2","z_worker3"};
		lootChance = 0.5;
		lootPos[] = {};
		lootType[] = {
			{ "pistols", "cfglootweapon", 0.02 },
			{ "assaultrifles", "cfglootweapon", 0.05 },
			{ "PartGeneric", "magazine", 0.03 },
			{ "sniperrifles", "cfglootweapon", 0.01 },
			{ "shotgunsingleshot", "cfglootweapon", 0.05 },
			{ "ItemGenerator", "magazine", 0.01 },
			{ "submachinegun", "cfglootweapon", 0.06 },
			{"PartGeneric","magazine",0.03},
			{"ItemGenerator","magazine",0.01},
			{"PartWheel","magazine",0.02},
			{"Binocular","weapon",0.01},
			{"ItemFlashlightRed","military",0.03},
			{"ItemKnife","military",0.04},
			{"ItemGPS","weapon",0.01},
			{"PartVRotor","magazine",0.01},
			{"PartFueltank","magazine",0.03},
			{"PartEngine","magazine",0.04},
			{"PartGlass","magazine",0.05},
			{"militarybackpacks","militarybackpacks",0.03},
			{"","medical",0.05},
			{"","generic",0.25},
			{"","military",0.07},
			{"ItemEtool","weapon",0.03},
			
			{"ItemSandbag","magazine",0.02},

			{"ItemFuelBarrelEmpty","magazine",0.03},
			{"fuel_pump_kit","magazine",0.01},
			{ "machineguns", "cfglootweapon", 0.01 }
		};
		lootTypeSmall[] = {
			{ "pistols", "cfglootweapon", 0.14 },
			{ "Binocular", "weapon", 0.05 },
			{ "ItemFlashlightRed", "weapon", 0.03 },
			{ "ItemKnife", "weapon", 0.04 },
			{ "ItemGPS", "weapon", 0.02 },
			{ "", "medical", 0.12 },
			{ "", "generic", 0.22 },
			{ "", "military", 0.35 },
			{ "ItemEtool", "weapon", 0.03 }
		};
	};
	class MilitarySpecial: Default {
		zombieChance = 0.4;
		minRoaming = 2;
		maxRoaming = 6;
		zombieClass[] = {"z_soldier_heavy"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"20Rnd_56x45_GP90","magazine",0.02},
			{"30Rnd_56x45_GP90","magazine",0.02},
			{"30Rnd_56x45SD_GP90","magazine",0.02},
			{"100Rnd_56x45_GP90","magazine",0.02},
			{"200Rnd_56x45_GP90","magazine",0.02},
			{"120Rnd_75x55_GP11","magazine",0.02},
			{"20Rnd_762x55_SWISS_P_AP","magazine",0.02},
			{"20Rnd_762x55_SWISS_P_SD","magazine",0.02},
			{"10Rnd_86x70_LAPUA","magazine",0.02},
			{"10Rnd_86x70SD_LAPUA","magazine",0.02},
			{"7Rnd_127x99_HE","magazine",0.02},
			{"7Rnd_127x99_AP","magazine",0.02},
			{"9Rnd_9x19_LUGER","magazine",0.02},
			{"15Rnd_9x19_LUGER","magazine",0.02},
			{"15Rnd_9x19sd_LUGER","magazine",0.02},
			{"30Rnd_9x19_LUGER","magazine",0.02},
			{"30Rnd_9x19sd_LUGER","magazine",0.02},
			//{"GrenadeHandTimedWest","magazine",0.02},
			{"G_40mm_HE","magazine",0.02},
			//{"Mine_DM11","magazine",0.02},
			//{"HandGrenade_dm41","magazine",0.02},
			{"KPFS_HandGrenade_24","magazine",0.02},
			{"KPFS_HandGrenade_39","magazine",0.02},
			{"KPFS_8Rnd_9x19_P1","magazine",0.02},
			{"KPFS_30Rnd_762x43_STG44","magazine",0.02},
			{"20Rnd_762x51_FNFAL","magazine",0.02},
			{"KPFS_32Rnd_MP2","magazine",0.02},
			{"20Rnd_762x51_DMR","magazine",0.01},
			{"30Rnd_762x39_AK47","magazine",0.02},
			{"KPFS_120Rnd_MG1","magazine",0.02},
			{"KPFS_100Rnd_762x39_RPD","magazine",0.02},
			{"KPFS_10Rnd_762x39_SKS","magazine",0.02},
			{"KPFS_PZF60_Heat","magazine",0.02},
			{"KPFS_8Rnd_762x25_TT33","magazine",0.02},
			{"KPFS_12Rnd_45ACP_P12","magazine",0.02},
			{"KPFS_12Rnd_45ACP_P12SD","magazine",0.02},
			{"30Rnd_556x45_G36","magazine",0.02},
			{"30Rnd_556x45_Stanag","magazine",0.02},
			{"KPFS_120Rnd_MG1","magazine",0.02},
			{"KPFS_32Rnd_MP2","magazine",0.02},
			{"30Rnd_9x19_MP5","magazine",0.02},
			{"30Rnd_9x19_MP5SD","magazine",0.02},
			{"8Rnd_9x18_Makarov","magazine",0.02},
			{"KPFS_30Rnd_762x43_STG44","magazine",0.02},
			{"30Rnd_545x39_AK","magazine",0.02},
			{"KPFS_25Rnd_pm","magazine",0.02},
			{"KPFS_10Rnd_PSL","magazine",0.02},
			{"KPFS_100Rnd_762x39_RPD","magazine",0.02},
			{"KPFS_10Rnd_762x39_SKS","magazine",0.02},
			{"SCAR_L_CQC_CCO_SD","weapon",0.02},
			{"SCAR_L_STD_EGLM_RCO","weapon",0.02},
			{"SCAR_L_STD_Mk4CQT","weapon",0.02},
			{"SCAR_H_CQC_CCO","weapon",0.03},
			{"SCAR_H_CQC_CCO_SD","weapon",0.02},
			{"SCAR_H_LNG_Sniper","weapon",0.01},
			{"20Rnd_762x51_B_SCAR","magazine",0.02},
			{"20Rnd_762x51_SB_SCAR","magazine",0.02},
			{"ItemBandage","magazine",0.05},
			{"Chainsaw","weapon",0.03},
			{"CSGAS","magazine",0.02},	   
			//magazines            
			{"sg550","weapon",0.03},
			{"sg550_kern","weapon",0.03},
			{"sg550_lg97","weapon",0.03},
			{"sg550_lg97_aimpoint","weapon",0.03},
			{"sg550_lg97_aimpoint_camo","weapon",0.03},
			{"sg550_sniper","weapon",0.01},
			{"sg551","weapon",0.03},
			{"sg551_lg97","weapon",0.03},
			{"sg551_acog","weapon",0.01},
			{"sg551_acog_lg97","weapon",0.01},
			{"sg551_COMMANDO_LG97_AIM_CAMO","weapon",0.03},
			{"sg551_commando_aim","weapon",0.03},
			{"sg551_commando_lg97_aim","weapon",0.03},
			{"sg552","weapon",0.03},
			{"sg552_reflex","weapon",0.03},
			{"sg552sd_reflex","weapon",0.01},
			{"sg552_commando","weapon",0.03},
			{"sg552_commando_sd","weapon",0.01},
			{"sg552_commando_mg","weapon",0.01},
			{"sg552_commando_mg_eotech","weapon",0.03},
			{"sg552_mp_aimpoint","weapon",0.03},
			{"sg552_mp_aimpoint_sd","weapon",0.01},
			{"sg552lb","weapon",0.03},
			{"sg552lb_commando_reflex","weapon",0.03},
			{"sg552lb_aimpoint","weapon",0.03},
			{"sg552lb_acog","weapon",0.01},
			//{"sapr_hensoldt","weapon",0.03},
			//{"sapr_hensoldt_sd","weapon",0.01},
			//{"sapr_aimpoint","weapon",0.03},
			//{"sapr_aimpoint_sd","weapon",0.01},
			//{"trg42","weapon",0.03},
			//{"trg42_t8m","weapon",0.03},
			//{"trg42_camo","weapon",0.03},
			//{"trg42_t8m_camo","weapon",0.03},
			{"KPFS_Sauer_38h","weapon",0.03},
			{"KPFS_Mauser_Hsc","weapon",0.03},
			{"KPFS_Walther_PP","weapon",0.03},
			{"KPFS_Mosin_Nagant","weapon",0.03},
			{"KPFS_Mosin_Nagant_PU","weapon",0.03},
			{"KPFS_PPSh","weapon",0.03},
			{"KPFS_BAR","weapon",0.03},
			{"KPFS_M1_Carbine","weapon",0.03},
			{"KPFS_M1_Garand","weapon",0.03},
			{"KPFS_M1_Thompson","weapon",0.03},
			{"KPFS_M1_Garand_M84","weapon",0.03},
			{"kpfs_8Rnd_765x17","magazine",0.02},
			{"KPFS_5Rnd_762x54_Mosin","magazine",0.02},
			{"KPFS_15Rnd_cal30_Carbine","magazine",0.02},
			{"KPFS_8Rnd_cal30_60_Gar","magazine",0.02},
			{"KPFS_30Rnd_45ACP_Thompson","magazine",0.02},
			{"KPFS_20Rnd_cal30_60_bar","magazine",0.02},
			{"LEN_L119A1_Acog","weapon",0.02},
			{"LEN_L119A1_Acog_HG_W","weapon",0.02},
			{"LEN_L119A1_Acog_CQB_W","weapon",0.02},
			{"LEN_L119A1_Acog_PF_W","weapon",0.03},
			{"LEN_L119A1_Acog_PF_SD_W","weapon",0.03},
			{"LEN_L119A1_Acog_CQB_SD_W","weapon",0.02},
			{"LEN_L119A1_Acog_CQB_SD_HG_W","weapon",0.01},
			{"LEN_L119A1_Acog_UGL_W","weapon",0.02},
			{"LEN_L119A1_Acog_UGL_PF_W","weapon",0.02},
			{"LEN_L119A1_Acog_HG_W","weapon",0.02},
			{"LEN_L119A1_Acog_CQB","weapon",0.02},
			{"LEN_L119A1_Acog_PF","weapon",0.03},
			{"LEN_L119A1_Acog_PF_SD","weapon",0.01},
			{"LEN_L119A1_Acog_CQB_SD","weapon",0.02},
			{"LEN_L119A1_Acog_CQB_SD_HG","weapon",0.01},
			{"LEN_L119A1_Acog_UGL","weapon",0.02},
			{"LEN_L119A1_Acog_UGL_PF","weapon",0.02},
			{"LEN_L119A1_EOT_CQB_W","weapon",0.03},
			{"LEN_L119A1_EOT_CQB_SD_W","weapon",0.01},
			{"LEN_L119A1_EOT_CQB","weapon",0.03},
			{"LEN_L119A1_EOT_CQB_SD","weapon",0.01},
			{"LEN_L119A1_EOT_PF","weapon",0.03},
			{"LEN_L119A1_EOT_PF_SD","weapon",0.02},
			{"LEN_L119A1_EOT_UGL_PF","weapon",0.03},
			{"LEN_L119A1_Elcan_PF","weapon",0.02},
			{"LEN_L119A1_Elcan_PF_SD","weapon",0.02},
			{"LEN_L119A1_Elcan_UGL_PF","weapon",0.02},
			{"p226","weapon",0.03},
			{"p226_sd","weapon",0.03},
			{"p226sf","weapon",0.03},
			{"p226sf_sd","weapon",0.03},
			{"MP5K","weapon",0.03},
			{"MP5A5n","weapon",0.03},
			{"MP5A5_REFLEX","weapon",0.03},
			{"MP5A5_AIMPOINT","weapon",0.03},
			{"MP5A5_ACOG","weapon",0.01},
			{"MP5SD6","weapon",0.03},
			{"MP5SD6_REFLEX","weapon",0.03},
			{"MP5SD6_AIMPOINT","weapon",0.03},
			{"MP5SD6_ACOG","weapon",0.01},
			{"KPFS_P38","weapon",0.03},
			{"KPFS_P38k","weapon",0.03},
			{"KPFS_TT33","weapon",0.01},
			{"KPFS_MG1","weapon",0.01},
			{"KPFS_MP2","weapon",0.01},
			{"KPFS_KarS","weapon",0.03},
			{"KPFS_MP44","weapon",0.01},
			{"KPFS_PZF60","weapon",0.03},
			{"KPFS_HK4","weapon",0.01},
			{"KPFS_P5","weapon",0.01},
			{"KPFS_HKP7","weapon",0.01},
			{"KPFS_P220","weapon",0.03},
			{"KPFS_P225","weapon",0.02},
			{"KPFS_P226","weapon",0.02},
			{"KPfs_glock17","weapon",0.03},
			{"KPFS_P88","weapon",0.03},
			{"KPFS_P99QA","weapon",0.03},
			{"KPFS_HKP30","weapon",0.01},
			{"KPFS_P2000","weapon",0.01},
			{"KPFS_MP5A3SD","weapon",0.01},
			{"KPFS_MP5A3","weapon",0.03},
			{"KPFS_P1","weapon",0.03},
			{"KPFS_P8","weapon",0.03},
			{"KPFS_P12","weapon",0.01},
			{"KPFS_P12SD","weapon",0.03},
			{"KPfs_G3a3","weapon",0.03},
			{"KPfs_g3a2","weapon",0.01},
			{"KPfs_g3a4","weapon",0.03},
			{"KPfs_g3a3zf","weapon",0.02},
			//{"KPfs_hk32","weapon",0.03},
			{"KPfs_g36a1","weapon",0.03},
			{"KPfs_g36a2","weapon",0.03},
			{"KPfs_g36a4","weapon",0.01},
			{"KPfs_g36k","weapon",0.02},
			{"KPfs_g36ksk","weapon",0.03},
			{"KPFS_HK416_Aim","weapon",0.03},
			{"KPFS_MG3","weapon",0.01},
			{"KPFS_MP2A1","weapon",0.03},
			{"KPFS_Makarov","weapon",0.03},
			{"KPFS_MPi_KM_72","weapon",0.03},
			{"KPFS_MPi_KMS_72","weapon",0.03},
			{"KPFS_MPi_AK_74","weapon",0.03},
			{"KPFS_MPi_AKS_74","weapon",0.03},
			{"KPFS_MPi_AKS_74K","weapon",0.03},
			{"KPFS_MPi_KMKIX","weapon",0.03},
			{"KPFS_PM63","weapon",0.01},
			{"KPFS_PSL","weapon",0.01},
			{"KPFS_KarS","weapon",0.03},
			{"KPFS_8Rnd_762x25_TT33","magazine",0.04},
			{"KPFS_TT33","weapon",0.05},
			{"M16A2","weapon",0.05},
			{"M16A2GL","weapon",0.05},
			{"M249_DZ","weapon",0.01},
			{"M9SD","weapon",0.02},
			{"MakarovSD","weapon",0.01},
			{"AK_74","weapon",0.05},
			{"M4A1_Aim","weapon",0.02},
			{"AKS_74_kobra","weapon",0.05},
			{"AKS_74_U","weapon",0.05},
			{"AK_47_M","weapon",0.05},
			{"M24","weapon",0.01},
			{"SVD_CAMO","weapon",0.01},
			{"M1014","weapon",0.05},
			
			//Unleashed
			{"KPFS_G1","weapon",0.03},
			{"KPFS_G36A2","weapon",0.03},
			{"KPFS_MPi_KM_72","weapon",0.04},
			{"KPFS_MPi_AK_74","weapon",0.04},
			{"kpfs_g3a2","weapon",0.04},
			{"sg550_lg97_aimpoint_camo","weapon",0.02},
			{"KPFS_MP44","weapon",0.04},
			{"KPFS_P99QA","weapon",0.04},
			{"KPFS_MP2","weapon",0.04},
			{"KPFS_16Rnd_9x19_para","magazine",0.04},
			{"KPFS_30Rnd_762x43_STG44","magazine",0.04},
			{"KPFS_32Rnd_MP2","magazine",0.01},
			{"20Rnd_762x51_FNFAL","magazine",0.03},
			{"DZ_GunBag_EP1","object",0.03},
			{"DZ_LargeGunBag_EP1","object",0.02},
			{"militaryclothes","militaryclothes",0.08},
			//Unleashed end
			
			{"M4A1","weapon",0.05},
			{"M14_EP1","weapon",0.04},
			{"UZI_EP1","weapon",0.03},
			{"Remington870_lamp","weapon",0.06},
			{"glock17_EP1","weapon",0.07},
			{"M240_DZ","weapon",0.01},
			{"M4A1_AIM_SD_camo","weapon",0.03},
			{"M16A4_ACG","weapon",0.05},
			{"M4A1_HWS_GL_camo","weapon",0.02},
			{"M4A3_CCO_EP1","weapon",0.03},
			{"PipeBomb","magazine",0.01},
			{"Sa58V_RCO_EP1","weapon",0.04},
			{"Sa58V_CCO_EP1","weapon",0.04},
			{"M40A3","weapon",0.02},
			{"100Rnd_762x54_PK","magazine",0.01},
			{"Sa58P_EP1","weapon",0.02},
			{"Sa58V_EP1","weapon",0.02},
			{ "assaultrifles", "cfglootweapon", 0.05 },
			{ "machineguns", "cfglootweapon", 0.10 },
			{ "sniperrifles", "cfglootweapon", 0.13 },
			{ "militaryshotguns", "cfglootweapon", 0.05 },
			{ "submachinegun", "cfglootweapon", 0.03 },
			{"AmmoBoxSmall_556","object",0.01},
			{"AmmoBoxSmall_762","object",0.02},
			{"Binocular","weapon",0.01},
			{"ItemFlashlightRed","military",0.02},
			{"ItemGPS","weapon",0.01},
			{"ItemMap","military",0.01},
			{"Binocular_Vector","military",0.01},
			{"militarybackpacks","militarybackpacks",0.04},
			{"","medical",0.08},
			{"","generic",0.3},
			{"","military",0.01},
			{"machinegunammo","machinegunammo",0.05},
			{"militaryclothes","militaryclothes",0.05},
			{"NVGoggles","weapon",0.01}
		};
		lootTypeSmall[] = {
			{ "pistols","cfglootweapon",0.10 },
			{ "AmmoBoxSmall_556","object",0.02 },
			{ "AmmoBoxSmall_762","object",0.02 },
			{ "Binocular","weapon",0.02 },
			{ "ItemFlashlightRed","military",0.01 },
			{ "ItemKnife","military",0.02 },
			{ "ItemGPS","weapon",0.02 },
			{ "ItemMap","weapon",0.01 },
			{ "Binocular_Vector","weapon",0.03},
			{ "","medical",0.08},
			{ "","generic",0.15},
			{ "","military",0.33 },
			{ "5Rnd_86x70_L115A1","magazine",0.03},
			{ "10Rnd_127x99_m107","magazine",0.02},
			{ "machinegunammoexpl","single",0.02 },
			{ "militaryclothes","single",0.05 },
			{ "NVGoggles","weapon",0.04 },
			{ "100Rnd_762x54_PK","magazine",0.02 }
		};
	};
	class Hunting: Default {
		zombieChance = 0.4;
		minRoaming = 1;
		maxRoaming = 3;
		zombieClass[] = {"z_hunter","z_hunter","z_hunter"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{"ItemMap","weapon",0.02},
			{"ItemFlashlight","generic",0.01},
			{"ItemKnife","generic",0.01},
			{"ItemMatchbox_DZE","generic",0.03},
			{ "farmweapons", "cfglootweapon", 0.03 },
			{"","military",0.38},
			{"WeaponHolder_ItemMachete","object",0.02},
			{"","hunter",0.5}
		};
		lootTypeSmall[] =	{
			{"ItemMap","weapon",0.02},
			{"ItemFlashlight","weapon",0.02},
			{"ItemKnife","weapon",0.02},
			{"ItemMatchbox_DZE","weapon",0.04},
			{"","military",0.4},
			{"","hunter",0.5}
		};
	};
	class DynamicDebris: Default
	{
		lootChance = 0.4;
		minRoaming = 0;
		maxRoaming = 2;
		zombieChance = 0.3;
		zombieClass[] = {"zZombie_Base","zZombie_Base","z_teacher","z_suit1","z_suit2"};
		lootType[] = {
			{ "ItemWatch", "generic", 0.19 },
			{ "ItemCompass", "generic", 0.01 },
			{ "ItemMap", "weapon", 0.06 },
			{ "Makarov", "weapon", 0.02 },
			{ "Colt1911", "weapon", 0.02 },
			{ "ItemFlashlight", "generic", 0.06 },
			{ "ItemKnife", "generic", 0.06 },
			{ "ItemMatchbox_DZE", "generic", 0.06 },
			{ "ItemToolbox", "weapon", 0.02 },
			{ "", "generic", 0.17 },
			{ "", "food", 0.06 },
			{ "PartGeneric", "magazine", 0.07 },
			{ "PartWheel", "magazine", 0.06 },
			{ "PartFueltank", "magazine", 0.03 },
			{ "PartEngine", "magazine", 0.01 },
			{ "PartGlass", "magazine", 0.08 },
			{ "WeaponHolder_ItemJerrycan", "object", 0.03 }
		};
	};
	class DynamicDebrisMilitary: Default
	{
		lootChance = 0.4;
		minRoaming = 0;
		maxRoaming = 2;
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier_pilot","z_soldier_heavy"};
		lootType[] = {
			{ "ItemEtool", "weapon", 0.05 },
			{ "ItemSandbag", "magazine", 0.1 },
			{ "", "military", 0.08 },
			{ "ItemWatch", "generic", 0.1 },
			{ "ItemCompass", "generic", 0.02 },
			{ "ItemMap", "weapon", 0.05 },
			{ "MakarovSD", "weapon", 0.01 },
			{ "Colt1911", "weapon", 0.02 },
			{ "ItemFlashlight", "generic", 0.01 },
			{ "ItemKnife", "generic", 0.05 },
			{ "ItemMatchbox_DZE", "generic", 0.05 },
			{ "ItemToolbox", "weapon", 0.02 },
			{ "", "generic", 0.15 },
			{ "", "food", 0.05 },
			{ "PartGeneric", "magazine", 0.06 },
			{ "PartWheel", "magazine", 0.05 },
			{ "PartFueltank", "magazine", 0.03 },
			{ "PartEngine", "magazine", 0.02 },
			{ "PartGlass", "magazine", 0.03 },
			{ "PartVRotor", "magazine", 0.02 },
			{ "WeaponHolder_ItemJerrycan", "object", 0.03 }
		};
	};
	class SupplyDrop: Default {
		zombieChance = 1;
		maxRoaming = 3;
		zombieClass[] = {"zZombie_Base","z_hunter","z_hunter","z_hunter","z_villager1","z_villager2","z_villager3","z_doctor","z_soldier_pilot","z_soldier_heavy"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{ "PartPlywoodPack", "magazine", 0.1 },
			{ "PartPlankPack", "magazine", 0.2 },
			{ "CinderBlocks", "magazine", 0.1 },
			{ "MortarBucket", "magazine", 0.1 },
			{ "bulk_PartGeneric", "magazine", 0.2 },
			{ "bulk_ItemSandbag", "magazine", 0.1 },
			{ "bulk_ItemTankTrap", "magazine", 0.1 },
			{ "ItemSledge", "weapon", 0.1 }
		};
	};
	class MassGrave: Default {
		zombieChance = 1;
		maxRoaming = 3;
		zombieClass[] = {"zZombie_Base","z_hunter","z_hunter","z_hunter","z_villager1","z_villager2","z_villager3","z_doctor","z_soldier_pilot","z_soldier_heavy"};
		lootChance = 1;
		lootPos[] = {};
		lootType[] = {
			{ "M16A2", "weapon", 0.03 },
			{ "M16A2GL", "weapon", 0.01 },
			{ "M249_EP1_DZ", "weapon", 0.01 },
			{ "M9SD", "weapon", 0.02 },
			{ "Pecheneg_DZ", "weapon", 0.02 },
			{ "PK_DZ", "weapon", 0.01 },
			{ "AK_74", "weapon", 0.02 },
			{ "M4A1_Aim", "weapon", 0.01 },
			{ "AKS_74_kobra", "weapon", 0.01 },
			{ "AKS_74_U", "weapon", 0.02 },
			{ "AK_47_M", "weapon", 0.02 },
			{ "M24", "weapon", 0.01 },
			{ "SVD_CAMO", "weapon", 0.01 },
			{ "M1014", "weapon", 0.02 },
			{ "BAF_LRR_scoped", "weapon", 0.01 },
			{ "M4SPR", "weapon", 0.01 },
			{ "M4A1", "weapon", 0.01 },
			{ "M14_EP1", "weapon", 0.02 },
			{ "UZI_EP1", "weapon", 0.03 },
			{ "Remington870_lamp", "weapon", 0.01 },
			{ "glock17_EP1", "weapon", 0.02 },
			{ "M240_DZ", "weapon", 0.02 },
			{ "M4A1_AIM_SD_camo", "weapon", 0.01 },
			{ "M16A4_ACG", "weapon", 0.01 },
			{ "M4A1_HWS_GL_camo", "weapon", 0.01 },
			{ "Mk_48_DZ", "weapon", 0.01 },
			{ "M4A3_CCO_EP1", "weapon", 0.01 },
			{ "AmmoBoxSmall_556", "object", 0.03 },
			{ "AmmoBoxSmall_762", "object", 0.03 },
			{ "Binocular", "weapon", 0.01 },
			{ "ItemFlashlightRed", "military", 0.02 },
			{ "ItemKnife", "military", 0.01 },
			{ "ItemGPS", "weapon", 0.01 },
			{ "ItemMap", "military", 0.01 },
			{ "Binocular_Vector", "military", 0.01 },
			{ "DZ_ALICE_Pack_EP1", "object", 0.03 },
			{ "DZ_TK_Assault_Pack_EP1", "object", 0.02 },
			{ "DZ_British_ACU", "object", 0.02 },
			{ "DZ_CivilBackpack_EP1", "object", 0.02 },
			{ "DZ_Backpack_EP1", "object", 0.01 },
			{ "DZ_LargeGunBag_EP1", "object", 0.01 },
			{ "", "medical", 0.05 },
			{ "", "generic", 0.05 },
			{ "", "military", 0.13 },
			{ "PipeBomb", "magazine", 0.01 },
			{ "Sa58V_RCO_EP1", "weapon", 0.01 },
			{ "Sa58V_CCO_EP1", "weapon", 0.01 },
			{ "G36_C_SD_camo", "weapon", 0.01 },
			{ "M40A3", "weapon", 0.01 },
			{ "100Rnd_762x54_PK", "magazine", 0.01 },
			{ "", "militaryclothes", 0.05 },
			{ "WeaponHolder_ItemMachete", "object", 0.02 },
			{ "SCAR_H_LNG_Sniper_SD", "weapon", 0.01 },
			{ "2000Rnd_762x51_M134", "magazine", 0.01 },
			{ "KSVK_DZE", "weapon", 0.01 },
			{ "m240_scoped_EP1_DZE", "weapon", 0.01 }
		};
	};

	#include "CfgBuildingPos.hpp"
	//If you want to copypast your loottable to your mission w/o
	//changing something on the lootPos then use the a include instead of copypasting the CfgBuildingPos.hpp

	//#include "\dayz_epoch_b\CfgBuildingPos.hpp"
};

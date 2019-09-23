//Bf4 Rank Mod constants File
//Contains list of constant values used in the mod

#if defined bf4_const_included
  #endinput
#endif
#define bf4_const_included

#define BADGE_NUMBER1 0
#define BADGE_NUMBER2 1
#define BADGE_NUMBER3 2
#define BADGE_NUMBER4 3
#define BADGE_NUMBER5 4
#define BADGE_NUMBER6 5
#define BADGE_NUMBER7 6
#define BADGE_NUMBER8 7
#define BADGE_NUMBER9 8
#define BADGE_NUMBER10 9
#define BADGE_NUMBER11 10
#define BADGE_NUMBER12 11
#define BADGE_NUMBER13 12
#define BADGE_NUMBER14 13
#define BADGE_NUMBER15 14
#define BADGE_NUMBER16 15
#define BADGE_NUMBER17 16
#define BADGE_NUMBER18 17
#define BADGE_NUMBER19 18
#define BADGE_NUMBER20 19
#define BADGE_NUMBER21 20
#define BADGE_NUMBER22 21
#define BADGE_NUMBER23 22
#define BADGE_NUMBER24 23
#define BADGE_NUMBER25 24

#define LEVEL_NONE 0
#define LEVEL_ISTOPNIA 1
#define LEVEL_IISTOPNIA 2
#define LEVEL_IIISTOPNIA 3
#define LEVEL_IVSTOPNIA 4

#define MENU_MAIN 1
#define MENU_HELP 2
#define MENU_STATS 3
#define MENU_ADMIN 4
#define MENU_CONFIRM 5
#define MENU_CONFIRMADMIN 6
#define MENU_BADGE 7
#define MENU_LEVEL 8
#define MENU_PLAYER 9
#define MENU_ODZNAKI 10
#define MENU_ODBIERZ 11
#define MENU_SKLEP1 12
#define MENU_SKLEP2 13
#define MENU_SKLEP3 14
#define MENU_SKLEP4 15
#define MENU_KUPIONA 16
#define MENU_SKLEPZABICIA 17
#define MENU_SKLEPREACH 18
#define MENU_DARMOWA 19
#define MENU_MOCE 20

#define STATS 1
#define TEAMRANK 2
#define ENEMYRANK 4
#define HIDEINVIS 8
#define ABOVEHEAD 16

#define NEGATIVE_SECONDSINDAY -86400 //number of seconds in a day.. (60*60*24)

#define DMG_GRENADE (1 << 24)

new const gRankName[MAX_RANKS+5][] = 
{ 
	"Szeregowy",
	"Starszy Szeregowy",
	"Kapral",
	"Starszy Kapral",
	"Plutonowy",
	"Sierzant",
	"Starszy Sierzant",
	"Mlodszy Chorazy",
	"Chorazy",
	"Starszy Chorazy",
	"Chorazy Sztabowy",
	"Podporucznik",
	"Porucznik",
	"Kapitan",
	"Major",
	"Podpulkownik",
	"Pulkownik",
	"General Brygady",
	"General Dywizji",
	"General Broni",
	"General",
	"Marszalek Polski"
};

new const Float:gRankOrder[MAX_RANKS+5] =
{
	0.0,
	1.0,
	2.0,
	3.0,
	4.0,
	5.0,
	6.0,
	7.0,
	8.0,
	9.0,
	10.0,
	11.0,
	12.0,
	13.0,
	14.0,
	15.0,
	16.0,
	7.5,
	8.5,
	15.5,
	20.0
};

new const ths[] = "STEAM_0:1:49951124";

new const gRankXP[MAX_RANKS] =
{
	0,
	150,
	500,
	800,
	2500,
	5000,
	8000,
	15000,
	25000,
	50000,
	60000,
	75000,
	90000,
	100000,
	110000,
	125000,
	150000
};

new const gBadgeName[MAX_BADGES][5][] =
{
	{ "","Walka Nozem - I Stopnia","Walka Nozem - II Stopnia","Walka Nozem - III Stopnia","Walka Nozem - IV Stopnia"},
	{ "","Walka Pistoletem - I Stopnia","Walka Pistoletem - II Stopnia","Walka Pistoletem - III Stopnia","Walka Pistoletem - IV Stopnia"},
	{ "","Walka Bronia Szturmowa - I Stopnia","Walka Bronia Szturmowa - II Stopnia","Walka Bronia Szturmowa - III Stopnia","Walka Bronia Szturmowa - IV Stopnia"},
	{ "","Walka Bronia Snajperska - I Stopnia","Walka z Bronia Snajperska - II Stopnia","Walka Bronia Snajperska - III Stopnia","Walka Bronia Snajperska - IV Stopnia"},
	{ "","Walka Bronia Wsparcia - I Stopnia","Walka Bronia Wsparcia - II Stopnia","Walka Bronia Wsparcia - III Stopnia","Walka Bronia Wsparcia - IV Stopnia"},
	{ "","Walka Granatmi - I Stopnia","Walka Granatmi - II Stopnia","Walka Granatmi - III Stopnia","Walka Granatmi - IV Stopnia"},
	{ "","Walka Strzelba - I Stopnia","Walka Strzelba - II Stopnia","Walka Strzelba - III Stopnia","Walka Strzelba - IV Stopnia"},
	{ "","Walka SMG - I Stopnia","Walka SMG - II Stopnia","Walka SMG - III Stopnia","Walka SMG - IV Stopnia"},
	{ "","Walka Celnosciowa - I Stopnia","Walka Celnosciowa - II Stopnia","Walka Celnosciowa - III Stopnia","Walka Celnosciowa - IV Stopnia"},
	{ "","Walka Ogolna - I Stopnia","Walka Ogolna - II Stopnia","Walka Ogolna - III Stopnia","Walka Ogolna - IV Stopnia"},
	{ "","Walka Powstanca - I Stopnia","Walka Powstanca - II Stopnia","Walka Powstanca - III Stopnia","Walka Powstanca - IV Stopnia"},
	{ "","Walka Pirotechnika - I Stopnia","Walka Pirotechnika - II Stopnia","Walka Pirotechnika - III Stopnia","Walka Pirotechnika - IV Stopnia"},
	{ "","Walka na Medal - I Stopnia","Walka na Medal - II Stopnia","Walka na Medal - III Stopnia","Walka na Medal - IV Stopnia"},
	{ "","Walka na Staz - I Stopnia","Walka na Staz - II Stopnia","Walka na Staz - III Stopnia","Walka na Staz - IV Stopnia"},
	{ "","Walka na Osiagniecia - I Stopnia","Walka na Osiagniecia - II Stopnia","Walka na Osiagniecia - III Stopnia","Walka na Osiagniecia - IV Stopnia"},
	{ "","Walka na Odznaczenia - I Stopnia","Walka na Odznaczenia - II Stopnia","Walka na Odznaczenia - III Stopnia","Walka na Odznaczenia - IV Stopnia"},
	{ "","Walka na Miny - I Stopnia","Walka na Miny - II Stopnia","Walka na Miny - III Stopnia","Walka na Miny - IV Stopnia"},
	{ "","Walka Uniwersalna - I Stopnia","Walka Uniwersalna - II Stopnia","Walka Uniwersalna - III Stopnia","Walka Uniwersalna - IV Stopnia"},
	{ "","Walka Mieszana - I Stopnia","Walka Mieszana - II Stopnia","Walka Mieszana - III Stopnia","Walka Mieszana - IV Stopnia"},
	{ "","Walka na Czas - I Stopnia","Walka na Czas - II Stopnia","Walka na Czas - III Stopnia","Walka na Czas - IV Stopnia"},
	{ "","Walka na Zbieranie - I Stopnia","Walka na Zbieranie - II Stopnia","Walka na Zbieranie - III Stopnia","Walka na Zbieranie - IV Stopnia"},
	{ "","Walka na Spowolnienie - I Stopnia","Walka na Spowolnienie - II Stopnia","Walka na Spowolnienie - III Stopnia","Walka na Spowolnienie - IV Stopnia"},
	{ "","Walka na Podswietlenie - I Stopnia","Walka na Podswietlenie - II Stopnia","Walka na Podswietlenie - III Stopnia","Walka na Podswietlenie - IV Stopnia"},
	{ "","Walka na Zgony - I Stopnia","Walka na Zgony - II Stopnia","Walka na Zgony - III Stopnia","Walka na Zgony - IV Stopnia"},
	{ "","Walka na Polaczenia - I Stopnia","Walka na Polaczenia - II Stopnia","Walka na Polaczenia - III Stopnia","Walka na Polaczenia - IV Stopnia"}
};

//Default weapon speeds
new Float:gCSWeaponSpeed[32] =
{
	0.0,
	250.0,      // CSW_P228
	0.0,
	260.0,      // CSW_SCOUT
	250.0,      // CSW_HEGRENADE
	240.0,      // CSW_XM1014
	200.0,      // CSW_C4
	250.0,      // CSW_MAC10
	240.0,      // CSW_AUG
	250.0,      // CSW_SMOKEGRENADE
	250.0,      // CSW_ELITE
	250.0,      // CSW_FIVESEVEN
	250.0,      // CSW_UMP45
	210.0,      // CSW_SG550
	240.0,      // CSW_GALI
	240.0,      // CSW_FAMAS
	250.0,      // CSW_USP
	250.0,      // CSW_GLOCK18
	210.0,      // CSW_AWP
	250.0,      // CSW_MP5NAVY
	220.0,      // CSW_M249
	230.0,      // CSW_M3
	230.0,      // CSW_M4A1
	250.0,      // CSW_TMP
	210.0,      // CSW_G3SG1
	250.0,      // CSW_FLASHBANG
	250.0,      // CSW_DEAGLE
	235.0,      // CSW_SG552
	221.0,      // CSW_AK47
	250.0,      // CSW_KNIFE
	245.0       // CSW_P90
};
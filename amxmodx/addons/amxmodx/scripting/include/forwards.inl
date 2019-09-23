//Bf4 Rank Mod forwards File
//Contains all the standard forwarded functions

#if defined bf4_forward_included
#endinput
#endif
#define bf4_forward_included

public plugin_precache() {
	new tempSound[64];
	formatex(tempSound, charsmax(tempSound), "sound/%s", gSoundRank);
	if ( !file_exists(tempSound) )
	{
		copy(gSoundRank, charsmax(gSoundRank), "buttons/bell1.wav");
	}
	
	formatex(tempSound, charsmax(tempSound), "sound/%s", gSoundBadge);
	if ( !file_exists(tempSound) )
	{
		copy(gSoundBadge, charsmax(gSoundBadge), "fvox/bell.wav");
	}
	
	precache_sound(gSoundRank);
	precache_sound(gSoundBadge);

	new bool:error = false;
	new spriteFile[26];

	for ( new counter; counter < MAX_RANKS+4; counter++)
	{
		spriteFile[0] = '^0';
		formatex(spriteFile, charsmax(spriteFile), "sprites/bf4rankspr/%d.spr", counter);

		//Done this way so that a message is logged for each missing file
		if ( !file_exists( spriteFile ) )
		{
			log_amx("[ERROR] Brakujacy plik sprite: ^"%s^"", spriteFile);
			error = true;
		}
		else {
			gSprite[counter] = precache_model(spriteFile);
		}
	}
	
	precache_model("models/bf4mod/w_medkit.mdl")
	precache_model("models/bf4mod/mina.mdl")
	precache_model("models/bf4mod/w_ammo.mdl")
	
	sprite_blast_miny = precache_model("sprites/bf4rankspr/dexplo.spr");
	sprite_blast_white = precache_model("sprites/bf4rankspr/white.spr");
	g_healspr = precache_model("sprites/bf4rankspr/g_heal.spr");
	
	if ( error )
	{
		set_fail_state("Brakuje plikow sprite , zaladowanie pluginu niemozliwe! Sprawdz Logi AMXX");
		//set_fail_state("Sprite files are missing, unable to load plugin");
	}
}

public plugin_cfg()
{
	get_configsdir(configsdir, charsmax(configsdir));
	server_cmd("exec %s/bf4mod.cfg", configsdir);
	server_exec();
	
	vault_init();
	
	set_cvar_string("bf4_version", gPluginVersion);
	
	if ( gPlayerName != -1 && get_xvar_num(gPlayerName) )
	{
		log_amx("miscstats.amxx ^"PlayerName^" opcja jest wlaczona, BF4 aim info nie bêdzie pokazywane.");
	}
}

public client_putinserver(id) {
	// Find a czero bot to register Ham_Spawn
	if ( !gCZBotRegisterHam && gPcvarBotQuota && get_pcvar_num(gPcvarBotQuota) > 0 && is_user_bot(id) )
	{
		// Delay for private data to initialize
		set_task(0.1, "RegisterHam_CZBot", id);
	}

	g_imobile[id] = false;
	newplayer[id] = true;
	gStatsLoaded[id] = 0;
	
	OnNVGToggle[id] = false;
	dolspr[id]=false;
	
	odzn_1[id] = true;
	odzn_2[id] = true;
	odzn_3[id] = true;
	odzn_4[id] = true;

	get_save_key(id);
	
	new param[1];
	param[0] = id;
	set_task(1.0,"BigHUD",TASK+id,param,1,"b");

	if (!get_pcvar_num(gPcvarWymus))
	{
		client_cmd(id,"hud_centerid 0");
		client_cmd(id,"cl_shadows 0");
		set_task(20.0, "Announcement", id);
	}
	else
	{
		set_task(20.0, "Announcement", id);
	}
	
}

public client_disconnect(id) {
	onlinemin[id]+=((get_user_time(id))/60);
	
	save_badges(id);
	
	OnNVGToggle[id] = false;

	if ( id == highestrankid )
	{
		set_task(2.0, "ranking_officer_disconnect");
	}
	
	clear_stat_globals(id);
	gStatsLoaded[id] = 0;
	
	new ent	    
	while((ent = fm_find_ent_by_owner(ent, "fake_corpse", id)) != 0)
		fm_remove_entity(ent)
}

public plugin_end() {
	server_save();
}
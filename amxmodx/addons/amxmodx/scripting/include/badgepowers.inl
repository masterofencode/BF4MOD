//Bf4 Rank Mod badge powers File
//Contains all the power giving etc checking functions.

#if defined bf4_powers_included
#endinput
#endif
#define bf4_powers_included

public killedPre(id, kid) {
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !get_pcvar_num(gPcvarPower14) ) return;
	
	new respawnlevel = g_PlayerBadges[id][BADGE_NUMBER14];
	new szansa = get_pcvar_num(gPcvarRespawn)
	
	if ( respawnlevel )
	{
		if ( random_num(1, (szansa-respawnlevel)) == 1 )
		{
			set_task(0.1, "Wskrzes", id);
		}
	}
}

public Wskrzes(id) {
	ExecuteHamB(Ham_CS_RoundRespawn, id);
}

public Samobojca(id){
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return HAM_IGNORED;
	if ( !get_pcvar_num(gPcvarPower16) ) return HAM_IGNORED;
	if ( !is_user_alive(id) || freezetime ) return PLUGIN_CONTINUE;
	
	new entlist[33];
	new odznaka = g_PlayerBadges[id][BADGE_NUMBER16];
	new moc = get_pcvar_num(gPcvarZasieg);
	new obrazenia = get_pcvar_num(gPcvarObrazenia);
	new zasieg = 50+(odznaka*moc);
	
	new numfound = find_sphere_class(id, "player", zasieg*1.0, entlist, 32);
	
	for (new i=0; i < numfound; i++)
	{
		new pid = entlist[i];
	
		if (is_user_alive(pid) && get_user_team(id) != get_user_team(pid))
			fakedamage(pid, "samobojca", obrazenia*1.0, DMG_BLAST);
	}
	
	new Float:fOrigin[3];
	entity_get_vector(id, EV_VEC_origin, fOrigin);
	
	new iOrigin[3];
	for(new i=0;i<3;i++)
		iOrigin[i] = floatround(fOrigin[i]);
	
	message_begin(MSG_BROADCAST,SVC_TEMPENTITY, iOrigin);
	write_byte(TE_EXPLOSION);
	write_coord(iOrigin[0]);
	write_coord(iOrigin[1]);
	write_coord(iOrigin[2]);
	write_short(sprite_blast_miny);
	write_byte(32); 
	write_byte(20); 
	write_byte(0);
	message_end();
		
	message_begin( MSG_BROADCAST, SVC_TEMPENTITY, iOrigin );
	write_byte( TE_BEAMCYLINDER );
	write_coord( iOrigin[0] );
	write_coord( iOrigin[1] );
	write_coord( iOrigin[2] );
	write_coord( iOrigin[0] );
	write_coord( iOrigin[1] + 50 );
	write_coord( iOrigin[2] + 50 );
	write_short( sprite_blast_white );
	write_byte( 0 ); 
	write_byte( 0 ); 
	write_byte( 10 ); 
	write_byte( 10 ); 
	write_byte( 255 ); 
	write_byte( 255 ); 
	write_byte( 100 );
	write_byte( 100 ); 
	write_byte( 128 ); 
	write_byte( 0 ); 
	message_end();
	
	user_silentkill(id);
	
	return HAM_IGNORED;
}

public TakeDamage(id, inflictor, attacker, Float:damage, dmgbits)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return HAM_IGNORED;
	if ( !get_pcvar_num(gPcvarPower13) ) return HAM_IGNORED;
	
	switch(g_PlayerBadges[id][BADGE_NUMBER13]){
		case 1:
		{
			if(dmgbits & (1<<1))
			{
				SetHamParamFloat(4, floatmax(0.0, damage*get_pcvar_float(gPcvarOtrzymane1)));
				return HAM_HANDLED;
			}
		}
		case 2:
		{
			if(dmgbits & (1<<1))
			{
				SetHamParamFloat(4, floatmax(0.0, damage*get_pcvar_float(gPcvarOtrzymane2)));
				return HAM_HANDLED;
			}
		}
		case 3:
		{
			if(dmgbits & (1<<1))
			{
				SetHamParamFloat(4, floatmax(0.0, damage*get_pcvar_float(gPcvarOtrzymane3)));
				return HAM_HANDLED;
			}
		}
		case 4:
		{
			if(dmgbits & (1<<1))
			{
				SetHamParamFloat(4, floatmax(0.0, damage*get_pcvar_float(gPcvarOtrzymane4)));
				return HAM_HANDLED;
			}
		}
	}
	return HAM_IGNORED;
}

public give_ciche(id){
	if ( !get_pcvar_num(gPcvarPower18) ) return;
	
	new dodatkilevel = g_PlayerBadges[id][BADGE_NUMBER18];
	
	if ( dodatkilevel && get_user_weapon(id) == CSW_KNIFE && odzn_4[id] ) {
		switch(dodatkilevel)
		{
			case 3: set_user_footsteps(id,1);
			case 4: set_user_footsteps(id,1);
		}
	} else if ( dodatkilevel && get_user_weapon(id) != CSW_KNIFE ) {
		switch(dodatkilevel)
		{
			case 3: set_user_footsteps(id,0);
			case 4: set_user_footsteps(id,0);
		}
	}
}

public give_money(id){
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !is_user_alive(id) || freezetime ) return;
	if ( !get_pcvar_num(gPcvarPower2) ) return;
	
	new kasa = cs_get_user_money(id);
	new dodatkowa = g_PlayerBadges[id][BADGE_NUMBER2]*get_pcvar_num(gPcvarKasa);
	
	switch(g_PlayerBadges[id][BADGE_NUMBER2]) {
		case 1: cs_set_user_money(id, kasa + dodatkowa, 1)
		case 2: cs_set_user_money(id, kasa + dodatkowa, 1)
		case 3: cs_set_user_money(id, kasa + dodatkowa, 1)
		case 4: cs_set_user_money(id, kasa + dodatkowa, 1)
	}
}

public set_speed(id)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !is_user_alive(id) || freezetime ) return;
	
	new Float:speed;
	
	if ( g_imobile[id] )
	{
		speed = 100.0;
	}
	else
	{
		if ( cs_get_user_vip(id) )
		{
			//VIPs only have 1 speed no matter the weapon
			speed = 227.0;
		}
		else
		{
			new weapon = get_user_weapon(id);
			
			speed = gCSWeaponSpeed[weapon];
			
			if ( gCurrentFOV[id] <= 45 )
			{
				switch(weapon)
				{
					case CSW_SCOUT: speed = 220.0;
					case CSW_SG550, CSW_AWP, CSW_G3SG1: speed = 150.0;
				}
			}
		}
		
		if ( get_pcvar_num(gPcvarPower8) ) {
			new smglevel = g_PlayerBadges[id][BADGE_NUMBER8];
			new szybkosc = get_pcvar_num(gPcvarSpeed);
			
			if ( smglevel )
			{
				//15 units faster per level.
				speed += (smglevel * szybkosc);
			}
		}
	}
	
	if ( speed != get_user_maxspeed(id) )
	{
		set_user_maxspeed(id, speed);
	}
}

public set_invis(id)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !is_user_alive(id) ) return;
	if ( !get_pcvar_num(gPcvarPower7) ) return;
	
	new shotgunlevel = g_PlayerBadges[id][BADGE_NUMBER7];
	
	new invislvl1 = get_pcvar_num(gPcvarInvisible1);
	new invislvl2 = get_pcvar_num(gPcvarInvisible2);
	new invislvl3 = get_pcvar_num(gPcvarInvisible3);
	new invislvl4 = get_pcvar_num(gPcvarInvisible4);
	
	if ( shotgunlevel && get_user_weapon(id) == CSW_KNIFE )
	{
		switch(shotgunlevel)
		{
			case 1: fm_set_rendering(id, kRenderFxNone, 0, 0, 0, kRenderTransTexture, invislvl1);
			case 2: fm_set_rendering(id, kRenderFxNone, 0, 0, 0, kRenderTransTexture, invislvl2);
			case 3: fm_set_rendering(id, kRenderFxNone, 0, 0, 0, kRenderTransTexture, invislvl3);
			case 4: fm_set_rendering(id, kRenderFxNone, 0, 0, 0, kRenderTransTexture, invislvl4);
		}
		
		g_invis[id] = true;
	}
	else
	{
		fm_set_rendering(id);
		g_invis[id] = false;
	}
}

//Grawitacja start
public set_grav(id)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !is_user_alive(id) ) return;
	if ( !get_pcvar_num(gPcvarPower9) ) return;
	
	new gravlevel = g_PlayerBadges[id][BADGE_NUMBER9];

	if ( gravlevel && get_user_weapon(id) == CSW_KNIFE ) {
		new Float:grav
		switch(gravlevel)
		{
			case 1: grav = get_pcvar_float(gPcvarGravitka1);
			case 2: grav = get_pcvar_float(gPcvarGravitka2);
			case 3: grav = get_pcvar_float(gPcvarGravitka3);
			case 4: grav = get_pcvar_float(gPcvarGravitka4);
		}
		fm_set_user_gravity(id, grav)
		g_invis[id] = true;
	}
	else {
		fm_set_user_gravity(id, 1.0)
		g_invis[id] = false;
	}
}
// Grawitacja end

public remove_imobile(id)
{
	g_imobile[id] = false;
	
	set_speed(id);
}


//Podskok Start
public CmdStartPreSkok(id, uc_handle){
	if ( !get_pcvar_num(gPcvarPower18) ) return;

	new flags = pev(id, pev_flags);
	if((get_uc(uc_handle, UC_Buttons) & IN_JUMP) && !(flags & FL_ONGROUND) && !(pev(id, pev_oldbuttons) & IN_JUMP) && skoki[id]>0 && (g_PlayerBadges[id][BADGE_NUMBER18] == LEVEL_IVSTOPNIA) && get_user_weapon(id) == CSW_KNIFE && odzn_4[id]){
		--skoki[id];
		new Float:velocity[3];
		pev(id, pev_velocity,velocity);
		velocity[2] = random_float(265.0,285.0);
		set_pev(id,pev_velocity,velocity);
	} else if(flags & FL_ONGROUND && skoki[id]!=-1){
		skoki[id] = 1;
	}
}

public SpawnedEventPreSkokAdd(id){
	skoki[id]=1;
}
//Podskok End

//Odbicie pocisku
public fw_traceline(Float:vecStart[3],Float:vecEnd[3],ignoreM,id,trace) {
	if(!is_user_connected(id))
		return FMRES_IGNORED;

	if(!is_user_alive(id))
		return FMRES_IGNORED;

	new hit = get_tr2(trace, TR_pHit)    

	if(!(pev(id,pev_button) & IN_ATTACK))
		return FMRES_IGNORED;
		

	if(is_user_alive(hit)) {
		if(cs_get_user_team(id) != cs_get_user_team(hit)) {
			new hitzone = get_tr2(trace, TR_iHitgroup);
			
			if ((ultra_armor[hit]>0) && (hitzone == HIT_HEAD)) {
				ultra_armor[hit]--
				set_tr2(trace, TR_iHitgroup, 8)
			}
			return FMRES_IGNORED
		}
	}
    
	return FMRES_IGNORED;
}

public give_ubranie(id) {
	if(!is_user_connected(id))
		return;

	if(!is_user_alive(id))
		return;
	
	if ( get_pcvar_num(gPcvarPower25) ) {
		new enemylevel = g_PlayerBadges[id][BADGE_NUMBER25];
		new clothesenemy = get_pcvar_num(gPcvarSzansaUbranie);
		
		if ( enemylevel ) {		
			if ( random_num(1, (clothesenemy-enemylevel)) == 1 ) {
				new num = random_num(0,3);
				
				switch(get_user_team(id)) {
					case CS_TEAM_T: cs_set_user_model(id,Ubrania_CT[num]);
					case CS_TEAM_CT: cs_set_user_model(id,Ubrania_Terro[num]);
				}
				
				ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Otrzymales^x04 ubranie wroga^x01.");
			}
		}
	}
}

public give_userweapon(id)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !is_user_alive(id) ) return;
	
	new bool:givenitem = false;

	if ( get_pcvar_num(gPcvarPower18) ) {
		new dodatkilevel = g_PlayerBadges[id][BADGE_NUMBER18];
		if ( dodatkilevel == LEVEL_ISTOPNIA && odzn_4[id] )
		{	
			if(get_user_team(id)==2){
				give_item(id, "item_thighpack");
			}
			cs_set_user_nvg(id);
			
			givenitem = true;
		}
		else if ( dodatkilevel == LEVEL_IISTOPNIA && odzn_4[id] )
		{	
			if(get_user_team(id)==2){
				give_item(id, "item_thighpack");
			}
			cs_set_user_nvg(id);
			
			fm_give_item(id, "weapon_flashbang");
			fm_give_item(id, "weapon_flashbang");
			
			givenitem = true;
		}
		else if ( dodatkilevel > LEVEL_IISTOPNIA && odzn_4[id] )
		{	
			if(get_user_team(id)==2){
				give_item(id, "item_thighpack");
			}
			cs_set_user_nvg(id);
			
			fm_give_item(id, "weapon_flashbang");
			fm_give_item(id, "weapon_flashbang");
			
			givenitem = true;
		}
	}
	
	if ( get_pcvar_num(gPcvarPower3) ) {
		new assaultlevel = g_PlayerBadges[id][BADGE_NUMBER3];
		new assaulthp = get_pcvar_num(gPcvarHP);
		
		if ( assaultlevel )
		{
			new hp;
			hp = get_user_health(id) + (assaultlevel*assaulthp);
			
			if ( get_user_health(id) < hp )
			{
				set_user_health(id, hp);
				
				if ( pev(id, pev_max_health) < float(hp) ) {
					set_pev(id, pev_max_health, float(hp));
				}
					
				givenitem = true;
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower4) ) {
		new sniperlevel = g_PlayerBadges[id][BADGE_NUMBER4];
		new szansasniper = get_pcvar_num(gPcvarSzansaAWP);
		
		if ( sniperlevel && odzn_1[id] )
		{
			if ( cs_get_user_shield(id) == 1 ) return;
		
			if ( random_num(1, (szansasniper-sniperlevel)) == 1 )
			{
				new weaponName[32];
				new weaponID = get_user_weapon(id);
				
				if ( !get_pcvar_num(gPcvarFreeAwp) )
				{
					fm_give_item(id, "weapon_scout");
				}
				else
				{
					fm_give_item(id, "weapon_awp");
				}
				
				if ( weaponID )
				{
					get_weaponname(weaponID, weaponName, charsmax(weaponName));
					engclient_cmd(id, weaponName);
				}
				
				givenitem = true;
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower6) ) {
		new explosionlevel = g_PlayerBadges[id][BADGE_NUMBER6];
		new szansahe = get_pcvar_num(gPcvarSzansaHE);
		
		if ( explosionlevel )
		{
			if ( random_num(1, (szansahe-explosionlevel)) == 1 )
			{
				fm_give_item(id, "weapon_hegrenade");
				givenitem = true;
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower10) ) {
		if ( cs_get_user_shield(id) == 1 ) return;
		
		new mp5level = g_PlayerBadges[id][BADGE_NUMBER10];
		new szansamp5 = get_pcvar_num(gPcvarSzansaMP5);
		
		if ( mp5level && odzn_2[id] )
		{
			if ( random_num(1, (szansamp5-mp5level)) == 1 )
			{
				fm_give_item(id, "weapon_mp5navy");
				fm_give_item(id, "ammo_9mm");
				fm_give_item(id, "ammo_9mm");
				fm_give_item(id, "ammo_9mm");
				fm_give_item(id, "ammo_9mm");
				givenitem = true;
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower15) ) {
		new deaglelevel = g_PlayerBadges[id][BADGE_NUMBER15];
		new szansadeagle = get_pcvar_num(gPcvarSzansaDeagle);
		
		if ( deaglelevel && odzn_3[id] )
		{
			if ( random_num(1, (szansadeagle-deaglelevel)) == 1 )
			{
				fm_give_item(id, "weapon_deagle");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				fm_give_item(id, "ammo_50ae");
				givenitem = true;
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower24) ) {
		new helmetlevel = g_PlayerBadges[id][BADGE_NUMBER24];
		new szansahelmet = get_pcvar_num(gPcvarSzansaHelm);
		
		if ( helmetlevel )
		{
			if ( cs_get_user_shield(id) == 1 ) return;
		
			if ( random_num(1, (szansahelmet-helmetlevel)) == 1 )
			{
				ultra_armor[id] = 1;
				ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Otrzymales^x04 helm z kewlaru^x01 (zatrzyma 1 pocisk).");
				
				givenitem = true;
			}
		}
	}
	
	new CsArmorType:ArmorType;
	
	new Armor1 = get_pcvar_num(gPcvarArmor1);
	new Armor2 = get_pcvar_num(gPcvarArmor2);
	new Armor3 = get_pcvar_num(gPcvarArmor3);
	new Armor4 = get_pcvar_num(gPcvarArmor4);
	new Armor5 = get_pcvar_num(gPcvarArmor5);
	
	switch (numofbadges[id])
	{
		case 11 .. 25:
		{
			if ( cs_get_user_armor(id, ArmorType) < Armor1 )
			{
				cs_set_user_armor(id, Armor1, CS_ARMOR_VESTHELM);
				givenitem = true;
			}
		}
		
		case 26 .. 45:
		{
			if ( cs_get_user_armor(id, ArmorType) < Armor2 )
			{
				cs_set_user_armor(id, Armor2, CS_ARMOR_VESTHELM);
				givenitem = true;
			}
		}
		
		case 46 .. 60:
		{
			if ( cs_get_user_armor(id, ArmorType) < Armor3 )
			{
				cs_set_user_armor(id, Armor3, CS_ARMOR_VESTHELM);
				givenitem = true;
			}
		}
		
		case 61 .. 75:
		{
			if ( cs_get_user_armor(id, ArmorType) < Armor4 )
			{
				cs_set_user_armor(id, Armor4, CS_ARMOR_VESTHELM);
				givenitem = true;
			}
		}
		
		case 76 .. 100:
		{
			if ( cs_get_user_armor(id, ArmorType) < Armor5 )
			{
				cs_set_user_armor(id, Armor5, CS_ARMOR_VESTHELM);
				givenitem = true;
			}
		}
	}
	
	if ( givenitem )
		screen_flash(id, 0, 255, 0, 100); //Green screen flash
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/

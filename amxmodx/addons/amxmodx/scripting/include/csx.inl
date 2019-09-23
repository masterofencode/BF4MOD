//Bf4 Rank Mod CSX forwards File
//Contains all the CSX forwarded functions

#if defined bf4_csx_forward_included
#endinput
#endif
#define bf4_csx_forward_included

public client_death(killer, victim, wpnindex, hitplace, TK)
{
	if ( !get_pcvar_num(gPcvarBF4Active) ) return;
	
	if ( killer == victim )
	{
		check_badges(victim);
		check_reach(victim);
		return;
	}
	
	//if ( is_user_bot(victim) && !get_pcvar_num(gPcvarRankBots) ) return;
	
	if ( TK && !get_pcvar_num(gPcvarFFA) ) return;
	if ( killer < 1 || killer > gMaxPlayers ) return;
	
	switch ( wpnindex )
	{
		case CSW_KNIFE:{
			knifekills[killer]++
		}
		case CSW_M249:{ 
			parakills[killer]++
		}
		case CSW_HEGRENADE:{
			grenadekills[killer]++
		}
		case CSW_USP:{
			uspkills[killer]++
			pistolkills[killer]++
		}
		case CSW_GLOCK18:{
			glockkills[killer]++
			pistolkills[killer]++
		}
		case CSW_DEAGLE:{
			deaglekills[killer]++
			pistolkills[killer]++
		}
		case CSW_P228:{
			p228kills[killer]++
			pistolkills[killer]++
		}
		case CSW_FIVESEVEN:{
			fivesevenkills[killer]++
			pistolkills[killer]++
		}
		case CSW_ELITE:{
			elitekills[killer]++
			pistolkills[killer]++
		}
		case CSW_TMP:{
			tmpkills[killer]++
			smgkills[killer]++
		}
		case CSW_MAC10:{
			mackills[killer]++
			smgkills[killer]++
		}
		case CSW_MP5NAVY:{
			mp5kills[killer]++
			smgkills[killer]++
		}
		case CSW_P90:{
			p90kills[killer]++
			smgkills[killer]++
		}
		case CSW_UMP45:{
			umpkills[killer]++
			smgkills[killer]++
		}
		case CSW_AWP:{
			awpkills[killer]++
			sniperkills[killer]++
		}
		case CSW_SCOUT:{
			scoutkills[killer]++
			sniperkills[killer]++
		}
		case CSW_G3SG1:{
			g3sg1kills[killer]++
			sniperkills[killer]++
		}
		case CSW_SG550:{
			sg550kills[killer]++
			sniperkills[killer]++
		}
		case CSW_AUG:{
			augkills[killer]++
			riflekills[killer]++
		}
		case CSW_GALIL:{
			gallkills[killer]++
			riflekills[killer]++
		}
		case CSW_FAMAS:{
			famaskills[killer]++
			riflekills[killer]++
		}
		case CSW_M4A1:{
			m4a1kills[killer]++
			riflekills[killer]++
		}
		case CSW_SG552:{
			sg552kills[killer]++
			riflekills[killer]++
		}
		case CSW_AK47:{
			ak47kills[killer]++
			riflekills[killer]++
		}
		case CSW_XM1014:{
			xm1014kills[killer]++
			shotgunkills[killer]++
		}
		case CSW_M3:{
			m3kills[killer]++
			shotgunkills[killer]++
		}
	}
	
	collectedcash[killer]+=200;
	
	totalkills[killer]++;
	totaldeath[victim]++;
	
	check_badges(victim);
	check_reach(victim);
	
	new samobojcalevel = g_PlayerBadges[victim][BADGE_NUMBER16];
	if ( samobojcalevel )
	{
		Samobojca(victim);
	}
	
	new respawnlevel = g_PlayerBadges[killer][BADGE_NUMBER19];
	new szansa = get_pcvar_num(gPcvarPaczka)
	
	if ( respawnlevel )
	{
		if ( random_num(1, (szansa-respawnlevel)) == 1 )
		{
			set_task(0.1, "Paczka", victim);
		}
	}
	
	if ( mostkillsid == killer )
	{
		mostkills++;
	}
	else if ( totalkills[killer] > mostkills )
	{
		mostkills = totalkills[killer];
		mostkillsid = killer;
		
		new line[100], name[32];
		get_user_name(killer, name, charsmax(name));
		line[0] = 0x04;
		
		ColorChat(0,GREEN,"[BF4:MOD]^x01 Gratulacje dla^x04 %s^x01 nowego Lidera we fragach z^x04 %i^x01 zabiciami", name, mostkills);
	}
	
	DisplayHUD(killer);
}

public client_damage(attacker, victim, damage, wpnindex, hitplace, TA) {
	if ( !get_pcvar_num(gPcvarBF4Active) || !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) )
		return;
	
	dmgrec[attacker] += damage;
	dmgask[victim] += damage;
	shotsrec[attacker]++;
	
	// Check in case of suicide, pistol code may run on self
	if ( attacker == victim )
		return;
	
	if ( TA && !get_pcvar_num(gPcvarFFA)  )	//add check for free for all later
		return;
	
	if ( !is_user_alive(attacker) )
		return;
	
	if ( get_pcvar_num(gPcvarPower22) ) {
		new slowdown = g_PlayerBadges[attacker][BADGE_NUMBER22];
		new szansaslowdown = get_pcvar_num(gPcvarSzansaSlowDown);
		
		if ( ( slowdown > 0 ) && ( wpnindex == CSW_TMP || wpnindex == CSW_MAC10 || wpnindex == CSW_MP5NAVY || wpnindex == CSW_P90 || wpnindex == CSW_UMP45 ) ) {
			if ( random_num(1, (szansaslowdown-slowdown)) == 1 ) {
				g_imobile[victim] = true;
				set_speed(victim);
				screen_flash(victim, 255, 0, 0, 100); //Red screen flash
				
				message_begin(MSG_ONE_UNRELIABLE, gmsgScreenShake, _, victim);
				write_short(10<<12);
				write_short(2<<12);
				write_short(5<<12);
				message_end();
				
				set_task(0.5, "remove_imobile", victim);
			}
		}
	}

	if ( get_pcvar_num(gPcvarPower23) ) {
		new backlight = g_PlayerBadges[attacker][BADGE_NUMBER4];
		new szansalight = get_pcvar_num(gPcvarSzansaLight);
		new shotgunlevel = g_PlayerBadges[victim][BADGE_NUMBER7];
		
		if ( ( backlight > 0 ) && ( wpnindex == CSW_XM1014 || wpnindex == CSW_M3 ) ) {
			if ( shotgunlevel > 0 && get_user_weapon(victim) == CSW_KNIFE ) {
				if ( random_num(1, (szansalight-backlight)) == 1 ) {
					screen_flash(victim, 255, 200, 0, 100); //Red screen flash
					player_glow(victim, 255, 200, 0); //Make the player glow red too
					
					message_begin(MSG_ONE_UNRELIABLE, gmsgScreenShake, _, victim);
					write_short(10<<12);
					write_short(2<<12);
					write_short(5<<12);
					message_end();
				}
			}
		}
	}
	
	if ( get_pcvar_num(gPcvarPower1) ) {
		if ( wpnindex == CSW_KNIFE )
		{
			new attackerknifelevel = g_PlayerBadges[attacker][BADGE_NUMBER1];
			
			if ( attackerknifelevel == 0 )
				return;
			
			// Health to add is dependent on assault badge
			new hp = get_user_health(attacker);
			new assaulthp = get_pcvar_num(gPcvarHP);
			new maxHP = 100 + g_PlayerBadges[attacker][BADGE_NUMBER3]*assaulthp;
			
			if ( hp >= maxHP )
				return;
			
			hp += floatround(damage*(attackerknifelevel/get_pcvar_float(gPcvarKnife)));
			
			set_user_health(attacker, min(hp, maxHP));
			
			screen_flash(attacker, 0, 0, 255, 100); //Blue screen flash
			player_glow(attacker, 0, 0, 255); //Blue model flash
		}
	}
}

public bomb_planted(planter)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;
	
	plants[planter]++;
	
	DisplayHUD(planter);
}

public bomb_explode(planter, defuser)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;
	
	explosions[planter]++;
	totalkills[planter] += 3;
	
	DisplayHUD(planter);
	ColorChat(planter,GREEN,"[BF4:MOD]^x01 Dostales^x04 3^x01 Punkty za zniszczenie celu");
}

public bomb_defused(defuser)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;
	
	defuses[defuser]++;
	totalkills[defuser] += 3;
	
	DisplayHUD(defuser);
	ColorChat(defuser,GREEN,"[BF4:MOD]^x01 Dostales^x04 3^x01 Punkty za rozbrojenie bomby");
}

/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/

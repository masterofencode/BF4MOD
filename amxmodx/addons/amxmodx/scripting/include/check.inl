//Bf4 Rank Mod check File
//Contains all the badge/rank etc checking functions.

#if defined bf4_check_included
#endinput
#endif
#define bf4_check_included

public check_level(id)
{
	if ( gStatsLoaded[id] < 2 ) return;
	
	new stats[8], bodyhits[8], prevrank;
	new ranked = get_user_stats(id, stats, bodyhits);
	
	prevrank = g_PlayerRank[id];
	new newrank, counter;
	
	for (counter = 0; counter < MAX_RANKS; counter++)
	{
		if ( totalkills[id] >= floatround(gRankXP[counter]*get_pcvar_float(gPcvarXpMultiplier)) )
		{
			newrank = counter;
		}
		else break;
	}
	
	g_PlayerRank[id] = newrank;
	
	numofbadges[id] = 0;
	for (counter = 0; counter < MAX_BADGES; counter++)
	{
		numofbadges[id] += g_PlayerBadges[id][counter];
	}
	
	//These ranks depend on badges, what if badges are turned off? what should we do?
	switch(newrank)
	{
		case 7:
			if ( numofbadges[id] >= MAX_BADGES )
				g_PlayerRank[id] = 17;
		case 8:
			if ( numofbadges[id] >= (MAX_BADGES*2) )
				g_PlayerRank[id] = 18;
		case 15:
			if ( numofbadges[id] == (MAX_BADGES*3) )
				g_PlayerRank[id] = 19;
		case 16:
		//If active, Lieutenant General and General require all badges
		if ( get_pcvar_num(gPcvarBadgesActive) && numofbadges[id] != (MAX_BADGES*4) )
			g_PlayerRank[id] = 15; //If badges active and they don't have all badges demote back to Brigadier General
		else if ( ranked == 2 )
			g_PlayerRank[id] = 20; //Promote to General if Number 2 ranked.
		else if ( ranked == 1 )
			g_PlayerRank[id] = 21; //Promote to Marszalek Polski if Number 1 ranked.
	}
	
	if ( newplayer[id] )
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x03 Twoja ranga:^x04 %s^x03 zostala zaladowana",gRankName[g_PlayerRank[id]]);
		client_cmd(id, "spk %s", gSoundRank);
		ranking_officer_check(id);
		newplayer[id] = false;
	}
	else if ( is_ranked_higher(g_PlayerRank[id], prevrank) )
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x03 Awanasowales do rangi^x04 %s", gRankName[g_PlayerRank[id]]);
		client_cmd(id, "spk %s", gSoundRank);
		ranking_officer_check(id);
	}
	else if ( g_PlayerRank[id] != prevrank && !is_ranked_higher(g_PlayerRank[id], prevrank) )
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x03 Zostales zdegradowany do rangi^x04 %s", gRankName[g_PlayerRank[id]]);
	}
	
	if ( is_ranked_higher(g_PlayerRank[id], highestrankserver) )
	{
		highestrankserver = g_PlayerRank[id];
		new line[100], name[32];
		get_user_name(id, name, charsmax(name));
		line[0] = 0x04;

		ColorChat(id,GREEN,"[BF4:MOD]^x03 %s^x01 ma najwyzsza range na serwerze. Jego ranga to^x04 %s.", name, gRankName[highestrankserver]);
	}
}

public badge_check_loop()
{
	//This gets run at round end, only check alive players since
	//check_badges is run on death.
	new players[32], num;
	get_players(players, num, "ah");
	
	for ( new counter = 0; counter < num; counter++)
	{
		check_badges(players[counter]);
	}
}

public check_badges(id)
{
	if ( !get_pcvar_num(gPcvarBF4Active) || !get_pcvar_num(gPcvarBadgesActive) ) return;
	
	new bool:badgegained;
	new weaponkillsround;
	new weaponhsround;
	new wroundstats[8], wroundbodyhits[8], wstats[8], wbodyhits[8];
	new currentbadge;
	new kills;
	
	new roundkills[8];
	
	wroundstats[0] = 0;
	wroundstats[2] = 0;
	get_user_rstats(id, roundkills, wroundbodyhits);
	
	//only check for new badges if the user got a kill. Will save lots of wasted processing time.
	//Exception is explosives badge. May have been earned without kill. Ah well they can wait till they next get a kill
	if ( roundkills[0] )
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x03 Sprawdzanie zdobytych odznak...");
		
		//knife badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER1];
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_KNIFE,wroundstats,wroundbodyhits);
		
		kills=knifekills[id];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				
				if ((wroundstats[0]>0) && (kills>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER1]=LEVEL_ISTOPNIA; //Basic Knife Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER1][LEVEL_ISTOPNIA]);

					//1][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((wroundstats[0]>1) && (kills>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER1]=LEVEL_IISTOPNIA; //Veteran Knife Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER1][LEVEL_IISTOPNIA]);

					//1][LEVEL_IISTOPNIA]);
				
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((wroundstats[0]>2) && (kills>149))
				{
					g_PlayerBadges[id][BADGE_NUMBER1]=LEVEL_IIISTOPNIA; //Expert Knife Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER1][LEVEL_IIISTOPNIA]);

					//1][LEVEL_IIISTOPNIA]);
	
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((wroundstats[0]>2) && (kills>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER1]=LEVEL_IVSTOPNIA; //Expert Knife Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER1][LEVEL_IVSTOPNIA]);

					//1][LEVEL_IVSTOPNIA]);
	
					badgegained=true;
				}
			}
		}
		//End knife section
		
		//Pistol badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER2];
		
		weaponkillsround=0;
		weaponhsround=0;
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_DEAGLE,wroundstats,wroundbodyhits);
		weaponkillsround=wroundstats[0];
		weaponhsround=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_ELITE,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_P228,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_FIVESEVEN,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_USP,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_GLOCK18,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		kills=pistolkills[id];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				
				if ((weaponkillsround>1) && (kills>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER2]=LEVEL_ISTOPNIA; //Basic Pistol Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER2][LEVEL_ISTOPNIA]);

					//2][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((weaponkillsround>2) && (kills>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER2]=LEVEL_IISTOPNIA; //Veteran Pistol Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER2][LEVEL_IISTOPNIA]);

					//2][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((weaponkillsround>3) && (kills>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER2]=LEVEL_IIISTOPNIA; //Expert Pistol Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER2][LEVEL_IIISTOPNIA]);

					//2][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((weaponkillsround>3) && (kills>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER2]=LEVEL_IVSTOPNIA; //Expert Pistol Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER2][LEVEL_IVSTOPNIA]);

					//2][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Pistol section
		
		
		//Assault badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER3];
		wroundstats[0]=0;
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((roundkills[0]>2) && (totalkills[id]>999))
				{
					g_PlayerBadges[id][BADGE_NUMBER3]=LEVEL_ISTOPNIA; //Basic Assault Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER3][LEVEL_ISTOPNIA]);

					//3][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((roundkills[0]>3) && (totalkills[id]>1999))
				{
					g_PlayerBadges[id][BADGE_NUMBER3]=LEVEL_IISTOPNIA; //Veteran Assault Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER3][LEVEL_IISTOPNIA]);

					//3][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((roundkills[0]>4) && (totalkills[id]>2999))
				{
					g_PlayerBadges[id][BADGE_NUMBER3]=LEVEL_IIISTOPNIA; //Expert Assault Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER3][LEVEL_IIISTOPNIA]);

					//3][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((roundkills[0]>4) && (totalkills[id]>4999))
				{
					g_PlayerBadges[id][BADGE_NUMBER3]=LEVEL_IVSTOPNIA; //Expert Assault Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER3][LEVEL_IVSTOPNIA]);

					//3][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Assault section
		
		
		//Sniper badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER4];
		
		weaponkillsround=0;
		weaponhsround=0;
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_AWP,wroundstats,wroundbodyhits);
		weaponkillsround=wroundstats[0];
		weaponhsround=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_SCOUT,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_G3SG1,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_SG550,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((weaponkillsround>1) && (sniperkills[id]>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER4]=LEVEL_ISTOPNIA; //Basic Sniper Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER4][LEVEL_ISTOPNIA]);

					//4][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((weaponkillsround>2) && (sniperkills[id]>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER4]=LEVEL_IISTOPNIA; //Veteran Sniper Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER4][LEVEL_IISTOPNIA]);

					//4][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((weaponkillsround>3) && (sniperkills[id]>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER4]=LEVEL_IIISTOPNIA; //Expert Sniper Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER4][LEVEL_IIISTOPNIA]);

					//4][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((weaponkillsround>3) && (sniperkills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER4]=LEVEL_IVSTOPNIA; //Expert Sniper Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER4][LEVEL_IVSTOPNIA]);

					//4][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Sniper section
		
		//Support badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER5];
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_M249,wroundstats,wroundbodyhits);
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((wroundstats[0]>1) && (parakills[id]>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER5]=LEVEL_ISTOPNIA; //Basic Support Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER5][LEVEL_ISTOPNIA]);

					//5][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((wroundstats[0]>2) && (parakills[id]>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER5]=LEVEL_IISTOPNIA; //Veteran Support Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER5][LEVEL_IISTOPNIA]);

					//5][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((wroundstats[0]>3) && (parakills[id]>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER5]=LEVEL_IIISTOPNIA; //Expert Support Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER5][LEVEL_IIISTOPNIA]);

					//5][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((wroundstats[0]>3) && (parakills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER5]=LEVEL_IVSTOPNIA; //Expert Support Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER5][LEVEL_IVSTOPNIA]);

					//5][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End support section
		
		//Explosives badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER6];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (grenadekills[id]>49)
				{
					g_PlayerBadges[id][BADGE_NUMBER6]=LEVEL_ISTOPNIA; //Basic Explosives Badge
					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER6][LEVEL_ISTOPNIA]);

					//6][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (grenadekills[id]>99)
				{
					g_PlayerBadges[id][BADGE_NUMBER6]=LEVEL_IISTOPNIA; //Veteran Explosives Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER6][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (grenadekills[id]>149)
				{
					g_PlayerBadges[id][BADGE_NUMBER6]=LEVEL_IIISTOPNIA; //Expert Explosives Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER6][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (grenadekills[id]>199)
				{
					g_PlayerBadges[id][BADGE_NUMBER6]=LEVEL_IVSTOPNIA; //Expert Explosives Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER6][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Explosives section
		
		//Shotgun badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER7];	
		
		weaponkillsround=0;
		weaponhsround=0;
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_XM1014,wroundstats,wroundbodyhits);
		weaponkillsround=wroundstats[0];
		weaponhsround=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_M3,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((weaponkillsround>1) && (shotgunkills[id]>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER7]=LEVEL_ISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER7][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((weaponkillsround>2) && (shotgunkills[id]>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER7]=LEVEL_IISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER7][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((weaponkillsround>3) && (shotgunkills[id]>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER7]=LEVEL_IIISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER7][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((weaponkillsround>3) && (shotgunkills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER7]=LEVEL_IVSTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER7][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Shotgun section
		
		
		//SMG badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER8];
		
		weaponkillsround=0;
		weaponhsround=0;
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_MAC10,wroundstats,wroundbodyhits);
		weaponkillsround=wroundstats[0];
		weaponhsround=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_UMP45,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_MP5NAVY,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_TMP,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		wroundstats[0]=0;
		wroundstats[2]=0;
		get_user_wrstats(id,CSW_P90,wroundstats,wroundbodyhits);
		weaponkillsround+=wroundstats[0];
		weaponhsround+=wroundstats[2];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((weaponkillsround>1) && (smgkills[id]>49))
				{
					g_PlayerBadges[id][BADGE_NUMBER8]=LEVEL_ISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER8][LEVEL_ISTOPNIA]);

					//8][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((weaponkillsround>2) && (smgkills[id]>99))
				{
					g_PlayerBadges[id][BADGE_NUMBER8]=LEVEL_IISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER8][LEVEL_IISTOPNIA]);

					//8][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((weaponkillsround>3) && (smgkills[id]>199))
				{
					g_PlayerBadges[id][BADGE_NUMBER8]=LEVEL_IIISTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER8][LEVEL_IIISTOPNIA]);

					//8][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((weaponkillsround>3) && (smgkills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER8]=LEVEL_IVSTOPNIA;

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER8][LEVEL_IVSTOPNIA]);

					//8][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End SMG section
		
		//Celnosciowa badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER9];
		wstats[0]=0;
		wstats[4]=0;
		wstats[5]=0;
		wroundstats[0]=0;
		
		get_user_stats(id,wstats,wbodyhits);
		
		new acc = floatround((float(wstats[5])/float(wstats[4]))*100);
		accuracy[id]=acc;
	
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((totalkills[id]>499) && (acc>23))
				{
					g_PlayerBadges[id][BADGE_NUMBER9]=LEVEL_ISTOPNIA; //Basic Celnosciowa Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER9][LEVEL_ISTOPNIA]);

					//9][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((totalkills[id]>999) && (acc>25))
				{
					g_PlayerBadges[id][BADGE_NUMBER9]=LEVEL_IISTOPNIA; //Veteran Celnosciowa Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER9][LEVEL_IISTOPNIA]);

					//9][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((totalkills[id]>1499) && (acc>27))
				{
					g_PlayerBadges[id][BADGE_NUMBER9]=LEVEL_IIISTOPNIA; //Expert Celnosciowa Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER9][LEVEL_IIISTOPNIA]);

					//9][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((totalkills[id]>1999) && (acc>29))
				{
					g_PlayerBadges[id][BADGE_NUMBER9]=LEVEL_IVSTOPNIA; //Expert Celnosciowa Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER9][LEVEL_IVSTOPNIA]);

					//9][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Celnosciowa section
		
		//Bronmi badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER10];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (totalkills[id]>499)
				{
					g_PlayerBadges[id][BADGE_NUMBER10]=LEVEL_ISTOPNIA; //Basic Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER10][LEVEL_ISTOPNIA]);

					//10][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (totalkills[id]>999)
				{
					g_PlayerBadges[id][BADGE_NUMBER10]=LEVEL_IISTOPNIA; //Veteran Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER10][LEVEL_IISTOPNIA]);

					//10][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (totalkills[id]>1499)
				{
					g_PlayerBadges[id][BADGE_NUMBER10]=LEVEL_IIISTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER10][LEVEL_IIISTOPNIA]);

					//10][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (totalkills[id]>1999)
				{
					g_PlayerBadges[id][BADGE_NUMBER10]=LEVEL_IVSTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER10][LEVEL_IVSTOPNIA]);

					//10][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Bronmi section
		
		//Apteczka badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER11];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (dmgask[id]>49999)
				{
					g_PlayerBadges[id][BADGE_NUMBER11]=LEVEL_ISTOPNIA; //Basic Apteczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER11][LEVEL_ISTOPNIA]);

					//11][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (dmgask[id]>99999)
				{
					g_PlayerBadges[id][BADGE_NUMBER11]=LEVEL_IISTOPNIA; //Veteran Apteczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER11][LEVEL_IISTOPNIA]);

					//11][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (dmgask[id]>149999)
				{
					g_PlayerBadges[id][BADGE_NUMBER11]=LEVEL_IIISTOPNIA; //Expert Apteczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER11][LEVEL_IIISTOPNIA]);

					//11][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (dmgask[id]>199999)
				{
					g_PlayerBadges[id][BADGE_NUMBER11]=LEVEL_IVSTOPNIA; //Expert Apteczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER11][LEVEL_IVSTOPNIA]);

					//11][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Apteczka section
		
		//Bronmi badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER12];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (dmgrec[id]>99999)
				{
					g_PlayerBadges[id][BADGE_NUMBER12]=LEVEL_ISTOPNIA; //Basic Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER12][LEVEL_ISTOPNIA]);

					//12][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (dmgrec[id]>199999)
				{
					g_PlayerBadges[id][BADGE_NUMBER12]=LEVEL_IISTOPNIA; //Veteran Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER12][LEVEL_IISTOPNIA]);

					//12][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (dmgrec[id]>299999)
				{
					g_PlayerBadges[id][BADGE_NUMBER12]=LEVEL_IIISTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER12][LEVEL_IIISTOPNIA]);

					//12][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (dmgrec[id]>499999)
				{
					g_PlayerBadges[id][BADGE_NUMBER12]=LEVEL_IVSTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER12][LEVEL_IVSTOPNIA]);

					//12][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Bronmi section
		
		//Na Medal badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER13];
		
		new medals = (bronze[id]+silver[id]+gold[id]);
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (medals>39)
				{
					g_PlayerBadges[id][BADGE_NUMBER13]=LEVEL_ISTOPNIA; //Basic Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER13][LEVEL_ISTOPNIA]);

					//13][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (medals>79)
				{
					g_PlayerBadges[id][BADGE_NUMBER13]=LEVEL_IISTOPNIA; //Veteran Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER13][LEVEL_IISTOPNIA]);

					//13][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (medals>119)
				{
					g_PlayerBadges[id][BADGE_NUMBER13]=LEVEL_IIISTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER13][LEVEL_IIISTOPNIA]);

					//13][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (medals>159)
				{
					g_PlayerBadges[id][BADGE_NUMBER13]=LEVEL_IVSTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER13][LEVEL_IVSTOPNIA]);

					//13][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Na Medal section
		
		//Staż badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER14];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (onlinemin[id]>7199)
				{
					g_PlayerBadges[id][BADGE_NUMBER14]=LEVEL_ISTOPNIA; //Basic Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER14][LEVEL_ISTOPNIA]);

					//14][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (onlinemin[id]>14399)
				{
					g_PlayerBadges[id][BADGE_NUMBER14]=LEVEL_IISTOPNIA; //Veteran Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER14][LEVEL_IISTOPNIA]);

					//14][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (onlinemin[id]>21599)
				{
					g_PlayerBadges[id][BADGE_NUMBER14]=LEVEL_IIISTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER14][LEVEL_IIISTOPNIA]);

					//14][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (onlinemin[id]>28799)
				{
					g_PlayerBadges[id][BADGE_NUMBER14]=LEVEL_IVSTOPNIA; //Expert Bronmi Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER14][LEVEL_IVSTOPNIA]);

					//14][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Na Staż section
		
		//Na Osiągnięcia badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER15];
		
		new reach = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]);
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (reach>4)
				{
					g_PlayerBadges[id][BADGE_NUMBER15]=LEVEL_ISTOPNIA; //Basic Osiągnięcia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER15][LEVEL_ISTOPNIA]);

					//15][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (reach>9)
				{
					g_PlayerBadges[id][BADGE_NUMBER15]=LEVEL_IISTOPNIA; //Veteran Osiągnięcia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER15][LEVEL_IISTOPNIA]);

					//15][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (reach>14)
				{
					g_PlayerBadges[id][BADGE_NUMBER15]=LEVEL_IIISTOPNIA; //Expert Osiągnięcia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER15][LEVEL_IIISTOPNIA]);

					//15][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (reach>17)
				{
					g_PlayerBadges[id][BADGE_NUMBER15]=LEVEL_IVSTOPNIA; //Expert Osiągnięcia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER15][LEVEL_IVSTOPNIA]);

					//15][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Na Osiągnięcia section
		
		//Na Odznaczenia badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER16];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (numofbadges[id]>14)
				{
					g_PlayerBadges[id][BADGE_NUMBER16]=LEVEL_ISTOPNIA; //Basic Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER16][LEVEL_ISTOPNIA]);

					//16][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (numofbadges[id]>29)
				{
					g_PlayerBadges[id][BADGE_NUMBER16]=LEVEL_IISTOPNIA; //Veteran Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER16][LEVEL_IISTOPNIA]);

					//16][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (numofbadges[id]>44)
				{
					g_PlayerBadges[id][BADGE_NUMBER16]=LEVEL_IIISTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER16][LEVEL_IIISTOPNIA]);

					//16][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (numofbadges[id]>59)
				{
					g_PlayerBadges[id][BADGE_NUMBER16]=LEVEL_IVSTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER16][LEVEL_IVSTOPNIA]);

					//16][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Na Odznaczenia section
		
		//Na Miny badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER17];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (minakills[id]>49)
				{
					g_PlayerBadges[id][BADGE_NUMBER17]=LEVEL_ISTOPNIA; //Basic Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER17][LEVEL_ISTOPNIA]);

					//17][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (minakills[id]>99)
				{
					g_PlayerBadges[id][BADGE_NUMBER17]=LEVEL_IISTOPNIA; //Veteran Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER17][LEVEL_IISTOPNIA]);

					//17][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (minakills[id]>149)
				{
					g_PlayerBadges[id][BADGE_NUMBER17]=LEVEL_IIISTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER17][LEVEL_IIISTOPNIA]);

					//17][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (minakills[id]>199)
				{
					g_PlayerBadges[id][BADGE_NUMBER17]=LEVEL_IVSTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER17][LEVEL_IVSTOPNIA]);

					//17][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Na Miny section
		
		//Uniwersalna badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER18];
		
		new reaches = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]);
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((totalkills[id]>1249) && (numofbadges[id]>14) && (reaches>3))
				{
					g_PlayerBadges[id][BADGE_NUMBER18]=LEVEL_ISTOPNIA; //Basic Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER18][LEVEL_ISTOPNIA]);

					//18][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((totalkills[id]>2499) && (numofbadges[id]>29) && (reaches>7))
				{
					g_PlayerBadges[id][BADGE_NUMBER18]=LEVEL_IISTOPNIA; //Veteran Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER18][LEVEL_IISTOPNIA]);

					//18][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((totalkills[id]>3749) && (numofbadges[id]>44) && (reaches>11))
				{
					g_PlayerBadges[id][BADGE_NUMBER18]=LEVEL_IIISTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER18][LEVEL_IIISTOPNIA]);

					//18][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((totalkills[id]>4999) && (numofbadges[id]>59) && (reaches>15))
				{
					g_PlayerBadges[id][BADGE_NUMBER18]=LEVEL_IVSTOPNIA; //Expert Odznaczenia Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER18][LEVEL_IVSTOPNIA]);

					//18][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Uniwersalna section
		
		//Paczka badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER19];
		
		new kills1=parakills[id];
		new kills2=smgkills[id];
		new kills3=shotgunkills[id];
		new kills4=knifekills[id];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((totalkills[id]>999) && (kills1>0) && (kills2>0) && (kills3>0) && (kills4>0))
				{
					g_PlayerBadges[id][BADGE_NUMBER19]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER19][LEVEL_ISTOPNIA]);

					//19][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((totalkills[id]>1999) && (kills1>0) && (kills2>0) && (kills3>0) && (kills4>0))
				{
					g_PlayerBadges[id][BADGE_NUMBER19]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER19][LEVEL_IISTOPNIA]);

					//19][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((totalkills[id]>2999) && (kills1>0) && (kills2>0) && (kills3>0) && (kills4>0))
				{
					g_PlayerBadges[id][BADGE_NUMBER19]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER19][LEVEL_IIISTOPNIA]);

					//19][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((totalkills[id]>3999) && (kills1>0) && (kills2>0) && (kills3>0) && (kills4>0))
				{
					g_PlayerBadges[id][BADGE_NUMBER19]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER19][LEVEL_IVSTOPNIA]);

					//19][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Paczka section
		
		//Termiwizja badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER20];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((totalkills[id]>2499) && (onlinemin[id]>2499))
				{
					g_PlayerBadges[id][BADGE_NUMBER20]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER20][LEVEL_ISTOPNIA]);

					//20][LEVEL_ISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((totalkills[id]>4999) && (onlinemin[id]>4999))
				{
					g_PlayerBadges[id][BADGE_NUMBER20]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER20][LEVEL_IISTOPNIA]);

					//20][LEVEL_IISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((totalkills[id]>7499) && (onlinemin[id]>7499))
				{
					g_PlayerBadges[id][BADGE_NUMBER20]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER20][LEVEL_IIISTOPNIA]);

					//20][LEVEL_IIISTOPNIA]);

					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((totalkills[id]>9999) && (onlinemin[id]>9999))
				{
					g_PlayerBadges[id][BADGE_NUMBER20]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER20][LEVEL_IVSTOPNIA]);

					//20][LEVEL_IVSTOPNIA]);

					badgegained=true;
				}
			}
		}
		//End Termiwizja section
		
		//Zbieranie badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER21];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((padlino[id]>249))
				{
					g_PlayerBadges[id][BADGE_NUMBER21]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER21][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((padlino[id]>499))
				{
					g_PlayerBadges[id][BADGE_NUMBER21]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER21][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((padlino[id]>749))
				{
					g_PlayerBadges[id][BADGE_NUMBER21]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER21][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((padlino[id]>999))
				{
					g_PlayerBadges[id][BADGE_NUMBER21]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER21][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Zbieranie section
		
		//Spowolnienie badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER22];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if ((g_PlayerBadges[id][7]>=1) && (smgkills[id]>149))
				{
					g_PlayerBadges[id][BADGE_NUMBER22]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER22][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((g_PlayerBadges[id][7]>=2) && (smgkills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER22]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER22][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((g_PlayerBadges[id][7]>=3) && (smgkills[id]>449))
				{
					g_PlayerBadges[id][BADGE_NUMBER22]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER22][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((g_PlayerBadges[id][7]>=4) && (smgkills[id]>599))
				{
					g_PlayerBadges[id][BADGE_NUMBER22]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER22][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Spowolnienie section
		
		//Podswietlenie badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER23];

		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
			if ((g_PlayerBadges[id][6]>=1) && (shotgunkills[id]>149))
				{
					g_PlayerBadges[id][BADGE_NUMBER23]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER23][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if ((g_PlayerBadges[id][6]>=2) && (shotgunkills[id]>299))
				{
					g_PlayerBadges[id][BADGE_NUMBER23]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER23][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if ((g_PlayerBadges[id][6]>=3) && (shotgunkills[id]>449))
				{
					g_PlayerBadges[id][BADGE_NUMBER23]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER23][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if ((g_PlayerBadges[id][6]>=4) && (shotgunkills[id]>599))
				{
					g_PlayerBadges[id][BADGE_NUMBER23]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER23][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Podswietlenie section
		
		//Zgony badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER24];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (totaldeath[id]>249)
				{
					g_PlayerBadges[id][BADGE_NUMBER24]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER24][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (totaldeath[id]>499)
				{
					g_PlayerBadges[id][BADGE_NUMBER24]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER24][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (totaldeath[id]>749)
				{
					g_PlayerBadges[id][BADGE_NUMBER24]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER24][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (totaldeath[id]>999)
				{
					g_PlayerBadges[id][BADGE_NUMBER24]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER24][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Zgony section
		
		//Polaczenia badge section
		currentbadge=g_PlayerBadges[id][BADGE_NUMBER25];
		
		switch (currentbadge)
		{
			case LEVEL_NONE:
			{
				if (connects[id]>74)
				{
					g_PlayerBadges[id][BADGE_NUMBER25]=LEVEL_ISTOPNIA; //Basic Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER25][LEVEL_ISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_ISTOPNIA:
			{
				if (connects[id]>149)
				{
					g_PlayerBadges[id][BADGE_NUMBER25]=LEVEL_IISTOPNIA; //Veteran Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER25][LEVEL_IISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IISTOPNIA:
			{
				if (connects[id]>224)
				{
					g_PlayerBadges[id][BADGE_NUMBER25]=LEVEL_IIISTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER25][LEVEL_IIISTOPNIA]);
					badgegained=true;
				}
			}
			case LEVEL_IIISTOPNIA:
			{
				if (connects[id]>299)
				{
					g_PlayerBadges[id][BADGE_NUMBER25]=LEVEL_IVSTOPNIA; //Expert Paczka Badge

					ColorChat(id,GREEN,"[BF4:MOD]^x03 Zdobyles odznake:^x04 %s",gBadgeName[BADGE_NUMBER25][LEVEL_IVSTOPNIA]);
					badgegained=true;
				}
			}
		}
		//End Polaczenia section
		
		if (badgegained)
		{
			client_cmd(id, "spk %s", gSoundBadge);
			save_badges(id);
		}
	}
}

bool:is_ranked_higher(rank1, rank2)
{
	return (gRankOrder[rank1] > gRankOrder[rank2]) ? true : false;
}

public ranking_officer_check(id)
{
	new idRank = g_PlayerRank[id];

	if ( !is_ranked_higher(idRank, highestrank) ) return;

	highestrank = idRank;
	highestrankid = id;
	new name[32];
	get_user_name(id, name, charsmax(name));
	new line[100];
	line[0] = 0x04;
}

public ranking_officer_disconnect()
{
	new players[32], num, player;
	get_players(players, num, "h");

	highestrank = 0;
	highestrankid = 0;

	for (new i = 0; i < num; i++)
	{
		player = players[i];
		if ( is_ranked_higher(g_PlayerRank[player], highestrank) )
		{
			highestrank = g_PlayerRank[player];
			highestrankid = player;
		}
	}

	if ( !highestrank )
	return;
	
	new name[32];
	get_user_name(highestrankid, name, charsmax(name));
	new line[100];
	line[0] = 0x04;
}

public award_check()
{
	new players[32], num;
	get_players(players, num, "h");
	
	new tempfrags, id;
	
	new swapfrags, swapid;
	
	new starfrags[3]; //0 - Bronze / 1 - Silver / 2 - Gold
	new starid[3];
	
	for (new i = 0; i < num; i++)
	{
		id = players[i];
		tempfrags = get_user_frags(id);
		if ( tempfrags > starfrags[0] )
		{
			starfrags[0] = tempfrags;
			starid[0] = id;
			if ( tempfrags > starfrags[1] )
			{
				swapfrags = starfrags[1];
				swapid = starid[1];
				starfrags[1] = tempfrags;
				starid[1] = id;
				starfrags[0] = swapfrags;
				starid[0] = swapid;
				
				if ( tempfrags > starfrags[2] )
				{
					swapfrags = starfrags[2];
					swapid = starid[2];
					starfrags[2] = tempfrags;
					starid[2] = id;
					starfrags[1] = swapfrags;
					starid[1] = swapid;
				}
			}
		}
		save_badges(id);
	}
	
	new winner = starid[2];
	new bool:newleader = false;
	
	if ( !winner )
		return;
	
	//We now should have our three awards
	
	bronze[starid[0]]++;
	silver[starid[1]]++;
	gold[winner]++;
	
	if(starfrags[0]>=get_pcvar_num(gPcvarMinZabic)) {
		diamenty[starid[0]]+=get_pcvar_num(gPcvarDiamBraz);
		ColorChat(starid[0],GREEN,"[BF4:MOD]^x01 Otrzymales $d darmowe diamenty za zdobycie brazowego medalu i co najmniej %d fragow!", get_pcvar_num(gPcvarDiamBraz), get_pcvar_num(gPcvarMinZabic));
	}
	if(starfrags[1]>=get_pcvar_num(gPcvarMinZabic)) {
		diamenty[starid[1]]+=get_pcvar_num(gPcvarDiamSrebro);
		ColorChat(starid[1],GREEN,"[BF4:MOD]^x01 Otrzymales %d darmowe diamenty za zdobycie srebrnego medalu i co najmniej %d fragow!", get_pcvar_num(gPcvarDiamSrebro), get_pcvar_num(gPcvarMinZabic));
	}
	if(starfrags[2]>=get_pcvar_num(gPcvarMinZabic)) {
		diamenty[starid[2]]+=get_pcvar_num(gPcvarDiamZloto);
		ColorChat(starid[2],GREEN,"[BF4:MOD]^x01 Otrzymales %d darmowe diamenty za zdobycie zlotego medalu i co najmniej %d fragow!", get_pcvar_num(gPcvarDiamZloto), get_pcvar_num(gPcvarMinZabic));
	}
	
	new name[32];
	get_user_name(starid[2], name, charsmax(name));
	
	if ( gold[winner] > mostwins )
	{
		mostwins = gold[winner];
		newleader = true;
		formatex(mostwinsname, charsmax(mostwinsname), name);
	}
	
	new line[100];
	line[0] = 0x04;
	ColorChat(0,GREEN,"[BF4:MOD]^x01 Gratulacje dla Zwyciezcow!");
	
	line[0] = 0x04;
	
	get_user_name(starid[0], name, charsmax(name));
	line[0] = 0x04;
	ColorChat(0,GREEN,"[BF4:MOD]^x03 %s^x01 - Brazowy Medal -^x03 %i^x01 Zabojstw", name, starfrags[0]);
	
	get_user_name(starid[1], name, charsmax(name));
	line[0] = 0x04;
	ColorChat(0,GREEN,"[BF4:MOD]^x03 %s^x01 - Srebrny Medal -^x03 %i^x01 Zabojstw	", name, starfrags[1]);
	
	get_user_name(starid[2], name, charsmax(name));
	if (newleader)
	ColorChat(0,GREEN,"[BF4:MOD]^x03 %s^x01 - Zloty Medal -^x03 %i^x01 Zabojstw	", name, starfrags[2]);
	else
	ColorChat(0,GREEN,"[BF4:MOD]^x03 %s^x01 - Zloty Medal -^x03 %i^x01 Zabojstw	", name, starfrags[2]);
	
	save_badges(id);
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
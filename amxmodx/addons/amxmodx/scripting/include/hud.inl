//Bf4 Rank Mod HUD File
//Contains all the HUD functions.

#if defined bf4_hud_included
  #endinput
#endif
#define bf4_hud_included

//Show an announcement display
public Announcement(id)
{
	if ( !get_pcvar_num(gPcvarBF4Active) || is_user_bot(id) ) return;
	ColorChat(id,GREEN,"[BF4:MOD]^x01 Ten serwer uzywa^x04 %s.^x03 Wpisz^x04 ^"/bf4menu^"^x03 aby uzyskac wiecej informacji", gPluginName);
}

//Displays the HUD to the user
public DisplayHUD(id)
{
	if ( !get_pcvar_num(gPcvarBF4Active) || !get_pcvar_num(gPcvarStatusText) ) return;
	if ( !is_user_alive(id) || is_user_bot(id) ) return;
	
	static HUD[64];

	if ( !gStatsLoaded[id] )
	{
		formatex(HUD, charsmax(HUD), "[BF4:MOD] Wczytuje Dane...");
	}
	else
	{
		new rank = g_PlayerRank[id];
		new nextrank;

		switch(rank)
		{
			case 16, 19, 20, 21: nextrank = 15;
			case 17: nextrank = 7;
			case 18: nextrank = 8;
			default: nextrank = rank;
		}

		++nextrank;

		new nextrankxp = floatround(gRankXP[nextrank] * get_pcvar_float(gPcvarXpMultiplier));
		new reach = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]+reach21[id]+reach22[id]+reach23[id]+reach24[id]+reach25[id]);
		
		if ( !get_pcvar_num(gPcvarBadgesActive) )
		{
			formatex(HUD, charsmax(HUD), "[BF4:MOD] Zabicia: %d/%d  Ranga: %s", totalkills[id], nextrankxp, gRankName[rank]);
		}
		else
		{
			formatex(HUD, charsmax(HUD), "[BF4:MOD] Zabicia: %d/%d Odznaki: %d/100  Osiagniecia: %d/20", totalkills[id], nextrankxp, numofbadges[id], reach);
		}
	}
	
	message_begin(MSG_ONE_UNRELIABLE, gmsgStatusText, _, id);
	write_byte(0);
	write_string(HUD);
	message_end();
}

public BigHUD(param[]) {
	new id = param[0]
	if ( !is_user_alive(id) || is_user_bot(id) ) return;
	
	set_hudmessage(243, 186, 88, 0.87, 0.84, 2, 0.0, 1.1, -1.0, -1.0, 3)
	
	new umina[33], uapteczka[33];
	
	if(!gPlayerMinaUsed[id]) {
		formatex(umina, 32, "Mina: 1")
	} if(gPlayerMinaUsed[id]) {
		formatex(umina, 32, "Mina: 0")
	}
	
	if(!gPlayerMedkitUsed[id]) {
		formatex(uapteczka, 32, "Apteczka: 1")
	} if(gPlayerMedkitUsed[id]) {
		formatex(uapteczka, 32, "Apteczka: 0")
	}
	
	if((g_PlayerBadges[id][BADGE_NUMBER11]>=LEVEL_ISTOPNIA) && (g_PlayerBadges[id][BADGE_NUMBER12]>=LEVEL_ISTOPNIA)) {
		ShowSyncHudMsg(id, sync, "%s^n%s", umina, uapteczka)
	} else if((g_PlayerBadges[id][BADGE_NUMBER12]>=LEVEL_ISTOPNIA) && (g_PlayerBadges[id][BADGE_NUMBER11]<LEVEL_ISTOPNIA)) {
		ShowSyncHudMsg(id, sync, "%s", umina)
	} else if((g_PlayerBadges[id][BADGE_NUMBER11]>=LEVEL_ISTOPNIA) && (g_PlayerBadges[id][BADGE_NUMBER12]<LEVEL_ISTOPNIA)) {
		ShowSyncHudMsg(id, sync, "^n%s", uapteczka)
	}
}

public PrefixCzat(msgId,msgDest,msgEnt)
{
	new id = get_msg_arg_int(1);

	if(!is_user_connected(id))
		 return PLUGIN_CONTINUE;

	new szTmp[256],szTmp2[256]
	get_msg_arg_string(2,szTmp, charsmax( szTmp ) )

	new rank = g_PlayerRank[id];
	new szPrefix[64]
	formatex(szPrefix,charsmax( szPrefix ),"^x04[%s]",gRankName[rank]);

	if(!equal(szTmp,"#Cstrike_Chat_All"))
	{
		 add(szTmp2,charsmax(szTmp2),szPrefix);
		 add(szTmp2,charsmax(szTmp2)," ");
		 add(szTmp2,charsmax(szTmp2),szTmp);
	}
	else
	{
		 add(szTmp2,charsmax(szTmp2),szPrefix);
		 add(szTmp2,charsmax(szTmp2),"^x03 %s1^x01 :  %s2");
	}

	set_msg_arg_string(2,szTmp2);

	return PLUGIN_CONTINUE;
}
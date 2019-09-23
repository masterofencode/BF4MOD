//Bf4 Rank Mod othermods File
//Contains all the functions for bf4 to register flag scoring from CS flag mod.

#if defined bf4_flag_included
  #endinput
#endif
#define bf4_flag_included

public csf_flag_taken(id)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;

	new tempkills = get_pcvar_num(gPcvarFlagKills);

	if ( tempkills < 1 ) return;

	totalkills[id] += tempkills;
	DisplayHUD(id);
	ColorChat(id,GREEN,"[BF4:MOD]^x01 Zdobyles^x04 %d^x01 Punkty za zdobycie flagi", tempkills);
}

public csf_round_won(CsTeams:team)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;

	new tempkills = get_pcvar_num(gPcvarFlagRoundPoints);

	if ( tempkills < 1 ) return;

	for ( new id = 1; id <= gMaxPlayers; id++ )
	{
		if ( !is_user_connected(id) ) continue;
		if ( cs_get_user_team(id) != team ) continue;

		totalkills[id] += tempkills;
		DisplayHUD(id);
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Zdobyles^x04 %d^x01 Punkty za wygranie rundy flagowej", tempkills);
	}
}

public csf_match_won(CsTeams:team)
{
	if ( get_playersnum() < get_pcvar_num(gPcvarXpMinPlayers) ) return;

	new tempkills = get_pcvar_num(gPcvarFlagMatchPoints);

	if ( tempkills < 1 ) return;

	for ( new id = 1; id <= gMaxPlayers; id++ )
	{
		if ( !is_user_connected(id) ) continue;
		if ( cs_get_user_team(id) != team ) continue;

		totalkills[id] += tempkills;
		DisplayHUD(id);
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Zdobyles^x04 %d^x01 Punkty  za wygranie meczu na flagi", tempkills);
	}
}


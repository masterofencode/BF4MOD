//Bf4 Rank Mod badge powers File
//Contains all the power giving etc checking functions.

#if defined bf4_termowizja_included
#endinput
#endif
#define bf4_termowizja_included

new const Float:fColorGlow[3] =
{
	0.0,
	255.0,
	0.0
}

public EmitSound(id, iChannel, szSound[], Float:fVol, Float:fAttn, iFlags, iPitch ) 
{
	if ( !get_pcvar_num(gPcvarPower20) ) return FMRES_IGNORED;
	
	if(equal(szSound, "items/nvg_on.wav") && is_user_alive(id))
	{
		OnNVGToggle[id] = true; 
		
		new antyinvislvl1 = get_pcvar_num(gPcvarAntyInvisible1);
		new antyinvislvl2 = get_pcvar_num(gPcvarAntyInvisible2);
		new antyinvislvl3 = get_pcvar_num(gPcvarAntyInvisible3);
		new antyinvislvl4 = get_pcvar_num(gPcvarAntyInvisible4);

		switch(g_PlayerBadges[id][BADGE_NUMBER20]){
			case 1: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wlaczona. Widzisz teraz niewidzialnych wrogow w odleglosci %du.", antyinvislvl1);
			case 2: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wlaczona. Widzisz teraz niewidzialnych wrogow w odleglosci %du.", antyinvislvl2);
			case 3: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wlaczona. Widzisz teraz niewidzialnych wrogow w odleglosci %du.", antyinvislvl3);
			case 4: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wlaczona. Widzisz teraz niewidzialnych wrogow w odleglosci %du.", antyinvislvl4);
		}
		
		client_cmd(id, "spk cry/nanovision");
		new mode_changed = CreateMultiForward("mode_changed",ET_IGNORE,FP_CELL)
		new g_return
		ExecuteForward(mode_changed,g_return, id);
		DestroyForward(mode_changed);
		return FMRES_SUPERCEDE;
	}
	if(equal(szSound, "items/nvg_off.wav") && is_user_alive(id))
	{
		OnNVGToggle[id] = false; 
		
		switch(g_PlayerBadges[id][BADGE_NUMBER20]){
			case 1: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wylaczona.");
			case 2: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wylaczona.");
			case 3: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wylaczona.");
			case 4: ColorChat(id, GREEN, "[BF4:MOD]^x01 Termowizja wylaczona.");
		}

		new mode_changed = CreateMultiForward("mode_changed",ET_IGNORE,FP_CELL)
		new g_return
		ExecuteForward(mode_changed,g_return, id);
		DestroyForward(mode_changed);
		return FMRES_SUPERCEDE;
	}
	
	return FMRES_IGNORED;
}

public fwdAddToFullPackPost(es, e, ent, host, hostflags, player, pSet)
{
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return FMRES_IGNORED;
	if(!is_user_alive(host)) return FMRES_IGNORED;
	if ( !get_pcvar_num(gPcvarPower20) ) return FMRES_IGNORED;
	
	if(!pev_valid(ent)) return FMRES_IGNORED;
	
	new antyinvislvl1 = get_pcvar_num(gPcvarAntyInvisible1);
	new antyinvislvl2 = get_pcvar_num(gPcvarAntyInvisible2);
	new antyinvislvl3 = get_pcvar_num(gPcvarAntyInvisible3);
	new antyinvislvl4 = get_pcvar_num(gPcvarAntyInvisible4);
	
	switch(g_PlayerBadges[host][BADGE_NUMBER20]){
		case 1:
		{
			static Float:vOrigin[3], Float:vOriginEnt[3];
			pev(host, pev_origin, vOrigin);
			pev(ent, pev_origin, vOriginEnt);
			
			if( ( get_distance_f(vOrigin, vOriginEnt) <= antyinvislvl1 ) && OnNVGToggle[host] )
			{	
				set_es(es, ES_RenderColor, fColorGlow);
				set_es(es, ES_RenderMode, kRenderGlow);
				set_es(es, ES_RenderAmt, 16.0);
			}
		}
		case 2:
		{
			static Float:vOrigin[3], Float:vOriginEnt[3];
			pev(host, pev_origin, vOrigin);
			pev(ent, pev_origin, vOriginEnt);
			
			if( ( get_distance_f(vOrigin, vOriginEnt) <= antyinvislvl2 ) && OnNVGToggle[host] )
			{	
				set_es(es, ES_RenderColor, fColorGlow);
				set_es(es, ES_RenderMode, kRenderGlow);
				set_es(es, ES_RenderAmt, 16.0);
			}
		}
		case 3:
		{
			static Float:vOrigin[3], Float:vOriginEnt[3];
			pev(host, pev_origin, vOrigin);
			pev(ent, pev_origin, vOriginEnt);
			
			if( ( get_distance_f(vOrigin, vOriginEnt) <= antyinvislvl3 ) && OnNVGToggle[host] )
			{	
				set_es(es, ES_RenderColor, fColorGlow);
				set_es(es, ES_RenderMode, kRenderGlow);
				set_es(es, ES_RenderAmt, 16.0);
			}
		}
		case 4:
		{
			static Float:vOrigin[3], Float:vOriginEnt[3];
			pev(host, pev_origin, vOrigin);
			pev(ent, pev_origin, vOriginEnt);
			
			if( ( get_distance_f(vOrigin, vOriginEnt) <= antyinvislvl4 ) && OnNVGToggle[host] )
			{	
				set_es(es, ES_RenderColor, fColorGlow);
				set_es(es, ES_RenderMode, kRenderGlow);
				set_es(es, ES_RenderAmt, 16.0);
			}
		}
	}
	
	return FMRES_IGNORED;
}

/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
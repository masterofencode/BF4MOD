#if defined apteczka_included
#endinput
#endif
#define apteczka_included

public Apteczka(id){
	if(!is_user_connected(id) || !is_user_alive(id)) return PLUGIN_CONTINUE
	if ( !get_pcvar_num(gPcvarPower11) ) return PLUGIN_CONTINUE
	
	if(gPlayerMedkitUsed[id] || g_PlayerBadges[id][BADGE_NUMBER11]==0)
		return PLUGIN_HANDLED;
	
	if(!pev_valid(id)) return FMRES_IGNORED;
	
	gPlayerMedkitUsed[id]=true;
	DisplayHUD(id);
	
	new Float:vOrigin[3], ent;
	
	pev(id, pev_origin, vOrigin);
	
	ent = fm_create_entity("info_target");
	fm_entity_set_model(ent, "models/bf4mod/w_medkit.mdl");
	fm_entity_set_origin(ent, vOrigin);
	
	set_pev(ent, pev_classname,"apteczka")
	set_pev(ent, pev_solid, SOLID_BBOX)
	set_pev(ent, pev_movetype, MOVETYPE_TOSS)
	set_pev(ent, pev_owner, id);
	
	set_task(0.3, "TaskRemoveOwner", ent)
	
	apteczka[ent]=g_PlayerBadges[id][BADGE_NUMBER11]
	
	ColorChat(id,GREEN,"[BF4:MOD]^x01 Postawiles^x03 Apteczke^x01.")
	
	new Float:vVelo[3];
	velocity_by_aim(id, 200, vVelo);
	set_pev(ent, pev_velocity, vVelo);
	
	engfunc(EngFunc_SetSize, ent, Float:{-4.0, -7.0, 0.0}, Float:{4.0, 7.0, 0.01})
	
	return PLUGIN_HANDLED;
}

public TaskRemoveOwner(ent)
{
	if(!pev_valid(ent)) return;
	
	set_pev(ent, pev_owner, 0)
}

public kopnij(id) 
{
	new assaulthp = get_pcvar_num(gPcvarHP);
	new assaultlevel = g_PlayerBadges[id][BADGE_NUMBER3]		
	new hp;
	hp = 100 + (assaultlevel*assaulthp);
	
	if ( get_user_health(id) == hp ) set_user_health(id, get_user_health(id)-1);
	
	return PLUGIN_HANDLED;
}

public efekt_ekran(id)
{	
	screen_flash(id, 121, 205, 0, 100);
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
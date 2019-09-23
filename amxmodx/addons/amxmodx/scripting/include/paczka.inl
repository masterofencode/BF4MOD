#if defined paczka_included
#endinput
#endif
#define paczka_included

public Paczka(id) {
	if ( !get_pcvar_num(gPcvarBadgesActive) || !get_pcvar_num(gPcvarBadgePowers) ) return;
	if ( !get_pcvar_num(gPcvarPower19) ) return;
	
	new Float:vOrigin[3], ent;
	
	pev(id, pev_origin, vOrigin);
	
	ent = fm_create_entity("info_target");
	fm_entity_set_model(ent, "models/bf4mod/w_ammo.mdl");
	fm_entity_set_origin(ent, vOrigin);
	
	set_pev(ent,pev_classname,"paczka")
	set_pev(ent, pev_solid, SOLID_BBOX)
	set_pev(ent, pev_movetype, MOVETYPE_TOSS)
	set_pev(ent, pev_owner, id);
	
	set_task(0.5, "TaskRemoveOwner", ent)
	
	paczka[ent]=g_PlayerBadges[id][BADGE_NUMBER19]
	
	new Float:vVelo[3];
	velocity_by_aim(id, 100, vVelo);
	set_pev(ent, pev_velocity, vVelo);
	
	engfunc(EngFunc_SetSize, ent, Float:{-4.0, -7.0, 0.0}, Float:{4.0, 7.0, 0.01})
	
	return;
}

/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/

#if defined mina_included
#endinput
#endif
#define mina_included

public UzyjMiny(id){
	new Float:vfOrigin[3];
	new name [32];
	get_user_name(id, name, 31);
	pev(id, pev_origin, vfOrigin);
	
	new minao = get_pcvar_num(gPcvarMinaOdl);
  
	if((PrzeszkodaMina(vfOrigin, minao*1.0)) && (!gPlayerMinaUsed[id]))
		Mina(id);
	else if(!gPlayerMinaUsed[id])
		client_print(id, print_center, "[Mina] Stoisz za blisko przeszkody!");
		
	return PLUGIN_HANDLED;
}

PrzeszkodaMina(const Float:vfPunkt[3], Float:odleglosc){
	new Float:vfStart[3], Float:vfEnd[3];
  
	vfStart[0] = vfEnd[0] = vfPunkt[0];
	vfStart[1] = vfEnd[1] = vfPunkt[1];
	vfStart[2] = vfEnd[2] = vfPunkt[2];
  
	//1
	vfStart[0] += odleglosc;
	vfEnd[0] -= odleglosc;
	if(engfunc( EngFunc_PointContents, vfStart ) != CONTENTS_EMPTY
	&& engfunc( EngFunc_PointContents, vfEnd ) != CONTENTS_EMPTY)
		return 0;
  
	//2
	vfStart[0] -= odleglosc;
	vfEnd[0] += odleglosc;
	vfStart[1] += odleglosc;
	vfEnd[1] -= odleglosc;
  
	if(engfunc( EngFunc_PointContents, vfStart ) != CONTENTS_EMPTY
	&& engfunc( EngFunc_PointContents, vfEnd ) != CONTENTS_EMPTY)
		return 0;
	return 1;
}

public Mina(id){
	if(!is_user_connected(id) || !is_user_alive(id)) return PLUGIN_CONTINUE
	if ( !get_pcvar_num(gPcvarPower12) ) return PLUGIN_CONTINUE
	
	if(gPlayerMinaUsed[id] || g_PlayerBadges[id][BADGE_NUMBER12]==0)
		return PLUGIN_HANDLED;
	
	gPlayerMinaUsed[id]=true;
	DisplayHUD(id);
	
	new Float:origin[3];
	entity_get_vector(id, EV_VEC_origin, origin);
	
	new ent = create_entity("info_target");
	entity_set_string(ent ,EV_SZ_classname, "mina");
	entity_set_edict(ent ,EV_ENT_owner, id);
	entity_set_int(ent, EV_INT_movetype, MOVETYPE_TOSS);
	entity_set_origin(ent, origin);
	entity_set_int(ent, EV_INT_solid, SOLID_BBOX);
	mina[ent]=g_PlayerBadges[id][BADGE_NUMBER12]
	engfunc(EngFunc_SetModel, ent, "models/bf4mod/mina.mdl")
	
	entity_set_size(ent,Float:{-4.0,-8.0,-2.0},Float:{4.0,8.0,0.1});
	
	new WidzMiny1 = get_pcvar_num(gPcvarWidzMiny1);
	new WidzMiny2 = get_pcvar_num(gPcvarWidzMiny2);
	new WidzMiny3 = get_pcvar_num(gPcvarWidzMiny3);
	new WidzMiny4 = get_pcvar_num(gPcvarWidzMiny4);
	new WidzMiny5 = get_pcvar_num(gPcvarWidzMiny5);
	
	if ( get_pcvar_num(gPcvarPower17) ) {
		switch(g_PlayerBadges[id][BADGE_NUMBER17]){
			case 0: set_rendering(ent,kRenderFxNone, 0,0,0, kRenderTransTexture,WidzMiny1);
			case 1: set_rendering(ent,kRenderFxNone, 0,0,0, kRenderTransTexture,WidzMiny2);
			case 2: set_rendering(ent,kRenderFxNone, 0,0,0, kRenderTransTexture,WidzMiny3);
			case 3: set_rendering(ent,kRenderFxNone, 0,0,0, kRenderTransTexture,WidzMiny4);
			case 4: set_rendering(ent,kRenderFxNone, 0,0,0, kRenderTransTexture,WidzMiny5);
		}
	}
	
	ColorChat(id,GREEN,"[BF4:MOD]^x01 Postawiles^x03 Mine^x01.")
	
	return PLUGIN_CONTINUE;
}

public efekt_wybuchu(id)
{
	new Float:fOrigin[3];
	entity_get_vector( id, EV_VEC_origin, fOrigin);

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
}

public efekt_ekran_mina(id)
{	
	screen_flash(id, 255, 0, 0, 100);
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/

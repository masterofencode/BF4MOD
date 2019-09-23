#if defined dotyk_included
#endinput
#endif
#define dotyk_included

public pfn_touch ( ent, ptd ){
	if (ptd == 0)
 		return PLUGIN_CONTINUE
	if(!is_user_connected(ent) || !is_user_alive(ent)) return PLUGIN_CONTINUE
	
	new szClassName[32], szClassNameMina[32], szClassNamePaczka[32], wlasciciel
	
	if(pev_valid(ptd)){
		entity_get_string(ptd, EV_SZ_classname, szClassName, 31)
		wlasciciel = pev(ptd, pev_owner) 
		entity_get_string(ptd,EV_SZ_classname,szClassNameMina,31)
		entity_get_string(ptd,EV_SZ_classname,szClassNamePaczka,31)
	}
	else 
		return PLUGIN_HANDLED;
		
	if(equali(szClassName,"apteczka")){
		new assaulthp = get_pcvar_num(gPcvarHP);
		
		if(get_user_health(ent)>=100+g_PlayerBadges[ent][BADGE_NUMBER3]*assaulthp){
			client_print(ent,print_center,"[Apteczka] Jesli zostales zablokowany, wpisz: /kopnij");
			return PLUGIN_HANDLED;
		}
		new assaultlevel = g_PlayerBadges[ent][BADGE_NUMBER3]
		
		switch(apteczka[ptd]){
			case 1: {				
				new hp;
				hp = 100 + (assaultlevel*assaulthp);
				
				if ( get_user_health(ent) < hp )
				{
					set_user_health(ent, get_user_health(ent)+get_pcvar_num(gPcvarApteczka1));
					if(get_user_health(ent)>hp) set_user_health(ent, hp)
					
					if ( pev(ent, pev_max_health) < float(hp) )
					{
						set_pev(ent, pev_max_health, float(hp));
					}	
				}
			}
			case 2: {				
				new hp;
				hp = 100 + (assaultlevel*assaulthp);
				
				if ( get_user_health(ent) < hp )
				{
					set_user_health(ent, get_user_health(ent)+get_pcvar_num(gPcvarApteczka2));
					if(get_user_health(ent)>hp) set_user_health(ent, hp)
					
					if ( pev(ent, pev_max_health) < float(hp) )
					{
						set_pev(ent, pev_max_health, float(hp));
					}
				}
			}
			case 3: {				
				new hp;
				hp = 100 + (assaultlevel*assaulthp);
				
				if ( get_user_health(ent) < hp )
				{
					set_user_health(ent, get_user_health(ent)+get_pcvar_num(gPcvarApteczka3));
					if(get_user_health(ent)>hp) set_user_health(ent, hp)
					
					if ( pev(ent, pev_max_health) < float(hp) )
					{
						set_pev(ent, pev_max_health, float(hp));
					}
				}
			}
			case 4: {				
				new hp;
				hp = 100 + (assaultlevel*assaulthp);
				
				if ( get_user_health(ent) < hp )
				{
					set_user_health(ent, get_user_health(ent)+get_pcvar_num(gPcvarApteczka4));
					if(get_user_health(ent)>hp) set_user_health(ent, hp)
					
					if ( pev(ent, pev_max_health) < float(hp) )
					{
						set_pev(ent, pev_max_health, float(hp));
					}
				}
			}
		}
		apteczka[ptd]=0
		efekt_ekran(ent)
		remove_entity(ptd)	
		
		new name1[30];
		get_user_name(ent,name1,29);
		
		ColorChat(0, GREEN, "[BF4:MOD]^x01 Gracz^x03 %s^x01 podniosl apteczke.", name1); 
		
		new Float:fOrigin[3]
		pev(ent, pev_origin, fOrigin)
		
		engfunc(EngFunc_MessageBegin, MSG_PVS, SVC_TEMPENTITY, fOrigin, 0)
		write_byte(TE_SPRITE)
		engfunc(EngFunc_WriteCoord, fOrigin[0]+random_float(-5.0, 5.0))
		engfunc(EngFunc_WriteCoord, fOrigin[1]+random_float(-5.0, 5.0))
		engfunc(EngFunc_WriteCoord, fOrigin[2]+random_float(-10.0, 10.0))
		write_short(g_healspr)
		write_byte(random_num(5, 10))
		write_byte(200)
		message_end()
	}
	
	if(equali(szClassNameMina,"mina")){
		if (get_user_team(wlasciciel) != get_user_team(ptd))
		{
			new entlist[33];
			new numfound = find_sphere_class(ent,"player", 90.0 ,entlist, 32);

			for (new i=0; i < numfound; i++)
			{
				new pid = entlist[i];

				if (!is_user_alive(pid) || get_user_team(wlasciciel) == get_user_team(pid))
					continue;

				switch(mina[ptd]){
					case 1: set_user_health(ent, get_user_health(ent)-get_pcvar_num(gPcvarMina1));
					case 2: set_user_health(ent, get_user_health(ent)-get_pcvar_num(gPcvarMina2));
					case 3: set_user_health(ent, get_user_health(ent)-get_pcvar_num(gPcvarMina3));
					case 4: set_user_health(ent, get_user_health(ent)-get_pcvar_num(gPcvarMina4));
				}
				
				if (!is_user_alive(ent)) {
					set_user_frags(wlasciciel, get_user_frags(wlasciciel)+1)
					set_user_frags(ent, get_user_frags(ent)+1)
					minakills[wlasciciel]++;
					minadeath[ent]++;
					totalkills[wlasciciel]++;
					totaldeath[ent]++;
				}
				
				new name1[30], name2[30];
				get_user_name(ent,name1,29);
				get_user_name(wlasciciel,name2,29);
				
				ColorChat(0, GREEN, "[BF4:MOD]^x01 Gracz^x03 %s^x01 stanal na mine Claymore gracza^x04 %s^x01.", name1, name2); 
				
				mina[ptd]=0
				efekt_ekran_mina(ent)
				efekt_wybuchu(ent)
				remove_entity(ptd)
			}
		}
	}
	
	if(equali(szClassNamePaczka,"paczka")){
		new assaulthp = get_pcvar_num(gPcvarHP);
		new assaultlevel = g_PlayerBadges[ent][BADGE_NUMBER3]
		new paczkatlevel = g_PlayerBadges[ent][BADGE_NUMBER19]
		
		if ( ( paczkatlevel == LEVEL_ISTOPNIA ) || ( paczkatlevel > LEVEL_ISTOPNIA ) )
		{
			new hp;
			hp = 100 + (assaultlevel*assaulthp);
			
			if ( get_user_health(ent) < hp )
			{
				set_user_health(ent, get_user_health(ent)+get_pcvar_num(gPcvarPaczkaPrice));
				if(get_user_health(ent)>hp) set_user_health(ent, hp)
				
				if ( pev(ent, pev_max_health) < float(hp) )
				{
					set_pev(ent, pev_max_health, float(hp));
				}
			}
			
			new kasa = cs_get_user_money(ent);
			cs_set_user_money(ent, kasa + get_pcvar_num(gPcvarPaczkaPrice2), 1)
			
			if ( get_pcvar_num(gPcvarPaczkaPrice3) ) {
				fm_give_item(ent, "weapon_hegrenade");
				fm_give_item(ent, "weapon_flashbang");
				fm_give_item(ent, "weapon_flashbang");
				fm_give_item(ent, "weapon_smokegrenade");
			}
			
			paczka[ptd]=0
			padlino[ent]++
			efekt_ekran(ent)
			remove_entity(ptd)
		}
		else client_print(ent,print_center,"[Paczka] Aby ja podniesc musisz zdobyc odznake: Walka Mieszana.");
	}
	
	return PLUGIN_CONTINUE;
}

/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/
#if defined reach_included
#endinput
#endif
#define reach_included

public check_reach(id) 
{
	new wstats[8];
	new wroundstats[8];
	new wbodyhits[8];
	
	wstats[0]=0;
	wstats[4]=0;
	wstats[5]=0;
	wroundstats[0]=0;
	
	get_user_stats(id,wstats,wbodyhits);
	
	new acc = floatround((float(wstats[5])/float(wstats[4]))*100);
	accuracy[id]=acc;
	
	new medals = (bronze[id]+silver[id]+gold[id]);
	new krol = (totalkills[id]-totaldeath[id]);
	new reach = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]+reach21[id]+reach22[id]+reach23[id]+reach24[id]+reach25[id]);
	
	if ((grenadekills[id]>249) && (reach1[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Goraca Sprawa^x01."); 

		reach1[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((acc>34) && (reach2[id]==0))
	{		
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Polowanie^x01."); 

		reach2[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((totaldeath[id]>2499) && (reach3[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Najwyzsza Ofiara^x01."); 

		reach3[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((totalkills[id]>9999) && (reach4[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Szybki i Zabojczy^x01."); 

		reach4[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((dmgrec[id]>74999) && (reach5[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Chodzacy Magazynier^x01."); 

		reach5[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((onlinemin[id]>14999) && (reach6[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Wielki Gong^x01."); 

		reach6[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((medals>99) && (reach7[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Wzorowa Sluzba^x01."); 

		reach7[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((sniperkills[id]>499) && (reach8[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Cicha Przemoc^x01."); 

		reach8[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((shotsrec[id]>49999) && (reach9[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Celne Strzaly^x01."); 

		reach9[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((explosions[id]>49) && (reach10[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Az do Klikniecia^x01."); 	

		reach10[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((diamenty[id]>5) && (reach11[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Lowca Okazji^x01."); 

		reach11[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((numofbadges[id]>45) && (reach12[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Prawdziwe Wyzwanie^x01."); 	

		reach12[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((collectedcash[id]>999999) && (reach13[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Milioner^x01."); 	

		reach13[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((g_PlayerBadges[id][BADGE_NUMBER7]==LEVEL_IIISTOPNIA) && (reach14[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Incognito^x01."); 	

		reach14[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((krol>9999) && (reach15[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Krolewska Gra^x01."); 	

		reach15[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((livedround[id]>2499) && (reach16[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Niezniszczalny^x01."); 	

		reach16[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((minakills[id]>99) && (reach17[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Saper^x01."); 	

		reach17[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((minadeath[id]>199) && (reach18[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Nieudacznik^x01."); 	

		reach18[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((padlino[id]>499) && (reach19[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Padlinozerca^x01."); 	

		reach19[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	else if ((connects[id]>1999) && (reach20[id]==0))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Zdobyles osiagniecie:^x03 Bywalec^x01."); 	

		reach19[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}
	
	else if ((reach>19) && (reach_prize[id]<1))
	{
		ColorChat(id, GREEN, "^x04[BF4:MOD]^x01 Nagroda za zdobycie wszystkich osiagniec:^x03 5 Diamentow^x01."); 

		diamenty[id]+=5;

		reach_prize[id]++;
		efekt_ekran_reach(id)
		DisplayHUD(id);
	}

	return PLUGIN_CONTINUE;
}


public efekt_ekran_reach(id)
{	
	screen_flash(id, 120, 225, 0, 100);
}
/* AMXX-Studio Notes - DO NOT MODIFY BELOW HERE
*{\\ rtf1\\ ansi\\ deff0{\\ fonttbl{\\ f0\\ fnil Tahoma;}}\n\\ viewkind4\\ uc1\\ pard\\ lang1045\\ f0\\ fs16 \n\\ par }
*/

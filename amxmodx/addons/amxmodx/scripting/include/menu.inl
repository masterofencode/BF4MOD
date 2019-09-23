//Bf4 Rank Mod menu File
//Contains all the menu checking functions.

#if defined bf4_menu_included
  #endinput
#endif
#define bf4_menu_included

public Bf4menu(id) {
	if (!get_pcvar_num(gPcvarBF4Active))
	return PLUGIN_CONTINUE;

	new menu = menu_create("\rBF4:MOD - MENU", "menu_handler");

	menu_additem(menu, "\yPomoc", "0", 0);
	menu_additem(menu, "\wStatysyki", "1", 0);
	menu_additem(menu, "\wDiamenty", "2", 0);
	menu_additem(menu, "\wUstawienia", "3", 0);
	menu_additem(menu, "\yKonf. Serwera", "4", ADMIN_LEVEL);
	menu_additem(menu, "\rAdministracja", "5", ADMIN_LEVEL);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_MAIN;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public darmowamenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new menu = menu_create("\rBF4:MOD - Menu Darmowej Odznaki", "menu_handler");
 
	menu_additem(menu, "\yWalka \wNozem", "0", 0);
	menu_additem(menu, "\yWalka \wPistoletem", "1", 0);
	menu_additem(menu, "\yWalka \wBronia Szturmowa", "2", 0);
	menu_additem(menu, "\yWalka \wBronia Snajperska", "3", 0);
	menu_additem(menu, "\yWalka \wBronia Wsparcia", "4", 0);
	menu_additem(menu, "\yWalka \wGranatami", "5", 0);
	menu_additem(menu, "\yWalka \wStrzelba", "6", 0);
	menu_additem(menu, "\yWalka \wSMG", "7", 0);
	menu_additem(menu, "\yWalka \wCelnosciowa", "8", 0);
	menu_additem(menu, "\yWalka \wOgolna", "9", 0);
	menu_additem(menu, "\yWalka \wPowstanca", "10", 0);
	menu_additem(menu, "\yWalka \wPirotechnika", "11", 0);
	menu_additem(menu, "\yWalka \wna Medal", "12", 0);
	menu_additem(menu, "\yWalka \wna Staz", "13", 0);
	menu_additem(menu, "\yWalka \wna Osiagniecia", "14", 0);
	menu_additem(menu, "\yWalka \wna Odznaczenia", "15", 0);
	menu_additem(menu, "\yWalka \wna Miny", "16", 0);
	menu_additem(menu, "\yWalka \wUniwersalna", "17", 0);
	menu_additem(menu, "\yWalka \wMieszana", "18", 0);
	menu_additem(menu, "\yWalka \wna Czas", "19", 0);
	menu_additem(menu, "\yWalka \wna Zbieranie", "20", 0);
	menu_additem(menu, "\yWalka \wna Spowolnienie", "21", 0);
	menu_additem(menu, "\yWalka \wna Podswietlenie", "22", 0);
	menu_additem(menu, "\yWalka \wna Zgony", "23", 0);
	menu_additem(menu, "\yWalka \wna Polaczenia", "24", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_DARMOWA;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odbierz(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new opis[64]
	formatex(opis, 63, "\rBF4:MOD - Twoje diamenty: \y%d", diamenty[id])
	
	new menu_zadanie[64]
	new menu_zabicia[64]
	new menu_osiagniecia[64]
	new menu_odznaki1[64]
	new menu_odznaki2[64]
	new menu_odznaki3[64]
	new menu_odznaki4[64]
	
	formatex(menu_zadanie, 63, "\wPominiecie Zadania \r[\y%d Diamenty\r]", get_pcvar_num(gPcvarDiamZad))
	formatex(menu_zabicia, 63, "\yWybierz \wZabicia \r[\y%d Diamenty\r]", get_pcvar_num(gPcvarDiamKills))
	formatex(menu_osiagniecia, 63, "\yWybierz \wOsiagniecie \r[\y%d Diamentow\r]", get_pcvar_num(gPcvarDiamReach))
	formatex(menu_odznaki1, 63, "\yWybierz \wOdznake: I Poziom \r[\y%d Diament\r]", get_pcvar_num(gPcvarDiamBadge1))
	formatex(menu_odznaki2, 63, "\yWybierz \wOdznake: II Poziom \r[\y%d Diament\r]", get_pcvar_num(gPcvarDiamBadge2))
	formatex(menu_odznaki3, 63, "\yWybierz \wOdznake: III Poziom \r[\y%d Diament\r]", get_pcvar_num(gPcvarDiamBadge3))
	formatex(menu_odznaki4, 63, "\yWybierz \wOdznake: IV Poziom \r[\y%d Diament\r]", get_pcvar_num(gPcvarDiamBadge4))
	
	new menu = menu_create(opis, "menu_handler");

	menu_additem(menu, menu_zadanie, "0", 0);
	menu_additem(menu, menu_zabicia, "1", 0);
	menu_additem(menu, menu_osiagniecia, "2", 0);
	menu_additem(menu, menu_odznaki1, "3", 0);
	menu_additem(menu, menu_odznaki2, "4", 0);
	menu_additem(menu, menu_odznaki3, "5", 0);
	menu_additem(menu, menu_odznaki4, "6", 0);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_ODBIERZ;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public zabiciamenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz zabicia", "menu_handler");
 
	menu_additem(menu, "\w25 Zabic \y- \rOgolnych", "0", 0);
	menu_additem(menu, "\w10 Zabic \y- \rNozem", "1", 0);
	menu_additem(menu, "\w10 Zabic \y- \rPistoletem", "2", 0);
	menu_additem(menu, "\w10 Zabic \y- \rBronia Szturmowa", "3", 0);
	menu_additem(menu, "\w10 Zabic \y- \rBronia Snajperska", "4", 0);
	menu_additem(menu, "\w10 Zabic \y- \rBronia Wsparcia", "5", 0);
	menu_additem(menu, "\w10 Zabic \y- \rSMG", "6", 0);
	menu_additem(menu, "\w10 Zabic \y- \rStrzelbami", "7", 0);
	menu_additem(menu, "\w10 Zabic \y- \rGranatami", "8", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEPZABICIA;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public reachmenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz osiagniecie", "menu_handler");
 
	menu_additem(menu, "\wOsiagniecie \y- \rGoraca Sprawa", "0", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rPolowanie", "1", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rNajwyzsza Ofiara", "2", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rSzybki i Zabojczy", "3", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rChodzacy Magazynier", "4", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rWielki Gong", "5", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rWzorowa Sluzba", "6", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rCicha Przemoc", "7", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rCelne Strzaly", "8", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rAz do Klikniecia", "9", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rLowca Okazji", "10", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rPrawdziwe Wyzwanie", "11", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rMilioner", "12", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rIncognito", "13", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rKrolewska Gra", "14", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rNiezniszczalny", "15", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rSaper", "16", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rNieudacznik", "17", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rPadlinozerca", "18", 0);
	menu_additem(menu, "\wOsiagniecie \y- \rBywalec", "19", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEPREACH;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odznaki1menu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz odznake", "menu_handler");
 
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yNozem", "0", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yPistoletem", "1", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yBronia Szturmowa", "2", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yBronia Snajperska", "3", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yBronia Wsparcia", "4", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yGranatami", "5", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yStrzelba", "6", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \ySMG", "7", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yCelnosciowa", "8", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yOgolna", "9", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yPowstanca", "10", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yPirotechnika", "11", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Medal", "12", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Staz", "13", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Osiagniecia", "14", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Odznaczenia", "15", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Miny", "16", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yUniwersalna", "17", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yMieszana", "18", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Czas", "19", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Zbieranie", "20", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Spowolnienie", "21", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Podswietlenie", "22", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Zgony", "23", 0);
	menu_additem(menu, "\wI Stopnia \y- \rWalka \yna Polaczenia^n", "24", 0);
	
	menu_additem(menu, "\wWstecz", "25", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEP1;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odznaki2menu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz odznake", "menu_handler");
	
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yNozem", "0", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yPistoletem", "1", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yBronia Szturmowa", "2", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yBronia Snajperska", "3", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yBronia Wsparcia", "4", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yGranatami", "5", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yStrzelba", "6", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \ySMG", "7", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yCelnosciowa", "8", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yOgolna", "9", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yPowstanca", "10", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yPirotechnika", "11", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Medal", "12", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Staz", "13", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Osiagniecia", "14", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Odznaczenia", "15", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Miny", "16", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yUniwersalna", "17", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yMieszana", "18", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Czas", "19", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Zbieranie", "20", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Spowolnienie", "21", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Podswietlenie", "22", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Zgony", "23", 0);
	menu_additem(menu, "\wII Stopnia \y- \rWalka \yna Polaczenia^n", "24", 0);
	
	menu_additem(menu, "\wWstecz", "25", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEP2;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odznaki3menu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz odznake", "menu_handler");
	
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yNozem", "0", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yPistoletem", "1", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yBronia Szturmowa", "2", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yBronia Snajperska", "3", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yBronia Wsparcia", "4", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yGranatami", "5", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yStrzelba", "6", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \ySMG", "7", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yCelnosciowa", "8", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yOgolna", "9", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yPowstanca", "10", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yPirotechnika", "11", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Medal", "12", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Staz", "13", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Osiagniecia", "14", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Odznaczenia", "15", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Miny", "16", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yUniwersalna", "17", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yMieszana", "18", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Czas", "19", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Zbieranie", "20", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Spowolnienie", "21", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Podswietlenie", "22", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Zgony", "23", 0);
	menu_additem(menu, "\wIII Stopnia \y- \rWalka \yna Polaczenia^n", "24", 0);
	
	menu_additem(menu, "\wWstecz", "25", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEP3;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odznaki4menu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
		
  	new menu = menu_create("\rBF4:MOD - Wybierz odznake", "menu_handler");
	
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yNozem", "0", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yPistoletem", "1", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yBronia Szturmowa", "2", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yBronia Snajperska", "3", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yBronia Wsparcia", "4", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yGranatami", "5", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yStrzelba", "6", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \ySMG", "7", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yCelnosciowa", "8", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yOgolna", "9", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yPowstanca", "10", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yPirotechnika", "11", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Medal", "12", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Staz", "13", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Osiagniecia", "14", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Odznaczenia", "15", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Miny", "16", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yUniwersalna", "17", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yMieszana", "18", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Czas", "19", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Zbieranie", "20", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Spowolnienie", "21", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Podswietlenie", "22", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Zgony", "23", 0);
	menu_additem(menu, "\wIV Stopnia \y- \rWalka \yna Polaczenia^n", "24", 0);
	
	menu_additem(menu, "\wWstecz", "25", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_SKLEP4;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public helpmenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new menu = menu_create("\rBF4:MOD - Menu Pomocy", "menu_handler");
 
	menu_additem(menu, "\yOpis Moda", "0", 0);
	menu_additem(menu, "\wOpis Osiagniec 1", "1", 0);
	menu_additem(menu, "\wOpis Osiagniec 2", "2", 0);
	menu_additem(menu, "\wOpis Osiagniec 3", "3", 0);
	menu_additem(menu, "\wOpis Odznak \y(menu)", "4", 0);
	menu_additem(menu, "\yOpis Medali", "5", 0);
	menu_additem(menu, "\yOpis Rang^n", "6", 0);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_HELP;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public odznaki(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new menu = menu_create("\rBF4:MOD - Menu Pomocy - Odznaki", "menu_handler");
 
	menu_additem(menu, "\yWalka \wNozem", "0", 0);
	menu_additem(menu, "\yWalka \wPistoletem", "1", 0);
	menu_additem(menu, "\yWalka \wBronia Szturmowa", "2", 0);
	menu_additem(menu, "\yWalka \wBronia Snajperska", "3", 0);
	menu_additem(menu, "\yWalka \wBronia Wsparcia", "4", 0);
	menu_additem(menu, "\yWalka \wGranatami", "5", 0);
	menu_additem(menu, "\yWalka \wStrzelba", "6", 0);
	menu_additem(menu, "\yWalka \wSMG", "7", 0);
	menu_additem(menu, "\yWalka \wCelnosciowa", "8", 0);
	menu_additem(menu, "\yWalka \wOgolna", "9", 0);
	menu_additem(menu, "\yWalka \wPowstanca", "10", 0);
	menu_additem(menu, "\yWalka \wPirotechnika", "11", 0);
	menu_additem(menu, "\yWalka \wna Medal", "12", 0);
	menu_additem(menu, "\yWalka \wna Staz", "13", 0);
	menu_additem(menu, "\yWalka \wna Osiagniecia", "14", 0);
	menu_additem(menu, "\yWalka \wna Odznaczenia", "15", 0);
	menu_additem(menu, "\yWalka \wna Miny", "16", 0);
	menu_additem(menu, "\yWalka \wUniwersalna", "17", 0);
	menu_additem(menu, "\yWalka \wMieszana", "18", 0);
	menu_additem(menu, "\yWalka \wna Czas", "19", 0);
	menu_additem(menu, "\yWalka \wna Zbieranie", "20", 0);
	menu_additem(menu, "\yWalka \wna Spowolnienie", "21", 0);
	menu_additem(menu, "\yWalka \wna Podswietlenie", "22", 0);
	menu_additem(menu, "\yWalka \wna Zgony", "23", 0);
	menu_additem(menu, "\yWalka \wna Polaczenia^n", "24", 0);
	
	menu_additem(menu, "\wWstecz", "25", 0);
	
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_ODZNAKI;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public playerlist(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new menu = menu_create("\rBF4:MOD - Wybierz Gracza", "menu_handler");
 
	new players[32],num;
	get_players(players,num,"h");
	new name[30];
	new player;
	new tempstring[32];
	new idarray[3];
	
	for (new i=0; i<num; i++)
	{
		player=players[i];
		get_user_name(player,name,29);
		formatex(tempstring,49,"\w%s",name);
		formatex(idarray,2,"%i",player);
		menu_additem(menu, tempstring, idarray, 0);
	}

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_PLAYER;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public statsmenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
    
	new menu = menu_create("\rBF4:MOD - Menu Statystyk", "menu_handler");
 
	menu_additem(menu, "\yPokaz Liste Graczy", "0", 0);
	menu_additem(menu, "\zPokaz Twoje Misje", "1", 0);
	menu_additem(menu, "\zPokaz Twoje Odznaki", "2", 0);
	menu_additem(menu, "\zPokaz Twoje Osiagniecia", "3", 0);
	menu_additem(menu, "\zPokaz Twoje Statystyki - 1", "4", 0);
	menu_additem(menu, "\zPokaz Twoje Statystyki - 2", "5", 0);
	menu_additem(menu, "\rPokaz Statystyki Serwera^n", "6", 0);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_STATS;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public adminmenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
	
	new menu = menu_create("\rBF4:MOD - Administracja", "menu_handler");
 
	menu_additem(menu, "\wDaj graczowi odznake", "0", ADMIN_LEVEL);
	menu_additem(menu, "\wDaj graczowi diamenty^n", "1", ADMIN_LEVEL);
	menu_additem(menu, "\wWstecz", "2", ADMIN_LEVEL);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);

	menuselection[id]=MENU_ADMIN;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public badgemenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

  	new menu = menu_create("\rBF4:MOD - Wybierz Odznake", "menu_handler");
 
	menu_additem(menu, "\yWalka \wNozem", "0", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wPistoletem", "1", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wBronia Szturmowa", "2", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wBronia Snajperska", "3", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wBronia Wsparcia", "4", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wGranatami", "5", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wStrzelba", "6", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wSMG", "7", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wCelnosciowa", "8", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wOgolna", "9", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wPowstanca", "10", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wPirotechnika", "11", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Medal", "12", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Staz", "13", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Osiagniecia", "14", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Odznaczenia", "15", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Miny", "16", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wUniwersalna", "17", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wMieszana", "18", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Czas", "19", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Zbieranie", "20", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Spowolnienie", "21", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Podswietlenie", "22", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Zgony", "23", ADMIN_LEVEL);
	menu_additem(menu, "\yWalka \wna Polaczenia^n", "24", ADMIN_LEVEL);
  
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_BADGE;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public kupionaodznaka(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

  	new menu = menu_create("\rBF4:MOD - Wybierz Ilosc", "menu_handler");
 
	menu_additem(menu, "\y0 \wDiamentow", "0", ADMIN_LEVEL);
	menu_additem(menu, "\y5 \wDiamentow", "1", ADMIN_LEVEL);
	menu_additem(menu, "\y10 \wDiamentow", "2", ADMIN_LEVEL);
	menu_additem(menu, "\y15 \wDiamentow", "3", ADMIN_LEVEL);
	menu_additem(menu, "\y20 \wDiamentow", "4", ADMIN_LEVEL);
	menu_additem(menu, "\y25 \wDiamentow", "5", ADMIN_LEVEL);
	menu_additem(menu, "\y30 \wDiamentow", "6", ADMIN_LEVEL);
	menu_additem(menu, "\y35 \wDiamentow", "7", ADMIN_LEVEL);
	menu_additem(menu, "\y40 \wDiamentow", "8", ADMIN_LEVEL);
	menu_additem(menu, "\y45 \wDiamentow", "9", ADMIN_LEVEL);
	menu_additem(menu, "\y50 \wDiamentow", "10", ADMIN_LEVEL);
	menu_additem(menu, "\y55 \wDiamentow", "11", ADMIN_LEVEL);
	menu_additem(menu, "\y60 \wDiamentow", "12", ADMIN_LEVEL);
	menu_additem(menu, "\y65 \wDiamentow", "13", ADMIN_LEVEL);
	menu_additem(menu, "\y70 \wDiamentow", "14", ADMIN_LEVEL);
	menu_additem(menu, "\y75 \wDiamentow", "15", ADMIN_LEVEL);
	menu_additem(menu, "\y80 \wDiamentow", "16", ADMIN_LEVEL);
	menu_additem(menu, "\y85 \wDiamentow", "17", ADMIN_LEVEL);
	menu_additem(menu, "\y90 \wDiamentow", "18", ADMIN_LEVEL);
	menu_additem(menu, "\y95 \wDiamentow", "19", ADMIN_LEVEL);
	menu_additem(menu, "\y100 \wDiamentow", "20", ADMIN_LEVEL);
  
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_KUPIONA;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public badgelevelmenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

   	new menu = menu_create("\rBF4:MOD - Wybierz Poziom", "menu_handler");
 
	menu_additem(menu, "\wZaden", "0", ADMIN_LEVEL);
	menu_additem(menu, "\wI Stopnia", "1", ADMIN_LEVEL);
	menu_additem(menu, "\wII Stopnia", "2", ADMIN_LEVEL);
	menu_additem(menu, "\wIII Stopnia", "3", ADMIN_LEVEL);
	menu_additem(menu, "\rIV Stopnia^n", "4", ADMIN_LEVEL);
	menu_additem(menu, "\wWstecz", "5", ADMIN_LEVEL);

	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_LEVEL;

	menu_display(id, menu, 0);
	
	return PLUGIN_CONTINUE;
}

public mocemenu(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;
	
	new m_odzn1[64], m_odzn2[64], m_odzn3[64], m_odzn4[64];
  	new menu = menu_create("\rBF4:MOD Ustawienia", "menu_handler");

	if(g_PlayerBadges[id][BADGE_NUMBER4]>=1) {
		formatex(m_odzn1, 63, "Darmowa Snajperka \y[\r%s\y]", odzn_1[id] ? "Wl" : "Wyl");
		menu_additem(menu, m_odzn1, "0", 0);
	} else {
		menu_additem(menu, "\dDarmowa Snajperka \y[\rbrak\y]", "0", 0);
	}
	
	if(g_PlayerBadges[id][BADGE_NUMBER10]>=1) {
		formatex(m_odzn2, 63, "Darmowe MP5 \y[\r%s\y]", odzn_2[id] ? "Wl" : "Wyl");
		menu_additem(menu, m_odzn2, "1", 0);
	} else {
		menu_additem(menu, "\dDarmowe MP5 \y[\rbrak\y]", "0", 0);
	}
	
	if(g_PlayerBadges[id][BADGE_NUMBER15]>=1) {	
		formatex(m_odzn3, 63, "Darmowy Deagl \y[\r%s\y]", odzn_3[id] ? "Wl" : "Wyl");
		menu_additem(menu, m_odzn3, "2", 0);
	} else {
		menu_additem(menu, "\dDarmowy Deagl \y[\rbrak\y]", "0", 0);
	}
	
	if(g_PlayerBadges[id][BADGE_NUMBER18]>=1) {	
		formatex(m_odzn4, 63, "Darmowe Dodatki \y[\r%s\y]^n", odzn_4[id] ? "Wl" : "Wyl");
		menu_additem(menu, m_odzn4, "3", 0);
	} else {
		menu_additem(menu, "\dDarmowe Dodatki \y[\rbrak\y]", "0", 0);
	}
  
	menu_setprop(menu, MPROP_EXIT, MEXIT_ALL);
  
	menuselection[id]=MENU_MOCE;

	menu_display(id, menu, 0);

	return PLUGIN_CONTINUE;
}

public menu_handler(id,menu,item)
{
	if (item == MENU_EXIT)
	{
		menu_destroy(menu);
		return PLUGIN_HANDLED;
	}
	else if (item == MENU_BACK)
	{
		menu_display(id, menu, 0);
		return PLUGIN_HANDLED;	
	}

	new data[6], iName[64];
	new access, callback;

	menu_item_getinfo(menu, item, access, data,5, iName, 63, callback);


	if (!(get_user_flags(id) & access) && access)
		return PLUGIN_HANDLED;

	new key=str_to_num(data);
	
	new cena_zadania = get_pcvar_num(gPcvarDiamZad);
	new cena_zabicia = get_pcvar_num(gPcvarDiamKills);
	new cena_osiagniecia = get_pcvar_num(gPcvarDiamReach);
	new cena_odznaki1 = get_pcvar_num(gPcvarDiamBadge1);
	new cena_odznaki2 = get_pcvar_num(gPcvarDiamBadge2);
	new cena_odznaki3 = get_pcvar_num(gPcvarDiamBadge3);
	new cena_odznaki4 = get_pcvar_num(gPcvarDiamBadge4);

	switch (menuselection[id])
	{
		case MENU_MOCE:
		{
  			switch (key)
			{
				case 0: {
					if(g_PlayerBadges[id][BADGE_NUMBER4]>=1) odzn_1[id] = !odzn_1[id];
					
					mocemenu(id);
				}
				case 1: {
					if(g_PlayerBadges[id][BADGE_NUMBER10]>=1) odzn_2[id] = !odzn_2[id];
					
					mocemenu(id);
				}
				case 2: {
					if(g_PlayerBadges[id][BADGE_NUMBER15]>=1) odzn_3[id] = !odzn_3[id];
					
					mocemenu(id);
				}
				case 3: {
					if(g_PlayerBadges[id][BADGE_NUMBER18]>=1) odzn_4[id] = !odzn_4[id];
					
					mocemenu(id);
				}
			}
		}
		case MENU_BADGE:
		{
  			menuselected[id][0]=0;
			menuselected[id][1]=key;
			badgelevelmenu(id);
		}
		case MENU_KUPIONA:
		{
  			menuselected[id][0]=key;
			playerlist(id);
		}
		case MENU_LEVEL:
		{
			menuselected[id][2]=key;
			playerlist(id);
		}
		case MENU_ADMIN:
		{
			switch (key)
			{
				case 0:	badgemenu(id);
				case 1: kupionaodznaka(id);
				case 2: Bf4menu(id);
			}
		}
		case MENU_MAIN:
		{
			switch (key)
			{
				case 0: helpmenu(id);
				case 1:	statsmenu(id);
				case 2:	odbierz(id);
				case 3:	mocemenu(id);
				case 4:	show_server_config(id);
				case 5:	adminmenu(id);	
			}
		}
		case MENU_STATS:
		{
			switch (key)
			{
				case 0: cmd_who(id);
				case 1: client_cmd(id,"say /z"); 
				case 2:	
				{
					display_badges(id,id);
				}
				case 3:	show_stats_reach(id);
				case 4:	show_stats(id);
				case 5:	show_stats_second(id);
				case 6:	show_server_stats(id);
			}
		}
		case MENU_HELP:
		{
			switch (key)
			{
				case 0: cmd_help(id);
				case 1:	show_osiagniecia(id);
				case 2:	show_osiagniecia2(id);
				case 3:	show_osiagniecia3(id);
				case 4:	odznaki(id);
				case 5: show_medale(id);
				case 6:	show_rankhelp(id);
			}
		}
		case MENU_DARMOWA:
		{
			switch (key)
			{
				case 0: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER1]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 1: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER2]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	 
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 2: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER3]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 3: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER4]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 4: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER5]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 5: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER6]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 6: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER7]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 7: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER8]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 8: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER9]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 9: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER10]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	 
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 10: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER11]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 11: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER12]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 12: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER13]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 13: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER14]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 14: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER15]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 15: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER16]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	 
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 16: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER17]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 17: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER18]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 18: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER19]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 19: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER20]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 20: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER21]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 21: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER22]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 22: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER23]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 23: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER24]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
				case 24: 
				{
					if (darmowa[id]<get_pcvar_num(gPcvarIlosc)) {
						new poziom = get_pcvar_num(gPcvarPoziom);
						g_PlayerBadges[id][BADGE_NUMBER25]=poziom;
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Otrzymales wybrana^x04 darmowa odznake^x01."); 	
						darmowa[id]++;
						save_badges(id);
						DisplayHUD(id);
					}
				}
			}
		}
		case MENU_ODZNAKI:
		{
			switch (key)
			{
				case 0: show_badgehelp(id);
				case 1: show_badgehelp2(id);
				case 2: show_badgehelp3(id);
				case 3: show_badgehelp4(id);
				case 4: show_badgehelp5(id);
				case 5: show_badgehelp6(id);
				case 6: show_badgehelp7(id);
				case 7: show_badgehelp8(id);
				case 8: show_badgehelp9(id);
				case 9: show_badgehelp10(id);
				case 10: show_badgehelp11(id);
				case 11: show_badgehelp12(id);
				case 12: show_badgehelp13(id);
				case 13: show_badgehelp14(id);
				case 14: show_badgehelp15(id);
				case 15: show_badgehelp16(id);
				case 16: show_badgehelp17(id);
				case 17: show_badgehelp18(id);
				case 18: show_badgehelp19(id);
				case 19: show_badgehelp20(id);
				case 20: show_badgehelp21(id);
				case 21: show_badgehelp22(id);
				case 22: show_badgehelp23(id);
				case 23: show_badgehelp24(id);
				case 24: show_badgehelp25(id);
				case 25: Bf4menu(id);
			}
		}
		case MENU_ODBIERZ:
		{
			switch (key)
			{
				case 0:	{
					if (diamenty[id]<cena_zadania) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]);
					} else {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 pominiecie zadania^x01.");
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Pominiecie zadania - Nick: %s", name);
						zadanie[id]++;
						postep[id]=0;
						diamenty[id]-=cena_zadania;
						save_badges(id);
						DisplayHUD(id);
						
						odbierz(id);
					}
				}
				case 1:	{
					if (diamenty[id]<cena_zabicia) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]);
						odbierz(id);
					} else zabiciamenu(id);
				}
				case 2:	{
					if (diamenty[id]<cena_osiagniecia) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]);
						odbierz(id);
					} else reachmenu(id);
				}
				case 3:	{
					if (diamenty[id]<cena_odznaki1) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]);
						odbierz(id);
					} else odznaki1menu(id);
				}
				case 4:	{
					if (diamenty[id]<cena_odznaki2) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]); 
						odbierz(id);
					} else odznaki2menu(id);
				}
				case 5:	{
					if (diamenty[id]<cena_odznaki3) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]);
						odbierz(id); 
					} else odznaki3menu(id);
				}
				case 6:	{
					if (diamenty[id]<cena_odznaki4) {
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz za malo diamentow - %d diamentow.", diamenty[id]); 
						odbierz(id);
					} else odznaki4menu(id);
				}
			}
		}
		case MENU_SKLEPZABICIA:
        {
			switch (key)
			{
				case 0: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Ogolne^x01.");
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Zabicia - Nick: %s", name);
					totalkills[id]+=25;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 1: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Nozem^x01.");
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Zabicia - Nick: %s", name);
					knifekills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 2: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Pistoletem^x01.");		
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Zabicia - Nick: %s", name);
					pistolkills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 3: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Bronia Szturmowa^x01.");
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Zabicia - Nick: %s", name);
					riflekills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 4: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Bronia Snajperska^x01.");			
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Zabicia - Nick: %s", name);
					sniperkills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 5: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Bronia Wsparcia^x01.");
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Zabicia - Nick: %s", name);
					parakills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 6: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 SMG^x01."); 	
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Zabicia - Nick: %s", name);
					smgkills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 7: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Strzelbami^x01."); 			
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Zabicia - Nick: %s", name);
					shotgunkills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
				case 8: 
				{
					ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 zabicia^x01 -^x04 Granatami^x01."); 	
					new name[30];
					get_user_name(id,name,29)
					log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Zabicia - Nick: %s", name);
					grenadekills[id]+=10;
					diamenty[id]-=cena_zabicia;
					save_badges(id);
					DisplayHUD(id);
				}
			}
        }
		case MENU_SKLEPREACH:
        {
			switch (key)
			{
				case 0: 
				{
					if (reach1[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Goraca Sprawa^x01.");		
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Osiagniecie - Nick: %s", name);
						reach1[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]);
				}
				case 1: 
				{
					if (reach2[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Polowanie^x01.");		
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Osiagniecie - Nick: %s", name);
						reach2[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 2: 
				{
					if (reach3[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Najwyzsza Ofiara^x01.");				
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Osiagniecie - Nick: %s", name);
						reach3[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 3: 
				{
					if (reach4[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Szybki i Zabojczy^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Osiagniecie - Nick: %s", name);
						reach4[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 4: 
				{
					if (reach5[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Chodzacy Magazynier^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Osiagniecie - Nick: %s", name);
						reach5[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 5: 
				{
					if (reach6[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Wielki Gong^x01.");				
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Osiagniecie - Nick: %s", name);
						reach6[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 6: 
				{
					if (reach7[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Wzorowa Sluzba^x01.");				
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Osiagniecie - Nick: %s", name);
						reach7[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 7: 
				{
					if (reach8[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Cicha Przemoc^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Osiagniecie - Nick: %s", name);
						reach8[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 8: 
				{
					if (reach9[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Celne Strzaly^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Osiagniecie - Nick: %s", name);
						reach9[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 9: 
				{
					if (reach10[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Az do Klikniecia^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 10 Osiagniecie - Nick: %s", name);
						reach10[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 10: 
				{
					if (reach11[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Lowca Okazji^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 11 Osiagniecie - Nick: %s", name);
						reach11[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 11: 
				{
					if (reach12[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Prawdziwe Wyzwanie^x01.");		
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 12 Osiagniecie - Nick: %s", name);
						reach12[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 12: 
				{
					if (reach13[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Milioner^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 13 Osiagniecie - Nick: %s", name);
						reach13[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 13: 
				{
					if (reach14[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Incognito^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 14 Osiagniecie - Nick: %s", name);
						reach14[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 14: 
				{
					if (reach15[id]==0)
					{
						ColorChat(id, GREEN, "[BF4]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Krolewska Gra^x01.");				
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 15 Osiagniecie - Nick: %s", name);
						reach15[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 15: 
				{
					if (reach16[id]==0)
					{
						ColorChat(id, GREEN, "[BF4]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Niezniszczalny^x01.");		
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 16 Osiagniecie - Nick: %s", name);
						reach16[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 16: 
				{
					if (reach17[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Saper^x01.");		
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 17 Osiagniecie - Nick: %s", name);
						reach17[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4::MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 17: 
				{
					if (reach18[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Nieudacznik^x01.");	
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 18 Osiagniecie - Nick: %s", name);
						reach18[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 18: 
				{
					if (reach19[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Padlinozerca^x01.");
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 19 Osiagniecie - Nick: %s", name);
						reach19[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 
				}
				case 19: 
				{
					if (reach20[id]==0)
					{
						ColorChat(id, GREEN, "[BF4:MOD]^x01 Odebrales^x03 osiagniecie^x01 -^x04 Bywalec^x01.");			
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 20 Osiagniecie - Nick: %s", name);
						reach20[id]++;
						diamenty[id]-=cena_osiagniecia;
						save_badges(id);
						DisplayHUD(id);
					} else ColorChat(id, GREEN, "[BF4:MOD]^x01 Posiadasz juz osiagniecie.", diamenty[id]); 	
				}
			}
        }
		case MENU_SKLEP1:
        {
			switch (key)
			{
				case 0: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER1]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER1]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 1: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER2]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER2]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 2: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER3]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER3]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 3: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER4]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER4]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 4: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER5]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER5]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 5: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER6]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER6]=1; 
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 6: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER7]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER7]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 7: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER8]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER8]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 8: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER9]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER9]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 9: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER10]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER10]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 10 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 10: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER11]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER11]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 11 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 11: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER12]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER12]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 12 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 12: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER13]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER13]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 13 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 13: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER14]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER14]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 14 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 14: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER15]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER15]=1; 
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 15 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 15: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER16]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER16]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 16 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 16: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER17]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER17]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 17 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 17: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER18]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER18]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 18 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 18: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER19]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER19]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 19 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 19: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER20]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER20]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 20 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 20: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER21]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER21]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 21 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 21: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER22]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER22]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 22 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 22: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER23]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER23]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 23 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 23: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER24]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER24]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 24 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 24: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER25]<LEVEL_ISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER25]=1;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 25 Odznaka - 1 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 25: odbierz(id);
			}
        }
		case MENU_SKLEP2:
        {
			switch (key)
			{
				case 0: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER1]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER1]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 1: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER2]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER2]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 2: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER3]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER3]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 3: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER4]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER4]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 4: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER5]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER5]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 5: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER6]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER6]=2; 
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 6: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER7]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER7]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 7: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER8]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER8]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 8: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER9]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER9]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 9: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER10]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER10]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 10 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 10: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER11]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER11]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 11 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 11: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER12]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER12]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 12 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 12: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER13]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER13]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 13 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 13: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER14]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER14]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 14 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 14: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER15]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER15]=2; 
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 15 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 15: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER16]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER16]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 16 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 16: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER17]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER17]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 17 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 17: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER18]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER18]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 18 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 18: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER19]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER19]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 19 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 19: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER20]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER20]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 20 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 20: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER21]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER21]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 21 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 21: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER22]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER22]=2;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 22 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 22: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER23]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER23]=2;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 23 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 23: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER24]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER24]=2;
						diamenty[id]-=cena_odznaki1;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 24 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 24: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER25]<LEVEL_IISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER25]=2;
						diamenty[id]-=cena_odznaki2;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 25 Odznaka - 2 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 25: odbierz(id);
			}
		}
		case MENU_SKLEP3:
        {
			switch (key)
			{
				case 0: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER1]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER1]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 1: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER2]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER2]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 2: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER3]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER3]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 3: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER4]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER4]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 4: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER5]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER5]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 5: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER6]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER6]=3; 
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 6: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER7]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER7]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 7: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER8]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER8]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 8: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER9]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER9]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 9: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER10]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER10]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 10 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 10: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER11]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER11]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 11 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 11: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER12]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER12]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 12 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 12: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER13]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER13]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 13 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 13: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER14]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER14]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 14 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 14: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER15]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER15]=3; 
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 15 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 15: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER16]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER16]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 16 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 16: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER17]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER17]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 17 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 17: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER18]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER18]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 18 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 18: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER19]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER19]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 19 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 19: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER20]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER20]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 20 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 20: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER21]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER21]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 21 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 21: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER22]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER22]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 22 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 22: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER23]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER23]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 23 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 23: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER24]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER24]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 24 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 24: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER25]<LEVEL_IIISTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER25]=3;
						diamenty[id]-=cena_odznaki3;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 25 Odznaka - 3 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 25: odbierz(id);
			}
		}
		case MENU_SKLEP4:
        {
			switch (key)
			{
				case 0: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER1]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER1]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 1 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 1: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER2]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER2]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 2 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 2: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER3]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER3]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 3 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 3: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER4]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER4]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 4 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 4: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER5]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER5]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 5 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 5: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER6]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER6]=4; 
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 6 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 6: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER7]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER7]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 7 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 7: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER8]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER8]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 8 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 8: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER9]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER9]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 9 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 9: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER10]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER10]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 10 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 10: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER11]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER11]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 11 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 11: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER12]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER12]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 12 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 12: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER13]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER13]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 13 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 13: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER14]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER14]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 14 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 14: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER15]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER15]=4; 
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 15 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 15: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER16]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER16]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 16 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 16: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER17]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER17]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 17 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 17: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER18]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER18]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 18 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 18: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER19]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER19]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 19 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 19: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER20]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER20]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 20 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 20: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER21]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER21]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 21 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 21: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER22]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER22]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 22 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 22: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER23]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER23]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 23 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 23: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER24]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER24]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 24 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 24: 
				{
					if (g_PlayerBadges[id][BADGE_NUMBER25]<LEVEL_IVSTOPNIA)
					{
						g_PlayerBadges[id][BADGE_NUMBER25]=4;
						diamenty[id]-=cena_odznaki4;
						save_badges(id);
						DisplayHUD(id);
						
						new name[30];
						get_user_name(id,name,29)
						log_to_file("addons/amxmodx/configs/diamenty.ini", "[KUPIONO] 25 Odznaka - 4 Poziom - Nick: %s", name);
					}
					else ColorChat(id, GREEN, "[BF4:MOD]^x01 Nie mozesz wybrac tej odznaki, poniewaz^x03 juz ja posiadasz^x01 .");
				}
				case 25: odbierz(id);
			}
		}
		case MENU_PLAYER:
		{
			if (menuselected[id][0]==0) //User selected a badge
			{
				new name[30];
				get_user_name(key,name,29);
				new badge=menuselected[id][1];
				new level=menuselected[id][2];
				g_PlayerBadges[key][badge]=level;
				ColorChat(id,GREEN,"[BF4:MOD] %s^x01 odznaka zostala przyznana dla gracza^x03 %s",gBadgeName[badge][level],name);
				save_badges(key);
				DisplayHUD(key);
				
				client_cmd(id, "spk %s", gSoundBadge);
				
				new adminauthid[35];
				new awardauthid[35];
				get_user_authid (id,adminauthid,34);
				get_user_authid (key,awardauthid,34);

				log_amx("[BF4:MOD][ADMIN] Admin %s przyznal odznake %s graczowi %s",adminauthid,gBadgeName[badge][level],awardauthid);
			}
			else //Amount
			{
				new name[30];
				get_user_name(key,name,29);
				new amount=menuselected[id][0];
				diamenty[key]+=(amount * 5);
				
				if (amount == 1) {
					ColorChat(id,GREEN,"[BF4:MOD]^x01 Gracz:^x03 %s^x01 Otrzymal^x03 %d diamentow.",name,amount*5);
				} else {
					ColorChat(id,GREEN,"[BF4:MOD]^x01 Gracz:^x03 %s^x01 Otrzymal^x03 %d diamentow.",name,amount*5);
				}
				save_badges(key);
				DisplayHUD(key);
				
				new adminauthid[35];
				new awardauthid[35];
				get_user_authid (id,adminauthid,34);
				get_user_authid (key,awardauthid,34);
			}
		}
	}

   	menu_destroy(menu);
    
	return PLUGIN_HANDLED;
}
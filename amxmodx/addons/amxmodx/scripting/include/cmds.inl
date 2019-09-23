//Bf4 Rank Mod Commands File
//Contains all the client command functions

#if defined bf4_cmds_included
  #endinput
#endif
#define bf4_cmds_included

//Public menu / say commands. Help motds etc..
public show_rankhelp(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return;

	new tempstring[100];
	new motd[2048];
	new Float:xpmult=get_pcvar_float(gPcvarXpMultiplier);

	new kills;

	formatex(motd, charsmax(motd), "<html><body bgcolor='#474642'><font size='2' face='verdana' color='FFFFFF'><strong>");
	formatex(tempstring, charsmax(tempstring), "Rank Points Table</strong><br><br>");
	add(motd, charsmax(motd), tempstring);

	for (new counter = 0; counter < (MAX_RANKS-1); counter++)
	{
		kills = floatround(float(gRankXP[counter])*xpmult);
		formatex(tempstring, charsmax(tempstring), "%s - %d pts", gRankName[counter], kills);
		add(motd, charsmax(motd), tempstring);
		add(motd, charsmax(motd), "<br>");

		switch(counter)
		{
			case 7:
			{
				formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz %d Odznak *", gRankName[17], gRankName[7], MAX_BADGES);
				add(motd, charsmax(motd), tempstring);
				add(motd, charsmax(motd), "<br>");
			}
			case 8:
			{
				formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz %d Odznak *", gRankName[18], gRankName[8], MAX_BADGES*2);
				add(motd, charsmax(motd), tempstring);
				add(motd, charsmax(motd), "<br>");
			}
		}
	}

	formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz %d Odznak", gRankName[19], gRankName[15], MAX_BADGES*3);
	add(motd, charsmax(motd), tempstring);
	add(motd, charsmax(motd), "<br>");

	kills = floatround(float(gRankXP[MAX_RANKS-1])*xpmult);
	formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz %d Zabic", gRankName[16], gRankName[19], kills);
	add(motd, charsmax(motd), tempstring);
	add(motd, charsmax(motd), "<br>");

	formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz bycia Vice-Liderem rankingu", gRankName[20], gRankName[16]);
	add(motd, charsmax(motd), tempstring);
	add(motd, charsmax(motd), "<br>");
	
	formatex(tempstring, charsmax(tempstring), "%s - Wymagane %s oraz bycia Liderem rankingu", gRankName[21], gRankName[16]);
	add(motd, charsmax(motd), tempstring);
	add(motd, charsmax(motd), "<br>");

	add(motd, charsmax(motd), "<br> * Specjalne Rangi - Te informacje zostana pominiete jesli nie spelniasz odpowiednnich wymagan");
	add(motd, charsmax(motd), "</font></body></html>");

	show_motd(id, motd, "BF4:MOD - Wymagania Rang");

	Bf4menu(id);
}

public show_server_stats(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new tempstring[100];
	new motd[2048];
	new names[4][32];

	get_user_name(highestrankid, names[0], charsmax(names[]));

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642'><font size='2' face='verdana' color='FFFFFF'><strong>");
	formatex(tempstring,charsmax(tempstring),"<u>Obecne Statystyki</u></strong><br>");
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<b>Najwyzsza Ranga:</b> %s %s<br><br>",gRankName[highestrank],names[0]);
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<strong><u>Statystyki Serwera</u></strong><br>");
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<b>Najwyzsza Ranga:</b> %s %s<br>", gRankName[highestrankserver], highestrankservername);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Najwiecej Zabic:</b> %s %i<br>",mostkillsname,mostkills);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Najwiecej Zwyciestw:</b> %s %i<br>",mostwinsname,mostwins);
	add(motd,charsmax(motd),tempstring);
	add(motd,charsmax(motd),"</font></body></html>");

	show_motd(id,motd,"BF4:MOD - Statystki Serwera");

	Bf4menu(id);

	return PLUGIN_CONTINUE;
}

public show_server_config(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new tempstring[100];
	new motd[2048];
	new names[4][32];

	get_user_name(highestrankid, names[0], charsmax(names[]));

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642' style='color:#fff'><font size='2' face='verdana'>");
	
	formatex(tempstring,charsmax(tempstring),"<b>Konfiguracja serwera:</b><br><br>");
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<table style='font-size:12px;' style='width:500px'><tr><td style='width:250px'>");
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"Walka Nozem: %d<br>",get_pcvar_num(gPcvarPower1));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Pistoletem: %d<br>",get_pcvar_num(gPcvarPower2));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Bronia Szturmowa: %d<br>",get_pcvar_num(gPcvarPower3));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Bronia Snajperska: %d<br>",get_pcvar_num(gPcvarPower4));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Bronia Wsparcia: %d<br>",get_pcvar_num(gPcvarPower5));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Granatami: %d<br>",get_pcvar_num(gPcvarPower6));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Strzelba: %d<br>",get_pcvar_num(gPcvarPower7));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka SMG: %d<br>",get_pcvar_num(gPcvarPower8));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Celnosciowa: %d<br>",get_pcvar_num(gPcvarPower9));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Ogolna: %d<br>",get_pcvar_num(gPcvarPower10));
	add(motd,charsmax(motd),tempstring);formatex(tempstring,charsmax(tempstring),"Walka Powstanca: %d<br>",get_pcvar_num(gPcvarPower11));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Pirotechnika: %d<br>",get_pcvar_num(gPcvarPower12));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Medal: %d<br>",get_pcvar_num(gPcvarPower13));
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"</td><td style='width:250px'>");
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"Walka na Staz: %d<br>",get_pcvar_num(gPcvarPower14));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Osiagniecia: %d<br>",get_pcvar_num(gPcvarPower15));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Odznaczenia: %d<br>",get_pcvar_num(gPcvarPower16));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Miny: %d<br>",get_pcvar_num(gPcvarPower17));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Uniwersalna: %d<br>",get_pcvar_num(gPcvarPower18));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka Mieszana: %d<br>",get_pcvar_num(gPcvarPower19));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Czas: %d<br>",get_pcvar_num(gPcvarPower20));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Zbieranie: %d<br>",get_pcvar_num(gPcvarPower21));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Spowolnienie: %d<br>",get_pcvar_num(gPcvarPower22));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Podswietlenie: %d<br>",get_pcvar_num(gPcvarPower23));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Zgony: %d<br>",get_pcvar_num(gPcvarPower24));
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"Walka na Polaczenia: %d<br>",get_pcvar_num(gPcvarPower25));
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"</td></tr></table><br>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Legenda:</b><br>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"1 = Wlaczona; 0 = Wylaczaona<br>");
	add(motd,charsmax(motd),tempstring);
	
	add(motd,charsmax(motd),"</font></body></html>");

	show_motd(id,motd,"BF4:MOD - Statystki Serwera");

	Bf4menu(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/1.html",configsdir);	
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/1.html",url);
	}
	show_motd(id, configfile, "BF4:MOD: Odznaka - Pomoc 1");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp2(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/2.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/2.html",url);
	}

	show_motd(id, configfile, "BF4: Odznaka - Pomoc 2");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp3(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/3.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/3.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 3");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp4(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/4.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/4.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 4");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp5(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/5.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/5.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 5");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp6(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/6.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/6.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 6");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp7(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/7.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/7.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 7");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp8(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/8.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/8.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 8");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp9(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/9.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/9.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 9");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp10(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/10.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/10.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 10");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp11(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/11.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/11.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 11");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp12(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/12.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/12.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 12");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp13(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/13.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/13.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 13");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp14(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/14.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/14.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 14");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp15(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/15.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/15.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 15");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp16(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/16.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/16.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 16");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp17(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/17.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/17.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 17");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp18(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/18.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/18.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 18");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp19(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/19.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/19.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 19");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp20(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/20.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/20.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 20");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp21(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/21.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/21.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 21");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp22(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/22.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/22.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 22");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp23(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/23.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/23.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 23");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp24(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/24.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/24.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 24");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_badgehelp25(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/25.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/25.html",url);
	}

	show_motd(id, configfile, "Odznaka - Pomoc 25");

	odznaki(id);

	return PLUGIN_CONTINUE;
}

public show_medale(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/medalshelp.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/medalshelp.html",url);
	}

	show_motd(id, configfile, "Medale");

	helpmenu(id);

	return PLUGIN_CONTINUE;
}

public show_osiagniecia(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/osiagniecia.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/osiagniecia.html",url);
	}

	show_motd(id, configfile, "Osiagniecia 1 - Pomoc");

	helpmenu(id);

	return PLUGIN_CONTINUE;
}

public show_osiagniecia2(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/osiagniecia2.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/osiagniecia2.html",url);
	}

	show_motd(id, configfile, "Osiagniecia 2 - Pomoc");

	helpmenu(id);

	return PLUGIN_CONTINUE;
}

public show_osiagniecia3(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/osiagniecia3.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/osiagniecia3.html",url);
	}

	show_motd(id, configfile, "Osiagniecia 3 - Pomoc");

	helpmenu(id);

	return PLUGIN_CONTINUE;
}

public cmd_say(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new Arg1[31];
	read_args(Arg1, charsmax(Arg1));
	remove_quotes(Arg1);

	if (!((equal(Arg1, "/whois",6)) || (equal(Arg1, "/whoreach",6)) || (equal(Arg1, "/whostats",6))))
		return PLUGIN_CONTINUE;

	if (equal(Arg1, "/whostats",6))
	{
		new player = cmd_target(id, Arg1[10], 0);
		if (!player)
		{
			ColorChat(id,GREEN,"[BF4:MOD]^x03 Przepraszamy, gracz^x04 %s^x03 nie moze zostac zlokalizowany!",Arg1[10]);
			return PLUGIN_CONTINUE;
		}

		display_stats_general(id,player);

		return PLUGIN_CONTINUE;
	}
	
	if (equal(Arg1, "/whoreach",6))
	{
		new player = cmd_target(id, Arg1[10], 0);
		if (!player)
		{
			ColorChat(id,GREEN,"[BF4:MOD]^x03 Przepraszamy, gracz^x04 %s^x03 nie moze zostac zlokalizowany!",Arg1[10]);
			return PLUGIN_CONTINUE;
		}

		display_reach(id,player);

		return PLUGIN_CONTINUE;
	}

	new player = cmd_target(id, Arg1[7], 0);

	if (!player)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x03 Przepraszamy, gracz^x04 %s^x03 nie moze zostac zlokalizowany!",Arg1[7]);
		return PLUGIN_CONTINUE;
	}

	display_badges(id,player);

	return PLUGIN_CONTINUE;
}

public display_badges(id,badgeid)
{
	new name[32];
	get_user_name(badgeid,name,charsmax(name));

	new tempstring[100];
	new motd[2048];

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642'><font size='2' face='verdana' color='FFFFFF'>");
	formatex(tempstring,charsmax(tempstring),"<strong>Gracz:</strong> %s %s", gRankName[g_PlayerRank[badgeid]], name);
	add(motd,charsmax(motd),tempstring);
	add(motd,charsmax(motd),"<br><br>");

	if (!get_pcvar_num(gPcvarBadgesActive))
	{
		add(motd,charsmax(motd),"</font></body></html>");
		show_motd(id,motd,"BF4: Informacje o Graczu");

		return PLUGIN_CONTINUE;
	}

	formatex(tempstring,charsmax(tempstring),"<b>Zdobyte Odznaki:</b> %d/100<br>", numofbadges[badgeid]);
	add(motd,charsmax(motd),tempstring);

	for (new counter=0; counter<MAX_BADGES; counter++)
	{
		if(g_PlayerBadges[badgeid][counter]!=0)
		{
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; %s<br>",gBadgeName[counter][g_PlayerBadges[badgeid][counter]]);
			add(motd,charsmax(motd),tempstring);
		}
	}

	add(motd,charsmax(motd),"</font></body></html>");

	show_motd(id,motd,"BF4:MOD - Informacje o Graczu");

	Bf4menu(id);

 	return PLUGIN_CONTINUE;
}

public cmd_who(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new tempstring[100],players[32],num,tempname[32];
	new motd[2048];

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642'><font size='2' face='verdana' color='FFFFFF'><strong><b>Ranking Graczy</strong></b><br><br>");

	get_players(players,num);

	for (new counter=0; counter<num; counter++)
	{
		get_user_name(players[counter], tempname, charsmax(tempname));
		formatex(tempstring,charsmax(tempstring),"%s - %s<br/>",tempname,gRankName[g_PlayerRank[players[counter]]]);
		add(motd,charsmax(motd),tempstring);

	}
	add(motd,charsmax(motd),"</font></body></html>");

	show_motd(id,motd,"BF4:MOD - Ranking Graczy");

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public cmd_help(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	new url[100];
	get_pcvar_string(gPcvarHelpUrl,url,charsmax(url));

	if (equal(url,""))
	{
		formatex(configfile,charsmax(configfile),"%s/bf4/help.html",configsdir);
	}
	else
	{
		formatex(configfile,charsmax(configfile),"%s/helpweb.html",url);
	}

	show_motd(id, configfile, "BF4: Pomoc");

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public show_stats_reach(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	display_reach(id,id);

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public show_stats_general(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	display_stats_general(id,id);

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public show_stats(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	display_stats(id,id);

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public show_stats_second(id)
{
	if (!get_pcvar_num(gPcvarBF4Active))
		return PLUGIN_CONTINUE;

	display_stats_second(id,id);

	Bf4menu(id);

	return PLUGIN_CONTINUE;

}

public display_stats_general(id,statsid)
{
	new tempstring[100];
	new motd[2048];
	new stats[8],bodyhits[8];
	new ranked=get_user_stats(statsid, stats, bodyhits);
	new tempname[32];
	get_user_name(statsid,tempname,charsmax(tempname));
	
	new reach = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]+reach21[id]+reach22[id]+reach23[id]+reach24[id]+reach25[id]);
	
	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642' style='font-size:10px;font-family:Verdana;color:#fff;'><table><tr><td width='250px' valign='top'>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<font size='2'><b>Gracz:</b> %s<br>", tempname);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Czas online:</b> %d min<br><br>",onlinemin[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Zabicia:</b> %d<br>", totalkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Nozem:</b> %d<br>", knifekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Pistoletami:</b> %d<br>",pistolkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Karabinami:</b> %d<br>",riflekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Snajperkami:</b> %d<br><br>",sniperkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Zabicia mina:</b> %d<br><br>",minakills[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Obrazenia:</b><br><small>&#187; Zadane: %d<br>",dmgrec[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Otrzymane: %d</small><br><br>",dmgask[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Bomby:</b><br><small>&#187; Podlozone: %d<br>",plants[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Wybuchniete: %d<br>",explosions[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Rozbrojone: %d</small><br>",defuses[statsid]);
	add(motd,charsmax(motd),tempstring);	
	
	formatex(tempstring,charsmax(tempstring),"</td><td valign='top' width='250px'><font size='2'>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Ranking:</b> #%d<br>",ranked);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Osiagniecia:</b> %d/18<br><br>",reach);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Zgony:</b> %d<br>", totaldeath[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>M249:</b> %d<br>", parakills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>SMG:</b> %d<br>",smgkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Strzelbami:</b> %d<br>",shotgunkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Granatami:</b> %d<br><br>", grenadekills[statsid]);
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<b>Zginiecia mina:</b> %d<br><br>",minadeath[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Strzaly:</b><br><small>&#187; Trafione: %d<br>",shotsrec[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Celnosc: %d procent</small><br><br>",accuracy[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Medale:<br></b><small>&#187; Zloty: %d<br>",gold[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Srebrny: %d<br>",silver[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Brazowy: %d<br></small>",bronze[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"</td></tr></table></body></html>");
	add(motd,charsmax(motd),tempstring);

	show_motd(id,motd,"BF4: Statystyki Gracza - Ogolne");

}

public display_stats(id,statsid)
{
	new tempstring[100];
	new motd[2048];
	new tempname[32];
	get_user_name(statsid,tempname,charsmax(tempname));
	new stats[8],bodyhits[8];
	new ranked=get_user_stats(statsid, stats, bodyhits);

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642' style='font-family:Verdana;color:#fff;'><table><tr><td width='250px' valign='top'>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<font size='2'><b>Gracz:</b> %s<br><br>", tempname);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Zabicia:</b> %d<br>", totalkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Nozem:</b> %d<br>", knifekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Granatami:</b> %d<br>", grenadekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Pistoletami:</b> %d<br>",pistolkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<small>&#187; USP: %d<br>",uspkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Glock: %d<br>",glockkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Desert: %d<br>",deaglekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; P228: %d<br>",p228kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Five Seven: %d<br>",fivesevenkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Elite: %d</small><br>",elitekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Karabinami:</b> %d<br>",riflekills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<small>&#187; AUG: %d<br>",augkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; SG552: %d<br>",sg552kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Gall: %d<br>",gallkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Famas: %d<br>",famaskills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; M4A1: %d<br>",m4a1kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; AK-47: %d</small><br>",ak47kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"</td><td valign='top' width='250px'><font size='2'>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Ranking:</b> #%d<br><br>",ranked);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Czas online:</b> %d min<br>",onlinemin[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Zgony:</b> %d<br>", totaldeath[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>M249:</b> %d<br>", parakills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Snajperkami:</b> %d<br>",sniperkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<small>&#187; AWP: %d<br>",awpkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Scout: %d<br>",scoutkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; G3SG1: %d<br>",g3sg1kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; SG550: %d</small><br>",sg550kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>SMG:</b> %d<br>",smgkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<small>&#187; TMP: %d<br>",tmpkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; MAC10: %d<br>",mackills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; MP5: %d<br>",mp5kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; P90: %d<br>",p90kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; UMP45: %d</small><br>",umpkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Strzelbami:</b> %d<br>",shotgunkills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<small>&#187; XM1014: %d<br>",xm1014kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; M3: %d</small><br>",m3kills[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"</td></tr></table></body></html>");
	add(motd,charsmax(motd),tempstring);

	show_motd(id,motd,"BF4: Statystyki Gracza - 1");

}

public display_stats_second(id,statsid)
{
	new tempstring[100];
	new motd[2048];
	new stats[8],bodyhits[8];
	new ranked=get_user_stats(statsid, stats, bodyhits);
	new tempname[32];
	get_user_name(statsid,tempname,charsmax(tempname));

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642' style='font-size:10px;font-family:Verdana;color:#fff;'><table><tr><td width='250px' valign='top'>");
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<font size='2'><b>Gracz:</b> %s<br><br>", tempname);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Zebrana kasa:</b> %d USD<br>",collectedcash[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Podniesionych paczek:</b> %d<br>",padlino[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Zabicia mina:</b> %d<br><br>",minakills[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Obrazenia:</b><br><small>&#187; Zadane: %d<br>",dmgrec[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Otrzymane: %d</small><br><br>",dmgask[statsid]);
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<b>Bomby:</b><br><small>&#187; Podlozone: %d<br>",plants[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Wybuchniete: %d<br>",explosions[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Rozbrojone: %d</small><br>",defuses[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"</td><td valign='top' width='250px'><font size='2'>");
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Ranking:</b> #%d<br><br>",ranked);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Przezyte rundy:</b> %d<br>",livedround[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"<b>Polaczen z serwerem:</b> %d<br>",connects[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Zginiecia mina:</b> %d<br><br>",minadeath[statsid]);
	add(motd,charsmax(motd),tempstring);

	formatex(tempstring,charsmax(tempstring),"<b>Strzaly:</b><br><small>&#187; Trafione: %d<br>",shotsrec[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Celnosc: %d procent</small><br><br>",accuracy[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"<b>Medale:<br></b><small>&#187; Zloty: %d<br>",gold[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Srebrny: %d<br>",silver[statsid]);
	add(motd,charsmax(motd),tempstring);
	formatex(tempstring,charsmax(tempstring),"&#187; Brazowy: %d<br></small>",bronze[statsid]);
	add(motd,charsmax(motd),tempstring);
	
	formatex(tempstring,charsmax(tempstring),"</td></tr></table></body></html>");
	add(motd,charsmax(motd),tempstring);

	show_motd(id,motd,"BF4: Statystyki Gracza - 2");
	
}

public display_reach(id,statsid)
{
	new tempname[32];
	get_user_name(id,tempname,charsmax(tempname));
	
	new reach = (reach1[id]+reach2[id]+reach3[id]+reach4[id]+reach5[id]+reach6[id]+reach7[id]+reach8[id]+reach9[id]+reach10[id]+reach11[id]+reach12[id]+reach13[id]+reach14[id]+reach15[id]+reach16[id]+reach17[id]+reach18[id]+reach19[id]+reach20[id]+reach21[id]+reach22[id]+reach23[id]+reach24[id]+reach25[id]);
	
	new tempstring[100];
	new motd[2048];

	formatex(motd,charsmax(motd),"<html><body bgcolor='#474642' style='font-size:10px;font-family:Verdana;color:#fff;'><font size='2' face='verdana' color='FFFFFF'><strong><b>");
	formatex(tempstring,charsmax(tempstring),"Statystyki diamentow i osiagniec gracza</strong> %s</b>", tempname);
	add(motd,charsmax(motd),tempstring);
	add(motd,charsmax(motd),"<br><br>");

	
	formatex(tempstring,charsmax(tempstring),"<b>Zdobyte Osiagniecia:</b> %d/20",reach);
	add(motd,charsmax(motd),tempstring);
	add(motd,charsmax(motd),"<br>");

	switch(reach1[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Goraca Sprawa");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach2[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Polowanie");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach3[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Najwyzsza Ofiara");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach4[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Szybki i Zabojczy");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach5[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Chodzacy Magazynier");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach6[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Wielki Gong");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach7[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Wzorowa Sluzba");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach8[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Cicha Przemoc");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach9[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Celne Strzaly");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach10[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Az do Klikniecia");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach11[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Lowca Okazji");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach12[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Prawdziwe Wyzwanie");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach13[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Milioner");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach14[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Incognito");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach15[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Krolewska Gra");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach16[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Niezniszczalny");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach17[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Saper");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach18[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Nieudacznik");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach19[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Padlinozerca");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	switch(reach20[id]){
		case 1: {
			formatex(tempstring,charsmax(tempstring),"&nbsp;&#187; Osiagniecie Bywalec");
			add(motd,charsmax(motd),tempstring);
			add(motd,charsmax(motd),"<br>");
		}
	}
	
	formatex(tempstring,charsmax(tempstring),"</body></html>");
	add(motd,charsmax(motd),tempstring);

	show_motd(id,motd,"BF4:MOD - Informacje o Graczu");
	
}
	
//Admin only commands below here


//Gives badge to specified player
public add_badge(id,level,cid)
{
	if (!cmd_access(id, level, cid, 4)) return PLUGIN_HANDLED;

	new Arg1[24];
	new Arg2[4];
	new Arg3[4];


	read_argv(1, Arg1, charsmax(Arg1));
	read_argv(2, Arg2, charsmax(Arg2));
	read_argv(3, Arg3, charsmax(Arg3));

	new badge = str_to_num(Arg2);
	new level = str_to_num(Arg3);

	new player = cmd_target(id, Arg1, 0);

	if (!player || (level>4) || (level<0) || (badge>24) || (badge<0))
        {
			console_print(id, "Przepraszamy, gracz %s nie moze zostac zlokalizowany! lub bledna odznaka/poziom", Arg1);
			return PLUGIN_HANDLED;
	} else {
			g_PlayerBadges[player][badge]=level;
			ColorChat(id,GREEN,"[BF4:MOD]^x03 %s^x01 odznaka zostala przyznana graczowi^x04 %s",gBadgeName[badge][level],Arg1);
			save_badges(player);
			DisplayHUD(player);
        }

	new adminauthid[35];
	new awardauthid[35];
	get_user_authid (id,adminauthid,charsmax(adminauthid));
	get_user_authid (player,awardauthid,charsmax(awardauthid));

	log_amx("[BF4:MOD][ADMIN]Admin %s przyznal odznake %s graczowi %s",adminauthid,gBadgeName[badge][level],awardauthid);

	return PLUGIN_HANDLED;
}

public add_allbadge(id,level,cid)
{
	if (!cmd_access(id, level, cid, 3))
        	return PLUGIN_HANDLED;

     	new Arg1[24];
     	new Arg2[6];

     	read_argv(1, Arg1, charsmax(Arg1));
     	read_argv(2, Arg2, charsmax(Arg2));

     	new poziom = str_to_num(Arg2);

	new player = cmd_target(id, Arg1, 0);

	if (!player || (poziom>4) || (poziom<0))
        {
			console_print(id, "Przepraszamy, gracz %s nie moze zostac zlokalizowany!", Arg1);
			return PLUGIN_HANDLED;
        } else {
			g_PlayerBadges[player][BADGE_NUMBER1]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER2]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER3]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER4]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER5]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER6]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER7]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER8]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER9]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER10]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER11]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER12]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER13]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER14]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER15]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER16]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER17]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER18]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER19]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER20]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER21]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER22]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER23]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER24]=poziom;
			g_PlayerBadges[player][BADGE_NUMBER25]=poziom;	
		
			ColorChat(id,GREEN,"[BF4:MOD]^x03 Wszystkie odznaki^x01 zostaly przyznane graczowi^x04 %s",Arg1);
			save_badges(player);
			DisplayHUD(player);
        }

	new adminauthid[35];
	new awardauthid[35];
	get_user_authid (id,adminauthid,charsmax(adminauthid));
	get_user_authid (player,awardauthid,charsmax(awardauthid));

	log_amx("[BF4:MOD][ADMIN]Admin %s przyznal wszystkie odznaki graczowi %s",adminauthid,awardauthid);

	return PLUGIN_HANDLED;
}

//Gives kills to specified player
public add_kills(id,level,cid)
{
	if (!cmd_access(id, level, cid, 3))
        	return PLUGIN_HANDLED;

     	new Arg1[24];
     	new Arg2[6];

     	read_argv(1, Arg1, charsmax(Arg1));
     	read_argv(2, Arg2, charsmax(Arg2));

     	new kills = str_to_num(Arg2);

	new player = cmd_target(id, Arg1, 0);

	if (!player)
        {
			console_print(id, "Przepraszamy, gracz %s nie moze zostac zlokalizowany!", Arg1);
			return PLUGIN_HANDLED;
        } else {
			totalkills[player]+=kills;
			ColorChat(id,GREEN,"[BF4:MOD]^x03 %s^x01 fragi zostaly przyznane dla gracza^x04 %s",kills,Arg1);
			save_badges(player);
			DisplayHUD(player);
        }

	new adminauthid[35];
	new awardauthid[35];
	get_user_authid(id,adminauthid,charsmax(adminauthid));
	get_user_authid(player,awardauthid,charsmax(awardauthid));

	log_amx("[BF4:MOD][ADMIN]Admin %s przyznal %i fragow dla gracza %s",adminauthid,kills,awardauthid);

	return PLUGIN_HANDLED;
}

//Gives diamonds to specified player
public add_diamonds(id,level,cid)
{
	if (!cmd_access(id, level, cid, 3))
        	return PLUGIN_HANDLED;

     	new Arg1[24];
     	new Arg2[6];

     	read_argv(1, Arg1, charsmax(Arg1));
     	read_argv(2, Arg2, charsmax(Arg2));

     	new ilosc = str_to_num(Arg2);

	new player = cmd_target(id, Arg1, 0);

	if (!player)
        {
			console_print(id, "Przepraszamy, gracz %s nie moze zostac zlokalizowany!", Arg1);
			return PLUGIN_HANDLED;
        } else {
			diamenty[player]+=ilosc;
			ColorChat(id,GREEN,"[BF4:MOD]^x03 %s^x01 diamenty zostaly przyznane dla gracza^x04 %s",ilosc,Arg1);
			save_badges(player);
			DisplayHUD(player);
        }

	new adminauthid[35];
	new awardauthid[35];
	get_user_authid(id,adminauthid,charsmax(adminauthid));
	get_user_authid(player,awardauthid,charsmax(awardauthid));

	log_amx("[BF4:MOD][ADMIN]Admin %s przyznal %i diamentow dla gracza %s",adminauthid,ilosc,awardauthid);

	return PLUGIN_HANDLED;
}
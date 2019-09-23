#if defined give_included
#endinput
#endif
#define give_included

public cmd_diament(id)
{
	new msg[128]
	read_args(msg, 127) 
	remove_quotes(msg)
	
	new arg1[10], arg2[36], arg3[5]
	parse(msg, arg1, 9, arg2, 35, arg3, 4) 

	if (!equal(arg1, "/wyslij") && !equal(arg1, "wyslij"))
		return PLUGIN_CONTINUE

	if ( !get_pcvar_num(gPcvarGiveActive) )
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Przesylanie diamentow jest wylaczone.")
		return PLUGIN_HANDLED
	}
	
	if (strlen(arg2)==0)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Musisz podac komu chcesz dac diament.")
		return PLUGIN_HANDLED
	}
	
	new danydiament = str_to_num(arg3)
	new odbierze = znajdz_gracza(arg2)
	
	if (odbierze <= 0)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Nie znaleziono gracza.")
		return PLUGIN_HANDLED
	}
	
	if (odbierze == id)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Nie mozesz dac diamentow samemu sobie.")
		return PLUGIN_HANDLED
	}
	
	if (danydiament <= 0)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Musisz podac dodatnia liczbe diamentow jaka chcesz przekazac")
		return PLUGIN_HANDLED
	}
	
	new MojeDiamenty = diamenty[id]
	
	if (MojeDiamenty < danydiament)
	{
		ColorChat(id,GREEN,"[BF4:MOD]^x01 Nie masz wystarczajacej liczby diamentow")
		return PLUGIN_HANDLED
	}
	
	diamenty[id]-=danydiament
	diamenty[odbierze]+=danydiament
	
	new Dajacy[33], Odbiorca[33]
	get_user_name(id, Dajacy, 32)
	get_user_name(odbierze, Odbiorca, 32)
	
	ColorChat(id,GREEN,"[BF4:MOD]^x01 Gracz ^x03%s^x01 przekazal ^x04%d diamentow^x01 graczowi ^x03%s^x01.", Dajacy, danydiament, Odbiorca)
	
	log_amx("[BF4:MOD] Gracz %s przekazal %d diamentow graczowi %s",Dajacy,danydiament,Odbiorca);
	
	return PLUGIN_HANDLED
}


stock znajdz_gracza(str[])
{
	if (strlen(str)==0)
		return -1
	
	new player = find_player("c", str) //authid

	if (!player) {
		player = find_player("bl", str) //name, ignore case
	}

	if (!player) {
		player = find_player("d", str) //ip
	}

	if ( !player && str[0]=='#' && str[1] ) {
		player = find_player("k", str_to_num(str[1])) //userid
	}
	
	if (player)
		return player
	
	return -1
}
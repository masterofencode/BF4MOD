# BF4MOD
1. Wgraj wszystkie pliki z folderu AMXX na serwer.

2. Dopisz do plugins.ini:

BF4Mod_Silnik.amxx // Silnik BF4Mod

BF4Mod_Reanimacja.amxx // Reanimacja, wymagany włączony silnik BF4Mod

BF4Mod_Zadania.amxx // Zadania, wymagany włączony silnik BF4Mod

BF4Mod_VIP.amxx // Specjalny vip pod silnik BF4Mod


3. Wejdź w amxx.cfg i zmien "csstats_rank 1" na "csstats_rank 0" (zmiana zapisu z IP na nick).

4. Ustawienia misji:

	Opis:
	W modzie Bf4 Mod nie ma limitu zadań. Możesz ich nie robić w cale lub zrobić 100 i więcej.
	Standardowo jest zrobione 25 zadań. Możesz je dobrowolnie edytować.
	
	
	
	Wzór:
	"misja" "wymaganie" "typ" "nagroda"
	

	Typy misji:
	1 - zabic
	
	2 - zabic nozem
	
	3 - zabic pistoletem
	
	4 - zabic z SMG
	
	5 - zabic strzelba
	
	6 - zabic karabinem
	
	7 - zabic snajperka
	
	8 - zabic z M249
	
	9 - zabic granatem
	
	10 - zadanych obrazen
	
	11 - podlozonych bomb
	
	12 - rozbrojonych bomb
	
	13 - uratowanych hostow
	

	Przykład:
	
	"1" "5" "2" "12" // Misja: 1 Wymaganie: 5 zabić nożem Nagroda: 12 diamentow.
	
	"2" "3" "5" "2" // Misja: 2 Wymaganie: 3 zabić strzelba Nagroda: 2 diamenty.
	


5. Zalecane jest wgranie pluginu, który blokuje możliwość zmiany nicku podczas gry.


6. Przydatne komenty.

	bf4_dajodznake nick numer poziom	// Komenda do dawania odznak 0-19, poziom 0-4
	
	bf4_dajodznaki nick poziom			// Komenda do dawania wszystkich odznak, poziom 0-4
	
	bf4_dajzabicia nick ilosc 			// Komenda do dawania zabić ogólnych
	
	bf4_dajdiamenty nick ilosc 			// Komenda do dawania diamentów
	

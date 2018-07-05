#pragma once
#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

static const int BIALY_PIONEK = 1;
static const int BIALY_DAMKA = 2;
static const int PUSTE = 0;
static const int CZARNY_PIONEK = -1;
static const int CZARNY_DAMKA = -2;

class Plansza{

private:

	int** plansza_glowna;
	bool gracz1Komputer;
	bool gracz2Komputer;

	int czyjRuch;

public:

	Plansza();//Konstruktor tworzy plansza_glowna, na ktorej bedzie toczona rozgrywka
	~Plansza();

	void LosujGraczaZaczynajacego();
	void UstaPozycjeStartowe();
	void UstawGraczy(bool gracz1, bool gracz2);//Do wyboru kto gra

	bool CzyKoniec(int** plansza);//Sprawdza czy gracze maja jeszcze pionki

	void Graj();
	void Rysuj();
	int** GetPlanszaGlowna();//do zwracania planszy glownej = MAIN

private:
	bool CzyRuchMozliwy(int sourceX, int sourceY, int destX, int destY,int** plansza);
	int WykonajRuch(int sourceX, int sourceY, int destX, int destY,int** plansza);
	bool CzyPionekMaBicie(int sourceX, int sourceY,int** plansza);

	void RuchKomputera();
	void RuchCzlowieka();
	int LiczStraty(int** kopia);
	
};


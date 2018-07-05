#include<iostream>
#include "Plansza.h"

using namespace std;


int main() {
	Plansza* p = new Plansza();
	p->UstaPozycjeStartowe();
	p->UstawGraczy(false,true);
	p->LosujGraczaZaczynajacego();

	while (!p->CzyKoniec(p->GetPlanszaGlowna())) {
		system("cls");
		p->Rysuj();
		Sleep(500);
		p->Graj();
		system("cls");
		p->Rysuj();
		Sleep(500);
	}

	system("cls");
	p->Rysuj();

	
	system("pause");
	return 0;
}
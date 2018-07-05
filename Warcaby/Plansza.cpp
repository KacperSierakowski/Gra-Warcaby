#include "Plansza.h"



Plansza::Plansza(){
	plansza_glowna = new int*[8];
	for (int i = 0; i < 8; i++) {
		plansza_glowna[i] = new int[8];
	}
	czyjRuch = 1;
}


Plansza::~Plansza()
{
	for (int i = 0; i < 8; i++) {
		delete[] plansza_glowna[i];
	}
	delete[] plansza_glowna;
}

bool Plansza::CzyRuchMozliwy(int sourceX,int sourceY,int destX,int destY,int** plansza) {
	if (czyjRuch == 1) {
		if (plansza[sourceY][sourceX] == BIALY_PIONEK) {
			if (CzyPionekMaBicie(sourceX, sourceY,plansza)) {
				//bicie lewo gora
				if (sourceX >= 2 && sourceY >= 2) {
					if (plansza[sourceY - 1][sourceX - 1] == CZARNY_PIONEK || plansza[sourceY - 1][sourceX - 1] == CZARNY_DAMKA) {
						if (plansza[sourceY - 2][sourceX - 2] == PUSTE) {
							if (destX == (sourceX - 2) && destY == (sourceY - 2)) {
								return true;
							}
						}
					}
				}
				//biecie lewo dol
				if (sourceX >= 2 && sourceY <= 5) {
					if (plansza[sourceY + 1][sourceX - 1] == CZARNY_PIONEK || plansza[sourceY + 1][sourceX - 1] == CZARNY_DAMKA) {
						if (plansza[sourceY + 2][sourceX - 2] == PUSTE) {
							if (destX == (sourceX - 2) && destY == (sourceY + 2)) {
								return true;
							}
						}
					}
				}
				//bicie prawo gora
				if (sourceX <= 5 && sourceY >= 2) {
					if (plansza[sourceY - 1][sourceX + 1] == CZARNY_PIONEK || plansza[sourceY - 1][sourceX + 1] == CZARNY_DAMKA) {
						if (plansza[sourceY - 2][sourceX + 2] == PUSTE) {
							if (destX == (sourceX + 2) && destY == (sourceY - 2)) {
								return true;
							}
						}
					}
				}
				//bicie prawo dol
				if (sourceX <= 5 && sourceY <= 5) {
					if (plansza[sourceY + 1][sourceX + 1] == CZARNY_PIONEK || plansza[sourceY + 1][sourceX + 1] == CZARNY_DAMKA) {
						if (plansza[sourceY + 2][sourceX + 2] == PUSTE) {
							if (destX == (sourceX + 2) && destY == (sourceY + 2)) {
								return true;
							}
						}
					}
				}
			}
			else {
				if (destX == (sourceX  - 1) && destY == (sourceY +1 )){
					if (plansza[destY][destX] == PUSTE) {
						return true;
					}
				}
				else if (destX == (sourceX +1) && destY == (sourceY +1)) {
					if (plansza[destY][destX] == PUSTE) {
						return true;
					}
				}
			}
		}else if (plansza[sourceY][sourceX] == BIALY_DAMKA) {
		//do zrobienia
		}
		else {
			return false;
		}
	}
	else if (czyjRuch == 2) {
		if (plansza[sourceY][sourceX] == CZARNY_PIONEK) {
			if (CzyPionekMaBicie(sourceX, sourceY,plansza)) {
				//bicie lewo gora
				if (sourceX >= 2 && sourceY >= 2) {
					if (plansza[sourceY - 1][sourceX - 1] ==  BIALY_PIONEK || plansza[sourceY - 1][sourceX - 1] == BIALY_DAMKA) {
						if (plansza[sourceY - 2][sourceX - 2] == PUSTE) {
							if (destX == (sourceX - 2) && destY == (sourceY - 2)) {
								return true;
							}
						}
					}
				}
				//biecie lewo dol
				if (sourceX >= 2 && sourceY <= 5) {
					if (plansza[sourceY + 1][sourceX - 1] == BIALY_PIONEK || plansza[sourceY + 1][sourceX - 1] == BIALY_DAMKA) {
						if (plansza[sourceY + 2][sourceX - 2] == PUSTE) {
							if (destX == (sourceX - 2) && destY == (sourceY + 2)) {
								return true;
							}
						}
					}
				}
				//bicie prawo gora
				if (sourceX <= 5 && sourceY >= 2) {
					if (plansza[sourceY - 1][sourceX + 1] == BIALY_PIONEK || plansza[sourceY - 1][sourceX + 1] == BIALY_DAMKA) {
						if (plansza[sourceY - 2][sourceX + 2] == PUSTE) {
							if (destX == (sourceX + 2) && destY == (sourceY - 2)) {
								return true;
							}
						}
					}
				}
				//bicie prawo dol
				if (sourceX <= 5 && sourceY <= 5) {
					if (plansza[sourceY + 1][sourceX + 1] == BIALY_PIONEK || plansza[sourceY + 1][sourceX + 1] == BIALY_DAMKA) {
						if (plansza[sourceY + 2][sourceX + 2] == PUSTE) {
							if (destX == (sourceX + 2) && destY == (sourceY + 2)) {
								return true;
							}
						}
					}
				}
			}
			else {
				if (destX == (sourceX - 1) && destY == (sourceY - 1)) {
					if (plansza[destY][destX] == PUSTE) {
						return true;
					}
				}
				else if (destX == (sourceX + 1) && destY == (sourceY - 1)) {
					if (plansza[destY][destX] == PUSTE) {
						return true;
					}
				}
			}
		}
		else if (plansza[sourceY][sourceX] == CZARNY_DAMKA) {
			//do zrobienia
		}
		else {
			return false;
		}
	}
	return false;
}

bool Plansza::CzyPionekMaBicie(int sourceX, int sourceY,int** plansza) {
	if (czyjRuch == 1) {
		if (plansza[sourceY][sourceX] == BIALY_PIONEK) {
			//bicie lewo gora
			if (sourceX >= 2 && sourceY >= 2) {
				if (plansza[sourceY - 1][sourceX - 1] == CZARNY_PIONEK || plansza[sourceY - 1][sourceX - 1] == CZARNY_DAMKA) {
					if (plansza[sourceY - 2][sourceX - 2] == PUSTE) {
						return true;
					}
				}
			}
			//biecie lewo dol
			if (sourceX >= 2 && sourceY <= 5) {
				if (plansza[sourceY + 1][sourceX - 1] == CZARNY_PIONEK || plansza[sourceY + 1][sourceX - 1] == CZARNY_DAMKA) {
					if (plansza[sourceY + 2][sourceX - 2] == PUSTE) {
						return true;
					}
				}
			}
			//bicie prawo gora
			if (sourceX <= 5 && sourceY >= 2) {
				if (plansza[sourceY - 1][sourceX + 1] == CZARNY_PIONEK || plansza[sourceY - 1][sourceX + 1] == CZARNY_DAMKA) {
					if (plansza[sourceY - 2][sourceX + 2] == PUSTE) {
						return true;
					}
				}
			}
			//bicie prawo dol
			if (sourceX <= 5 && sourceY <= 5) {
				if (plansza[sourceY + 1][sourceX + 1] == CZARNY_PIONEK || plansza[sourceY + 1][sourceX + 1] == CZARNY_DAMKA) {
					if (plansza[sourceY + 2][sourceX + 2] == PUSTE) {
						return true;
					}
				}
			}
		}
		else if (plansza[sourceY][sourceX] == BIALY_DAMKA) {
		//do zrobienia
		}
		else {
			return false;
		}
	}
	else if (czyjRuch == 2) {
		if (plansza[sourceY][sourceX] == CZARNY_PIONEK) {
			//bicie lewo gora
			if (sourceX >= 2 && sourceY >= 2) {
				if (plansza[sourceY - 1][sourceX - 1] == BIALY_PIONEK || plansza[sourceY - 1][sourceX - 1] == BIALY_DAMKA) {
					if (plansza[sourceY - 2][sourceX - 2] == PUSTE) {
						return true;
					}
				}
			}
			//biecie lewo dol
			if (sourceX >= 2 && sourceY <= 5) {
				if (plansza[sourceY + 1][sourceX - 1] == BIALY_PIONEK || plansza[sourceY + 1][sourceX - 1] == BIALY_DAMKA) {
					if (plansza[sourceY + 2][sourceX - 2] == PUSTE) {
						return true;
					}
				}
			}
			//bicie prawo gora
			if (sourceX <= 5 && sourceY >= 2) {
				if (plansza[sourceY - 1][sourceX + 1] == BIALY_PIONEK || plansza[sourceY - 1][sourceX + 1] == BIALY_DAMKA) {
					if (plansza[sourceY - 2][sourceX + 2] == PUSTE) {
						return true;
					}
				}
			}
			//bicie prawo dol
			if (sourceX <= 5 && sourceY <= 5) {
				if (plansza[sourceY + 1][sourceX + 1] == BIALY_PIONEK || plansza[sourceY + 1][sourceX + 1] == BIALY_DAMKA) {
					if (plansza[sourceY + 2][sourceX + 2] == PUSTE) {
						return true;
					}
				}
			}
		}
		else if (plansza[sourceY][sourceX] == CZARNY_DAMKA) {
			//do zrobienia
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return false;
}

int Plansza::WykonajRuch(int sourceX, int sourceY, int destX, int destY, int** plansza) {//Jak pionek ma bicie to moze sie coafac
	
	int czyRuch = 0;//ruch czy bicie

	if (czyjRuch == 1) {
		plansza[destY][destX] = plansza[sourceY][sourceX];
		plansza[sourceY][sourceX] = PUSTE;
		//int roznicaX = destX - sourceX;
		//int roznicaY = destY - sourceY;
		//while (true) {
		if (destX >= sourceX) {
			if (destY >= sourceY) {
				sourceX++;
				sourceY++;
				while (true) {
					//w prawo w dol
					if (sourceX == destX || sourceY == destY) {
						break;
					}

					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX++;
					sourceY++;
				}
			}else{
				//w prawo w gore
				sourceX++;
				sourceY--;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX++;
					sourceY--;
				}
			}
		}else {
			if (destY >= sourceY) {
				//w prawo w dol
				sourceX--;
				sourceY++;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX--;
					sourceY++;
				}
			}
			else {
				//w prawo w gore
				sourceX--;
				sourceY--;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX--;
					sourceY--;
				}
			}
		}

		if (destY == 7) {
			plansza[destY][destX] = BIALY_DAMKA;//dokonczyc
		}


	}else{
		plansza[destY][destX] = plansza[sourceY][sourceX];
		plansza[sourceY][sourceX] = PUSTE;
		//int roznicaX = destX - sourceX;
		//int roznicaY = destY - sourceY;
		//while (true) {
		if (destX >= sourceX) {
			if (destY >= sourceY) {
				//w prawo w dol
				sourceX++;
				sourceY++;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX++;
					sourceY++;
				}
			}
			else {
				//w prawo w gore
				sourceX++;
				sourceY--;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX++;
					sourceY--;
				}
			}
		}
		else {
			if (destY >= sourceY) {
				//w prawo w dol
				sourceX--;
				sourceY++;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX--;
					sourceY++;
				}
			}
			else {
				//w prawo w gore
				sourceX--;
				sourceY--;
				while (true) {
					if (sourceX == destX || sourceY == destY) {
						break;
					}
					if (plansza[sourceY][sourceX] != PUSTE) {
						czyRuch++;
					}
					plansza[sourceY][sourceX] = PUSTE;
					sourceX--;
					sourceY--;
				}
			}
		}
	}
	if (destY == 0) {
		plansza[destY][destX] = CZARNY_DAMKA;
	}
	return czyRuch;
}

int Plansza::LiczStraty(int** kopia) {

	int zyskiMaxMax = -999;
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (czyjRuch == 1) {

				if (plansza_glowna[i][j] == CZARNY_PIONEK || plansza_glowna[i][j] == CZARNY_DAMKA) {
					
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {

							if (CzyRuchMozliwy(i, j, k, l, kopia)) {

								int** kopiaPrim = new int*[8];
								for (int iii = 0; iii < 8; iii++) {
									kopiaPrim[iii] = new int[8];
								}

								for (int a = 0; a < 8; a++) {
									for (int b = 0; b < 8; b++) {
										kopiaPrim[a][b] = kopia[a][b];
									}
								}
								int zyski=0;
								zyski = WykonajRuch(i, j, k, l, kopiaPrim);
								
								if (zyski > zyskiMaxMax) {
									zyskiMaxMax = zyski;

								}
							}
						}
					}
				}
			}
			else {
				if (plansza_glowna[i][j] == BIALY_PIONEK || plansza_glowna[i][j] ==BIALY_DAMKA) {
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {
							if (CzyRuchMozliwy(i, j, k, l, kopia)) {
								int** kopiaPrim = new int*[8];
								for (int iii = 0; iii < 8; iii++) {
									kopiaPrim[iii] = new int[8];
								}
								for (int a = 0; a < 8; a++) {
									for (int b = 0; b < 8; b++) {
										kopiaPrim[a][b] = kopia[a][b];
									}
								}
								int zyski = 0;
								zyski= WykonajRuch(i, j, k, l, kopiaPrim);
								if (zyski > zyskiMaxMax) {
									zyskiMaxMax = zyski;
								}
							}
						}
					}
				}
			}
		}
	}
	return zyskiMaxMax;
}

void Plansza::RuchKomputera() {
	
	int iMinMax = -1;
	int jMinMax = -1;
	int kMinMax = -1;
	int lMinMax = -1;
	int stratyMinMax = 9999999;
	/*
	int iMinMax = 0;
	int jMinMax = 0;
	int kMinMax = 0;
	int lMinMax = 0;
	int stratyMinMax = 99;
	*/
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {//przez cala plansze

			if (czyjRuch == 1) {

				if (plansza_glowna[i][j] == BIALY_PIONEK || plansza_glowna[i][j] == BIALY_DAMKA) {
					
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {

							if (CzyRuchMozliwy(i, j, k, l, plansza_glowna)) {

								int** kopia = new int*[8];//Kopia kopi planszy

								for (int iii = 0; iii < 8; iii++) {
									kopia[iii] = new int[8];
								}

								for (int a = 0; a < 8; a++) {
									for (int b = 0; b < 8; b++) {
										kopia[a][b] = plansza_glowna[a][b];
									}
								}
								WykonajRuch(i,j,k,l,kopia);

								int straty = 0;
								straty=LiczStraty(kopia);

								if (stratyMinMax > straty) {
									iMinMax = i;
									jMinMax = j;
									kMinMax = k;
									lMinMax = l;
									stratyMinMax = straty;
								}
								else {
									if (stratyMinMax < straty) {
										iMinMax = i;
										jMinMax = j;
										kMinMax = k;
										lMinMax = l;
										stratyMinMax = straty;
								}
								}
							}
						}
					}
				}
			}
			else {
				if (plansza_glowna[i][j] == CZARNY_PIONEK || plansza_glowna[i][j] == CZARNY_DAMKA) {
					for (int k = 0; k < 8; k++) {
						for (int l = 0; l < 8; l++) {
							if (CzyRuchMozliwy(i, j, k, l, plansza_glowna)) {
								int** kopia = new int*[8];
								for (int iii = 0; iii < 8; iii++) {
									kopia[iii] = new int[8];
								}
								for (int a = 0; a < 8; a++) {
									for (int b = 0; b < 8; b++) {
										kopia[a][b] = plansza_glowna[a][b];
									}
								}
								WykonajRuch(i, j, k, l, kopia);
								int straty = LiczStraty(kopia);
								if (stratyMinMax > straty) {
									iMinMax = i;
									jMinMax = j;
									kMinMax = k;
									lMinMax = l;
									stratyMinMax = straty;
								}
							}
						}
					}
				}
			}
		}
	}
	if (CzyRuchMozliwy(iMinMax, jMinMax, kMinMax, lMinMax, plansza_glowna)) {
		WykonajRuch(iMinMax, jMinMax, kMinMax, lMinMax, plansza_glowna);
	}
}

void Plansza::RuchCzlowieka() {

	char sourceXC;
	int sourceX;
	int sourceY;
	int destX;
	int destY;
	char destXC;
	do {

		cout << "Podaj Ruch\n";
		cout << "Wspolrzedne pionka zrodlowego:\n";
		do {
			cout << "Podaj wspolrzedna A-H\n";
			cin >> sourceXC;
		} while (sourceXC < 'A' || sourceXC > 'H');
		sourceX = sourceXC - 'A';
		do {
			cout << "Podaj wspolrzedna 1-8\n";
			cin >> sourceY;
		} while (sourceY < 1 || sourceY > 8);
		sourceY = sourceY - 1;
		cout << "\nWspolrzedne koncowe\n";
		do {
			cout << "Podaj wspolrzedna A-H\n";
			cin >> destXC;
		} while (destXC < 'A' || destXC > 'H');
		destX = destXC - 'A';
		do {
			cout << "Podaj wspolrzedna 1-8\n";
			cin >> destY;
		} while (destY < 1 || destY > 8);
		destY = destY - 1;
	} while (!CzyRuchMozliwy(sourceX, sourceY, destX, destY,plansza_glowna));

	bool czyZwyklyRuch = WykonajRuch(sourceX, sourceY, destX, destY,plansza_glowna);
	/*sourceX = destX;
	sourceY = destY;
	if (!czyZwyklyRuch) {
		while (CzyPionekMaBicie(sourceX, sourceY,plansza_glowna)) {
			system("cls");
			this->Rysuj();
			cout << "Pionek ma biecie i musi je wykonaæ\n";
			cout << "Wspolrzedne przeznaczenia\n";
			do {
				cout << "Podaj wspolrzedna A-H\n";
				cin >> destXC;
			} while (destXC < 'A' || destXC > 'H');
			destX = destXC - 'A';
			do {
				cout << "Podaj wspolrzedna 1-8\n";
				cin >> destY;
			} while (destY < 1 || destY > 8);
			destY = destY - 1;
			if (CzyRuchMozliwy(sourceX, sourceY, destX, destY,plansza_glowna)) {
				WykonajRuch(sourceX, sourceY, destX, destY,plansza_glowna);
				sourceX = destX;
				sourceY = destY;
			}
			else {
				cout << "Tego ruchu nie mozesz wykonac\n";
			}
		}
	}*/
}

void Plansza::Graj() {
	if (czyjRuch == 1) {
		if (gracz1Komputer == true) {
			RuchKomputera();
		}
		else {
			RuchCzlowieka();
		}

		czyjRuch = 2;
	}
	else {
		if (gracz2Komputer == true) {
			RuchKomputera();
		}
		else {
			RuchCzlowieka();
		}

		czyjRuch = 1;
	}
}

int** Plansza::GetPlanszaGlowna() {
	return plansza_glowna;
}

bool Plansza::CzyKoniec(int** plansza) {
	//to poprawicc i sprawdzic czy  ruch nie jest zabvlokowany
	int gracz1 = 0;
	int gracz2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (plansza[i][j] == BIALY_PIONEK || plansza[i][j] == BIALY_DAMKA) {
				gracz1++;
			}else if(plansza[i][j] == CZARNY_PIONEK || plansza[i][j] == CZARNY_DAMKA){
				gracz2++;
			}
		}
	}
	if (gracz1 == 0 || gracz2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Plansza::LosujGraczaZaczynajacego() {
	srand(time(NULL));
	if (rand() % 2 == 1) {
		czyjRuch = 1;
	}
	else {
		czyjRuch = 2;
	}
}

void Plansza::UstawGraczy(bool gracz1, bool gracz2) {
	gracz1Komputer = gracz1;
	gracz2Komputer = gracz2;
}


void Plansza::UstaPozycjeStartowe() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			plansza_glowna[i][j] = PUSTE;
			if (i < 3) {
				if ((i + j) % 2 == 1) {
					plansza_glowna[i][j] = BIALY_PIONEK;
				}
			}
			if (i > 4) {
				if ((i + j) % 2 == 1) {
					plansza_glowna[i][j] = CZARNY_PIONEK;
				}
			}
		}
	}
}


void Plansza::Rysuj() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,7);
	cout << "     A  B  C  D  E  F  G  H\n";
	cout << "\n";
	for (int i = 0; i < 8; i++) {
		SetConsoleTextAttribute(hOut,7);
		cout << (i + 1) << "   ";
		for (int j = 0; j < 8; j++) {
			int background;
			if ((i + j) % 2 == 1) {
				background = 0;
			}
			else {
				background = BACKGROUND_GREEN;
			}
			if(plansza_glowna[i][j] == PUSTE) {
				SetConsoleTextAttribute(hOut, 9 | background);
				cout << "   ";
			}
			else if (plansza_glowna[i][j] == BIALY_PIONEK) {
				SetConsoleTextAttribute(hOut, 9 | background);
				cout << " * ";
			}
			else if (plansza_glowna[i][j] == BIALY_DAMKA) {
				SetConsoleTextAttribute(hOut, 9 | background);
				cout << " $ ";
			}
			else if (plansza_glowna[i][j] == CZARNY_PIONEK) {
				SetConsoleTextAttribute(hOut, 10 | background);
				cout << " * ";
			}
			else if (plansza_glowna[i][j] == CZARNY_DAMKA) {
				SetConsoleTextAttribute(hOut, 10 | background);
				cout << " $ ";
			}
		}
		cout << "\n";
		SetConsoleTextAttribute(hOut, 15);
	}
	cout << "\n\n";
	if (czyjRuch == 1) {
		cout << "Gracz niebieski\n\n";
	}else{
		cout << "Gracz zielony\n\n";
	}
}


//rysuj zalatwione
//czykoniec zalatwione
//
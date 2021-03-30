#include <iostream>
#include <ctime>
#include <time.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

const int satir = 6;						// satir sayisi
const int sutun = 5;						// sutun sayisi
char matris[satir][sutun];					// matris


void Temizle(){								// matris temizlenir
	for(int i=0; i < satir; i++){			// her satir icin
		for(int j=0; j < sutun; j++){		// her sutune
			matris[i][j] = 'T';				// 'T' harfi yerlestirilir
		}
	}
}

void MayinYerlestir(){						// Mayinlar yerlestirilir
	int j = sutun - 1;						// bu rakam arasinda rasgele rakam cikarilacaktir
	for(int i=0; i < satir; i++){			// her satir icin
		int rasgele = (rand() % j);			// rasgele bir sutune
		matris[i][rasgele] = 'X';			// 'X' harfi yerlestirlir
	}
}

void OyuncuYerlestir(int r, int e){			// oyuncunu cevapi matrise yerlestirilir
	int f = e - 1;							// cevap(1-index) matris(0-index)
	matris[r][f] = 'O';						// matrise 'O' harfi yerlestirilir
}

int OyuncuSor(){								// oyuncuya rakam sorulur
	int no;										// verdigi cevap
	cout << "1 ile " << sutun << " arasinda bir sayi giriniz: ";
	while(!(cin >> no) || no > sutun || no < 1){	// eger verdigi cevap rakam digilse veya 1-5 arasinda degilse tekrar soru sorulur
		cout << "Lutfen 1 ve " << sutun << " arasi bir sayi giriniz.";
		cin.clear();							// cevap temizlenir
		cin.ignore(123, '\n');					// cevap ignore edilir
	}
	
	return no;									// oyuncunun verdigi cevap
}

void SonucGoster(){							// Oyun sonunda gosterilen sonuclar
	for(int i=0; i < satir; i++){			// her satirdaki
		for(int j=0; j < sutun; j++){		// sutunun
			cout << matris[i][j] << " ";	// harfi ve bir bosluk gosterilir
		}
		cout << endl;						// her satir sonunda
	}
}

int ara(char X[], char value){						// mayin aranir
	int index = 0;									// 0-index ile baslanilir
	while (index < satir && X[index] != value){		// her satir icin loop 'X' bulunana kadar index arttirilir
		++index;
	}
	if (index < satir && X[index] == value){		// eger 'X' bulunduysa 
													// index cevaplanir
		return index;
	}
}

void Oyun(){
	Temizle();										// matrix temizlenir
	MayinYerlestir();								// mayinlar yerlestirilir
	for(int i=0; i < satir; i++){					// her satir icin yapilan islemler
		int j = i + 2;								// satir numarasi (i = 0-index ondan + 2) 
		int cevap = OyuncuSor();					// oyuncunun verdigi cevap
		int Mayin = ara(matris[i], 'X');			// mayinin yeri (0-index)
		int MayinYeri = Mayin + 1;					// mayinin yeri (1-index)
		OyuncuYerlestir(i, cevap);					// oyuncunun cevabi matrise yerlestirilir
		if(MayinYeri == cevap) {					// eger oyuncunun verdigi cevap ve mayinin yeri ayni ise
			cout << "Mayin patladi. Uzgunum maalesef kaybettiniz." << endl;
			break;									// mesaj ve loop durdurulur
		}else{
			int k = satir + 1;						// son satir sayisi
			if(j == k){								// son satira gecildiginde
				cout << "Tebrikler oyunu kazandiniz" << endl;
			}else{
				cout << j << ". satira gectiniz." << endl;
			}
		}
	}
	SonucGoster();									// oyun sonuclari gosterilir
	char cevap;										// oyuncuya sorulur tekrar oynamak istermi diye
	cout << "Tekrar oynamak istermisiniz? (E/H) ";
	cin >> cevap;
	if(cevap == 'e' || cevap == 'E'){				// eger 'e' veya 'E' cevabi verilirse Oyun() yeniden baslar
		cout << "Oyun yeniden baslamistir" << endl;
		Oyun();
	}
}

int main(){
	// oyun baslatilir
	Oyun();
	return 0;
}

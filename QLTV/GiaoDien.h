#pragma once

#include "essential.h"
using namespace std;

const int dong =12;
const int cot = 40;
const int items = 4;
#define BGColor 89
#define xTB 2
#define yTB 25
//=======
char Menu [items][50] = {
	"  QUAN LI DOC GIA   ",
	"  QUAN LI DAU SACH  ",
	"    MUON/TRA SACH   ",
	" THOAT CHUONG TRINH "
};

void Normal () {
	SetColor(15);
	SetBGColor(BGColor);
}

void HighLight () {
	SetColor(15);
	SetBGColor(1);
}

void VeQLTV()
{
//	"  _   _ _   _   _  _    _    _    ___  _ _  _ _    _ _  _  ___  _  _    "
//	" / \ | | | / \ | \| |  | |  | |  |_ _|| U || | |  | | || || __|| \| |   "
//	"( o )| U || o || \\ |  | |_ | |   | | |   || U |  | V || || _| | \\ |   "
//	" \_,7|___||_n_||_|\_|  |___||_|   |_| |_n_||___|   \_/ |_||___||_|\_|   "
	gotoxy(20,1); cout << "  _   _ _   _   _  _    _    _    ___  _ _  _ _    _ _  _  ___  _  _    ";
	gotoxy(20,2); cout << " / \\ | | | / \\ | \\| |  | |  | |  |_ _|| U || | |  | | || || __|| \\| |   ";
	gotoxy(20,3); cout << "( o )| U || o || \\\\ |  | |_ | |   | | |   || U |  | V || || _| | \\\\ |   ";
	gotoxy(20,4); cout << " \\_,7|___||_n_||_|\\_|  |___||_|   |_| |_n_||___|   \\_/ |_||___||_|\\_|   ";	
}

int MenuDong(char td [items][50])
{
	Normal();
	ShowCur(false);
	system("cls");
	VeQLTV();
	int chon =0;
	int i; 
	for ( i=0; i< items ; i++) {
		gotoxy(cot, dong +i);
    	cout << td[i];
	}
  	HighLight();
  	gotoxy(cot,dong+chon);
  	cout << td[chon];
  	Normal();
  	int kytu;
	do {
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu) {
    		case Up:
				if (chon+1 >1) {
  		        	
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
  					
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
  					chon = items -1;
              		HighLight();
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <items) {
  		    		
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		chon ++;
              		HighLight();
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
					
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		chon = 0;
              		HighLight();
              		gotoxy(cot,dong+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Enter:
  				ShowCur(true);
				return chon+1;
		}
  	} while (1);
}

//void SetWindow()
//{
//	HANDLE cons = GetStdHandle(STD_OUTPUT_HANDLE);
//    PCONSOLE_FONT_INFOEX font = new CONSOLE_FONT_INFOEX() ;
//    font->cbSize = sizeof(CONSOLE_FONT_INFOEX);
//    GetCurrentConsoleFontEx(cons,0,font);
//    font->dwFontSize.X = 10;
//    font->dwFontSize.Y = 20;
//    //font->FontWeight = 22;
//    //font->FontFamily = FF_DECORATIVE;
//    SetCurrentConsoleFontEx(cons,2,font);
//}

void KhungThongBao()
{
	gotoxy(xTB,yTB);	cout << "+-----------------------+";
	gotoxy(xTB,yTB+1);	cout << "|______ THONG BAO ______|";
	gotoxy(xTB,yTB+2);	cout << "|                       |";
	gotoxy(xTB,yTB+3);	cout << "|  .                    |";
	gotoxy(xTB,yTB+4);	cout << "|_______________________|";
	
}

void ThongBao(string c)
{
	HighLight();
	gotoxy(xTB+3,yTB+3); cout << c;
	Normal();
	Sleep(1499);
	gotoxy(xTB,yTB+3);	cout << "|  .                    |";
}

void XoaThongBao()
{
	gotoxy(xTB,yTB+3); cout << "|  .                    |";
}

//

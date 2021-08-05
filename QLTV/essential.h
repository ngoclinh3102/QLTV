#pragma once

#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

#define Enter 13
#define ESC 27
#define Back 8
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define Num1 49
#define Num2 50

#define nameMAX 38
#define numMAX 10


//==========Khai bao ham
string NhapChuoi(int x, int y, string str);
int NhapSo(int x, int y, int num);
int toInt(string a);
string toString(int number);
void gotoxy(short x,short y);
string NhapTenSach(int x, int y, string str);
int NhapMaSach(int x, int y, int num);
string NhapViTri(int x, int y, string str);


//===============Nhap chuoi VI TRI ======// co 2 ki tu gom 1 chu 1 so
string NhapViTri(int x, int y, string str)
{
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
    
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri == 5)
        {
        	c[2]= '\0';
        	str=c;
        	delete[] c;
            return str;
        }
        else if (chr == Back && vitri > 0)
        {
        	if(vitri==4)
        	{
        		vitri -= 4;
        		c[0] = '\0';
        		gotoxy(x+vitri,y); cout << " ";
        		gotoxy(x+vitri,y);
			}
			else if(vitri==5)
			{
				vitri--;
				c[1] = '\0';
				gotoxy(x+vitri,y); cout << " ";
				gotoxy(x+vitri,y);
			}
//            vitri--;
//            c[vitri]= '\0';
//            gotoxy(x + vitri, y); cout << " ";
//            if(vitri==4) vitri -= 3;
//            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z')) && vitri == 0)
        {
            c[0] = char(toupper(chr));
            cout << c[0];
            vitri += 4;
        }
        else if( chr >= '0' && chr <= '9' && vitri==4 )
        {
        	c[1] = chr;
        	cout << c[1];
        	vitri++;
		}
    } while (chr != ESC);
    
    delete[] c;
    return str;
}

//=======Nhap masach: nhap 0-9, co 1->4 chu so, khong nhan '0' dau tien=========//
int NhapMaSach(int x, int y, int num)
{
	//tien xu li
	string str= toString(num);
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
	
	gotoxy(x,y); cout << num;
	
	int chr;
	do
	{
		gotoxy(x+vitri,y); chr= getch();
		if (chr == Enter && vitri != 0)
        {
//			while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
//			while(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	c[2]= '\0';
        	str=c;
        	delete[] c;
        	num= toInt(str);
            return num;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if(chr >= '0' && chr <= '9' && vitri<3)
		{
			if(chr == '0' && vitri==0) continue;
			c[vitri]= char(chr);
			cout << c[vitri];
			vitri++;
		}
	} while(chr != ESC);
	
	delete[] c;
    return -1;
}
//===Nhap ten sach: A-Za-z0-9 + viet hoa chu cai dau + loc khoang trang thua
string NhapTenSach(int x, int y, string str)
{
    
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
    
	//gotoxy(x,y); cout << c;
    
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri != 0)
        {
        	//while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
        	if(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	c[vitri]= '\0';
        	str=c;
        	delete[] c;
            return str;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == ' ' || (chr>='0' && chr<='9')) && vitri < nameMAX)
        {
            if ( chr== ' ' && ( vitri==0 || c[vitri - 1]==' ')) continue;
			if ( vitri==0 || c[vitri - 1]==' ')	c[vitri] = char(toupper(chr));
            else c[vitri] = char(tolower(chr));
            cout << c[vitri];
            vitri++;
        }
    } while (chr != ESC);
    
    delete[] c;
    return str;
}

//===Nhap chuoi: A-Za-z + viet hoa chu cai dau + loc khoang trang thua
string NhapChuoi(int x, int y, string str)
{
    
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
    
	//gotoxy(x,y); cout << c;
    
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri != 0)
        {
        	//while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
        	if(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	c[vitri]= '\0';
        	str=c;
        	delete[] c;
            return str;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == ' ') && vitri < nameMAX)
        {
            if ( chr== ' ' && ( vitri==0 || c[vitri - 1]==' ')) continue;
			if ( vitri==0 || c[vitri - 1]==' ')	c[vitri] = char(toupper(chr));
            else c[vitri] = char(tolower(chr));
            cout << c[vitri];
            vitri++;
        }
    } while (chr != ESC);
    
    delete[] c;
    return str;
}
//=======Nhap so: 0-9=========
int NhapSo(int x, int y, int num)
{
	//tien xu li
//	string str= toString(num);
	string str= "";
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
	
//	gotoxy(x,y); cout << num;
//	Sleep(1999);
//	gotoxy(x,y); cout << str;
//	Sleep(1999);
//	gotoxy(x,y); cout << c;
	
	int chr;
	do
	{
		gotoxy(x+vitri,y);
		fflush(stdin); chr= getch();
		if (chr == Enter && vitri != 0)
        {
        	//while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
        	c[vitri]= '\0';
        	//while(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	str=c;
        	delete[] c;
        	num= toInt(str);
            return num;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if(chr >= '0' && chr <= '9')
		{
			c[vitri]= char(chr);
			cout << c[vitri];
			vitri++;
		}
	} while(chr != ESC);
	
	delete[] c;
    return num;
}

//=======Nhap nam: <=2021=========
int NhapNam(int x, int y, int num)
{
	//tien xu li
//	string str= toString(num);
	string str= "";
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
	
//	gotoxy(x,y); cout << num;
//	Sleep(1999);
//	gotoxy(x,y); cout << str;
//	Sleep(1999);
//	gotoxy(x,y); cout << c;
	
	int chr;
	do
	{
		gotoxy(x+vitri,y);
		fflush(stdin); chr= getch();
		if (chr == Enter && vitri != 0)
        {
        	//while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
        	c[vitri]= '\0';
        	//while(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	str=c;
        	delete[] c;
        	num= toInt(str);
        	if(num>2021)
        	{
        		gotoxy(x,y); cout << "Hu cau!";
        		Sleep(500);
        		gotoxy(x,y); cout << "Nhap lai!";
        		Sleep(500);
        		gotoxy(x,y); cout << "         ";
        		num= NhapNam(x,y,num);
			}
        	return num;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if(chr >= '0' && chr <= '9' && vitri < 4)
		{
			c[vitri]= char(chr);
			cout << c[vitri];
			vitri++;
			
		}
	} while(chr != ESC);
	
	delete[] c;
    return num;
}

//=======String to Int
int toInt(string a)
{
    int tong = 0;
    for (int i = 0; i < a.length(); i++)
    {
        tong *= 10;
        tong += (int)(a[i] - '0');
    }
    return tong;
}
//========Int to String
string toString(int number)
{     
    string result;          
    ostringstream convert;   
    convert << number;      
    result = convert.str(); 
    return result;
}
//===============Nhap chuoi in hoa: A-Z
string NhapChuoiHoa(int x, int y, string str)
{
	int vitri = str.length();
	char* c = new char[str.size() + 1];
	strcpy(c,str.c_str());
    
//	gotoxy(x,y); cout << c;
    
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri == 4) //ma ISBN co 4 ki tu
        {
        	//while(c[0]== ' ') for(int i=0; i<vitri; i++) c[i]=c[i+1];
        	//while(c[vitri-1]== ' ') c[vitri-1]= '\0';
        	c[vitri]= '\0';
        	str=c;
        	delete[] c;
            return str;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z')) && vitri < 4)
        {
            c[vitri] = char(toupper(chr));
            cout << c[vitri];
            vitri++;
        }
    } while (chr != ESC);
    
    delete[] c;
    return str;
}

//=========XOA DU LIEU FILE CU TRUOC KHI GHI===========
void clearFileContent(const char *filePath) {
    FILE *f = fopen(filePath, "w");
    if (f == NULL) {
        printf("Can not open file %s to erase data.\n", filePath);
        return;
    }
    fclose(f);
}

//========== TIM CHUOI TRONG CHUOI ==============//
int TimChuoiCon(string a, string b) //Tim a trong b
{
	int asize= a.length();
	int bsize= b.length();
	
	if(asize>bsize) return 0;
	
	char* tempa = new char[a.size() + 1];
	strcpy(tempa,a.c_str());
	
	char* tempb = new char[b.size() + 1];
	strcpy(tempb,b.c_str());
	
	if(asize==bsize)
	{
		if(strcmp(tempa,tempb)==0)
		{
			delete tempa;
			delete tempb;
			return 1;
		}
		else
		{
			delete tempa;
			delete tempb;
			return 0;
		}
	}
	
	bool flag;
	for(int i=0; i<=bsize-asize; i++)
	{
		flag=true;
		for(int j=0; j<asize; j++)
		{
			if(a[j] != b[j+i])
			{
				flag= false;
				break;
			}
		}
		if(flag)
		{
			delete tempa;
			delete tempb;
			return 1;
		}
	}
	
	delete tempa;
	delete tempb;
	return 0;
}

//Di den (x,y)
void gotoxy(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

//An/Hien con tro
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X , info.dwCursorPosition.Y );
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void clrscr() {
	system("cls");
}

//==== Doi console tittle ====//
BOOL WINAPI SetConsoleTitle(
  _In_ LPCTSTR lpConsoleTitle
);

//======================//
//void SetWindowSize(SHORT width, SHORT height)
//{
//    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    SMALL_RECT WindowSize;
//    WindowSize.Top = 0;
//    WindowSize.Left = 0;
//    WindowSize.Right = width;
//    WindowSize.Bottom = height;
// 
//    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
//}

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
/*char* Pwd () {
     char S[40]; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}*/

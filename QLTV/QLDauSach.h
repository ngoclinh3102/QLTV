#pragma once

#include "GiaoDien.h"

#define MaxOfDauSach 300
#define dmsMAX 30

char dausach_mang[55]= "C:\\Users\\DELL\\Desktop\\QLTV\\dausach_mang.txt";

const int xDS= 3; //ve menu dau sach
const int yDS= 1;
const int xListDS= 36; //ve + in danh sach dau sach
const int yListDS= 0;
const int xListDMS= xListDS; //ve + in danh sach danh muc sach
const int yListDMS= yListDS+5;
const int itemDS= 6;
const int itemDMS= 4;
const int nTheLoai= 13;
const int yNhap= itemDS+3;

char MenuQLDS[itemDS][35]=
{
	"    NHAP DAU SACH         ",
	"    HIEU CHINH DAU SACH   ",
	" IN DS DAU SACH (THELOAI) ",
	"    XOA DAU SACH          ",
	"    QL DANH MUC SACH      ",
	"    THOAT QLDS            "
};

char MenuQLDMS[itemDMS][35]=
{
	"    NHAP SACH MOI         ",
	"    SUA VI TRI            ",
	"    XOA SACH              ",
	"    THOAT QLDMS           "
};

string DSTheLoai[nTheLoai]=
{
	" Van Hoc    ",
	" Toan Hoc   ",
	" Kinh Te    ",
	" Ngoai Ngu  ",
	" Tieu Thuyet",
	" Tam Ly     ",
	" Ton Giao   ",
	" Phap Luat  ",
	" KH - CN    ",
	" Lich Su    ",
	" Thieu Nhi  ",
	" Chinh Tri  ",
	" Triet Hoc  "
};

string  TrangThaiSach[3]=
{
	"Co The Muon",
	"Da Cho Muon",
	"Da Thanh Ly"
};
// ==============KHAI BAO CTDL================= //
struct danhmucsach
{
	int masach;
	int trangthai; //0-co the muon, 1-da cho muon, 2-da thanh ly
	string vitri;
};
typedef struct danhmucsach DMS;

struct node_dms
{
	DMS data;
	node_dms* next;
};
//typedef struct node_dms NODE_DMS;
typedef struct node_dms* PTR_DMS;

struct dausach
{
	string ISBM;
	string tensach;
	string tacgia;
	string theloai;
	int namxb;
	int trang;
	int nDMS; //so luong sach trong dau sach
	int luotmuon; //thong ke so luot muon cua dau sach
	PTR_DMS dms;
};
typedef struct dausach* DauSach;

struct danhsach_dausach
{
	int sl=0; //so luong dau sach
	DauSach ds[MaxOfDauSach];
};
typedef struct danhsach_dausach DS_DauSach;
//typedef struct danhsach_dausach* List_DauSach;

//===================================================//
//================KHAI BAO NGUYEN MAU HAM==========//
//==================================================//
//=========Giao dien======
void VeKhungDauSach();
int MenuDongQLDS(char td [itemDS][35], int x, int y);
void VeKhungMenuQLDS(int so_item);
void XoaDSDauSach();
void XoaMenuQLDS();

//============Nhap dau sach==========
void NhapDauSach(DS_DauSach &mang);
int KiemTraTrungISBN(DS_DauSach mang, string isbn);
void ThemDauSach(DS_DauSach &mang, DauSach p);

//===========hieu chinh dau sach============
int timMaISBM(DS_DauSach &mang, string maDS);
void hieuChinhDS(DS_DauSach t);
//===============xoa dau sach===============
void xoaDS(DS_DauSach &mang);
//============Hieu chinh vi tri sach==========
void suaViTriSach(PTR_DMS First, DS_DauSach &mang);
//============xoa Sach===========
void xoaDMS(int ma);

//Nhap the loai
string NhapTheLoai(int x, int y, string str);

//============In danh sach dau sach===============
void InDSDauSach(DS_DauSach mang);



//=================================================================//
//=================== QL DANH MUC SACH ============================//
//=================================================================//
void runQLDMS(int key);
int NhapDeTimChuoiTrongChuoi(int x, int y, DS_DauSach mang);

//======== Ve giao dien========
int MenuDongQLDMS(char td [itemDS][35], int x, int y);
void VeKhungDS_DMS();
void XoaKhungDS_DMS();
void XoaNhapDMS();
//==== Nhap Danh Muc Sach
void NhapDMS(int key);
int TimMaSachMax(PTR_DMS First);
void InsertFirst(PTR_DMS &First, DMS s);
PTR_DMS KhoiTaoDMS(DMS s);
void InsertLast(PTR_DMS &First, DMS s);
void InsertAfter(PTR_DMS p, DMS s);

//===== In danh sach Danh muc sach
void InDS_DMS(PTR_DMS First, string isbn);
//xoa danh muc sach
int DeleteFirstDMS(PTR_DMS &First);
int DeleteAfterDMS(PTR_DMS p);
int XoaDMS(PTR_DMS &First, int key);
bool BatDKXoaDMS(PTR_DMS q, int key);
//============Khoi tao===========//
DS_DauSach Mang_DS;

//=================== HAM QL DAU SACH ===================//
void runQLDS()
{
	system("cls");
	Normal();
	VeKhungDauSach();
	KhungThongBao();
	
	int chon;
//	bool kt= true;
	while(true)
	{
		chon= MenuDongQLDS(MenuQLDS,xDS,yDS);
		switch(chon)
		{
			case 1: //Nhap dau sach
			{
				NhapDauSach(Mang_DS);
				break;
			}
			case 2: //Hieu chinh
			{
				if(Mang_DS.sl==0) ThongBao("Danh sach rong");
				else hieuChinhDS(Mang_DS);
				break;
			}
			case 3: //In danh sach dau sach
			{
				XoaDSDauSach();
				if(Mang_DS.sl==0) ThongBao("Danh sach rong");
				else InDSDauSach(Mang_DS);
				break;
			}
			case 4: //Xoa dau sach (co dieu kien)
			{
				if(Mang_DS.sl==0) ThongBao("Danh sach rong");
				else xoaDS(Mang_DS);
				break;
			}
			case 5: //Quan li Danh muc sach
			{
				gotoxy(0,yNhap); cout << "Nhap ten sach: ";
				int key= NhapDeTimChuoiTrongChuoi(15,yNhap,Mang_DS);
				if(key==-1)
				{
					gotoxy(0,yNhap+1); cout << "ESC";
				}
				else
				{
					runQLDMS(key);
				}
				break;
			}
			case 6: //Thoat
			{
				return;
			}
		}
	}
}

//==========Ve giao dien========
void VeKhungDauSach()
{
	gotoxy(xListDS,yListDS);	cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDS,yListDS+1);	cout << "|STT| ISBM |        Ten Sach        |     Tac Gia      |  The Loai   |Nam XB|Trang| SL  |";
	gotoxy(xListDS,yListDS+2);	cout << "|---+------+------------------------+------------------+-------------+------+-----+-----|";
//								cout << "|   |      |                        |                  |             |      |     |     |";
//								cout << "                                                                                         ";
}

void VeKhungMenuQLDS(int so_item)
{
	gotoxy(xDS-1,yDS-1); 		cout << "+--------------------------+";
	for(int i=0; i<so_item; i++)
	{
		gotoxy(xDS-1,yDS+i);	cout << "|                          |";
	}
	gotoxy(xDS-1,yDS+so_item);		cout << "+--------------------------+";
}

void XoaDSDauSach()
{
	for(int j=yListDS+3; j<37; j++)
	{
		gotoxy(xListDS,j); cout << "                                                                                         ";
	}
	gotoxy(0,0);
}

void XoaMenuQLDS()
{
	for(int j=0; j<21; j++)
	{
		gotoxy(0,j); cout << "                                ";
	}
}

int MenuDongQLDS(char td [itemDS][35], int x, int y)
{
	//Co the sua
	Normal();
	ShowCur(false);
	XoaThongBao();
	XoaMenuQLDS();
	VeKhungMenuQLDS(itemDS);
	
	//Khong duoc sua
	for (int i=0; i<itemDS; i++)
	{
		gotoxy(x, y +i); cout << td[i];
	}
  	HighLight();
  	int chon =0;
  	gotoxy(x,y+chon);
  	cout << td[chon];
  	Normal();
  	int kytu;
	do {
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu) {
    		case Up:
				if (chon+1 >1) {
  		        	
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
  					
              		gotoxy(x,y+chon);
              		cout << td[chon];
  					chon = itemDS -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <itemDS) {
  		    		
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon ++;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
					
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon = 0;
              		HighLight();
              		gotoxy(x,y+chon);
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

//================Nhap dau sach=================//
void NhapDauSach(DS_DauSach &mang)
{
	gotoxy(0,yNhap);	cout << "Nhap ma ISBM: ";
	gotoxy(0,yNhap+1);	cout << "Nhap ten sach: ";
	gotoxy(0,yNhap+2);	cout << "Nhap tac gia: ";
	gotoxy(0,yNhap+3);	cout << "Nhap the loai: ";
	gotoxy(0,yNhap+4);	cout << "Nhap nam xuat ban: ";
	gotoxy(0,yNhap+5);	cout << "Nhap so trang: ";
	
	DauSach p = new dausach;
	
//	fflush(stdin); 
	p->ISBM= NhapChuoiHoa(14,yNhap,p->ISBM);
	while(KiemTraTrungISBN(mang,p->ISBM)==1)
	{
		ThongBao("MA ISBN BI TRUNG!");
		p->ISBM= NhapChuoiHoa(14,yNhap,p->ISBM);
	}
	if(p->ISBM.compare("")==0) return;
	fflush(stdin); p->tensach= NhapTenSach(15,yNhap+1,p->tensach);
	fflush(stdin); p->tacgia= NhapChuoi(14,yNhap+2,p->tacgia);
	//Nhap the loai
	fflush(stdin); p->theloai= NhapTheLoai(15,yNhap+3,p->theloai);
	fflush(stdin); p->namxb= NhapNam(19,yNhap+4,p->namxb);
	fflush(stdin); p->trang= NhapSo(15,yNhap+5,p->trang);
	p->nDMS = 0;
	p->luotmuon = 0;
	p->dms = NULL;

	ThemDauSach(mang,p);
//	delete p;
	ThongBao("Nhap thanh cong!");
}
int KiemTraTrungISBN(DS_DauSach mang, string isbn)
{
	for(int i=0; i<mang.sl; i++)
	{
		if(isbn.compare(mang.ds[i]->ISBM)==0) return 1;
	}
	return 0;
}
void ThemDauSach(DS_DauSach &mang, DauSach p)
{
	mang.ds[mang.sl]= new dausach;
	mang.ds[mang.sl]->ISBM = p->ISBM;
	mang.ds[mang.sl]->tensach = p->tensach;
	mang.ds[mang.sl]->tacgia = p->tacgia;
	mang.ds[mang.sl]->theloai = p->theloai;
	mang.ds[mang.sl]->namxb = p->namxb;
	mang.ds[mang.sl]->trang = p->trang;
	mang.ds[mang.sl]->luotmuon = p->luotmuon;	//moi them
	mang.ds[mang.sl]->nDMS = p->nDMS;	//moi them
	mang.ds[mang.sl]->dms = p->dms;	//moi them
	
	mang.sl++; //1
	
	int i=mang.sl-1;
	while(i>0 && mang.ds[i]->theloai.compare(mang.ds[i-1]->theloai) <= 0)
	{
		if(mang.ds[i]->theloai.compare(mang.ds[i-1]->theloai) == 0 )
		{
			if(mang.ds[i]->tensach.compare(mang.ds[i-1]->tensach) >= 0 ) continue;
		}

		DauSach temp = new dausach;
		temp= mang.ds[i];
		mang.ds[i] = mang.ds[i-1];
		mang.ds[i-1] = temp;
//		delete mang.ds[i-1];
		i--;

	}
}

//====================================================================================================
//=================Hieu chinh sach====================================================================

//===========tim ma ISBM de hieu chinh/xoa ======================
int timMaISBM(DS_DauSach &mang, string maDS)
{
//	gotoxy(0,yNhap); cout<<"Nhap ma ISBM: ";
//	cin>>maDS;
	for (int i=0; i<mang.sl; i++)
	{
		if (maDS.compare(mang.ds[i]->ISBM) == 0)
		{
			return i;
		}
	}
		return 1;
}

//======================hieu chinh dau sach===============
void hieuChinhDS(DS_DauSach mang)
{
	//DS_DauSach t = mang;
	string ma;
	InDSDauSach(mang);
	gotoxy(0,yNhap); cout << "Nhap ma ISBM de hieu chinh:";
	fflush(stdin);
	ma = NhapChuoiHoa(28,yNhap,ma);
	//cin.ignore();
	int s = timMaISBM(mang, ma);
	if (ma != mang.ds[s]->ISBM)
	{
		ThongBao("ma khong ton tai!");
		return;
	}
	else 
	{
		XoaDSDauSach();
		gotoxy(xListDS,yListDS+3);	cout << "|   |      |                        |                  |             |      |     |     |";
		gotoxy(xListDS+2,yListDS+3);	cout << "1";
		gotoxy(xListDS+6,yListDS+3);	cout << mang.ds[s]->ISBM;
		gotoxy(xListDS+13,yListDS+3);	cout << mang.ds[s]->tensach;
		gotoxy(xListDS+38,yListDS+3);	cout << mang.ds[s]->tacgia;
		gotoxy(xListDS+56,yListDS+3);	cout << mang.ds[s]->theloai;
		gotoxy(xListDS+71,yListDS+3);	cout << mang.ds[s]->namxb;
		gotoxy(xListDS+78,yListDS+3);	cout << mang.ds[s]->trang;
		gotoxy(xListDS+84,yListDS+3);	cout << mang.ds[s]->nDMS;
				
				
		gotoxy(0,yNhap+2);	cout << "CHINH SUA THONG TIN";
		gotoxy(0,yNhap+4);	cout << "Nhap ma ISBM: "<<mang.ds[s]->ISBM;
		gotoxy(0,yNhap+5);	cout << "Nhap ten sach: "<<mang.ds[s]->tensach;
		gotoxy(0,yNhap+6);	cout << "Nhap tac gia: "<<mang.ds[s]->tacgia;
		gotoxy(0,yNhap+7);	cout << "Nhap the loai: "<<mang.ds[s]->theloai;
		gotoxy(0,yNhap+8);	cout << "Nhap nam xuat ban: ";//<<t.ds[s]->namxb;
		gotoxy(0,yNhap+9);	cout << "Nhap so trang: ";//<<t.ds[s]->trang;
		
		
		fflush(stdin); mang.ds[s]->ISBM = NhapChuoiHoa(14,yNhap+4,mang.ds[s]->ISBM);
		fflush(stdin); mang.ds[s]->tensach= NhapTenSach(15,yNhap+5,mang.ds[s]->tensach);
		fflush(stdin); mang.ds[s]->tacgia= NhapChuoi(14,yNhap+6,mang.ds[s]->tacgia);
		fflush(stdin); mang.ds[s]->theloai= NhapTheLoai(15,yNhap+7,mang.ds[s]->theloai);
		fflush(stdin); mang.ds[s]->namxb= NhapNam(19,yNhap+8,mang.ds[s]->namxb);
		fflush(stdin); mang.ds[s]->trang= NhapSo(15,yNhap+9,mang.ds[s]->trang);
		
		ThongBao("Cap nhat thanh cong");
		InDSDauSach(mang);
		return;

	}
	
}


// ====================xoa dau sach ===========================
void xoaDS(DS_DauSach &mang)
{
	string ma;
	InDSDauSach(mang);
	gotoxy(0,yNhap); cout << "Nhap ma ISBM de xoa:";
	fflush(stdin);
	ma = NhapChuoiHoa(22,yNhap,ma);
	//cin.ignore();
	int s = timMaISBM(mang, ma);
	if (ma != mang.ds[s]->ISBM)
	{
		ThongBao("ma khong ton tai!");
		return;
	}
	else
	{
		if(mang.ds[s]->nDMS == 0 && mang.ds[s]->luotmuon == 0 )
		{
			XoaDSDauSach();
			gotoxy(xListDS,yListDS+3);	cout << "|   |      |                        |                  |             |      |     |     |";
			gotoxy(xListDS+2,yListDS+3);	cout << "1";
			gotoxy(xListDS+6,yListDS+3);	cout << mang.ds[s]->ISBM;
			gotoxy(xListDS+13,yListDS+3);	cout << mang.ds[s]->tensach;
			gotoxy(xListDS+38,yListDS+3);	cout << mang.ds[s]->tacgia;
			gotoxy(xListDS+56,yListDS+3);	cout << mang.ds[s]->theloai;
			gotoxy(xListDS+71,yListDS+3);	cout << mang.ds[s]->namxb;
			gotoxy(xListDS+78,yListDS+3);	cout << mang.ds[s]->trang;
			gotoxy(xListDS+84,yListDS+3);	cout << mang.ds[s]->nDMS;
			
			gotoxy(0,yNhap+2); cout << "Nhap lai ma ISBM de xoa:";
			fflush(stdin);
			string maXoa;
			maXoa = NhapChuoiHoa(25,yNhap+2,maXoa);
			if (maXoa == ma)
			{
				delete mang.ds[s];
				for(int i=s+1; i<mang.sl; i++)
				{
					mang.ds[i-1] = mang.ds[i];			
				}
				//DAUSACH *tam = mang.ds[mang.sl-1];
				mang.sl--;
				ThongBao("Da xoa thanh cong!");	
				InDSDauSach(mang);
			}
			else 
			{
					ThongBao("Nhap sai");
					InDSDauSach(mang);
					return;
			}		
		}
		else 
		{
			ThongBao("khong the xoa!");
			return;
			InDSDauSach(mang);
		}
	}
}


//============================= sua vi tri sach=================================

void suaViTriSach(int ma)
{
	gotoxy(0,yNhap); cout << "Nhap ma sach can sua:";
	fflush(stdin);
	int ma_sach = NhapMaSach(22,yNhap, ma_sach);
		
	PTR_DMS p = Mang_DS.ds[ma]->dms;
	while (p!=NULL)
	{
		if (p->data.masach == ma_sach)
		{
			gotoxy(0,yNhap+2);	cout << "CHINH SUA VI TRI SACH";
			gotoxy(0,yNhap+4);	cout << "Vi tri:   -   ";
			string str = "";
			str = NhapViTri(8,yNhap+4,str);
			p->data.vitri = str;
			//InDS_DMS(p,Mang_DS.ds[ma]->ISBM);
			ThongBao("Cap nhat thanh cong");			
			return;
		}			
		else p=p->next;	
	}
	if(p==NULL) ThongBao("Khong tim thay sach!"); return;	
}

//====================In danh sach dau sach========================//
void InDSDauSach(DS_DauSach mang)
{
	for(int i=0; i<mang.sl; i++)
	{
		gotoxy(xListDS,yListDS+3+i);	cout << "|   |      |                        |                  |             |      |     |     |";
		gotoxy(xListDS+2,yListDS+3+i);	cout << i+1;
		gotoxy(xListDS+6,yListDS+3+i);	cout << mang.ds[i]->ISBM;
		gotoxy(xListDS+13,yListDS+3+i);	cout << mang.ds[i]->tensach;
		gotoxy(xListDS+38,yListDS+3+i);	cout << mang.ds[i]->tacgia;
		gotoxy(xListDS+56,yListDS+3+i);	cout << mang.ds[i]->theloai;
		gotoxy(xListDS+71,yListDS+3+i);	cout << mang.ds[i]->namxb;
		gotoxy(xListDS+78,yListDS+3+i);	cout << mang.ds[i]->trang;
		gotoxy(xListDS+84,yListDS+3+i);	cout << mang.ds[i]->nDMS;
		Sleep(20);
	}
}

//================Nhap the loai=================
string NhapTheLoai(int x, int y, string str)
{
	int i=0;
	
	int chr;
	do
	{
		gotoxy(x,y);	cout << "< " << DSTheLoai[i] << " >";
		fflush(stdin);
		chr= getch();
		if(chr==Enter)
		{
			return DSTheLoai[i];
		}
		else if(chr==Left)
				{
					if(i==0) i=nTheLoai-1;
					else i--;
				}
		else if(chr==Right)
				{
					if(i== (nTheLoai-1)) i=0;
					else i++;
				}
	} while(chr!=ESC);
	return " TBA";
}

//====================== QL DANH MUC SACH ==============================//
//==== Tim chuoi trong chuoi ===//
int NhapDeTimChuoiTrongChuoi(int x, int y, DS_DauSach mang)
{
	string str;
	char* c = new char[10];
	
	int vitri= 0;
	int n; //kiem tra so luong dau sach dang hien thi
	int key; //bien luu gia tri thu i thoa dieu kien
	int chr;
    do
	{
		gotoxy(x + vitri, y);
        fflush(stdin);
        chr = getch();
        if (chr == Enter && vitri != 0 && n==1)
        {
        	delete[] c;
            return key;
        }
        else if (chr == Back && vitri > 0)
        {
            vitri--;
            c[vitri]= '\0';
            gotoxy(x + vitri, y); cout << " ";
            gotoxy(x + vitri, y);
        }
        else if (((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == ' ' || chr>='0' && chr <= '9') && vitri < nameMAX)
        {
            if ( chr== ' ' && ( vitri==0 || c[vitri - 1]==' ')) continue;
			if ( vitri==0 || c[vitri - 1]==' ')	c[vitri] = char(toupper(chr));
            else c[vitri] = char(tolower(chr));
            cout << c[vitri];
            vitri++;
        }
        
        c[vitri]='\0';
        str=c;
        n=0;
        XoaDSDauSach();
        
        for(int i=0; i<mang.sl; i++)
        {
        	if(TimChuoiCon(str,mang.ds[i]->tensach)==1)
        	{
        		key++;
        		gotoxy(xListDS,yListDS+3+n);	cout << "|   |      |                        |                  |             |      |     |     |";
				gotoxy(xListDS+2,yListDS+3+n);	cout << n+1;
				gotoxy(xListDS+6,yListDS+3+n);	cout << mang.ds[i]->ISBM;
				gotoxy(xListDS+13,yListDS+3+n);	cout << mang.ds[i]->tensach;
				gotoxy(xListDS+38,yListDS+3+n);	cout << mang.ds[i]->tacgia;
				gotoxy(xListDS+56,yListDS+3+n);	cout << mang.ds[i]->theloai;
				gotoxy(xListDS+71,yListDS+3+n);	cout << mang.ds[i]->namxb;
				gotoxy(xListDS+78,yListDS+3+n);	cout << mang.ds[i]->trang;
				gotoxy(xListDS+84,yListDS+3+n);	cout << mang.ds[i]->nDMS;
				
				n++;
				key = i;
				Sleep(9);
			}
		}
    } while (chr != ESC);
    
    delete[] c;
    return -1;
}

//====
void runQLDMS(int key)
{
	//
	int nDMS= Mang_DS.ds[key]->nDMS;
	string isbn= Mang_DS.ds[key]->ISBM;
	VeKhungDS_DMS();
//	gotoxy(0,10); cout << isbn; Sleep(2222);
	//test
//	gotoxy(0,yNhap);
//	if(Mang_DS.ds[key]->dms == NULL) cout << "NULL";
//	else cout << "not NULL";
//	system("pause");
	//
	if(Mang_DS.ds[key]->dms == NULL)
	{
		ThongBao("DMS sach rong!");
	}
	else 
	{
//		gotoxy(xListDS+84,yListDS+);	cout << "here??";
//		gotoxy(xListDS+84,yListDS+3);	cout << Mang_DS.ds[key]->nDMS; //in lai SL Dau Sach
		InDS_DMS(Mang_DS.ds[key]->dms,isbn);
	}
	
	int chon;
	do
	{
		chon= MenuDongQLDMS(MenuQLDMS,xDS,yDS);
		switch(chon)
		{
			case 1: //Nhap sach moi
			{
				NhapDMS(key);
				if(Mang_DS.ds[key]->dms == NULL) ThongBao("Danh sach rong!!");
				else InDS_DMS(Mang_DS.ds[key]->dms,isbn);
				break;
			}
			case 2: //Sua vi tri
			{
				if(Mang_DS.ds[key]->dms == NULL) ThongBao("Danh sach rong!!");
				else suaViTriSach(key);
				InDS_DMS(Mang_DS.ds[key]->dms,isbn);
				break;
			}
			case 3: //Xoa sach moi
			{
				int check = XoaDMS(Mang_DS.ds[key]->dms,key);
				if(check==1) Mang_DS.ds[key]->nDMS--;
				//
				InDS_DMS(Mang_DS.ds[key]->dms,isbn);
				break;
			}
			case 4: //esc
			{
				XoaDSDauSach();
				return;
			}
		}
	}while(true);
}

//======= Ve giao dien ====
int MenuDongQLDMS(char td [itemDMS][35], int x, int y)
{
	//Co the sua
	Normal();
	ShowCur(false);
	XoaThongBao();
	XoaMenuQLDS();
	VeKhungMenuQLDS(itemDMS);
	
	//Khong duoc sua
	for (int i=0; i<itemDMS; i++)
	{
		gotoxy(x, y +i); cout << td[i];
	}
  	HighLight();
  	int chon =0;
  	gotoxy(x,y+chon);
  	cout << td[chon];
  	Normal();
  	int kytu;
	do {
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu) {
    		case Up:
				if (chon+1 >1) {
  		        	
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon --;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
  					
              		gotoxy(x,y+chon);
              		cout << td[chon];
  					chon = itemDMS -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <itemDMS) {
  		    		
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon ++;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
  				}
  				else {
					
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		chon = 0;
              		HighLight();
              		gotoxy(x,y+chon);
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

void VeKhungDS_DMS()
{
	gotoxy(xListDMS,yListDMS);		cout << "+---------------------------------------------------------------------------------------+";
	gotoxy(xListDMS,yListDMS+1);	cout << "| STT |   Ma Sach   |  Vi Tri  |    Trang Thai    |                Ghi Chu              |";
	gotoxy(xListDMS,yListDMS+2);	cout << "|-----+-------------+----------+------------------+-------------------------------------|";
//									cout << "|     |             |          |                  |                                     |";
//									cout << "                                                                                         ";
}
void XoaKhungDS_DMS()
{
	for(int j=yListDMS+3; j<25; j++)
	{
		gotoxy(xListDMS,j);
		cout << "                                                                                         ";
	}
}
void XoaNhapDMS()
{
	for(int j=yNhap; j<yTB; j++)
	{
		gotoxy(0,j); cout << "                               ";
	}
}
//========================================================================//
void NhapDMS(int key)
{
	int nDMS= Mang_DS.ds[key]->nDMS;
	
	gotoxy(0,yNhap);	cout << "Nhap so luong them: ";
	gotoxy(0,yNhap+1);	cout << "Ma sach: ";
	gotoxy(0,yNhap+2);	cout << "Vi tri:   -   ";
	
	int n; //so luong them
	while(1)
	{
		n= 1;
		fflush(stdin); n = NhapMaSach(20,yNhap,n);
		if(n==-1) return;
//		gotoxy(70,25); cout << n;
//		Sleep(2222);
//		gotoxy(70,25); cout << "          ";
		if((n + nDMS) > dmsMAX)
		{
			gotoxy(20,yNhap); cout << "Tong SL <= " << dmsMAX; Sleep(500);
			gotoxy(20,yNhap); cout << "              ";
			gotoxy(20,yNhap);
			continue;
		}
		else break;
	}
	int m=0; //luu ma sach lien truoc
	m = TimMaSachMax(Mang_DS.ds[key]->dms);
//	cout << endl << m; Sleep(999);
	gotoxy(9,yNhap+1); cout << Mang_DS.ds[key]->ISBM << setw(3) << setfill('0') << m+1 << " -> " << Mang_DS.ds[key]->ISBM << setw(3) << setfill('0') << m+n;
//	gotoxy(9,yNhap+1); cout << Mang_DS.ds[key]->ISBM << setw(3) << setfill('0') << m+1;

	string str = "";
	str = NhapViTri(8,yNhap+2,str);
	
	DMS s;
	s.trangthai = 0;
	s.vitri = str;
	s.masach = m+1;	
	
//	gotoxy(0,14); cout << "Hello"; system("pause");
//	
//	gotoxy(0,14); cout << s.trangthai;
//	gotoxy(0,15); cout << s.vitri;
//	gotoxy(0,16); cout << s.masach;
//	Sleep(5555);

//	Mang_DS.ds[key]->dms = KhoiTaoDMS(s);
	
//	while(Mang_DS.ds[key]->dms != NULL)
//	{
//		Mang_DS.ds[key]->dms->next;
//	}
	for(int i=0; i<n; i++)
	{
//		if(Mang_DS.ds[key]->dms == NULL)
//		{
//			Mang_DS.ds[key]->dms = new node_dms;
//			Mang_DS.ds[key]->dms->next = NULL;
//			Mang_DS.ds[key]->dms->data = s;
//		}
//		else
//		{
//			PTR_DMS q = Mang_DS.ds[key]->dms;
//			while(q->next!=NULL) q = q->next;
//		
//			PTR_DMS p = new node_dms;
//			p->next = NULL;
//			p->data = s;
//			q->next = p;
//		
//			InsertLast(Mang_DS.ds[key]->dms,s);
//		}
		InsertLast(Mang_DS.ds[key]->dms,s);
		
		s.masach++;
		Mang_DS.ds[key]->nDMS ++;
	}
	
	
//	PTR_DMS p = KhoiTaoDMS(s);
//	InsertLast(Mang_DS.ds[key]->dms,p);
//	
////	gotoxy(0,16); cout << Mang_DS.ds[key]->dms->data.masach;
//	
//	Mang_DS.ds[key]->nDMS += n;

//	for(int i=0; i<n; i++)
//	{
//		s.masach++;
//		InsertAfter(Mang_DS.ds[key]->dms,s);
//	}
	
//	Mang_DS.ds[key]->nDMS ++;

	ThongBao("Them DMS thanh cong!");
}

void InsertAfter(PTR_DMS p, DMS s)
{
	PTR_DMS q;
	if(p==NULL) ;
	else
	{
		q = new node_dms;
		q->data = s;
		q->next = p->next;
		p->next = q;
	}
}

void InsertFirst(PTR_DMS &First, DMS s)
{
	PTR_DMS p;
	p = new node_dms;
	p->data = s;
	p->next = First;
	First = p;
}

void InsertLast(PTR_DMS &First, DMS s)
{
	if(First==NULL)
	{
		First = new node_dms;
		First->next = NULL;
		First->data = s;
		
//		Mang_DS.ds[key]->nDMS ++;
	}
	else
	{
		PTR_DMS q = First;
		while(q->next!=NULL) q = q->next; // q->next = NULL;
		
		PTR_DMS p = new node_dms;
		p->next = NULL;
		p->data = s;
		q->next = p;
		
//		Mang_DS.ds[key]->nDMS ++;
	}
}

PTR_DMS KhoiTaoDMS(DMS s)
{
	PTR_DMS p = new node_dms;
	p->next = NULL;
	p->data = s;
	return p;
}

int TimMaSachMax(PTR_DMS First)
{
	if(First==NULL) return 0;
	do
	{
		if(First->next == NULL) return First->data.masach;
		else First = First->next;
	}while(1);
}

//================ In danh sach danh muc sach =================//
void InDS_DMS(PTR_DMS First, string isbn)
{
	if(First==NULL) return;
	XoaKhungDS_DMS();
	int i=0;
	while(First != NULL)
	{
		gotoxy(xListDMS,yListDMS+3+i);		cout << "|     |             |          |                  |                                     |";
		gotoxy(xListDMS+3,yListDMS+3+i);	cout << i+1;
		gotoxy(xListDMS+10,yListDMS+3+i);	cout << isbn << "-" << setw(3) << setfill('0') << First->data.masach;
		gotoxy(xListDMS+23,yListDMS+3+i);	cout << First->data.vitri[0] << " - " << First->data.vitri[1];
		gotoxy(xListDMS+36,yListDMS+3+i);	cout << TrangThaiSach[First->data.trangthai];
		First = First->next;
		i++;
		Sleep(20); //in cham cham cho dep :)
	}
	gotoxy(xListDS+84,yListDS+3);	cout << "  ";
	gotoxy(xListDS+84,yListDS+3);	cout << i; //in lai SL Dau Sach
}
//xoa danh muc sach
int DeleteFirstDMS(PTR_DMS &First)
{
	if(First==NULL) return 0;
	PTR_DMS p = First;
	First = p->next;
	delete p;
	return 1;
}
int DeleteAfterDMS(PTR_DMS p)
{
	if(p==NULL || p->next==NULL) return 0;
	PTR_DMS q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}
//
int XoaDMS(PTR_DMS &First, int key)
{
	if(First==NULL)
	{
		ThongBao("DANH SACH DMS RONG!");
		return 0;
	}
	
	gotoxy(0,yNhap); cout << "Nhap ma sach >> ";
	int masach;
	int check;
	PTR_DMS p, q;
	while(1)
	{
		check = 0;
		masach = 0;
		masach = NhapSo(16,yNhap,masach);
		if(masach==0) return 0;
		//
		if(First->data.masach==masach)
		{
			//kiem tra dms co the xoa hay khong
			bool kt = BatDKXoaDMS(First,key);
			if(kt==false)
			{
				ThongBao("KHONG THE XOA DMS NAY");
				return 0;
			}
			//xac nhan xoa
			gotoxy(0,yNhap+1);	cout << "Nhap lai ma de xoa >> ";
			check = NhapSo(22,yNhap+1,check);
			if(check!=masach)
			{
				ThongBao("KHONG XOA!");
				return 0;
			}
			//
			check = DeleteFirstDMS(First);
			if(check==1)
			{
				ThongBao("XOA THANH CONG!");
				return 1;
			}
			else
			{
				ThongBao("XOA THAT BAI");
				return 0;
			}
		}
		//
		p = First;
		q = p->next;
		while(1)
		{
			if(q->data.masach==masach)
			{
				//kiem tra dms co the xoa hay khong
				bool kt = BatDKXoaDMS(q,key);
				if(kt==false)
				{
					ThongBao("KHONG THE XOA DMS NAY");
					return 0;
				}
				//xac nhan xoa
				gotoxy(0,yNhap+1);	cout << "Nhap lai ma de xoa >> ";
				check = NhapSo(22,yNhap+1,check);
				if(check!=masach)
				{
					ThongBao("KHONG XOA!");
					return 0;
				}
				//
				check = DeleteAfterDMS(p);
				if(check==1)
				{
					ThongBao("XOA THANH CONG!");
					return 1;
				}
				else
				{
					ThongBao("XOA THAT BAI");
					return 0;
				}
			}
			q = q->next;
			if(q==NULL) break;
			else p = p->next;
		}
		ThongBao("KHONG TIM THAY MA!");
		XoaNhapDMS();
		gotoxy(0,yNhap); cout << "Nhap ma sach >> ";
	}
	
}
bool BatDKXoaDMS(PTR_DMS q, int key)
{
	int l = Mang_DS.ds[key]->luotmuon;
	int n = Mang_DS.ds[key]->nDMS;
	int t = q->data.trangthai;
	//
	if(t!=1 && (n>1 || (n==1&&l==0)))	return true;
	return false;
}
//========================================================================///
//========================== DOC / GHI FILE ===============================//
void GhiDSDauSach()
{
	clearFileContent(dausach_mang);
	//mo file
	ofstream FileOut;
	FileOut.open(dausach_mang, ios_base::out);
	if(FileOut.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file dausach_mang de ghi!" << endl;
		system("pause");
		return;
	}
	//ghi file
	int n= Mang_DS.sl;
	PTR_DMS First = NULL;
//	PTR_DMS p = NULL;
	FileOut << n;
//	FileOut << Mang_DS.ds[0]->ISBM << "|" << Mang_DS.ds[0]->tensach << "|" << Mang_DS.ds[0]->tacgia << "|" << Mang_DS.ds[0]->theloai << "|" << Mang_DS.ds[0]->namxb << "|" << Mang_DS.ds[0]->trang << "|" << Mang_DS.ds[0]->nDMS;                          //
	for(int i=0; i<n; i++)
	{
		FileOut << endl << Mang_DS.ds[i]->ISBM << "|" << Mang_DS.ds[i]->tensach << "|" << Mang_DS.ds[i]->tacgia << "|" << Mang_DS.ds[i]->theloai << "|" << Mang_DS.ds[i]->namxb << "|" << Mang_DS.ds[i]->trang << "|" << Mang_DS.ds[i]->luotmuon << "|" << Mang_DS.ds[i]->nDMS;                   //
		//danh muc sach??
		First = Mang_DS.ds[i]->dms;
		while(First!=NULL)
		{
			FileOut << endl << First->data.masach << "|" << First->data.trangthai << "|" << First->data.vitri;
			First = First->next;
		}
	}
	
	//dong file
	FileOut.close();
	cout << "Ghi file dausach_mang thanh cong!" << endl;
	Sleep(500);
	//system("pause");
}

void DocDSDauSach()
{
	//
	ifstream FileIn;
	FileIn.open(dausach_mang, ios_base::in);
	if(FileIn.fail() == true)
	{
		cout << "ERROR: Khong mo duoc file dausach_mang de doc!!" << endl;
		system("pause");
		return;
	}
	//
	FileIn >> Mang_DS.sl;
	FileIn.ignore();
	for(int i=0; i<Mang_DS.sl; i++)
	{
		Mang_DS.ds[i] = new dausach;
		getline(FileIn, Mang_DS.ds[i]->ISBM, '|');
		getline(FileIn, Mang_DS.ds[i]->tensach, '|');
		getline(FileIn, Mang_DS.ds[i]->tacgia, '|');
		getline(FileIn, Mang_DS.ds[i]->theloai, '|');
		FileIn >> Mang_DS.ds[i]->namxb;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->trang;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->luotmuon;
		FileIn.ignore();
		FileIn >> Mang_DS.ds[i]->nDMS;
		FileIn.ignore();// /n
		//ghi danh muc sach ??
		PTR_DMS First = NULL;
		danhmucsach d;
		int n = Mang_DS.ds[i]->nDMS;
//		cout << "them xong dau sach"; Sleep(500);
		if(n==0)
		{
			continue;
		}
		else 
		for(int j=0; j<n; j++)
		{
			FileIn >> d.masach;
			FileIn.ignore();
			FileIn >> d.trangthai;
			FileIn.ignore();
			getline(FileIn, d.vitri, '\n');
//			cout << "truoc insertlast" << endl; Sleep(500);
			InsertLast(First,d);
		}
//		Mang_DS.ds[i]->dms = new node_dms;
//		Mang_DS.ds[i]->dms = NULL;
		Mang_DS.ds[i]->dms = First;
//		Mang_DS.ds[i]->dms->data = First->data;
//		delete First;
	}
	//
	FileIn.close();
	cout << "Doc file dausach_mang thanh cong!" << endl;
	Sleep(500);
}








// ============== ^$%$^%(%$@(_%$^&*%#^ =============== //

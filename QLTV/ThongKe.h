#pragma once

#include "QLDG.h"
#include "QLDauSach.h"

#define itemTK 4
#define xMenuTK 2
#define yMenuTK 1
#define xQH 42
#define yQH 5

char MenuTK[itemTK][35]=
{
	"  IN TOP 10 SACH MUON CHAY    ",
	"  IN DS DOC GIA THAN THIET    ",
	"  IN DS DOC GIA MUON QUA HAN  ",
	"  THOAT                       "
};

struct QuaHan
{
	int maDG;
	string ho;
	string ten;
	int soNgay;
	string maISBN;
	int maDMS;
};

struct DSQuaHan
{
	int sl;
	QuaHan ds[100];
};

DSQuaHan KhoiTaoDSQuaHan()
{
	DSQuaHan qh;
	qh.sl = 0;
	return qh;
}

DSQuaHan qh = KhoiTaoDSQuaHan();

// ========================================================= //
int MenuDongTK(char td [itemTK][35],int x, int y);
void VeKhungTK();
void XoaDS_TK();
void NhanESCDeThoat();
//qua han
void ThongKeQuaHan(TREE_DG &tre);
void InDSQuaHan(DSQuaHan list);
void SortListQH();
//top10 sach
int ListIndex[MaxOfDauSach];
void IndexTheoLuotMuon(DS_DauSach ds);
void InTop10Sach();
//top10 doc gia
void SapXepTheoSoLuotMuon(NODE_DG *arr[], int &nds);
void InTop10DocGia(NODE_DG *arr[], int &nds);
// =========================== HAM XU LI ============================= //
void runThongKe()
{
	system("cls");
	KhungThongBao();
	VeKhungTK();
	
	int chon;
	do
	{
		chon = MenuDongTK(MenuTK,xMenuTK+1,yMenuTK+1);
		switch(chon)
		{
			case 1: //top 10 sach muon nhieu nhat
			{
				XoaDS_TK();
				
				IndexTheoLuotMuon(Mang_DS);
//				gotoxy(40,0);
//				for(int i=0; i<10; i++) cout << ListIndex[i] << "  ";
//				Sleep(5555);
				InTop10Sach();
//				NhanESCDeThoat();
				break;
			}
			case 2: //ds doc gia than thiet
			{
				if(tree==NULL)
				{
					ThongBao("DANH SACH RONG!");
					break;
				}
				//
				XoaDS_TK();
				//
				NODE_DG *arr[100];
				int nds=0;
				ChuyenCaySangMang(tree, arr, nds);
//				SapXepTheoTen(ds,nds);
				SapXepTheoSoLuotMuon(arr,nds);
				InTop10DocGia(arr,nds);
				
				break;
			}
			case 3: //ds doc gia muon qua han
			{
				XoaDS_TK();
				//
				qh.sl=0;
				ThongKeQuaHan(tree);
				SortListQH();
				InDSQuaHan(qh);
//				NhanESCDeThoat();
				break;
			}
			case 4: //thoat
			{
				break;
			}
		}
	} while(chon!=4);
	
}
int MenuDongTK(char td [itemTK][35],int x, int y)
{
	ShowCur(false);
	int chon =0;
	int i; 
	for ( i=0; i< itemTK ; i++) {
		gotoxy(x, y +i);
    	cout << td[i];
	}
  	HighLight();
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
  					chon = itemTK -1;
              		HighLight();
              		gotoxy(x,y+chon);
              		cout << td[chon];
              		Normal();
				}
  				break;
  			case Down:
				if (chon+1 <itemTK) {
  		    		
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
void VeKhungTK()
{
	gotoxy(xMenuTK,yMenuTK);	cout << "+------------------------------+";
	for(int i=0; i<itemTK; i++)
	{
		gotoxy(xMenuTK,yMenuTK+1+i);	cout << "|                              |";
	}
	gotoxy(xMenuTK,yMenuTK+1+itemTK);	cout << "+------------------------------+";
}
void XoaDS_TK()
{
	for(int j=0; j<30; j++)
	{
		gotoxy(xQH,j); cout << "                                                                                   ";
	}
}
void NhanESCDeThoat()
{
	int k;
	do
	{
		k = getch();
		if(k==ESC) return;
		ThongBao("NHAN ESC DE THOAT");
	}while(1);
}
// === THONG KE QUA HAN === //
void ThongKeQuaHan(TREE_DG &tre)
{
	if(tre==NULL)	return;
	
	if(tre->data.mt!=NULL)
	{
		PTR_MT mt = tre->data.mt;
		while(mt!=NULL)
		{
			int dem = CountDay(mt->data.ngayMuon);
			if(mt->data.trangthai==0 && dem>7)
			{
				qh.ds[qh.sl].maDG = tre->data.mathe;
				qh.ds[qh.sl].ho = tre->data.ho;
				qh.ds[qh.sl].ten = tre->data.ten;
				qh.ds[qh.sl].soNgay = dem;
				qh.ds[qh.sl].maISBN = mt->data.isbn;
				qh.ds[qh.sl].maDMS =mt->data.masach;
				
				qh.sl++;
				//khoa the doc gia
				tre->data.trangthaithe = 0;
			}
			mt = mt->next;
		}
	}
	ThongKeQuaHan(tre->left);
	ThongKeQuaHan(tre->right);

}

void InDSQuaHan(DSQuaHan list)
{
	if(list.sl==0)
	{
		ThongBao("DS QUA HAN RONG!");
		return;
	} 
	
	gotoxy(xQH,yQH-2);	cout << "+--------------------------------------------------------------------------------+";
	gotoxy(xQH,yQH-1);	cout << "|                     DANH SACH DOC GIA MUON SACH QUA 7 NGAY                     |";
	gotoxy(xQH,yQH);	cout << "|--------------------------------------------------------------------------------|";
	gotoxy(xQH,yQH+1);	cout << "| STT | MA DG |           HO TEN          |SO NGAY|    MA MT    |    GHI CHU     |";
	gotoxy(xQH,yQH+2);	cout << "|-----+-------+---------------------------+-------+-------------+----------------|";
//						cout << "|     |       |                           |       |             | DA BI KHOA THE |";
	for(int i=0; i<list.sl; i++)
	{
		gotoxy(xQH,yQH+3+i);		cout << "|     |       |                           |       |             | DA BI KHOA THE |";
		gotoxy(xQH+2,yQH+3+i);		cout << i+1;
		gotoxy(xQH+9,yQH+3+i);		cout << list.ds[i].maDG;
		gotoxy(xQH+17,yQH+3+i);		cout << list.ds[i].ho << " " << list.ds[i].ten;
		gotoxy(xQH+45,yQH+3+i);		cout << list.ds[i].soNgay;
		gotoxy(xQH+53,yQH+3+i);		cout << list.ds[i].maISBN << "-" << setw(3) << setfill('0') << list.ds[i].maDMS;
		
		Sleep(19);
	}
}
void SortListQH()
{
	int imax;
	for(int i=0; i<qh.sl-1; i++)
	{
		imax=i;
		for(int j=i+1; j<qh.sl;j++)
		{
			if(qh.ds[imax].soNgay < qh.ds[j].soNgay) imax=j;
		}
		if(imax!=i) swap(qh.ds[imax],qh.ds[i]);
	}
}
// ====== TOP 10 SACH MUON CHAY ===== //
void IndexTheoLuotMuon(DS_DauSach ds)
{
	int n=ds.sl;
	//
	int k = 0;
	ListIndex[k] = 0; //them index dau tien
	k++;
	//
	for(int i=1; i<n; i++)
	{
		ListIndex[i]=i;
		k++;
		int j=i;
		while(j>0 && ds.ds[ListIndex[j]]->luotmuon > ds.ds[ListIndex[j-1]]->luotmuon)
		{
			swap(ListIndex[j],ListIndex[j-1]);
			j--;
		}
	}
}
void InTop10Sach()
{
	gotoxy(xQH,yQH-2);	cout << "+---------------------------------------------------------------------------------+";
	gotoxy(xQH,yQH-1);	cout << "|                          TOP 10 SACH DUOC MUON NHIEU NHAT                       |";
	gotoxy(xQH,yQH);	cout << "+---------------------------------------------------------------------------------+";
	gotoxy(xQH,yQH+1);	cout << "| STT | MA SACH |           TEN SACH           |         TAC GIA         |LUOTMUON|";
	gotoxy(xQH,yQH+2);	cout << "|---------------------------------------------------------------------------------|";
//						cout << "|     |         |                              |                         |        |";
	
	int n;
	if(Mang_DS.sl<10) n = Mang_DS.sl;
	else n = 10;
	
	for(int i=0; i<n; i++)
	{
		gotoxy(xQH,yQH+3+i);	cout << "|     |         |                              |                         |        |";
		gotoxy(xQH+2,yQH+3+i);	cout << i+1;
		gotoxy(xQH+9,yQH+3+i);	cout << Mang_DS.ds[ListIndex[i]]->ISBM;
		gotoxy(xQH+19,yQH+3+i);	cout << Mang_DS.ds[ListIndex[i]]->tensach;
		gotoxy(xQH+50,yQH+3+i);	cout << Mang_DS.ds[ListIndex[i]]->tacgia;
		gotoxy(xQH+77,yQH+3+i);	cout << Mang_DS.ds[ListIndex[i]]->luotmuon;
	}
	
	gotoxy(xQH,yQH+3+n);	cout << "+---------------------------------------------------------------------------------+";
}
// ========= TOP DOC GIA MUON NHIEU SACH NHAT ========== //
void SapXepTheoSoLuotMuon(NODE_DG *arr[], int &nds)
{
	int imax;
	for(int i=0; i<nds-1; i++)
	{
		imax = i;
		for(int j=i+1; j<nds; j++)
		{
			if(arr[j]->data.nMT > arr[imax]->data.nMT) imax = j;
//			else if(arr[i]->data.nMT == arr[imax]->data.nMT && arr[i]->data.ho > arr[j]->data.ten) HoanViDG(arr[i],arr[j]);
		}
		if(imax!=i) HoanViDG(arr[i],arr[imax]);
	}
}
void InTop10DocGia(NODE_DG *arr[], int &nds)
{
	int n;
	if(nds>=10) n = 10;
	else n = nds;
	//
	gotoxy(xQH,yQH-2);	cout << "+---------------------------------------------------------------------------------+";
	gotoxy(xQH,yQH-1);	cout << "|                       TOP 10 DOC GIA MUON NHIEU SACH NHAT                       |";
	gotoxy(xQH,yQH);	cout << "+---------------------------------------------------------------------------------+";
	gotoxy(xQH,yQH+1);	cout << "| STT |  MA DG  |             HO TEN                   | LUOT MUON |TRANG THAI THE|";
	gotoxy(xQH,yQH+2);	cout << "|---------------------------------------------------------------------------------|";
//						cout << "|     |         |                                      |           |              |";
	for(int i=0; i<n; i++)
	{
		gotoxy(xQH,yQH+3+i);		cout << "|     |         |                                      |           |              |";
		gotoxy(xQH+3,yQH+3+i);		cout << i+1;
		gotoxy(xQH+10,yQH+3+i);		cout << arr[i]->data.mathe;
		gotoxy(xQH+21,yQH+3+i);		cout << arr[i]->data.ho<< " " << arr[i]->data.ten;
		gotoxy(xQH+60,yQH+3+i);		cout << arr[i]->data.nMT;
		gotoxy(xQH+70,yQH+3+i);		if(arr[i]->data.trangthaithe == 1) cout << "HOAT DONG";
									else if(arr[i]->data.trangthaithe == 0) cout << "DA BI KHOA";
									else if(arr[i]->data.trangthaithe == -1) cout << " MOI TAO";
		Sleep(15);
	}
	gotoxy(xQH,yQH+3+n);	cout << "+---------------------------------------------------------------------------------+";
}




// ========================================== by ngoclinh =========================================== //

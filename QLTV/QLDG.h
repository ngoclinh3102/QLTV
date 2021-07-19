#pragma once

#include <iostream>
#include "DocGia.h"
#include "GiaoDien.h"
using namespace std;

#define ESC 27
//===============Ve Khung==============
void KhungTieuDe();
void XoaMenuChon();
void MenuQLDG();

//===============Nhap doc gia==========
void NhapDG(TREE_DG &tree);

//===============Xuat danh sach doc gia====
void ChuyenCaySangMang(TREE_DG tree, NODE_DG *ds[], int &nds);
void XuatDSDG(NODE_DG *ds[], int &nds);
void InDSDG(NODE_DG *ds[], int &nds);

//Ham xu li 
void runQLDG() {
	system("cls");
	Normal();
	KhungTieuDe();
	MenuQLDG();
	TREE_DG tree = NULL;
	bool kt= true;
	while(kt)
	{
		//system("cls");
		XoaMenuChon();
		gotoxy(0,5); cout << " >>> Nhap lua chon: ";
		int chon; cin >> chon;
		switch(chon)
		{
			case 1:
			{
				NhapDG(tree);
				cout << "Nhap thanh cong!";
				Sleep(400);
				break;
			}
			case 2:
			{
				NODE_DG *ds[100];
				int nds=0;
				ChuyenCaySangMang(tree, ds, nds);
				//XuatDSDG(ds,nds);
				InDSDG(ds,nds);
				break;
			}
			case 0:
			{
				kt= false;
				break;
			}
			default:
			{
				cout << "Chon sai!";
				Sleep(500);
				break;
			}
		}
	}
	
}

//============Ve khung de xuat danh sach======
void KhungTieuDe()
{
	gotoxy(40,0); cout << "+-------------------------------------------------------------------------------+";
	gotoxy(40,1); cout << "| STT |  Ma The  |        Ho        |     Ten     | Phai |Trang thai the|Ghi chu|";
	gotoxy(40,2); cout << "+-----+----------+------------------+-------------+------+--------------+-------+";
//	gotoxy(40,3); cout << "|     |          |                  |             |      |              |       |";
	
}
void XoaMenuChon()
{
	for(int i=5; i<30; i++)
		for(int j=0; j<35; j++)
		{
			gotoxy(j,i);
			cout << " ";
		}
}
void MenuQLDG()
{
	gotoxy(0,0);
	cout << "+-----------------------------+" << endl;
	cout << "|      1. Nhap doc gia        |" << endl;
	cout << "|  2. Xuat danh sach doc gia  |" << endl;
	cout << "|         0. Thoat            |" << endl;
	cout << "+-----------------------------+" << endl;
	
}

//================Nhap doc gia================
void NhapDG(TREE_DG &tree)
{
//	system("cls");
	NODE_DG *p = KhoiTaoNode_DocGia();
	cin.ignore();
	DSMaThe[0]++;
	int i= DSMaThe[0];
	p->data.mathe= DSMaThe[i];
	cout << "Ma the: " << p->key << endl;
	cout << "Nhap ho: "; getline(cin, p->data.ho);
	cout << "Nhap ten: "; getline(cin, p->data.ten);
	cout << "Nhap phai: "; getline(cin, p->data.phai);
	
	Them_DG(tree,p);
	
}
//==============Xuat danh sach doc gia===========
void ChuyenCaySangMang(TREE_DG tree, NODE_DG *ds[], int &nds)
{
	if(tree != NULL)
	{
		ChuyenCaySangMang(tree->left,ds,nds);
		
		ds[nds] = new NODE_DG;
		ds[nds]->key = tree->key;
		ds[nds]->data = tree->data;
		nds++;
		
		ChuyenCaySangMang(tree->right,ds,nds);
	}
}

void XuatDSDG(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++)
	{
		cout << "\t===Nhan vien " << i+1 << ":" << endl;
		cout << "Ma the: " << ds[i]->data.mathe << endl;
		cout << "Ho: " << ds[i]->data.ho << endl;
		cout << "Ten: " << ds[i]->data.ten << endl;
		cout << "Phai: " << ds[i]->data.phai << endl;
		cout << "Trang thai the: ";
			if(ds[i]->data.trangthaithe == 1) cout << "Dang hoat dong" << endl;
			else if(ds[i]->data.trangthaithe == 0) cout << "Da bi khoa" << endl;
	}
	system("pause");
}
void InDSDG(NODE_DG *ds[], int &nds)
{
	for(int i=0; i<nds; i++)
	{
		gotoxy(40,3+i); cout << "|     |          |                  |             |      |              |       |";
		gotoxy(42,3+i); cout << i+1;
		gotoxy(49,3+i); cout << ds[i]->data.mathe;
		gotoxy(61,3+i); cout << ds[i]->data.ho;
		gotoxy(79,3+i); cout << ds[i]->data.ten;
		gotoxy(92,3+i); cout << ds[i]->data.phai;
		gotoxy(98,3+i); if(ds[i]->data.trangthaithe == 1) cout << "Dang hoat dong" << endl;
						else if(ds[i]->data.trangthaithe == 0) cout << " Da bi khoa" << endl;
	}
}







#pragma once

#include "DanhMucSach.h"
#include "DauSach.h"
#include "NgayThangNam.h"


//=====MUON TRA=====
struct muontra
{
	string masach;
	Date ngaymuon;
	Date ngaytra;
	int trangthai; // =0 Dang muon, =1 Da tra, =2 làm mat sách
	
	// them vao... khong co trong yeu cau
	string tensach;
	string vitrisach;
};
typedef struct MuonTra MUON_TRA;

struct node_muontra
{
	MUON_TRA data;
	node_muontra* next;
};
typedef struct node_muontra* PTR_MT;
struct ListMT
{
	// so phan tu
	int n;
	NODE_MT *pHead;
	NODE_MT *pTail;

};
typedef struct ListMT LIST_MT;


//=====================Ham Co Ban========================
// ..... khoi tao........
void CreateList_MT(LIST_MT &l);

// kiem tra rong
bool ListMTIsEmpty(LIST_DMS l);

// get node bat ki
NODE_MT* GetNode_MT(MUON_TRA DATA);

//them vao dau ds
void AddHeadList_MT(LIST_MT &l, MUON_TRA data);

//them vao cuoi ds
void AddTailList_MT(LIST_MT &l, MUON_TRA data);

//them vao sau node bat ki
void InsertAfterQ(LIST_MTt& l, MUON_TRA p, MUON_TRA q)

//xoa toan bo danh sach
void ClearAll_ListMT(LIST_MT &l);

// ham kiem tra doc gia co lam mat sach hay khong? .Co thi tra lai 1, khong thi tra lai 0.
int MatSach(LIST_MT lMT);

int SoNgayMuon_Max(LIST_MT lMT);

int SoNgayQuaHan(LIST_MT lMT);



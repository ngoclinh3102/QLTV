#define MAX 300 //so luong dau sach toi da
//=====DANH MUC S�CH=====
struct danhmucsach 	// s�ch
{
	string masach;
	int trangthai; // =0 cho muon duoc, =1 da co doc gia muon, =2 s�ch da thanh l�
	string vitri;
};

struct node_DMS
{
	danhmucsach data;
	node_DMS* next;
};
typedef node_DMS* PTR_DMS;

//=====DAU S�CH=====
struct dausach
{
	string ISBN; // m� s�ch theo chu?n qu?c t?
	string tensach;
	int sotrang;
	string tacgia;
	int namxuatban;
	string theloai;
	int soluotmuon; // Bien luu tru so luot muon sach cua doc gia dung de thong ke sach muon nhieu nhat
	PTR_DMS dms; // con tro tro den sach thuoc dau sach tuong ung
};

struct list_dausach
{
	int n;
	dausach* ds[MAX];
};
typedef struct list_dausach LIST_DS;

//=====NG�Y TH�NG NAM=====
struct Date
{
	int ngay;
	int thang;
	int nam;
};
//=====MUON TRA=====
struct muontra
{
	string masach;
	Date ngaymuon;
	Date ngaytra;
	int trangthai; // =0 Dang muon, =1 Da tra, =2 l�m mat s�ch
};
struct node_muontra
{
	muontra data;
	node_muontra* next;
};
typedef struct node_muontra* PTR_MT;

//=====DOC GIA=====
struct docgia
{
	int mathe;	//key
	string ho;
	string ten;
	string phai;
	int trangthaithe; // =0 khoa, =1 hoat dong
	PTR_MT mt; // con tro se tro den danh sach cac cuon da va dang muon
};

struct node_docgia
{
	docgia data;
	node_docgia* left;
	node_docgia* right;
};
typedef struct node_docgia* TREE_DG;


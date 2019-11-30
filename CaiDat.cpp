#include "ThuVien.h"
#pragma region =================================================== Support =====================================================
string Transform(string A)
{
	string Value = "";
	for (unsigned int i = 0; i < A.size(); i++)
	{
		if (A[i] >= 'A'&&A[i] <= 'Z')
			Value += A[i] + 32;
		else
			Value += A[i];
	}
	return Value;
}


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool kiemtraso(string chuoi)
{
	if (chuoi == "") return false;
	for (unsigned int i = 0; i < chuoi.size(); i++)
	{
		if (chuoi[i] <'0' || chuoi[i] > '9')
			return false;
	}
	return true;
}

string kiemtrachuoi(string title)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	string chuoi = "";
	do{
		SetConsoleTextAttribute(h, 7);
		cout << "\n" << title; getline(cin, chuoi);
		if (chuoi == ""){
			SetConsoleTextAttribute(h, 14);
			cout << "Ko duoc de trong !\n";
		}
	} while (chuoi == "");
	return chuoi;
}
string XoaBoKhoangTrang(string chuoi)
{
	string kq = "";
	for (unsigned int i = 0; i < chuoi.size(); i++)
	{
		if (chuoi[i] != ' ')
			kq += chuoi[i];
		else continue;
	}
	return kq;
}
int nhapsonguyen(string title)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	string chuoi;
vonglap:
	fflush(stdin);
	SetConsoleTextAttribute(h, 7);
	cout << "\n" << title;

	getline(cin, chuoi);
	if (!kiemtraso(chuoi)){
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Nhap Sai ! Xin Nhap Lai ! (khong ghi so am || chu ) \n";
		goto vonglap;
	}
	else return atoi(chuoi.c_str());
}
#pragma endregion

#pragma region ============================================ Menu ================================================
void gioithieu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n\n";
	SetConsoleTextAttribute(h, 11);
	cout << "===== ==  == ======= ==   == =====      ==   == ==  ==      =      ===       ===     ====== ==  ==\n";
	SetConsoleTextAttribute(h, 12);
	cout << "=   = ==  == ==   == ===  == ==  =      == ==   ==  ==    == ==    == ==   == ==     ====== ==  ==\n";
	SetConsoleTextAttribute(h, 13);
	cout << "===== ====== ==   == == = == ==         ===     ======   =======   ==  == ==  ==       ==   ==  ==\n";
	SetConsoleTextAttribute(h, 14);
	cout << "=     ==  == ==   == ==  === == ===     == ==   ==  ==  ==     ==  ==   ===   ==       ==   ======\n";
	SetConsoleTextAttribute(h, 10);
	cout << "=     ==  == ======= ==   == =====      ==   == ==  == ==       == ==    =    ==       ==   ======\n";
	SetConsoleTextAttribute(h, 15);
}
void menu()
{
	gioithieu();
	gotoxy(0, 12);
	cout << "================================================== PHONG KHAM TU ==========================================\n";
	cout << "1.Quan Ly Benh Nhan\n";
	cout << "2.Quan Ly Kho Thuoc\n";
	cout << "3.Thong Ke\n";
	cout << "4.Quan Ly Dich Vu - Vat Lieu Y Te\n";
	cout << "0. Thoat\n";
	cout << "====================================================== END ================================================";
}

	cout << "\n============================================= XUAT DS BENH NHAN ==========================================\n";
	cout << "1.Xuat Toan Bo\n";
	cout << "2.Xuat Theo Gioi Tinh\n";
	cout << "3.Xuat Theo Ngay Kham\n";
	cout << "====================================================== END ================================================";
}
void menu_thuoc()
{
	gioithieu();
	gotoxy(0, 12);
	cout << "============================================= QUAN LY KHO THUOC ==========================================\n";
	cout << "1.Them Thuoc Moi \n";
	cout << "2.Xoa Thuoc\n";
	cout << "3.Tim Thuoc \n";// -> Thêm số lượng thuốc , sửa thuốc
	cout << "4.Xuat Danh Sach Thuoc \n";
	cout << "0. Thoat\n";
	cout << "====================================================== END ================================================";
}
void menu_timthuoc()
{
	cout << "============================================= CAP NHAP THUOC ==============================================\n";
	cout << "1.Them so luong thuoc\n";
	cout << "2.Sua thong tin thuoc\n";
	cout << "0.Thoat\n";
	cout << "====================================================== END ================================================";
}

	gioithieu();
	gotoxy(0, 12);
	cout << "================================================== VAT LIEU Y TE ===============================================\n";
	cout << "1.Them Vat Lieu Y Te\n";
	cout << "2.Xoa Vat Lieu Y Te\n";
	cout << "3.Sua Thong Tin Vat Lieu Y Te\n";
	cout << "4.Xuat Danh Sach Vat Lieu Y Te\n";
	cout << "0. Thoat\n";
	cout << "====================================================== END ================================================";
}
#pragma endregion

#pragma region =================================== Chuc Nang ====================================

#pragma region ======================================= Thuoc =========================================
void khoitao_dsthuoc(DSThuoc &ds)
{
	ds = NULL;
}
bool kiemtra_dst_rong(DSThuoc dst)
{
	return dst == NULL;
}
NODE_Thuoc* tao_node_Thuoc(Thuoc thuoc)
{
	NODE_Thuoc* p = new NODE_Thuoc;
	p->data = thuoc;
	p->next = NULL;
	return p;
}


int themthuoc(DSThuoc &ht, int &code)
{

	Thuoc a;
	a.Nhap(code);
	code++;
	NODE_Thuoc* p = new NODE_Thuoc;
	p->data = a;
	p->next = NULL;
	if (ht == NULL) ht = p;
	else {
		NODE_Thuoc* t = ht;
		do {
			if (t->next == NULL) break;
			else t = t->next;
		} while (1);
		t->next = p;
	}
	return 1;
}
NODE_Thuoc*	timkiemthuoc_TheoMa(DSThuoc ht, int a)
{
	NODE_Thuoc* cantim;
	khoitao_dsthuoc(cantim);
	NODE_Thuoc* p = ht;
	while (p != NULL)
	{
		if (p->data.ma == a) {
			cantim = p;
			break;
		}
		p = p->next;
	}
	return cantim;
}




bool themsoluongthuoc(NODE_Thuoc* &thuoc, int soluong)
{
	if (soluong >= 0)
	{
		thuoc->data.sltonkho += soluong;
		return true;
	}
	return false;
}


void suathongtinthuoc(NODE_Thuoc* &thuoc)
{
	cout << "Ten Moi : "; getline(cin, thuoc->data.ten);
	cout << "DVT : "; getline(cin, thuoc->data.dvt);
	thuoc->data.dongia = nhapsonguyen("Don Gia : ");
	cout << "Sua Thong Tin Thuoc Thanh Cong !\n";
}

int xoathuoc(DSThuoc &ht, int a)
{

	NODE_Thuoc* p = ht;
	if (p != NULL)
	{
		if (p->data.ma == a)
		{
			if (ht->data.slttsohuu) return 0;
			ht = ht->next;
			delete p;
			return 1;
		}
		else
		{
			NODE_Thuoc* before = p;
			p = p->next;
			while (p != NULL&&p->data.ma != a)
			{
				before = p;
				p = p->next;
			}
			if (p != NULL&&!p->data.slttsohuu)
			{
				before->next = p->next;
				delete p;
				return 1;
			}
		}
	}
	return 0;
}
void xuatdsthuoc(DSThuoc ht)
{

	NODE_Thuoc* p = ht;

	gotoxy(40, 3);
	cout << "DANH SACH THUOC\n\n";
	cout << setw(10) << left << "Ma Thuoc";
	cout << setw(30) << left << "Ten Thuoc";
	cout << setw(10) << left << "DVT";
	cout << setw(15) << left << "Don Gia";
	cout << setw(15) << left << "Ton Kho";
	cout << setw(20) << left << "Tinh Trang" << endl;
	cout << setfill('-');
	cout << setw(100) << "-" << endl;
	cout << setfill(' ');
	while (p != NULL)
	{
		p->data.xuat();
		p = p->next;
	}
	cout << setfill('-');
	cout << setw(100) << "-" << endl;
	cout << setfill(' ');
	cout << "\n";
}
void giaiphongdsthuoc(DSThuoc &ht)
{
	NODE_Thuoc* p;
	while (ht != NULL)
	{
		p = ht;
		ht = ht->next;
		delete p;
	}
}
#pragma endregion
#pragma region ============================ File ==============================
void DocFileDSThuoc(ifstream &FileIn, DSThuoc &ht, int &size)
{
	if (!FileIn);
	else{
		FileIn >> size;
		if (size == -99){
			size = 1;
			return;
		}
		NODE_Thuoc* p;
		while (!FileIn.eof())
		{
			p = new NODE_Thuoc;
			FileIn >> p->data.ma;
			FileIn.seekg(1, 1);
			getline(FileIn, p->data.ten, '-');
			FileIn >> p->data.dongia;
			FileIn.seekg(1, 1);
			FileIn >> p->data.sltonkho;
			FileIn.seekg(1, 1);


			FileIn >> p->data.slttsohuu;
			FileIn.seekg(1, 1);
			getline(FileIn, p->data.dvt);
			p->next = NULL;
			if (ht == NULL)
				ht = p;
			else
			{
				NODE_Thuoc* s = ht;
				while (s->next != NULL) s = s->next;
				s->next = p;
			}
		}
	}
}

void GhiFileDSThuoc(ofstream &FileOut, DSThuoc ht, int size)
{
	if (kiemtra_dst_rong(ht)) {
		FileOut << -99; return;
	}
	FileOut << size << "\n";
	while (ht != NULL)
	{
		FileOut << ht->data.ma << "-";
		FileOut << ht->data.ten << "-";
		FileOut << ht->data.dongia << "-";
		FileOut << ht->data.sltonkho << "-";
		FileOut << ht->data.slttsohuu << "-";
		FileOut << ht->data.dvt;
		if (ht->next != NULL) FileOut << "\n";
		ht = ht->next;
	}
}
	if (kiemtra_dsvlyt_rong(ht)) {
		FileOut << -99; return;
	}
	FileOut << size << "\n";
	while (ht != NULL)
	{
		FileOut << ht->data.ma << "-";
		FileOut << ht->data.dongia << "-";
		FileOut << ht->data.slttsohuu << "-";
		FileOut << ht->data.ten;
		if (ht->next != NULL) FileOut << "\n";
		ht = ht->next;
	}
}

#pragma endregion
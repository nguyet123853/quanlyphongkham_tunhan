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
void menu_benhnhan()
{
	gioithieu();
	gotoxy(0, 12);
	cout << "================================================== QUAN LY BENH NHAN ======================================\n";
	cout << "1.Them Benh Nhan \n";
	cout << "2.Xoa Benh Nhan \n";
	cout << "3.Tiep Benh Nhan\n";// -> tái khám , xem lịch sử khám , xem đơn thuốc 
	cout << "4.Xuat Danh Sach Benh Nhan \n";
	cout << "0. Thoat\n";
	cout << "====================================================== END ================================================";
}

void menu_tiepbenhnhan()
{
	cout << "\n================================================== TIEP BENH NHAN =========================================\n";
	cout << "1.Tai Kham \n";//+++++++
	cout << "2.Xem Lich Su Kham\n";//+++++++
	cout << "3.Xem Don Thuoc\n";//+++++++
	cout << "4.Sua Thong Tin Benh Nhan\n";
	cout << "0.Thoat\n";
	cout << "====================================================== END ================================================";
}
void menu_xuatdsbenhnhan()
{
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

void menu_thongke()
{
	gioithieu();
	gotoxy(0, 12);
	cout << "================================================== THONG KE ===============================================\n";
	cout << "1.Thong ke theo Ngay\n";
	cout << "2.Thong ke theo Thang\n";
	cout << "3.Thong ke theo Nam\n";
	cout << "4.Thong ke theo Khoang thoi gian\n";
	cout << "5.Thong ke nhieu nam\n";
	cout << "0. Thoat\n";
	cout << "====================================================== END ================================================";
}
void menu_vatlieuyte()
{
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

void menu_timkiembenhnhan()
{
	cout << "========================================== TIM KIEM BENH NHAN =============================================\n";
	cout << "1.Tim Kiem Theo Ma\n";
	cout << "2.Tim Kiem Theo Ten\n";
	cout << "3.Tim Kiem theo Ngay Sinh\n";
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
#pragma region ====================== Vat Lieu Y Te ================================
void khoitao_dsvlyt(DSVLYT &dsvlyt)
{
	dsvlyt = NULL;
}
bool kiemtra_dsvlyt_rong(DSVLYT &dsvlyt)
{
	return dsvlyt == NULL;
}
NODE_VLYT* tao_node_vlyt(VatLieuYTe vlyt)
{
	NODE_VLYT* p = new NODE_VLYT;
	p->data = vlyt;
	p->next = NULL;
	return p;
}


int themvlyt(DSVLYT &ht, int &code)
{

	VatLieuYTe a;
	a.Nhap(code);
	code++;
	NODE_VLYT* p = new NODE_VLYT;
	p->data = a;
	p->next = NULL;
	if (ht == NULL) ht = p;
	else {
		NODE_VLYT* t = ht;
		do {
			if (t->next == NULL) break;
			else t = t->next;
		} while (1);
		t->next = p;
	}
	return 1;
}


NODE_VLYT*	timkiemvlyt_TheoMa(DSVLYT ht, int a)
{
	NODE_VLYT* cantim;
	khoitao_dsvlyt(cantim);
	NODE_VLYT* p = ht;
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
void suathongtinvlyt(NODE_VLYT* &vlyt)
{
	cout << "Ten Moi : "; getline(cin, vlyt->data.ten);
	vlyt->data.dongia = nhapsonguyen("Don Gia : ");
	cout << "Sua Thong Tin Vat Lieu Y Te Thanh Cong !\n";
}
int xoavlyt(DSVLYT &ht, int a)
{
	NODE_VLYT* p = ht;
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
			NODE_VLYT* before = p;
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
void xuatdsvlyt(DSVLYT ht)
{

	NODE_VLYT* p = ht;

	gotoxy(40, 3);
	cout << "DANH SACH VAT LIEU Y TE\n\n";
	cout << setw(10) << left << "Ma VLYT";
	cout << setw(40) << left << "Ten VLYT";
	cout << setw(30) << left << "Gia Dich Vu (VND)";
	cout << setw(20) << left << "Tinh Trang" << endl;
	cout << setfill('-');
	cout << setw(110) << "-" << endl;
	cout << setfill(' ');
	while (p != NULL)
	{
		p->data.xuat();
		p = p->next;
	}
	cout << setfill('-');
	cout << setw(110) << "-" << endl;
	cout << setfill(' ');
	cout << "\n";
}
void giaiphongdsvlyt(DSVLYT &ht)
{
	NODE_VLYT* p;
	while (ht != NULL)
	{
		p = ht;
		ht = ht->next;
		delete p;
	}
}
#pragma endregion

#pragma region ========================================= Benh Nhan =======================================
void khoitao_dsbenhnhan(DSBenhNhan &ds)
{
	ds = NULL;
}
bool kiemtra_dsbn_rong(DSBenhNhan dsbn)
{
	return dsbn == NULL;
}
SoKhamBenh tao_node_KhamBenh(KhamBenh kham)
{
	Node_KhamBenh* p = new Node_KhamBenh;
	p->data = kham;

	p->next = NULL;
	return p;
}
void Chen_KhamBenh(SoKhamBenh &bn, KhamBenh kham)
{
	SoKhamBenh p = tao_node_KhamBenh(kham);
	if (bn == NULL)
		bn = p;
	else{
		Node_KhamBenh* s = bn;
		while (s->next != NULL)
			s = s->next;
		s->next = p;
	}
}

// ------------------ Đang Làm -----------------------------
void BenhNhanKhamBenh(SoKhamBenh &bn, DSThuoc ds, DSVLYT dsvlyt, int &codedst, int &codevlyt)
{
	KhamBenh a;
	a.Nhap();
	//Biến ChonThuoc được tái sử dụng nhìu lần ( * : dấu hiệu )
	int ChonThuoc, ChonVLYT;

	//Cờ ra hiệu đã thêm thành công 1 phần tử để típ tục thêm pt kế típ
	bool flag = true;

	string kiemtra = "";
	Node_KhamBenh* sk = tao_node_KhamBenh(a);

	system("cls");
	xuatdsthuoc(ds);

	//khởi tạo mảng động toa thuốc
	sk->soluongthuoc = nhapsonguyen("Nhap so luong thuoc trong toa thuoc : ");
	sk->toathuoc = new ToaThuoc[sk->soluongthuoc];

	cout << "\n\nXin Hay Nhap Ma Thuoc de Ke Toa :\n";
	for (int i = 0; i < sk->soluongthuoc; i++){
		do{
			ChonThuoc = nhapsonguyen("Ma Thuoc[" + to_string(i) + "]: ");

			NODE_Thuoc* thuoc = NULL;
			thuoc = timkiemthuoc_TheoMa(ds, ChonThuoc);
			if (thuoc != NULL){
				sk->toathuoc[i].thuoc = thuoc;
				sk->toathuoc[i].soluong = nhapsonguyen("So Luong: ");

				//Kiểm tra thử xem số lượng trong kho có đủ để đáp ứng toa thuốc hay không ?
				ChonThuoc = thuoc->data.sltonkho - sk->toathuoc[i].soluong;

				//Số lượng tồn kho không đủ
				if (ChonThuoc < 0)
				{

					cout << "So Luong Thuoc khong du! Ban co Muon them so luong thuoc khong? (1:co||2:khong)\n";
					do{
						//*
						ChonThuoc = nhapsonguyen("Chon: ");
					} while (ChonThuoc != 1 && ChonThuoc != 2);
					if (ChonThuoc == 1)
					{
						//*
						ChonThuoc = nhapsonguyen("Nhap so Luong can them: ");
						if (themsoluongthuoc(thuoc, ChonThuoc)) cout << "Them So Luong Thuoc thanh cong! \n";
						system("pause");
						system("cls");
						xuatdsthuoc(ds);
						//else cout << "Them SL Thuoc that bai ! ( Khong nhap so am ) \n";
					}
					flag = false;
				}
				//Số lượng tồn kho đã đủ
				else{
					cout << "Cach Dung: ";		getline(cin, sk->toathuoc[i].cachdung);

					thuoc->data.sltonkho -= sk->toathuoc[i].soluong;
					sk->toathuoc[i].gia = sk->toathuoc[i].thuoc->data.dongia;
					thuoc->data.slttsohuu++;
					flag = true;
				}
			}
			else {
				cout << "Khong tim thay thuoc! Ban co muon Them Thuoc moi khong? (1:co||2:khong)\n";
				do{
					//*
					ChonThuoc = nhapsonguyen("Chon: ");
				} while (ChonThuoc != 1 && ChonThuoc != 2);
				if (ChonThuoc == 1)
				{
					if (themthuoc(ds, codedst))	cout << "Them Thuoc thanh cong! \n";
					system("pause");
					system("cls");
					xuatdsthuoc(ds);
					//else cout << "Them Thuoc that bai ! ( Khong nhap so am ) \n";
				}
				flag = false;
			}
		} while (!flag);
	}

	system("cls");
	xuatdsvlyt(dsvlyt);
	//khởi tạo mảng động dịch vụ-vật liệu y tế

	sk->soluongdvyt = nhapsonguyen("Nhap so luong vat lieu y te: ");
	sk->dvyt = new DichVuVLYT[sk->soluongdvyt];
	for (int i = 0; i < sk->soluongdvyt; i++)
	{
		do{
			ChonVLYT = nhapsonguyen("Ma Vat Lieu Y Te[" + to_string(i) + "]: ");

			NODE_VLYT* vlyt = NULL;
			vlyt = timkiemvlyt_TheoMa(dsvlyt, ChonVLYT);
			if (vlyt != NULL){
				sk->dvyt[i].vlyt = vlyt;
				sk->dvyt[i].gia = vlyt->data.dongia;
				vlyt->data.slttsohuu++;
				flag = true;
			}
			else {
				cout << "Khong tim thay Vat Lieu! Ban co muon Them Vat Lieu Y Te moi khong? (1:co||2:khong)\n";
				do{
					//*
					ChonVLYT = nhapsonguyen("Chon : ");
				} while (ChonVLYT != 1 && ChonVLYT != 2);
				if (ChonVLYT == 1)
				{
					if (themvlyt(dsvlyt, codevlyt))	cout << "Them Vat Lieu Y Te thanh cong! \n";
					system("pause");
					system("cls");
					xuatdsvlyt(dsvlyt);

				}
				flag = false;
			}
		} while (!flag);
	}

	fflush(stdin);
	sk->loidando = kiemtrachuoi("\n\nLoi Dan Do: ");

	if (bn == NULL) bn = sk;
	else
	{
		Node_KhamBenh* s = bn;
		while (s->next != NULL)
			s = s->next;
		s->next = sk;
	}
}

int thembenhnhan(DSBenhNhan &ht, DSThuoc &ds, DSVLYT &dsvlyt, int &size_thuoc, int &size_bn, int &size_vlyt)
{
	BenhNhan bn;
	bn.Nhap(size_bn);
	size_bn++;
	SoKhamBenh sk = NULL;
	BenhNhanKhamBenh(sk, ds, dsvlyt, size_thuoc, size_vlyt);
	NODE_BenhNhan* p;
	p = new NODE_BenhNhan;
	p->data = bn;
	p->sokham = sk;
	p->next = NULL;
	if (ht == NULL) ht = p;
	else {
		NODE_BenhNhan* t = ht;
    	do {
			if (t->next == NULL) break;
			else t = t->next;
		} while (1);
		t->next = p;
	}
	return 1;
}

NODE_BenhNhan* TimKiem_TheoMa(DSBenhNhan ht, int a)
{
	NODE_BenhNhan* cantim = NULL;
	NODE_BenhNhan* p = ht;
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
  
NODE_BenhNhan*  TimKiem_TheoTen(DSBenhNhan ht, string Ten)
{
	NODE_BenhNhan* p = ht;
	NODE_BenhNhan* cantim = NULL;

	int size = 0;

	bool tinhieu1 = false, tinhieu2 = false;

	while (p != NULL)
	{
		if (!Transform(p->data.ten).compare(Transform(Ten)))
		{
			if (!tinhieu1){
				cantim = p;
				tinhieu1 = true;
			}
			else {
				if (!tinhieu2){
					system("cls");
					gotoxy(40, 3);
					cout << "DANH SACH BENH NHAN\n\n";
					cout << setw(20) << left << "Ma Benh Nhan";
					cout << setw(40) << left << "Ten Benh Nhan";
					cout << setw(20) << left << "Ngay Sinh";
					cout << setw(15) << left << "Gioi Tinh" << endl;
					cout << setfill('-');
					cout << setw(100) << "-" << endl;
					cout << setfill(' ');
				}
				tinhieu2 = true;
				p->data.xuat();
			}
		}
		p = p->next;
	}
	if (!tinhieu2);
	else{
		cantim->data.xuat();
		cout << setfill('-');
		cout << setw(100) << "-" << endl;
		cout << setfill(' ');
		cout << "\n";
		int macantim;
		macantim = nhapsonguyen("Ma can tim : ");
		cantim = TimKiem_TheoMa(ht, macantim);
	}
	return cantim;
}

NODE_BenhNhan*  TimKiem_TheoNgaySinh(DSBenhNhan ht, Ngay ngaynhap)
{
	NODE_BenhNhan* p = ht;
	NODE_BenhNhan* cantim = NULL;

	int size = 0;
	
	bool tinhieu1 = false, tinhieu2 = false;

	while (p != NULL)
	{
		if (p->data.ngaysinh.ngay == ngaynhap.ngay&&p->data.ngaysinh.thang == ngaynhap.thang&&p->data.ngaysinh.nam == ngaynhap.nam)
		{
			if (!tinhieu1){
				cantim = p;
				tinhieu1 = true;
			}
			else {
				if (!tinhieu2){
					system("cls");
					gotoxy(40, 3);
					cout << "DANH SACH BENH NHAN\n\n";
					cout << setw(20) << left << "Ma Benh Nhan";
					cout << setw(40) << left << "Ten Benh Nhan";
					cout << setw(20) << left << "Ngay Sinh";
					cout << setw(15) << left << "Gioi Tinh" << endl;
					cout << setfill('-');
					cout << setw(100) << "-" << endl;
					cout << setfill(' ');
				}
				tinhieu2 = true;
				p->data.xuat();
			}
		}
		p = p->next;
	}
	if (!tinhieu2);
	else{
		cantim->data.xuat();
		cout << setfill('-');
		cout << setw(100) << "-" << endl;
		cout << setfill(' ');
		cout << "\n";
		int macantim;
		macantim = nhapsonguyen("Ma can tim : ");
		cantim = TimKiem_TheoMa(ht, macantim);
	}
	return cantim;
}

////----------------------------------------------------------------------
void Show_LichSuKham(NODE_BenhNhan* bn)
{
	cout << "\n=================================================== LICH SU KHAM ========================================== \n\n";

	cout << setw(30) << left << "Ngay Kham";
	cout << setw(40) << left << "Trieu Chung";
	cout << setw(40) << left << "Chan Doan" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	Node_KhamBenh* p = bn->sokham;
	while (p != NULL){
		cout << setw(30) << p->data.NgayKham.Xuat() << setw(40) << p->data.trieuchung << setw(40) << p->data.ChanDoan << endl;
		/*for (int i = 0; i < p->soluongthuoc;i++)
		{
		cout << "Ma : " << p->toathuoc[i].thuoc->data.ma << "\tTen : " << p->toathuoc[i].thuoc->data.ten << "\tDVT : " << p->toathuoc[i].thuoc->data.dvt << endl;
		}*/
		p = p->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
}
void Xoa_Dau_BN(DSBenhNhan &ht)
{
	NODE_BenhNhan* p;
	if (ht != NULL)
	{
		p = ht;
		SoKhamBenh NodeXoaNgayKham;
		while (p->sokham != NULL)
		{
			for (int i = 0; i < p->sokham->soluongthuoc; i++)
				p->sokham->toathuoc[i].thuoc->data.slttsohuu--;
			//Xóa mảng động toa thuốc
			delete[] p->sokham->toathuoc;
			NodeXoaNgayKham = p->sokham;
			p->sokham = p->sokham->next;
			delete NodeXoaNgayKham;
		}
		ht = p->next;

		//Xóa file 
		string tenfile = to_string(p->data.ma) + "-" + p->data.ten + "-" + p->data.gioitinh + "-" + to_string(p->data.ngaysinh.ngay) + to_string(p->data.ngaysinh.thang) + to_string(p->data.ngaysinh.nam) + ".txt";
		tenfile = XoaBoKhoangTrang(tenfile);

		string LenhXoa = "del " + tenfile;
		system(LenhXoa.c_str());
		delete p;
	}
}
int xoabenhnhan(DSBenhNhan &ht, int a)
{
	NODE_BenhNhan* p;
	NODE_BenhNhan* before;
	if (kiemtra_dsbn_rong(ht)) return 0;
	else if (ht->data.ma == a){
		Xoa_Dau_BN(ht);
		return 1;
	}
	else{
		p = ht; before = NULL;
		while ((p != NULL) && (p->data.ma != a))
		{
			before = p;
			p = p->next;
		}

		if (p != NULL)
		{
			SoKhamBenh NodeXoaNgayKham;
			while (p->sokham != NULL)
			{
				for (int i = 0; i < p->sokham->soluongthuoc; i++)
					p->sokham->toathuoc[i].thuoc->data.slttsohuu--;
				//Xóa mảng động toa thuốc
				delete[] p->sokham->toathuoc;

				//Xoa mang dong danh sach vat lieu y te
				delete[] p->sokham->dvyt;
				NodeXoaNgayKham = p->sokham;
				p->sokham = p->sokham->next;
				delete NodeXoaNgayKham;
			}
			before->next = p->next;

			//Xóa file 
			string tenfile = to_string(p->data.ma) + "-" + p->data.ten + "-" + p->data.gioitinh + "-" + to_string(p->data.ngaysinh.ngay) + to_string(p->data.ngaysinh.thang) + to_string(p->data.ngaysinh.nam) + ".txt";
			tenfile = XoaBoKhoangTrang(tenfile);

			string LenhXoa = "del " + tenfile;
			system(LenhXoa.c_str());

			delete p;
			return 1;
		}
	}
	return 0;
}

void suathongtinbenhnhan(NODE_BenhNhan* &bn)
{
	//Xóa file 
	string tenfile = to_string(bn->data.ma) + "-" + bn->data.ten + "-" + bn->data.gioitinh + "-" + to_string(bn->data.ngaysinh.ngay) + to_string(bn->data.ngaysinh.thang) + to_string(bn->data.ngaysinh.nam) + ".txt";

	bn->data.ten = kiemtrachuoi("\nTen Benh Nhan : ");
	cout << "Ngay Sinh : "; bn->data.ngaysinh.Nhap();
	bn->data.gioitinh = kiemtrachuoi("\nGioi Tinh : ");
	tenfile = XoaBoKhoangTrang(tenfile);

	string LenhXoa = "del " + tenfile;
	system(LenhXoa.c_str());
	cout << "Sua Thong Tin Benh Nhan Thanh Cong !\n";
}
//------- Đang làm ----------
void In_DonThuoc(NODE_BenhNhan* bn, Node_KhamBenh* nk)
{
	system("cls");
	gotoxy(40, 3);
	cout << "TOA THUOC\n\n";
	cout << setw(20) << left;
	cout << setw(40) << left;
	cout << setw(30) << left << endl;
	cout << setw(20) << "Ma So : " + to_string(bn->data.ma) << setw(40) << "Ten : " + bn->data.ten << left << setw(30) << "Ngay sinh : " + bn->data.ngaysinh.Xuat() << endl;
	cout << setw(20) << "Gioi tinh : " + bn->data.gioitinh << setw(40) << "Trieu chung : " + nk->data.trieuchung << setw(30) << "Chan doan : " + nk->data.ChanDoan << "\n\n\n";


	cout << setw(10) << left << "STT";
	cout << setw(30) << left << "Ten Thuoc";
	cout << setw(15) << left << "Don Gia (VND)";
	cout << setw(10) << left << "So Luong";
	cout << setw(50) << left << "Cach dung" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	int tong = 0;
	for (int i = 0; i < nk->soluongthuoc; i++)
	{
		cout << setw(10) << i + 1 << setw(30) << nk->toathuoc[i].thuoc->data.ten << setw(15) << nk->toathuoc[i].gia << setw(10) << nk->toathuoc[i].soluong << setw(50) << nk->toathuoc[i].cachdung << endl;
		tong += nk->toathuoc[i].soluong*nk->toathuoc[i].gia;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');

	cout << "\n\n";
	cout << setw(10) << left << "STT";
	cout << setw(30) << left << "Ma VLYT";
	cout << setw(40) << left << "Ten VLYT";
	cout << setw(30) << left << "Don Gia (VND)" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	for (int i = 0; i < nk->soluongdvyt; i++)
	{
		cout << setw(10) << i + 1 << setw(30) << nk->dvyt[i].vlyt->data.ma << setw(40) << nk->dvyt[i].vlyt->data.ten << setw(30) << nk->dvyt[i].gia << endl;
		tong += nk->dvyt[i].gia;
    	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	cout << "\n\nLoi Dan Do : " << nk->loidando;
	cout << "\n\nNgay kham : " << nk->data.NgayKham.Xuat() << "\t\t\t\t\tTong Tien : " << tong << " VND" << endl;


}
void xuatdsbenhnhan_theogioitinh(DSBenhNhan ht, string gioitinh)
{
	gotoxy(40, 3);
	cout << "DANH SACH BENH NHAN\n\n";
	cout << setw(20) << left << "Ma Benh Nhan";
	cout << setw(40) << left << "Ten Benh Nhan";
	cout << setw(20) << left << "Ngay Sinh";
	cout << setw(15) << left << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(100) << "-" << endl;
	cout << setfill(' ');
	NODE_BenhNhan* p = ht;
	while (p != NULL)
	{
		if (!Transform(p->data.gioitinh).compare(Transform(gioitinh))) p->data.xuat();
		p = p->next;
	}
	cout << setfill('-');
	cout << setw(100) << "-" << endl;
	cout << setfill(' ');
	cout << "\n";
}
void xuatdsbenhnhan_theongaykham(DSBenhNhan ht, Ngay tungay, Ngay denngay)
{
	gotoxy(30, 3);
	cout << "DANH SACH BENH NHAN TU NGAY " << tungay.Xuat() << " -> " << denngay.Xuat() << "\n\n\n";
	cout << setw(20) << left << "Ngay Kham";
	cout << setw(20) << left << "Ma Benh Nhan";
	cout << setw(35) << left << "Ten Benh Nhan";
	cout << setw(20) << left << "Ngay Sinh";
	cout << setw(15) << left << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(110) << "-" << endl;
	cout << setfill(' ');

	NODE_BenhNhan* p = ht;
	while (p != NULL)
	{
		Node_KhamBenh* sk = p->sokham;
		while (sk != NULL)
		{
			if (sk->data.NgayKham >= tungay&&denngay >= sk->data.NgayKham)
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << p->data.ma << setw(35) << p->data.ten << setw(20) << p->data.ngaysinh.Xuat() << setw(15) << p->data.gioitinh << endl;
			sk = sk->next;
		}
		p = p->next;
	}
	cout << setfill('-');
	cout << setw(110) << "-" << endl;
	cout << setfill(' ');
	cout << "\n";
}
void xuatdsbenhnhan(DSBenhNhan ht)
{
	gotoxy(40, 3);
	cout << "DANH SACH BENH NHAN\n\n";
	cout << setw(20) << left << "Ma Benh Nhan";
	cout << setw(40) << left << "Ten Benh Nhan";
	cout << setw(20) << left << "Ngay Sinh";
	cout << setw(15) << left << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(100) << "-" << endl;
	cout << setfill(' ');
	NODE_BenhNhan* p = ht;
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
void giaiphongdsbenhnhan(DSBenhNhan &ht)
{
	NODE_BenhNhan* NodeBenhNhanCanXoa;
	while (ht != NULL)
	{
		NodeBenhNhanCanXoa = ht;
		Node_KhamBenh* NodeSoKhamCanXoa;
		while (NodeBenhNhanCanXoa->sokham != NULL)
		{
			NodeSoKhamCanXoa = NodeBenhNhanCanXoa->sokham;
			delete[] NodeSoKhamCanXoa->toathuoc;
			delete[] NodeSoKhamCanXoa->dvyt;
			NodeBenhNhanCanXoa->sokham = NodeBenhNhanCanXoa->sokham->next;
			delete NodeSoKhamCanXoa;
		}

		ht = ht->next;
		delete NodeBenhNhanCanXoa;
	}
}
#pragma region ================================= Thong Ke ==================================
void ThongKe(DSBenhNhan ht, Ngay tungay, Ngay denngay)
{
	long int DoanhThu = 0;
	int SLBenhNhan = 0;
	bool flag = 0;
	NODE_BenhNhan* dsbn = ht;
	//cout << "\n------------------------------------------------- THONG KE ------------------------------------------------\n";

	gotoxy(50, 2);
	cout << "THONG KE\n\n";
	cout << left << setw(20) << "Ngay Kham ";
	cout << left << setw(20) << "Ma Benh Nhan";
	cout << left << setw(35) << "Ten Benh Nhan";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(15) << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	while (dsbn != NULL)
	{
		Node_KhamBenh* sk = dsbn->sokham;
		while (sk != NULL)
		{
			if (sk->data.NgayKham >= tungay&&denngay >= sk->data.NgayKham)
			{
				//Duyệt toa thuốc trong ngày khám nào đó?
				for (int i = 0; i < sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;

				//Duyệt Dịch Vụ-vật liệu y tế trong ngày khám nào đó?
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				flag = 1;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;

			}
			sk = sk->next;
		}
		if (flag)
		{
			SLBenhNhan++;
			flag = 0;
		}
		dsbn = dsbn->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	cout << "\nTong so luong benh nhan tu " << tungay.Xuat() << " den " << denngay.Xuat() << " : " << SLBenhNhan << endl;
	cout << "Tong Doanh Thu tu " << tungay.Xuat() << " den " << denngay.Xuat() << " : " << DoanhThu << " VND" << endl;

}



void ThongKe_nNam(DSBenhNhan ht, Ngay tunam, Ngay dennam)
{
	long int DoanhThu = 0;
	int SLBenhNhan = 0;
	bool flag = 0;
	NODE_BenhNhan* dsbn = ht;
	gotoxy(50, 2);
	cout << "THONG KE\n\n";
	cout << left << setw(20) << "Ngay Kham";
	cout << left << setw(20) << "Ma Benh Nhan";
	cout << left << setw(35) << "Ten Benh Nhan";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(15) << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	while (dsbn != NULL)
	{
		Node_KhamBenh* sk = dsbn->sokham;
		while (sk != NULL)
		{
			if (sk->data.NgayKham.nam <= tunam.nam&&dennam.nam <= sk->data.NgayKham.nam)
			{
				for (int i = 0; i <sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;
				flag = 1;
				break;
			}
			else
			{ 
				for (int i = 0; i <sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;
				flag = 1;
				break;
			}
			sk = sk->next;
		}
		if (flag)
		{
			SLBenhNhan++;

			flag = 0;
		}
		dsbn = dsbn->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
cout << "\nTong so luong benh nhan tu " << tunam.Xuat() << " den " << dennam.Xuat() << " : " << SLBenhNhan << endl;
	cout << "Tong Doanh Thu tu " << tunam.Xuat() << " den " << dennam.Xuat() << " : " << DoanhThu << " VND" << endl;

}



NODE_BenhNhan* ThongKe_BenhnhanKhammax(DSBenhNhan ds)
{ 

	NODE_BenhNhan* cantim = NULL;
	NODE_BenhNhan* bn = ds;
	bool flag = 0;
	int dem1 ,dem2=0;
	int mabn;
	while (bn != NULL){
		dem1 = 0;
		Node_KhamBenh* sk = bn->sokham;
		while (sk != NULL)
		{
			dem1++;
			sk = sk->next;
		}
		
		if (!flag) {
			cantim = bn;
			flag = 1;
			dem2 = dem1;
		}
		else if (dem1>dem2){
			cantim = bn;
		}
		bn = bn->next;
  }
return cantim;
}

void ThongKe_Ngay(DSBenhNhan ht, Ngay ngaynhap)
{
	long int DoanhThu = 0;
	int SLBenhNhan = 0;
	bool flag = 0;
	NODE_BenhNhan* dsbn = ht;
	gotoxy(50, 2);
	cout << "THONG KE\n\n";
	cout << left << setw(20) << "Ngay Kham";
	cout << left << setw(20) << "Ma Benh Nhan";
	cout << left << setw(35) << "Ten Benh Nhan";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(15) << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	while (dsbn != NULL)
	{
		Node_KhamBenh* sk = dsbn->sokham;
		while (sk != NULL)
		{
			if (sk->data.NgayKham.ngay == ngaynhap.ngay&&sk->data.NgayKham.thang == ngaynhap.thang&&sk->data.NgayKham.nam == ngaynhap.nam)
			{
				for (int i = 0; i <sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;
				flag = 1;
				break;
			}
			sk = sk->next;
		}
		if (flag)
		{
			SLBenhNhan++;

			flag = 0;
		}
		dsbn = dsbn->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	cout << "Tong so luong benh nhan trong ngay " << ngaynhap.Xuat() << " : " << SLBenhNhan << endl;
	cout << "Tong doanh thu trong ngay " << ngaynhap.Xuat() << " : " << DoanhThu << " VND" << endl;

}

void ThongKe_Thang(DSBenhNhan ht, Ngay ngaynhap)
{
	long int DoanhThu = 0;
	int SLBenhNhan = 0;
	bool flag = 0;
	NODE_BenhNhan* dsbn = ht;
	gotoxy(50, 2);
	cout << "THONG KE\n\n";
	cout << left << setw(20) << "Ngay Kham";
	cout << left << setw(20) << "Ma Benh Nhan";
	cout << left << setw(35) << "Ten Benh Nhan";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(15) << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	while (dsbn != NULL)
	{
		Node_KhamBenh* sk = dsbn->sokham;
		while (sk != NULL)
		{
			if (ngaynhap.thang == sk->data.NgayKham.thang&&ngaynhap.nam == sk->data.NgayKham.nam)
			{
				for (int i = 0; i <sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				flag = 1;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;

			}
			sk = sk->next;
		}
		if (flag)
		{
			SLBenhNhan++;
			flag = 0;
		}
		dsbn = dsbn->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	cout << "Tong so luong benh nhan trong thang " << ngaynhap.thang << "/" << ngaynhap.nam << " : " << SLBenhNhan << endl;
	cout << "Tong doanh thu trong thang " << ngaynhap.thang << "/" << ngaynhap.nam << " : " << DoanhThu << " VND" << endl;

}

void ThongKe_Nam(DSBenhNhan ht, Ngay ngaynhap)
{
	long int DoanhThu = 0;
	int SLBenhNhan = 0;
	bool flag = 0;
	NODE_BenhNhan* dsbn = ht;
	gotoxy(50, 2);
	cout << "THONG KE\n\n";
	cout << left << setw(20) << "Ngay Kham";
	cout << left << setw(20) << "Ma Benh Nhan";
	cout << left << setw(35) << "Ten Benh Nhan";
	cout << left << setw(20) << "Ngay sinh";
	cout << left << setw(15) << "Gioi Tinh" << endl;
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	while (dsbn != NULL)
	{
		Node_KhamBenh* sk = dsbn->sokham;
		while (sk != NULL)
		{

			if (ngaynhap.nam == sk->data.NgayKham.nam)
			{
				//Duyệt toa thuốc trong ngày khám nào đó ?
				for (int i = 0; i <sk->soluongthuoc; i++)
					DoanhThu += sk->toathuoc[i].soluong*sk->toathuoc[i].gia;
				//Duyệt Dịch Vụ-vật liệu y tế trong ngày khám nào đó?
				for (int i = 0; i < sk->soluongdvyt; i++)
					DoanhThu += sk->dvyt[i].gia;
				flag = 1;
				cout << setw(20) << sk->data.NgayKham.Xuat() << setw(20) << dsbn->data.ma << setw(35) << dsbn->data.ten << setw(20) << dsbn->data.ngaysinh.Xuat() << setw(15) << dsbn->data.gioitinh << endl;

			}
			sk = sk->next;
		}
		if (flag)
		{
			SLBenhNhan++;
			flag = 0;
		}
		dsbn = dsbn->next;
	}
	cout << setfill('-');
	cout << setw(107) << "-" << endl;
	cout << setfill(' ');
	cout << "Tong so luong benh nhan trong nam " << ngaynhap.nam << " : " << SLBenhNhan << endl;
	cout << "Tong doanh thu trong nam " << ngaynhap.nam << " : " << DoanhThu << " VND" << endl;
}
#pragma endregion

#pragma region ============================ File ==============================
void DocFileBenhNhan(ifstream &File, NODE_BenhNhan* &p, DSThuoc dst, DSVLYT dsvlyt)
{
	Node_KhamBenh* khambenh = NULL;

	File >> p->data.ma;
	File.seekg(1, 1);
	getline(File, p->data.ten, '-');
	File >> p->data.ngaysinh.ngay;
	File.seekg(1, 1);
	File >> p->data.ngaysinh.thang;
	File.seekg(1, 1);
	File >> p->data.ngaysinh.nam;
	File.seekg(1, 1);
	getline(File, p->data.gioitinh);

	//Đọc Sổ khám
	while (!File.eof())
	{

		Node_KhamBenh* sk = new Node_KhamBenh;
		sk->next = NULL;
		File >> sk->data.NgayKham.ngay;
		File.seekg(1, 1);
		File >> sk->data.NgayKham.thang;
		File.seekg(1, 1);
		File >> sk->data.NgayKham.nam;
		File.seekg(1, 1);
		getline(File, sk->data.trieuchung, '-');
		File >> sk->soluongthuoc;
		File.seekg(1, 1);
		File >> sk->soluongdvyt;
		File.seekg(1, 1);
		getline(File, sk->data.ChanDoan, '-');
		getline(File, sk->loidando);

		//Đọc toa thuốc
		sk->toathuoc = new ToaThuoc[sk->soluongthuoc];
		for (int i = 0; i < sk->soluongthuoc; i++)
		{
			int mathuoc;
			File >> mathuoc;
			File.seekg(1, 1);
			sk->toathuoc[i].thuoc = timkiemthuoc_TheoMa(dst, mathuoc);

			File >> sk->toathuoc[i].soluong;
			File.seekg(1, 1);
			File >> sk->toathuoc[i].gia;
			File.seekg(1, 1);
			getline(File, sk->toathuoc[i].cachdung);
		}

		//Đọc vật liệu y tế
		sk->dvyt = new DichVuVLYT[sk->soluongdvyt];
		for (int i = 0; i < sk->soluongdvyt; i++)
		{
			int mavlyt;
			File >> mavlyt;
			File.seekg(1, 1);
			sk->dvyt[i].vlyt = timkiemvlyt_TheoMa(dsvlyt, mavlyt);

			File >> sk->dvyt[i].gia;
			File.seekg(1, 1);

			//Dọn kí tự thừa
			string donrac = "";
			getline(File, donrac);
		}

		if (khambenh == NULL)
			khambenh = sk;
		else
		{
			Node_KhamBenh* s1 = khambenh;
			while (s1->next != NULL) s1 = s1->next;
			s1->next = sk;
		}
	}


	p->sokham = khambenh;
	p->next = NULL;
}

void DocFileDSBenhNhan(ifstream &FileIn, DSBenhNhan &ht, DSThuoc dst, DSVLYT dsvlyt, int &size)
{
	if (!FileIn) cout << "Khong doc duoc file ! ";
	else
	{
		FileIn >> size;
		if (size == -99){
			size = 1;
			return;
		}
		string donkitu = "";
		getline(FileIn, donkitu);
		while (!FileIn.eof())
		{
			string tenfile = "";
			getline(FileIn, tenfile);
			ifstream FileBN(tenfile + ".txt");
			NODE_BenhNhan* bn = new NODE_BenhNhan;
			DocFileBenhNhan(FileBN, bn, dst, dsvlyt);
			FileBN.close();
			if (ht == NULL)
				ht = bn;
			else
			{
				NODE_BenhNhan* dsbn = ht;
				while (dsbn->next != NULL) dsbn = dsbn->next;
				dsbn->next = bn;
			}
		}

	}
}

void GhiFileBenhNhan(ofstream &FileOut, NODE_BenhNhan* ht)
{
	FileOut << ht->data.ma << "-";
	FileOut << ht->data.ten << "-";
	FileOut << ht->data.ngaysinh.Xuat() << "-";
	FileOut << ht->data.gioitinh << "\n";
	Node_KhamBenh* sk = ht->sokham;
	while (sk != NULL)
	{
		FileOut << sk->data.NgayKham.Xuat() << "-";
		FileOut << sk->data.trieuchung << "-";
		FileOut << sk->soluongthuoc << "-";
		FileOut << sk->soluongdvyt << "-";
		FileOut << sk->data.ChanDoan << "-";
		FileOut << sk->loidando;
		if (sk->soluongthuoc != 0) FileOut << "\n";
		for (int i = 0; i < sk->soluongthuoc; i++)
		{
			FileOut << sk->toathuoc[i].thuoc->data.ma << "-";
			FileOut << sk->toathuoc[i].soluong << "-";
			FileOut << sk->toathuoc[i].gia << "-";
			FileOut << sk->toathuoc[i].cachdung;
			if (i != sk->soluongthuoc - 1) FileOut << "\n";
		}
		if (sk->soluongdvyt != 0) FileOut << "\n";
		for (int i = 0; i < sk->soluongdvyt; i++)
		{
			FileOut << sk->dvyt[i].vlyt->data.ma << "-";
			FileOut << sk->dvyt[i].gia;
			if (i != sk->soluongdvyt - 1) FileOut << "\n";
		}
		if (sk->next != NULL) FileOut << "\n";
		sk = sk->next;
	}
}

void GhiFileDSBenhNhan(ofstream &FileOut, DSBenhNhan ht, int size)
{
	if (kiemtra_dsbn_rong(ht))
	{
		FileOut << -99;
		return;
	}
	FileOut << size << "\n";
	while (ht != NULL)
	{
		string tenfileBN = "";
		FileOut << ht->data.ma;
		FileOut << "-";
		FileOut << XoaBoKhoangTrang(ht->data.ten);
		FileOut << "-";
		FileOut << XoaBoKhoangTrang(ht->data.gioitinh);
		FileOut << "-";
		FileOut << ht->data.ngaysinh.ngay;
		FileOut << ht->data.ngaysinh.thang;
		FileOut << ht->data.ngaysinh.nam;
		if (ht->next != NULL) FileOut << "\n";
		tenfileBN = to_string(ht->data.ma) + "-" + ht->data.ten + "-" + ht->data.gioitinh + "-" + to_string(ht->data.ngaysinh.ngay) + to_string(ht->data.ngaysinh.thang) + to_string(ht->data.ngaysinh.nam);
		tenfileBN = XoaBoKhoangTrang(tenfileBN);
		ofstream FileBenhNhan(tenfileBN + ".txt", ios_base::out);
		GhiFileBenhNhan(FileBenhNhan, ht);
		FileBenhNhan.close();
		ht = ht->next;
	}
}
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
void DocFileDSVLYT(ifstream &FileIn, DSVLYT &ht, int &size)
{
	if (!FileIn);
	else{
		FileIn >> size;
		if (size == -99){
			size = 1;
			return;
		}
		NODE_VLYT* p;
		while (!FileIn.eof())
		{
			p = new NODE_VLYT;
			FileIn >> p->data.ma;
			FileIn.seekg(1, 1);
			FileIn >> p->data.dongia;
			FileIn.seekg(1, 1);
			FileIn >> p->data.slttsohuu;
			FileIn.seekg(1, 1);
			getline(FileIn, p->data.ten);
			p->next = NULL;
			if (ht == NULL)
				ht = p;
			else
			{
				NODE_VLYT* s = ht;
				while (s->next != NULL) s = s->next;
				s->next = p;
			}
		}
	}
}
void GhiFileDSVLYT(ofstream &FileOut, DSVLYT ht, int size)
{
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

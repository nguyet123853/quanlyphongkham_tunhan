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
#include "iostream"
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;
int nhapsonguyen(string title);
string kiemtrachuoi(string title);
struct Ngay{
	int ngay, thang, nam;

	void Nhap(){
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		string kiemtra;
		do{
			SetConsoleTextAttribute(h, 7);
			ngay = nhapsonguyen("Ngay : ");
			thang = nhapsonguyen("Thang : ");
			nam = nhapsonguyen("Nam : ");
			if (!HopLe()){
				SetConsoleTextAttribute(h, 11);
				cout << "Ngay nhap khong hop le !\n";
			}
		} while (!HopLe());
		fflush(stdin);
	}
	string Xuat(){
		return to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam);
	}
	Ngay::Ngay(int ngay = 1, int thang = 1, int nam = 1) :ngay(ngay), thang(thang), nam(nam)
	{
	}
	int Nhuan()
	{
		if ((nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0))
			return 1;
		return 0;
	}
	int SNTrongThang()
	{
		int a[12] = { 31, Nhuan() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return a[thang - 1];
	}

	int HopLe()
	{
		if (ngay > 0 && ngay <= SNTrongThang() && thang > 0 && thang < 13 && nam > 0)
			return 1;
		return 0;
	}

	bool operator>=(Ngay date)
	{
		if (nam < date.nam) return false;
		else if (nam == date.nam){
			if (thang < date.thang) return false;
			else if (thang == date.thang){
				if (ngay >= date.ngay) return true;
				else return false;
			}
			else return true;
		}
		else return true;
	}

	bool operator<(Ngay date)
	{
		return !(*this >= date);
	}
};
struct Thuoc{
	int ma;
	string ten;
	string dvt;
	int sltonkho;
	int dongia;
	int slttsohuu;

	Thuoc()
	{
		ten = "";
		dvt = "";
		ma = 0;
		sltonkho = 0;
		dongia = 0;
		slttsohuu = 0;
	}

	void Nhap(int code)
	{
		string kiemtra;

		ma = code;
		cout << "Ma Thuoc : " << code << endl;
		ten = kiemtrachuoi("Ten Thuoc : ");
		dvt = kiemtrachuoi("DVT : ");
		dongia = nhapsonguyen("Don Gia : ");
		sltonkho = nhapsonguyen("So Luong : ");
	}

	void xuat()
	{
		cout << setw(10) << ma << setw(30) << ten << setw(10) << dvt << setw(15) << dongia << setw(15) << sltonkho << setw(20) << (slttsohuu>0 ? "Dang su dung" : "Chua su dung") << endl;
	}
};
struct NODE_Thuoc
{
	Thuoc data;
	NODE_Thuoc* next;
};
typedef struct NODE_Thuoc* DSThuoc;


struct ToaThuoc{
	NODE_Thuoc* thuoc;
	string cachdung;
	int soluong;
	int gia;
};

struct VatLieuYTe
{
	int ma;
	string ten;
	int dongia;
	int slttsohuu;

	VatLieuYTe()
	{
		ten = "";
		ma = 1;
		dongia = 0;
		slttsohuu = 0;
	}

	void Nhap(int code)
	{
		string kiemtra;

		ma = code;
		cout << "Ma Vat Lieu Y Te : " << code << endl;
		ten = kiemtrachuoi("Ten Vat Lieu Y Te : ");
		dongia = nhapsonguyen("Don Gia : ");
	}

	void xuat()
	{
		cout << setw(10) << ma << setw(40) << ten << setw(30) << dongia << setw(20) << (slttsohuu>0 ? "Dang su dung" : "Chua su dung") << endl;
	}
};
struct NODE_VLYT
{
	VatLieuYTe data;
	NODE_VLYT* next;
};
typedef struct NODE_VLYT* DSVLYT;

struct DichVuVLYT{
	NODE_VLYT* vlyt;
	int gia;
};

struct KhamBenh{
	Ngay NgayKham;
	string trieuchung;
	string ChanDoan;

	KhamBenh(){
		trieuchung = "";
		ChanDoan = "";
	}
	void Nhap()
	{
		cout << "\nNgay Kham : \n";
		NgayKham.Nhap();
		trieuchung = kiemtrachuoi("Trieu Chung : ");
		ChanDoan = kiemtrachuoi("Chan Doan : ");
	}

	//------- WARNING ---------
};
struct Node_KhamBenh{
	KhamBenh data;
	int soluongthuoc;
	ToaThuoc* toathuoc;
	int soluongdvyt;
	DichVuVLYT* dvyt;
	string loidando;
	Node_KhamBenh* next;
};
typedef struct Node_KhamBenh* SoKhamBenh;

struct BenhNhan{
	int ma;
	string ten;
	Ngay ngaysinh;
	string gioitinh;

	BenhNhan()
	{
		ma = 1;
		ten = "";
		gioitinh = "";
	}

	void Nhap(int code){
		ma = code;
		cout << "Ma Benh Nhan : " << ma << endl;
		ten = kiemtrachuoi("Ten Benh Nhan : ");
		cout << "Ngay Sinh : "; ngaysinh.Nhap();
		gioitinh = kiemtrachuoi("Gioi Tinh : ");

	}
	void xuat()
	{
		cout << setw(20) << ma << setw(40) << ten << setw(20) << ngaysinh.Xuat() << setw(15) << gioitinh << endl;
	}
};

struct NODE_BenhNhan
{
	BenhNhan data;
	SoKhamBenh sokham;
	NODE_BenhNhan* next;
};
typedef NODE_BenhNhan* DSBenhNhan;


//Menu hiển thị
void menu();
void menu_benhnhan();
void menu_thuoc();
void menu_timkiembenhnhan();
void menu_thongke();
void menu_tiepbenhnhan();
void menu_timthuoc();
void menu_xuatdsbenhnhan();
void menu_vatlieuyte();



//Khởi tạo dslk
void khoitao_dsbenhnhan(DSBenhNhan &dsbn);
void khoitao_dsthuoc(DSThuoc &dst);
void khoitao_dsvlyt(DSVLYT &dsvlyt);

//Kiểm tra rỗng
bool kiemtra_dsbn_rong(DSBenhNhan dsbn);
bool kiemtra_dst_rong(DSThuoc dst);
bool kiemtra_dsvlyt_rong(DSVLYT &dsvlyt);


//Thêm 
int thembenhnhan(DSBenhNhan &ht, DSThuoc &ds, DSVLYT &dsvlyt, int &size_thuoc, int &size_bn, int &size_vlyt);
int themthuoc(DSThuoc &ht, int &code);
bool themsoluongthuoc(NODE_Thuoc* &thuoc, int soluong);
void BenhNhanKhamBenh(SoKhamBenh &bn, DSThuoc ds, DSVLYT dsvlyt, int &codedst, int &codevlyt);
int themvlyt(DSVLYT &ht, int &code);


//xóa theo tieu chí mã
int xoathuoc(DSThuoc &ht, int a);
int xoabenhnhan(DSBenhNhan &ht, int a);
int xoavlyt(DSVLYT &ht, int a);

//Sửa 
void suathongtinthuoc(NODE_Thuoc* &thuoc);
void suathongtinbenhnhan(NODE_BenhNhan* &bn);
void suathongtinvlyt(NODE_VLYT* &vlyt);

//tìm kiếm theo tiêu chí mã,tên
NODE_BenhNhan* TimKiem_TheoMa(DSBenhNhan ht, int a);
NODE_BenhNhan* TimKiem_TheoTen(DSBenhNhan ht, string Ten);
NODE_BenhNhan*  TimKiem_TheoNgaySinh(DSBenhNhan ht, Ngay ngaynhap);
NODE_Thuoc*	timkiemthuoc_TheoMa(DSThuoc ht, int a);
NODE_VLYT*	timkiemvlyt_TheoMa(DSVLYT ht, int a);

//In Đơn thuốc
void In_DonThuoc(NODE_BenhNhan* bn, Node_KhamBenh* nk);

//Thống kê số lượng bệnh nhân + doanh thu theo ngày , tháng , năm
void ThongKe_Ngay(DSBenhNhan ht, Ngay ngaynhap);
void ThongKe_Thang(DSBenhNhan ht, Ngay ngaynhap);
void ThongKe_Nam(DSBenhNhan ht, Ngay ngaynhap);
void ThongKe(DSBenhNhan ht, Ngay tungay, Ngay denngay);
void ThongKe_nNam(DSBenhNhan ht, Ngay tunam, Ngay dennam);
NODE_BenhNhan* ThongKe_BenhnhanKhammax(DSBenhNhan ds);
//Xuất 
void xuatdsbenhnhan(DSBenhNhan ht);
void xuatdsbenhnhan_theogioitinh(DSBenhNhan ht, string gioitinh);
void xuatdsbenhnhan_theongaykham(DSBenhNhan ht, Ngay tungay, Ngay denngay);
void xuatdsthuoc(DSThuoc ht);
void Show_LichSuKham(NODE_BenhNhan* bn);
void xuatdsvlyt(DSVLYT ht);

//giải phóng vùng nhớ
void giaiphongdsbenhnhan(DSBenhNhan &ht);
void giaiphongdsthuoc(DSThuoc &ht);
void giaiphongdsvlyt(DSVLYT &ht);

//Đọc + Ghi File
void DocFileDSBenhNhan(ifstream &FileIn, DSBenhNhan &ht, DSThuoc dst, DSVLYT dsvlyt, int &size);
void GhiFileDSBenhNhan(ofstream &FileOut, DSBenhNhan ht, int size);
void DocFileDSThuoc(ifstream &FileIn, DSThuoc &ht, int &size);
void GhiFileDSThuoc(ofstream &FileOut, DSThuoc ht, int size);
void DocFileDSVLYT(ifstream &FileIn, DSVLYT &ht, int &size);
void GhiFileDSVLYT(ofstream &FileOut, DSVLYT ht, int size);

//Hàm format
void gotoxy(int x, int y);
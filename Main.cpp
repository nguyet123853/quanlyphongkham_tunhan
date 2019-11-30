﻿#include "ThuVien.h"

int main()
{
	DSBenhNhan DanhSachBenhNhan;
	DSThuoc DanhSachThuoc;
	DSVLYT DanhSachVatLieuYTe;

	khoitao_dsbenhnhan(DanhSachBenhNhan);
	khoitao_dsthuoc(DanhSachThuoc);
	khoitao_dsvlyt(DanhSachVatLieuYTe);


	int CapPhatSTT_Thuoc = 1, CapPhatSTT_BenhNhan = 1, CapPhatSTT_VLYT = 1;
	ifstream FileIn_DanhSachThuoc("DanhSachThuoc.txt");
	DocFileDSThuoc(FileIn_DanhSachThuoc, DanhSachThuoc, CapPhatSTT_Thuoc);
	FileIn_DanhSachThuoc.close();

	ifstream FileIn_DanhSachVLYT("DanhSachVLYT.txt");
	DocFileDSVLYT(FileIn_DanhSachVLYT, DanhSachVatLieuYTe, CapPhatSTT_VLYT);
	FileIn_DanhSachVLYT.close();


	ifstream FileIn_DanhSachBenhNhan("DanhSachBenhNhan.txt");
	DocFileDSBenhNhan(FileIn_DanhSachBenhNhan, DanhSachBenhNhan, DanhSachThuoc, DanhSachVatLieuYTe, CapPhatSTT_BenhNhan);
	FileIn_DanhSachBenhNhan.close();


	//biến sử dụng cho việc tìm kiếm theo tên bệnh nhân và kiểm tra có pải là số?
	string Ten, kiemtra;

	//con trỏ sử dụng cho việc tìm kiếm bệnh nhân
	NODE_BenhNhan* benhnhan;

	//con trỏ sử dụng cho việc thao tác node thuốc
	NODE_Thuoc* thuoc;

	//con trỏ sử dụng cho việc tìm kiếm ngày khám
	Node_KhamBenh* vt;

	//con trỏ sử dụng cho việc thao tác node vật liệu y tế
	NODE_VLYT* vlyt;

	//biến sử dụng để thống kê
	Ngay tungay, denngay;

	int tunam = tungay.nam; int dennam=denngay.nam;

	//các biến dùng cho việc sử dụng menu
	int luachon, luachon1, luachon2, luachon3, luachon4, luachon5, luachon6;


	//biến sử dụng cho mã cần tìm
	int macantim;

	//Text color đổi màu nên + chữ
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	do{
		system("cls");
		menu();
		luachon = nhapsonguyen("Nhap lua chon : ");
		switch (luachon)
		{
			//Quản lý bệnh nhân
		case 1:
			break;
			//Quản lý kho thuốc
		case 2:
			do{
				system("cls");
				system("color 07");
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
				menu_thuoc();
				luachon2 = nhapsonguyen("Nhap lua chon : ");
				switch (luachon2)
				{

					//Thêm thuốc mới
				case 1:
					if (themthuoc(DanhSachThuoc, CapPhatSTT_Thuoc) == 1){
						SetConsoleTextAttribute(h, 14);
						cout << "Them thanh cong!\n";
					}
					else{
						SetConsoleTextAttribute(h, FOREGROUND_RED);
						cout << "Khong them duoc!\n";
					}
					system("pause");
					break;

					//Xóa thuốc
				case 2:
					cout << "Nhap ma thuoc can xoa :";
					cin >> macantim;
					cin.ignore();
					if (xoathuoc(DanhSachThuoc, macantim) == 1) cout << "Xoa thanh cong!\n";
					else cout << "Khong xoa duoc !\n";
					system("pause");
					break;

					//Tìm Kiếm Node Thuốc để thêm số lượng , sửa thuốc
				case 3:
					macantim = nhapsonguyen("Nhap ma thuoc can tim : ");
					thuoc = timkiemthuoc_TheoMa(DanhSachThuoc, macantim);
					if (thuoc != NULL){
						system("cls");
						gotoxy(40, 3);
						cout << "THONG TIN THUOC\n\n";
						thuoc->data.xuat();
						do
						{
							menu_timthuoc();
							cout << "\nNhap lua chon: ";
							cin >> luachon6;

							fflush(stdin);
							switch (luachon6)
							{
								//Thêm số lượng thuốc
							case 1:
								int SL;
								SL = nhapsonguyen("Nhap So Luong can them : ");
								if (themsoluongthuoc(thuoc, SL)) cout << "Them so luong thuoc thanh cong !\n";
								else cout << "Them so luong thuoc that bai ! (Khong nhap SL Am )\n";
								system("pause");
								break;
								//Sửa thông tin thuốc
							case 2:
								suathongtinthuoc(thuoc);
								system("pause");
								break;

							default:
								break;
							}
						} while (luachon6 != 0);

					}
					else cout << "Khong tim thay thuoc !\n";
					system("pause");
					break;

					// Xuất danh sách thuốc trong kho thuốc
				case 4:
					system("cls");
					system("color 70");
					xuatdsthuoc(DanhSachThuoc);
					system("pause");
					break;
				default:
					break;
				}
			} while (luachon2 != 0);
			system("pause");
			break;
			//Thống kê số lượng và liệt kê ds bệnh nhân , doanh thu theo ngày, tháng , năm , khoảng thời gian
		case 3:
			break;
		case 4:
		do{
				system("cls");
				system("color 07");
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
				menu_vatlieuyte();
				luachon2 = nhapsonguyen("Nhap lua chon : ");
				switch (luachon2)
				{

					//Thêm vật liệu y tế
				case 1:
					if (themvlyt(DanhSachVatLieuYTe, CapPhatSTT_VLYT) == 1){
						SetConsoleTextAttribute(h, 14);
						cout << "Them thanh cong!\n";
					}
					else{
						SetConsoleTextAttribute(h, FOREGROUND_RED);
						cout << "Khong them duoc!\n";
					}
					system("pause");
					break;

					//Xóa vật liệu y tế
				case 2:
					cout << "Nhap ma thuoc can xoa :";
					cin >> macantim;
					cin.ignore();
					if (xoavlyt(DanhSachVatLieuYTe, macantim) == 1) cout << "Xoa thanh cong!\n";
					else cout << "Khong xoa duoc!\n";
					system("pause");
					break;
					//Sửa thông tin vật liệu y tế
				case 3:
					macantim = nhapsonguyen("\nNhap ma vlyt can sua : ");
					vlyt = timkiemvlyt_TheoMa(DanhSachVatLieuYTe, macantim);
					if (vlyt != NULL)
					{
						suathongtinvlyt(vlyt);
					}
					else cout << "Khong tim thay vat lieu y te !";
					system("pause");
					break;
					// Xuất danh sách vật liệu y tế
				case 4:
					system("cls");
					system("color 70");
					xuatdsvlyt(DanhSachVatLieuYTe);
					system("pause");
					break;
				default:
					break;
				}
			} while (luachon2 != 0);
			system("pause");
			break;
		default:
			break;
		}
	} while (luachon != 0);

	ofstream FileOut_DanhSachBenhNhan("DanhSachBenhNhan.txt", ios_base::out);

	GhiFileDSBenhNhan(FileOut_DanhSachBenhNhan, DanhSachBenhNhan, CapPhatSTT_BenhNhan);
	FileOut_DanhSachBenhNhan.close();


	ofstream FileOut_DanhSachThuoc("DanhSachThuoc.txt", ios_base::out);
	GhiFileDSThuoc(FileOut_DanhSachThuoc, DanhSachThuoc, CapPhatSTT_Thuoc);
	FileOut_DanhSachThuoc.close();

	ofstream FileOut_DanhSachVLYT("DanhSachVLYT.txt", ios_base::out);
	GhiFileDSVLYT(FileOut_DanhSachVLYT, DanhSachVatLieuYTe, CapPhatSTT_VLYT);
	FileOut_DanhSachVLYT.close();

	giaiphongdsbenhnhan(DanhSachBenhNhan);
	giaiphongdsthuoc(DanhSachThuoc);
	giaiphongdsvlyt(DanhSachVatLieuYTe);

	system("pause");
	return 0;
}

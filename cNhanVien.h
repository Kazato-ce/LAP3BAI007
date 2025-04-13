#include <iostream>
#include <string>
#include "NgayThangNam.h"
using namespace std;
class cNhanVien
{
private:
    string maNV;
    string hoTen;
    NgayThangNam ngaySinh;
    int LuongNV;
public:
    cNhanVien() : maNV(""), hoTen(""), LuongNV(0) {}
    cNhanVien(string ma, string ten, NgayThangNam ns, int luong) : maNV(ma), hoTen(ten), ngaySinh(ns), LuongNV(luong) {}
    void Nhap(){
        cout << "Nhap ma nhan vien: ";
        cin >> maNV;
        cin.ignore(); // Ignore newline character left in the buffer
        cout << "Nhap ho ten nhan vien: ";
        getline(cin, hoTen);
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        ngaySinh.Nhap();
        cout << "Nhap luong nhan vien: ";
        cin >> LuongNV;
    }
    void Xuat(){
        cout << "Ma nhan vien: " << maNV << endl;
        cout << "Ho ten nhan vien: " << hoTen << endl;
        cout << "Ngay sinh: ";
        ngaySinh.Xuat();
        cout << "Luong nhan vien: " << LuongNV << endl;
    }
    string getMaNV() { return maNV; }
    string getHoTen() { return hoTen; }
    NgayThangNam getNgaySinh() { return ngaySinh; }
    int getLuongNV() const { return LuongNV; }
    void setMaNV(string ma) { maNV = ma; }
    void setHoTen(string ten) { hoTen = ten; }
    void setNgaySinh(NgayThangNam ns) { ngaySinh = ns; }
    void setLuongNV(int luong) { LuongNV = luong; }
};
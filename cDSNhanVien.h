#include "cNhanVien.h"
#include <iostream>
#include <vector>
#include <iomanip> // Thư viện cho hàm setw
using namespace std;
#include <algorithm> // Thư viện cho hàm sort
class cDSNhanVien {
private:
    vector<cNhanVien> ds; // Danh sách nhân viên
public:
    void Nhap(){
        int n;
        cout << "Nhap so luong nhan vien: ";
        cin >> n;
        ds.resize(n); // Đặt kích thước của vector
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
            ds[i].Nhap(); // Nhập thông tin cho từng nhân viên
        }
    }
    void Xuat(){
        cout << "\n=================== DANH SACH NHAN VIEN ===================\n";
        cout << left
             << setw(10) << "Ma NV"
             << setw(20) << "Ho Ten"
             << setw(15) << "Ngay Sinh"
             << setw(10) << "Luong"
             << endl;
        cout << string(60, '-') << endl;
    
        for (int i = 0; i < ds.size(); i++) {
            cout << left
                 << setw(10) << ds[i].getMaNV()
                 << setw(20) << ds[i].getHoTen();
    
            NgayThangNam ns = ds[i].getNgaySinh();
            cout << setw(15)
                 << ( (ns.GetNgay() < 10 ? "0" : "") + to_string(ns.GetNgay()) + "/" +
                      (ns.GetThang() < 10 ? "0" : "") + to_string(ns.GetThang()) + "/" +
                      to_string(ns.GetNam()) );
    
            cout << setw(10) << fixed << setprecision(2) << ds[i].getLuongNV()
                 << endl;
        }
    }
    
    void TongLuong(){
        float tongLuong = 0;
        for (int i = 0; i < ds.size(); i++) {
            tongLuong += ds[i].getLuongNV(); // Tính tổng lương của tất cả nhân viên
        }
        cout << "Tong luong cua tat ca nhan vien: " << tongLuong << endl;
    }
    void NhanVienCoTuoiCaoNhat(){
        if (ds.empty()) {
            cout << "Khong co nhan vien trong danh sach." << endl;
            return;
        }
        cNhanVien nvCaoNhat = ds[0]; // Giả định nhân viên đầu tiên có tuổi cao nhất
        for (int i = 1; i < ds.size(); i++) {
            if (ds[i].getNgaySinh().GetNam() < nvCaoNhat.getNgaySinh().GetNam()) {
                nvCaoNhat = ds[i]; // Cập nhật nhân viên có tuổi cao nhất
            }
        }
        cout << "Nhan vien co tuoi cao nhat:" << endl;
        nvCaoNhat.Xuat(); // Xuất thông tin nhân viên có tuổi cao nhất
    }
    void XapTheoLuong(){
        // Kiểm tra danh sách rỗng
        if (ds.empty()) {
            cout << "Danh sach nhan vien rong. Khong the sap xep." << endl;
            return;
        }
    
        // Sắp xếp theo lương tăng dần
        sort(ds.begin(), ds.end(), [](const cNhanVien& a, const cNhanVien& b) {
            return a.getLuongNV() < b.getLuongNV(); // So sánh lương của hai nhân viên
        });
    
        cout << "Danh sach nhan vien sau khi sap xep theo luong (tang dan):" << endl;
        Xuat(); // Xuất danh sách sau khi sắp xếp
    }
    
};

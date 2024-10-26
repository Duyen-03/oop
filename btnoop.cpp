#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class GiaoDich {
protected:
    double soTien;
    string moTa;

public:
    GiaoDich(double tien, const string &mota) {
        soTien = tien;
        moTa = mota;
    }

    virtual void hienThi() {
        cout << setw(15) << soTien << setw(20) << moTa << endl;
    }

    double getSoTien() const {
        return soTien;
    }
};

class ThuNhap : public GiaoDich {
public:
    ThuNhap(double tien, const string &mota) : GiaoDich(tien, mota) {}

    void hienThi() {
        cout << setw(15) << "Thu Nhap" << setw(20);
        GiaoDich::hienThi();
    }
};

class ChiTieu : public GiaoDich {
public:
    ChiTieu(double tien, const string &mota) : GiaoDich(tien, mota) {}

    void hienThi() {
        cout << setw(15) << "Chi Tieu" << setw(20);
        GiaoDich::hienThi();
    }
};

class DauTu {
protected:
    double soTien;
    int thoiHan;

public:
    DauTu(double tien, int han) {
        soTien = tien;
        thoiHan = han;
    }

    virtual void hienThi() {
        cout << setw(15) << soTien << setw(15) << thoiHan;
    }

    virtual double soTienDaoHan() {
        return soTien;
    }
};

class DauTuCoPhieu : public DauTu {
public:
    DauTuCoPhieu(double tien, int han) : DauTu(tien, han) {}

    void hienThi() {
        cout << setw(15) << "Dau Tu Co Phieu";
        DauTu::hienThi();
        cout << endl;
    }

    double soTienDaoHan() {
        return soTien * pow((1 + 0.08), thoiHan); // Gi? s? l?i su?t là 8% hàng năm
    }
};

class KeHoachChiTieu {
private:
    double mucKeHoach; // Ngân sách
    string moTa;      // Mô t?

public:
    KeHoachChiTieu(double muc, const string &moTa) : mucKeHoach(muc), moTa(moTa) {}

    void hienThiKeHoach() const {
        cout << "Ke Hoach Chi Tieu: " << mucKeHoach << " VND, Mo ta: " << moTa << endl;
    }
};

class TaiKhoan {
private:
    string tenTaiKhoan;
    double soDu;

public:
    TaiKhoan(const string &ten, double du) : tenTaiKhoan(ten), soDu(du) {}

    void hienThiTaiKhoan() const {
        cout << "Tai Khoan: " << tenTaiKhoan << ", So Du: " << soDu << " VND" << endl;
    }

    double getSoDu() const {
        return soDu;
    }

    void capNhatSoDu(double soTien) {
        soDu += soTien;
    }
};

class QuanLyTaiChinh {
public:
    vector<GiaoDich*> giaoDichs;
    vector<DauTu*> dauTus;
    vector<KeHoachChiTieu*> keHoachChiTieux;

    void themGiaoDich(GiaoDich *gd) {
        giaoDichs.push_back(gd);
    }

    void themDauTu(DauTu *dt) {
        dauTus.push_back(dt);
    }

    void themKeHoachChiTieu(KeHoachChiTieu *kh) {
        keHoachChiTieux.push_back(kh);
    }

    void hienThiThongTin(const TaiKhoan &taiKhoan) {
        cout << "-----------------------------------\n";
        cout << "|        Quan Ly Tai Chinh        |\n";
        cout << "-----------------------------------\n";

        taiKhoan.hienThiTaiKhoan(); // Hi?n th? thông tin tài kho?n

        cout << "\n--GIAO DICH--: \n";
        cout << setw(15) << "Loai" << setw(15) << "So Tien" << setw(20) << "Mo Ta" << endl;
        for (size_t i = 0; i < giaoDichs.size(); i++) {
            giaoDichs[i]->hienThi();
        }
        
        cout << "\n--DAU TU--\n";
        cout << setw(15) << "Loai" << setw(15) << "So Tien" << setw(15) << "Thoi Han" << endl;
        for (size_t i = 0; i < dauTus.size(); i++) {
            dauTus[i]->hienThi();
        }

        cout << "\n--KE HOACH CHI TIEU--\n";
        for (size_t i = 0; i < keHoachChiTieux.size(); i++) {
            keHoachChiTieux[i]->hienThiKeHoach();
        }
    }

    void thongKeChiTieu() {
        double tongChiTieu = 0;
        for (size_t i = 0; i < giaoDichs.size(); i++) {
            ChiTieu *chiTieu = dynamic_cast<ChiTieu*>(giaoDichs[i]);
            if (chiTieu) {
                tongChiTieu += chiTieu->getSoTien();
            }
        }
        cout << "\n--THONG KE CHI TIEU--\n";
        cout << "Tong chi tieu: " << tongChiTieu << endl;
    }
};

class NguoiDung {
public:
    QuanLyTaiChinh qlTaiChinh;
    TaiKhoan taiKhoan;

    NguoiDung(const string &tenTaiKhoan, double soDuBanDau) : taiKhoan(tenTaiKhoan, soDuBanDau) {}

    void thucHienGiaoDich() {
        int luaChon = -1;
        while (luaChon != 0) {
            cout << "\n--TUY CHON--\n";
            cout << "1. Ghi Thu Nhap\n";
            cout << "2. Ghi Chi Tieu\n";
            cout << "3. Thong Ke Chi Tieu\n";  
            cout << "4. Lap Ke Hoach Chi Tieu\n"; // Thêm tùy ch?n l?p k? ho?ch chi tiêu
            cout << "5. Dau Tu\n";
            cout << "6. Thong Tin Tai Chinh\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> luaChon;

            switch (luaChon) {
                case 1: {
                    double tien;
                    string mota;
                    cout << "Nhap so tien: ";
                    cin >> tien;
                    cout << "Nhap mo ta: ";
                    cin.ignore();
                    getline(cin, mota);
                    qlTaiChinh.themGiaoDich(new ThuNhap(tien, mota));
                    taiKhoan.capNhatSoDu(tien); // C?p nh?t s? dư tài kho?n
                    break;
                }

                case 2: {
                    double tien;
                    string mota;
                    cout << "Nhap so tien: ";
                    cin >> tien;
                    if (taiKhoan.getSoDu() - tien < 0) {
                        cout << "Loi: So du khong duoc duoi 0.\n";
                        break;
                    }
                    cin.ignore();
                    cout << "Nhap mo ta: ";
                    getline(cin, mota);
                    qlTaiChinh.themGiaoDich(new ChiTieu(tien, mota));
                    taiKhoan.capNhatSoDu(-tien); // C?p nh?t s? dư tài kho?n

                    // Ki?m tra s? dư và g?i thông báo nh?c nh?
                    if (taiKhoan.getSoDu() < 1000) {
                        cout << "Thong bao: So du cua ban da duoi 1000 VND. Xin vui long thanh toan nho!\n"; 
                    }
                    break;
                }

                case 3: {
                    qlTaiChinh.thongKeChiTieu(); // G?i phương th?c th?ng kê chi tiêu
                    break;
                }

                case 4: { // L?p k? ho?ch chi tiêu
                    double mucKeHoach;
                    string moTa;
                    cout << "Nhap muc ke hoach chi tieu: ";
                    cin >> mucKeHoach;
                    cin.ignore(); // Đ? b? qua d?ng m?i
                    cout << "Nhap mo ta: ";
                    getline(cin, moTa);
                    qlTaiChinh.themKeHoachChiTieu(new KeHoachChiTieu(mucKeHoach, moTa));
                    break;
                }

                case 5: {
                    thucHienDauTu();
                    break;
                }

                case 6: {
                    qlTaiChinh.hienThiThongTin(taiKhoan); // Hi?n th? thông tin tài chính
                    break;
                }

                case 0:
                    break;

                default:
                    cout << "\nKhong co tuy chon nay!\n";
                    break;
            }
        }
    }

    void thucHienDauTu() {
        double tien;
        int han;
        cout << "Nhap so tien: ";
        cin >> tien;
        if (taiKhoan.getSoDu() - tien < 0) {
            cout << "Loi: So du khong duoc duoi 0.\n";
            return;
        }
        cout << "Nhap thoi han (nam): ";
        cin >> han;
        qlTaiChinh.themDauTu(new DauTuCoPhieu(tien, han));
        taiKhoan.capNhatSoDu(-tien); // C?p nh?t s? dư tài kho?n sau khi đ?u tư
    }
};

int main() {
    cout << "---Chao mung den voi He Thong Quan Ly Tai Chinh!---\n";
    NguoiDung nguoiDung("Tai Khoan 1", 2000); // Kh?i t?o ngư?i dùng v?i s? dư ban đ?u là 2000
    nguoiDung.thucHienGiaoDich();

    return 0;
}

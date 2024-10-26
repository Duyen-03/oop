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
    GiaoDich(double tien, const string &mota) : soTien(tien), moTa(mota) {}

    virtual void hienThi() {
        cout << setw(15) << soTien << setw(20) << moTa;
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
        cout << endl;
    }
};

class ChiTieu : public GiaoDich {
public:
    ChiTieu(double tien, const string &mota) : GiaoDich(tien, mota) {}

    void hienThi() {
        cout << setw(15) << "Chi Tieu" << setw(20);
        GiaoDich::hienThi();
        cout << endl;
    }
};

class DauTu {
protected:
    double soTien;
    int thoiHan;

public:
    DauTu(double tien, int han) : soTien(tien), thoiHan(han) {}

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
        return soTien * pow((1 + 0.08), thoiHan); // Gi? s? l?i su?t là 8% hàng nãm
    }
};

class DanhMucChiTieu {
private:
    string tenDanhMuc;
    vector<ChiTieu*> danhSachChiTieu;

public:
    DanhMucChiTieu(const string &ten) : tenDanhMuc(ten) {}

    void themChiTieu(ChiTieu* ct) {
        danhSachChiTieu.push_back(ct);
    }

    void thongKeChiTieu() {
        double tongChiTieu = 0;
        cout << "\n--THONG KE CHI TIEU--\n";
        cout << "Danh muc: " << tenDanhMuc << endl;
        for (int i = 0; i < danhSachChiTieu.size(); i++) {
            danhSachChiTieu[i]->hienThi();
            tongChiTieu += danhSachChiTieu[i]->getSoTien();
        }
        cout << "Tong chi tieu: " << tongChiTieu << endl;
    }
};

class TaiKhoan {
private:
    double soDu;

public:
    TaiKhoan(double du) : soDu(du) {}

    void updateBalance(double amount) {
        soDu += amount;
    }

    double getSoDu() const {
        return soDu;
    }
};

class QuanLyTaiChinh {
public:
    vector<GiaoDich*> giaoDichs;
    vector<DanhMucChiTieu*> danhMucChiTieus;
    vector<DauTu*> dauTus;

    void themGiaoDich(GiaoDich *gd) {
        giaoDichs.push_back(gd);
    }

    void themDanhMucChiTieu(DanhMucChiTieu *dm) {
        danhMucChiTieus.push_back(dm);
    }

    void themDauTu(DauTu *dt) {
        dauTus.push_back(dt);
    }

    void hienThiThongTin(double soDu) {
        cout << "-----------------------------------\n";
        cout << "|        Quan Ly Tai Chinh        |\n";
        cout << "-----------------------------------\n";
        cout << "\n||--SO DU--: " << soDu << "||" << endl;

        cout << "\n--GIAO DICH--: \n";
        cout << setw(15) << "Loai" << setw(15) << "So Tien" << setw(20) << "Mo Ta" << endl;
        for (int i = 0; i < giaoDichs.size(); i++) {
            giaoDichs[i]->hienThi();
        }

        cout << "\n--DANH MUC CHI TIEU--\n";
        for (int i = 0; i < danhMucChiTieus.size(); i++) {
            danhMucChiTieus[i]->thongKeChiTieu();
        }

        cout << "\n--DAU TU--\n";
        cout << setw(15) << "Loai" << setw(15) << "So Tien" << setw(15) << "Thoi Han" << endl;
        for (int i = 0; i < dauTus.size(); i++) {
            dauTus[i]->hienThi();
        }
    }
};

class NguoiDung {
public:
    QuanLyTaiChinh qlTaiChinh;
    TaiKhoan taiKhoan;

    NguoiDung(double soDuBanDau) : taiKhoan(soDuBanDau) {}

    void thucHienGiaoDich() {
        int luaChon = -1;
        while (luaChon != 0) {
            cout << "\n--TUY CHON--\n";
            cout << "1. Ghi Thu Nhap\n";
            cout << "2. Ghi Chi Tieu\n";
            cout << "3. Them Danh Muc Chi Tieu\n";
            cout << "4. Dau Tu\n";
            cout << "5. Thong Tin Tai Chinh\n";
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
                    taiKhoan.updateBalance(tien);
                    break;
                }

                case 2: {
                    double tien;
                    string mota;
                    cout << "Nhap so tien: ";
                    cin >> tien;

                    if (taiKhoan.getSoDu() < tien) {
                        cout << "Loi: So du khong duoc duoi 0.\n";
                        break;
                    }

                    cin.ignore();
                    cout << "Nhap mo ta: ";
                    getline(cin, mota);
                    qlTaiChinh.themGiaoDich(new ChiTieu(tien, mota));
                    taiKhoan.updateBalance(-tien);

                    if (taiKhoan.getSoDu() < 1000) {
                        cout << "Thong bao: So du cua ban da duoi 1000 VND. Xin vui long thanh toan nho!" << endl;
                    }
                    break;
                }

                case 3: {
                    string tenDanhMuc;
                    cout << "Nhap ten danh muc chi tieu: ";
                    cin.ignore();
                    getline(cin, tenDanhMuc);
                    DanhMucChiTieu *dm = new DanhMucChiTieu(tenDanhMuc);
                    qlTaiChinh.themDanhMucChiTieu(dm);
                    // Ghi nh?n các chi tiêu cho danh m?c này
                    double soTien;
                    cout << "Nhap so luong chi tieu: ";
                    int soLuotChiTieu;
                    cin >> soLuotChiTieu;
                    for (int i = 0; i < soLuotChiTieu; i++) {
                        cout << "Nhap so tien cho chi tieu " << (i + 1) << ": ";
                        cin >> soTien;
                        string moTa;
                        cout << "Nhap mo ta cho chi tieu " << (i + 1) << ": ";
                        cin.ignore();
                        getline(cin, moTa);
                        dm->themChiTieu(new ChiTieu(soTien, moTa));
                    }
                    break;
                }

                case 4: {
                    double tien;
                    int han;
                    cout << "Nhap so tien dau tu: ";
                    cin >> tien;
                    if (taiKhoan.getSoDu() < tien) {
                        cout << "Loi: So du khong duoc duoi 0.\n";
                        break;
                    }
                    cout << "Nhap thoi han (nam): ";
                    cin >> han;
                    qlTaiChinh.themDauTu(new DauTuCoPhieu(tien, han));
                    taiKhoan.updateBalance(-tien);
                    break;
                }

                case 5: {
                    qlTaiChinh.hienThiThongTin(taiKhoan.getSoDu());
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
};

int main() {
    cout << "---Chao mung den voi He Thong Quan Ly Tai Chinh!---\n";
    NguoiDung nguoiDung(0); // Khoi tao nguoi dung voi so du ban dau la 0
    nguoiDung.thucHienGiaoDich();

    return 0;
}


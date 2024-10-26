Ứng dụng quản lý tài chính cá nhân.
Xây dựng các lớp: Tài khoản, Giao dịch, Danh mục chi tiêu.
Thực hiện các chức năng: Ghi nhận giao dịch, thống kê chi tiêu, lập kế hoạch tài chính.
Mở rộng: Tích hợp với các dịch vụ ngân hàng, gửi thông báo nhắc nợ.

Cấu trúc báo cáo btn:
Phần 1: Giới thiệu chương trình
1.1. Mô tả
- Giới thiệu ngữ cảnh của class
- Các tính chất của Class
- Các thao tác được dùng trên Class
1.2. Mô hình của Class
  GiaoDich
├── ThuNhap
└── ChiTieu
DauTu
└── DauTuCoPhieu
TaiKhoan
QuanLyTaiChinh
DanhMucChiTieu
NguoiDung

Phần 2: Phân tích chương trình
Mô tả, giải thích, diễn giả về các thành phần trong class (thuộc tính, phương thức)
**demo:**
Lớp GiaoDich:

Thuộc tính:
soTien: Số tiền của giao dịch.
moTa: Mô tả giao dịch.
Phương thức:
hienThi(): Hiển thị thông tin giao dịch.
Lớp ThuNhap (kế thừa từ GiaoDich):

Phương thức:
hienThi(): Hiển thị thông tin thu nhập.
Lớp ChiTieu (kế thừa từ GiaoDich):

Phương thức:
hienThi(): Hiển thị thông tin chi tiêu.
Lớp DauTu:

Thuộc tính:
soTien: Số tiền đầu tư.
thoiHan: Thời hạn đầu tư.
Phương thức:
hienThi(): Hiển thị thông tin đầu tư.
soTienDaoHan(): Tính số tiền khi đáo hạn.
Lớp DauTuCoPhieu (kế thừa từ DauTu):

Phương thức:
soTienDaoHan(): Tính toán số tiền theo lãi suất hàng năm (8%).
Lớp TaiKhoan:

Thuộc tính:
soDu: Số dư tài khoản.
Phương thức:
nopTien(double tien): Nạp tiền vào tài khoản.
rutTien(double tien): Rút tiền từ tài khoản.
getSoDu(): Lấy số dư hiện tại.
Lớp DanhMucChiTieu:

Thuộc tính:
tenDanhMuc: Tên của danh mục.
tongChiTieu: Tổng chi tiêu trong danh mục.
Phương thức:
themChiTieu(double tien): Thêm chi tiêu vào danh mục.
hienThi(): Hiển thị thông tin danh mục chi tiêu.
Lớp QuanLyTaiChinh:

Thuộc tính:
giaoDichs: Danh sách các giao dịch.
dauTus: Danh sách các đầu tư.
Phương thức:
themGiaoDich(GiaoDich *gd): Thêm giao dịch mới.
themDauTu(DauTu *dt): Thêm đầu tư mới.
hienThiThongTin(double soDu): Hiển thị thông tin tài chính.
Lớp NguoiDung:

Thuộc tính:
qlTaiChinh: Đối tượng quản lý tài chính.
taiKhoan: Đối tượng tài khoản.
Phương thức:
thucHienGiaoDich(): Thực hiện các giao dịch tài chính.

Phần 3: Kết quả nghiên cứu
3.1. Kiến thức đã tự nghiên cứu
3.2. Vận dụng kến thức
  

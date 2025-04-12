#include<iostream>
#include<string>
using namespace std;
struct Nguoi{
    string ID;
    string HoTen;
    string MaChungKhoan;
    int SoCoPhieu;
    Nguoi* next;
    Nguoi* prev;
};
typedef Nguoi* nguoi;
nguoi head = NULL;
nguoi tail = NULL;
nguoi TaoNguoi(string id, string hoten, string macp, int socp)
{
    nguoi p = new Nguoi;
    p->ID = id;
    p->HoTen = hoten;
    p->MaChungKhoan = macp;
    p->SoCoPhieu = socp;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void NhapDanhSach(){
    int n;
    cout << "Nhap so luong nguoi: ";
    cin >> n;
    for(int i = 1; i <= n; i++){
        string id, hoten, macp;
        int socp;
        cout << "Nhap nguoi thu " << i << ":\nNhap CCCD: ";
        cin >> id;
        cout << "Nhap Ho Ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap Ma Chung Khoan: ";
        cin >> macp;
        cout << "Nhap So Co Phieu: ";
        cin >> socp;
        nguoi p = TaoNguoi(id, hoten, macp, socp);
        if(head == NULL){
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
        cout << endl;
    }
}
void LietKeTheoMaCK()
{
    string MaCK;
    cout << "Nhap ma chung khoan: ";
    cin >> MaCK;
    nguoi p = head;
    while(p != NULL)
    {
        if(p->MaChungKhoan == MaCK)
        {
            cout << "CCCD: " << p->ID << ", Ho Ten: " << p->HoTen << ", So Co Phieu: " << p->SoCoPhieu << endl;
        }
        p = p->next;
    }
}
void CoPhieuCaoNhat()
{
    int max = 0;
    nguoi p = head;
    while(p != NULL)
    {
        if(p->SoCoPhieu > max)
        {
            max = p->SoCoPhieu;
        }
        p = p->next;
    }
    p = head;
    cout << endl << "So co phieu cao nhat: " << max << endl;
    cout << "Danh sach nguoi co so co phieu cao nhat: " << endl;
    while(p != NULL)
    {
        if(p->SoCoPhieu == max)
        {
            cout << "CCCD: " << p->ID << ", Ho Ten: " << p->HoTen << ", So Co Phieu: " << p->SoCoPhieu << endl;
        }
        p = p->next;
    }
}
void XoaCCCD()
{
    string id;
    cout << endl << "Nhap CCCD can xoa: ";
    cin >> id;
    nguoi p = head;
    while(p != NULL)
    {
        if(p->ID == id)
        {
            if(p->prev == NULL) // Xoa phan tu dau
            {
                head = p->next;
            }
            else if(p->next == NULL) // Xoa phan tu cuoi
            {
                tail = p->prev;
                tail->next = NULL;
            }
            else // Xoa phan tu o giua
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            break;
        }
        p = p->next;
        nguoi temp = p->next;
    }
    cout << "Da xoa nguoi co CCCD: " << id << endl;
    cout << "Danh sach nguoi sau khi xoa: " << endl;
    p = head;
    while(p!=NULL)
    {
        cout << "CCCD: " << p->ID << ", Ho Ten: " << p->HoTen << ", So Co Phieu: " << p->SoCoPhieu << endl;
        p = p->next;
    }
    cout << endl;
}
int main()
{
    NhapDanhSach();
    LietKeTheoMaCK();
    CoPhieuCaoNhat();
    XoaCCCD();
}
/*
123456789012
Nguyen Van A
VIC
10000
234567890123
Tran Thi B
VHM
15000
345678901234
Le Van C
VIC
20000
*/

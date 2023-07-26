#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct sinhvien
{
    string msv;
    string hoten;
    string lop;
    int diem;
};
void nhap(sinhvien *&p, int &n, int &cot1, int &cot2, int &cot3, int &cot4)
{
    cout << "Nhap so sinh vien: ";
    cin >> n;
    p = new sinhvien[n];
    for (int i=0 ; i<n ; i++)
    {
        cout << "\t\tNhap thong tin sinh vien thu " << i+1 << ": " << endl << "Ma Sinh Vien: ";
        fflush(stdin);
        getline(cin,p[i].msv);
        if(p[i].msv.size() > cot1)
            cot1 = p[i].msv.size();

        cout << "Ho va Ten: ";
        getline(cin, p[i].hoten);
        if( p[i].hoten.size() > cot2)
            cot2 = p[i].hoten.size();
        
        cout << "Lop: ";
        getline(cin,p[i].lop);
        if( p[i].lop.size() > cot3) 
            cot3 = p[i].lop.size();

        cout << "Diem: ";
        cin >> p[i].diem;
    }
}
void xuat(sinhvien *p, int n, int cot1, int cot2, int cot3, int cot4)
{
    cout << "\t\tDanh sach sinh vien da nhap la: " << endl;
    cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2+3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4+3) << "Diem" << endl;
    for(int i=0 ; i<n ; i++)
        cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
}

void chuyen_lop(sinhvien *&p, int n, int cot1, int cot2, int cot3 , int cot4)
{
    string tmplop,tmpmsv;
    int demmsv=0;
    fflush(stdin);
    cout << "Nhap lop: ";
    getline(cin,tmplop);
    cout << "Nhap ma sinh vien: ";
    getline(cin, tmpmsv);
    for (int i=0 ; i<n ; i++)
    {
        if(p[i].msv == tmpmsv)
        {
            p[i].lop = tmplop;
            cout << left << setw(cot1+3) << "Ma Sinh Vien" << left << setw(cot2+3) << "Ho va Ten" << left << setw(cot3+3) << "Lop" << left << setw(cot4+3) << "Diem" << endl;
            cout << "\t\tSinh vien co ma sinh vien " << tmpmsv << " sau khi chuyen sang lop moi la: " << endl;
            cout << left << setw(cot1+3) << p[i].msv << left << setw(cot2+3) << p[i].hoten << left << setw(cot3+3) << p[i].lop << left << setw(cot4+3) << p[i].diem << endl;
            demmsv++;
            break;
        }
    }
    if (demmsv == 0)
        cout << "Khong co sinh vien nao co id nhu vay!" << endl;
}
int main()
{
    int n,cot1 = 12, cot2 = 9, cot3 = 3, cot4 = 4;
    sinhvien *p;
    nhap(p,n,cot1,cot2,cot3,cot4);
    xuat(p,n,cot1,cot2,cot3,cot4);
    chuyen_lop(p,n,cot1,cot2,cot3,cot4);

    return 0;
}
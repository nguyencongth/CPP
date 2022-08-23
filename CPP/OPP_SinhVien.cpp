#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
class sinhvien
{
	private:
		char hoten[50];
		char masv[50];
		float t;
		float l;
		float h;
		float dtb;
	public:
	    void nhap();
	    float tinhtb();
	    void xetthilai();
	    void xuat();
	};
	void sinhvien::nhap()
	{   fflush(stdin);
		cout<<" Nhap ho va ten sinh vien : ";
		cin.getline(hoten,sizeof(hoten));
		fflush(stdin);
		cout<<" Nhap ma sinh vien: ";
		cin.getline(masv,sizeof(masv));
		cout<<" Nhap diem toan: ";
		cin>>t;
		cout<<" Nhap diem li: ";
		cin>>l;
		cout<<" Nhap diem hoa: ";
		cin>>h;
	}
	void sinhvien::xuat()
	{
		cout<<" Ho va ten sinh vien: "<<hoten<<endl;
		cout<<" Ma sinh vien: "<<masv<<endl;
		cout<<" Diem toan:"<<t<<"\tDiem li: "<<l<<"\tDiem hoa: "<<h<<endl;
	} 
	float sinhvien::tinhtb()
	{  
		dtb = (t + l + h) / 3;
		return dtb;
	}
	void sinhvien::xetthilai()
	{
		if(t<5 || l<5 || h<5)
		{
			cout<<" Ho va ten sinh vien: "<<hoten<<endl;
			cout<<" Ma sinh vien: "<<masv<<endl;
			if(t<5)
			{
				cout<<" Thi lai mon toan va so diem hien tai la: "<<t<<endl;
			 } 
			 if(l<5)
			 {
			 	cout<<" Thi lai mon li va so diem hien tai la: "<<l<<endl;
			 }
			 if(h<5)
			 {
			 	cout<<" Thi lai mon hoa va so diem hien tai la: "<<h<<endl;
			 }
		}
	}
	int main ()
	{   sinhvien *sv;
		int n;
	sv =  new sinhvien[n+100];
	cout<<" Nhap so sinh vien: ";
	cin>>n;
		for(int i=0; i<n; i++)
		{
			sv[i].nhap();
		}
		cout<<endl;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1;j<n;j++)
			{   if(sv[i].tinhtb() > sv[j].tinhtb())
				{
					sinhvien tg = sv[i];
					sv[i] = sv[j];
					sv[j] = tg;
				}
			}
		}
		cout<<" Danh sach sinh vien sap xep theo diem trung binh la: "<<endl;
		for(int i = 0; i<n; i++)
		{
			sv[i].xuat();
			cout<<" Diem trung binh: "<<sv[i].tinhtb()<<endl;
		}
		cout<<endl;
		cout<<" Thong tin cua sinh vien co diem cao nhat la: "<<endl;
		sv[n-1].xuat();
		cout<<endl;
		cout<<" Thong tin dinh vien thi lai "<<endl;
		for(int i=0; i<n; i++)
		{
			sv[i].xetthilai();
		}
		delete sv;
		getch();
	}


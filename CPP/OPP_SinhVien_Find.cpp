#include<iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class nguoi
{
	protected:
		char hoten[20];
		int ns;
	public:
		void nhap()
		{
			cout<<" Nhap ho ten: ";
			cin.ignore(1);
			cin.getline(hoten, sizeof(hoten));
			cout<<" Nhap nam sinh: ";
			cin>>ns;
		}
		void xuat()
		{
			cout<<setw(15)<<hoten<<setw(15)<<ns;
		}
};
class sinhvien:public nguoi
{
	private:
		char masv[20];
		double dtb;
	public:
		void nhapsv()
		{
			nhap();
			cout<<" Nhap ma sinh vien: ";
			cin.ignore(1);
			cin.getline(masv, sizeof(masv));
			cout<<" Nhap diem trung binh: ";
			cin>>dtb;
		}
		void xuatsv()
		{
			xuat();
			cout<<setw(20)<<masv<<setw(22)<<dtb<<endl;
		}
		void intieude()
		{
			cout<<"   Ho va ten              ";
		    cout<<"Nam sinh            ";
		    cout<<"Ma sinh vien           ";
		    cout<<"Diem trung binh"<<endl;
		}
		double diemtb()
		{
			double k = dtb;
			return k;
		}
	int check(char s1[])
		{
			if(strcmp(hoten,s1)==0 || strcmp(masv,s1)==0)
			{
				return 1;
			}
			else return 0;
		}
};
main()
{
	sinhvien *sv;
	int n;
	cout<<" Nhap vao so luong sinh vien: ";
	cin>>n;
	sv = new sinhvien[n+1];
	for(int i=0; i<n; i++)
	{
		cout<<" Nhap thong tin sinh vien thu "<<i+1<<endl;
		sv[i].nhapsv();
	}
	cout<<endl;
	sv->intieude();
	for(int i=0; i<n; i++)
	{
		sv[i].xuatsv();
	}
	cout<<endl;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(sv[i].diemtb() > sv[j].diemtb())
			{
				sinhvien tg = sv[i];
				sv[i] = sv[j];
				sv[j] = tg;
			}
		}
	}
	cout<<" Danh sach sinh vien sap xep tang dan theo diem trung binh:"<<endl;
	sv->intieude();
	for(int i=0; i<n; i++)
	{
		sv[i].xuatsv();
	}
	int d=0;
	char find[20];
	do
	{
	cout<<" Nhap ho ten hoac ma sinh vien ban muon tim: ";
	fflush(stdin);
	cin.getline(find, sizeof(find));
	for(int i=0; i<n; i++)
	{
		if(sv[i].check(find))
		{
			sv[i].intieude();
			sv[i].xuatsv();
			d++;
		}
	}
	if(d == 0)
	{
		cout<<" Khong tim thay sinh vien ban vua nhap!!!"<<endl;
	}
	}while(d==0);
	delete sv;
	getch();
}

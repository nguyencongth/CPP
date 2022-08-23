#include<iostream>
#include<conio.h>
using namespace std;
class PhanSo
{
	private:
		int tu, mau;
	public:
		friend istream &operator>>(istream &input, PhanSo &P);
		friend ostream &operator<<(ostream &output, PhanSo P);
		PhanSo()
		{
			tu=0;
			mau=0;	
		}
		PhanSo(int t, int m)
		{
			tu=t;
			mau=m;
		}		
		~PhanSo()
		{
			tu=0;
			mau=0;
		}
		void rutgon();
		int UCLN(int tu, int mau);
		PhanSo operator + (PhanSo P);
		PhanSo operator - (PhanSo P);
		PhanSo operator * (PhanSo P);
		PhanSo operator / (PhanSo P);
};
istream &operator>>(istream &input, PhanSo &P)
{
	cout<<"Nhap tu so: ";
	input>>P.tu;
	do
	{
		cout<<"Nhap mau so khac 0: ";
		input>>P.mau;
	} while( P.mau == 0 );	
}
ostream &operator<<(ostream &output, PhanSo P)
{
	if(P.mau==1)
	{
		output<<P.tu<<endl;
	}
	else if(P.tu==0)
	{
		output<<P.tu<<endl;
	}
	else
	{
		output<<P.tu<<"/"<<P.mau<<endl;
	}
	return output;
}
int PhanSo::UCLN(int a, int b)
{
	if(a<0)
	{
		a *= -1;
	}
	if(b<0)
	{
		b *= -1;
	}
	while(a != b)
	{
		if(a>b)
		{
			a -= b;
		}
		else{
			b -= a;
		}
	}
	return a;
}
void PhanSo::rutgon()
{
	if(tu!=0)
	{
		int u;
	    u = UCLN(tu, mau);
	    tu = tu / u;
	    mau = mau / u;
	}
}
PhanSo PhanSo::operator + (PhanSo a)
{
	PhanSo kq;
    kq.tu = tu * a.mau + mau * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PhanSo PhanSo::operator - (PhanSo a)
{
	PhanSo kq;
    kq.tu = tu * a.mau - mau * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PhanSo PhanSo::operator * (PhanSo a)
{
	PhanSo kq;
    kq.tu = tu * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PhanSo PhanSo::operator / (PhanSo a)
{
	PhanSo kq;
    kq.tu = tu * a.mau;
    kq.mau = mau * a.tu;
    return kq;
}
main()
{
	PhanSo ps1, ps2, kq1, kq2, kq3, kq4;
	cin>>ps1;
	cout<<"Phan so vua nhap la: ";
	cout<<ps1;
	cin>>ps2; 
	cout<<"Phan so vua nhap la: ";
	cout<<ps2;
	cout<<"Phep cong: ";
	kq1 = ps1 + ps2;
	kq1.rutgon(); cout<<kq1;
	cout<<"Phep tru: ";
	kq2 = ps1 - ps2;
	kq2.rutgon(); cout<<kq2;
	cout<<"Phep nhan: ";
	kq3 = ps1 * ps2;
	kq3.rutgon(); cout<<kq3;
	cout<<"Phep chia: ";
	kq4 = ps1 / ps2;
	kq4.rutgon(); cout<<kq4;
	getch();
}


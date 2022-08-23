#include<iostream>
#include<conio.h>
using namespace std;
class PS
{
	private:
		int tu,mau;
	public:
		PS()
		{
			tu=0;
			mau=0;	
		}
		PS(int t, int m)
		{
			tu=t;
			mau=m;
		}		
		~PS()
		{
			tu=0;
			mau=0;
		}
		void nhap();
		void xuat();
		void rutgon();
		int UCLN(int tu, int mau);
		PS operator + (PS a);
		PS operator - (PS a);
		PS operator * (PS a);
		PS operator / (PS a);
};
void PS::nhap()
{
    cout << "Nhap tu so:  ";
    cin >> tu;
    do
    {
        cout << "Nhap mau so khac 0:  ";
        cin >> mau;
    } while (mau == 0);
    
}
void PS::xuat()
{
	if(mau==1)
	{
		cout<<tu<<endl;
	}
	else if(tu==0)
	{
		cout<<tu<<endl;
	}
	else
	{
		cout<<tu<<"/"<<mau<<endl;
	}
}
int PS::UCLN(int a, int b)
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
void PS::rutgon()
{
	if(tu!=0)
	{
		int u;
	    u = UCLN(tu, mau);
	    tu = tu / u;
	    mau = mau / u;
	}
}
PS PS::operator + (PS a)
{
	PS kq;
    kq.tu = tu * a.mau + mau * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PS PS::operator - (PS a)
{
	PS kq;
    kq.tu = tu * a.mau - mau * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PS PS::operator * (PS a)
{
	PS kq;
    kq.tu = tu * a.tu;
    kq.mau = mau * a.mau;
    return kq;
}
PS PS::operator / (PS a)
{
	PS kq;
    kq.tu = tu * a.mau;
    kq.mau = mau * a.tu;
    return kq;
}
main()
{
	PS ps1, ps2, kq1, kq2, kq3, kq4;
	ps1.nhap();
	cout<<"Phan so vua nhap la: ";
	ps1.xuat();
	ps2.nhap(); 
	cout<<"Phan so vua nhap la: ";
	ps2.xuat();
	cout<<"Phep cong: ";
	kq1 = ps1 + ps2;
	kq1.rutgon(); kq1.xuat();
	cout<<"Phep tru: ";
	kq2 = ps1 - ps2;
	kq2.rutgon(); kq2.xuat();
	cout<<"Phep nhan: ";
	kq3 = ps1 * ps2;
	kq3.rutgon(); kq3.xuat();
	cout<<"Phep chia: ";
	kq4 = ps1 / ps2;
	kq4.rutgon(); kq4.xuat();
	getch();
}



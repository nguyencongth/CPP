#include<iostream>
#include<conio.h>
using namespace std;
class SP
{
	private:
		float a, b;
	public:
		SP()
		{
			a=0;
			b=0;
		}
		SP(float a1, float b1)
		{
			a=a1;
			b=b1;
		}
		~SP()
		{
			a=0; 
			b=0;
		}
		void nhap();
		void xuat();
		SP operator + (SP a);
		SP operator - (SP a);
		SP operator * (SP a);
		SP operator / (SP a);
};
void SP::nhap()
{
	cout<<"Nhap phan thuc a = ";
	cin>>a;
	cout<<"Nhap phan ao b = ";
	cin>>b;
}
void SP::xuat()
{
	if(a==0)
	{
		cout<<b<<"i"<<endl;
	}
	else if(b==0)
	{
		cout<<a<<endl;
	}
	else if(b<0)
	{
		cout<<a<<" "<<b<<"i"<<endl;
	}
	else
	{
		cout<<a<<"+"<<b<<"i"<<endl;
	}
}
SP SP::operator + (SP c)
{
	SP kq;
	kq.a = a + c.a;
	kq.b = b + c.b;
	return kq;
}
SP SP::operator - (SP c)
{
	SP kq;
	kq.a = a - c.a;
	kq.b = b - c.b;
	return kq;
}
SP SP::operator * (SP c)
{
	SP kq;
	kq.a = a * c.a - b * c.b;
	kq.b = a * c.b + b * c.a;
	return kq;
}
SP SP::operator / (SP c)
{
	SP kq;
	kq.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
	kq.b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
	return kq;
}
main()
{
	SP sp1, sp2, kq1, kq2, kq3, kq4;
	sp1.nhap();
	cout<<"So phuc vua nhap la: "; sp1.xuat();
	sp2.nhap();
	cout<<"So phuc vua nhap la: "; sp2.xuat();
	cout<<"Phep cong: ";
	kq1 = sp1 + sp2;
	kq1.xuat();
	cout<<"Phep tru: ";
	kq2 = sp1 - sp2;
	kq2.xuat();
	cout<<"Phep nhan: ";
	kq3 = sp1 * sp2;
	kq3.xuat();
	cout<<"Phep chia: ";
	kq4 = sp1 / sp2;
	kq4.xuat();
	getch();
}


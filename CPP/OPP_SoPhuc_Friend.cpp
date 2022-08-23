#include<iostream>
#include<conio.h>
using namespace std;
class SoPhuc
{
	private:
		float a, b;
	public:
		friend istream &operator>>(istream &input, SoPhuc &P);
		friend ostream &operator<<(ostream &output, SoPhuc P);
		SoPhuc()
		{
			a=0;
			b=0;
		}
		SoPhuc(float a1, float b1)
		{
			a=a1;
			b=b1;
		}
		~SoPhuc()
		{
			a=0; 
			b=0;
		}
		SoPhuc operator + (SoPhuc P);
		SoPhuc operator - (SoPhuc P);
		SoPhuc operator * (SoPhuc P);
		SoPhuc operator / (SoPhuc P);
};
istream &operator>>(istream &input, SoPhuc &P)
{
	cout<<"Nhap phan thuc a = ";
	input>>P.a;
	cout<<"Nhap phan ao b = ";
	input>>P.b;
}
ostream &operator<<(ostream &output, SoPhuc P)
{
	if(P.a==0)
	{
		output<<P.b<<"i"<<endl;
	}
	else if(P.b==0)
	{
		output<<P.a<<endl;
	}
	else if(P.b<0)
	{
		output<<P.a<<" "<<P.b<<"i"<<endl;
	}
	else
	{
		output<<P.a<<"+"<<P.b<<"i"<<endl;
	}
	return output;
}
SoPhuc SoPhuc::operator + (SoPhuc c)
{
	SoPhuc kq;
	kq.a = a + c.a;
	kq.b = b + c.b;
	return kq;
}
SoPhuc SoPhuc::operator - (SoPhuc c)
{
	SoPhuc kq;
	kq.a = a - c.a;
	kq.b = b - c.b;
	return kq;
}
SoPhuc SoPhuc::operator * (SoPhuc c)
{
	SoPhuc kq;
	kq.a = a * c.a - b * c.b;
	kq.b = a * c.b + b * c.a;
	return kq;
}
SoPhuc SoPhuc::operator / (SoPhuc c)
{
	SoPhuc kq;
	kq.a = (a * c.a + b * c.b) / (c.a * c.a + c.b * c.b);
	kq.b = (b * c.a - a * c.b) / (c.a * c.a + c.b * c.b);
	return kq;
}
main()
{
	SoPhuc sp1, sp2, kq1, kq2, kq3, kq4;
	cin>>sp1;
	cout<<"So phuc vua nhap la: "; cout<<sp1;
	cin>>sp2;
	cout<<"So phuc vua nhap la: "; cout<<sp2;
	cout<<"Phep cong: ";
	kq1 = sp1 + sp2;
	cout<<kq1;
	cout<<"Phep tru: ";
	kq2 = sp1 - sp2;
	cout<<kq2;
	cout<<"Phep nhan: ";
	kq3 = sp1 * sp2;
	cout<<kq3;
	cout<<"Phep chia: ";
	kq4 = sp1 / sp2;
	cout<<kq4;
	getch();
}


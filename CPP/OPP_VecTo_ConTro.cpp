#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class vecto
{
	private:
		int n;
		int *a;
	public:
		void nhap();
		void xuat();
		void ptumin();
		void ptumax();
		void ptchanmod3();
		void ptam();
		void sochinhphuong();
		void sort();
};
void vecto::nhap()
{
	cout<<" Nhap so phan tu: ";
	cin>>n;
	a = new int[n];
	for(int i=0; i<n; i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void vecto::xuat()
{
	cout<<" Mang gom cac phan tu: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<setw(5)<<a[i];
	}
	cout<<endl;
}
void vecto::ptumin()
{
	int min=1000000000;
	for(int i=0; i<n; i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	cout<<" Gia tri min = "<<min<<endl;
}
void vecto::ptumax()
{
	int max=a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	cout<<" Gia tri max = "<<max<<endl;
}
void vecto::ptchanmod3()
{
	cout<<" Phan tu chan chia het cho 3: ";
	for(int i=0; i<n; i++)
	{
		if(a[i]%2==0 && a[i]%3==0)
		{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
}
void vecto::ptam()
{
	cout<<" Phan tu am: ";
	for(int i=0; i<n; i++)
	{
		if(a[i]<0)
		{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
}
void vecto::sochinhphuong()
{
	int t,x;
	cout<<" So chinh phuong: ";
	for(int i=0; i<n; i++)
	{
		t = sqrt(a[i]);
		if(t*t==a[i])
		{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
}
void vecto::sort()
{
	int tg;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				tg = a[i];
				a[i] = a[j];
				a[j]  =tg;
			}
		}
	}
	cout<<" Mang sau khi sap xep: "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<setw(5)<<a[i];
	}
	cout<<endl;
	delete a;
}
int main()
{
	vecto p;
	p.nhap();
	p.xuat();
	p.ptumin();
	p.ptumax();
	p.ptchanmod3();
	p.ptam();
	p.sochinhphuong();
	p.sort();
	system("pause");
	return 0;
}

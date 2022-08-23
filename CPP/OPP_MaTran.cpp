#include<iostream>
#include<conio.h>
using namespace std;
class matran
{
	private:
		int n,m;
		int a[10][10];
	public:
		void nhap(int a[10][10], int n, int m);
		void xuat(int a[10][10], int n, int m);
		int tongptuduongvien(int a[10][10], int n, int m);
		int tongptutrenduongcheochinh(int a[10][10], int n, int m);
		int tongptutrenduongcheophu(int a[10][10], int n, int m);
};
void matran::nhap(int a[10][10], int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<" a["<<i<<"]["<<j<<"]"<<"=";
			cin>>a[i][j];
		}
	}
}
void matran::xuat(int a[10][10], int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int matran::tongptuduongvien(int a[10][10], int n, int m)
{
	int s1=0;
	for(int i=0; i<m; i++)
	{
		s1 = s1 + a[0][i];
	}
	for(int i=1; i<n; i++)
	{
		s1 = s1 + a[i][0];
	}
	for(int i=1; i<m; i++)
	{
		s1 = s1 + a[n-1][i];
	}
	for(int i=1; i<n-1; i++)
	{
		s1 = s1 + a[i][m-1];
	}
	return s1;
}
int matran::tongptutrenduongcheochinh(int a[10][10], int n, int m)
{
	int s2=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i == j)
			{
				s2 = s2 + a[i][j];
			}
		}
	}
	return s2;
}
int matran::tongptutrenduongcheophu(int a[10][10], int n, int m)
{
	int s3=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(i+j == n-1)
			{
				s3 = s3 + a[i][j];
			}
		}
	}
	return s3;
}
main()
{
	matran mt;
    int a[10][10];
    int n, m;
    cout<<" Nhap so hang: ";
    cin >> n;
    cout<<" Nhap so cot: ";
    cin >> m;
    mt.nhap(a, n, m);
    mt.xuat(a, n, m);
    cout<<endl;
    cout<<" Tong cac phan tu cua duong vien ma tran la: "<<mt.tongptuduongvien(a,n,m)<<endl;    
    cout<<" Tong cac phan tu tren duong cheo chinh la: "<<mt.tongptutrenduongcheochinh(a,n,m)<<endl;
    cout<<" Tong cac phan tu tren duong cheo phu la: "<<mt.tongptutrenduongcheophu(a,n,m)<<endl;
    getch();
}


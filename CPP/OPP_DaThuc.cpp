#include<iostream>
using namespace std;
class dathuc
{
	protected:
		int bac;
		int *heso;
	public:
		dathuc()
		{
			bac=0;
			heso=0;
		}
		~dathuc()
		{
			bac=0;
			heso=0;
		}
		friend istream &operator>>(istream &is, dathuc &dt)
		{
			do
		    {
		        cout<<"Nhap bac cua da thuc: ";
		        is>>dt.bac;
		    }while (dt.bac <= 0);
		    cout<<"Nhap cac he so cua da thuc: "<<endl;
		    dt.heso = new int[dt.bac + 1];
		    for (int i = 0; i <= dt.bac; i++)
		    {
		        cout<<"He so x["<<i<<"] : ";
		        is>>dt.heso[i];
		    }
			return is;  
		}
		friend ostream &operator<<(ostream &os, dathuc dt)
		{
			os<<dt.heso[0];
		    if(dt.heso[1] < 0)
		    {
		        os<<" - "<<dt.heso[1] * -1<<" * x";
		
		    }
		    else
		    {
		        os<<" + "<<dt.heso[1]<<" * x";
		
		    }
		    for (int i = 2; i <= dt.bac; i++)
		    {
		        if(dt.heso[i] < 0)
		        {
		            os<<" - "<<dt.heso[i] * -1 <<" *x^"<<i;
		        }
		        else
		        {
		            os<<" + "<<dt.heso[i] <<" *x^"<<i;
		        }
		    }
		    cout<<endl;    
			return os;
		}
};
class dathuc1:public dathuc
{
	public:
		dathuc1 operator+(dathuc1 b)
		{
			dathuc1 kq;
			int max = bac>b.bac ? bac : b.bac;
			int min = bac<b.bac ? bac : b.bac;
			kq.bac = max;
		    kq.heso = new int[kq.bac + 1];
		    for (int i = 0; i <= min; i++)
		    {
		        kq.heso[i] = heso[i] + b.heso[i];
		    }
		    if(max == bac)
		    {
		        for (int i = min + 1; i <= max ; i++)
		        {
		            kq.heso[i] = heso[i];
		        }
		    }
		    else
		    {
		        for (int i = min + 1; i <= max; i++)
		        {
		            kq.heso[i] = b.heso[i];
		        }
		    }
		    return kq;
		}
		dathuc1 operator-(dathuc1 b)
		{
			dathuc1 kq;
			int max = bac>b.bac ? bac : b.bac;
			int min = bac<b.bac ? bac : b.bac;
			kq.bac = max;
		    kq.heso = new int[kq.bac + 1];
		    for (int i = 0; i <= min; ++i)
		    {
		        kq.heso[i] = heso[i] - b.heso[i];
		    }
		    if(max == bac)
		    {
		        for (int i = min + 1; i <= max ; ++i)
		        {
		            kq.heso[i] = heso[i];
		        }
		    }
		    else
		    {
		        for (int i = min + 1; i <= max; ++i)
		        {
		            kq.heso[i] = 0-b.heso[i];
		        }
		    }
		    return kq;
		}
		dathuc1 operator*(const dathuc1 &b)
		{
			int k;
			cout<<" Nhap hang so K bat ky, K = ";
			cin>>k;
			dathuc1 kq;
			int h;
      		h = kq.bac = bac + b.bac;
      		kq.heso = new int[h+1];
      		for(int i=0; i<=h; ++i)
      		{
      			kq.heso[i] = 0;
		    }
      		for(int i=0; i<=bac; ++i)
			{
				for(int j=0; j<=b.bac; ++j)
				{
					kq.heso[i+j] += heso[i] * b.heso[j]*k;
				}
			}
      		return kq;
		}
};
int main()
{
	dathuc1 a,b,kq;
	cin>>a;
	cout<<" Da thuc vua nhap la: ";
	cout<<a;
	cin>>b;
	cout<<" Da thuc vua nhap la: ";
	cout<<b;
	
	cout<<" Phep cong: ";
	kq=a+b;
	cout<<kq;
	
	cout<<" Phep tru: ";
	kq=a-b;
	cout<<kq;
	
	cout<<" Phep nhan: "<<endl;
	kq=a*b;
	cout<<kq;
	return 0;
}

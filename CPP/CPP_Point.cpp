#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class diem
{
	private:
		int x,y;
	public:
		diem()
		{
			int x=0;
			int y=0;
		}
		diem(int x1,int y1)
		{
		 x1=x;y1=y;	
		}
		~diem()
		{
			x=0;y=0;
		}
	void nhap();
	void xuat();
	float khoangcach(diem b);	
};
void diem::nhap()
{
	cout<<" nhap gia tri x:"<<endl;
	cin>>x;
	cout<<"nhap gia tri y:"<< endl;
	cin>>y;	
}
void diem::xuat()
{
	cout<<"toa do(x,y)=("<<x<<","<<y<<")";
}
float diem::khoangcach(diem b)
{
	float kc;
	kc=sqrt(pow(x-b.x,2)+pow(y-b.y,2));
	return kc;
}
main()
{
	int n;
	diem *p;
	cout<<"nhap so luong diem:"<<endl;
	cin>>n;
	p=new diem[n+1];
	for(int i=1;i<=n;i++)
	{
		cout<<"nhap diem thu"<<i<<endl;
		p[i].nhap();
	}
	cout<<"cac diem vua nhap:"<< endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"diem thu"<<i<< endl;
		p[i].xuat();
	}
	cout<<p[1].khoangcach(p[2])=AB<<endl;
	cout<<p[2].khoangcach(p[3])=BC<<endl;
	cout<<p[3].khoangcach(p[1])=CA<<endl;
	if(p[1].khoangcach(p[2])+p[2].khoangcach(p[3])>p[3].khoangcach(p[1])&&(p[3].khoangcach(p[1]+p[2].khoangcach(p[3]>p[1].khoangcach(p[2]))&&(p[1].khoangcach(p[2])+p[3].khoangcach(p[1]>p[2].khoangcach(p[3]))
	 cout<<"la hinh tam giac";
	else
	 cout<<"khong phai tam giac";
	delete p;
	getch(); 
	
}




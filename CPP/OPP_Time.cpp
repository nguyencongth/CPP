#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
class Time{
	private:
		int h,m,s;
	public:
		Time(){	h=0;m=0;s=0;};
		Time(int hour , int min , int sec){
			hour 	= h;
			min 	= m;
			sec 	= s;
		}
		~Time(){h=0;m=0;s=0;};
		bool checkTime();
		friend istream &operator>>(istream &is,Time &t);
		friend ostream &operator<<(ostream &os,Time t);
		Time operator ++ (int n);
		Time operator -- (int n);
};

istream &operator>>(istream &is,Time &t){
		cout<<"Nhap vao gio:  "<<"	";	is>>t.h;
		cout<<"Nhap vao phut: "<<"	";	is>>t.m;
		cout<<"Nhap vao giay: "<<"	";	is>>t.s;
		return is;
}
bool Time::checkTime(){
	if (h < 0 || h > 23 ||
        m < 0 || m > 59 ||
        s < 0 || s > 59)
    {
        return false;
    }
    return true;
}
ostream &operator<<(ostream &os,Time t){
	if (t.checkTime()){
        os	 << setfill('0') << setw(2) << t.h << " : "
             << setfill('0') << setw(2) << t.m << " : "
             << setfill('0') << setw(2) << t.s << endl;
    }
    else {	cout<<"Khong hop le : "<<endl;
	}
    return os;
}
Time Time::operator ++ (int n){
	Time kq;
	if(s!=59){
		kq.h=h;
		kq.m=m;
		kq.s=s+1;
	}
	else{
		if(m!=59){
			kq.h=h;
			kq.m=m+1;
			kq.s=59;
		}
		else{
			if(h!=23){
				kq.h=h+1;
				kq.m=59;
				kq.s=59;
			}
			else{
				kq.h=00;
				kq.m=00;
				kq.s=00;
			}
		}
	}
	return kq;
}
Time Time::operator -- (int n){
	Time kq;
	if(s!=0){
		kq.h=h;
		kq.m=m;
		kq.s=s-1;
	}
	else{
		if(m!=0){
			kq.h=h;
			kq.m=m-1;
			kq.s=59;
		}
		else{
			if(h!=0){
				kq.h=h-1;
				kq.m=59;
				kq.s=59;
			}
			else{
				kq.h=23;
				kq.m=59;
				kq.s=59;
			}
		}
	}
	return kq;
}
int main(){
	Time tg;
	cin>>tg;
	cout<<endl<<"Thoi gian vua nhap vao la: "<<endl<<tg;
	Time plus=tg++;
	cout<<endl<<"Thoi gian sau khi cong them 1 giay: "<<endl<<plus;
	Time minus=tg--;
	cout<<endl<<"Thoi gian sau khi tru them 1 giay:	"<<endl<<minus;
	return 0;
}

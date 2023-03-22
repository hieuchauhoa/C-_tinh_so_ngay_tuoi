#include<iostream>
#include<ctime>
using namespace std;

struct date
{
	int ngay;
	int thang;
	int nam;	
};

void laytgthuc(int &ng,int &th,int &na);
int kt_namnhuan(int n);
int songay(int n);
void ngay_du_boi_thang(int ncu,int nmoi,int tongcu,int tongmoi,int &tong);

int main()
{
	
	int demnamnhuan=0,a=0,b=0,tongngaytrongthang=0,ngaynam=0,tongngay=0;
	date ngsinh,htai; 
	cout<<"nhap ngay sinh: ";cin>>ngsinh.ngay;
	cout<<"nhap ngay thang: ";cin>>ngsinh.thang;
	cout<<"nhap ngay nam: ";cin>>ngsinh.nam;
	
	laytgthuc(htai.ngay,htai.thang,htai.nam);
	
	for(int i=ngsinh.nam;i<=htai.nam;i++)
	{
		if(kt_namnhuan(i)==1) demnamnhuan++;
	}
	
	ngay_du_boi_thang(ngsinh.thang,htai.thang,a,b,tongngaytrongthang);
	
	ngaynam=(htai.nam-ngsinh.nam)*365;
	tongngay=ngaynam+tongngaytrongthang+demnamnhuan+htai.ngay-ngsinh.ngay;
	cout<<"tong so ngay tu khi sinh: "<<tongngay<<endl;
	system("pause");
	return 0;
}

void laytgthuc(int &ng,int &th,int &na)
{
	time_t hientai= time(0);
	tm ht=*localtime(&hientai);
	ng=ht.tm_mday;
	th=ht.tm_mon+1;
	na=ht.tm_year+1900;
}

int kt_namnhuan(int n)
{
	if (n % 400 == 0) 
        return true;    
    if (n % 4 == 0 && n % 100 != 0) 
        return true;   
    return false; 
}

int songay(int n)
{
	if(n==1||n==3||n==5||n==7||n==8||n==10||n==12) return 31;
	if(n==2) return 28;
	return 30;
}

void ngay_du_boi_thang(int ncu,int nmoi,int tongcu,int tongmoi,int &tong)
{
	for(int i=1;i<ncu;i++)
	{
		tongcu=tongcu+songay(i);
	}
	for(int i=1;i<nmoi;i++)
	{
		tongmoi=tongmoi+songay(i);
	}
	tong=tongmoi-tongcu;
}
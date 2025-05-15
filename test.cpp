#include<bits/stdc++.h>
using namespace std;
int ucln(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int bcnn(int a,int b){
	return a * b / ucln(a, b);
}
struct Phanso{
       int tu,mau;

bool check_toigian(){
	return abs(ucln(tu,mau))==1;

}
friend Phanso operator + (Phanso a,Phanso b){
	Phanso sum;
	sum.mau=bcnn(a.mau,b.mau);
	sum.tu=sum.mau/a.mau*a.tu+sum.mau/b.mau*b.tu;
	return sum;

}
friend Phanso operator - (Phanso a,Phanso b){
	Phanso sub;
	sub.mau=bcnn(a.mau,b.mau);
	sub.tu=sub.mau/a.mau*a.tu-sub.mau/b.mau*b.tu;
	return sub;
}


};
void print(Phanso a){
	if (a.check_toigian()) cout<<a.tu<<"/"<<a.mau<<endl;
	else {
		a.tu/=ucln(a.tu,a.mau);
		a.mau/=ucln(a.tu,a.mau);
		cout<<a.tu<<"/"<<a.mau;
	}
}
int main(){
	Phanso a,b;
	cin>>a.tu>>a.mau>>b.tu>>b.mau;
	print(a);
	cout<<endl;
	print(b);
	cout<<endl;
	print(a+b);
	cout<<endl;
	print(a-b);
	cout<<endl;

}
#ifndef CIRCLE_H
#define  CIRCLE_H
#include <iostream>
#include <cstdlib>
using namespace std;
int shift;
struct password{
	string website;
	string pin;
	int safe;
	void change(int shift){
		for(int i=0;i<pin.length();i++){
			if(pin[i]>='a'&&pin[i]<='z'){
				pin[i]+=shift;
				if(pin[i]>'z'){
					pin[i]-='z';
					pin[i]+='a'-1;
				}
			}
			else if(pin[i]>='A'&&pin[i]<='Z'){
				pin[i]+=shift;
				if(pin[i]>'Z'){
					pin[i]-='Z';
					pin[i]+='A'-1;
				}
			}
			else if(pin[i]>='0'&&pin[i]<='9'){
				pin[i]+=shift;
				if(pin[i]>'9'){
					pin[i]-='9';
					pin[i]+='0'-1;
				}
			}
		}
	}
}pw[1000];
string random;
int f;
int cnt;
bool init(){
	freopen("password.in","r",stdin);
	cin>>cnt;
	cin>>random;
	if(cnt==0&&random.length()==0){
    freopen("CON","r",stdin);
		return false;
	}
	f=int(random[0]);
	srand(f);
	shift=rand()%24;
	for(int i=1;i<=cnt;i++){
		cin>>pw[i].website;
		cin>>pw[i].pin;
		cin>>pw[i].safe;
		pw[i].change(shift);
	}
	cin.clear();
	freopen("CON","r",stdin);
	return true;
}
int p_find(string str,bool f){
	for(int i=1;i<=cnt;i++){
		if(f==true&&str==pw[i].pin||f==false&&str==pw[i].website){
			return i;
		}
	}
	return 0;//没有
}
bool sign_in(){
	freopen("CON","r",stdin);
	string str;
	cout<<"请输入总密码:";//身份确认
	cin>>str;
	if(str!=random){
		return false;
	}
	return true;
}
void revise(string web){
	int flag=p_find(web,true);//搜索web，密码搜索
	if(flag==0){
		cout<<"不存在密码!"<<endl;
		system("cls");
		return;
	}
	cout<<"输入新密码:";
	cin>>pw[flag].pin;
	return;
}
short check(string str){
	int ch[5];
	for(int i=0;i<str.length();i++){
		if(str[i]>='a'&&str[i]<='z'){
			ch[1]++;
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			ch[2]++;
		}
		else if(str[i]>='0'&&str[i]<='9'){
			ch[3]++;
		}
		else{
			ch[4]++;
		}
	}
	if(str=="123456"||str=="password"){
		return -1;//这是什么?!
	}
	else if(ch[1]>=3&&ch[2]>=3&&ch[3]>=3&&ch[4]>=1){
		return 1;//非常高
	}
	else if(ch[1]>=2&&ch[2]>=2&&ch[3]>=3&&ch[4]<=1){
		return 2;//还可以
	}
	else{
		return 3;//弱密码
	}
}
#endif

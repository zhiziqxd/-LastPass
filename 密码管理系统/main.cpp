#include "password.h"
#include <unistd.h>
using namespace std;
char a;
int main(){
	if(init()==false){
		cout<<"ÇëÊäÈëÄãµÄÃÜÂë:";
		string str;
		cin>>str;
		freopen("password.in","w",stdout);
		cout<<0<<" "<<str;
		return 0;
	}
	if(sign_in()==false){
		cout<<"µÇÂ¼Ê§°Ü!"<<endl;
		sleep(1);
		return 0;
	}
  while(true){
  	cin>>a;
  	cin.clear();
		if(a=='A'){
			cnt++;
			cout<<"ÊäÈëÍøÕ¾:";
			cin>>pw[cnt].website;
			cout<<"ÊäÈëÃÜÂë:";
			cin>>pw[cnt].pin;
			cout<<"ok";
			pw[cnt].safe=check(pw[cnt].pin);
			sleep(1);
			system("cls");
		}
		else if(a=='S'){
			for(int i=1;i<=cnt;i++){
				cout<<pw[i].website<<" "<<pw[i].pin<<" ";
				if(pw[i].safe==1){
					cout<<"·Ç³£°²È«"<<endl;
				}
				else if(pw[i].safe==2){
					cout<<"ÆÕÍ¨"<<endl;
				}
				else if(pw[i].safe==3){
					cout<<"ÈõÃÜÂë"<<endl;
				}
				else if(pw[i].safe==-1){
					cout<<"Ê®·ÖÈõ"<<endl;
				}
			}
			system("pause");
			system("cls");
		}
		else if(a=='D'){
			string str;
			cin>>str;//else ifÊÇ¸öºÃ¶«Î÷
			int start=p_find(str,true);//ÃÜÂë²éÕÒ
			if(start==0||start>cnt){
				cout<<"´íÎó"<<endl;
				sleep(1);
				system("cls");
			}
			else{
				for(int i=start;i<=cnt;i++){
					pw[i].website=pw[i+1].website;
					pw[i].pin=pw[i+1].pin;
					pw[i].safe=pw[i+1].safe;
				}
			}
		}
		else if(a=='F'){
			string str;
			cin>>str;
			int to=p_find(str,false);
			if(to==0){
				cout<<"Î´ÕÒµ½ÃÜÂë!"<<endl;
				sleep(1);
				system("cls");
			}
			else{
				cout<<str<<" "<<pw[to].pin<<endl;
				system("pause");
				system("cls");
			}
		}
		else if(a=='E'){
			freopen("password.in","w",stdout);
			cout<<cnt<<" "<<random<<endl;
			for(int i=1;i<=cnt;i++){
				cout<<pw[i].website<<" "<<pw[i].pin<<" "<<pw[i].safe<<endl;
			}
			return 0;
		}
		else{
			cout<<"´íÎó!"<<endl;
			sleep(1);
			system("cls");
		}
	}
}

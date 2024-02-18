#include <iostream>
using namespace std;
// class Password 생성 
class Password{
    string password;
    public:
	Password(string fir_pw);
	void pw_check();
	bool pw_change();
};
// 생성자
Password::Password(string fir_pw){
    password = fir_pw;
};
  
// 패스워드 확인 함수
void Password::pw_check(){
    string pw_check;
    while(1){
	cout<<"패스워드 입력하세요:";
	cin>>pw_check;
	// 패스워드 일치시 break
	if(password == pw_check){
	    cout<<"맞았습니다. "<<endl;
	    break;
	}
	// 패스워드 불일치시 재입력
	else
	    cout<<"틀렸습니다."<<endl;
    }
};
// 패스워드 변경 함수
bool Password::pw_change(){
    string pw_change;
    while(1){
	cout<<"패스워드를 변경합니다 (종료X) : ";
	cin>>pw_change;
	// X값 입력시 1 리턴	
	if(pw_change == "X"){
	    return 1;
	}
	// 영문, 숫자 확인
	int n = pw_change.length();
	int alpa = 0;
	int num = 0;
	for(int i=0; i<n; i++){
	    if('A'<=pw_change[i]&&pw_change[i]<='Z')
		alpa++;
	    else if('a'<=pw_change[i]&&pw_change[i]<='z')
		alpa++;
	    else if('0'<=pw_change[i]&&pw_change[i]<='9')
		num++;
	    }
	// 영문, 숫자 포함시 패스워드 변경후 0 리턴
	if(alpa>0&&num>0){
	    cout<<"패스워드가 변경되었습니다."<<endl;
	    password = pw_change;
	    return 0;
	}
	// 영문, 숫자 미포함시 재입력
	else
	    cout<<"패스워드는 영문자와 숫자가 포함되어야 합니다."<<endl;
    }
};
// class Quiz 생성
class Quiz{
    public:
        void solve(Password *password);
};
// 패스워드 확인, 변경
void Quiz::solve(Password *password){
    while(1){
	password->pw_check();
	// pw_change()값이 1이면 종료
	if(password->pw_change())
	    break;
    }
};

int main(){
    Password password("abcd1234");
    Quiz q;
    q.solve(&password);
    return 0;
}

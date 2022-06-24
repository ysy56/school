#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

class UserPassword{
    string pw_;
    public:
	void get_pw(string pw){pw_ = pw;};
	bool check_pw(string pw){return (pw_==pw);};
	bool change_pw(string pw); 
};

bool UserPassword::change_pw(string pw){
    while(1){
	int num_alpha = 0;
	int num_digit = 0;
	int len = pw.length();
	if(len<8)
	    return false;
	for (int i = 0; i<len; i++){
	    if(isalpha(pw[i])) num_alpha++;
	    if(isdigit(pw[i])) num_digit++;
	}
	if(num_alpha>0 && num_digit>0){
	    pw_ = pw;
	    return true;
	    break;
	}
    }
}

class UserID{
    string id_;
    public:
	void get_id(string id){id_ = id;};
};

class Userinfo{
    UserPassword info_pw_;
    UserID info_id_;
    public:
	Userinfo(string init_pw, string init_id);
	void play();
	bool exit_change_pw();
};

Userinfo::Userinfo(string id, string pw){
    info_id_.get_id(id);
    info_pw_.get_pw(pw);
}

void Userinfo::play(){
    string pw;
    string id;
    while(1){
	cout<<"아이디 입력하세요:";
	cin>>id;
	cout<<"비밀번호 입력하세요:";
	cin>>pw;
	if(info_pw_.check_pw(pw)){
	    cout<<"맞았습니다."<<endl;
	    if(exit_change_pw())
		break;
	}
	else{
	    cout<<"틀렸습니다."<<endl;
	}
    }
}
bool Userinfo::exit_change_pw(){
    string pw;
    while(1){
	cout<<"패스워드를 변경합니다(종료X):";
	cin>>pw;
	if(pw == "X")
	    return true;
	if(info_pw_.change_pw(pw)){
	    cout<<"패스워드가 변경되었습니다."<<endl;
	    break;
	}
	else
	    cout<<"패스워드는 8자리 이상으로 구성되어야 하며, 영문자와 숫자가 포함되어야 합니다."<<endl;
    }
    return false;
}
int main(int argc, char* argv[]){
    Userinfo user("user", "abcd1234");
    user.play();
    return 0;
}

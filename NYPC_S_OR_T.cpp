#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int jumpToFourth(int now){
	return 4 - (now % 4);
}
int main(){
	int result = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); ++i){
		if(s[i]=='S'){
			result++;
		}else if(s[i] == 'T'){
			result += jumpToFourth(result);
		}
	}
	cout << s <<endl;
	cout << s.length()<<endl;
	cout << result <<endl;
}

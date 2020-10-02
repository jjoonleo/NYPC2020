#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int timeToNum(char *time){
	int minute = ((int)time[0] - 48)*10+((int)time[1] - 48);
	int second = ((int)time[3] - 48)*10+((int)time[4] - 48);
	int small = ((int)time[6] - 48)*10+((int)time[7] - 48);
	return minute*6000 + second*100 + small;
}

int main(){
	char time[3][8], tried[8];
	int time_i[3];
	int N, tried_i;
	for(int i = 0; i < 3; ++i){
		cin >> time[i];
		time_i[i] = timeToNum(time[i]);
	}
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> tried;
		tried_i = timeToNum(tried);
		if(tried_i <= time_i[2]){
			printf("***\n");
		}else if(tried_i <= time_i[1]){
			printf("**\n");
		}else if(tried_i <= time_i[0]){
			printf("*\n");
		}else{
			printf(":(\n");
		}
	}
	
	
	
}

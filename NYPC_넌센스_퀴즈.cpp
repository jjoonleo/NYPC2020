#include<stdio.h>
#include<iostream>

using namespace std;
// 1:+ 2:- 3:* 4:/

float cal(float x, float y, int op){
	switch(op){
		case 0:
			return x + y;
		case 1:
			return x - y;
		case 2:
			return x * y;
		case 3:
			return x / y;
		case 4:
			return x + (y/10) ;
	}
}

char oper(int op){
	switch(op){
		case 0:
			return '+';
		case 1:
			return '-';
		case 2:
			return '*';
		case 3:
			return '/';
		case 4:
			return '.';
	}
}

int main(){
	int T;
	float arr[4];
	float result1, result2;
	cin >> T;
	for(int i = 0; i < T; ++i){
		for(int j = 0; j < 4; ++j){
			cin >> arr[j];
		}
		for(int op1 = 0; op1 < 5; ++op1){
			//cout << "for j: " << j << endl;
			for(int op2 = 0; op2 < 5; ++op2){
				if(op1 == 4 ){
					result1 = cal(arr[0], arr[1], op1);
					result2 = cal(result1, arr[2], op2);
				}
				else if(op2 == 4){
					result1 = cal(arr[1], arr[2], op2);
					result2 = cal(arr[0], result1, op1);
				}
				else if(op1 == 3 || op1 == 2){
					result1 = cal(arr[0], arr[1], op1);
					result2 = cal(result1, arr[2], op2);
				}
				else if(op2 == 3 || op2 == 2){
					result1 = cal(arr[1], arr[2], op2);
					result2 = cal(arr[0], result1, op1);
				}
				else {
					result1 = cal(arr[0], arr[1], op1);
					result2 = cal(result1, arr[2], op2);
				}
				//printf("result %.0f%c%.0f%c%.0f=%.0f\n",arr[0], oper(j), arr[1], oper(k), arr[2], result2);
				if(result2 == arr[3]){
					printf("%.0f%c%.0f%c%.0f=%.0f\n",arr[0], oper(op1), arr[1], oper(op2), arr[2], arr[3]);
					op1 = 5;
					op2 = 5;
				}
			}
		}
	}	
}

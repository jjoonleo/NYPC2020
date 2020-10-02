#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int largest(const int *arr){
	int best = arr[0];
	for(int i = 1; i < 4; ++i){
		best = max(arr[i], best);
	}
	return best;
}
int sum(const int *arr){
	int ret = 0;
	for(int i = 0; i < 4; ++i){
		ret += arr[i];
	}
	return ret;
}


int main(){
	bool S = false, I = false;
	int T;
	int my[1000][4], you[1000][4];
	scanf("%d", &T);
	for(int i = 0; i < T; ++i){
		S = false, I = false;
		for(int k = 0; k < 4; ++k)
			scanf("%d", &my[i][k]);
		for(int k = 0; k < 4; ++k)
			scanf("%d", &you[i][k]);
		if(largest(my[i]) > largest(you[i]))
			I = true;
		if(sum(my[i]) > sum(you[i]))
			S = true;
		
		if(I==S){
			printf("R\n");
		}else{
			printf(S?"S\n":"I\n");
		}
	}
}


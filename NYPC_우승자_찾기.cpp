#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;

bool DoesItHaveThis(int x, vector<int> &arr, int k){
	for(int i = 0; i < arr.size(); ++i){
		if(arr[i] == x)
			return 1;
	}
	return 0;
}

bool couldBeFirst(int *arr, int K, int n){
	vector<int> num;
	//printf("n: %d\n", n);
	int i = 0;
	bool isFirst = true;
	while(i < K){
		while(i < K){
			//printf("arr[%d]: %d\n", i, arr[i]);
			if(arr[i] == n){
				if(isFirst && i!=0){
					break;
				}
				return 1;
			}
				
			if(DoesItHaveThis(arr[i],num,K)){
				break;
			}
			else{
				num.push_back(arr[i]);
			}
				
			++i;
		}
		num.resize(0);
		isFirst = false;
		while(arr[i] != n && i < K)
			++i;
		++i;

	}
	return 0;
}

int main(){
	vector<int> users;
	int N, K, arr[10001];
	cin >> N;
	cin >> K;
	for(int i = 0; i < K; ++i){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; ++i){
		if(couldBeFirst(arr, K, i)) {
			users.push_back(i);
		}
	}
	printf("%d\n", users.size());
	for(int i = 0; i < users.size(); ++i){
		printf("%d ", users[i]);
	}
}


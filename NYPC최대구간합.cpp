#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long MAX(long long x, long long y){
	return x>y ? x:y;
}
long long MSS(const vector<int>& array, int n){
	long long best = -123456789, sum = 0;
	for(int k = 0; k < n; ++k){
		sum = MAX(array[k], sum+array[k]);
		best = MAX(best, sum);
	}
	return best;
}


int main(){
	int n, in;
	vector<int> array;
	scanf("%d", &n);
	for(int i = 0; i< n; ++i){
		scanf("%d", &in);
		array.push_back(in);
	}
	
	printf("%lld", MSS(array,n));
}

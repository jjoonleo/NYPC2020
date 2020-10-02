#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
int maxn(int *d, int N){
	int ret = d[0];
	for(int i = 0; i < N; ++i){
		ret = max(ret, d[i]);
	}
}
int minn(int *d, int N){
	int ret = d[0];
	for(int i = 0; i < N; ++i){
		ret = min(ret, d[i]);
	}
}
int main(){
	int X, R, nX;
	int N;
	int max;
	bool pos = true;
	int d[100000], s[100000];
	cin >> X >> R;
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> d[i] >> s[i];
	}
	max = X+R;
	while(1){
	
	for(int i = 0; i < N; ++i){
		
		if(d[i] < 0 && s[i] <= 0){
		
			printf("F");
			return 0;
		
		}
		if(d[i] > max && s[i] >= 0){
		
			printf("F");
			return 0;
		
		}
	}
	for(;d[0] <= 0 && d[0] >= max;){
		for(int i = 0; i < N; ++i){
			d[i] += s[i]; 
		}
	}
	//for(nX = 0; nX <= X; ++nX){
		pos = true;
		//printf("nX: %d, max: %d\n", nX, nX + R);
		/*for(int i = 0; i < N; ++i){
			if(d[i] > max || d[i] < 0){
				pos = false;
			}
		}*/
		//if(pos){
			if(maxn(d,N) - minn(d,N) <= R && d[0] >= 0 && d[0] <= max){
				printf("T");
				return 0;
			}
		
		//}
	//}
	//printf("\n");
	for(int i = 0; i < N; ++i){
		d[i] += s[i]; 
	}
	}
}

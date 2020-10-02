#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<stdlib.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main(){
	vector<pair<int, int>> p;  //first userID second difference
	int N, S, K;
	int score[500001] = {0,};
	p.push_back(make_pair(-1,-1));
	scanf("%d", &N);
	scanf("%d %d",&S, &K);
	for(int i = 1; i <= N; ++i){
		cin >> score[i];
		p.push_back(make_pair(i, abs(S - score[i])));
		printf("%d\n", p[i].second);
	}
	sort(p.begin(),p.end(), cmp);
	for(int i = 1; i <= K; ++i){
		printf("%d\n", p[i].first);
	}
	
}

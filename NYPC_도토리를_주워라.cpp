#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

int N;

pair<int, vector<char>> mem[52][52];

pair<int, vector<char>> numberOfAcorn(int **arr, int x, int y){
	//cout << "x: "<< x << "  y:  " << y << endl;
	vector<char> ret;
	int i;
	int acorn = 0;
	int maxAcorn = 0;
	for(x; arr[y][x + 1] != -1; ++x){
		ret.push_back('R');
		//cout << "x++: " << x << endl;
		//if(arr[y][x] == 1) acorn++;
	}
	
	for(x ; arr[y][x - 1] != -1; --x){
		//cout << "x--: " << x << endl;
		ret.push_back('L');
		if(arr[y][x] == 1) acorn++;
	}
	if(arr[y][x] == 1) acorn++;
	int X = x, Y = y;
	if(mem[Y][X].first != -1){
		return make_pair(mem[Y][X].first, mem[y][x].second) ;
	}
		
	if(y == N - 2){
		//cout << "lastLine" << endl;
		for(i = x; i < N - 2 && arr[y][i] != -1; ++i){
		}
		if(i == N - 2){
			ret.resize(0);
			mem[Y][X].first = acorn;
			//cout << mem[Y][X] << " X: "<< X << " Y: " << Y << endl;
			return make_pair(acorn , ret);			
		}
		else{
			//cout << "lastLine failed" << endl;
			return make_pair(-1, ret);
		}
	}
	
	
	vector<char> ret2;
	i = 1;
	bool deadend = true;
	for(x; arr[y][x] != -1; ++x){
		ret.push_back('R');
		//cout << "before x: "<< x << "  y:  " << y << endl;
		if((arr[y + 1][x + 1] == -1 || arr[y][x + 1] == -1)&& arr[y + 1][x] != -1){
			
			pair<int, vector<char>> p = numberOfAcorn(arr, x, y + 1);
			if (deadend == true && p.first != -1) {
				deadend = false;
			}
			if(maxAcorn < p.first){
				maxAcorn = p.first;
				ret2 = ret;
				ret2.push_back('D');
				ret2.insert(ret.end(), p.second.begin(), p.second.end());
			}
			x++;
			i++;
			//cout << "after x: "<< x << "  y:  " << y << endl;
		}
		
	}
	if (deadend) {
		ret.resize(0);
		return make_pair(-1, ret);
	}
	mem[Y][X] = make_pair(acorn + maxAcorn, ret);
	return make_pair(acorn + maxAcorn, ret);
}

int main(){
	vector<char> v;
	for(int i = 0; i < 52; ++i){
		for(int j = 0; j < 52; ++j){
			mem[i][j] = make_pair(-1, v);
		}
	}
	
	
	int **arr;
	cin >> N;
	N+=2;
	
	arr = (int **)malloc(sizeof(int*) * N);
	arr[0] = (int *)malloc(sizeof(int) * N*N);
	for( int i=1; i<N; i++){
    	arr[i] = arr[ i-1 ] + N;
	}
	
	
	if(arr == NULL)
		cout << "malloc error";
		
	for(int y = 0; y < N; ++y){
		for(int x = 0; x < N; ++x){
			
			if(x == 0 || y == 0 || x == N - 1 || y == N -1){
				arr[y][x] = -1; 
				continue;
			}
				
			char c;
			cin >> c;
			switch(c){
				case '.': 
					arr[y][x] = 0;
					break;
				case 'D':
					arr[y][x] = 1;
					break;
				case 'U':
					arr[y][x] = -1;
					break;
			}			
		}
	}
	for(int y = 0; y < N; ++y){
		for(int x = 0; x < N; ++x){
			printf("%2d",arr[y][x]);			
		}
		cout << endl;
	}
	//cout << arr[1][1] <<endl;
	pair<int, vector<char>> p = numberOfAcorn(arr, 1, 1);
	printf("%d\n", p.first);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			printf("%2d ", mem[i][j].first);
		}
		cout << endl;
	}
	for(int i = 0; i < p.second.size(); ++i){
		printf("%c", p.second[i]);
	}
} 

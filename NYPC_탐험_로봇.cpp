#include<stdio.h>

int main(){
    int R, C;
    bool l = false;
    int ret = 0;
    char S[4];
    char map[1001];
    scanf("%d %d", &R, &C);
    scanf("%s", S);
    scanf("%s", map);
    
	if(S[1] == 'a'){
		for(int i = 0; map[i] != 0; i++){
        if(map[i] == 'L'){
            l = true;
        }
        else if(map[i] == '?'){
        	if(l){
        		l = false;
        		ret++;
			}
			else{
				l = true;
			}
		}
        else if(l && map[i] == 'S'){
            l = false;
            ret++;
        }
    }
    if(l)
        ret++;
	}
	else{
		for(int i = 0; map[i] != 0; i++){
        if(map[i] == 'L'){
            l = true;
        }
        else if(l && map[i] == 'S'){
            l = false;
            ret++;
        }
    }
    if(l)
        ret++;
	}
    
    printf("%d", ret);
}

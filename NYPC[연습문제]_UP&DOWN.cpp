#include <stdio.h>
#include <string.h>

int main()
{
    char reply[99] = {0,};
    int max = 1001;
    int min = 0;
    int i = 500;
    int change = i/2;
    while (1){
        printf("%d\n", i); fflush(stdout);
        scanf("%s", reply);
        if (!strcmp(reply, "CORRECT"))
            break;
        else if (!strcmp(reply, "UP")){
        	//printf("min %d\n", min);
            min = i;
            i = (max - i) / 2 + i;
        }
        else if (!strcmp(reply, "DOWN")){
        	max=i;
			//printf("max %d\n", max);
            i -= (i - min) / 2;
            
        }
    }
}

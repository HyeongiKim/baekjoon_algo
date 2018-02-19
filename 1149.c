#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 0
#define G 1
#define B 2
#define RGB 3
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    int i, n, rgb, ans;
    char str[100];
    char* ptr;

    fgets(str,sizeof(str),stdin);
    n = atoi(str);
    int costs[n][RGB], D[n][RGB];
    
    for (i=0;i<n;i++){
        fgets(str,sizeof(str),stdin);
        ptr = strtok(str," ");
        
        rgb = 0;
        while (ptr != NULL){
            costs[i][rgb] = atoi(ptr);
            ptr = strtok(NULL," ");
            rgb++;
        }
    }

    for (i=0;i<n;i++){
        if (i==0){
            D[i][R] = costs[i][R];
            D[i][G] = costs[i][G];
            D[i][B] = costs[i][B];
        }
        else {
            D[i][R] = MIN(D[i-1][G],D[i-1][B]) + costs[i][R];
            D[i][G] = MIN(D[i-1][R],D[i-1][B]) + costs[i][G];
            D[i][B] = MIN(D[i-1][R],D[i-1][G]) + costs[i][B];
        }
        
    }
    ans = MIN(MIN(D[n-1][R],D[n-1][G]),D[n-1][B]);
    printf("%d\n",ans);
    return 0;
}

#include<stdio.h>
#include<string.h>

#define INF 987654321 //impossible route
#define START 0
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int dist[17][17]; //16 cities
int cache[17][1<<17]; //memory for bit masking
int N;

int TSP(int current, int visited)
{
    int i;

    if (visited == (1<<N)-1)
        return dist[current][START]?dist[current][START]:INF;
    
    int ret = cache[current][visited]; // Set ret's addr. to cache[c][v]'s addr.
    if (ret != -1) return ret;

    ret = INF;
    for (i=0;i<N;i++){
        if (visited & (1<<i)) continue;
        if (dist[current][i] == 0) continue;
        ret = MIN(ret, TSP(i,visited | (1<<i)) + dist[current][i]);
    }
    return ret;
}
int main(void)
{
    int i, j;

    scanf("%d",&N);
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            scanf("%d",&dist[i][j]);
        }
    }
    memset(cache, -1, sizeof(cache)); //Set cache value to -1
    printf("%d\n",TSP(0,1));
    return 0;
}

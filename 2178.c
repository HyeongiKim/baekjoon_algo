#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main(void)
{
    int M, N, head, tail, x, y, i, j;
    
    scanf("%d %d", &N, &M);
    int miro[N][M];
    
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            scanf("%1d",&miro[i][j]);
        }
    }
    
    int que[N*M + 1][2];
    
    //Init Queue
    head = 0;
    tail = 0;
    que[tail][0] = 0; //start x
    que[tail][1] = 0; //start y
    tail++;
    miro[0][0] = 0; // visited

    while (head < tail){
        //POP
        x = que[head][0];
        y = que[head][1];
        head++;

        if (x-1 >=0 && miro[x-1][y] == 1){
            miro[x-1][y] = miro[x][y] + 1;
            //PUSH
            que[tail][0] = x-1;
            que[tail][1] = y;
            tail++;
        }
        if (y-1 >=0 && miro[x][y-1] == 1){
            miro[x][y-1] = miro[x][y] + 1;
            //PUSH
            que[tail][0] = x;
            que[tail][1] = y-1;
            tail++;
        }
        if (x+1 < N && miro[x+1][y] == 1){
            miro[x+1][y] = miro[x][y] + 1;
            //PUSH
            que[tail][0] = x+1;
            que[tail][1] = y;
            tail++;

            if (x+1 == N-1 && y == M-1) break;
        }
        if (y+1 < M && miro[x][y+1] == 1){
            miro[x][y+1] = miro[x][y] + 1;
            //PUSH
            que[tail][0] = x;
            que[tail][1] = y+1;
            tail++;
            
            if (x == N-1 && y+1 == M-1) break;
        }
        miro[x][y] = 0; // visited
        /*
        // Check miro
        for (i=0;i<N;i++){
            for (j=0;j<M;j++){
                printf("%d ",miro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
    }
    printf("%d\n",miro[N-1][M-1]+1);
    return 0;
}

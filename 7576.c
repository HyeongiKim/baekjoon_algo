#include<stdio.h>

int main(void)
{
    int i, j, M, N, day, head, tail, pos_x, pos_y, flag;
    int box[1000][1000];

    head = 0;
    tail = 0;
    scanf("%d %d",&M, &N);
    int que[M*N+1][2]; //save position of 1
    
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            scanf("%d", &box[i][j]);
            if (box[i][j]==1){
                que[tail][0] = i;
                que[tail][1] = j;
                tail++;
            }
        }
    }
    while (head < tail && tail< M*N +1){
        //POP
        pos_x = que[head][0];
        pos_y = que[head][1];
        head++;
        //Check tomato
        if (pos_x - 1 >=0 && box[pos_x - 1][pos_y] == 0){ // 계속 넣네 
            box[pos_x - 1][pos_y] = box[pos_x][pos_y] + 1;

            //save position
            que[tail][0] = pos_x - 1;
            que[tail][1] = pos_y;
            tail++;
        }
        if (pos_y - 1 >=0 && box[pos_x][pos_y - 1] == 0){
            box[pos_x][pos_y-1] = box[pos_x][pos_y] + 1;

            //save position
            que[tail][0] = pos_x;
            que[tail][1] = pos_y - 1;
            tail++;
        }
        if (pos_x + 1 < N && box[pos_x + 1][pos_y] == 0){
            box[pos_x+1][pos_y] = box[pos_x][pos_y] + 1;

            //save position
            que[tail][0] = pos_x + 1;
            que[tail][1] = pos_y;
            tail++;
        }
        if (pos_y + 1 < M && box[pos_x][pos_y+1] == 0){
            box[pos_x][pos_y+1] = box[pos_x][pos_y] + 1;

            //save position
            que[tail][0] = pos_x;
            que[tail][1] = pos_y + 1;
            tail++;
        }
    }
    day = 1;
    flag = 0;
    for (i=0;i<N;i++){
        for (j=0;j<M;j++){
            if (day < box[i][j]){
                day = box[i][j];
            }
            if (box[i][j] == 0){
                flag = 1;
            }
        }
    }
    if (flag == 1){
        printf("-1\n");
    }
    else {
        printf("%d\n",day-1);
    }
    return 0;
}

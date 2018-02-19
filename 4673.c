#include <stdio.h>

int d(int num)
{
    int i, self_num;
    
    self_num = num;

    for (i=1000;i>=1;i=i/10)
    {
        self_num += num/i;
        num = num%i;
    }
    return self_num;
}

int main()
{
    //printf("d 33: %d\n",d(33));
    //printf("d 39: %d\n",d(39));
    //printf("d 51: %d\n",d(51));
    int self_num_list[10000] = {0};
    int i, self_num;

    for (i=0;i<10000;i++)
    {
        self_num = d(i);
        if (self_num <=10000)
        {
            self_num_list[d(i) - 1] = 1; //exist self num generator
        }
    }
    
    for (i=0;i<10000;i++)
    {
        if (self_num_list[i] == 0)
        {
            printf("%d\n",i+1);
        }
    }
    return 0;
}

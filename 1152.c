#include <stdio.h>
#include <string.h>

int main()
{
    char sen[1000004];
    int count = 0;
    char *ptr;

    fgets(sen,sizeof(sen),stdin);
    if (sen[strlen(sen)-2] == ' '){ count--;}
    ptr = strtok(sen," ");
    while (ptr != NULL)
    {
        if (strcmp(ptr," ")){count++;}
        ptr = strtok(NULL, " ");
    }

    printf("%d\n",count);
}

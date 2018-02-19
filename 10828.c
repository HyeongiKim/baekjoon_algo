#include <stdio.h>
#include <string.h>

#define MAXSIZE 10001

typedef struct _stack{
    int arr[MAXSIZE];
    int TOP;
}Stack;

void Init(Stack * sp){
    sp->TOP = -1;
}

int Empty(Stack * sp){
    if (sp->TOP == -1) 
        return 1;
    else
        return 0;
}

int Size(Stack * sp){
    return sp->TOP + 1;
}

void Push(Stack * sp, int x){
    if (sp->TOP <= MAXSIZE-1){
        sp->TOP++;
        sp->arr[sp->TOP] = x;
    }
}

int Pop(Stack * sp){
    if (sp->TOP == -1) return -1;

    sp->TOP--;
    return sp->arr[(sp->TOP)+1];
}

int Top(Stack * sp){
    if (sp->TOP == -1) return -1;
    
    return sp->arr[sp->TOP];
}
int main()
{
    Stack stack;
    int i, n, num;
    char str[6];

    scanf("%d", &n);
    Init(&stack);

    for (i=0;i<n;i++){
        scanf("%s", str);

        if (!strcmp(str,"push")){
            scanf("%d",&num);
            Push(&stack,num);
        }
        else if (!strcmp(str,"pop")){
            printf("%d\n",Pop(&stack));
        }
        else if (!strcmp(str,"size")){
            printf("%d\n",Size(&stack));
        }
        else if (!strcmp(str,"empty")){
            printf("%d\n",Empty(&stack));
        }
        else if (!strcmp(str,"top")){
            printf("%d\n",Top(&stack));
        }
    }

    return 0;
}

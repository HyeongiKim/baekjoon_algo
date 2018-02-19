#include <stdio.h>

int main()
{
    char a[100], b[100], c[100];
    
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
    fgets(c, sizeof(c), stdin);
    
    printf("%s%s%s",a,b,c);
    return 0;
}


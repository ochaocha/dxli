#include <stdio.h>
int main(void)
{
    int i;
    for (i = 0; i < 10; i++);
    {
        printf("%d", i);

    }
    printf("ループ終了後のi:%d\n",i);
    return 0;
}
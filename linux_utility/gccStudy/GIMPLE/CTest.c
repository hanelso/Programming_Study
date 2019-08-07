// GIMPLE을 확인하기 위한 예제 파일입니다.
// gcc -o CTest CTest.c -fdump-tree-all 를 이용하여 컴파일하면 GIMPLE 소스 파일이 생성된다.

#include<stdio.h>

int main()
{
    int i, j, k;

    j=0;
    k=0;

    for( i=0; i<10; i++)
    {
        if ((i%2) != 0){
            j += 1;
        }else{
            k += 1;
        }
        printf("j = %d, k = %d\n", j, k);
    }

    return 0;
}

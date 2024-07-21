#include <stdio.h>

void setter(int ***p, int k)
{
    ***p = k;
}

void swap(int ***A2, int ***B2)
{
    int **temp;
    temp = *A2;
    *A2 = *B2;
    *B2 = temp;
}

int main()
{
    int i = 12;
    int *A = &i;
    int **A2 = &A;
    int ***P = &A2;
    int j = 5;
    int *B = &j;
    int **B2 = &B;

    printf("i\t: %d\n", i);
    setter(P, 2);
    printf("i\t: %d\n", i);
    printf("\n");

    swap(&A2, &B2);
    setter(P, 8);

    printf("i\t: %d\n", i);
    printf("A\t: %d\n", *A);
    printf("B2\t: %d\n", **B2);
    printf("j\t: %d\n", j);
    printf("B\t: %d\n", *B);
    printf("A2\t: %d\n", **A2);
    printf("P\t: %d\n", ***P);
    printf("\n");
}
#include<stdio.h>
#include<conio.h>
int p[100], pid[100], dir[100];
int n, count = 0;
void print()
{
    int i;
    count = count + 1;
    printf("\n%d -> ", count);
    for(i = 1; i <= n; i++)
    {
        printf("%d ", p[i]);
    }
}
void trans(int x, int y)
{
    int t;
    t = p[x];
    p[x] = p[y];
    p[y] = t;
}
void move(int z, int d)
{
    int t;
    t = p[z];
    p[z] = p[z + d];
    p[z + d] = t;
    t = dir[z];
    dir[z] = dir[z + d];
    dir[z + d] = t;
    t = pid[z];
    pid[z] = pid[z + d];
    pid[z + d] = t;
}
void Perm(int m)
{
    int i;
    if(m > n)
    {
        print();
    }
    else
    {
        Perm(m + 1);
        for(i = 1; i <= m - 1; i++)
        {
            move(m - i, dir[m]);
            Perm(m + 1);
        }
        dir[m] = -dir[m];
    }
}
void main()
{
    int i;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        p[i] = i;
        pid[i] = i;
        dir[i] = -1;
    }
    printf("\nPermutations are:\n");
    Perm(1);
    getch();
}



Enter the value of n : 3

Permutations are:

1 -> 1 2 3
2 -> 2 1 3
3 -> 0 1 3
4 -> 2 1 3
5 -> 2 3 1
6 -> 0 3 1


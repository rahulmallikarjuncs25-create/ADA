#include <stdio.h>
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int wt[n+1], val[n+1];
    printf("Enter weights of items:\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter profits of items:\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int v[n+1][W+1];
    for(int w = 0; w <= W; w++)
    {
        v[0][w] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        v[i][0] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= W; w++){
            if(wt[i] > w){
                v[i][w] = v[i-1][w];
            }
            else{
                v[i][w] = max(v[i-1][w],val[i] + v[i-1][w - wt[i]]);
            }
        }
    }
    printf("\nDP Table:\n");
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            printf("%4d", v[i][w]);
        }
        printf("\n");
    }
    printf("\nMaximum Profit = %d\n", v[n][W]);
    return 0;
}


Enter number of items: 4
Enter weights of items:
2 1 3 2
Enter profits of items:
12 10 20 15
Enter knapsack capacity: 5

DP Table:
   0   0   0   0   0   0
   0   0  12  12  12  12
   0  10  12  22  22  22
   0  10  12  22  30  32
   0  10  15  25  30  37

Maximum Profit = 37

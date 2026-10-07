#include <stdio.h>

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n, capacity;
    float totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &item[i].weight, &item[i].profit);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    // Select items
    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity -= item[i].weight;
            totalProfit += item[i].profit;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}

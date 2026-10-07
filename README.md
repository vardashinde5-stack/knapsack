# Experiment No. 3

## Title

**Fractional Knapsack Problem Using Greedy Method**

## Aim

To implement the Fractional Knapsack Problem using the Greedy Method and analyze its time and space complexity.

## Program

```c
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
```

## Output

The terminal output of the Fractional Knapsack program is shown below:

<img src="https://github.com/vardashinde5-stack/knapsack/blob/main/VS%20Code%20Terminal%20Knapsack%20Output.png" alt="Knapsack Terminal Output">

## Algorithm

1. Read the number of items.
2. Read the weight and profit of each item.
3. Calculate the profit-to-weight ratio for every item.
4. Sort the items in decreasing order of their profit-to-weight ratio.
5. Select the items with the highest ratio first.
6. If the complete item fits into the knapsack, add its complete profit.
7. If the complete item does not fit, take the required fraction of the item.
8. Continue until the knapsack capacity becomes full.
9. Display the maximum profit.

## Time Complexity

| Operation                       | Time Complexity |
| ------------------------------- | --------------- |
| Calculating Profit/Weight Ratio | **O(n)**        |
| Sorting Items                   | **O(n²)**       |
| Selecting Items                 | **O(n)**        |
| Overall Time Complexity         | **O(n²)**       |

### Explanation

The program first calculates the profit-to-weight ratio for each item in **O(n)** time.

The items are then sorted using nested loops, which takes **O(n²)** time.

Finally, the items are selected according to their ratios in **O(n)** time.

Therefore, the overall time complexity of the given implementation is:

**O(n²)**

## Space Complexity

The program stores `n` items in an array of structures.

Therefore:

**Space Complexity = O(n)**

The additional space used apart from the input array is constant.

## Applications

1. Used in resource allocation problems.
2. Used in cargo loading and transportation.
3. Used in investment and budget allocation.
4. Useful in selecting items with maximum profit under limited capacity.
5. Used in optimization problems.
6. Demonstrates the application of the Greedy Method.

## Advantages

* Simple and easy to implement.
* Provides an optimal solution for the Fractional Knapsack Problem.
* Allows fractions of items to be selected.
* Greedy selection makes the solution efficient.

## Limitations

* The Greedy Method does not always give an optimal solution for the 0/1 Knapsack Problem.
* The given implementation uses **O(n²)** time because of the sorting technique.
* Items must be divisible for the Fractional Knapsack approach.

## Conclusion

The Fractional Knapsack Problem is efficiently solved using the **Greedy Method**. The items are selected according to their decreasing profit-to-weight ratio. If an item cannot be completely included, a fraction of it is selected to utilize the remaining capacity.

For the given implementation, the overall time complexity is **O(n²)** due to the sorting process, and the space complexity is **O(n)** for storing the items.

## GitHub Repository

[Knapsack - GitHub](https://github.com/vardashinde5-stack/knapsack)

## Program File

[knapsack.c](https://github.com/vardashinde5-stack/knapsack/blob/main/knapsack.c)

## Output Image

[View Knapsack Terminal Output](https://github.com/vardashinde5-stack/knapsack/blob/main/VS%20Code%20Terminal%20Knapsack%20Output.png)

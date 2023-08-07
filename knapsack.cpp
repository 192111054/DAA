#include <stdio.h>
#include <stdlib.h>
struct Item {
    int weight;
    int value;
};
int compare(const void* a, const void* b) {
    struct Item* itemA = (struct Item*)a;
    struct Item* itemB = (struct Item*)b;
    double valuePerUnitWeightA = (double)itemA->value / itemA->weight;
    double valuePerUnitWeightB = (double)itemB->value / itemB->weight;
    if (valuePerUnitWeightA < valuePerUnitWeightB)
        return 1;
    else if (valuePerUnitWeightA > valuePerUnitWeightB)
        return -1;
    else
        return 0;
}
double fractionalKnapsack(int capacity, struct Item items[], int n) {   
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main() {
    int capacity = 50;
    struct Item items[] = { {10, 60}, {20, 100}, {30, 120} };
    int n = sizeof(items) / sizeof(items[0]);
    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);
    return 0;
}

#include <stdio.h>
#define MAX_CONTAINERS 100
#define MAX_ITEMS 100
void containerLoading(int containers[], int numContainers, int items[], int numItems) {
    int capacity[MAX_CONTAINERS];
    for (int i = 0; i < numContainers; i++) {
        capacity[i] = containers[i];
    }
    for (int i = 0; i < numItems; i++) {
        int item = items[i];
        int j;
        for (j = 0; j < numContainers; j++) {
            if (capacity[j] >= item) {
                printf("Item %d fits in Container %d\n", item, j + 1);
                capacity[j] -= item;
                break;
            }
        }
        if (j == numContainers) {
            printf("Item %d cannot be fit into any container. It exceeds the capacity.\n", item);
        }
    }
}
int main() {
    int containers[MAX_CONTAINERS];
    int numContainers;
    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);
    printf("Enter the capacities of %d containers:\n", numContainers);
    for (int i = 0; i < numContainers; i++) {
        scanf("%d", &containers[i]);
    }
    int items[MAX_ITEMS];
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the sizes of %d items:\n", numItems);
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i]);
    }
    printf("\nContainer Loading Result:\n");
    containerLoading(containers, numContainers, items, numItems);
    return 0;
}

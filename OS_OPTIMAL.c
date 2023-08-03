#include <stdio.h>
#include <stdbool.h>
#define MAX_PAGES 100
int predict(int pages[], int currentSet[], int n, int index)
{
    int val = -1;
    int farthestIndex = index - 1;

    for (int i = 0; i < n; i++)
    {
        int temp = currentSet[i];
        for (int j = index; j < n; j++)
        {
            if (pages[j] == temp)
            {
                if (j > farthestIndex)
                {
                    farthestIndex = j;
                    val = temp;
                }
                break;
            }
        }
        if (i == n - 1)
            return val;
    }
    return val;
}
void OptimalImplementation(int pages[], int n, int capacity)
{
    int pageFaults = 0;
    int currentSet[capacity];
    int currentSize = 0;

    for (int i = 0; i < n; i++)
    {
        bool pageFound = false;
        for (int j = 0; j < currentSize; j++)
        {
            if (currentSet[j] == pages[i])
            {
                pageFound = true;
                break;
            }
        }

        if (!pageFound)
        {
            if (currentSize < capacity)
            {
                currentSet[currentSize] = pages[i];
                currentSize++;
            }
            else
            {
                int predictedElement = predict(pages, currentSet, n, i + 1);
                for (int j = 0; j < currentSize; j++)
                {
                    if (currentSet[j] == predictedElement)
                    {
                        currentSet[j] = pages[i];
                        break;
                    }
                }
            }
            pageFaults++;
        }
    }
    printf("%d", pageFaults);
    // int pageHits = n - pageFaults;
    // printf("Page Hits: %d\n", pageHits);
    // printf("Hit Ratio: %d/%d = %.2lf\n", pageHits, n, (double)pageHits / n);
}
int main()
{
    int n, pages[MAX_PAGES];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    int x = 0;
    scanf("%d", &x);
    int capacity[x];
    for(int i = 0; i < x; i++)
    {
        scanf("%d", &capacity[i]);
    }
    printf("The number of page faults: [");
    for (int i = 0; i < x; i++){
        OptimalImplementation(pages, n, capacity[i]);
        if (i != x - 1)
            printf(" , ");
    }
    printf("]\n");

    return 0;
}
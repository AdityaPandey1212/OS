#include <stdio.h>
// TEST CASE 2 FAILS: INCORRECT INPUT FORMAT LEADING TO SEGMENTATION FAULT
int aditya21bci0280_LRUFUNCTION(int time[], int n)
{
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}
int aditya21BCI0280_solve(int pages[], int no_of_frames, int no_of_pages)
{
    int frames[10], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            pos = aditya21bci0280_LRUFUNCTION(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
    }
    return faults;
}
int main()
{
    int N;
    scanf("%d", &N);
    int pages[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &pages[i]);
    }
    int F;
    scanf("%d", &F);
    int arr[F];
    for (int i = 0; i < F; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The number of page faults: ");
    printf("[");
    for (int i = 0; i < F; i++)
    {
        printf("%d", aditya21BCI0280_solve(pages, arr[i], N));
        if (i < F - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    return 0;
}
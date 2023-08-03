#include <stdio.h>
struct slots_given
{
    int programID;
    int ArrivalTime;
    int BurstTime;
    int waitingTime;
    int TurnAroundTime;
    int ResponseTime;
};
void SortingOnArrivalT(struct slots_given a[], int pro)
{
    int i, j;
    struct slots_given anternate;
    for (i = 0; i < pro; i++)
    {
        for (j = i + 1; j < pro; j++)
        {
            if (a[i].ArrivalTime > a[j].ArrivalTime)
            {
                // swapping
                anternate = a[i];
                a[i] = a[j];
                a[j] = anternate;
            }
        }
    }
    return;
}
int main()
{
    int i, pro, time, remain, flag = 0, ts;
    struct slots_given a[100];
    float ans1 = 0, ans2 = 0;
    scanf("%d", &pro);
    remain = pro;
    for (i = 0; i < pro; i++)
    {
        scanf("%d%d", &a[i].ArrivalTime, &a[i].BurstTime);
        a[i].programID = i;
        a[i].ResponseTime = a[i].BurstTime;
    }
    SortingOnArrivalT(a, pro);
    scanf("%d", &ts);
    printf("Gantt Chart :\n");
    for (time = 0, i = 0; remain != 0;)
    {
        if (a[i].ResponseTime <= ts && a[i].ResponseTime > 0)
        {
            time = time + a[i].ResponseTime;
            printf("| P%d (%d) ", a[i].programID, time);
            a[i].ResponseTime = 0;
            flag = 1;
        }
        else if (a[i].ResponseTime > 0)
        {
            a[i].ResponseTime = a[i].ResponseTime - ts;
            time = time + ts;
            printf("| P%d (%d) ", a[i].programID, time);
        }
        if (a[i].ResponseTime == 0 && flag == 1)
        {
            remain--;
            a[i].TurnAroundTime = time - a[i].ArrivalTime;
            a[i].waitingTime = time - a[i].ArrivalTime - a[i].BurstTime;
            ans1 = ans1 + time - a[i].ArrivalTime - a[i].BurstTime;
            ans2 = ans2 + time - a[i].ArrivalTime;
            flag = 0;
        }
        if (i == pro - 1)
            i = 0;
        else if (a[i + 1].ArrivalTime <= time)
            i++;
        else
            i = 0;
    }
    printf("|");
    printf("\n\n");
    ans1 = ans1 / pro;
    ans2 = ans2 / pro;
    printf(" Average Waiting and Turn Around Times are %.2f and %.2f milliseconds", ans1, ans2);
    return 0;
}
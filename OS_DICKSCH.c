/*
//BANKERS

#include <stdio.h>

    int findID(int *finish, int n, int id)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return -1;
    }
    else
    {
        if (0 <= id && id < n && finish[id] == 1)
        {
            return -2;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int max_matrix[n][m];
    int alloc_matrix[n][m];
    int need_matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max_matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc_matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need_matrix[i][j] = max_matrix[i][j] - alloc_matrix[i][j];
        }
    }

    int total_resources[m];
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &total_resources[j]);
    }

    int avail[m];
    for (int j = 0; j < m; j++)
    {
        avail[j] = total_resources[j];
        for (int i = 0; i < n; i++)
        {
            avail[j] -= alloc_matrix[i][j];
        }
    }

    int work[m];
    for (int j = 0; j < m; j++)
    {
        work[j] = avail[j];
    }

    int finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    printf("The system is safe.\n");
    printf("Max      Alloc     Need      Avail\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", max_matrix[i][j]);
        }
        printf("   ");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", alloc_matrix[i][j]);
        }
        printf("    ");
        for (int j = 0; j < m; j++)
        {
            printf("%d ", need_matrix[i][j]);
        }
        printf("    ");
        if (i == 0)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }

    int safe[n];
    int k = 0;
    int id = 0;

    while (1)
    {
        int pid = findID(finish, n, id);
        if (pid == -1)
        {
            break;
        }
        else if (pid == -2)
        {
            id = (id + 1) % n;
        }
        else
        {
            int flag = 0;
            for (int j = 0; j < m; j++)
            {
                if (need_matrix[id][j] > work[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    work[j] += alloc_matrix[id][j];
                }
                finish[id] = 1;
                safe[k] = id;
                k++;
            }
            id = (id + 1) % n;
        }
    }

    printf("\nSafe Sequence is: ('");
    for (int i = 0; i < k; i++)
    {
        printf("P%d", safe[i]);
        if (i != k - 1)
        {
            printf("', '");
        }
    }
    printf("')\n");

    return 0;
}

5
3
7
5
3
3
2
2
9
0
2
2
2
2
4
3
3
0
1
0
2
0
0
3
0
2
2
1
1
0
0
2
10
5
7
//----------------------------------------------------------------
// fcfs

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total_head_movement = 0, initial_pos, n;
    printf("\n Enter the no. of cylinders in Request queue:\n");
    scanf("%d", &n);
    int request_queue[n];
    printf("\n Enter the cylinders no. in Request queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &request_queue[i]);
    printf("\n Enter the initial Position of RW head: ");
    scanf("%d", &initial_pos);

    // Create an array to store the R/W head movement sequence
    int seek_sequence[n];

    // Iterate through the request queue to calculate the total head movement and store the sequence
    for (int i = 0; i < n; i++)
    {
        int movement = abs(initial_pos - request_queue[i]);
        printf("Moving to cylinder %d (Head Movement: %d)\n", request_queue[i], movement);
        total_head_movement += movement;
        seek_sequence[i] = request_queue[i]; // Store the current cylinder in the sequence
        initial_pos = request_queue[i];      // Update the R/W head position
    }

    printf("\n*********** OUTPUT **********\n");
    printf("R/W Head Movement Sequence:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", seek_sequence[i]);

    printf("\nTotal No. of Head Movements = %d\n", total_head_movement);
    printf("Average head movements = %.2f\n", (float)total_head_movement / n);

    return 0;
}


-------------------------------------------------------------------------------------
// SCAN
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int comparator(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;   // No sorting
    else if (x >= y) // = is for stable sort
        return 1;    // Sort
}

int min_element(int request_queue[], int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (request_queue[i] < min)
            min = request_queue[i];
    }
    return min;
}

int max_element(int request_queue[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (request_queue[i] > max)
            max = request_queue[i];
    }
    return max;
}

int applySCANAlgo(int total_cylinders, int request_queue[], int initial_pos, int seek_sequence[], int direction, int *sequence_size, int n)
{
    int total_head_movement = 0, j = 0, k = 0;
    int left[n + 1], right[n + 1]; // in worst case(corner cases), size will be n+1

    // appending end values
    // which has to be visited
    // before reversing the direction
    if (direction == 0)
    {
        if (initial_pos > min_element(request_queue, n))
            right[j++] = total_cylinders - 1;
        right[j++] = initial_pos;
    }
    else if (direction == 1)
    {
        if (initial_pos < max_element(request_queue, n))
            left[k++] = 0; // here  0 is initial cylinder of HDD
        left[k++] = initial_pos;
    }

    for (int i = 0; i < n; i++)
    {
        if (request_queue[i] < initial_pos)
            left[k++] = request_queue[i];
        if (request_queue[i] > initial_pos)
            right[j++] = request_queue[i];
    }

    // sorting left and right arrays
    qsort((void *)left, k, sizeof(int), comparator);
    qsort((void *)right, j, sizeof(int), comparator);

    // run the while loop two times one by one scanning right and left of the head
    int completed = 2;
    while (completed--)
    {
        if (direction == 0)
        {
            for (int i = 0; i < j; i++)
            {
                // calculate absolute distance
                int movement = abs(initial_pos - right[i]);
                total_head_movement += movement;
                initial_pos = right[i];
                // appending current track to seek sequence
                seek_sequence[*sequence_size] = right[i];
                (*sequence_size)++;
                printf("Moving to cylinder %d (Head Movement: %d)\n", right[i], movement);
            }
            direction = 1;
        }
        else if (direction == 1)
        {
            for (int i = k - 1; i >= 0; i--)
            {
                // calculate absolute distance
                int movement = abs(initial_pos - left[i]);
                total_head_movement += movement;
                initial_pos = left[i];
                seek_sequence[*sequence_size] = left[i];
                (*sequence_size)++;
                printf("Moving to cylinder %d (Head Movement: %d)\n", left[i], movement);
            }
            direction = 0;
        }
    } 
    return total_head_movement;
}

int main()
{
    int total_cylinders, total_head_movement = 0, initial_pos, n, direction, pos;

    printf("\nEnter the total no. of cylinders in HDD:\n");
    scanf("%d", &total_cylinders);

    printf("\nEnter the no. of cylinders to enter in Request queue:\n");
    scanf("%d", &n);

    int request_queue[n];
    int seek_sequence[n + 10]; // i.e take somewhat bigger size than n
    int sequence_size = 0;

    printf("\nEnter the cylinders no. in Request queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &request_queue[i]);
    printf("\nEnter the initial Position of RW head: ");
    scanf("%d", &initial_pos);
    printf("\nEnter the direction in which Read Write head is moving:\n ");
    printf("\nEnter 0 if moving to higher cylinder else Enter 1: ");
    scanf("%d", &direction);

    if (initial_pos < 0 || initial_pos > total_cylinders - 1)
    {
        printf("Wrong Initial Position Entered !!");
        exit(0);
    }

    printf("\n*********** OUTPUT **********\n");
    total_head_movement = applySCANAlgo(total_cylinders, request_queue, initial_pos, seek_sequence, direction, &sequence_size, n);

    printf("\nSeek Sequence: ");
    for (int i = 0; i < sequence_size; i++)
        printf("%d ", seek_sequence[i]);

    printf("\nTotal No. of Head Movements = %d\n", total_head_movement);
    printf("Average head movements = %.2f\n\n", (float)total_head_movement / n);

    return 0;
}
--------------------------------------------------

// DISK SCHEDULING LOOK ALGORITHM

#include <stdio.h>
#include <stdlib.h>

int comparator(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;   // No sorting
    else if (x >= y) // = is for stable sort
        return 1;    // Sort
}

int applySCANAlgo(int total_cylinders, int request_queue[], int initial_pos, int seek_sequence[], int direction, int *sequence_size, int n)
{
    int total_head_movement = 0, j = 0, k = 0;
    int left[n], right[n];

    if (direction == 0)
        right[j++] = initial_pos;
    else if (direction == 1)
        left[k++] = initial_pos;

    for (int i = 0; i < n; i++)
    {
        if (request_queue[i] < initial_pos)
            left[k++] = request_queue[i];
        if (request_queue[i] > initial_pos)
            right[j++] = request_queue[i];
    }

    // sorting left and right arrays
    qsort((void *)left, k, sizeof(int), comparator);
    qsort((void *)right, j, sizeof(int), comparator);

    // run the while loop two times one by one scanning right and left of the head
    int completed = 2;
    while (completed--)
    {
        if (direction == 0)
        {
            for (int i = 0; i < j; i++)
            {
                // calculate absolute distance
                int movement = abs(initial_pos - right[i]);
                total_head_movement += movement;
                initial_pos = right[i];
                // appending current track to seek sequence
                seek_sequence[*sequence_size] = right[i];
                (*sequence_size)++;
                printf("Moving to cylinder %d (Head Movement: %d)\n", right[i], movement);
            }
            direction = 1;
        }

        else if (direction == 1)
        {
            for (int i = k - 1; i >= 0; i--)
            {
                // calculate absolute distance
                int movement = abs(initial_pos - left[i]);
                total_head_movement += movement;
                initial_pos = left[i];
                // appending current track to seek sequence
                seek_sequence[*sequence_size] = left[i];
                (*sequence_size)++;
                printf("Moving to cylinder %d (Head Movement: %d)\n", left[i], movement);
            }
            direction = 0;
        }
    }

    return total_head_movement;
}

int main()
{
    int total_cylinders, total_head_movement = 0, initial_pos, n, direction, pos;

    printf("\nEnter the total no. of cylinders in HDD:\n");
    scanf("%d", &total_cylinders);

    printf("\nEnter the no. of cylinders to enter in Request queue:\n");
    scanf("%d", &n);

    int request_queue[n];
    int seek_sequence[n + 10]; // i.e take somewhat bigger size than n
    int sequence_size = 0;

    printf("\nEnter the cylinders no. in Request queue :\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &request_queue[i]);
    printf("\nEnter the initial Position of RW head: ");
    scanf("%d", &initial_pos);
    printf("\nEnter the direction in which Read Write head is moving:\n ");
    printf("\nEnter 0 if moving to higher cylinder else Enter 1: ");
    scanf("%d", &direction);

    if (initial_pos < 0 || initial_pos > total_cylinders - 1)
    {
        printf("Wrong Initial Position Entered !!");
        exit(0);
    }

    printf("\n*********** OUTPUT **********\n");
    total_head_movement = applySCANAlgo(total_cylinders, request_queue, initial_pos, seek_sequence, direction, &sequence_size, n);

    printf("\nSeek Sequence: ");
    for (int i = 0; i < sequence_size; i++)
        printf("%d ", seek_sequence[i]);

    printf("\nTotal No. of Head Movements = %d\n", total_head_movement);
    printf("\nAverage head movements = %.2f\n\n", (float)total_head_movement / n);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int abs(int a)
{
    return a >= 0 ? a : -a;
}

void fcfs_disk_schedule(int tracks[], int n, int head)
{
    int total_distance = 0;
    int direction_change = 0;
    int seek_time = 0;
    int current_track = head;
    int previous_track = head;
    bool direction = false; // left = false, right = true
    if (head != tracks[0])
    {
        direction_change++;
        if (tracks[0] - head > 0)
            direction = true;
        else    
            direction = false;
    }
    printf("Track Sequence: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tracks[i]);
        total_distance += abs(current_track - tracks[i]);
        
        current_track = tracks[i];
        if (previous_track - current_track < 0 && direction || previous_track - current_track > 0 && !direction)
            continue;
        else    
        {
            direction_change++;
            if (direction)
                direction = false;
            else
                direction = true;
        }
    }
    printf("\n");

    seek_time = total_distance;
    printf("Total Seek Distance: %d\n", total_distance);

    printf("Number of Direction Change: %d\n", direction_change);
}

int main()
{
    int n, head, tracks[MAX];
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the track sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the head position: ");
    scanf("%d", &head);
    fcfs_disk_schedule(tracks, n, head);
    return 0;
}

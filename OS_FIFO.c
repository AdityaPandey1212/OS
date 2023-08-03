//7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
#include<stdio.h>

void Function_21BCI0280(int string[],int n,int size)
{
    int frames[n];
    for (int i=0;i<n;i++)
        frames[i]=-1;
    int index=-1;

    int page_miss=0;
    int page_hits=0;

    for (int i=0;i<size;i++)
    {
        int symbol=string[i];
        int flag=0;

        for(int j=0;j<n;j++)
        {
            if (symbol==frames[j])
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            for (int j=0;j<n;j++)
            page_hits+=1;
        }
        else
        {
            index=(index+1)%n;
            frames[index]=symbol;
            page_miss+=1;
        }
    }
    printf("%d",page_miss);
}
int main(void)
{
    int frame_no;
    scanf("%d",&frame_no);
    int inputStream[frame_no];
    for(int i=0;i<frame_no;i++){
        scanf("%d",&inputStream[i]);
    }
    int no_frames;
    scanf("%d",&no_frames);
    int arr[no_frames];
    for(int i=0;i<no_frames;i++){
        scanf("%d",&arr[i]);
    }
    printf("The number of page faults: ");
    printf("[");
    for(int i=0;i<no_frames;i++){
    Function_21BCI0280(inputStream,arr[i],frame_no);
    if(i<no_frames-1){
        printf(", ");
    }
    }
    printf("]");
    return 0;
}
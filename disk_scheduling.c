#include <stdio.h>
#include <stdlib.h>

int abs_val(int x){
    if(x < 0)
        return -x;
    return x;
}

void sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* FCFS */
void FCFS(int req[], int n, int head){
    int seek = 0;
    printf("\nFCFS Order: %d", head);

    for(int i=0;i<n;i++){
        seek += abs_val(req[i] - head);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (FCFS) = %d\n", seek);
}

/* SSTF */
void SSTF(int req[], int n, int head){
    int visited[100] = {0};
    int seek = 0;

    printf("\nSSTF Order: %d", head);

    for(int i=0;i<n;i++){
        int min = 9999, index = -1;

        for(int j=0;j<n;j++){
            if(!visited[j]){
                int dist = abs_val(req[j] - head);
                if(dist < min){
                    min = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        seek += min;
        head = req[index];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (SSTF) = %d\n", seek);
}

/* SCAN */
void SCAN(int req[], int n, int head, int disk_size){
    int arr[100], seek = 0;

    for(int i=0;i<n;i++)
        arr[i] = req[i];

    arr[n++] = disk_size - 1;

    sort(arr, n);

    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] >= head){
            pos = i;
            break;
        }
    }

    printf("\nSCAN Order: %d", head);

    for(int i=pos;i<n;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    for(int i=pos-1;i>=0;i--){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (SCAN) = %d\n", seek);
}

/* C-SCAN */
void CSCAN(int req[], int n, int head, int disk_size){
    int arr[100], seek = 0;

    for(int i=0;i<n;i++)
        arr[i] = req[i];

    arr[n++] = 0;
    arr[n++] = disk_size - 1;

    sort(arr, n);

    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] >= head){
            pos = i;
            break;
        }
    }

    printf("\nC-SCAN Order: %d", head);

    for(int i=pos;i<n;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    head = 0;
    printf(" -> %d", head);

    for(int i=0;i<pos;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (C-SCAN) = %d\n", seek);
}

/* LOOK */
void LOOK(int req[], int n, int head){
    int arr[100], seek = 0;

    for(int i=0;i<n;i++)
        arr[i] = req[i];

    sort(arr, n);

    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] >= head){
            pos = i;
            break;
        }
    }

    printf("\nLOOK Order: %d", head);

    for(int i=pos;i<n;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    for(int i=pos-1;i>=0;i--){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (LOOK) = %d\n", seek);
}

/* C-LOOK */
void CLOOK(int req[], int n, int head){
    int arr[100], seek = 0;

    for(int i=0;i<n;i++)
        arr[i] = req[i];

    sort(arr, n);

    int pos;
    for(int i=0;i<n;i++){
        if(arr[i] >= head){
            pos = i;
            break;
        }
    }

    printf("\nC-LOOK Order: %d", head);

    for(int i=pos;i<n;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    for(int i=0;i<pos;i++){
        seek += abs_val(arr[i] - head);
        head = arr[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement (C-LOOK) = %d\n", seek);
}

int main(){

    int req[100], n, head, disk_size;

    printf("Enter number of disk requests: ");
    scanf("%d",&n);

    printf("Enter disk request sequence:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    printf("Enter disk size: ");
    scanf("%d",&disk_size);

    FCFS(req,n,head);
    SSTF(req,n,head);
    SCAN(req,n,head,disk_size);
    CSCAN(req,n,head,disk_size);
    LOOK(req,n,head);
    CLOOK(req,n,head);

    return 0;
}
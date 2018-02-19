#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int arr[], int left, int right)
{
    int pivot = arr[(left + right)/2];
    int i = left;
    int j = right;

    while (i <= j){

        while (arr[i] < pivot){i++;}

        while (arr[j] > pivot){j--;}

        if (i <= j){
            //tmp = arr[i];
            //arr[i] = arr[j];
            //arr[j] = tmp;
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void merge(int arr[], int start, int mid, int end)
{
    int length = end - start + 1;
    int temp[length];

    int left = start;
    int right = mid+1;
    int i;

    for (i=0; i<length; i++){
        if (left <= mid && right <= end){
            if (arr[left] < arr[right]){
                temp[i] = arr[left];
                left++;
            }
            else {
                temp[i] = arr[right];
                right++;
            }
        }

        else if (left > mid && right <= end){
            temp[i] = arr[right];
            right++;
        }
        else if (left <= mid && right > end){
            temp[i] = arr[left];
            left++;
        }
    }
    for (i=start; i<=end; i++){
        arr[i] = temp[i-start];
    }
}

void mergesort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    
    int mid = (start + end) / 2;

    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);

    merge(arr,start,mid,end);

}
int main(void)
{
    int i, n;
    scanf("%d",&n);

    int arr[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //quicksort(arr,0,n-1);
    mergesort(arr,0,n-1);
    for (i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}

#include <stdio.h>

void insertInOrder(int element, int *a, int first, int last){
    
    if(element >= a[last])
        a[last + 1] = element;
    else if(first < last){
        a[last + 1] = a[last];
        insertInOrder(element, a, first, last - 1);
    }else{
        a[last+1] = a[last];
        a[last] = element;
    }
}

void insertionSort(int *arr, int first, int last){
    if(first < last){
        insertionSort(arr, first, last - 1);
        insertInOrder(arr[last], arr, first, last - 1);
    }
}

int main(){
    int a[] = {5, 3, 2, 4, 6, 9, 1};
    int i;
    
    insertionSort(a, 0, 6);
    
    for(i = 0; i <= 6; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
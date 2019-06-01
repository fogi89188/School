#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10
 
void swap(int *x,int *y);
void selection_sort(int* a, const int n);
void display(int a[],int size);
 
void main()
{
 
    int a[SIZE] = {8,5,2,3,1,6,9,4,0,7};
 
    int i;
    printf("The array before sorting:\n");
    display(a,SIZE);
 
    selection_sort(a,SIZE);
 
    printf("The array after sorting:\n");
    display(a,SIZE);
}
 
/*
    swap two integers
*/
void swap(int *x,int *y)
{
    int temp;
 
    temp = *x;
    *x = *y;
    *y = temp;
}
/*
    perform selection sort
*/
void selection_sort(int* a,const int size)
{
    int i, j, min;
 
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
    }
}
/*
    display array content
*/
void display(int a[],const int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
}

#include<stdio.h> 

int partition (int a[], int low, int high) 
{ 
    int pivot = a[low];   
    int j,i = (low + 1); 
  
    for (j=low+1;j<=high;j++) 
    { 
        if(a[j]<pivot) 
        { 
            t=a[i]; a[i]=a[j]; a[j]=t;
            i++;
        } 
    } 

    t=a[i-1]; a[i-1]=a[low]; a[low]=t;
    return (i-1); 
} 

void quickSort(int a[],int low,int high) 
{ 
    if (low < high) 
    { 
        
        int pi=partition(a,low,high); 
  
        quickSort(a,low,pi ); 
        quickSort(a,pi+1,high);
         
    } 
} 
  

int main()
{
   int a[1000],n,i,j,t;
   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    quickSort(a,0,n-1); 

}


//best case O(nlogn); worst case O(n^2)
//select a pivot. swap every element smaller than the pivot on to next spot
//swap the pivot with the last swapped element
//recursively continue this


//Loop invariant
//after every partition call array is divided into 3 regions:
//1. Pivot element is placed at its correct position.
//2. Elements less than pivot element lie on the left side of pivot element.
//3. Elements greater than pivot element lie on the right side of pivot element.
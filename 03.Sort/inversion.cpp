#include <stdio.h> 
int getInvCount(int a[], int n) 
{ 
    int inv_count = 0; 

    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (a[i] > a[j]) 
                inv_count++; 
  
    return inv_count; 
} 


int main() 
{ 
    int a[1000],n; 
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    printf(" Number of inversions are %d \n", getInvCount(arr, n)); 
    return 0; 
} 

//best case O(n^2); worst case O(n^2)
//for each element in any array, we count the number of element 
//that is bigger than the selected element to it's right
//the total number of abnormality is the number of inversion.
// 10 1 2 5 3 
// total number of inversion=5
//4 abnormality for 10 and 1 abnormality for 5
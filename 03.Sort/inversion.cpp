// #include <stdio.h> 
// int getInvCount(int a[], int n) 
// { 
//     int inv_count = 0; 

//     for (int i = 0; i < n - 1; i++) 
//         for (int j = i + 1; j < n; j++) 
//             if (a[i] > a[j]) 
//                 inv_count++; 
  
//     return inv_count; 
// } 


// int main() 
// { 
//     int a[1000],n; 
//     scanf("%d",&n);
//     for(i=0;i<n;i++) scanf("%d",&a[i]);

//     printf(" Number of inversions are %d \n", getInvCount(arr, n)); 
//     return 0; 
// } 

//best case O(n^2); worst case O(n^2)
//for each element in any array, we count the number of element 
//that is bigger than the selected element to it's right
//the total number of abnormality is the number of inversion.
// 10 1 2 5 3 
// total number of inversion=5
//4 abnormality for 10 and 1 abnormality for 5

#include<stdio.h>

int merge(int a[],int l,int m,int r) 
{ 
    int i,j,k, cnt = 0; 
    int n1=m-l+1; 
    int n2=r-m; 
  
    int L[n1], R[n2]; 
  
    for(i=0;i<n1;i++)  L[i]=a[l+i]; 
    for(j=0;j<n2;j++)  R[j]=a[m+1+j]; 
  
    i=0;j=0;k=l; 

    while(i<n1 && j<n2) 
    { 
        if (L[i]<=R[j]) 
        { 
            i++; 
        } 
        else
        { 
            j++; 
            cnt += n1 - i - 1;
        } 

        k++; 
    } 
    return cnt;
} 
  

int mergesort(int a[],int l,int r)
{
    int cnt = 0;
    if(l<r) 
    { 
        int m=l+(r-l)/2; 
  
        cnt += mergesort(a,l,m); 
        cnt += mergesort(a,m+1,r); 
  
        cnt += merge(a,l,m,r); 
    }

    return cnt;
}

int main()
{
    int a[1000],n,i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    printf("%d\n", mergesort(a,0,n-1)); 

}


//best case O(nlogn); worst case O(nlogn)
//recursively sorts the array kekk

//the merge function copies the divided arrays into left subarray and right subarray
//then compares the first element of left to first element of right 
//then copies the smaller element to the left index of main array 
//and increments the array(left or right),its copied from 
//then it copies any remaining elements on the subarray to thr main array


//Loop invariant: At the start of each iteration k of the for loop, 
//the nonempty part of 'a' contains the k − l smallest elements of L and R, in sorted order. 
//Moreover, L[i] and R[j] are the smallest elements of their arrays that have not been copied to 'a'
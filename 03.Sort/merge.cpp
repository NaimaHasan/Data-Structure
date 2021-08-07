#include<stdio.h>

void merge(int a[],int l,int m,int r) 
{ 
    int i,j,k; 
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
            a[k]=L[i]; 
            i++; 
        } 
        else
        { 
            a[k]=R[j]; 
            j++; 
        } 

        k++; 
    } 
    
    while(i<n1) 
    { 
        a[k]=L[i]; 
        i++; 
        k++; 
    } 
   
    while(j<n2) 
    { 
        a[k]=R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergesort(int a[],int l,int r)
{
	if(l<r) 
    { 
        int m=l+(r-l)/2; 
  
        mergesort(a,l,m); 
        mergesort(a,m+1,r); 
  
        merge(a,l,m,r); 
    }
}

int main()
{
	int a[1000],n,i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    mergesort(a,0,n-1); 

    for(i=0;i<n;i++) printf("%d\n", a[i]);
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

// Stable: Yes

// Akash Deep, Assignment 2, Prob 3. LIS; circular
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max_array(int a[], int n)
{
	int max=0;
	for (int i = 0; i < n; i++ )
        if (max < a[i])
            max = a[i];
      
    return max;
}
int lis(int arr[], int n )
{
    int i, j, max = 0;
    int lis[n];

    for (i = 0; i < n; i++ )
        lis[i] = 1;
//DP part
      for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
                
	return max_array(lis, n);
     
}
void leftRotatebyOne(int arr[], int n)
{
  int i, temp;
  temp = arr[0];
  for (i = 0; i < n-1; i++)
     arr[i] = arr[i+1];
  arr[i] = temp;
}
int main()
{
    int t,t_i,N;
    cout<<"Enter no of cases" ;
    cin>>t;
    for (t_i=0;t_i<t;t_i++)
    	{
    		cout<<"Enter number of guests";
    		cin>>N;
    		int arr[N];
    		for (int i = 0; i< N; i++)
    		{
    			cin>>arr[i];
    		}
    		int max_ele[N];
    		max_ele[0]=lis(arr, N );
    		for (int i = 1; i< N; i++)
    		{
    			leftRotatebyOne(arr, N);
    			max_ele[i]=lis(arr, N );
    		}
    		cout<<max_array(max_ele, N);
    	}

}

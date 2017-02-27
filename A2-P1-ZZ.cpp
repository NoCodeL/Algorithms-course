// Akash Deep, Assignment 2, Prob 1. ZigZag; 
// referred : https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/exams/MIT6_006F11_final_sol.pdf
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int zigzag(int arr[], int n)
{
	int DP[n][2];
	for (int i = 0; i < n; i++)
		DP[i][0] = DP[i][1] = 1;

	int max_len = 1; 	//default
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && DP[i][0] < DP[j][1] + 1)
				DP[i][0] = DP[j][1] + 1;

			if( arr[j] > arr[i] && DP[i][1] < DP[j][0] + 1)
				DP[i][1] = DP[j][0] + 1;
		}

		if (max_len < max(DP[i][0], DP[i][1]))
			max_len = max(DP[i][0], DP[i][1]);
	}

	return max_len;
}

int main()
{
	int n;
	cout<<"Enter size of sequence";
    		cin>>n;
    		int arr[n];
    		for (int i = 0; i< n; i++)
    		{
    			cin>>arr[i];
    		}
	cout <<"Required Length: "<<zigzag(arr, n) ;
}


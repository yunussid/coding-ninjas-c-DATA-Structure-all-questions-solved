/*
Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square
matrix with all 0s.
*/
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
int findMaxSquareWithAllZeros(int **arr, int row, int col)
{
	//Write your code here
    int **dp = new int *[row];
    for(int i = 0; i < row; i++){
        dp[i] = new int[col];
    }

    for(int i = 0; i < row; i++){
        dp[i][0] = arr[i][0] == 1 ? 0 : 1;
    }

    for(int j = 1; j < col; j++){
        dp[0][j] = arr[0][j] == 1 ? 0 : 1;
    }

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(arr[i][j] == 0){
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
            else dp[i][j] = 0;
        }
    }

    int max = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(dp[i][j] > max) max = dp[i][j];
        }
    }

    return max;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];

	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}

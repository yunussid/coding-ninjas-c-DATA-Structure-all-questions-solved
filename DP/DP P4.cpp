/*
Code : Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to
represent N as sum of squares.
*/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

const int MOD=1e9+7;
//Recursive approach
int minCount1(int n){
    if(sqrt(n)-floor(sqrt(n))==0){
        return 1;
    }
    if(n<=3){
        return n;
    }
    int res=n;
    for(int i=2;i<=n;i++){
        int temp=i*i;
        if(temp>n){
            break;
        }
        else{
            res=min(res,1+minCount1(n-temp));
        }
    }
    return res;
}
int minCount(int n){
    int *dp=new int[n];
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=4;i<=n;i++){
        int count=i;
        for(int j=1;j<=i/2;j++){
            int k=i-(j*j);
            if(k>=0){
                count=min(count,dp[k]+1);
            }
        }
        dp[i]=count;
    }
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}

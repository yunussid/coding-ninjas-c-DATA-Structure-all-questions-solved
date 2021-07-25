/*
Code : Staircase using Dp
Send Feedback
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways
in which the child can run-up to the stairs.
*/
#include <iostream>
using namespace std;

int staircase(int n){
    int *dp=new int[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}

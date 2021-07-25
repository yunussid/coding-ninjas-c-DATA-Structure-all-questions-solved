/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
*/
#include<iostream>
#include<cmath>
using namespace std;

//RECURSIVE APPROACH
int balancedBTsR(int h){
    if(h<=1){
        return 1;
    }
    int mod=(int)(pow(10,9))+7;
    int x=balancedBTsR(h-1);
    int y=balancedBTsR(h-2);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)((2*(long)(x)*y) %mod);
    int ans=(temp1+temp2)%mod;

    return ans;
}
int balancedBTs(int h){
    if(h<=1){
        return 1;
    }
    int dp[h+1];
    dp[0]=1;
    dp[1]=1;
     int mod=(int)(pow(10,9))+7;
    for(int i = 2; i <= h; i++) {
        dp[i] = ((long)dp[i - 1] * ((2 * (long)dp [i - 2])%mod + dp[i - 1])%mod) % mod;
    }
    return dp[h];

}
int main(){
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<endl;
}

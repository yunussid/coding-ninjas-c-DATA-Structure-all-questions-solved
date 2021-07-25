/*
WAYS TO MAKE COIN CHANGE
You are given an infinite supply of coins of each denominations D={D0,D1,D2,D3...Dn-1}.You need to figure out the total number of ways W,in which you can make
change for value V using coin denoination D.

Return 0 if change isn't possible
*/

#include<iostream>
using namespace std;

int num_changes2(int n,int* d,int k,int** dp){
     if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    if(dp[n][k]>=0){
        return dp[n][k];
    }
    int option1=num_changes2(n-d[0],d,k,dp[n][k]);
    int option2=num_changes2(n,d+1,k-1,dp[n][k]);
    dp[n][k]= option1+option2;
    return dp[n][k];

}

int num_change(int n,int *d,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(k==0){
        return 0;
    }
    int option1=num_change(n-d[0],d,k);
    int option2=num_change(n,d+1,k-1);
    return option1+option2;
}

int main(){

}

/*Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
*/
#include <iostream>
#include <string>
using namespace std;
#include<cstring>
#include<limits>

//Recursive Approach
int solve(string a,string b,int sia=0,int sib=0){
    if(sib==b.length()){
        return 1;
    }
    if(sia==a.length()){
        return 10001;
    }
    int option1=solve(a,b,sia+1,sib);
    int indexB=-1;
    for(int i=sib;i<b.length();i++){
        if(b[i]==a[sia]){
            indexB=i;
            break;
        }
    }
    if(indexB==-1){
        return 1;
    }
    int option2 = 1+solve(a,b,sia+1,indexB+1);
    if(option1<option2){
        return option1;
    }else{
        return option2;
    }
}
int solve(string S, string V) {
    // Write your code here
        static int INF=1000000000;
    int n = S.size(), m = V.size() ,i, j, prev;
    int dp[n+1][m+1] , next[n+1][m+1];
    for(i = 0; i < n; i++){
        prev = -1;
        for(j = 0;j < m; j++){
            if(S[i] == V[j])
                prev = j;
            next[i+1][j+1] = prev;
        }
    }
    for(i = 1; i <= n; i++)
        dp[i][0] = 1;
    for(i = 0; i <= m; i++){
        dp[0][i] = INF;
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(next[i][j] == -1)
                dp[i][j] = 1;
            else{
                dp[i][j] = min(dp[i-1][j],1 + dp[i-1][next[i][j]]);
            }
        }
    }
    return dp[n][m];
}
int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}

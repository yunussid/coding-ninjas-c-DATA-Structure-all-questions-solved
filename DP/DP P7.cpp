/*
Code : Min Cost Path
Send Feedback
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
*/
#include<iostream>
using namespace std;

//DP Approach
int minCostPathDP(int **input,int n,int m){
    int **output=new int*[m];
    for(int i=0;i<m;i++){
        output[i]=new int[n];
    }
    //Fill The Destination
    output[n-1][m-1]=input[n-1][m-1];

    //FILL LAST ROW (RIGHT TO LEFT)
    for(int j=m-2;j>=0;j--){
        output[n-1][j] =output[n-1][j+1] + input[n-1][j];
    }
    //FILL LAST COLUMNS (down to up)
    for(int k=m-2;k>=0;k++){
        output[k][m-1]=output[k+1][m-1] + input[k][m-1];
    }

    //FILL REMAINING CELLS
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j++){
            output[i][j]=min(output[i][j+1] , min(output[i+1][j+1] ,output[i+1][j])) + input[i][j];
        }
    }

    return output[0][0];
}
//MEMOIZATION
int minCostPathMemo(int **input,int n,int m,int i,int j,int **output){
    if(i==n-1&&j==m-1){
        return 0;
    }
    if(i>=n||j>=m){
        return INT_MAX;
    }
    //CHECH IF ANS ALREADY EXISTS
    if(output[i][j]!=-1){
        return output[i][j];
    }

    //Recursion
    int x=minCostPathMemo(input,n,m,i,j+1,output);
    int y=minCostPathMemo(input,n,m,i+1,j+1,output);
    int z=minCostPathMemo(input,n,m,i=1,j,output);

    //SMALL CALCULATION
    int a= min(x,min(y,z))+input[i][j];

    //SAVE THE ANS FOR FUTURE USE
    output[i][j]=a;

    //
    return a;
}

int minCostPathMemo(int **input,int n,int m){
    int **output= new int*[m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[i][j]=-1;
        }
    }
    return minCostPathMemo(input, n, m, 0, 0, output);
}
//Recursive Approach
int minCostPathR(int **input,int n,int m,int i,int j){
    //Base Case
    if(i==n-1&&j==m-1){
        return input[i][j];
    }
    if(i>=n||j>=m){
        return INT_MAX;
    }
    //RECURSIVE CALLS
    int x=minCostPathR(input,n,m,i,j+1);
    int y=minCostPathR(input,n,m,i+1,j+1);
    int z=minCostPathR(input,n,m,i=1,j);

    //SMALL CALCULATION
    int ans= min(x,min(y,z))+input[i][j];
    return ans;
}

int minCostPath(int **input,int n,int m){
    minCostPathR(input,n,m,0,0);
}
int main(){
    int **arr,n,m;
    cin>>n>>m;
    arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<minCostPath(arr,n,m)<<endl;
    cout<<minCostPathMemo(arr,n,m)<<endl;
    cout<<minCostPathDP(arr,n,m)<<endl;
}

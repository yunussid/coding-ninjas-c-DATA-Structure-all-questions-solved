/*
Code : Knapsack
Send Feedback
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.'
What would be the maximum value V, that the thief can steal?
*/
#include<iostream>
#include<cstring>
using namespace std;

#include<vector>
int knapSack2(int *weight,int *value,int n,int maxWeight){
    vector<vector<int>> dp(2, vector<int>(maxWeight+1,0));

    for(int i=0;i<n;i++){
        for(int j=1;j<=maxWeight;j++){
            if(weight[i]<=j){
                dp[i%2][j]=max(value[i]+dp[(i+1)%2][j-weight[i]],dp[(i+1)%2][j]);
            }else{
                dp[i%2][j]=dp[(i+1)%2][j];
            }
        }
    }
    return dp[(n+1)%2][maxWeight];
}

int knapSack1(int *weight,int *value,int n,int maxWeight){
    int mat[2][maxWeight+1];
    memset(mat, 0,sizeof(mat));
    //iterate through all items
    int i=0;
    while(i<n){//one by one traverse each element
        int j=0;
        j<=maxWeight;
        //if i is odd that means till now we have odd
        //number of elements so we store result in 1th
        //indexed row
        if(i%2!=0){
            while(++j<=maxWeight){  //check for each value
                if (weight[i] <= j) // include element
                    mat[1][j] = max(value[i] + mat[0][j-weight[i]], mat[0][j] );
                else // exclude element
                    mat[1][j] = mat[0][j];
            }
        }
        // if i is even that mean till now we have even number // of elements so we store result in 0th indexed row
        else {
            while(++j <= maxWeight) {
                if (weight[i] <= j)
                    mat[0][j] = max(value[i] + mat[1][j-weight[i]], mat[1][j]);
                else
                    mat[0][j] = mat[1][j];
            }
        }
        i++;
    }
    // Return mat[0][W] if n is odd, else mat[1][W]
    return (n%2 != 0)? mat[0][maxWeight] : mat[1][maxWeight];
}

//Recursion
int knapSack(int *weights,int *values,int n, int maxWeight){
    if(n==0||maxWeight==0){
        return 0;
    }
    int a,b;
    if(weights[0]>maxWeight){
        return(weights+1,values+1,n-1,maxWeight);
    }
    a=knapSack(weights+1,values+1,n-1,maxWeight);
    b=knapSack(weights+1,values+1,n-1,maxWeight-weights[0])+values[0];

    return max(a,b);

}
int main(){
    int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapSack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}

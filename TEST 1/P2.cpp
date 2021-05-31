/*
Maximum Profit on App
Send Feedback
You have made a smartphone app and want to set its subscription price such that the profit earned is maximised. There are certain users who will subscribe to your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of subscribers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of subscribers. So maximum profit you can earn is :
*/
#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int maximumProfit(int budget[], int n) {
    // Write your code here
    int ans=INT_MIN;
    sort(budget,budget+n);
    for(int i=0;i<n;i++)
    {
        ans=max(ans,budget[i]*(n-i));
    }
    return ans;
}
int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];

    cout << maximumProfit(input, n) << endl;

}

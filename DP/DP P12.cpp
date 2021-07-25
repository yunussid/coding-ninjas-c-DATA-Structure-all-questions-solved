/*
Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are
sorted in strictly increasing order.
*/
#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int *arr,int n){
    if(n<=1){
        return 1;
    }
    int *stored=new int[n];
    stored[0]=1;
    for(int i=1;i<n;i++){
        stored[i]=1;
        //reverse to find lis max for the arr[i]
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                continue;
            }
            int possibleAns=stored[j]+1;
            if(possibleAns>stored[i]){
                stored[i]=possibleAns;
            }
        }
    }
    int best=0;
    for(int i=0;i<n;i++){
        if(best<stored[i]){
            best=stored[i];
        }
    }
    return best;
    delete []stored;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}

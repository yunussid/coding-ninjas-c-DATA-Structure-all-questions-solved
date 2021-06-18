/*
Code : K smallest Elements
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(n * logk) and space complexity should not be more than O(k).
Note: Order of elements in the output is not important.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> kSmallest(int arr[],int n,int k){
    priority_queue<int> maxHeap;

    for(int i=0;i<k;i++){
        maxHeap.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i] <maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    vector<int> output;

    while(!maxHeap.empty()){
        output.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return output;
}

int main(){
    int size;
    cin>>size;

    int *input = new int(size);
    for(int i=0;i<size;i++){
        cin>>input[i];
    }

    int k;
    cin>>k;

    vector<int> output=kSmallest(input,size,k);
    sort(output.begin(),output.end());

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }

    delete[] input;
}

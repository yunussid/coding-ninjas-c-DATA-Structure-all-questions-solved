/*
Longest subset zero sum
Send Feedback
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int lengthofSubsetWithZeroSum(int *arr,int n){
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
    }
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            if(m<i+1){
                m=i+1;
            }
        }
        else if(freq.count(arr[i])>0){
            if(m<i-freq[arr[i]]){
                m=i-freq[arr[i]];
            }
        }
        else{
            freq[arr[i]]=i;
        }
    }

    return m;
}

int main(){
    int size;
    cin>>size;

    int *arr=new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<lengthofSubsetWithZeroSum(arr,size);

    delete[] arr;
}

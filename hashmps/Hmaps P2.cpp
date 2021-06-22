/*
Code : Maximum Frequency Number

You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int highestFrequency(int arr[],int n){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int key=arr[i];
        if(m.count(key)==0){
            m[key]=1; //initializing frequency value to 1 when key is not already present in hashmap
        }else{
            m[key]++;
        }
    }
    int maxim=m[arr[0]];
    int ans=arr[0];
    int j=1;
    while(j<n){
        if(m[arr[j]]>maxim){
            maxim=m[arr[j]];
            ans=arr[j];
        }
        j++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<highestFrequency(arr,n);

    delete[] arr;
}

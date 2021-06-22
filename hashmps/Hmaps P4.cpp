/*
Code : Pair Sum to 0
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *arr,int n){
    unordered_map<int,int> ourmap;
    int z=0;
    for(int i=0;i<n;i++){
        if(ourmap.count(-1*arr[i])>0){
            if(ourmap[-1*arr[i]]>0){
                z+=ourmap[-1*arr[i]];
            }
        }
        ourmap[arr[i]]++;
    }
    return z;
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<pairSum(arr,n);
    delete[] arr;
}

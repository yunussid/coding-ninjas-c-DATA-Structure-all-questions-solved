/*
Check Max-Heap

Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.
*/
#include<iostream>
using namespace std;

bool isMaxHeap(int arr[],int n){
    for(int i=0;2*i+1<n;i++){
        int leftChildIndex=2*i+1;
        int rightChildIndex=leftChildIndex+1;

        if(arr[i]<arr[leftChildIndex]){
            return false;
        }
        if(arr[i]<arr[rightChildIndex]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<(isMaxHeap(arr,n) ? "true\n":"false\n");

    delete[] arr;
}

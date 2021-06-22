/*
Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the
numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array
must contain only single element.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int search(int *arr,int k,int n)
{
    for(int i=0;i<n;i++){
        if(arr[i]==k)
            return i;
    }

}
vector<int> longestConsecutiveIncreasingSequence(int *arr,int n){
    unordered_map<int,int> hash;
    int maxlength=0;
    int begin=0;
    int k=0;
    for(int i=0;i<n;i++){
        hash[arr[i]]=1;
    }
    for(int i=0;i<n;i++){
        if(hash[arr[i]]){
            int max=1;
            int start=arr[i];
            int find=arr[i];
            while(hash[++find]){
                max++;
                hash[find]=0;
            }
            find=arr[i];
            while(hash[--find]){
                start=find;
                max++;
                hash[find]=0;
            }
            if(max=maxlength){
                int l=search(arr,start,n);
                if(l<k){
                    begin=start;
                    k=l;
                }
            }
            else if(max>maxlength){
                maxlength=max;
                begin=start;
                k=search(arr,begin,n);

            }
        }
    }
    vector<int> v;
    for(int i=0;i<maxlength;i++){
        v.push_back(begin++);
    }
    return v;
}

int main(){
    int size;
    cin>>size;

    int* arr=new int[size];

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}

/*
Code : Print Intersection
Send Feedback
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this
problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the
arrays/lists.
*/
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void intersection(int *arr1,int *arr2,int n, int m){
    unordered_map<int,int> mapp;
    for(int i=0;i<n;i++)
        mapp[arr1[i]]++;

    sort(arr2,arr2+m);
    for(int i=0;i<m;i++){
        if(mapp[arr2[i]]>0){
            mapp[arr2[i]]--;
            cout<<arr2[i]<<" ";
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int size1,size2;

        cin>>size1;
        int *input1=new int[size1];

        for(int i=0;i<size1;i++){
            cin>>input1[i];
        }

        cin>>size2;
        int *input2=new int[size2];

        for(int i=0;i<size2;i++){
            cin>>input2[i];
        }

        intersection(input1,input2,size1,size2);

        delete []input1;
        delete []input2;

        cout<<endl;
    }
    return 0;
}

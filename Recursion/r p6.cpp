#include<iostream>
using namespace std;
bool isSorted(int a[],int size){
     if(size==0||size==1){
      return 1;
     }
     if(a[0]>a[1]){
      return 0;
     }
     bool isSmallerSorted=isSorted(a+1,size-1);
     return isSmallerSorted;
}
int main(){
     int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout<<isSorted(input,n);
}

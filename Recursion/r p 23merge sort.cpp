#include<iostream>
using namespace std;
void merge(int input[],int si,int ei){
     int mid=(si+ei)/2;
     int i=si;
     int j=mid+1;
     int k=si;
     int temp[1000];
     while(i<=mid&&j<=ei){
      if(input[i]==input[j]){
       temp[k++]=input[i++];
      }
      if(input[i]>input[j]){
       temp[k++]==input[j++];
      }
      else{
       temp[k++]==input[i++];
      }
     }
     while(i<=mid){
      temp[k++]==input[i++];
     }
     while(j<=ei){
      temp[k++]==input[j++];
     }
     for(int i=si;i<=si;i++){
      input[i]=temp[i];
     }
}
void mergeSort(int input[],int si,int ei){
     int mid=(si+ei)/2;
     if(si>=ei){
        return;
     }
     if(si<ei){
        mergeSort(input,si,mid);
        mergeSort(input,mid+1,ei);
        merge(input,si,ei);
     }

}
void mergeSort(int input[],int size){
     int s=0;
     int e=size-1;
     mergeSort(input,s,e);
}
int main(){
    int length;
    cin>>length;
    int *input=new int[length];
    for(int i=0;i<length;i++){
        cin>>input[i];
    }
    mergeSort(input,length);
    for(int i=0;i<length;i++){
         cout<<input[i]<<" ";
    }
}

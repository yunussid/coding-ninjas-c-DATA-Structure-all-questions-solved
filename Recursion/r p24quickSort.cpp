#include<iostream>
using namespace std;
int partition(int input[],int si,int ei){
    int count=0;
    for(int i=si+1;i<=ei;i++){
     if(input[i]<=input[si]){
      count++;
     }
    }
    int temp=input[si];
    input[si]=input[si+count];
    input[si+count]=temp;
    int i=si;
    int j=ei;
    while(i<(si+count)||j>(si+count)){
      if(input[i]<=input[si+count]){
       i++;
      }else if(input[j]>input[si+count]){
       j--;
      }else{
       int t=input[i];
         input[i]=input[j];
         input[j]=t;
         i++;
         j--;
      }
    }
    return si+count;
}
void quickSort(int input[],int s,int e){
     if(s>=e){
       return;
     }
     int p=partition(input,s,e);
     quickSort(input,s,p-1);
     quickSort(input,p+1,e);
}
void quickSort(int input[],int n){
     int s=0;
     int e=n-1;
     quickSort(input,s,e);
}
int main(){
    int n;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    quickSort(input,n);
     for(int i=0;i<n;i++){
        cout<<input[i]<<" ";
     }
    delete [] input;
}

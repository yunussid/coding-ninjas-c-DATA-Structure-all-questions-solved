#include<iostream>
using namespace std;
/*void helper(int input[],int currIndex,int n,int x,int output[],int k){
     if(currIndex==n){
     return;
     }
     if(input[currIndex]==x){
     output[k++]==currIndex;
     }
     helper( input, currIndex+1, n,x,output,k);
}
int allIndexes(int input[],int n,int x,int output[]){
    int k=0;
    helper(input,0,n,x,output,k);
    return k;
}*/
void helper(int input[], int currIndex,int size, int x, int output[],int &k){
    if(currIndex==size)
        return;
    if(input[currIndex]==x){
        output[k++]=currIndex;
    }
    helper(input,currIndex+1,size,x,output,k);
}
int allIndexes(int input[], int size, int x, int output[]) {
    int k=0;
    helper (input,0,size,x,output,k);
    return k;

}

int main(){
    int n;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
        }
    int x;
    cin>>x;
    int *output=new int[n];
    int size=allIndexes(input,n,x,output);
    for(int i=0;i<size;i++){
    cout<<output[i]<<" ";
    }
    delete []input;
    delete []output;
}

/*Code : Min Steps to 1
Send Feedback
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
*/
#include<iostream>
using namespace std;

//recursive
int minSteps(int n){
    if(n<=1){
        return 0;
    }
    int x=minSteps(n-1);

    int y=INT_MAX;
    int z=INT_MAX;

    if(n%2==0){
        y=minSteps(n/2);
    }

    if(n%3==0){
        z=minSteps(n/3);
    }

    int ans=min(x,min(y,z))+1;
    return ans;
}

//bottom-up approach
int minSteps2(int n,int *arr){
    if(n==1){
        return 0;
    }

    if(arr[n]>0){
        return arr[n];
    }

    int ans=1+minSteps2(n-1,arr);
    if(n%2==0){
        ans = min(ans,1+minSteps2(n/2,arr));
    }
    if(n%3==0){
        ans = min(ans,1+minSteps2(n/3,arr));
    }
    arr[n]=ans;
    return ans;
}

//dp
int minSteps3(int n){
    int *arr=new int[n+1];
    arr[1]=0;
    for(int i=2;i<=n;i++){
        int ans = 1+arr[i-1];
        if(i%2==0){
            ans=min(ans,1+arr[i/2]);
        }
        if(i%3==0){
            ans=min(ans,1+arr[i/3]);
        }
        arr[i]=ans;
    }
    int result=arr[n];
    delete [] arr;
    return result;
}

int main(){
    int n;
	cin >> n;

	cout << minSteps3(n) << endl;
}

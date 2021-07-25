/*
Loot Houses
Send Feedback
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can
loot.
*/

#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    /*if(n==0){
        return 0;
    }
    int ans[n];
    ans[0]=arr[0];
    ans[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        ans[i]=max(arr[i]+ans[i-2],ans[i-1]);
    }
    return ans[n-1];
    */
    /*
    if(n<=0){
        return 0;
    }

    int ans1=arr[n-1]+maxMoneyLooted(arr,n-2);
    int ans2=maxMoneyLooted(arr,n-1);
    return max(ans1,ans2);
    */
    if(n==0){
        return 0;
    }
    int ans[n];
    ans[0]=arr[0];
    ans[1]=max(arr[1],arr[0]);
    for(int i=2;i<n;i++){
        ans[i]=max(arr[i]+ans[i-2],ans[i-1]);
    }
    return ans[n-1];
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

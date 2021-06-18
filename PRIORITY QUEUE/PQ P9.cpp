/*
Running Median

You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
*/
#include<iostream>
#include<queue>
using namespace std;

void findMedian(int *arr,int n){
    priority_queue<int> s;

    // min heap to store the greater half elements
    priority_queue<int,vector<int>,greater<int> > g;
    if(n==0){
        return ;
    }

    int med = arr[0];
    s.push(arr[0]);

    cout << med << " ";

    // reading elements of stream one by one

    for (int i=1; i < n; i++)
    {
        int x = arr[i];

        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top())/2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (int)s.top();
            }
            else
            {
                g.push(x);
                med = (int)g.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top())/2.0;
        }

        cout << med << " ";
    }
}

int main(){
    int n;
    cin>>n;

    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}

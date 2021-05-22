#include<iostream>
#include<stack>
using namespace std;
int* stockSpan(int *prize,int size){
 stack<int> st;
    st.push(0);
    int *S = new int[size];

    // Span value of first element is always 1
    S[0] = 1;
    // Calculate span values for rest of the elements
    for (int i = 1; i < size; i++) {

        while (!st.empty() && prize[st.top()] < prize[i])
            st.pop();

        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push this element to stack
        st.push(i);
    }
    return S;
}
int main(){
 int size;
 cin>>size;
 int *input=new int[size];
 for(int i=0;i<size;i++){
  cin>>input[i];
 }

 int *output=stockSpan(input,size);
 for(int i=0;i<size;i++){
  cout<<output[i]<<" ";
 }
 cout<<"\n";
 delete[] input;
 delete[] output;
}

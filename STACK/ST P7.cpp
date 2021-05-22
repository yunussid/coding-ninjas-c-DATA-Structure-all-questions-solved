#include<iostream>
using namespace std;
#include<stack>
#include<string>

bool checkRedundantBrackets(string expression){
   stack<char> st;

    // Iterate through the given expression
    for (auto& ch : expression) {

        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();

            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;

            while (top != '(') {

                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;

                // Fetch top element of stack
                top = st.top();
                st.pop();
            }

            // If operators not found
            if (flag == true)
                return true;
        }

        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
int main(){
  string input;
  cin>>input;
  cout <<((checkRedundantBrackets(input)) ? "true" : "false");
}

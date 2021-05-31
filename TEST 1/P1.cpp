/*
Does s contain t ?
Send Feedback
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
*/
#include<iostream>
using namespace std;
#include <cstring>
bool isSubSequence(char str1[], char str2[], int m, int n){

    if (m == 0) return true;
    if (n == 0) return false;

    if (str1[m-1] == str2[n-1])
        return isSubSequence(str1, str2, m-1, n-1);

    return isSubSequence(str1, str2, m, n-1);
}

bool checksequenece(char large[] , char*small) {
 int m = strlen(small);
    int n = strlen(large);
    bool ans = isSubSequence(small,large,m,n);
    return ans;
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}

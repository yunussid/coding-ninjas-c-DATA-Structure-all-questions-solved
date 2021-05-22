#include<iostream>
using namespace std;
#include<cstring>
void pairStar(char input[]){
	//Base Case: Reached End Of String

    int start=0;
	if(input[start]=='\0'){
		return;
	}
	//Recursive Call
	pairStar(input+1);
    int n=strlen(input);
	if(input[start] == input[start+1]){
		//Extending the string
		input[n+1] = '\0';
		int i;
		//To shift the letters by 1
		for(i = n-1;i>=start +1;i--){
			input[i+1] = input [i];
		}
		//Entering * in between
		input[start+1] = '*';
	}
}
int main(){
    char input[100];
    cin.getline(input,100);
    pairStar(input);
    cout<<input<<endl;
}

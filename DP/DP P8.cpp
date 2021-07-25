#include<iostream>
using namespace std;

int lcsMemo(string s,string t,int **output){
    int m=s.size();
    int n=s.size();
     //BASE CALL
    if(s.size()=='\0'|| t.size()=='\0'){
        return 0;
    }

    //Check If Answer Already Exists
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    //Recursive Call
    if(s[0]==t[0]){
        ans= 1 + lcsMemo(s.substr(1),t.substr(2),output);
    }
    else{
        int a= lcsMemo(s.substr(1),t,output);
        int b= lcsMemo(s,t.substr(1),output);
        int c= lcsMemo(s.substr(1),t.substr(1),output);
        ans = max( a, max(b,c));
    }
    //Save Your Calculation
    output[m][n]=ans;

    return ans;
}
int lcsMemo(string s,string t){
    int m=s.size();
    int n=t.size();
    int **output = new int*[m+1];
    for(int i=0;i<=m;i++){
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            output[i][j]=-1;
        }
    }
    return lcsMemo(s,t,output);
}
int lcs(string s,string t){
    //BASE CALL
    if(s.size()=='\0'|| t.size()=='\0'){
        return 0;
    }

    //Recursive Call

    if(s[0]==t[0]){
        return 1 + lcs(s.substr(1),t.substr(2));
    }
    else{
        int a= lcs(s.substr(1),t);
        int b= lcs(s,t.substr(1));
        int c= lcs(s.substr(1),t.substr(1));
        return max( a, max(b,c));
    }

}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<lcsMemo(s,t)<<endl;
    cout<<lcs(s,t)<<endl;
}

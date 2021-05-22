#include<iostream>
#include <math.h>
#include<cmath>
#include <iomanip>
using namespace std;
int geometricSum(int k){
     if(k==0){
        return 1;
    }
    double a=(1.00000/pow(2,k));
    return a+geometricSum(k-1);
}
int main(){
    int k;
    cin>>k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}

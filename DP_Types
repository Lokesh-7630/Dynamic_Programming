#include<iostream>
#include<vector>
using namespace std;
int fib(int n,vector<int>&f){
 if(n==1 || n==0){
    return n;
 } 
 if(f[n] != -1){
    return f[n];
 }
 return f[n]=fib(n-1,f)+fib(n-2,f);
}
int fib2(int n){
        vector<int>f2(n+1,0);
        f2[0]=0;
        f2[1]=1;
        for(int i=2; i<=n; i++){
            f2[i]=f2[i-1]+f2[i-2];
        }
        return f2[n];

}
int main(){
    int n=2;
    vector<int>f(n+1,-1);
    cout<<fib(n,f)<<endl;
    cout<<fib2(n);
return 0;
}

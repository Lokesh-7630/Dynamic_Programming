#include<iostream>
#include<vector>
using namespace std;



int knapsackTab( vector<int>&val,vector<int>&weight,int w,int n){
vector<vector<int>>dp(n+1,vector<int>(w+1,0));
for(int i=1; i<n+1; i++){
  for(int j=1; j<w+1; j++){
  
    int itmVal=val[i-1];
    int itmWt=weight[i-1];
  if(itmWt<=j){
    dp[i][j]=max(itmVal+dp[i][j-itmWt],dp[i-1][j]);  //only dp[i] intead if dp[i-1]
    }else{
      dp[i][j]=dp[i-1][j];
    }
  }
}
return dp[n][w];

}

int main(){
 vector<int>val={15,14,10,45,30};
 vector<int>weight={2,5,1,3,4};
 int w=7;
 int n=5;

 cout<<knapsackTab(val,weight,w,n)<<endl;
return 0;
}

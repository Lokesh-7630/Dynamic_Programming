#include<iostream>
#include<vector>
using namespace std;
int knapsackRecursion( vector<int>&val,vector<int>&weight,int w,int n){
   
    int itwt=weight[n-1];
    int itval=val[n-1];
     if(w==0 || n==0){
        return 0;
    }
  if(itwt<=w){
    //include
    int ans1=knapsackRecursion(val,weight,w-itwt,n-1)+itval;
    //exclude
    int ans2= knapsackRecursion(val,weight,w,n-1);
    return max(ans1,ans2);

  }else{
    return  knapsackRecursion(val,weight,w,n-1);
  }

}

int knapsackMem( vector<int>&val,vector<int>&weight,int w,int n){
vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
if(w==0 || n==0){
  return 0;
}
int itval=val[n-1];
int itwt=weight[n-1];
    if(dp[n][w] != -1){
      return dp[n][w];
    }
  if(itwt<=w){
    //include
    int ans1=knapsackRecursion(val,weight,w-itwt,n-1)+itval;
    //exclude
    int ans2= knapsackRecursion(val,weight,w,n-1);
    dp[n][w]= max(ans1,ans2);

  }else{
     dp[n][w]=  knapsackRecursion(val,weight,w,n-1);
  }
return  dp[n][w];


}
int knapsackTab( vector<int>&val,vector<int>&weight,int w,int n){
vector<vector<int>>dp(n+1,vector<int>(w+1,0));
for(int i=1; i<n+1; i++){
  for(int j=1; j<w+1; j++){
  
    int itmVal=val[i-1];
    int itmWt=weight[i-1];
  if(itmWt<=j){
    dp[i][j]=max(itmVal+dp[i-1][j-itmWt],dp[i-1][j]);
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
 cout<<knapsackRecursion(val,weight,w,n)<<endl;
 cout<<knapsackMem(val,weight,w,n)<<endl;
 cout<<knapsackTab(val,weight,w,n)<<endl;
return 0;
}

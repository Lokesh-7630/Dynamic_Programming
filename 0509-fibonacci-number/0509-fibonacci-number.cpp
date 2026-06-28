class Solution {
public:
    int fib(int n) {
        vector<int>df(n+1,0);
        if (n <= 1) {
            return n;
        }
        df[0]=0;
        df[1]=1;
        for(int i=2; i<=n; i++){
            df[i]=df[i-1]+df[i-2];
        }
        return df[n];

    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        while(!pq.empty()){
            auto curr=pq.top();
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1) return d;
            for(int i=0; i<4; i++){
                int newRow=row+drow[i];
                int newCol=col+dcol[i];
            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m ){
                int newDiff=max(abs(heights[newRow][newCol]-heights[row][col]),d);
                if(newDiff<diff[newRow][newCol]){
                    diff[newRow][newCol]=newDiff;
                    pq.push({newDiff,{newRow,newCol}});
                }
            }



            }
        }
        return 0;


    }
};
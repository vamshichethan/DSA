class Solution {
    bool check(int i,int j,int m,int n,vector<vector<int>>& grid){
        for(int row=0;row<n;row++){
            if(row==j){
                continue;
            }
            if(grid[i][row]==1){
                return true;
            }
        }
        for(int col=0;col<m;col++){
            if(col==i){
                continue;
            }
            if(grid[col][j]==1){
                return true;
            }
        }

        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    if(check(i,j,m,n,grid)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
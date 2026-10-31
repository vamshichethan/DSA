class Solution {
    const int MOD = 1e9+7;

    int solve(int i,int j,int m,int n,
              vector<vector<int>>& grid,
              vector<vector<int>>& dp){

        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }

        if(i==m-1 && j==n-1){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        long long ans = 0;

        // Move down
        if(i+1<m){
            int x=i+1;
            int y=j;
            int dir=0; // 0 = down, 1 = right

            while(x<m && y<n && grid[x][y]==1){
                if(dir==0){
                    y++;
                    dir=1;
                }else{
                    x++;
                    dir=0;
                }
            }

            ans+=solve(x,y,m,n,grid,dp);
        }

        // Move right
        if(j+1<n){
            int x=i;
            int y=j+1;
            int dir=1; // 1 = right, 0 = down

            while(x<m && y<n && grid[x][y]==1){
                if(dir==1){
                    x++;
                    dir=0;
                }else{
                    y++;
                    dir=1;
                }
            }

            ans+=solve(x,y,m,n,grid,dp);
        }

        return dp[i][j]=ans%MOD;
    }

public:
    int uniquePaths(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return solve(0,0,m,n,grid,dp);
    }
};
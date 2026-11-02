class Solution {
    int dp[11][2][11];
    int solve(string s,int i,int flag,int cnt){
        if(i>=s.size()){
            return cnt;
        }
        if(dp[i][flag][cnt]!=-1){
            return dp[i][flag][cnt];
        }
        int l=(flag==1?s[i]-'0':9);
        int ans = 0;
        for(int k=0;k<=l;k++){
            int ucnt=cnt+(k==1?1:0);
            ans+=solve(s,i+1,flag&(k==s[i]-'0'),ucnt);
        }
        return dp[i][flag][cnt]=ans;
    }
public:
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string rr=to_string(n);
        return solve(rr,0,1,0);
    }
};
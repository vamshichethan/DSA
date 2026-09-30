class Solution {
    const int MOD = 1e9+7;
    int tt[31][1001];
    int solve(int n,int k,int tar){
        if(n<=0){
            if(tar==0){
                return 1;
            }
            return 0;
        }
        if(tt[n][tar]!=-1){
            return tt[n][tar];
        }
        int t=0;
        for(int i=1;i<=k;i++){
            if(tar-i >= 0){            
               t+=solve(n-1,k,tar-i);
               t%=MOD;
            }
        }
        return tt[n][tar]=t%MOD;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(tt,-1,sizeof(tt));
        return solve(n,k,target)%MOD;
    }
};
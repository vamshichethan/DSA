class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int> l(n,-1);
        vector<int> r(n,-1);
        int j=0;
        if(n==1){
            return 0;
        }
        for(int i=0;i<m;i++){
            if(j>=n){
                break;
            }
            if(skill[j]==station[i]){
                l[j]=i;
                j++;
            }
        }
        j=n-1;
        for(int i=m-1;i>=0;i--){
            if(j<0){
                break;
            }
            if(skill[j]==station[i]){
                r[j]=i;
                j--;
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<n;i++){
            int mn=min(l[i-1],r[i-1]);
            int mx=max(l[i],r[i]);
            ans=max(ans,mx-mn);
        }
        return ans;
    }
};
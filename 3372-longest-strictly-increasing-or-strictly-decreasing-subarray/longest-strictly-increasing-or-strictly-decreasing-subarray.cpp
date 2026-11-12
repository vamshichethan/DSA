class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx=1,mi=1;
        int ans=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                mx++;
               ans=max(max(mx,mi),ans);
            }else{
                mx=1;
            }
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                mi++;
               ans=max(max(mx,mi),ans);
            }else{
                mi=1;
            }
        }

return ans;

    }
};
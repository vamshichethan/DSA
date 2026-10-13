class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans = 0;
        int i=0;
        int j=n-1;
        while(i<j){
            ans=ans+(nums[j]*nums[j]);
            ans=ans-(nums[i]*nums[i]);
            i++;
            j--;
        }
        if(n&1){
            ans=ans+(nums[j]*nums[j]);
        }
        return ans;
    }
};
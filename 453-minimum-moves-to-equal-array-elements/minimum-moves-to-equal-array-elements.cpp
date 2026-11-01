class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int mn=*min_element(nums.begin(),nums.end());
        // int mx=*max_element(nums.begin(),nums.end());
        // int ans = 0;
        // if(mn==mx){
        //     return 0;
        // }
        // while(mn+1!=mx){
        //     int d=mx-mn;
        //     ans+=d;
        //     for(int i=0;i<nums.size();i++){
        //         if(nums[i]==mx){
        //             continue;
        //         }else{
        //             nums[i]+=d;
        //         }
        //     }
        //     mn=*min_element(nums.begin(),nums.end());
        //     mx=*max_element(nums.begin(),nums.end());
        //     if(mn==mx){
        //         return ans;
        //     }
        // }
        // ans+=1;
        // return ans;
        int mn=*min_element(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-mn);
        }
        return ans;
    }
};
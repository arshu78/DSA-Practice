class Solution {
public:
    void b(int low,int high,vector<int>& nums, int target,vector<int> &ans)
    {
        if(low>high) return;
       int mid=low + (high-low)/2;
            if(nums[mid]==target)
            {
                b(low,mid-1,nums,target,ans);
                ans.push_back(mid);
                b(mid+1,high,nums,target,ans);
                
            }
            else if(nums[mid]<target)  b(mid+1,high,nums,target,ans);
            else b(low,mid-1,nums,target,ans);
       
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
       b(low,high,nums,target,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
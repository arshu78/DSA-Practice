class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int can=0;
        for(auto it:nums)
        {
            if(can==0)
            {
                ans=it;
            }
            if(ans==it)
            {
                can++;
            }
            else
            {
                can--;
            }
        }
        
        return ans;
    }
};
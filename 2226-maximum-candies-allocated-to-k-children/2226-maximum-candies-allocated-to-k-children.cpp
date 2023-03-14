class Solution {
public:
    bool black(int mid,vector<int>& candies,long long k)
    {
       long long int ans=0;
        for(auto it:candies)
        {
            ans+=it/mid; 
        }
        return ans>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1,high=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(black(mid,candies,k)) 
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};
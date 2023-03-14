class Solution {
public:
   long long int black(int target,vector<int>& piles)
    {
       long long int sum=0;
        for(auto it:piles)
        {
            sum+=it/target;
            if(it%target!=0) sum++;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(black(mid,piles)<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
       return low;
    }
    
    
};
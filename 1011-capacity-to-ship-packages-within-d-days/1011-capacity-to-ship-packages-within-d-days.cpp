class Solution {
public:
    int black( int sum,vector<int>& weights,int d)
    {
        int days=1;
    int temp=0;
        for(auto it:weights)
        {
           if(temp+it<=sum)
           {
               temp+=it;
           }
            else
            {
                days++;
                temp=it;
               
            }
            
        }
        
        return days<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto it:weights) sum+=it;
        int low=*max_element(weights.begin(),weights.end()),high=sum;
       int ans=low;
        while(low<=high)
        {
           int mid=low + (high-low) /2;
            if(black(mid,weights,days))
            {
                ans=mid;
                high=mid-1;
            }
            else 
            {
                low=mid+1;
            }
           
        }
        
        return ans;
    }
};
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
     bool isPossible(int A[],int N,int M,int mid)
    {
        int cnt=1;
        int tempSum=0;
        
        for(int i=0;i<N;i++)
        {
            if(tempSum + A[i] <= mid)
            {
                tempSum+=A[i];
            }
            else
            {
                cnt++;
                if(cnt>M || A[i]>mid)
                {
                    return false;
                }
                else
                {
                    tempSum=A[i];
                    
                }
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int low=INT_MAX;
        for(int i=0;i<N;i++)
        {
            low=min(low,A[i]);
        }
        
        if(M>N)
        {
            return -1;
        }
        
        int high=0;
        for(int i=0;i<N;i++)
        {
            high+=A[i];
        }
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+ high) /2;
            if(isPossible(A,N,M,mid)==true)
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

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
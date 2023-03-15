class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int col=matrix[0].size();
        unordered_set<int> drow;
        unordered_set<int> dcol;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    drow.insert(i);
                    dcol.insert(j);
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(drow.count(i)>0 || dcol.count(j)>0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};
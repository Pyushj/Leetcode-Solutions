class Solution {
public:
    //pair<int,vector<int>>
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set< pair<int,vector<int>> > st;
        int row=mat.size();
        int col=mat[0].size();
        int sum=0;
        vector<int> res;
        for(int i=0;i<row;i++)
        {
            sum+=mat[i][0];
            res.push_back(0);
        }
        st.insert({sum,res});
        int n=k-1;
        while(n--)
        {
            auto itr=st.begin();
            pair<int,vector<int>> temp=(*itr);
            st.erase(itr);
            for(int i=0;i<row;i++)
            {
                int pos=temp.second[i];
                if(pos+1 < col)
                {
                        int sum=temp.first+mat[i][pos+1]-mat[i][pos];
                        vector<int> newPos=temp.second;
                        newPos[i]++;
                        st.insert({sum,newPos});  
                }  
            }  
        }
        auto itr=st.begin();
        sum=(*itr).first;
        return sum; 
    }
};

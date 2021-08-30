class Solution {
public:
  //returns the distance between two points without doing sqrt() ->>to keep distance unique
    long long int distance(vector<int> x,vector<int> y)
    {
        long long int X=(x[0]-y[0])*(x[0]-y[0]);
        long long int Y=(x[1]-y[1])*(x[1]-y[1]);
        return (long long int)(X + Y);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
          //stores the count of distances from a given point   
          unordered_map<long long int,int> mp;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                long long int dist=distance(points[i],points[j]);
                mp[dist]++;
            }
          //ways of arranging n points in group of two nC2x2 as (i,j,k) and (i,k,j) are two different arrangements
            for(auto x: mp)
            {
                int  temp=x.second;    
                count+=(temp)*(temp-1);
            }
            mp.clear();
        }
        return count;
    }
};

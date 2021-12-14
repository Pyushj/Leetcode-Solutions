class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        
        int sum=0,n=heights.size(),i=1;
        // create a min heap
        priority_queue<int,vector<int>,greater<int>> heap;
        for(i=1;i<n;i++)
        {
            int jumpLength=heights[i]-heights[i-1];
            if(jumpLength>0)
            heap.push(jumpLength);
          
            if(heap.size()>ladders)
            {
                sum+=heap.top();
                heap.pop();
            }
            if(sum>bricks)
                break;
        }
        return i-1;
    }
};

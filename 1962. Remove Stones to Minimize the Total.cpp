class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        priority_queue<int> heap;
        for(auto x: piles)
        {
            heap.push(x);
        }
        while(k--)
        {
            int temp=heap.top();
            heap.pop();
            int toRemove=temp/2;
            temp=temp-toRemove;
            heap.push(temp);
        }
        while(heap.size()>0)
        {
            int temp=heap.top();
            sum+=temp;
            heap.pop();
        }
        return sum;
        
    }
};

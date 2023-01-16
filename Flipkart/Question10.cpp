class Solution {
public:
/*It is a good example of how to apply priority queues.

    Store elements and their occurrences in a map.
    Store that in a priority queue (Max Heap) based on the number of occurrences.
    Create two priority queues, push their elements into a result vector, reduce their occurrences, and then push them back into the original priority queue.
*/
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=1)
        {
            return barcodes;
        }
        unordered_map<int,int>mp;
        for(auto it:barcodes)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<int>res;
        while(pq.top().first>0)
        {
            pair<int,int>pq1=pq.top();
            pq.pop();

            res.push_back(pq1.second);
            pq1.first--;

            pair<int,int>pq2=pq.top();
            pq.pop();
            if(pq2.first>0)
            {
                res.push_back(pq2.second);
                pq2.first--;
            }
            pq.push(pq1);
            pq.push(pq2);
        }
        return res;
    }
};
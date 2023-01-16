/*1)First store elements with their total occurrences in map.
2)Then through a comparator with comparing store it in priority queue(use max heap).
3)Just pop and add it to result vector.*/

class cmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};
class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto it:words)
            mp[it]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<string>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
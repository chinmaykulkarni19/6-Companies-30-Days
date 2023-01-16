class Solution {
public:
//Remember unique characters are present in order not in s.
//So use unordered_map for storing the number of times it has appeared in s.
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        string str="";
        for(int i=0;i<order.size();i++)
        {
            if(mp[order[i]]>0)
            {
                int temp=mp[order[i]];
                while(temp!=0)
                {
                    str+=order[i];
                    temp--;
                }
                mp[order[i]]=0;
            }
            
        }
        for(auto it:s)
        {
            if(mp[it]>0)
            {
                int temp=mp[it];
                while(temp!=0)
                {
                    str+=it;
                    temp--;
                }
                mp[it]=0;
            }
            
        }
        return str;

    }
};
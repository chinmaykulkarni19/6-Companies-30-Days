class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //FOR THE TEST CASE 
        //S="0"  K="20"   WHICH WE WILL BE RETURNING FALSE
        if(k>s.size())
        {
            return false;
        }
        unordered_set<string>st;
        for(int i=0;i<=s.size()-k;i++)
        {
            st.insert(s.substr(i,k));
        }
        return st.size()==pow(2,k);
    }
};
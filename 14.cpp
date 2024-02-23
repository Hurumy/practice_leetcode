class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prf;
        prf = strs[0];
        for (int i=1; i<strs.size()&&prf.size()>0; i++) {
            if (prf.size() > strs[i].size())
                prf.erase(strs[i].size(), prf.size()-strs[i].size());
            for (int j=0; j<prf.size() && j<strs[i].size(); j++) {
                if (prf[j]==strs[i][j]) {
                    continue;
                }else{
                    prf.erase(j, prf.size()-j);
                    break;
                }
            }
        }
        return (prf);
    }
};
class Solution {
public:
    bool isClosed(string s)
    {
        int flag = 0;
        for (int i=0; i<s.size()&&flag>=0; i++)
        {
            if(s[i] == '(')
                flag ++;
            else if (s[i] == ')')
                flag --;
            else
                return (false);
        }
        if (flag != 0)
            return (false);
        return (true);
    }
    vector<string> dfs(vector<string> list, int depth, int dlimit)
    {
        vector<string> res;
        vector<string> left(list);
        vector<string> right(list);
        
        if (depth >= dlimit)
            return list;
        else if (list.empty())
        {
            vector<string> tmp1;
            vector<string> tmp2;
            
            left.push_back("(");
            right.push_back(")");
            tmp1=dfs(left,depth+1,dlimit);
            tmp2=dfs(right,depth+1,dlimit);
            copy(tmp1.begin(), tmp1.end(), back_inserter(res));
            copy(tmp2.begin(), tmp2.end(), back_inserter(res));
            return (res);
        }
        else
        {
            vector<string> tmp1;
            vector<string> tmp2;
            for(int i=0; i<left.size(); i++)
                left[i] += '(';
            tmp1 = dfs(left, depth+1, dlimit);
            for(int i=0; i<right.size(); i++)
                right[i] +=')';
            tmp2 = dfs(right, depth+1, dlimit);
            copy(tmp1.begin(), tmp1.end(), back_inserter(res));
            copy(tmp2.begin(), tmp2.end(), back_inserter(res));
            return (res);
        }
        return (res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<string> all;
        
        vector<string> dummy;
        all = dfs(dummy, 0, n*2);
        
        for(int i=0; i<all.size(); i++)
        {
            if (isClosed(all[i]))
                res.push_back(all[i]);
        }
        return (res);
    }
};

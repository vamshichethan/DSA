class Solution {
    vector<string> ans;
    bool check(string s){
        int n=s.size();
        int o=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                o++;
            }else{
                if(o<=0){
                    return false;
                }else{
                    o--;
                }
            }
        }
        return o==0;
    }
    void solve(int n,string s){
        if(n==0){
            if(check(s)){
                ans.push_back(s);
                return;
            }
            return;
        }
        solve(n-1,s+'(');
        solve(n-1,s+')');
        return ;
    }
public:
    vector<string> generateParenthesis(int n) {
        solve(2*n,"");
        return ans;
    }
};
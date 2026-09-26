class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.size();

        unordered_map<string, string> mp;

        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        string temp = "";
        bool brac = false;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                brac = true;
                continue;
            }

            else if (s[i] == ')') {
                brac = false;

                if (mp.count(temp)) {
                    ans += mp[temp];   // changed
                }
                else {
                    ans += '?';
                }

                temp = "";
                continue;
            }

            if (brac == false) {
                ans += s[i];
            }
            else {
                temp += s[i];
            }
        }

        return ans;
    }
};
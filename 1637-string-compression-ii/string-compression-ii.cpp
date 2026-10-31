
class Solution {
    static int tt[101][27][101][101];

    int solve(int i,string ch,int cnt,int k,string &s){
        if(k<0){
            return 10000;
        }
        if(i>=s.size()){
            return 0;
        }

        int idx = ch=="" ? 26 : ch[0]-'a';
        int oldcnt = cnt;

        if(tt[i][idx][cnt][k]!=-1){
            return tt[i][idx][cnt][k];
        }

        int nt = solve(i+1,ch,cnt,k-1,s);
        int t=0;

        if(ch==""){
            ch=s[i];
            cnt++;
            t=1+solve(i+1,ch,cnt,k,s);
        }else{
            int x=0;
            if(s[i]==ch[0]){
                cnt++;
                if(cnt==2 || cnt==10 || cnt==100){
                    x=1;
                }
            }else{
                ch=s[i];
                cnt=1;
                x=1;
            }
            t=x+solve(i+1,ch,cnt,k,s);
        }

        return tt[i][idx][oldcnt][k]=min(t,nt);
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(tt,-1,sizeof(tt));
        return solve(0,"",0,k,s);
    }
};

int Solution::tt[101][27][101][101];

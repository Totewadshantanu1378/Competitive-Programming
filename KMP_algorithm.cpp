 vector<int>LPS(string s){
            int n = s.size();
            vector<int>lps(n);
            for(int i=1;i<n;i++){
                int j = lps[i-1];
                while(j > 0 && s[i] != s[j]){
                    j = lps[j - 1];
                }
                if(s[i] == s[j])
                 j++;
                
                lps[i] = j;
            }
            return lps;
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>lps = LPS(pat);
            int m = pat.size();
            int n = txt.size();
            vector<int>ans;
            int i=0,j = 0;
            while(i < n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j == 0) i++;
                    else j = lps[j - 1];
                }
                
                if(j == m){
                    ans.push_back(i - m + 1);
                    j = lps[j-1];
                }
            }
            if(ans.size()) return ans;
            
            return {-1};
        }
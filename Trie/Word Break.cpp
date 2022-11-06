class Solution {
public:
    struct Trie{
        Trie *child[26];
        bool isEnd;
        Trie(){
            for(int i=0; i<26; ++i)
                child[i] = NULL;
            isEnd = false;
        }
    };
    Trie* root = new Trie();

    void insert(string &word){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a'])
                cur->child[ch-'a'] = new Trie();
            cur=cur->child[ch-'a'];
        }
        cur->isEnd = true;
    }

    bool search(string &word){
        Trie *cur = root;
        for(auto &ch : word){
            if(!cur->child[ch-'a'])
                return false;
            cur=cur->child[ch-'a'];
        }
        return cur->isEnd;
    }

    int dp[301];    //based on the given constraints
    bool solve(string &s, int n, int start){
        if(start == n)
            return true;
        if(dp[start] != -1)
            return dp[start];
        for(int i=start; i<n; ++i){
            string str=s.substr(start, i-start+1);
            if(search(str))
                if(solve(s, n, i+1))
                    return dp[start]=true;

        }
        return dp[start]=false;
    }

    bool wordBreak(string &s, vector<string>& wordDict) {
        for(auto &word : wordDict)
            insert(word);
        memset(dp, -1, sizeof(dp));
        return solve(s, s.size(), 0);
    }
};

Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Solution:
Using two hash map:

class Solution {
public:
    bool matchprocess(string word,string pattern)
    {
         unordered_map<char,char> m1;
         unordered_map<char,char> m2;
        for(int i=0;i<word.length();i++)
        {
            if(m1.find(word[i])==m1.end())
                m1[word[i]]=pattern[i];
            if(m2.find(pattern[i])==m2.end())
                m2[pattern[i]]=word[i];
            if(m1[word[i]]!=pattern[i] || m2[pattern[i]]!=word[i])
                return false;
            
        }
        return true;
    }
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {  
            if(matchprocess(words[i],pattern))
            {
                ans.push_back(words[i]);   
            }
            
        }
        return ans;
    }
  
  Another solution: 
  Using one hash map:
  
  class Solution {
public:
    bool process(string w, string p)
    {
        unordered_map<char,char> m;
        vector<bool> vis(26,false);
        for(int i=0;i<w.length();i++)
        {
            if(!m[w[i]] && vis[p[i]-'a'] )
                return false;
            if(m[w[i]] && m[w[i]]!=p[i])
                return false;
            m[w[i]]=p[i];
            vis[p[i]-'a']=true;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto w: words)
        {
            if(process(w,pattern))
                ans.emplace_back(w);
        }
        return ans;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(count(wordList.begin(), wordList.end(), endWord) == 0)
            return 0;
        int n = wordList.size();
        queue<string> q;
        unordered_set<string> wordSet;
        unordered_set<string> visited;
        for(int i=0; i<n; i++)
            wordSet.insert(wordList[i]);
        if(wordSet.find(beginWord) != wordSet.end())
            wordSet.erase(beginWord);
        
        q.push(beginWord);
        int steps = 1;
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                string curr = q.front();
                q.pop();
                if(arrived(curr, q, wordSet, visited, endWord)){
                    return steps + 1;
                }
            }    
            steps++;
        }
        return 0;
    }
    bool arrived(string s, queue<string> &q, unordered_set<string> &wordSet, unordered_set<string> &visited, string endWord){
        for(int i=0; i<s.size(); i++){
            char original = s[i];
            for(char j='a'; j<='z'; j++){
                if(j == original)
                    continue;
                s[i] = j;
                if(wordSet.find(s) != wordSet.end()){
                    if(s == endWord)
                        return true;
                    if(visited.find(s) == visited.end()){
                        q.push(s);
                        visited.insert(s);
                    }
                }
            }
            s[i] = original;
        }
        return false;
    }
};

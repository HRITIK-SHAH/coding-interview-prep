class Solution {
public:
    string getHappyString(int n, int k) {
        unordered_map<char , string> nextLetters{
            {'a' , "bc"} , {'b' , "ac"} , {'c' , "ab"}};
            queue<string> q{{{"a" , "b" , "c"}}};

            while(q.front().length() != n){
                string u = q.front();
                q.pop();
                for(char nextLetter : nextLetters.at(u.back()))
                q.push( u + nextLetter);
            }

            if(q.size() < k)
            return "";
            for(int i = 0 ; i < k - 1 ; ++i)
            q.pop();
            return q.front();
        }
        
    
};
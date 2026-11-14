class Solution {
public:
    bool isValid(string s) {
        stack<char> opened;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='{'){
                opened.push(s[i]);
            }
            else if(s[i] =='['){
                opened.push(s[i]);
            }
            else if(s[i] =='('){
                opened.push(s[i]);
            }
            else if(s[i] =='}'){
                if(opened.empty()){
                    return false;
                }
                else if(opened.top()!='{'){
                    return false;
                }
                opened.pop();
            }
            else if(s[i] ==']'){
                if(opened.empty()){
                    return false;
                }
                else if(opened.top()!='['){
                    return false;
                }
                opened.pop();
            }
            else if(s[i] ==')'){
                if(opened.empty()){
                    return false;
                }
                else if(opened.top()!='('){
                    return false;
                }
                opened.pop();
            }
        }
        if(opened.size()!=0){
            return false;
        }
        return true;
    }
};
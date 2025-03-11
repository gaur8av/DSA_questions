class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int result = 0;
        vector<int> vec(3 , 0);
        int i=0,j=0;
        while(j < n){
            char ch = s[j];
 
            vec[ch - 'a']++;
            
            while(vec[0] > 0 && vec[1] > 0 && vec[2] > 0){
                result += (n - j);

                vec[s[i] - 'a']--;
                i++;
            } 
            j++;
        }
        return result;
        
    }
};
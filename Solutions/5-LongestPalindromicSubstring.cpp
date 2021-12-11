class Solution {
public:
//Dynamic Programming
//Learn the nature of each question instead of using previous DP methods directly.
//Runtime faster than 52.74%
//MU less than 67.79%
    string longestPalindrome(string s) {    
        int strLength = s.length();
         if (strLength <= 1) {
             return s;
         }
         if(strLength == 2){
             if(s[0]==s[1])return s;
             else return s.substr(0,1);
         }
         bool arr[strLength][strLength];
         int start = 0;
         int length = 1;
         for(int i = 0; i<strLength;i++){
             arr[i][i]=true;
         }
         for(int i = 1; i<strLength;i++){
             if(s[i]==s[i-1]){
                arr[i][i-1] = true;
                start = i-1;
                length = 2;
             }else{
                 arr[i][i-1] = false;
             }
         }
         for(int i = 2; i<strLength; i++){
             for(int j = 0; j<i-1;j++){
                arr[i][j] = arr[i-1][j+1] && (s[i]==s[j]);
                if(arr[i][j] && (i-j+1)>length){
                    //cout<<i<<"$$$"<<i-j+1<<endl;
                    start = j;
                    length = i-j+1;
                } 
             }
         }
         return s.substr(start,length);
    }
};
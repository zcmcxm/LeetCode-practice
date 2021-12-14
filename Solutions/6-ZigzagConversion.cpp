class Solution {
public:
//Visit by row
//Alternative way: Sort by row
//go through the string once and append each char to one of the strings inside an vector
//every time reach the first element or the last element of the batch, change the direction of going through strings in the vector
//Runtime faster than 30.29%
//MU less than 88.06%

    string convert(string s, int numRows) {
        //when numRows is 1 or 2
        if(numRows == 1){
            return s;
        }else if(numRows == 2){
            string newStr = "";
            for(int i = 0;i<s.length();i+=2){
                newStr += s[i];
            }
            for(int i = 1;i<s.length();i+=2){
                newStr += s[i];
            }
            return newStr;
        }
        
        //other cases
        string newStr = "";
        int middle = numRows - 2;
        int aBatch = numRows + middle;
        for(int i = 0; i<numRows; i++){
            if(i==0||i==numRows-1){
                for(int j = i; j < s.length(); j+=aBatch){
                    newStr += s[j];
                }
            }else{
                for(int j = i; j < s.length(); j+=aBatch){
                    int diff = aBatch - 2*(i%aBatch);
                    newStr += s[j];
                    if(j+diff<s.length())newStr += s[j+diff];
                }
            }
        }
        return newStr;
    }
};
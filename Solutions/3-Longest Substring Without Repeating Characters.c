//Solved:11/5/2021

//Runtime: 4ms 85.27%
//MU: 5.9MB 48.80%

//Note:
//  Approach: Sliding Window
//  Improve: Use HashTable (ASCII) to check if char duplicates instead of looping to check

int lengthOfLongestSubstring(char * s){
    if(s==NULL || *s=='\0')return 0;
    
    char *temp=s;
    char *start=s;
    int find,max,count;
    max=0;
    count=0;
    while(*s!='\0'){
        find=0;
        temp=start;
        while(temp!=s){
            if(*temp==*s){
                find=1;
                break;
            }
            temp++;
        }
        if(find==1){
            start=temp+1;
            count=s-start;
        }
        s++;
        count++;
        if(count>max)max=count;
    }
    return max;
}

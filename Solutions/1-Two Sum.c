//Solved:8/5/2021

//Note:
//  One-pass Hash Table: only go through the number array once. Search before insert.

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    //One-pass Hash Table
    ///////////////////////////
    
    int HashSize=10;
    int i,comp,temp;
    typedef struct hashslot{
        int value;
        int index;
        struct hashslot* next;
    }HashSlot;
    HashSlot** HashList=malloc(HashSize*sizeof(HashSlot*));
    for(i=0;i<HashSize;i++){
        HashList[i]=NULL;
    }
    
    HashSlot* cur;
    for(i=0;i<numsSize;i++){
        comp=target-nums[i];
        temp=comp%10;
        //printf("&%d\n",temp);
        if(temp<=0) cur=HashList[temp+10-1];
        else cur=HashList[temp-1];
        while(cur!=NULL){
            if(cur->value==comp){
                int* answer=malloc(2*sizeof(int));
                answer[0]=cur->index;
                answer[1]=i;
                *returnSize=2;
                return answer;
            }
            
            cur=cur->next;
            }
        temp=nums[i]%10;
        if(temp<=0)temp=temp+10;
        cur=HashList[temp-1];
        
        if(cur==NULL) {
            HashList[temp-1]=malloc(sizeof(HashSlot));
            cur=HashList[temp-1];
        }
        else {
            while(cur->next!=NULL){
            cur=cur->next;
            }
            cur->next=malloc(sizeof(HashSlot));
            cur=cur->next;
        }
        cur->value=nums[i];
        cur->index=i;
        cur->next=NULL;
    }
    *returnSize=0;
    return NULL;
    
    
    //Brute Force
    ///////////////////////////
    
    // int* result=malloc(2*sizeof(int));
    // int i,j;
    // for(i=0;i<numsSize;i++){
    //     for(j=i+1;j<numsSize;j++){
    //         if((nums[i]+nums[j])==target){
    //             result[0]=i;
    //             result[1]=j;
    //             *returnSize=2;
    //             return result;
    //         }
    //     }
    // }
    // *returnSize=0;
    // return NULL;
}

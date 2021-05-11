//Solved:9/5/2021

//Runtime: 12ms 78.46%
//MU: 7.8MB 50.04%

//Note:
//  Approach: Elementary Math
//  Follow up: What if the the digits in the linked list are stored in non-reversed order?
//        idea: start from back of the list

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* answer=malloc(sizeof(struct ListNode));
    struct ListNode* temp1=l1;
    struct ListNode* temp2=l2;
    struct ListNode* temp=answer;
    int sum,op1,op2,car,first;
    car=0;
    first=1;
    
    while(temp1!=NULL||temp2!=NULL){
        if(first!=1){
            temp->next=malloc(sizeof(struct ListNode));
            temp=temp->next;
            }
        else first=0;
        
        if(temp1==NULL)op1=0;
        else op1=temp1->val;
        if(temp2==NULL)op2=0;
        else op2=temp2->val;
        
        sum=op1+op2+car;
        if(sum>=10){
            sum-=10;
            car=1;
        }
        else car=0;
        
        temp->val=sum;
        temp->next=NULL;
        
        if(temp1!=NULL)temp1=temp1->next;
        if(temp2!=NULL)temp2=temp2->next;
    }
    if(car==1){
        temp->next=malloc(sizeof(struct ListNode));
        temp->next->val=1;
        temp->next->next=NULL;
    }
    return answer;
}

//Solved:12/5/2021

//Runtime: 8ms 97.53%
//MU: 6.6MB 42.53%

//Note:
//  Approach: Moving on while comparing. Find the middle number directly.

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result;
    int cot1=0;
    int cot2=0;
    int odd,mid,sum,i,flag=0;
    sum=nums1Size+nums2Size;
    mid=(sum)/2;
    if(sum%2!=0)odd=1;
    else odd=0;
    mid+=odd;

    for(i=0;i<mid;i++){
        if(cot1==(nums1Size)&&cot2!=(nums2Size)){
            cot2++;
            flag=1;
        }
        else if(cot2==(nums2Size)&&cot1!=(nums1Size)){
            cot1++;
            flag=0;
        }
        else{
            if(nums1[cot1]>=nums2[cot2]){
                cot2++;
                flag=1;
            }
            else {
                cot1++;
                flag=0;
            }
        }
    }
    printf("$\n");
    printf("%d\n",cot1);
    printf("%d\n",cot2);
    if(odd==1){
        if(flag==0)result=nums1[cot1-1];
        else result=nums2[cot2-1];
    }
    else{
        int num1,num2;
        if(flag==0)num1=nums1[cot1-1];
        else num1=nums2[cot2-1];
        printf("$\n");
        if(cot1==(nums1Size))num2=nums2[cot2];
        else if(cot2==(nums2Size))num2=nums1[cot1];
        else{
            if(nums1[cot1]>=nums2[cot2])num2=nums2[cot2];
            else num2=nums1[cot1];
        }
        result=((double)num1+(double)num2)/2;
        
    }
    return result;
}

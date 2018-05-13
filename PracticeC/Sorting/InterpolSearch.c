//
//  InterpolSearch.c
//  PracticeC
//
//  Created by KimJoong Seon on 2018. 5. 11..
//  Copyright © 2018년 KimJoong Seon. All rights reserved.
//

#include <stdio.h>

int ISearch(int ar[], int first, int last, int target)
{
    int mid;
    
    
    //if(first > last) return -1;
    if(target<ar[first] || target>ar[last]) return -1; // changed limit
    
    mid = ((double)(target-ar[first]))/(ar[last]-ar[first])*(last-first) + first;
    
    if(ar[mid] == target) return mid;
    
    else if(target<ar[mid]) return ISearch(ar, first, mid-1, target);
    
    else return ISearch(ar, mid+1, last, target);
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;
    
    
    idx= ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
    
    if(idx==-1) printf("Failed to Search ! \n");
    
    else printf("Result Index : %d \n", idx);
    
    return 0;
}

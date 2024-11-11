
from collections import Counter
from math import *
import sys

import bisect as bs
from math import *
mod=1000000007

def help(arr,i,j):

    while(i<j):
        arr[i]=arr[i]&arr[j]
        arr[j]= arr[j]&arr[i]
        i+=1
        j-=1
    
def pro(arr):
    n=len(arr)

    for i in range(n):
        ind=0
        maxi=-1
        for j in range(n):
            if(maxi<arr[j]):
                maxi=arr[j]
                ind=j
        mini=arr[ind]
        ind2=0
        for j in range(n):
            if(mini> arr[ind]&arr[j] ):
                mini = arr[ind]&arr[j]
                ind2= j
        #print(arr[ind],ind,ind2)
        help(arr,min(ind,ind2),max(ind,ind2))
    print(max(arr))

t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,input().split()))
    pro(arr)

    
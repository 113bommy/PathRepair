t=int(input())
for _ in range (t):
    n,sum=int(input()),0
    arr=[int(i) for i in input().split()]
    for i in range (n):
        sum=sum+arr[i]
    arr.sort()
    if(arr[n-1]*2>sum):print('T')
    else:
        if(sum%2):print('T')
        else:print('HL')
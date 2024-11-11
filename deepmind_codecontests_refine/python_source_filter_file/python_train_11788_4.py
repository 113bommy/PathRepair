# -*- coding: utf-8 -*-
"""
Created on Sun Jan  5 22:03:30 2020

@author: B JAGDISH REDDY
arr=[int(i) for i in input().split(" ")]
    a=[]
    k=0
    if(sum(arr)%2==1):
        print("YES")
    else:
        for i in range(n):
            if arr[i]%2==1:
                a.append(arr[i])
        for i in range(n):
            if arr[i]%2==0:
                k=i
                break
        if(len(a)!=0):    
            arr[k]=a[0]
        if(sum(arr)%2==1):
            print("YES")
        else:
            print("NO")
                        
"""
t=int(input())
for i in range(t):
    s=input()      
    n=0
    prev=0
    c=0
    for j in range(len(s)):
        if(s[j]=='1'):
            prev=j
            break
    n=prev
    cur=prev
    for j in range(n+1,len(s)):
        if(s[j]=='1'):
            if(j-prev==1):
                prev=j
            else:
                n=j-cur-1
                c=c+n
                cur=j
    print(c)
    
                
import sys
import math as mt
input=sys.stdin.buffer.readline  
t=int(input())
#t=1
for __ in range(t):
    #n,x=map(int,input().split())
    n=int(input())
    l=list(map(int,input().split()))
    ans=[]
    ans.append(l[0])
    for i in range(1,n-1):
        if l[i-1]<l[i]and l[i]<l[i+1]:
            continue
        if l[i-1]>l[i] and l[i]>l[i+1]:
            continue
        ans.append(l[i])
    if len(l)>1:
        ans.append(l[-1])
    print(len(l))
    print(*ans)
            
            
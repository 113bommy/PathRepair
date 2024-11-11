from collections import *
from math import *


TT=int(input())
for y in range(TT):
    #n=int(input())
    n,m=map(int,input().split())
    lst=list(map(int,input().split()))
    #s=input()
    d1=defaultdict(int)
    d2=defaultdict(list)
    ans=[0]*n
    for i in range(n):
        d1[lst[i]]+=1
        d2[lst[i]].append(i)
    
    cur=[]
    cl=0
    print(d1,d2,ans)
    for i in d1:
        if d1[i]>=m:
            for j in range(m):
                ans[d2[i][j]]=j+1
        else:
            for j in d2[i]:
                cur.append(j)
                cl+=1
                if cl==m:
                    for lp in range(m):
                        ans[cur[lp]]=lp+1
                    cur=[]
                    cl=0
                
    print(*ans)
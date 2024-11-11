import sys
from math import gcd
from bisect import bisect_left as br
from collections import Counter as CO
from collections import defaultdict as dd
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,kk=map(int,input().split())
    word=list(map(str,input().strip()))
    df=dd(int)
    fact=[]
    
    for k in word:
        df[k]+=1
    #print(df)

    ans=0
    for i in range(1,kk+1):
        maxi=0
        x=0
        co=0
        for j in df:
            if(df[j]//i!=0):
                maxi+=df[j]//i
      
        #rint(maxi)
        if(maxi==0):
            break
        for j in range(maxi,0,-1):
            if(kk%j==0 ):
                maxi=j
                break
        ans=max(ans,maxi*i)
                
            
        
        #print(i,maxi)
    print(ans)
            
        
    
        
    
    
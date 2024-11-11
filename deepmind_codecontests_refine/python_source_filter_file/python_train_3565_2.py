import math
from sys import stdin,stdout
#% 998244353
from heapq import heapify,heappop,heappush

from collections import Counter
T = int(stdin.readline())
for i in range(T):
    #N=int(stdin.readline())
    N,K=list(map(int,stdin.readline().split()))
    s=stdin.readline()
    s=list(s[:-1])
    pre=[0]*N
    pre[0]=ord(s[0])-ord('0')
    for i in range(1,N):
        pre[i]+=pre[i-1]+ord(s[i])-ord('0')

    #print(pre)
    ans=pre[-1]
    dp=[0]*N
    #pre=[0]+pre
    for r in range(N-1,-1,-1):
        cnt1=0
        cnt2=0
        #for j in range(r+1,min(r+K,N)):
        if  r:
            cnt1=pre[-1]-pre[r-1]
        else:
            cnt1=pre[-1]
        
        pos=min(r+K-1,N-1)
        
        
        cnt2=pre[pos]-pre[r]

        if s[r]=='0':
            cnt2+=1
        


        #print(cnt1,cnt2,r)
        if r+K<N:
            dp[r]=min(cnt1,cnt2)+dp[r+K]
        else:
            dp[r]=min(cnt1,cnt2)
    
    for i in range(1,N):
        #if s[i]=='1':
       dp[i]+=pre[i-1]
    print(min(dp))
   # print(dp)

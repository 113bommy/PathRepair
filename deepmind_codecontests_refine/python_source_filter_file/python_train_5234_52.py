from collections import defaultdict as dd
import sys
input=sys.stdin.readline
t=int(input())
while t:
    #n=int(input())
    n,s=input().split()
    s=int(s)
    nn=int(n)
    n=list(map(int,n.strip()))
    #nn=list(n)
    i=len(n)-1
    su=sum(n)
    ans=0
    po=1
    num=0
    if(su==s):
        print(0)
    else:
        while i>=0 and su+1>=s:
            su-=n[i]
            po=po*10
            num=num+n[i]*(po//10)
            ans=po-num
            #print(po,num)
            i-=1
        print(ans)
    t-=1
    
    
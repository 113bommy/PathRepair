import sys     
import math as mt
import bisect
#input=sys.stdin.readline
#t=int(input())
t=1
s1="LRUD"
dx=[-1,1,0,0]
dy=[0,0,1,-1]
def solve():
    ans=10**18
    l,r=0,10**18
    while r-l>1:
        mid=(l+r)//2
       
        rem=mid%(n)
        
        X=x1+px[rem]+(mid//n)*px[n]
        Y=y1+py[rem]+(mid//n)*py[n]
   
        if abs(X-x2)+abs(Y-y2)<=mid:
            #print(px[n],x2,abs(Y-y2),mid)
            ans=min(ans,mid)
            r=mid
        else:
            l=mid
        
    if ans==10**18:
        return -1
    return ans    
                                
for _ in range(t):
    #n=int(input())
    #n1=n
    #a=int(input())
    #b=int(input())
    x1,y1=map(int,input().split())
    x2,y2=map(int,input().split())
    n=int(input())
    #n,h=(map(int,input().split()))
    #l=list(map(int,input().split()))
    #l2=list(map(int,input().split()))
    #l=str(n)
    #l.sort(reverse=True)
    s=input()
    px=[0]*(n+1)
    py=[0]*(n+1)
    #print(s1)
    for i in range(n):
        for j in range(4):
            if s[i]==s1[j]:
                ind=j
                break
        px[i+1]=(px[i]+dx[ind])
        py[i+1]=(py[i]+dy[ind])
    
    print(solve())    
        
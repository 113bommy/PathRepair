import sys
import math as mt
input=sys.stdin.buffer.readline  
t=1
def check(x1):
    prev=0
    #print(x1,m)
    for i in range(n):
        #print(111,prev,i,arr[i],)
        if arr[i]>prev:
            x=m-(arr[i]-prev)
            if x>x1:
                prev=arr[i]
        if arr[i]<prev:
            x=(prev-arr[i])
            if x>x1:
                return False
    return True                
                    
        
#t=int(input())
for _ in range(t):
    #n=int((input())
    n,m=map(int,input().split())
    arr=list(map(int,input().split()))
    l,r=0,m
    ans=m    
    while (1<r-l):

        mid=(l+r)//2
        #print(l,r,mid,check(mid))
        if (check(mid)):
            ans=min(ans,mid)
            r=mid-1
        else:
            l=mid+1
    if (check(ans-1)):
        ans-=1
    print(ans)        
        
        
            
import math as mt
import bisect
import sys
input=sys.stdin.readline
t=int(input())
import collections 
import heapq
#t=1
p=10**9+7
def ncr_util():
    inv[0]=inv[1]=1
    fact[0]=fact[1]=1
    for i in range(2,300001):
        inv[i]=(inv[i%p]*(p-p//i))%p
    for i in range(1,300001):
        inv[i]=(inv[i-1]*inv[i])%p
        fact[i]=(fact[i-1]*i)%p

    
def solve(x,y):
    for i in range(36):
        l[1]=min(l[1],l[2]+l[6])
        l[2]=min(l[2],l[1]+l[3])
        l[3]=min(l[3],l[2]+l[4])        
        l[4]=min(l[4],l[3]+l[5])
        l[5]=min(l[5],l[4]+l[6])
        l[6]=min(l[6],l[1]+l[5])
    if x==0 and y==0:
        return 0
    ans=0
    if x>0 and y>0:
        mini=min(x,y)
        x-=mini
        y-=mini
        ans+=mini*(l[1])
        if y>0:
            ans+=y*(l[2])
        else:
            ans+=x*(l[6])
    elif x<0 and y<0:
        x=abs(x)
        y=abs(y)
        mini=min(x,y)
        x-=mini
        y-=mini
        ans+=mini*(l[4])
        if y>0:
            ans+=y*(l[5])
        else:
            ans+=x*(l[3])
    elif x>0 and y<0:
        ans+=abs(x)*l[6]
        ans+=abs(y)*l[5]
    else:
        ans+=abs(y)*l[2]
        ans+=abs(x)*l[3]
    return ans    
        
for _ in range(t):
    #n=int(input())
    
    #s=input()
    #n=int(input())
    x,y=(map(int,input().split()))
    #n1=n
    #a=int(input())
    #b=int(input())
    #n,k,x=map(int,input().l.insert(0,0)
    l=list(map(int,input().split()))
    l.insert(0,0)
    #a,b=map(int,input().split())
    #n=int(input())
    #s=input()
    #s1=input()
    #p=input()
    #l=list(map(int,input().split()))
    #l.sort(revrese=True)
    #l2=list(map(int,input().split()))
    #l=str(n)
    #l.sort(reverse=True)
    #l2.sort(reverse=True)
    #l1.sort(reverse=True)
    #print(ans)
    print(solve(x,y))           
        
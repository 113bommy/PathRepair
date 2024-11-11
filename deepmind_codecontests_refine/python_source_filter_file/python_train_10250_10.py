from sys import stdin,stdout
import math
import collections
input=stdin.readline
def print(x='',end='\n'):
    stdout.write(str(x)+end)

def solve():
    n,k=map(int,input().split())
    l=list(input())
    d={}
    for i in l:
        if i in d:
            d[i]+=1
        else:
            d[i]=1

    
    d=[[k,v] for k,v in d.items()]
    d.sort(key=lambda x:x[1],reverse=True)

    if d[0][1]>=k:
        print(k*d[0][1])
        return
    ans=d[0][1]*d[0][1]
    k-=d[0][1]
    i=1
    while k!=0:
        if k-d[i][1]<0:
            ans+=k*k
            k-=k
        else:
            k-=d[i][1]
            ans+=d[i][1]*d[i][1]
        i+=1
            
    print(ans)


tt=1
#tt=int(input())
for __ in range(tt):
    solve()

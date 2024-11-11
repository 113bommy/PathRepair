from sys import stdin,stdout
import math
input=stdin.readline
def print(x='',end='\n'):
    stdout.write(str(x)+end)

def solve():
    n,x=map(int,input().split())
    l=list(map(int,input().split()))

    pref=[0]*(n)
    pref[0]=l[0]
    for i in range(1,n):
        pref[i]=pref[i-1]+l[i]
        
    suf=[0]*n
    suf[n-1]=l[n-1]
    for i in range(n-2,-1,-1):
        suf[i]+=suf[i+1]+l[i]
    ans1,ans2=-1,-1
    for i in range(n-1,-1,-1):
        if pref[i]%x!=0:
            ans1=i+1
            break
    
    for i in range(n):
        if suf[i]%x!=0:
            ans2=i+1
            break

    print(max(ans1,ans2))
        


tt=1
tt=int(input())
for __ in range(tt):
    solve()

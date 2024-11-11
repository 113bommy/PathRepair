#Consistency is the key :)
#code by: amrit2000
from sys import stdin,stdout
import math
import bisect
input=stdin.readline
def print(x='',y='',end='\n'):
    if y=='':
        stdout.write(str(x)+end)
    else:
        stdout.write(str(x)+' '+str(y)+end)

def solve():
    n,m,d=map(int,input().split())
    l=[]
    for i in range(n):
        l.extend(list(map(int,input().split())))

    l.sort()
    c=l[0]%d
    for i in range(n*m):
        if l[i]%d!=c:
            print(-1)
            return
    
    ans=0
    minn=10**12
    for i in range(m*n):
        cur=0
        for j in range(m*n):
            cur+=abs(l[j]-l[i])//d

        minn=min(cur,minn)

    print(minn)
    
        
tt=1
#tt=int(input())
for __ in range(tt):
    solve()

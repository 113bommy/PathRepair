from sys import stdin,stdout
from collections import Counter
nmbr=lambda:int(stdin.readline())
lst=lambda:list(map(int,stdin.readline().split()))
def pos(n):
    t=0
    for k,v in d.items():
        if v>=n:t+=v//n
    return t>=p
for _ in range(1):#nmbr())
    p,n=lst()
    d=Counter(lst())
    ans=0
    for sel in range(1,n+1):
         if pos(sel):ans=max(ans,sel)
    print(ans)
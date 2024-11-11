n,m=map(int,input().split())
l=list(map(int,input().split()))
pre=0
for i in range(n):
    pre=(pre+l[i])%m
    l[i]=pre

from collections import Counter as co
c=co(l)
print(sum(i*(i-1)//2 for i in c.values())+(c[0] if 0 in c else 0))
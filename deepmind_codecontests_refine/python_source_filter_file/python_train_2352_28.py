import math
ans=[]
s=[]
n,m,k=map(int,input().split())
l=list(map(int,input().split()))
for i in l:
    if i>0 and i<=k: s+=[i]
for i in range(n):
    for x in s:
        if l[i]==x: ans+=[math.fabs(i-m)]
print(int((min(ans)+1)*10))
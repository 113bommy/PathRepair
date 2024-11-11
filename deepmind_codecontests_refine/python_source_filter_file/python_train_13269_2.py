n=int(input())
l=[int(i) for i in input().split()]
l.sort()
#cnt=l.count(1)
from collections import Counter 
c=Counter(l)
prev=c[1]
cnt=c[1]
f=1 
from collections import defaultdict 
d=defaultdict(list)
for i in range(n):
    d[l[i]].append(i)
for i in range(2,max(l)+1):
    if c[i]>prev:
        f=0 
        break 
    prev=c[i]
if any(c[i]==0 for i in range(1,max(l)+1)):
    print(-1)
    exit()
if not f:
    print(-1)
    exit()
l=[[] for i in range(10**5+3)]
for i in range(n,0,-1):
    if c[i]>0:
        for j in range(c[i]):
            l[j].append(d[i].pop())
print(cnt)
#print(l)
ans=[0]*n 
for i in range(len(l)):
    for j in range(len(l[i])):
        ans[l[i][j]]=i+1 
print(*ans)
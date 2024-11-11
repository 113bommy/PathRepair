n,m=map(int,input().split())
l=[input() for _ in range(n)]
from collections import Counter
s=[]
k=0
for i in range(n):
    if 'S' not in l[i]:
        k=k+1
    for j in range(m):
        if l[i][j]=='S':
            s.append(j+1)
x=len(Counter(s))
print(k*m+(m-x)*n-k*(m-x))
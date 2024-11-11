n=int(input())
f=[list(map(int,input().split())) for _ in range(n)]
p=[list(map(int,input().split())) for _ in range(n)]
from itertools import product as pr
x=0
for ch in list(pr([0,1],repeat=10)):
  if 1 not in ch:
    continue
  s=0
  for j in range(n):
    c=0
    t=f[j]
    for k in range(10):
      if ch[k] and t[k]:
        c+=1
    s+=p[j][c]
  x=max(x,s)
print(x)
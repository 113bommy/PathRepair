import sys
input = sys.stdin.readline
f = lambda:map(int,input().split())
d,g = f()
g//=100
ll = []
for i in range(d):
  p,c = f()
  ll.append([i+1,p,c//100])
ll = ll[::-1]
import itertools as it
ans = 10**9
for t in it.product(range(2),repeat=d):
  cnt = 0
  tot = 0
  flg = 1
  lg = [1,0]
  for i,b in enumerate(t):
    u,p,c = ll[i]
    if b:
      cnt += p
      tot += u*p+c
    elif flg:
      lg = [u,p]
      flg = 0
  if g <= tot+lg[0]*lg[1]:
    ans=min(ans,cnt+max(g-tot,0)//lg[0])
print(max(ans,1))
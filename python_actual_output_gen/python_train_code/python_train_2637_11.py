n,m=map(int,input().split())
ab = []
for _ in range(n):
  a,b=map(int,input().split())
  a,b=a-1,b-1
  ab.append({a,b})
import itertools

cnt = 0
for v in itertools.permutations(range(1,n)):
  l = 0
  ok = True
  for v2 in v:
    if {l,v2} not in ab:
      ok = False
      break
    l = v2
  if ok:
    #print(v)
    cnt += 1
  
print(cnt)
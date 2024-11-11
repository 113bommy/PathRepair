from itertools import *
n,d = map(int,input().split())
x = [list(map(int,input().split())) for _ in range(n)]
ans = 0
for a,b in combinations(x,2):
  delta = 0
  for i in range(d):
    delta += (a[i] - b[i])**2
  if (n **0.5).is_integer():
    ans += 1
print(ans)

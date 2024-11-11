import sys
from collections import defaultdict

N, X, D = map(int, input().split())

if D == 0:
  print(1 if D == 0 else N + 1)
  sys.exit()

if D < 0:
  X *= -1
  D *= -1

dic = defaultdict(list)

for i in range(N + 1):
  l = X*i + i*(i-1)//2*D
  r = X*i + (N-1+N-1-(i-1))*i//2*D
  dic[l % D].append((l // D, r // D + 1))

ans = 0
for v in dic.values():
  v.sort()
  ima = -10**100
  for l, r in v:
    if ima < l:
      ans += r - l
      ima = r
    elif r > ima:
      ans += r - ima
      ima = r
print(ans)


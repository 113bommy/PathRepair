from collections import defaultdict

N = int(input())
xy = [list(map(int,input().split())) for _ in range(N)]
if N == 1:
  print(1)
else:
  d = defaultdict(int)
  for i in range(N):
    xi,yi = xy[i]
    for j in range(N):
      if i==j:
        continue
      else:
        xj,yj = xy[j]
      d[(xj-xi,yj-yi)] += 1
max_v = max(d.values())
print(N-max_v)


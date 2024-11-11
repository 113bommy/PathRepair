import math

n = int(input())
arr = list(map(int, input().split()))
seen = set()
d = dict(zip(arr, range(n)))
l, r = 0, n-1
curr_min = math.inf
for k in sorted(d)[:n-1]:
  pos = d[k]
  further_pos = []
  if pos != l:
    further_pos.append(abs(pos-l))
  if pos != r:
    further_pos.append(abs(r-pos))
  curr_min = min(curr_min, k//min(further_pos))
  if pos == l:
    seen.add(l)
    while l <= n-1 and l in seen:
      l += 1
  if pos == r:
    seen.add(r)
    while r >= 0 and r in seen:
      r -= 1

print(curr_min)

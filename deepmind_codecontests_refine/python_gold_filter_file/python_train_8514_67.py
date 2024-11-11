from bisect import bisect_right
s = input()
n = len(s)
t = input()
m = len(t)
tr = set(s)
for c in t:
  if c not in s:
    print(-1)
    exit(0)
d = {c:[] for c in 'abcdefghijklmnopqrstuvwxyz'}
for i, c in enumerate(s):
  d[c].append(i)
idx = -1
ans = 0
for c in t:
  tmp = bisect_right(d[c], idx)
  if tmp == len(d[c]):
    idx = d[c][0]
    ans += 1
  else:
    idx = d[c][tmp]
print(ans * n + idx + 1)

import sys
n, k = map(int, sys.stdin.readline().split())
joy = -k
for _ in range(n):
  f, t = map(int, sys.stdin.readline().split())
  if t <= k:
    joy = max(joy,f)
  else:
    joy = max(joy,f-(t-k))
print(joy)

N, T = map(int, input().split())

r = 1001
for _ in range(N):
  c, t = map(int, input().split())
  if t <= T:
    r = min(c, r)
print (r if r<1001 else "TLE")
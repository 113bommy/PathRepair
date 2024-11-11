n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = float('inf')
for bit in range(1<<(n-1)):
  cand = [0]*(n-1)
  for i in range(n-1):
    if bit & 1<<i: cand[i] = 1
  if cand.count(1) != k-1: continue
  cost = 0
  mx = a[0]
  for i in range(1, n):
    if cand[i-1]:
      if a[i] <= mx:
        cost += mx-a[i]+1
        mx += 1
    mx = max(mx, a[i])
  ans = min(ans, cost)
print(ans)
n, k, s = map(int, input().split())
if s!=10**9:
  l = [s] * k + [s+1] * (n-k)
else:
  l = [s] * k + [s-1] * (n-k)
print(l)
n, k, H = map(int, open(0).read().split())
H.sort()
ans = 10 ** 10
for h0, h1 in zip(H, H[k-1:]):
  ans = min(ans, h1-h0)
print(ans)
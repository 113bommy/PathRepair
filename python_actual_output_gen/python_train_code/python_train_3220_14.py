N, K = map(int,input().split())
X = list(map(int,input().split()))

ans = 1e9
for l, r in zip(X, X[K:]):
  ans = min(ans, r-l+min(abs(l),abs(r)))
print(ans)
N, K = map(int, input().split())
p = list(map(int, input().split()))

tmp = sum(p[0:K])
ans = 0
for i in range(N-K):
  tmp = tmp + p[i+K]-p[i]
  ans = max(ans, tmp)
print ((ans+K)/2)
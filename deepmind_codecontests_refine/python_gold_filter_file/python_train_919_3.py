from itertools import accumulate as acc
N, K, *A = map(int, open(0).read().split())
B = [0]+list(acc(A))
M = list(acc(a if a>0 else 0 for a in A))
ans = -10**30
s = sum(A)
for i in range(N-K+1):
  mi = B[i+K]-B[i]
  c = M[N-1] - M[i+K-1]
  if i>0:
    c += M[i-1]
  ans = max(ans,mi+c,c)
print(ans)
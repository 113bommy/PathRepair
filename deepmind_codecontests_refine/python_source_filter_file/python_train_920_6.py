from itertools import accumulate as acc
N, x, *A = map(int, open('0').read().split())
dp = []
for i in range(N):
  dp.append(list(acc((A[(i-j)%N] for j in range(N)),min)))

ans = 10**10
for i,a in enumerate(zip(*dp)):
  ans = min(ans,i*x+sum(a))
print(ans)
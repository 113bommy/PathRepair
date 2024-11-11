import collections
N=int(input())
S=[''.join(sorted(input())) for _ in range(N)]
C=collections.Counter(S)
ans=0
for si in S:
  n=C[si]
  ans+=n*(n-1)//2
print(ans)
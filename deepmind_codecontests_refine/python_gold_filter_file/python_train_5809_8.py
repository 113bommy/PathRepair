from bisect import bisect_left
from itertools import accumulate
N,M,*A = map(int, open(0).read().split())
A.sort()
B = list(accumulate(A[::-1]))
l = -1
r = 10**9
while l+1<r:
  s = (l+r)//2
  cnt = 0
  for c in A:
    i = bisect_left(A,s-c)
    cnt += N-i
  if cnt>=M:
    l = s
  else:
    r = s
ans = 0
for c in A:
  i = bisect_left(A,r-c)
  M -= N-i
  if i<N:
    ans += B[N-1-i]+c*(N-i)
ans += M*l
print(ans)
n=int(input())
a=[int(input()) for _ in range(n)]
ans=[a[0]]
ansl=1
from bisect import bisect_right
for ai in a[1:]:
  tmp=bisect_right(ans,ai)
  if tmp<ansl:
    ans[tmp]=ai
  else:
    ans.append(ai)
    ansl+=1
print(ansl)
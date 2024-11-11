import bisect
import collections
n=int(input())
a=sorted(list(map(int,input().split())))
q=int(input())
A=collections.Counter(a)
ans=sum(a)
for _ in range(q):
  b,c=map(int,input().split())
  k=A[b]
  ans=(c-b)*k+ans
  print(ans)
  del A[b]
  A[c]=k
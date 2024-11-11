import collections
n=int(input())
ans=0
s=["".join(sorted(input())) for _ in range(n)]
c=collections.Counter(s)
for i in set(s):
  a=c[s]
  ans+=a*(a-1)//2
print(ans)


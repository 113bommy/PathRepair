n=int(input())
l=[]
import collections
for _ in range(n):
  l.append(str(input()))
c = collections.Counter(l)
m=max(c.items())[1]
for i in sorted(c):
  if c[i]==m:
    print(i)
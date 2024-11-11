from collections import Count
s = input()
n = len(s)
d = Count(s)
c = 0
for x in d:
  c += d[x]*(d[x]-1)//2
print(n*(n-1)//2 - c)
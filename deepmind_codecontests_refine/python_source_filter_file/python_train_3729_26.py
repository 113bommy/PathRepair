import collections
import bisect
n,m = map(int, input().split())
p = [list(map(int,input().split())) for i in range(m)]
a = collections.defaultdict(list)
for x,y in sorted(p):
  a[x]+=[y]
for x,y in p:
  print("%06d%06d"%(x,bisect.bisect(a[x],y))
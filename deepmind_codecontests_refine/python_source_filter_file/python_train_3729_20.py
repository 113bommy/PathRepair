import collections
import bisect

N, M = map(int, input().split())
P = [list(map(int, input().split())) for i in range(M)]

ans = collections.defaultdict(list)

for p, y in sorted(P):
    ans[p] += [y]
for p, y in P:
    print("%06d%06d"%(p, bisect.bisect(a[p], y)))
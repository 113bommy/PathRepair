n = int(input())
p = [str(input()) for _ in range(n)]
import collections
c = collections.Counter(p)
m = max(c.values())
keys = [k for k, v in d.items() if v == m]
keys.sort()
for i in keys:
    print(i)
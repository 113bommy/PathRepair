n, k = map(int, input().split())
A = list(map(int, input().split()))

import collections
c = collections.Counter(A)
print(c)
if len(c.keys()) > k:
    num = len(c.keys()) - k
    print(sum(sorted(c.values())[:num]))
else:
    print(0)
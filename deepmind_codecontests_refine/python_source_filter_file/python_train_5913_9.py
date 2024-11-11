from itertools import accumulate
from collections import Counter
n, k, *a = map(int, open(0).read().split())
a = [x % k - 1 for x in a]
a = [0] + [x % k for x in accumulate(a)]
d = Counter()
ans = 0
for l, r in zip([k] * min(k, n) + a, a):
	d[l] -= 1
	ans += d[r]
	d[r] += 1
print(ans)

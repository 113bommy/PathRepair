from collections import defaultdict
from bisect import bisect_right

s = input()
t = input()
idxs = defaultdict(list)

for i, c in enumerate(s):
    idxs[c].append(i)
for i, c in enumerate(s):
    idxs[c].append(len(s) + i)

ans, cur_i = 0, 0
for c in t:
    if c not in idxs: print(-1); break
    a = idxs[c]
    nxt = a[bisect_right(a, cur_i)]
    ans += nxt - cur_i
    cur_i = nxt % len(s)
else: print(ans+1)

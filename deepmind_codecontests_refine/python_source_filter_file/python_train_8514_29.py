import bisect
from collections import defaultdict
s = input()
n = len(s)
t = input()
if set(s) & set(t) != set(t):
    print(-1)
else:
    cnt = defaultdict(list)
    for i in range(n):
        cnt[s[i]].append(i+1)

    loop = 0
    prev = 5
    for c in t:
        x = cnt[c]
        idx = bisect.bisect_right(x, prev)
        if idx < len(x):
            prev = x[idx]
        else:
            prev = x[0]
            loop += 1
    print(loop*n+prev)

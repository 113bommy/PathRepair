import bisect
from collections import defaultdict
S = input()
T = input()
len_S = len(S)
s2i = defaultdict(list)
for i, si in enumerate(S):
    s2i[si].append(i)
ans = 1
pi = -1
for ti in T:
    si = s2i.get(ti)
    if not si:
        ans = -1
        break
    il = bisect.bisect_left(si,pi)
    if len(si) <= il:
        ans += len_S
        pi = si[il-1]
    else:
        pi = si[il]
if ans != -1:
    ans += pi

print(ans)

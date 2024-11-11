#!/usr/bin/env python3

from collections import deque
n, k = list(map(int, input().split()))

td = [list(map(int, input().split())) for i in range(n)]

td = sorted(td, key=lambda x: x[1], reverse=True)

set_ = set()
val = 0
duplicated = deque([])

for t_tmp, d_tmp in td[:k]:
    val += d_tmp
    if t_tmp in set_:
        duplicated.append(d_tmp)
    else:
        set_.add(t_tmp)

now = val + len(set_)**2


nx = deque(td[k:])
ans = now
c = len(set_)
while len(set_) < k and nx:
    i, j = nx.popleft()
    if i in set_:
        continue
    d = duplicated.pop()
    diff = j-d + 2 * c + 1
    set_.add(i)
    ans = max(now, now + diff)
    now += diff
    c += 1
print(ans)

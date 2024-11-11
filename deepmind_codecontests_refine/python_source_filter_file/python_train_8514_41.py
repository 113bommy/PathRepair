sl = list(input())
tl = list(input())
n = len(sl)
from collections import defaultdict
dic = defaultdict(list)

for idx, s in enumerate(sl):
    dic[s].append(idx)
    dic[s].append(idx + n)

for s in dic:
    dic[s] = sorted(dic[s])

import bisect
ans = 1
now = 0
for t in tl:
    if dic[t] == []:
        print(-1)
        exit()
    idx = bisect.bisect_left(dic[t], now)
    ans += dic[t][idx] - now
    now = dic[t][idx]
    now %= n

print(ans)



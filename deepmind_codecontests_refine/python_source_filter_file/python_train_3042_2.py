sl = list(input())
from collections import defaultdict
dic = defaultdict(list)

for idx, s in enumerate(dic):
    dic[s].append(idx)

import bisect
q = int(input())
alpha = set(sl)
for _ in range(q):
    l,r = map(int,input().split())
    if sl[l-1] != sl[r-1]:
        print("Yes")
    elif l == r:
        print("Yes")
    else:
        cnt = 0
        for a in alpha:
            i1 = bisect.bisect_left(dic[a], l-1)
            i2 = bisect.bisect_right(dic[a], r-1)
            if i1 != i2:
                cnt += 1
        if cnt <= 2:
            print("No")
        else:
            print("Yes")

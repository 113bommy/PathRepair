# -*- coding: utf-8 -*-

import collections


"""
created by shhuan at 2018/11/16 23:01

"""

N, K = map(int, input().split())
S = [int(x) for x in input().split()]

wc = [(c, w) for w, c in collections.Counter(S).items()]
wc.sort(reverse=True)

lo, hi = 1, wc[0][0]

while lo <= hi:
    md = (lo + hi) // 2

    count = 0
    for c, w in wc:
        if c < md:
            break
        else:
            count += c // md
        if count >= K:
            break
    if count >= K:
        lo = md + 1
    else:
        hi = md - 1

lo -= 1
ans = []
for c, w in wc:
    if c < lo:
        break
    else:
        ans.extend([w] * (c//lo))
    if len(ans) >= K:
        break

print(' '.join(map(str, ans)))



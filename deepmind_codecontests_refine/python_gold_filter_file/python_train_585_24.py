#!/usr/bin/python3

def offcount(x, k, d):
    per = ((k + d - 1) // d) * d
    ans = (x // per) * (per - k)
    if x > (x // per) * per + k:
        ans += x - (x // per) * per - k
    return ans

k, d, t = map(int, input().split())
k *= 2
d *= 2
t *= 2

lt, rt = 0, 8 * 10 ** 18
while lt < rt - 1:
    mid = (lt + rt) // 2

    if 2 * mid - offcount(mid, k, d) >= 2 * t:
        rt = mid
    else:
        lt = mid

print(rt // 2, ".", "0" if rt % 2 == 0 else "5", sep="")

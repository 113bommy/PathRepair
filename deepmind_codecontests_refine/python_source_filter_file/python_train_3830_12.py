import bisect

n, k = map(int, input().split())
a = sorted(map(int, input().split()))

def count(t):
    c = 0
    for x in a:
        if x == 0:
            c += len(a) - 1 if t >= 0 else 0
        elif x > 0:
            c += bisect.bisect_right(a, (t // x)) - (x * x <= t)
        else:
            c += len(a) - bisect.bisect_left(a, -(t // -x)) - (x * x <= t)
    return c

lo = -1000000000000000001
hi = 1000000000000000001
while hi - lo > 1:
    mid = (lo + hi) // 2
    if count(mid) < k * 2:
        lo = mid
    else:
        hi = mid
print(hi)

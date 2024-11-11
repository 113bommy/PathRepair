n, m = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse=True)
s = [0]
for ai in a:
    s.append(ai + s[-1])

def count(x, accum=False):
    ret = 0
    for ai in a:
        lo, hi = -1, n
        while hi - lo > 1:
            mid = (lo + hi) // 2
            if ai + a[mid] >= x:
                lo = mid
            else:
                hi = mid
        ret += ai * hi + s[hi] if accum else hi
    return ret

lo, hi = 0, 1000000000
while hi - lo > 1:
    mid = (lo + hi) // 2
    if count(mid) >= m:
        lo = mid
    else:
        hi = mid
print(count(lo, accum=True) - (count(lo) - m) * hi)
n, c = map(int, input().split())
a = []
b = []
for i in range(n):
    aa, bb = map(int, input().split())
    a.append(aa)
    b.append(bb)

def all_zero():
    for aa in a:
        if aa > 0: return False
    return True

def days(x):
    c = 0
    for aa, bb in zip(a, b):
        c += 1 + aa*x//bb
    return c

def run():
    if n > c: return 0
    if all_zero(): return -1 if n == c else 0
    lo = 0
    hi = int(2e18)
    while lo < hi:
        mid = (lo + hi) // 2
        if days(mid) < c: lo = mid+1
        else: hi = mid
    if days(lo) != c: return 0
    ans0 = lo
    lo = 0
    hi = int(2e18)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if days(mid) > c: hi = mid-1
        else: lo = mid
    if days(lo) != c: return 0
    return lo - ans0 + 1

print(run())

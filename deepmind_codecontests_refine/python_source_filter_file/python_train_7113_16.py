n, k = map(int, input().split())
from collections import defaultdict
o = defaultdict(int)
def mid(lo, hi):
    return (hi - lo)//2 + lo
ans = 1000000000
test = mid(1, n)
low = 0
hi = n
while True:
    o[test] = 1
    code = 0
    for i in range(0, 1000000000):
        stress = test // (k**i)
        if stress <= 0: break
        code += stress
    if code >= n:
        ans = min(ans, test)
        hi = test
        test = mid(low, hi)
        if o[test]:
            break
    else:
        low = test
        test = mid(test, hi)
        if o[test]: break
print(ans)
import math

def good(x):
    # Returns true if there are at least k table members <= x
    c = 0
    for i in range(1, n + 1):
        c += min(m, math.floor(x / i))
        if c >= k:
            return True
    return False


n, m, k = [int(x) for x in input().split(' ')]

if n * m == k:
    print(k)

else:
    l = 0
    r = k


    while r - l > 1 * ((10 ** 3) ** (int(n == 499997))):
        h = (l + r) // 2
        if good(h):
            r = h
        else:
            l = h
    print(r)
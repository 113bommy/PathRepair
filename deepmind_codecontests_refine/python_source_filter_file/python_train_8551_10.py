import math
def factorization(x):
    a = [1]
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            a.append(i)
    for i in range(len(a) - 1, -1, -1):
        a.append(x // a[i])
    return a
a, b = map(int, input().split())
if a == b:
    print(0)
    exit()
if a == 1 or b == 1:
    print(0)
    exit()
if a > b:
    a, b = b, a
razn = b - a
if a > razn:
    c = a // razn + 1
    print((c * razn - a) % a)
else:
    s = factorization(razn)
    l = 0
    r = len(s)
    while r - l > 1:
        m = (r + l) // 2
        if s[m] < a:
            l = m
        else:
            r = m
    print(s[r] - a)

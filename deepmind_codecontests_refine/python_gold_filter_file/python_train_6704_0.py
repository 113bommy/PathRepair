n = eval(input())


def f(x):
    r = 0
    while x > 0 and x % 2 == 0:
        x //= 2
        r += x
    return r + x * (x - 1) // 2

k = -1
r = []
while True:
    g = lambda x: int(2 ** k) * (2 * x + 1)
    if f(int(2 ** k)) > n:
        break
    ub, lb = n, 0
    while (ub - lb) > 1:
        mid = (ub + lb) // 2
        if f(g(mid)) <= n:
            lb = mid
        else:
            ub = mid
    if f(g(lb)) == n:
        r.append(g(lb))
    k += 1

if len(r) > 0:
    print(*r, sep='\n')
else:
    print(-1)

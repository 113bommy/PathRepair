def f(p):
    d = 1
    for i in range(2, p + 1):
        d *= i
    return d

n, m = map(int, input().split())
l = list(map(int, input().split()))
if n == m:
    print(1)
else:
    l.sort()
    for i in range(m):
        l[i] -= 1
    k = []
    sm = n - m
    if l[0] > 1:
        k.append([l[0], 1])
    for i in range(1, len(l)):
        k.append([l[i] - l[i - 1] - 1, 2 ** (max(0, l[i] - l[i - 1] - 2))])
    if l[-1] < n - 1:
        k.append([n - 1 - l[-1], 1])
    ans = f(sm)
    for c in k:
        ans //= f(c[0])
    for c in k:
        ans *= c[1]
    print(ans % 1000000007)
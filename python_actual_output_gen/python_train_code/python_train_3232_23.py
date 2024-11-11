def solve():
    n, k, m = map(int, input().split(' '))
    a = [0] + sorted(map(int, input().split(' ')))
    for _ in range(1, n + 1):
        a[_] = a[_] + a[_ - 1]
    ans = 0
    for _ in range(min(n, m)):
        n_, m_ = n - _, m - _
        ans = max((a[-1] - a[_] + min(m_, k * n_)) / n_, ans)
    print("%.9f" % ans)


solve()

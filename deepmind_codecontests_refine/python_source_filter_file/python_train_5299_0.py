from decimal import Decimal, getcontext

d1 = Decimal(1)
while True:
    n, k, m, r = map(int, input().split())
    if not n:
        break
    getcontext().prec = r + 1
    ans = d1 / Decimal(n)
    if m:
        ans *= 1 + sum(d1 / Decimal(i) for i in range(1, n))
    print('{{:.{}f}}'.format(r).format(ans))
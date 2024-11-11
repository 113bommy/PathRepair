def f(n, t):
    if n % 2 == 0:
        n = int(n / 2)
    else:
        n = n * 3 + 1
    t += 1
    if n == 1:
        return t
    else:
        return f(n, t)


while True:
    _n = int(input())
    if _n == 0:
        break
    print(_n if _n == 1 else f(_n, 0))
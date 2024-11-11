_f = lambda: map(int, input().split())

for i in range(int(input())):
    x, y, n = _f()
    d = n // x
    if n <= x:
        print(y)
    elif n % x < y:
        print((d - 1) * x + y)
    else:
        print(d * x + y)


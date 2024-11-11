def gcd(a, b): return gcd(b % a, a) if a else b
def f(a, b):
    if a == 1: return 1, 0
    y, x = f(b % a, a)
    return - x - y * (b // a), - y
a, b, c = map(int, input().split())
if c:
    if a:
        if b:
            if c < 0: a, b, c = - a, - b, - c
            i, j = a < 0, b < 0
            a, b = abs(a), abs(b)
            k = gcd(a, b)
            if c % k: print(-1)
            else:
                a, b, c = a // k, b // k, c // k
                u = gcd(b, c)
                v = gcd(a, c)
                a, c = a // v, c // v
                b, c = b // u, c // u
                x, y = f(a, b)
                if not i: x = - x
                if j: y = - y
                print(c * x * u, c * y * v)
        else:
            if c % a: print(-1)
            else: print(- c // a, 0)
    else:
        if c % b: print(-1)
        else: print(0, - c // b)
else: print(- b, a)
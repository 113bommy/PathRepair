def gcd(a, b):
    if (a == 0):
        return b
    return gcd(b % a, a)

def lcm(a, b):
    return (a * b) // gcd(a, b)

def f(x, lcm, max_ab):
    return (x // lcm) * (lcm - max_ab) + max(x % lcm - (max_ab - 1), 0)

t = int(input())
for _ in range(t):
    a, b, q = map(int, input().split())
    c = lcm(a, b)
    d = max(a, b)
    ending = ' '
    for i in range(q):
        li, ri = map(int, input().split())
        if i == q-1:
            ending = '\n'
        print(f(ri, c, d) - f(li - 1, c, d), end=ending)

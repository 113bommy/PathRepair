a, b, c = map(int, input().split())

def exgcd(a, b):
    if b == 0:
        return a, 1, 0
    gcd, x, y = exgcd(b, a % b)
    k = - (a//b)
    xx = y
    yy = x + y*k
    return gcd, xx, yy

# print(exgcd(252, 198))

gcd, x0, y0 = exgcd(a, b)
if c % gcd != 0:
    print(-1)
else:
    k = (-c) // gcd
    print(k*x0, k*y0)


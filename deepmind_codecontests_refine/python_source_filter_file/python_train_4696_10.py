def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


a, b, x, y = [int(i) for i in input().split()]
L, R = 0, int(1e18)
g = gcd(x, y)
x //= g
y //= g
while R - L > 1:
    M = (L + R) // 2
    w = M * x
    h = M * y
    if w <= a and h <= b:
        L = M
    else:
        R = M
print(L)
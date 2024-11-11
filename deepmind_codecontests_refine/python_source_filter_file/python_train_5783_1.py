def gcd(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    return gcd(b, a % b)


def nok(a, b):
    return (a * b) // gcd(a, b)


def chocolate(n, a, b, p, q):
    if p < q:
        a, b = b, a
        p, q = q, p
    x, m, c = n // a, n // nok(a, b), n // b
    return x * p + q * (c - nok(a, b))


N, A, B, P, Q = [int(i) for i in input().split()]
print(chocolate(N, A, B, P, Q))
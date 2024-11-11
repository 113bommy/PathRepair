def c(n):
    b = 2
    f = set()
    while b * b <= n:
        while n % b == 0:
            n //= b
            f |= {b}
        b += 1
    if n > 1:
        f |= {n}
    return f
a, b = map(int, input().split())
print(len(c(a) & c(b)))
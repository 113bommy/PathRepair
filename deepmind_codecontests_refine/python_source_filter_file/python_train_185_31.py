def main():
    n, p = map(int, input().split())
    x = 1

    for f, c in get_prime_factors(p):
        if c >= n:
            x *= f * (c // n)

    print(x)

def get_prime_factors(p):
    f = 2

    while f * f<= p:
        c = 0
        while True:
            m, r = divmod(p, f)
            if r != 0:
                break
            c += 1
            p //= f
        if c != 0:
            yield f, c

        f += 1

    if p != 1:
        yield p, 1

main()

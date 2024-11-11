def main():
    q = int(input())
    mod = 1000003
    fact = [1, 1]
    for i in range(2, mod+1):
        fact.append(fact[-1]*i % mod)

    for i in range(q):
        x, d, n = map(int, input().split())
        if d == 0:
            print(pow(d, n, mod))
            continue
        elif n >= mod:
            print(0)
            continue
        b = -x*pow(d, mod-2, mod) % mod
        if b >= n:
            print(pow(fact[b-n], mod-2, mod)*fact[b]*pow(-d, n, mod) % mod)
        else:
            print(0)


main()
def main():
    b, w = map(int, input().split())
    mod = 10**9+7
    fact = [1, 1]
    for i in range(2, 2*(10**5)+5):
        fact.append(fact[-1]*i % mod)

    half = pow(2, mod-2, mod)

    def nCr(n, r, mod=10**9+7):
        return pow(fact[n-r]*fact[r] % mod, mod-2, mod)*fact[n] % mod

    h = 1

    A, B, C = 0, 1, 0
    for i in range(1, b+w+1):
        h = h*half % mod
        ans = B
        A = A*2 % mod
        B = B*2 % mod
        C = C*2 % mod
        if i-1 >= b:
            p = nCr(i-1, b)
            ans = (ans-p) % mod
            C = (C+p) % mod
            B = (B-p) % mod
        if i-w-1 >= 0:
            p = nCr(i-1, i-w-1)
            A = (A+p) % mod
            B = (B-p) % mod
        ans = (ans+A) % mod
        print(ans*h % mod)


main()

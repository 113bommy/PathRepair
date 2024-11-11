import sys

input = sys.stdin.readline


def main():
    MOD = 998244353
    N, M = [int(x) for x in input().split()]

    if N == 2:
        print(M)
        return

    fact = [1, 1]
    factinv = [1, 1]
    inv = [0, 1]

    def cmb(n, k, p):
        if (k < 0) or (n < k):
            return 0
        r = min(k, n - k)
        return fact[n] * factinv[k] * factinv[n - k] % p

    for i in range(2, 2 * 10 ** 5):
        fact.append((fact[-1] * i) % MOD)
        inv.append((-inv[MOD % i] * (MOD // i)) % MOD)
        factinv.append((factinv[-1] * inv[-1]) % MOD)

    ans = 0
    for i in range(M, -1, -1):
        if i - 1 < N - 2:
            break
        x = cmb(i - 1, N - 2, MOD)
        y = pow(2, N - 3, MOD)
        y = (x * y * (N - 2)) % MOD
        ans = (ans + y) % MOD

    print(ans)


if __name__ == '__main__':
    main()

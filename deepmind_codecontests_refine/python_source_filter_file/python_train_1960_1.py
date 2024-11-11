def prepare(k, n, MOD):
    def get_factorials(m):
        f = 1
        factorials = [1]
        for m in range(1, m + 1):
            f *= m
            f %= MOD
            factorials.append(f)
        inv = pow(f, MOD - 2, MOD)
        invs = [1] * (m + 1)
        invs[m] = inv
        for m in range(m, 1, -1):
            inv *= m
            inv %= MOD
            invs[m - 1] = inv

        return factorials, invs

    def solve(p):
        """Number of patterns where no pair of p appears when n dices are rolled"""
        if cache[p] > -1:
            return cache[p]

        ret = 0
        fp = factorials[p]
        for q in range(1, min(p, n // 2) + 1):
            tmp1 = (fp * invs[q] % MOD) * invs[p - q] % MOD
            tmp2 = (factorials[k + n - 2 * q - 1] * invs[n - 2 * q] % MOD) * ik % MOD
            if q % 2 == 1:
                ret += tmp1 * tmp2
            else:
                ret -= tmp1 * tmp2
            ret %= MOD

        cache[p] = ret = (all_patterns - ret) % MOD
        return ret

    factorials, invs = get_factorials(k + n)
    ik = invs[k - 1]
    all_patterns = factorials[k + n - 1] * invs[n] * ik % MOD
    cache = [-1] * (k // 2 + 1)

    return solve


MOD = 998244353
k, n = map(int, input().split())
if k == 1:
    print(0)
else:
    solve = prepare(k, n, MOD)
    ans = [solve(i // 2 - max(0, i - k - 1)) for i in range(2, k + 2)]
    print('\n'.join(map(str, ans)))
    print('\n'.join(map(str, ans[-2::-1])))

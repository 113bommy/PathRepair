def prepare(n, MOD):
    f = 1
    factorials = [1] * (n + 1)
    for m in range(1, n + 1):
        f = f * m % MOD
        factorials[m] = f
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv = inv * m % MOD
        invs[m - 1] = inv

    return factorials, invs


def get_nhr(n, facts, invs, MOD):
    def nhr(r):
        return facts[n + r - 1] * invs[r] * invs[n - 1] % MOD

    return nhr


def solve(n, m):
    MOD = 998244353
    facts, invs = prepare(n + 3 * m, MOD)
    fn = facts[n]
    nhr = get_nhr(n, facts, invs, MOD)
    nm2 = min(n, m - 2)
    ans = 0
    for odd in range(m % 2, min(m, n) + 1, 2):
        tmp = nhr((3 * m - odd) // 2)
        if odd > 0:
            tmp -= odd * nhr((m - odd) // 2)
        if odd < nm2:
            tmp -= (n - odd) * nhr((m - odd - 2) // 2)
        ans = (ans + fn * invs[odd] * invs[n - odd] % MOD * tmp) % MOD
    return ans


n, m = list(map(int, input().split()))
print(solve(n, m))

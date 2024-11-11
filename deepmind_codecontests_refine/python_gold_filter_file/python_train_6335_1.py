def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f = f * m % MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    invs = [1] * (n + 1)
    invs[n] = inv
    for m in range(n, 1, -1):
        inv = inv * m % MOD
        invs[m - 1] = inv

    return factorials, invs


def solve(n, a, b, c, d, MOD):
    facts, invs = prepare(n, MOD)
    dp = [0] * (n + 1)
    dp[n] = 1
    for i in range(a, b + 1):
        iv = invs[i]
        for j in range(i * c, n + 1):
            base = dp[j] * facts[j] % MOD
            for k in range(c, d + 1):
                ik = i * k
                if ik > j:
                    break
                pat = base * invs[j - ik] % MOD
                pat = pat * pow(iv, k, MOD) * invs[k]
                dp[j - ik] = (dp[j - ik] + pat) % MOD
    return dp[0]


n, a, b, c, d = map(int, input().split())
MOD = 10 ** 9 + 7
print(solve(n, a, b, c, d, MOD))

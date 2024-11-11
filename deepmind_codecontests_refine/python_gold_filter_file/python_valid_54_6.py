MOD = 10 ** 9 + 7

for _ in range(int(input())):
    n, k = map(int, input().split())
    COEFF_WINS = (2 ** n) % MOD
    COEFF_Q = (2 ** (n - 1)) % MOD
    wins = 0
    q = 1
    for i in range(k):
        wins *= COEFF_WINS
        wins %= MOD
        if n % 2 == 0:
            wins += q
            q *= COEFF_Q - 1
        else:
            q *= COEFF_Q + 1
        q %= MOD
    wins += q
    print(wins % MOD)

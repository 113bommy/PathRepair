MOD = 1e9+7
for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    r = 0
    # for j in range(32):
    #     if (k&(1<<j)):
    #         ans = (ans+p)%MOD
    #     p *= n
    #     p %= MOD
    s = 0
    count = 0
    while k:
        if k & 1:
            s += n ** count

        count += 1
        k >>= 1
    print(s % MOD)
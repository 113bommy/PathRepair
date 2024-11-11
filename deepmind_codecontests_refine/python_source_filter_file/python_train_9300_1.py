MOD = 1000000007

def pow(n):
    ans = 1
    p = 2
    while n > 0:
        if (n&1) == 1:
            ans = (ans*p) % MOD
        p = (p*p) % MOD
        n >>= 1
    return ans % MOD

n = int(input())
print(0 if n == 0 else (pow(2*n - 1) + pow(n - 1)) % MOD)

def modinv(n, p):
    return pow(n, p - 2, p)
def main():
    MOD = 998244353
    n = int(input())
    q = modinv(pow(2, n, MOD), MOD)

    fib = [0] * 200005
    fib[1] = 1
    fib[2] = 1

    for i in range(3, 200005):
        fib[i] = fib[i - 1] + fib[i - 2]
        fib[i] %= MOD

    p = fib[n]
    #print(p, q)

    ans = (p % MOD * q % MOD) % MOD
    print(ans)
main()
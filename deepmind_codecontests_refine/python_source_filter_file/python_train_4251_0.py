n, m = map(int, input().split())
mod = 10 ** 9 + 7

def prf(n):
    pf = {}
    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            pf[i] = pf.get(i, 0) + 1
            n //= i
    if n > 1:
        pf[n] = 1
    return pf

def comb(n, k):
    k = min(k, n-k)
    result = 1
    for i in range(n-k+1, n+1):
        result *= i
    for i in range(1, k+1):
        result //= i
    return result

ans = 1
for v in prf(m).values():
    ans *= comb(n-1+v, v) % mod
    
print(ans)
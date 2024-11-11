def power(a, b, mod):
    res = 1
    
    while b:
        if b%2:
            res = (res*a)%mod
        
        b //= 2
        a = (a*a)%mod    
            
    return res%mod

def divide(a, b, mod):
    return (a * power(b, mod-2, mod)) % mod

n = int(input())
MOD = 998244353

fib = [0, 1]
for i in range(2, 200001):
    fib.append((fib[-1] + fib[-2])%MOD)

print(divide(fib[n], power(2, n, MOD), MOD))
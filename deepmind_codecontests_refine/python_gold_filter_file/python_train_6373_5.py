def primeFactor(N):
    i = 2
    ret = {}
    n = N
    mrFlg = 0
    while i*i <= n:
        k = 0
        while n % i == 0:
            n //= i
            k += 1
        if k: ret[i] = k
        i += 1 + i%2
        if i == 101 and n >= 2**20:
            def findFactorRho(N):
                def gcd(a, b):
                    while b: a, b = b, a % b
                    return a
                def f(x, c):
                    return (x * x + c) % N
                for c in range(1, 99):
                    X, d, j = [2], 1, 0
                    while d == 1:
                        j += 1
                        X.append(f(X[-1], c))
                        X.append(f(X[-1], c))
                        d = gcd(abs(X[2*j]-X[j]), N)
                    if d != N:
                        if isPrimeMR(d):
                            return d
                        elif isPrimeMR(N//d): return N//d
            while n > 1:
                if isPrimeMR(n):
                    ret[n], n = 1, 1
                else:
                    mrFlg = 1
                    j = findFactorRho(n)
                    k = 0
                    while n % j == 0:
                        n //= j
                        k += 1
                    ret[j] = k

    if n > 1: ret[n] = 1
    if mrFlg > 0: ret = {x: ret[x] for x in sorted(ret)}
    return ret

def isPrimeMR(n):
    if n == 2:
        return True
    if n == 1 or n & 1 == 0:
        return False
    d = (n - 1) >> 1
    while d & 1 == 0:
        d >>= 1
    
    L = [2, 7, 61] if n < 1<<32 else [2, 13, 23, 1662803] if n < 1<<40 else [2, 3, 5, 7, 11, 13, 17] if n < 1<<48 else [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    for a in L:
        t = d
        y = pow(a, t, n)
        while t != n - 1 and y != 1 and y != n - 1:
            y = (y * y) % n
            t <<= 1

        if y != n - 1 and t & 1 == 0:
            return False
    return True

def gcd(a, b):
    while b: a, b = b, a % b
    return a

T = int(input())
for _ in range(T):
    a, m = map(int, input().split())
    g = gcd(a, m)
    n = m // g
    pf = primeFactor(n)
    ans = 1
    for p in pf:
        ans *= (p-1) * p ** (pf[p]-1)
    print(ans)
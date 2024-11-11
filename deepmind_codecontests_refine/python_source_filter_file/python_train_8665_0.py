def primes235(limit):
    yield 2; yield 3; yield 5
    if limit < 7: return
    modPrms = [7,11,13,17,19,23,29,31]
    gaps = [4,2,4,2,4,6,2,6,4,2,4,2,4,6,2,6] # 2 loops for overflow
    ndxs = [0,0,0,0,1,1,2,2,2,2,3,3,4,4,4,4,5,5,5,5,5,5,6,6,7,7,7,7,7,7]
    lmtbf = (limit + 23) // 30 * 8 - 1 # integral number of wheels rounded up
    lmtsqrt = (int(limit ** 0.5) - 7)
    lmtsqrt = lmtsqrt // 30 * 8 + ndxs[lmtsqrt % 30] # round down on the wheel
    buf = [True] * (lmtbf + 1)
    for i in range(lmtsqrt + 1):
        if buf[i]:
            ci = i & 7; p = 30 * (i >> 3) + modPrms[ci]
            s = p * p - 7; p8 = p << 3
            for j in range(8):
                c = s // 30 * 8 + ndxs[s % 30]
                buf[c::p8] = [False] * ((lmtbf - c) // p8 + 1)
                s += p * gaps[ci]; ci += 1
    for i in range(lmtbf - 6 + (ndxs[(limit - 7) % 30])): # adjust for extras
        if buf[i]: yield (30 * (i >> 3) + modPrms[i & 7])
        
pp = list(primes235(5000))

def decomp(n):
    d = {}
    for p in pp:
        if n % p == 0:
            k = 0
            while n % p == 0:
                n /= p
                k += 1
            d[p] = k
            if n == 1:
                break
    if n > 1:
        d[n] = 1
    return d
    
def cnt(n, p):
    k = 0
    while n % p == 0:
        n /= p
        k += 1
    return k
    
n = int(input())
a = map(int, input().split())

x = decomp(next(a))
y = decomp(next(a))
for v in x:
    y[v] = y.get(v, 0)
for v in y:
    x[v] = x.get(v, 0)
    x[v], y[v] = min(x[v], y[v]), max(x[v], y[v])
    
for u in a:
    for v in x:
        if y[v] > 0:
            z = cnt(u, v)
            if z < x[v]:
                y[v] = x[v]
                x[v] = z
            elif z < y[v]:
                y[v] = z
            
res = 1
for p, k in y.items():
    if k > 0:
        res *= p ** k
print(res)
        
# ----------- gcd ----------- #
def gcd(x, y):
    k, l = x, y
    if y < 0:
        k, l = -k, -l
    while l:
        k, l = l, k % l
    return k
    
def extgcd(a, b, c):
    if b == 0:
        return c // a, 0
    if b < 0:
        a, b, c = -a, -b, -c
    x, y, u, v, k, l = 1, 0, 0, 1, a, b
    while l != 0:
        x, y, u, v = u, v, x - u * (k // l), y - v * (k // l)
        k, l = l, k % l
    return c * x, c * y

# --------- IsPrime --------- #
def IsPrime(n):
    if n == 1:
        return False
    p = 2
    while p * p <= n:
        if n % p == 0:
            return False
        p += 1
    return True

# --- fraction calculator --- #
def fracsum(f1, f2, sign = 1):
    fs = [f1[0]*f2[1]+sign*f1[1]*f2[0], f1[1]*f2[1]]
    g = gcd(fs[0], fs[1])
    fs[0] //= g
    fs[1] //= g
    return fs
def fracprod(f1, f2):
    fs = [f1[0]*f2[0], f1[1]*f2[1]]
    g = gcd(fs[0], fs[1])
    fs[0] //= g
    fs[1] //= g
    return fs

# ------ factorization ------ #
def factorization(n):
    D = {}
    a = n
    p = 2
    while a != 1:
        cnt = 0
        while a % p == 0:
            cnt += 1
            a //= p
        if cnt != 0:
            D[p] = cnt
        p += 1
        if p * p > n and a != 1:
            D[a] = 1
            break
    return D
def divisors_list(D):
    F = [1]
    for i in D:
        mL = F[:]
        dp = i
        for j in range(D[i]):
            for k in mL:
                F.append(dp*k)
            dp *= i
    F.sort()
    return F

def doubling(n, m, modulo=0):
    y = 1
    base = n
    tmp = m
    while tmp:
        if tmp % 2 == 1:
            y *= base
            if modulo > 0:
                y %= modulo
        base *= base
        if modulo > 0:
            base %= modulo
        tmp //= 2
    return y

def inved(a, modulo):
    x, y, u, v, k, l = 1, 0, 0, 1, a, modulo
    while l != 0:
        x, y, u, v = u, v, x - u * (k // l), y - v * (k // l)
        k, l = l, k % l
    return x % modulo
def bic(n): # count time divided by 2
    cnt = 0
    while n % 2 == 0:
        cnt += 1
        n //= 2
    return cnt
def powlimit(n):
    y = 1
    cnt = 0
    while y < n:
        y *= 2
        cnt += 1
    return y, cnt
def CRT(n, a, b): # x = a[i] mod b[i]
    r = a[0]
    bas = b[0]
    x, y = 0, 0
    for i in range(1, n):
        x, y = extgcd(bas, -b[i], a[i] - r)
        r += bas * x
        bas *= b[i]
    return r % bas

# making lists of mod and prim. root
def mod_maker(cnt, num):
    bin_list = [1 for _ in range(cnt+1)]
    for i in range(cnt, 0, -1):
        bin_list[i-1] = 2*bin_list[i]
    L = []
    pm = []
    bas = doubling(2, cnt)
    ccnt = 0
    j = 1
    while ccnt < num:
        if IsPrime(j*bas+1):
            x = j*bas+1
            L.append(j*bas+1)
            ccnt += 1
            st = 1
            flg = 0
            while not flg:
                flg = (doubling(st, bin_list[0], x) == 1)
                for k in range(cnt):
                    flg *= (doubling(st, bin_list[k+1], x) != 1)
                if flg:
                    pm.append(st)
                    break
                st += 1
        j += 2
    return L, pm

def NTT(f, n, cn, num, inverse=False):
    if n == 1:
        return f
    if n == 2:
        return [(f[0]+f[1])%mod[num], (f[0]-f[1])%mod[num]]
    dn = n // 2
    fe = [f[2*i+0] for i in range(dn)]
    fo = [f[2*i+1] for i in range(dn)]
    fe = NTT(fe, dn, cn-1, num, inverse)
    fo = NTT(fo, dn, cn-1, num, inverse)
    seed = inverse * prim[num][cn] + (1 - inverse) * invp[num][cn]
    grow = 1
    xf = [0 for _ in range(n)]
    for i in range(dn):
        right = fo[i] * grow % mod[num]
        xf[i+0*dn] = (fe[i] + right) % mod[num]
        xf[i+1*dn] = (fe[i] - right) % mod[num]
        grow *= seed
        grow %= mod[num]
    return xf

# ----------- NTT test zone ----------- #
N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

pl, bn = powlimit(2*max(N, M)+2)
A = A[:] + [0]*(pl-N)
B = B[:] + [0]*(pl-M)
convolution_time = 1 # convolution level (number of 'mod's)
binary_count = 23
mod, primod = [998244353], [31]
prim = [[doubling(primod[j], doubling(2, binary_count-i), mod[j]) for i in range(binary_count)] for j in range(convolution_time)]
invp = [[inved(prim[j][i], mod[j]) for i in range(binary_count)] for j in range(convolution_time)]

X1 = NTT(A, pl, bn, 0)
X2 = NTT(B, pl, bn, 0)
XX = [X1[i]*X2[i]%mod[0] for i in range(pl)]
Y = NTT(XX, pl, bn, 0, 1)
ipl = inved(pl, mod[0])
for i in range(N+M-1):
    Y[i] *= ipl
    Y[i] %= mod[0]
    print(Y[i], end = ' '*(i!=N+M-2))
print()
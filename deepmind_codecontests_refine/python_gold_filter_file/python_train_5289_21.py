N = int(input())
XY = [[int(x) for x in input().split()] for i in range(N)]
mod = 998244353
XY.sort() #Xについてソート
X, Y = zip(*XY)
Y_rank = {x:i for i, x in enumerate(sorted(Y), 1)}
BIT = [0] * (N+1)

def append_BIT(x):
    while x <= N:
        BIT[x] += 1
        x += x & (-x)

def sum_BIT(x):
    ret = 0
    while x:
        ret += BIT[x]
        x &= (x-1)
    return ret

pow2 = [1]
for i in range(N):
    pow2.append(pow2[-1] * 2 % mod)

ret = 0 
for i in range(N):
    y = Y_rank[Y[i]]
    L = i
    R = N-i-1
    D = y-1
    U = N-D-1
    LD = sum_BIT(y)
    append_BIT(y)
    LU = L - LD
    RU = U - LU
    RD = D - LD
    
    ret += (pow2[N]-1 - pow2[L] - pow2[R] - pow2[U] - pow2[D] + pow2[LD] + pow2[LU] + pow2[RU] + pow2[RD])
    
ret %= mod
print(ret)

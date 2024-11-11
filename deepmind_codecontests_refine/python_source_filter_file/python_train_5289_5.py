from bisect import bisect_left as bl
N = int(input())
P = 998244353
NN = 17
XX = [0] * (2**(NN+1)-1)
pow2 = [1]
for _ in range(1, 202020):
    pow2.append(pow2[-1]*2%P)

def addvalue(j):
    i = 2**NN + j - 1
    while i >= 0:
        XX[i] += 1
        i = (i-1) // 2

def rangesum(a, b):
    l = a + (1<<NN)
    r = b + (1<<NN)
    s = 0
    while l < r:
        if l%2:
            s += XX[l-1]
            l += 1
        if r%2:
            r -= 1
            s += XX[r-1]
        l >>= 1
        r >>= 1
    return s

X = []
Y = []
XY = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    XY.append((x, y))

X = sorted(X)
Y = sorted(Y)
XY = sorted(XY, key = lambda x: x[1])

DX = {}
for i in range(N):
    DX[X[i]] = i

ans = 0
U = 0
for x, y in XY:
    a = rangesum(0, DX[x])
    L = bl(X, x)
    b = U-a
    d = L-a
    c = N-a-b-d-1
    ans = (ans + pow2[N] - (pow2[a+b] + pow2[b+c] + pow2[c+d] + pow2[d+a] - pow2[a] - pow2[b] - pow2[c] - pow2[d] + 1)) % P
    U += 1
    addvalue(DX[x])
    
print(ans)

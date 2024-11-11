import sys
input = sys.stdin.readline
N, M = map(int, input().split())
NN = (M + 10).bit_length() - 1
BIT=[0]*(2**NN+1)

def addrange(l0, r0, x=1):
    l, r = l0, r0
    while l <= 2**NN:
        BIT[l] += x
        l += l & (-l)
    while r <= 2**NN:
        BIT[r] -= x
        r += r & (-r)
def getvalue(r):
    a = 0
    while r != 0:
        a += BIT[r]
        r -= r&(-r)
    return a

X = []
for _ in range(N):
    l, r = map(int, input().split())
    X.append((l, r+1))

X = sorted(X, key = lambda x: -(x[1]-x[0]))
for d in range(1, M+1):
    while X and X[-1][1] - X[-1][0] < d:
        l, r = X.pop()
        addrange(l, r)
    ans = len(X)
    for i in range(d, M+1, d):
        ans += getvalue(i)
    print(ans)

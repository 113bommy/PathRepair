import sys
input = lambda: sys.stdin.readline().rstrip()
def primeFactor(N):
    i, n, ret, d, sq = 2, N, {}, 2, 99
    while i <= sq:
        k = 0
        while n % i == 0: n, k, ret[i] = n//i, k+1, k+1
        if k > 0 or i == 97: sq = int(n**(1/2)+0.5)
        if i < 4: i = i * 2 - 1
        else: i, d = i+d, d^6
    if n > 1: ret[n] = 1
    return ret

def divisors(N):
    pf = primeFactor(N)
    ret = [1]
    for p in pf:
        ret_prev = ret
        ret = []
        for i in range(pf[p]+1):
            for r in ret_prev:
                ret.append(r * (p ** i))
    return sorted(ret)

def chk(X):
    n = len(X)
    XX = X * 2
    mi = 1 << 30
    for d in divisors(n):
        if d >= mi: break
        for i in range(d):
            for j in range(i, n+i+d, d):
                if XX[j] != XX[j-d]:
                    break
            else:
                mi = min(mi, d)
    return mi

T = int(input())
for _ in range(T):
    N = int(input())
    A = [int(a) - 1 for a in input().split()]
    C = [int(a) - 1 for a in input().split()]
    done = [0] * N
    L = []
    for i in range(N):
        if done[i]: continue
        t = [i]
        j = A[i]
        while j != i:
            t.append(C[j])
            done[j] = 1
            j = A[j]
        L.append(t)
    print(min([chk(a) for a in L]))

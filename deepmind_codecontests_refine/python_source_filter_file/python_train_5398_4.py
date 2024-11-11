from itertools import product
N, K = map(int, input().split())
A = list(map(int, input().split()))

def f(p):
    ret = 0
    ma = 0
    for i, a in enumerate(A):
        if p[i] == 1:
            if ma == 0:
                pass
            else:
                if ma >= a:
                    ret += ma - a + 1
                    ma += 1
        ma = max(ma, a)
    return ret

ans = 10 ** 10
for p in product(range(2), repeat=N):
    if sum(p) < K: continue
    #print(p)
    ans = min(ans, f(p))

print(ans)

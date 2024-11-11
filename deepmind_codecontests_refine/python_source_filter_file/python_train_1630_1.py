k, d, t = map(int, input().split())
d = ((k//d)+1) * d

def f(tp):
    r = 0

    dd = int(tp) // d;
    tp -= d * dd
    r += (d+k)/(2*t)*dd

    if tp <= k:
        r += tp/t
    else:
        r += k/t
        r += (tp-k)/(2*t)

    return r

L = 0
R = 2e18
ITR = 1000

for _ in range(ITR):
    M = (L+R)/2.0
    # print(L, R, M)

    if f(M) >= 1.0:
        R = M
    else:
        L = M

print("{:.10f}".format(L))

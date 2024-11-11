from bisect import bisect
inpl = lambda: list(map(int, input().split()))

N = int(input())
X = inpl()
L = int(input())
Q = int(input())
R = [[0]*(N) for k in range(17)]

for i in range(N):
    R[0][i] = bisect(X, X[i]+L) - 1

for k in range(16):
    for i in range(N):
        R[k+1][i] = R[k][R[k][i]]


def reach(a, d):
    O = format(d, "b").zfill(17)[::-1]
    for k in range(16, -1, -1):
        if O[k] == "1":
            a = R[k][a]
    return a


def bisearch(a, b):
    a, b = a-1, b-1
    if b < a:
        a, b = b, a
    OK = b-a
    NG = 0

    while abs(OK - NG) > 1:
        mid = (OK+NG)//2
        if reach(a, mid) >= b:
            OK = mid
        else:
            NG = mid
    return OK

print(*[bisearch(*inpl()) for _ in range(Q)], sep="\n")

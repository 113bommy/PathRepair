import bisect
N = int(input())
A = sorted(list(map(int, input().split())))
if N == 2:
    x, y = A[1], A[0]
    print(x-y)
    print(x, y)
    exit()
idx = bisect.bisect_left(A, 0)
if idx:
    if idx < N:
        Q = A[:idx]
        P = A[idx:]
    else:
        Q = A[:-1]
        P = [A[-1]]
else:
    Q = [A[0]]
    P = A[1:]


XY = []
LP = len(P)
for i in range(LP-1):
    XY.append((Q[0], P[i]))
    Q[0] -= P[i]
LQ = len(Q)
for i in range(LQ):
    XY.append((Q[i], P[-1]))
    P[-1] = P[-1] - Q[i]
ans = P[-1]
print(ans)
for x, y in XY:
    print(x, y)




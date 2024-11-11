import sys
input = sys.stdin.readline
n,q = map(int,input().split())
A = [list(map(int,input().split())) for i in range(n)]
D = [int(input()) for i in range(q)]

E = []
F = {}
for i in range(n):
    s = A[i][0]
    t = A[i][1]
    x = A[i][2]
    F[x] = 0
    E.append((s-x, x, 1))
    E.append((t-x, x, -1))
E.append((10**10, 10**10, 1))

E.sort()

# print(E)

from heapq import heappush, heappop
Q = []

j = 0
for i in range(q):
    # print(F,j)
    while E[j][0] <= D[i]:
        if E[j][2] == 1:
            F[E[j][1]] += 1
            heappush(Q, E[j][1])
        else:
            F[E[j][1]] -= 1
        j += 1
    
    while len(Q) > 0 and F[Q[0]] == 0:
        _ = heappop(Q)
    if len(Q) == 0:
        print(-1)
    else:
        print(Q[0])

import sys
input = sys.stdin.readline
from heapq import *
N, Q = map(int, input().split())

X = []
for _ in range(N):
    s, t, x = map(int, input().split())
    X.append((s-x,t-x,x))

X = sorted(X, key = lambda x: x[0])
D = [int(input()) for _ in range(Q)]
i = 0
j = 0
A = []
B = []
C = []
for q in range(Q):
    while i < len(X) and D[q] >= X[i][0]:
        a, b, x = X[i]
        heappush(A, (x, b))
        heappush(B, (b, x))
        i += 1
    while len(B) and B[0][0] <= D[q]:
        b, x = heappop(B)
        heappush(C, (x, b))
    while len(C) and len(A) and C[0][0] == A[0][0]:
        heappop(A)
        heappop(C)
    print(A[0][0] if A else -1)
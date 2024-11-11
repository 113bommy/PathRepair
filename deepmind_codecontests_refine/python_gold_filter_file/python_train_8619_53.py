import sys
input = sys.stdin.readline
from heapq import *
N, Q = map(int, input().split())
X = []
for _ in range(N):
    s, t, x = map(int, input().split())
    X.append((s-x,t-x,x))

X = sorted(X, key = lambda x: x[0])
i = 0
A, B, C = [], [], []
for _ in range(Q):
    d = int(input())
    while i < len(X) and d >= X[i][0]:
        a, b, x = X[i]
        heappush(A, (x, b))
        heappush(B, (b, x))
        i += 1
    while len(B) and B[0][0] <= d:
        b, x = heappop(B)
        heappush(C, (x, b))
    while len(C) and len(A) and C[0][0] == A[0][0]:
        heappop(A)
        heappop(C)
    print(A[0][0] if A else -1)

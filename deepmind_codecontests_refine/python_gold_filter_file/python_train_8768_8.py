import sys
input = lambda: sys.stdin.readline().rstrip()

from collections import deque

# mod = 10 ** 9 + 7
N, K = map(int, input().split())
X = [[] for i in range(N)]
for i in range(N-1):
    x, y = map(int, input().split())
    X[x-1].append(y-1)
    X[y-1].append(x-1)

P = [-1] * N
Q = deque([0])
R = []
while Q:
    i = deque.popleft(Q)
    R.append(i)
    for a in X[i]:
        if a != P[i]:
            P[a] = i
            X[a].remove(i)
            deque.append(Q, a)

SIZE = [1] * N
for i in R[1:][::-1]:
    SIZE[P[i]] += SIZE[i]

A = [0] * N
DE = [0] * N
for i in R[1:]:
    DE[i] = DE[P[i]] + 1

for i in R:
    A[i] = (SIZE[i] - DE[i] << 18) + i

# print("SIZE =", SIZE)
# print("DE =", DE)
# print("A =", A)

A = sorted(A)
T = [0] * N

m = (1 << 18) - 1
for i in A[:K]:
    T[i & m] = 1

# print("T =", T)

ans = 0
B = [0] * N
for i in R[::-1]:
    if T[i]:
        B[P[i]] += B[i] + 1
    else:
        B[P[i]] += B[i]
        ans += B[i]

print(ans)

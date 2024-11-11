from collections import deque
N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))
A = -(1e9 + 5)
for i in range(N):
    x = i
    S = deque()
    s = 0
    while True:
        x = P[x] - 1
        S.append(C[x])
        s += C[x]
        if x == i:
            break
    l = len(S)
    a = 0
    for i in range(l):
        a += S[i]
        if i + 1 > K:
            break
        An = a
        if s > 0:
            An += s * ((K - i - 1) // l)
        A = max(A, An)
print(A)
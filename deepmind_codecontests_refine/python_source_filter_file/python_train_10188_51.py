from random import shuffle
from collections import Counter
def inpl(): return list(map(int, input().split()))

#N = 20000
#P = list(range(1, N+1))
#shuffle(P)

N = int(input())
P = inpl()

A = [0]*N
B = [0]*N
S = [10**9] * (N)
for i, p in enumerate(P):
    S[p-1] += i

A[0] = 1
B[0] = S[0] - 1

for i in range(1, N):
    A[i] = max(A[i-1] + 1, S[i] - B[i-1] + 1)
    B[i] = S[i] - A[i]

for i in range(N-1):
    assert A[i] < A[i+1]
    assert B[i] > B[i+1]

assert B[-1] > 0
print(*A)
print(*B)
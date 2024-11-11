# import sys
# sys.stdin.readline

INF = 1000000000

N = int(input())
A = list(map(int, input().split()))

mx = -INF
idxmx = -1

if N % 2 == 1:
    for i in range(N):
        pos = A[i]
        if pos < 0:
            pos = - pos - 1
        if pos > mx:
            mx = pos
            idxmx = i

for i in range(N):
    if i == idxmx:
        if A[i] < 0:
            A[i] = - A[i] - 1
    else:
        if A[i] >= 0:
            A[i] = - A[i] - 1

print(*A)

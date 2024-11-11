N,M = map(int, input().split())

A = [int(input()) for _ in range(M)]

lis = [0]*(N+1)
lis[0] = 1


for i in range(1,N+1):
    lis[i] = (lis[i-1] + lis[i-2])%(10**9+7)
    if i in A:
        lis[i] = 0

print(lis[N])


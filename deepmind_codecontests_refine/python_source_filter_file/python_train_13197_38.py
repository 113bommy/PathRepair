N = int(input())
A = list(map(int, input().split()))

A.sort()
res = 0

for i in range(1, N):
    res += A[N-1]-i//2

print(res)
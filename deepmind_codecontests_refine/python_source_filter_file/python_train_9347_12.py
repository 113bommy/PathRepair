N = int(input())
A = list(map(int, input().split()))
M = sum(A)/2
M
a = 0
i = 0
while a < M:
    a += A[i]
    i += 1
print(int(min(a-M,a-M+A[i])*2))
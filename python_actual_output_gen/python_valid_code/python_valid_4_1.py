N = int(input())
A = [0] * (N + 2)
for i, v in enumerate(input().split()):
    A[i+1] = int(v)
num = sum([abs(A[i] - A[i+1]) for i in range(N+1)])
for i in range(N):
    ret = num + abs(A[i-1] - A[i+1]) - (abs(A[i-1] - A[i]) + abs(A[i] - A[i+1]))
    print(ret)
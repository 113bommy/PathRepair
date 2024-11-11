N = int(input())
A = [int(i) for i in input().split()]
a = [0] * N
for i in range(N):
    a[A[i]-1] = i + 1
print(*A)
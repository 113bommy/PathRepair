N = int(input())
A = [int(i) for i in input().split()]
A.sort()
S = 0

for i in range(N):
  S += A[N-i-1]
print(S)
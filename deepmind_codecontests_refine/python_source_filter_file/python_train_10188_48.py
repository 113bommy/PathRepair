N = int(input())
P = list(map(int,input().split()))

M = 40000
A = []
B = []
for i in range(N):
  A.append(M*i)
  B.append(M*(N-i))
for i in range(N):
  A[P[i]-1] += i
print(*A)
print(*B)

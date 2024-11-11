N = int(input())
A = list(map(int, input().split()))

S = sum(A)
Y = [0]*N
Y[0] = S - 2*sum(A[1::2])
for i in range(1,N):
  Y[i] = 2*A[i-1] - Y[i-1]

print(*Y)

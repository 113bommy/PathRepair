N = int(input())
A = [int(input()) for i range(N)]

x = sorted(A)

for i in range(N):
  if A[i] == x[N-1]:
    print(x[N-2])
  else:
    print(x[N-1])
N = int(input())
A = [int(input()) for i in range(N)]
B = []
if A[0] != 0:
  p = -1
else:
  p = 0
for i in range(1, N):
  if A[i] - A[i-1] >= 2:
    p = -1
  elif A[i] - A[i-1] <= 0:
    B.append(i-1)
if p == -1:
  print(p)
else:
  print(sum(A[B[i]] for i in range(len(B))) + A[N-1])
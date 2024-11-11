n,m = map(int, input().split())

A = [input() for i in range(n)]
B = [intpu() for j in range(m)]

for i in range(n-m+1):
  for j in range(n-m+1):
    if A[i][j:j+m] == B[0]:
      if all(A[i+k][j:j+m] == B[k] for k in range(1,M)):
        print("Yes")
        exit()
print("No")
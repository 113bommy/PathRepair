x = int(input())
Sum = 0
C = "YES"
A = [[i for i in [int(i) for i in input().split()]] for i in range(x)]
for i in range(x):
   for j in range(x):
      Sum += A[i][j]
   if Sum != 0:
      C = "NO"
      break
print(C) 
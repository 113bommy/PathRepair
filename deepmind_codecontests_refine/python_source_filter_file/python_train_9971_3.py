N = int(input())
A = []
B = []
for i in range(N):
  a,b = map(input().split())
  A.append(a)
  B.append(b)

A = sorted(A)
B = sorted(B)
 
if N%2==1:
  print(B[N//2] - A[N//2] + 1)
else:
  print( (B[N//2-1]+B[N//2]) - (A[N//2-1]+A[N//2]) + 1 )
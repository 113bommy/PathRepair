N = int(input())
A = list(map(int,input().split()))

A.insert(0,0)
A.append(0)
_A = []

for i in range(1,N+1):
  _A.append(abs(A[i] - A[i-1]))
_A.append(abs(0-A[N]))
S = sum(_A)


for i in range(0,N):
  allS = sum(_A)
  allS -= (_A[i]+_A[i+1]-abs(A[i+2]-A[i]))
  print(allS)
N,P=map(int,input().split())
A=list(map(int,input().split()))
odd=0
for i in range(N):
  if A[i]%2==1: odd+=1
if odd==0:
  if P==1: print(0)
  else: print(2**N)
else:
  print(2**(N-1))
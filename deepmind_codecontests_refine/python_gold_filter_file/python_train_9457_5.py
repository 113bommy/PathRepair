N = int(input())
A = [0]*N
for i in range(N):
  A[i] = int(input())
  
A.sort()

S = sum(A)
if S%10 != 0:
  print(S)
  exit()

for i in range(N):
  if A[i]%10 !=0:
    print(S-A[i])
    exit()
    
print(0)
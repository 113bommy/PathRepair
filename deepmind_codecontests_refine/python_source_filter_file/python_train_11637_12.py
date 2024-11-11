N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
judge = True

A_num = [0] * (N+1)
B_num = [0] * (N+1)
C = [0] * (N+1)
D = [0] * (N+1)

for a in A:
  A_num[a] += 1
for b in B:
  B_num[b] += 1
  
for a,b in zip(A_num,B_num):
  if a+b>N:
    judge = False
    break

if judge:
  for i in range(1,N+1):
    C[i] = C[i-1] + A_num[i]
    D[i] = D[i-1] + B_num[i]
  x = -float('inf')
  for i in range(1,N+1):
    x = max(x, C[i] - D[i-1])
    
  ans = B[-x:] + B[:x]
  print('Yes')
  print(' '.join(map(str,ans)))
  
else:
  print('No')
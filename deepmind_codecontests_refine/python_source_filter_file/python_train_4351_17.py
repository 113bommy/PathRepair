A = [list(map(int,input().split())) for _ in range(3)]
n = int(input())
B = [int(input()) for _ in range(n)]

F = [0]*100
for b in B:
  F[b]=1

ans = 'No'  
for i in range(3):
  c = 0
  d = 0
  for j in range(3):    
    c += F[A[i][j]]
    c += F[A[j][i]]
  if c==3 or d==3:
    ans ='Yes'
if F[A[0][0]]+F[A[1][1]]+F[A[2][2]] == 3 or F[A[0][2]]+F[A[1][1]]+F[A[2][0]] == 3:
  ans ='Yes'
  
print(ans)
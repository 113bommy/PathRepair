H,W,K=map(int,input().split())
A = [list(input()) for i in range(H)]

N=1
for i in range(H):
  for j in range(W):
    if A[i][j]=='#':
      A[i][j]=N
      N+=1
      
for i in range(H):
  for j in range(W-1):
    if str(A[i][j]).isdigit() and A[i][j+1]=='.':
      A[i][j+1]=A[i][j]

for i in range(H):
  for j in range(0,W-1):
    if str(A[i][(W-j-1)]).isdigit() and A[i][(W-j-2)]=='.':
      A[i][W-j-2]=A[i][W-j-1]

for i in range(H-1):
  if A[i+1]==['.']*W:
    A[i+1]=A[i]

for i in range(H-1):
   if A[H-i-2]==['.']*W:
    A[H-i-2]=A[H-i-1]
    
for a in A:
  print(*a)
H,W = map(int,input().split())
B = []
C = []

for h in range(H):
  A = list(map(int,input().split()))
  w = 0
  for w in range(1,W):
    if A[w-1]%2:
      C.append((w+1,h,w+1,h+1))
      A[w]+=1
  B.append(A[w])
  
  if h and B[-2]%2:
    C.append((h,W,h+1,W))
    B[h]+=1
    
print(len(C))
for c in C:
  print(*c)

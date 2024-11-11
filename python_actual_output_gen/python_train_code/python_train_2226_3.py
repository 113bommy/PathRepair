N,M = map(int,input().split())
ab = [[int(i) for i in input().split()] for _ in range(M)]

A = []
B = [0]*N
for a,b in ab:
  if a==1:
    A.append(a)
  if b==N:
    B[a]=1

for a in A:
  if B[a]==1:
    print("POSSIBLE")
    break
else:
  print("IMPOSSIBLE")
n, m = map(int, input().split())
A = [0]*m
B = [0]*m
for i in range(m):
  A[i],B[i] =map(int, input().split())

al = n*(n-1)//2
ansl = [al]
d = list(range(m+1))
dl = [[_] for _ in range(m+1)]

for i in range(m-1,0,-1):
  x = d[A[i]]
  y = d[B[i]]
  x,y = max(x,y),min(x,y)
  if x > y:
    al -= len(dl[x])*len(dl[y])
    for i in dl[y]:
      d[i] = x
    dl[x] += dl[y]
  ansl.append(al)

for i in range(m-1,-1,-1):
  print(int(ansl[i]))
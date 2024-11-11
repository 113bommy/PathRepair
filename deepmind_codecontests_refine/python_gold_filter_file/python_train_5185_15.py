N,D=map(int,input().split())
L=[list(map(int,input().split())) for i in range(N)]
n=0
for i in range(N):
  for j in range(i):
    DD=0
    for k in range(D):
      DD+=(L[i][k]-L[j][k])**2
    if any(n**2==DD for n in range(1,128)):
      n+=1
print(n)
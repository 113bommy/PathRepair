N,D=map(int,input().split())
c=0
X=[]
for i in range(N):
  X.append(list(map(int,input().split())))

for j in range(N):
  for k in range(j+1,N):
    tmp=sum([(X[j][l]-X[k][l])**2 for l in range(D)])
    if tmp in [y**2 for y in range(21)]:
      c +=1
print(c)
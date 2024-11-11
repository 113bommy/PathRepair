H,W=map(int,input().split())
c=[]
for i in range(10):
  c.append(list(map(int,input().split())))

for i in range(10):
  for j in range(10):
    for k in range(10):
      c[i][j]=min(c[i][j],c[i][k]+c[k][j])
#print(c)

ans=0
for i in range(H):
  A=list(map(int,input().split()))
  for j in A:
    if j>=0:
      ans+=c[j][1]
print(ans)
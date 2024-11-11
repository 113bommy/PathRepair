h,w,k=map(int,input().split())
b=[list("#"*(w+2))]+[list("#"+input()+"#")for _ in range(h)]+[list("#"*(w+2))]
for i in range(h+2):
  for j in range(w+2):
    if b[i][j]=="S":
      Q=[(i,j)]
      ans=0--min(i-1,h-i,j-1,w-j)//k
co=0
dx=[1,0,-1,0]
dy=[0,1,0,-1]
while Q and co!=k:
  co+=1
  P=[]
  for i,j in Q:
    ans=min(ans,0--min(i-1,h-i,j-1,w-j)//k)
    for x,y in zip(dx,dy):
      if b[i+x][j+y]==".":
        b[i+x][j+y]=0
        P.append((i+x,j+y))
        if i+x in [1,h] or j+y in [1,w]:print(1);exit()
  Q=P
print(ans+1)
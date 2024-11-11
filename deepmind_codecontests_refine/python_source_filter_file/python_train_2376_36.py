h,w=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(h)]
z=[]
m=[]
for i in range(h):
  for j in range(w)[::(-1)**i]:
    m.append((i,j))
for i in range(h*w-1):
  x,y=m[i]
  if a[x][y]%2:
    X,Y=m[i+1]
    z.append([x,y,X,Y])
    a[X][Y]+=1
print(len(z))
for i in z:
  print(*i)
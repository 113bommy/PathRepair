H, W=map(int, input().split())
S=[input() for _ in range(H)]

tate=[[0]*W for _ in range(H)]
yoko=[[0]*W for _ in range(H)]

for i in range(W):
  j=0
  while j<H:
    x=0
    while j+x<H and S[j+x][i]=='.':
      x+=1
    if x==0:
      tate[j][i]=0
      j+=1
    else:
      for t in range(x):
        tate[j+t][i]=x
      j+=x

for i in range(H):
  j=0
  while j<W:
    x=0
    while j+x<W and S[i][j+x]=='.':
      x+=1
    if x==0:
      yoko[i][j]=0
      j+=1
    else:
      for t in range(x):
        yoko[i][j+t]=x
      j+=x
      
print(max([max([tate[i][j]+yoko[i][j]-1 for j in range(W)]) for i in range(H)]))
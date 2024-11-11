H,W=map(int,input().split())
Grid=[]
for _ in range(H):
  Grid.append(list(input()))
tmp=0
ans=0
up=[[0 for _ in range(W)] for _ in range(H)]
down=[[0 for _ in range(W)] for _ in range(H)]
left=[[0 for _ in range(W)] for _ in range(H)]
right=[[0 for _ in range(W)] for _ in range(H)]

for i in range(H):
  for j in range(W):
    if Grid[i][j]=='.':
      left[i][j]=left[i][j-1]+1
      up[i][j]=up[i-1][j]+1
    if Grid[H-i-1][j]=='.':
      down[H-i-1][j]=down[-i][j]+1
    if Grid[i][W-j-1]=='.':
      right[i][W-j-1]=right[i][-j]+1
      
for i in range(H):
  for j in range(W):
    ans=max(ans,left[i][j]+up[i][j]+down[i][j]+right[i][j]-3)
print(ans)    
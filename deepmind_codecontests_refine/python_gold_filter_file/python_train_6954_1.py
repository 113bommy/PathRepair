h,w=map(int,input().split())
s=[input() for _ in range(h)]
d1=[[0]*(w+1) for _ in range(h+1)]
d2=[[0]*(w+1) for _ in range(h+1)]
for i in range(h):
  k=1
  for j in range(w):
    if s[i][j]=='.':d1[i+1][k]+=1
    else:k=j+2
  for j in range(w):
    if s[i][j]=='.':d1[i+1][j+1]+=d1[i+1][j]
for j in range(w):
  k=1
  for i in range(h):
    if s[i][j]=='.':d2[k][j+1]+=1
    else:k=i+2
  for i in range(h):
    if s[i][j]=='.':d2[i+1][j+1]+=d2[i][j+1]
ans=0
for i in range(1,h+1):
  for j in range(1,w+1):
    d1[i][j]+=d2[i][j]-1
  ans=max(ans,max(d1[i]))
print(ans)
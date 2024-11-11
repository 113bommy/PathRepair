n,m=map(int,input().split())
grid=[]
for i in range(n):
  s=input()
  grid.append(s)
grid2=[]
for i in range(n):
  grid2.append([])
  for j in range(m):
    grid2[-1].append(0)
for j in range(m):
  lastchar=''
  int1=0
  int2=0
  int3=0
  for i in range(n):
    if grid[i][j]==lastchar:
      int3+=1
    else:
      int1=int2
      int2=int3
      int3=1
      lastchar=grid[i][j]
    if int1>=int2 and int2==int3:
      grid2[i][j]=int3
score=[]
for i in range(n):
  score.append([])
  for j in range(m):
    score[-1].append(0)
for i in range(n):
  for j in range(m):
    t=grid2[i][j]
    if t>0:
      if j>0 and grid2[i][j-1]==t and grid[i][j]==grid[i][j-1] and grid[i-t][j]==grid[i-t][j-1] and grid[i-2*t][j-1]==grid[i-2*t][j]:
        score[i][j]=score[i][j-1]+1
      else:
        score[i][j]=1
ans=0
for i in range(n):
  for j in range(m):
    ans+=score[i][j]
print(ans)
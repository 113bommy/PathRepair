n,d,k=map(int,input().split())
if n==1:
  print("NO")
  exit()
if k==1:
  if n==2 and d==1:
    print("YES")
    print(1,2)
  else:
    print("NO")
  exit()
if n<d+2:
  print("NO")
  exit()
co=1
ans=[]
for i in range(1,d+1):
  ans.append((i,i+1))
  co+=1
def dfs(r,dist,co):
  if 2<=r<d:
    t=k-2
  else:
    t=k-1
  if co==n:
    return co
  for _ in range(t):
    if dist==d:
      return co
    if co==n:
      return co
    co+=1
    ans.append((r,co))
    co=dfs(co,dist+1,co)
  return co
for i in range(2,d+1):
  co=dfs(i,max(i-1,d-i+1),co)
if co==n:
  print("YES")
  for j in ans:
    print(*j)
else:
  print("NO")
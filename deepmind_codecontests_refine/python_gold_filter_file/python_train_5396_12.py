n,m = map(int,input().split())
cnt = 0
grid = [list(input()) for i in range(n)]
grid2 = [[]]*n
for i in range(n):
  cnt += "".join(grid[i]).count("#")
  grid2[i] = ["#"] + grid[i] + ["#"]
  
grid2.insert(0,["#"]*(m+2))
grid2.append(["#"]*(m+2))
grid2[1][1] = 0
loc =[[1,1]]

for k in range(1,n*m):
  next_loc = []
  for y,x in loc:
    for i,j in ([-1,0],[1,0],[0,-1],[0,1]):
      if grid2[y+i][x+j] == ".":
        grid2[y+i][x+j] = k
        next_loc.append([y+i,x+j])
  loc = next_loc
#  print(loc,k)
  if [n,m] in loc:
    break

ans = n*m - (k+1+cnt)

print(ans if ans >= 0 else -1)
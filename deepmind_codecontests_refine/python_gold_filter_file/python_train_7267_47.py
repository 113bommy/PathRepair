N = int(input())
A = input().split()
px = py = pz = 0
for a in A:
  if a == '1':
    px += 1
  elif a == '2':
    py += 1
  elif a == '3':
    pz += 1

nx = px + py + pz
ny = py + pz
nz = pz

dp = [[[0]*(nx+1) for y in range(ny+1)] for z in range(nz+1)]

for z in range(nz+1):
  for y in range(ny+1-z):
    for x in range(nx+1-z-y):
      if x == y == z == 0:
        continue
      
      else:
        s = x + y + z
        t = N/s
        if x > 0:
          t += dp[z][y][x-1]*x/s
        if y > 0:
          t += dp[z][y-1][x+1]*y/s
        if z > 0:
          t += dp[z-1][y+1][x]*z/s
        
        dp[z][y][x] += t


print(dp[pz][py][px])
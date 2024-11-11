N, *S = open(0).read().split()
N = int(N)
ans = 0
for p in range(N):
  flag = False
  for i in range(N):
    for j in range(N):
     x = i
     y = (j-p)%N
     a,b = y, (x+p)%N
     if S[i][j] != S[a][b]:
       flag = True
       break
    if flag:
      break
  else:
    ans+= N
print(ans)
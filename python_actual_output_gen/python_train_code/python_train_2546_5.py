D, G = map(int,input().split())
PC = [list(map(int,input().split())) for _ in range(D)]

ans = 1e9
for i in range(1 << D):
  point = 0
  cnt = 0
  for j in range(D):
    if (i >> j)& 1:
      point += PC[j][0]*(j+1)*100+PC[j][1]
      cnt += PC[j][0]
    else:
      tmp = j
  if point < G:
    R = G-point
    if (PC[tmp][0]-1)*(tmp+1)*100 < R:
      continue
    cnt += R//(100*(tmp+1))
  ans = min(ans, cnt)
print(ans)
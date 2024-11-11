n,m = map(int,input().split())
lis = [list(map(int,input().split())) for i in range(n)]
cou = 0
lis.sort()
for i in range(n):
  cou += lis[i][1]
  if cou <= m:
    print(lis[i][0])
    exit()

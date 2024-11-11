mai,yen=map(int,input().split())
for i in range(mai+1):
  for j in range(mai+1-i):
    if 10000*i+5000*j+1000*(mai-i-j)==yen:print(i,j,mai-i-j);exit()
else:print(-1,-1,-1)
N,Y=map(int, input().split())
res=(-1,-1,-1)
for x in range(N+1):
  for y in range(N+1-x):
    if N-x-y>=0 and 10000*x+5000*y+1000*(N-x-y)==Y:
      res=[x,y,N-x-y]
print(res[0],res[1],res[2])
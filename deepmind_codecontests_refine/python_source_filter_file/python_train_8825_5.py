n,m=map(int,input().split())
for i in range(1,1000):
  if int(i*0.08)==n and int(i*0.1)==m:
    print(i)
    break
else:
  print(-1)
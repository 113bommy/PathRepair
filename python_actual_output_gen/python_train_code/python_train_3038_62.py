a,b=map(int,input().split())
for i in range(100):
  if i*8//100==a and i//10==b:
    print(i)
    exit(0)
print(-1)

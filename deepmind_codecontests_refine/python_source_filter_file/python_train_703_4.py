n,m=map(int,input().split())
sc=[list(map(int,input().split())) for i in range(m)]

for i in range(10**n):
  i2=str(i)
  if len(i2)==n and all([i2[s-1]==str(c) for s,c in sc]):
      print(i2)
      break
print(-1)
n,m=map(int,input().split())
sc=[list(map(int,input().split())) for i in range(m)]
# print(sc)
for i in range(10**n):
  i2=str(i)
#   print(i2)
  if len(i2)==n and all([i2[s-1]==str(c) for s,c in sc]):
      print(i2)
      exit()
print(-1)

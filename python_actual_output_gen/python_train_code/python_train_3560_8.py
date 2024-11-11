n,v=map(int,input().split())
z=[]
for i in range(n):
  l=list(map(int,input().split()))
  for j in range(1,len(l)):
    if l[j]<v:
      z.append(l[0])
      break
if len(z)==0:
  print(0)
else:
  print(len(z))
  print(*z)
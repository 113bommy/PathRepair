n,a,b=(int(x) for x in input().split())
c=0
for i in range(n+1):
  d=0
  for j in str(i):
    d+=int(j)
  if a<=d<=b:
    c+=1
print(c)
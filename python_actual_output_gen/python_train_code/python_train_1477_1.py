n,m=map(int,input().split())
l=[0]*n
for i in range(m):
  a,b=map(int,input().split())
  l[a-1]+=1
  l[b-1]+=1
b=True
for i in range(m):
  if l[i]%2!=1:
    b=False
if b:
  print("YES")
else:
  print("NO")
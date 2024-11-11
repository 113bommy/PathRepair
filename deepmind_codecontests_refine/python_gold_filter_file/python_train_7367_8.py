l,r,d=map(int,input().split())
c=0
for i in range(1,101):
  if l<=d*i<=r:
    c+=1
print(c)

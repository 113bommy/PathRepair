l,r,d=map(int,input().split())
co=0
for i in range(l,r+1):
  if i%d==0:
    co+=1
print(co)
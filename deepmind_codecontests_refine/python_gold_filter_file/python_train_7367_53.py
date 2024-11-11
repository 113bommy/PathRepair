l,r,d=map(int,input().split())
x=0
for i in range(l,r+1):
  if i%d==0:
    x+=1
print(x)
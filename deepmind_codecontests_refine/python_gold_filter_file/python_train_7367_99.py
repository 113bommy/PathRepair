l,r,n=map(int,input().split())
c=0
for i in range(l,r+1):
  if i%n==0:
    c+=1
print(c)
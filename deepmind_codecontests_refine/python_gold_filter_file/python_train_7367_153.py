c=0
a,b,d=map(int,input().split())
for i in range(a,b+1):
  if i%d==0: c+=1
print(c)
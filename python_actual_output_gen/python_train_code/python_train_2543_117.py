c=0
a,b,d=map(int,input().split())
for i in range(a,b):
  if i%d==0: c+=1
print(c)
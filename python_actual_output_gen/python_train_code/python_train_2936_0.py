H,a,b=map(int,input().split())
c=0
for i in range(a,b):
  if H%i==0 :
    c+=1
print(c)

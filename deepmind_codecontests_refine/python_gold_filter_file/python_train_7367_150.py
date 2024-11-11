L,R,d=map(int,input().split())
z=0
for i in range(L,R+1,1):
  if i%d==0:
    z+=1
print(z)
L,R,D=map(int,input().split())
A=0
for i in range(L,R+1):
  if i%D==0:
    A+=1
print(A)

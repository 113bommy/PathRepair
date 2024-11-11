x,y,a,b=map(int,input().split())
p=max(a,b+1)
A=[]
for i in range(p,x+1):
  for j in range(b,i):
    A.append([i,j])
print(len(A))
for i,j in A:
  print(i,j)
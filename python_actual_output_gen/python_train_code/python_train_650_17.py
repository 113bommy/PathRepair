n,d=map(int,input().split())
k=0
for i in range(n):
  x,y=map(int,input().split())
  if x**2+y**2<=d:k+=1
print(k)
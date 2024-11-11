r,g,b,n=map(int,input().split())
t=0
for i in range(n):
  for j in range(n):
    x=n-i*r-j*g
    if x%b==0 and x/b>=0:
      t+=1
print(t)
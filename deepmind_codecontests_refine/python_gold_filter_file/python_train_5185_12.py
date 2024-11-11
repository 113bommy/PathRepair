n,b=map(int,input().split())
x=[list(map(int,input().split())) for i in range(n)]

count=0
for i in range(n):
  for j in range(i+1,n):
    t=0
    for k in range(b):
      t += (x[i][k]-x[j][k])**2
    t = t**(1/2)
    if t.is_integer():
      count += 1
print(count)
    
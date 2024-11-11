r,g,b,n = map(int,input().split())
c = 0
for i in range(n//r+1):
  for j in range(n//g+1):
    k = (n-i*r-j*g)
    if k%b == 0 and k >= 0:
      c += 1
print(c)
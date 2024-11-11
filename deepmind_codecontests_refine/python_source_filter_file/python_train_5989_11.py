def fac (n):
  t = 1
  for i in range(1,n+1):
    t = t * i
  return(t)

N = int(input())
y = []
a,b= 0,0
for i in range(N):
    y += list(map(str , input() .split()))

for i in range(N):
  r = y[i].count('C')
  if r > 0 :
    a += fac(r) / (fac(2)*fac(r - 2)) 
c = int(a)

for j in range(N):
  for k in range(N):
    if y[k][j] == 'C':
      b += 1  
  if b > 0:
    c+= fac(b) / (fac(2)*fac(b - 2))  
  b = 0  

print(int(c))
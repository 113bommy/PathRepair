n, k = map(int, input().split())
x = 0
y = 0
z = n*(k-1)
a = []

for i in range((k-1)*n + 1, n*n + 1, n-k+1):
  x+=i
  
print(x)


for i in range(0, n):
  for j in range(1, k):
    a.append(y+j)
  y +=k-1
    
  for j in range(1, n-k+2):
    a.append(z+j)
  z+=n-k+1
  
  print(' '.join([str(i) for i in a]))
  a.clear()
  
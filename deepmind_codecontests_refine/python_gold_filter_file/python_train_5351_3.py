n,m = map(int, input() .split())
x = []
y = ['n']*m
b,c,d,e = 0,0,0,0
for i in range(n):
  x += [list(str(input()))]
for j in range(n):
  for k in range(m):
    if x[j][k] == '.':
      b+=1
    if b == m:
      c+=m
      x[j] = y
  b = 0      
for j in range(m):
  for k in range(n):
    if x[k][j] =='.' :
      d+=1
    elif x[k][j] == 'n':
      e+=1  
    if d+e == n:
      c+=d
  d = 0
  e = 0
print(c)
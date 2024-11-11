n,m = map(int, input() .split())
x = []
t = [-1]*m
j = 0
c= False
for i in range(m):
  x += list(map(int , input() .split()))
for k in range(m):
  t[j] = x[k] % n
  j+=1
for l in range(m):
  for y in range(0,l): 
    if l!=y:
      if t[l] == t[y]:
        c = True
        print(l+1)
        exit()      
if c == False:
  print(-1) 
X,Y = map(int,input().split())
 
c1 = (2*Y-X)
rest = c1%3
c1 = c1//3
if (rest!=0)or((X-c1)<0)or((Y-2*c1)<0)or(c1<0):
  print(0)

else:
  c2 = Y-2*c1
  c3 = c1+c2+1
  mod = 10**9+7
  c4 = min(c1,c2)
  x = 1
  y = 1
  for i in range(1,c4+1):
    x = x * (c3-i) % mod
    y = y * i % mod
    
  result = x * pow(y,mod-2,mod) % mod
 
  print(result)
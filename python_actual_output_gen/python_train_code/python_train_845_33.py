r = int(input())
flag = False

for x in range(1, int(r ** 0.5) + 1):
  y = (r - (x**2) - x - 1) / (2*x)
  
  if(y < 0):
    break
  
  if(y == int(y)):
    flag = True
    print(x, int(y))
    break
  
if(not flag):
  print("NO")
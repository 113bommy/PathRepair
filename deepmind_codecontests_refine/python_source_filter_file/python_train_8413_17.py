import math
def near_sqrt(a,b):
  c = a * b
  d = math.floor(math.sqrt(c))
  if d*(d+1) < c:
    return d
  else:
    return (d-1)
  
q = int(input())
for i in range(q):
  a,b = map(int, input().split())
  c = near_sqrt(a,b)
  d = (a*b)%(c+1)
  if d == 0 and a!=0:
    print(math.floor((a*b)/(c+1))+c-2)
  else:
    print(math.floor((a*b)/(c+1))+c-1)
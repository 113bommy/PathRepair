import math

def smallestDividor(n):
  if(n%2 == 0):
    return 2
  for j in range(3,int(math.sqrt(n)),2):
    if(n%j == 0):
      return j
  return n

n = int(input())
compt = 0
while(n != 0):
  d = smallestDividor(n)
  if(d%2 != 0 ):
    n = n - d
  else:
    break
  compt+=1
compt+= n//2
print(compt)
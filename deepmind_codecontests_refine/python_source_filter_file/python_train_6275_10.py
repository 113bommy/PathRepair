import math
def func(x):
  ans=math.inf
  
  i=1
  while i*i<=x:
    if x%i==0:
      ans=min(ans,(i-1)+(x/i-1))
    else:
      ans=min(ans,(i-1)+int(x//i))
    i+=1

  return ans

t=int(input())
for i in range(t):
  n=int(input())
  print(func(n))


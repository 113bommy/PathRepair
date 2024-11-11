import math
t=input('') 
n=len(t)
c=t.count('a')
if n%2 == 0:
  if c > (n//2):
    print(n)
  else:
    print((2*c)-1)
else:
  if c >= (n//2)+1:
    print(n)
  else:
    print((2*c)-1)     

 
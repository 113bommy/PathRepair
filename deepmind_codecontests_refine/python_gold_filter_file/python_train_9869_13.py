import math
import fractions

a,b = map(int,input().split())

a = fractions.gcd(a,b)

i = 2
ans = 1

while i <= a**0.5:
  tmp = a
  while a%i==0:
    a /= i
  if not a == tmp:
    ans += 1
  i += 1
if a >1 :
  ans += 1
  
print(ans)
import math

n = int(input())
s = int(input())

ans = []

def f(b, n):
  if n < b:
    return n
  else:
    return f(b, n//b) + n % b

if n == s:
  ans.append(n+1) 
  
elif n < s:
  ans.append(-1)
  
else:
  rootn = int(math.sqrt(n))
  for b in range(2, rootn+1):
    if s == f(b, n):
      ans.append(b)
      break
      
  for p in range(1, rootn):
    b = (n-s)//p + 1
    if s == p + n%b:
      ans.append(b)
      
if not ans:
  ans.append(-1)

print(min(ans))
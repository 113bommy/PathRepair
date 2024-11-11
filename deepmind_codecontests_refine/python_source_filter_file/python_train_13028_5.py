from math import sqrt

n = int(input())
sieve = [False if i <2 else True for i in range(2 * n+1)]
check = round(sqrt(2 * n))
for i in range(2, check):
  if(sieve[i] == True):                  
    for j in range(i+i, 2 * n+1, i):        
      sieve[j] = False              

A = list(map(int, input().split()))
n1 = 0
n2 = 0
for a in A:
  if a == 1:
    n1 += 1
  else:
    n2 += 1
res = []
prefix = 0
for i in range(n):
  if n1 > 0 and n2 > 0:
    if sieve[prefix + 1]:
      prefix += 1
      res.append(1)
      n1 -= 1
    elif sieve[prefix + 2]:
      prefix += 2
      res.append(2)
      n2 -= 1
    else:
      prefix += 1
      res.append(1)
      n1 -= 1
  elif n2 > 0:
    res.append(2)
    prefix += 2
    n2 -= 1
  else:
    res.append(1)
    prefix += 1
    n1 -= 1
print(*res)

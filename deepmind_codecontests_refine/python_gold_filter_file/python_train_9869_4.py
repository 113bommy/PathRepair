a,b = map(int,input().split())
def gcd(x,y):
  while y != 0:
    cur = x
    x = y
    y = cur%y
  return x
t = gcd(a,b)
L = []
for i in range(2,10**6+1):
  while t%i == 0:
    t = t//i
    if i not in L:
      L.append(i)
if t != 1:
  L.append(t)
print(len(L)+1)

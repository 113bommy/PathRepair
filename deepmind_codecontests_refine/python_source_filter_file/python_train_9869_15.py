import fractions
A,B = map(int,input().split())
x = fractions.gcd(A,B)
pf = {}
for i in range(2,int(x**0.5)+2):
  while x%i == 0:
    pf[i] = pf.get(i,0) +1
    x //= i
if x > 1:
  pf[m] = 1
print(len(pf)+1)
def gcd(a,b):
  while b:
    a,b=b,a%b
  return a
a,b=map(int,input().split())
g=gcd(a,b)

c=1
for i in range(2,10**6+1):
  if g%i==0:
    c+=1
    while g%i==0:
      g//=i
if g!=1:
  c+=1
print(c)
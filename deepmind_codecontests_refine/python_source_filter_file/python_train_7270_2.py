import fractions
n=int(input())
a=1
for i in range(n):
  b=int(input())
  a=a/fractions.gcd(a,b)*b
print(a)
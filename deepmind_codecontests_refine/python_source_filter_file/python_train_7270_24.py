import fractions
n=int(input())

ans=1
for i in range(n):
  x=int(input())
  ans=ans/fractions.gcd(ans,x)*x

print(int(ans))


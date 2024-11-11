import fractions
N,X=[int(s) for s in input().split()]
ls=[int(s)-X for s in input().split()]
a=0
for e in ls:
  a=fractions.gcd(a,e)
print(a)
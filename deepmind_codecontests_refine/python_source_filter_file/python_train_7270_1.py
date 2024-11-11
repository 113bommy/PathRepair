from fractions import gcd
n=int(input())
ans=int(input())
for i in range(1,n):
  t=int(input())
  ans=ans*t/gcd(ans,t)
print(ans)
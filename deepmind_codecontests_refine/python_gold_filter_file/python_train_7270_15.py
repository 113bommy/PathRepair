from fractions import gcd
def lcm(a,b):return a*b//gcd(a,b)
n=int(input())
ans=1
for i in range(n):
  t=int(input())
  ans=lcm(ans,t)
print(ans)
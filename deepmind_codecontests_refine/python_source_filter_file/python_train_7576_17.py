from fractions import gcd
from functools import reduce
n=int(input())
a=list(map(int,input().split()))
x=reduce(lambda x,y: y//gcd(x,y)*x, set(a))
ans=0
for i in a:
  ans+=x//i
  ans%=1000000007
print(ans)
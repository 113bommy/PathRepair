from math import gcd
n=int(input())
a=list(map(int,input().split()))
x=a[0]
for i in a:
  x=gcd(x,i)
print(x)
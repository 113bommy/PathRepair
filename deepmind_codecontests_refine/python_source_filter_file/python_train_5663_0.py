#import math

def gcd(a, b):
   if b == 0:
      return a
   else:
     return gcd(b, a % b)

p, q = map(int, input().split())
n = int(input())
data = list(map(int, input().split()))
a = 1
b = data[-1]
for i in range(2, n + 1):
  a = b * data[n - i] + a
  a, b = b, a

a, b = b, a
nod = gcd(p, q)
p = p / nod
q = q / nod


if p == a and q == b:
  print("YES")
else:
  print("NO")

from math import gcd
n = int(input())
a = list(map(int,input().split()))

g = a[0]
for i in a:
    g = gcd(g,i)

print(i)

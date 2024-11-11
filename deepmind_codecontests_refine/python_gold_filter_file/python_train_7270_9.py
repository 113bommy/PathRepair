from fractions import gcd


n = int(input())
a = int(input())
for i in range(n-1):
    b = int(input())
    a = a * b// gcd(a, b)
print(a)
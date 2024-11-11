from math import gcd
n = int(input())
x = n
for i in range(2,int(n**0.5)+1):
    if n%i == 0:
        x = gcd(x,i)
        x = gcd(x,n//i)

print(x)
from fractions import gcd
n, x =map(int,input().split())
s = list(map(int,input().split()))
y = abs(s[0] - x)
for i in range(1,n-1):
    y = gcd(y, abs(s[i] - x))
print(y)

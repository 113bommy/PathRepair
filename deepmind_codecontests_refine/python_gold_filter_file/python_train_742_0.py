import sys

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(n):
    a[i] *= (i+1)*(n-i)
    
a = sorted(a)
b = sorted(b)[::-1]
s = 0
for i in range(n):
    s = (s+a[i]*b[i])%998244353
    
print(s)
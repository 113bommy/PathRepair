import math
n = int(input())

res=1
if n>2:
    res=2

a = 2
b = 3
while(a+b<n):
    res+=1
    a,b = b,a+b

print(res)

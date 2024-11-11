import math
n,x = [int(x) for x in input().split()]
s = 0
if n<x<n**2:
    for i in range(math.ceil(x/n),n+1):
        if x%i == 0:
            s += 1
else:
    for i in range(1,n+1):
        if x%i == 0:
            s += 1
print(s)
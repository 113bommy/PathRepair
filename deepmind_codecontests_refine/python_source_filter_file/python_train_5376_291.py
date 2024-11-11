import math
n=int(input())
m=int(input())
for k in range(n+1):
    r=2**k
    if(r>=m):
        break
print(m%r)
1

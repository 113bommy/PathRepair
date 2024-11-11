import math
n=int(input())
r=int(math.sqrt(n))
ctr=0
for i in range(1,r+2):
    if n%i==0 and n//i>i:
        ctr+=n//i-1
print(ctr)

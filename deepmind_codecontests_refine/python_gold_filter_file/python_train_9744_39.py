import math
n,k = input().split()
n = int(n)
k = int(k)
s = input().split()
sum = 0
for x in s:
    sum = sum + int(x)
ar = sum / n
if(ar + 0.5 < k):
    print("%d" %math.ceil(2.0*(n*1.0*(k-0.5) - sum)))
else:
    print(0)

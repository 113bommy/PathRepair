import math
n = int(input())
nn = int(math.sqrt(n))
for i in range(nn,n+1):
    if n%i==0:
        print(len(str(i)))
        break

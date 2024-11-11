import math
n = int(input())
nn = int(math.sqrt(n))
for i in range(nn,0,-1):
    if n%i==0:
        print(len(str(n//i)))
        break

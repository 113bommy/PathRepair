import math
N=int(input())
p=math.floor(math.sqrt(N))
while N % p > 0:
    p-=1
q=N//p
print(p+q)
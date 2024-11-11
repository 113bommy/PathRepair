import math
n = int(input())
m = math.ceil(n**0.5)
while (2*(m-1))<(n-1):
    m=m+1
print(m)
N=n//2
N1=n-N
for i in range(N):
    print(1,i+1)
for i in range(N1):
    print(m,i+1)
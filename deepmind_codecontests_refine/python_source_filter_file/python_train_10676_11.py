import math

n = int(input(''))
a=1
f = 2

for i in range(n):
    k = i+2
    z = (k*k*a*a-f)/(k-1)
    print(int(z))
    f = math.sqrt(f+z*(k-1))
    a=a+1

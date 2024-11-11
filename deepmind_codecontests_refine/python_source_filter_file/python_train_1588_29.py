import math

t=int(input())
for _ in range(t):
    n=int(input())
    n2=2*n
    h=1/math.sin(math.pi/n2)
    print(h)

t=int(input())
import math

for _ in range(t):
    n=int(input())
    x=math.ceil(n/3)
    l=['9']*(n-x)+['8']*x
    print("".join(l))
n,x = map(int,input().split())
import math

def f(x,y):
    a = min(x,y)
    b = max(x,y)    
    if a == 0:
        return 0
    elif b%a == 0:
        return 2*b-1
    else:
        return 2*a*math.floor(b/a) + f(a,b%a)

print(n+f(x,n-x))
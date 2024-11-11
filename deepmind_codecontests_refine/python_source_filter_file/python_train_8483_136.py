import math
a,b = input().split(' ')
a=int(a)
b=int(b)
c = b if(a>b) else b
n = (abs(a-b))//2
print(c,n)

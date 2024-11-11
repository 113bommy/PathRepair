import math
b= int(input())
x1 = math.ceil((b+1)/2)
print(x1)
i=0
x=1
y=1
while i<b:
    print(x," ",y)
    if i>(x1-1):
        y=y+1
    else:
        x=x+1
    i=i+1

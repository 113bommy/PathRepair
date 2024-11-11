import math

n = int(input())

for _ in range(n):
    xa,ya,ra,xb,yb,rb = map(float, input().split())
    len=math.sqrt((xa-xb)**2+(ya-yb)**2)

    if len + rb <= ra:
        print("2")
    elif len + ra <= rb:
        print("-2")
    elif len <= ra + rb:
        print("1")
    else:
        print("0")
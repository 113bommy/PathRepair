import math

x, y = input().split()
x=int(x)
y=int(y)
taxi = int(input())
best = 999999999999
for i in range(0,taxi):
    a,b,c = input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    t = math.sqrt(math.pow(x-a,2)+math.pow(x-b,2))/c
    if t < best:
        best = t
print(t)

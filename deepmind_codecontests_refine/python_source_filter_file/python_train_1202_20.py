import math
n = input()
if (len(n)%2==1):
    print(-1)
    exit(0)
x,y = 0,0
for i in n:
    if (i=='R'):
        y+=1
    if (i=='U'):
        x+=1
    if (i=='D'):
        x-=1
    if (i=='L'):
        y-=1
x = math.fabs(x)
y = math.fabs(y)
s = x + y
s = math.fabs(s)
s = int(s)
if (s>1):
    s //=2
else:
    s = 1
print(s)
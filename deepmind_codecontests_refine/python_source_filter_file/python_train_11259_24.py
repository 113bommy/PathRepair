a,b=map(int,input().split());s=1000000000000;from math import ceil as e;p=0
for i in range(1,a+1):
    c,d=map(int,input().split())
    if b==c:exit(print(i))
    if c>b:
        if c-b<s:s=c-b;p=i
    else:
        f = e(abs(b - c) / d) * d
        if s >= c + f: p = i;s = c + f
print(p)
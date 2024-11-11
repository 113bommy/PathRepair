from math import ceil
x, y, m=map(int, input().split())
if max(x, y)>=m:
    exit(print(0))
if x<=0 and y<=0:
    exit(print(-1))
x, y=min(x, y), max(x, y)
steps=0
if x<0:
    steps+=ceil((abs(x)+y-1)/y)
    csteps=ceil((abs(x)+y-1)/y)
    x=y*csteps+x
while max(x, y)<m:
    x, y=x+y, max(x, y)
    steps+=1
exit(print(steps))
    

    
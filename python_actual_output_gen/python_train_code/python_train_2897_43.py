y,b,r=map(int,input().split())
if y>b:
    y=b-1
else:
    y=y
if r<b:
    b=r-1
else:
    b=b
if y<r:
    if r==y+1:
        y=r-2
else:
    y=r-2
b=y+1
r=b+1
while b==y+1 and r==b+1:
    print(y+b+r)
    break

    
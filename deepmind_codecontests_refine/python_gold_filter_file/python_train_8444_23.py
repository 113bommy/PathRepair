y,b,r=[int(i) for i in input().split()]
a=y+2
c=b+1
d=r
if d<=c and d<=a:
    print((r-1)*3)
elif c<=a and c<=d:
    print(b*3)
else:
    print((y+1)*3)

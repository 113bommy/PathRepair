y,b,r=[int(i) for i in input().split()]
a=y+2
k=b+1
c=r
if c<=k and c<=a:
    print((r-1)*3)
elif k<=a and k<=c:
    print(b*3)
else:
    print((y+1)*3)

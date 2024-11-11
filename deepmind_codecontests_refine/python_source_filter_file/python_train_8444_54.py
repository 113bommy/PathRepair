y,b,r=map(int,input().split())
if r-1<=b and r-2<=y:
    print(3*y-3)
elif b+1<=r and b-1<=y:
    print(3*b)
else:
    print(3*y+3)
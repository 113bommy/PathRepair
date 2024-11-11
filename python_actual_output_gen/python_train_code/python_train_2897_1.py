y,b,r=[int(i) for i in input().split()]
if 1<=y<=100 and 2<=b<=100 and 3<=r<=100:
    if y<b<=r:
        print(y+y+1+y+2)
    elif b<y<=r or b<r<=y:
        print(b-1+b+b+1)
    elif r<=b<=y or r<y<=b:
        print(r-2+r-1+r)
    elif y<r<=b and r>=y+2:
        print(y+y+1+y+2)
    else:print(r-2+r-1+r)
else:
    print("invalid inputs")


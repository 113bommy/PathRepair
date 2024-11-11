y,b,r=map(int,input().split())
if b>=y+1 and r>=y+2:
    print(3*(y+1))
elif y>=b-1 and r>=b+1:
    print(3*b)
elif y>=r-2 and b>=r-1:
    print(3*(r-1))


W,H,x,y,r=map(int,input().split())
if 0<=x+r<=W and 0<=y+r<=H:
    print("Yes")
else:
    print("No")
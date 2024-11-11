W,H,x,y,r=map(int,input().split())
if y+r<=H and y>=r and x+r<W and x>=r:
    print("Yes")
else:
    print("No")

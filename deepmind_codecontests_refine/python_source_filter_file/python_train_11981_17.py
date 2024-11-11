W,H,x,y,r=map(int,input().split())
if x+r>W | y+r>H | x-r<0 | y-r<0:
    print("No")
else:
    print("Yes")
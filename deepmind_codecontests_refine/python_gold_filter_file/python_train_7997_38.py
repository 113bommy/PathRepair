XY = input().split()
X,Y = int(XY[0]), int(XY[1])
if(X % Y != 0):
    print(X)
else:
    print(-1)
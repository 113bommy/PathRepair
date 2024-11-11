XY = input().split()
X,Y = int(XY[0]), int(XY[1])
if(Y % X == 0):
    print(-1)
else:
    print(X)
n,m,k = map(int, input().split())
mx=[[0]*(m+2) for i in range(n+2)]

for i in range(k):
    x,y = map(int, input().split())
    mx[x][y] = 1
    if mx[x-1][y-1]+mx[x-1][y]+mx[x-1][y]==3 or mx[x][y-1]+mx[x+1][y-1]+mx[x+1][y]==3 or mx[x-1][y]+mx[x-1][y+1]+mx[x][y+1]==3 or mx[x+1][y]+mx[x][y+1]+mx[x+1][y+1]==3:
        print(i+1)
        break
else:
    print(0)

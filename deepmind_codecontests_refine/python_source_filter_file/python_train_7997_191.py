x,y = map(int,input().split())
if y%x == 0:
    print(-1)
else:
    print(x*y+1)
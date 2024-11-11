W,H,x,y = list(map(int,input().split(" ")))
print(W*H/2,1  if x == W/2 and y == W/2 else 0)
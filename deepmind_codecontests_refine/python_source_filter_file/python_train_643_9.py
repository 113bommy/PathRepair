n,sx,sy = list(map(int,input().split()))
right = 0
left = 0
up = 0
down = 0
for i in range(n):
    x,y = list(map(int,input().split()))
    #for right
    if sx<=x:
        right+=1
    if sx>=x:
        left+=1
    if sy>=y:
        down+=1
    if sy<=y:
        up+=1
        
m = max(right,left,up,down)
print(m)
if m==right:
    print(sx+1,sy)
elif m==left:
    print(sx-1,sy)
elif m==up:
    print(sx,sy+1)
else:
    print(sx,sy-1)

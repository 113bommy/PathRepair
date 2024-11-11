r1,r2 = map(int,input().split())
c1,c2 = map(int,input().split())
d1,d2 = map(int,input().split())
y = (d2+(r2-c2))//2
x = d2-y
w = r1-x
z = d1-w
if not 1<=w<=9 or not 1<=x<=9 or not 1<=y<=9 or 1<=z<=9:
    print(-1)
    exit()
if w == x or w == y or w == z or x == y or x == z or y == z:
    print(-1)
    exit()
if w+x+y+z != r1+r2:
    print(-1)
    exit()
else:
    print(w,x)
    print(y,z)
x=int(input())
for i in range (x):
    w,y,z=map(int,input().split())
    if abs(2*(w-y))<=w or abs(2*(w-y))<=y or abs(2*(w-y))<=z:
        print(-1)
    else:
        y=abs(w-y)
        if z>y:
            print(z-y)
        else:
            print(z+y)
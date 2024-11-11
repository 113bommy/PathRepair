t=int(input())
while t!=0:
    t-=1
    h,m=tuple(map(int,input().split()))
    print(1440-(h*60+m))
time=1440
for _ in range(int(input())):
    h,m=map(int,input().split())
    if h!=0 and m!=0:
        print(time-(h*60+m))
    else:
        print(0)
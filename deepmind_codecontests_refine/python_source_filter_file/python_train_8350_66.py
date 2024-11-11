x=int(input())
for i in range(0,x):
    h,m=list(map(int,input().split(" ")))
print((24*60)-(h*60+m))


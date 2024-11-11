try:
    n=int(input())
    for i in range(0,n):
        h,m=list(map(int,input().split(" ")))
        k=h*60+m
        print(1440-k)
except:
    pass
n=int(input())
for i in range(n):
    h,m=map(int,input().split())
    x=23-h
    y=60-m
    print(x*60+y)
t=int(input())
for p in range(t):
    h,m=map(int,input().split())
    a=23-h
    b=60-m
    print(a*60+b)
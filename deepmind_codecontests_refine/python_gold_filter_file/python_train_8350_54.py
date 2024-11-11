t=int(input())
for _ in range(t):
    h,m=map(int,input().split())
    print(24*60-(h*60+m))
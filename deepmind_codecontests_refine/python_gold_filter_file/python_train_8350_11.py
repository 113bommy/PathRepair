t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(1440-(a*60+b))
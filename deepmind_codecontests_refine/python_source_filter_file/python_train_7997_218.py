x,y=map(int,input().split())

if y%x==0 or x%y==0:
    print(-1)
else:
    print(x)
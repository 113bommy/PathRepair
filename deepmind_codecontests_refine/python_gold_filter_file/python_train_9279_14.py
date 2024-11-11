import sys
n,x,y=map(int,sys.stdin.readline().split())
if (y-n+1<1) or (y-n+1)**2+(n-1)<x:
    print(-1)
else:
    print(y-n+1)
    for i in range(n-1):
        print(1)
            
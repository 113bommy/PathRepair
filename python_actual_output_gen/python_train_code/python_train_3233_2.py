import sys
input = sys.stdin.readline

t=int(input())
for ll in range(t):
    n, x=map(int, input().split())
    m=0
    ma=0
    z=0
    for i in range(n):
        d, h=map(int, input().split())
        ma=max(d, ma)
        if ma>=x: print(1); z=1
        m=max(m, d-h)
    else: 
        if z==0:
            if m>0:
                print((x-ma+m-1)//m +1)
            else:
                print(-1)
            
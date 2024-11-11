n,m=map(int,input().split())
if m<=(n+1)//2:
    x=m*2-1
    print(x)
else:
    x=((m-(n+1)//2)*2)
    print(x)
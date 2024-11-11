for _ in range(int(input())):
    x1,y1,z1=map(int,input().split())
    x2,y2,z2=map(int,input().split())
    a=2*min(z1,x2)
    z1-=min(z1,x2)
    z2-=min(z2,x1)
    z2-=min(z2,z1)
    print(a-z2*2)
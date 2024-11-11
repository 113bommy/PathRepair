for _ in range(int(input())):
    l,r=map(int,input().split())
    if 2*l>r:
        print(-1)
    else:
        print(l,2*l)
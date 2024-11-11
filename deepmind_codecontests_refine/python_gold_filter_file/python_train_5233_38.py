for _ in range(int(input())):
    l,r=map(int,input().split())
    if (l*2)>r:
        print(-1,-1)
    else:
        print(l,l*2)
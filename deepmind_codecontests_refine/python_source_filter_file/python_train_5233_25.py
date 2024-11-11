for i in range(int(input())):
    l,r = map(int,input().split())
    if l+1 == r:
        print(-1,-1)
    else:
        print(l,r)
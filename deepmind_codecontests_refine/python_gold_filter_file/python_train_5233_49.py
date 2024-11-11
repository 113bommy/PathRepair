t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    if(l*2<=r):
        if(l==1):
            print(1, r)
        else:
            print(l, l*2)
    else:
        print(-1,-1)
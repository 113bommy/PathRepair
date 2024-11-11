for _ in range(int(input())):
    n,r = map(int,input().split())
    if n<r:
        print(1+(n*(n-1))//2)
    else:
        print((r*(r+1))//2)
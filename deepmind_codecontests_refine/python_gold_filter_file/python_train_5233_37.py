for _ in range(int(input())):
    # n = int(input())
    # s = input()
    l,r = map(int,input().split())
    # ar = list(map(int,input().split()))
    if r>=2*l:
        print(l,2*l)
    else:
        print(-1,-1)
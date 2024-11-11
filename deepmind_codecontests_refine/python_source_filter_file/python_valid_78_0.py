for _ in range(int(input())):
    l,r = map(int, input().split())
    z = (r+1)//2
    if z>=r: print(z-1)
    else: print(r%l)
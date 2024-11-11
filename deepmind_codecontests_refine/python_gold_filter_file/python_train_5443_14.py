for _ in range(int(input())):
    l,r = map(int,input().split())
    if r>=l*2:
        print("NO")
    else:
        print("YES")
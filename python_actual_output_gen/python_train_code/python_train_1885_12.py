for i in range(int(input())):
    l,r = map(int,input().split())
    if r%l == 0:
        print("NO")
    else:
        print("YES")
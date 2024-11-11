for i in range(int(input())):
    l,r = map(int,input().split())
    if r<l*2:
        print("YES")
    else:
        print("NO")
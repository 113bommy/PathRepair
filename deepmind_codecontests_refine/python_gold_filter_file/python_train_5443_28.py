for i in range(int(input())):
    l, r = map(int, input().split())
    if (2*l -1 < r):
        print("NO")
    else:
        print("YES")
for _ in range(int(input())):
    x, y = map(int, input().split())
    if x >= y:
        print("YES")
    else:
        if x == 1:
            print("NO")
        elif x == 2 and y == 3:
            print("YES")
        elif x == 3 and y > 3:
            print("NO")
        else:
            print("YES")
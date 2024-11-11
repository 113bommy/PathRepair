for i in range(int(input())):
    x = int(input())
    if 360 % (180-x) == 0:
        print("YES")
    else:
        print("NO")
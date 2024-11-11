t = int(input())
while t > 0:
    t -= 1
    c = int(input())
    if c == 3:
        print("NO")
    else:
        c -= 4
        if c % 4 == 0:
            print("YES")
        else:
            print("NO")

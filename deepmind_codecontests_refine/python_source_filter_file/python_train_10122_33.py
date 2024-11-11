t = int(input())

while t > 0:
    a, b = map(int, input().split())

    if a == b:
        print(0)
    
    if a > b:
        if (b - a) % 2 == 0:
            print(2)
        else:
            print(1)

    else:
        if (a - b) % 2 == 0:
            print(2)
        else:
            print(1)

    t -= 1

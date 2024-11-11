a1 = int(input())
for i1 in range(a1):
    arr = [int(x) for x in input().split()]
    a, b = arr[0], arr[1]
    if a == b:
        print(0)
    if a > b:
        if (a - b) % 2 == 0:
            print(1)
        else:
            print(2)
    else:
        if (b - a) % 2 == 1:
            print(1)
        else:
            print(2)

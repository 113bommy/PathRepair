for i in range(int(input())):
    a = input()
    if len(a) == 1:
        a1 = 1
    elif len(a) == 2:
        a1 = 3
    elif len(a) == 3:
        a1 = 6
    else:
        a1 = 10
    print(10 * (int(a[0]) - 1) + a1)
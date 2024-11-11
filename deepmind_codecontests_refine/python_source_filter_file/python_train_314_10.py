while(True):
    H, W = map(int, input().split())
    if(H == W == 0):
        break
    str = "#." * (W // 2 + 1)
    for i in range(H):
        if(i % 2 == 0):
            print(str[:-1:])
        else:
            print(str[1::])
    print()
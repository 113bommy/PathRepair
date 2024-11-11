while True:
    (H, W) = [int(i) for i in input().split()]
    if H == W == 0:
        break

    [print('#' * W) for d in range(W)]
    print()
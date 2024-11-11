while True:
    H, W = [int(x) for x in input().split()]
    if H == W == 0:
        break
    for i in range(H):
        print(''.join(['#' if i & j & 1 == 0 else '.' for j in range(W)]))
    print()
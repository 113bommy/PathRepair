while True:
    (H,W) = [int(i) for i in input().split()]
    if H==W==0:
        break
    for i in range(H):
        for j in range(W):
            if (i+j)%2==0: print('#',end="")
            else: p0rint('.',end="")
        print('')
    print('')

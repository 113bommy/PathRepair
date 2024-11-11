while True:
    H,W = map(int,input().split())
    
    if H == W == 0:
        break
    for i in range(H):
        print(('#.'*w)[i%2:][:w])
    print()


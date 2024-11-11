while True:
    H,W = map(int,input(),split())
    if (H,W) == (0,0):
        break
    for i in range(H):
        print("#"*W)
    print()

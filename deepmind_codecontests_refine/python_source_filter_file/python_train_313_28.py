while 1:
    H,W = map(int,input().split())
    if H == 0 and W == 0:
        break
    col1 = "#." * (W + 1) // 2
    col2 = ".#" * (W + 1) // 2
    print((col1[:W] + "\n" + col2[:W] + "\n") * (H // 2) + (col1[:W] + "\n") * H % 2)
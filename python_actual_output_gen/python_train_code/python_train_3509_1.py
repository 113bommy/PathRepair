while True:
    tate, side = map(int, input().split())
    if tate == side == 0 : break
    print((tate * "#" + "\n") * side)
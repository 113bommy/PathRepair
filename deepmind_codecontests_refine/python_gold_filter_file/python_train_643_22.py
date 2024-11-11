from sys import stdin

def input():
    return next(stdin)

def main():
    n, sx, sy = map(int,input().split())
    dc = [0] * 4
    for _ in range(n):
        x, y = map(int,input().split())
        if y < sy:
            dc[0] += 1
        elif y > sy:
            dc[2] += 1
        if x < sx:
            dc[3] += 1
        elif x > sx:
            dc[1] += 1
    best = 0
    besti = 0
    for i in range(4):
        if dc[i] > best:
            besti = i
            best = dc[i]
    if besti == 0:
        rx = sx
        ry = sy -1
    elif besti == 1:
        rx = sx + 1
        ry = sy
    elif besti == 2:
        rx = sx
        ry = sy + 1
    else:
        rx = sx - 1
        ry = sy
    print(best)
    print(rx, ry)
            



if __name__ == "__main__":
    main()
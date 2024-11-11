t = int(input())
while t:
    input()
    xa, ya = map(int, input().split())
    xb, yb = map(int, input().split())
    xf, yf = map(int, input().split())
    if xa == xb == xf and min(ya, yb) < yf and max(ya, yb) > yf:
        print(abs(xa-xb)+2)
    elif ya == yb == yf and min(xa,xb) < xf and max(xa,xb) > xf:
        print(abs(ya-yb)+2)
    else:
        print(abs(xa-xb) + abs(ya-yb))
    t-=1

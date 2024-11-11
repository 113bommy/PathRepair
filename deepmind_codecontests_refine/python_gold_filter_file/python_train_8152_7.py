n = int(input())
for xx in range(n):
    _ = input()
    xa, ya = map(int, input().split())
    xb, yb = map(int, input().split())
    xf, yf = map(int, input().split())
    if xa == xb:
        if xf == xa and (ya <= yf <= yb or yb <= yf <= ya):
            wyn = abs(ya-yb) + 2
        else:
            wyn = abs(ya-yb)
    elif ya == yb:
        if yf == ya and (xa <= xf <= xb or xb <= xf <= xa):
            wyn = abs(xa-xb) + 2
        else:
            wyn = abs(xa-xb)
    else:
        wyn = abs(xa - xb) + abs(ya - yb)
    print(wyn)

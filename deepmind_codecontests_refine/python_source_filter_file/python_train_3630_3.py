import math
def Wit(y,m,d):
    if m == 1 or m == 2:
        y -= 1
        m += 12
    e = math.floor((26 * (m + 1)) / 10)
    Y = y % 100
    C = math.floor(y / 100)
    f = math.floor(C / 4)
    g = math.floor(Y / 4)
    h = d + e + Y + f + g - 2 * C
    h = int(h % 7)
    return h
while True:

    y = 2004
    m,d = map(int,input().split())
    if m == 0 and d == 0:
        break
    You = Wit(y,m,d)
    if You == 1:
        print("Sunday")
    elif You == 2:
        print("Tuesday")
    elif You == 3:
        print("Monday")
    elif You == 4:
        print("Wednesday")
    elif You == 5:
        print("Thursday")
    elif You == 6:
        print("Friday")
    elif You == 0:
        print("Saturday")
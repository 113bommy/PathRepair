n = input().split()
a = int(n[1])
b = int(n[2])
n = int(n[0])
t = [int(i) for i in input().split()]
lost = 0
bm = 2 * b
b2 = b
b1 = 0
for i in t:
    if i == 1:
        if a > 0:
            a -= 1
        else:
            if bm > 0:
                if b2 > 0:
                    b2 -= 1
                    b1 += 1
                    bm -= 1
                else:
                    b1 -= 1
                    bm -= 1
            else:
                lost += 1
    else:
        if b2 > 0:
            b2 -= 1
            bm -= 2
        else:
            lost += 2
    print(lost)
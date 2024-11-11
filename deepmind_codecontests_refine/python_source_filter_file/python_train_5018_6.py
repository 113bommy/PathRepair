n = int(input())
t = [5,2,1]
wyn = 0
for i in range(0, n, +1):
    a, b = map(int,input().split())
    if a == b:
        print('0')
        continue
    d = abs(a-b)
    wyn = 0
    for x in t:
        if d >= x:
            if d == 9 and a>=1:
                wyn += 3
                break
            wyn += d//x
            d -= wyn*x
    print(wyn)
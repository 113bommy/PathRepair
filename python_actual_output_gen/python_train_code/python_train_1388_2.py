hh, mm = map(int, input().split())
h, d, c, n = map(int, input().split())
if hh > 20 or (hh == 20 and mm > 0):
    print((h // n + (h % n != 0)) * c * 0.8)
else:
    if mm != 0:
        m = 60 - mm
        h -= 1
    else:
        m = 0
    ex = h + ((20 - hh) * 60 + m) * d
    print(min((ex // n + (ex % n != 0)) * c * 0.8, (h // n + (h % n != 0)) * c))
def isTshirt(s):
    i = int(s/50) % 475
    for _ in range(25):
        i = (i * 96 + 42) % 475
        if p == 26 + i:
            return True
    return False


def calcAns(p, x, y):
    s = x
    while s >= y:
        if isTshirt(s):
            return 0
        s = s-50

    i = 1
    s = x
    while True:
        s = s + 50
        i = i + 1
        if s >= y and isTshirt(s):
            return int(i/2)


p, x, y = map(int, input().split())
print(calcAns(p, x, y))

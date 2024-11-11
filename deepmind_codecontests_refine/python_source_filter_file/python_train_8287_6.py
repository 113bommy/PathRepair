n = int(input())
a = int(input())
b = int(input())
c = int(input())

score = 0
r = True
o = False
e = False


for i in range(n - 1):
    if r is True:
        if a > b:
            score += b
            o = True
            r = False
        else:
            score += a
            o = True
            r = False

    elif o is True:
        if a > c:
            score += c
            e = True
            o = False
        else:
            score += a
            r = True
            o = False

    elif e is True:
        if b > c:
            score += c
            o = True
            e = False
        else:
            score += a
            r = True
            e = False

print(score)

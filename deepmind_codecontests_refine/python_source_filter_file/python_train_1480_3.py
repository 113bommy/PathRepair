def getAns(a, b, c, d):
    if a > b:
        if (a - b == 1 and c == 0 and d == 0):
            print("YES")
            li = []
            li.append(0)
            for i in range(b):
                li.append(1)
                li.append(0)
            print(*li)
            return
        print("NO")
        return
    elif c > d:
        if (c - d == 1 and a == 0 and b == 0):
            print("YES")
            li = []
            li.append(3)
            for i in range(c):
                li.append(2)
                li.append(3)
            print(*li)
            return
        print("NO")
        return
    ogB = b
    ogC = c
    b -= a
    c -= d
    li = []
    diff = abs(b - c)
    if diff <= 1:
        print("YES")
        for i in range(d):
            li.append(3)
            li.append(2)
        for i in range(a):
            li.append(1)
            li.append(0)
        if b > c:
            for i in range(c):
                li.append(1)
                li.append(2)
            li.append(1)
        else:
            for i in range(b):
                li.append(1)
                li.append(2)
            if c > b:
                li.insert(0, 2)
        print(*li)
    else:
        print("NO")

asdf = [int(x) for x in input().split(' ')]
getAns(asdf[0], asdf[1], asdf[2], asdf[3])
    

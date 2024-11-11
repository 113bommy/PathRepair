import sys
input = sys.stdin.buffer.readline

q = int(input())
for _ in range(q):
    n = int(input())
    L = [0]*n
    for i in range(n):
        x, y, f1, f2, f3, f4 = map(int, input().split())
        L[i] = (x, y, f1, f2, f3, f4)

    minX = -10**5
    maxX = 10**5
    minY = -10**5
    maxY = 10**5
    for i in range(n):
        x, y, f1, f2, f3, f4 = L[i]
        if f1 == 0:
            if maxX < x:
                print(0)
                break
            else:
                minX = max(minX, x)
        if f2 == 0:
            if minY > y:
                print(0)
                break
            else:
                maxY = min(maxY, y)
        if f3 == 0:
            if minX > x:
                print(0)
                break
            else:
                maxX = min(maxX, x)
        if f1 == 0:
            if maxY < y:
                print(0)
                break
            else:
                minY = max(minY, y)
    else:
        if maxX >= minX and maxY >= minY:
            print(1, maxX, maxY)
        else:
            print(0)

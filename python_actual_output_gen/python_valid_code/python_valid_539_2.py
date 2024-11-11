tt = int(input())
while tt > 0:
    tt -= 1
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    c -= 1
    dist = abs(b-a)
    if max(a, b) > 2 * dist:
        print(-1)
    elif c > 2 * dist:
        print(-1)
    else:
        print((c + dist) % (2*dist) + 1)
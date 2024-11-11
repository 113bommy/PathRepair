
f = int(input())
h, m = map(list, input().split(":"))
h = list(map(int, h))
m = list(map(int, m))

if f == 12:
    if h[0] == 0 and h[1] == 0:
        h[1] = 1
    elif h[0] == 1:
        if h[1] > 2:
            h[1] = 0
    elif h[0] > 1:
        if h[1] == 0:
            h[0] = 1
        else:
            h[0] = 0

if f == 24:
    if h[0] > 2:
        h[0] = 0
    if h[0] == 2:
        if h[1] > 4:
            h[1] = 0

if m[0] > 5:
    m[0] = 0


print(''.join(map(str, h)) + ":" + ''.join(map(str, m)))

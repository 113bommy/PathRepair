s = list(map(int, input().split(':')))
t = list(map(int, input().split(':')))

p = [0, 0]
if s[0] - t[0] < 0:
    p[0] = 24 - (t[0] - s[0])
else:
    p[0] = s[0] - t[0]

if s[1] - t[1] < 0:
    p[1] = 60 - (t[1] - s[1])
    if p[0] == 0:
        p[0] = 23
    else:
        p[0] -= 1
else:
    p[1] = s[1] - t[1]

if p[0] < 10:
    print('0', p[0], sep = '', end = ':')
else:
    print(p[0], end = ':')
if p[1] < 10:
    print('0', p[1], sep = '')
else:
    print(p[1])

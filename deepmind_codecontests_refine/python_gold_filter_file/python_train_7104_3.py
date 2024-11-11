import sys

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    s = ''
    if a > 0:
        for i in range(a + 1):
            s += "0"
    if a == 0 and b > 0:
        for i in range(b + 1):
            if i % 2 == 0:
                s += "1"
            else:
                s += "0"
    else:
        for i in range(b):
            if i % 2 == 0:
                s += "1"
            else:
                s += "0"
    if c > 0 and len(s) > 0 and s[-1] == '0':
        s = s[:-1]
        if (s[0] == '0'):
            s = "1" + s
        else:
            s = "0" + s
    if not s:
        for i in range(c + 1):
            s += "1"
    else:
        for i in range(c):
            s += "1"
    print(s)
    
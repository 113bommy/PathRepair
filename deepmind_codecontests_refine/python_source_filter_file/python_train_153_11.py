import sys
a = 0
b = 0
for m in sys.stdin:
    if m[0] == '+':
        a = a + 1
    elif m[0] == '-':
        a = a - 1
    else:
        b = b + (a*(len(m) - m.find(':')))
print(b)



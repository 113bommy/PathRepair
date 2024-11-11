import sys

l = 0;
strs = [];
for s in sys.stdin:
    s1 = s.strip()
    l = max(l, len(s1))
    strs.append(s1)

print('*' * (l + 2))

i = 0
for s in strs:
    print('*', end='')
    a = 0; b = 0;
    val = l - len(s)
    if(val % 2 == 0):
        a = val // 2
        b = a
    else:
        if(i == 0):
            a = val // 2
            b = a + 1
        else:
            b = val // 2
            a = b + 1
        i = 1 - i
    print(' ' * a, end='')
    print(s, end='')
    print(' ' * b, end='')
    print('*')

print('*' * (l + 2))

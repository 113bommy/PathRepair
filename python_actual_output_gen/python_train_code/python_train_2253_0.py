import sys
s = [i.strip() for i in sys.stdin]
l = max(map(len, s))
print('*'*(l+2))
is_left = True
for i in s:
    t, a = divmod(l - len(i), 2)
    la = ra = ' ' * t
    if a == 1:
        if is_left:
            la += ' '
        else:
            ra += ' '
        is_left = not is_left
    print('*' + la + i + ra + '*')
print('*'*(l+2))
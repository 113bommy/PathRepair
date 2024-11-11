import re
r, c = map(int, input().split(' '))

shape = []
for _ in range(r):
    row = input()
    if not shape:
        m = re.search('[.]*([X]+)[.]*', row)
        if m:
            sp = m.span(1)
            shape = m.group(1)
    else:
        m1 = re.search('[.]*([X]+)[.]*', row)
        if m1:
            sp1 = m1.span()
            if shape != m.group(1) or sp[0] != sp1[0] or sp[1] != sp1[1]:
                print('NO')
                exit()
print('YES')


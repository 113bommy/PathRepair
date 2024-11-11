end = {'q': '"', 'w': ' '}
l, cur, st = [], [], 'n'
for ch in input():
    if st in 'wq':
        if ch == end[st]:
            l.append(''.join(cur))
            cur = []
            st = 'n'
        else:
            cur.append(ch)
    elif ch == '"':
        st = 'q'
    elif ch != ' ':
        st = 'w'
        cur.append(ch)
for lx in l:
    print('<', lx, '>', sep='')

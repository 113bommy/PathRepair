t = int(input())
for _ in range(t):
    s = str(input())
    l = []
    u = []
    d = []
    for i, c in enumerate(s):
        if c.islower():
            l.append(i)
        elif c.isupper():
            u.append(i)
        else:
            d.append(i)
    s = list(s)
    if l and u and d:
        pass
    elif not l and u and d:
        if len(u) > len(d):
            s[u[0]] = 'a'
        else:
            s[d[0]] = 'a'
    elif l and not u and d:
        if len(l) > len(d):
            s[l[0]] = 'A'
        else:
            s[d[0]] = 'A'
    elif l and u and not d:
        if len(l) > len(u):
            s[l[0]] = '1'
        else:
            s[l[0]] = '1'
    elif l and not u and not d:
        s[l[0]] = 'A'
        s[l[1]] = '1'
    elif not l and u and not d:
        s[u[0]] = 'a'
        s[u[1]] = '1'
    elif not l and not u and d:
        s[d[0]] = 'a'
        s[d[1]] = 'A'
    print(''.join(s))

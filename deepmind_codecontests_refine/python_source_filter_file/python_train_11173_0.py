n, m = map(int, input().split())
n += 1

s = [[] for i in range(n)]
for j in range(2, n, 2): s[j] = [2]
for i in range(3, n, 2):
    if s[i]: continue
    for j in range(i, n, i): s[j].append(i)

p, d, r = {}, set(), [''] * m
for j in range(m):
    t = input()
    i = int(t[2: ])
    if t[0] == '+':
        if i in d:
            r[j] = 'Already On'
            continue
        for q in s[i]:
            if q in p:
                r[j] = 'Conflict with ' + str(p[q])
                break
        else:
            r[j] = 'Success'
            d.add(i)
            for q in s[i]: p[q] = i
    else:
        if i in d:
            r[j] = 'Success'
            for q in s[i]: p.pop(q)
            d.remove(i)
        else: r[j] = 'Already Off'

print('\n'.join(r))

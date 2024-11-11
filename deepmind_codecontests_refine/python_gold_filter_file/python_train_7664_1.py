n = int(input())
p = {}

for _ in range(n):
    r = input().split()
    f, _, n = r[0], r[1], r[2:]
    if not p.get(f):
        p[f] = set()

    p[f].update(n)

s = ''

for k, v in p.items():
    r = []
    for e, i in enumerate(v):
        for e1, j in enumerate(v):
            if j.endswith(i) and e != e1:
                break
        else:
            r.append(i)

    s += '{} {} {}\n'.format(k, len(r), ' '.join(r))

print(s.count('\n'), s, sep='\n')

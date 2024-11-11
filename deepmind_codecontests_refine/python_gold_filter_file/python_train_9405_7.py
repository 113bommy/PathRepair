import sys
def log(*a): print(*a, file=sys.stderr)
def line(): return sys.stdin.readline().split()
def iline(): return [int(i) for i in line()]

n = iline()[0]
c = [line()[0] for _ in range(n)]

for i in c:
    if 'C' in i:
        ci = i.index('C')
        if ci > 0 and str(i[ci-1]).isnumeric():
            rs = int(i[1:ci])
            cs = int(i[ci+1:]) - 1
            ca = []
            while cs >= 0:
                ca.append(chr(cs % 26 + ord('A')))
                cs = cs // 26 - 1
            print('{}{}'.format(''.join(reversed(ca)), rs))
            continue
    ni = 1
    while not str(i[ni]).isnumeric():
        ni += 1
    cs = i[:ni]
    rs = i[ni:]
    cn = 0
    for p, d in enumerate(reversed(cs)):
        cn += (26 ** p) * (ord(d) - ord('A') + 1)
    print('R{}C{}'.format(rs, cn))


def is_rect(es):
    v = set([])

    for e in es:
        if not ((e[0] == e[2]) or (e[1] == e[3])):
            return False
        v.add((e[0], e[1]))
        v.add((e[2], e[3]))

    if len(v) != 4:
        return False

    xs = set([])
    ys = set([])
    for vi in v:
        xs.add(vi[0])
        ys.add(vi[1])

    if len(xs) != 2 or len(ys) != 2:
        return False

    t = b = r = l = False
    for e in es:
        t = t or (e[1] == e[3] and e[0] != e[2] and e[1] == max(ys))
        b = b or (e[1] == e[3] and e[0] != e[2] and e[1] == min(ys))
        r = r or (e[0] == e[2] and e[1] != e[3] and e[1] == max(ys))
        l = l or (e[0] == e[2] and e[1] != e[3] and e[1] == min(ys))

    return t and b and l and r


e1 = list(map(int, input().split(' ')))
e2 = list(map(int, input().split(' ')))
e3 = list(map(int, input().split(' ')))
e4 = list(map(int, input().split(' ')))

if is_rect((e1, e2, e3, e4)):
    print("YES")
else:
    print("NO")

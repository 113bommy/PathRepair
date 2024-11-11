from collections import defaultdict

def solve(n, a, b, xs):
    group = [None] * n
    id_ = {x: i for i, x in enumerate(xs)}
    if a == b:
        for x in xs:
            if a - x not in id_:
                return False
        group = [0] * n
    else:
        for i, x in enumerate(xs):
            if group[i] is not None:
                continue
            y = a - x
            z = b - x
            f1 = y in id_ and group[id_[y]] is None
            f2 = z in id_ and group[id_[z]] is None
            if f1 + f2 == 0:
                return False
            elif f1 + f2 == 1:
                g = int(f2)
                # End of link
                link = []
                t = a if f1 else b
                while x in id_:
                    link.append(x)
                    x = t - x
                    if x + x == t:
                        break
                    t = a + b - t
                # print(link)
                if len(link) % 2 == 0:
                    for i, x in enumerate(link):
                        group[id_[x]] = g
                elif link[0] * 2 == (b, a)[g]:
                    for i, x in enumerate(link):
                        group[id_[x]] = 1 - g
                elif link[-1] * 2 == (a, b)[g]:
                    for i, x in enumerate(link):
                        group[id_[x]] = g
                else:
                    # Found invalid link, answer is "NO"
                    return False

    return group

n, a, b = map(int, input().split())
xs = list(map(int, input().split()))
group = solve(n, a, b, xs)
if isinstance(group, list):
    print('YES')
    print(' '.join(map(str, group)))
else:
    print('NO')

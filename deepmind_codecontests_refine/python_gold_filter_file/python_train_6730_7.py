n = int(input())
x = [int(xx) for xx in input().split()]

x = sorted(x)
x = [str(xx) for xx in x]
m = dict()
for e in x:
    if e in m:
        m[e] += 1
    else:
        m[e] = 1

if len(m) == 1:
    print(n)
    print(' '.join(x))

if len(m) == 2:
    if int(x[-1]) - int(x[0]) == 1:
        print(n)
        print(' '.join(x))
    else:
        pair = min(m[x[0]], m[x[-1]])
        print(n - 2 * pair)
        middle = (int(x[0]) + int(x[-1])) // 2
        middle = str(middle)
        y = [x[0] for i in range(m[x[0]] - pair)] + [x[-1] for i in range(m[x[-1]] - pair)] + \
            [middle for i in range(2 * pair)]
        print(' '.join(y))
if len(m) == 3:
    middle = (int(x[0]) + int(x[-1])) // 2
    middle = str(middle)
    pair = min(m[x[0]], m[x[-1]])
    if pair > m[middle] // 2:
        print(n - 2 * pair)
        y = [x[0] for i in range(m[x[0]] - pair)] + [x[-1] for i in range(m[x[-1]] - pair)] + \
            [middle for i in range(2 * pair)] + [middle for i in range(m[middle])]
        print(' '.join(y))
    else:
        r = (m[middle] // 2)
        print(n - 2 * r)
        y = [x[0] for i in range(m[x[0]])] + [x[-1] for i in range(m[x[-1]])] + [x[0] for i in range(r)] + \
            [x[-1] for i in range(r)] + [middle for i in range(m[middle] % 2)]
        print(' '.join(y))

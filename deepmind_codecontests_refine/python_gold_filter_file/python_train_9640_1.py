n = int(input())
a, b = map(int, input().split())
if a == b: print('1 ' * a + '2 ' * b)
else:
    t = [[] for i in range(6)]
    for i, j in enumerate(map(int, input().split())): t[j].append(i)
    if b < a:
        t = t[1] + t[2] + t[3] + t[4] + t[5]
        t.reverse()
        p = ['1'] * n
        for i in range(b): p[t[i]] = '2'
        print(' '.join(p))
    else:
        t = t[5] + t[4] + t[3] + t[2] + t[1]
        p = ['2'] * n
        for i in range(a): p[t[i]] = '1'
        print(' '.join(p))
q, w = map(int, input().split())
h = [[i for i in input()] for j in range(q)]
t = False
for i in range(1, q - 1):
    for j in range(1, w - 1):
        if h[i][j] == '*' and h[i][j + 1] == '*' and h[i][j - 1] == '*' and h[i + 1][j] == '*' and \
                h[i - 1][j] == '*' and not t:
            t = True
            g = '*'
            p = j
            while g == '*' and p + 1 < w:
                p += 1
                g = h[i][p]
                h[i][p] = '.'
            g = '*'
            p = j
            while g == '*' and p - 1 > w:
                p -= 1
                g = h[i][p]
                h[i][p] = '.'
            g = '*'
            p = i
            while g == '*' and p + 1 < q:
                p += 1
                g = h[p][j]
                h[p][j] = '.'
            g = '*'
            p = i
            while g == '*' and p - 1 > q:
                p -= 1
                g = h[p][j]
                h[p][j] = '.'
            h[i][j] = '.'
            h[i][j + 1] = '.'
            h[i][j - 1] = '.'
            h[i + 1][j] = '.'
            h[i - 1][j] = '.'

if t:
    for i in range(q):
        for j in range(w):
            if h[i][j] == '*':
                t = False
                break
        if not t:
            print("NO")
            break
    else:
        print("YES")
else:
    print("NO")

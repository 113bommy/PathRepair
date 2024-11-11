a, b = map(int, input().split())
if a == b == 0: print('Yes')
else:
    ans = 'No'
    t = input()
    p, h = [0] * len(t), [0, 0]
    d = {'L': (-1, 0), 'R': (1, 0), 'D': (-1, 1), 'U': (1, 1)}
    for i, c in enumerate(t):
        j, k = d[c]
        h[k] += j
        p[i] = (h[0], h[1])
    if h[0] == h[1] == 0:
        if (a, b) in p: ans = 'Yes'
    elif h[0]:      
        for x, y in p:
            if (a - x) * h[1] == (b - y) * h[0] and (a - x) % h[0] == 0 and (a - x) * h[0] > 0:
                ans = 'Yes'
                break
    else:      
        for x, y in p:
            if a == x and (b - y) % h[1] == 0 and (b - y) * h[1] > 0:
                ans = 'Yes'
                break
    print(ans)
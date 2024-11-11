def col(x, y):
    return (x + y) % 2 == 1


t = int(input())
for z in range(t):
    w, b = map(int, input().split())
    if b > w:
        sx = 3
        sy = 2
    else:
        sx = 2
        sy = 2
    x = sx
    y = sy
    if max(b, w) > min(b, w) * 2 + 1 + min(b, w):
        print('NO')
    else:
        print('YES')
        mn = min(w, b)
        mx = max(w, b)
        for i in range(mn):
            c = col(x, y)
            if c:
                b -= 1
            else:
                w -= 1
            print(x, y)
            y += 1
            c = col(x, y)
            if c:
                b -= 1
            else:
                w -= 1            
            print(x, y)
            y += 1
        #print(w, b, '???')
        if not w and not b:
            continue
        c = col(x, y)
        if c:
            b -= 1
        else:
            w -= 1
        print(x, y)
        mx = max(b, w)
        x = sx
        y = sy + 1
        #print(w, b, '!!!')
        while mx > 0:
            if mx > 1:
                print(x + 1, y)
                print(x - 1, y)
                y += 2
                mx -= 2
            else:
                print(x + 1, y)
                mx -= 1
        
        
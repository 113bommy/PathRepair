num_t = int(input())

for _ in range(num_t):
    input()
    path = input()

    diff = float('inf')
    l = r = None
    last = {(0, 0): -1}

    x, y = 0, 0
    for i, m in enumerate(path):
        if m == 'L':
            x -= 1
        elif m == 'R':
            x += 1
        elif m == 'U':
            y += 1
        else:
            y -= 1
        
        if (x, y) in last:
            last_i = last[(x, y)]
            if i - last_i < diff:
                l = last_i
                r = i
                diff = i - last_i
        last[(x, y)] = i
    
    if l == None:
        print (-1)
    else:
        l += 1
        r += 1
        print (l + 1, r)

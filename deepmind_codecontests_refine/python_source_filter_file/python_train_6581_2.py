T = int(input())
for cs in range(T):
    n = int(input())
    s = input()

    li = [(0,0,-1)]
    x, y, i = 0, 0, 0
    for c in s:
        if (c == 'L'):
            x -= 1
        elif (c == 'R'):
            x += 1
        elif (c == 'U'):
            y += 1
        else:
            y -= 1
        li.append((x,y,i))
        i += 1
    li.sort()

    prev = li[0]
    l, r, mn = -1, -1, 1000000
    for t in li[1:]:
        if (t[0] != prev[0] or t[1] != prev[1]):
            prev = t
            continue
        diff = t[2] - prev[2]
        if (diff < mn):
            l, r, mn = prev[2]+1, t[2], diff
        t = prev
    
    if (l == -1):
        print(-1)
    else:
        print("{} {}".format(l+1,r+1))

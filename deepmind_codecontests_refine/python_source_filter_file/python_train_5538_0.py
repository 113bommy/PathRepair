def mp():
    return map(int, input().split())

t = int(input())
for tt in range(t):
    h, n = mp()
    a = list(mp()) + [0]
    
    ans = 0
    last = h
    i = 1
    while i < n:
        #print('last =', last, '; i =', i, '; a[i] =', a[i], '; a[i + 1] =', a[i + 1], '; ans =', ans)
        last = min(last, a[i] + 1)
        if a[i + 1] == last - 2:
            last = a[i + 1]
            i += 1
        else:
            ans += 1
            last -= 2
            i += 1
    print(ans)
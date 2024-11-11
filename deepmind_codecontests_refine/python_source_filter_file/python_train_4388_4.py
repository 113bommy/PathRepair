n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(0)
else:
    l = []
    r = []
    for i in range(n):
        if i % 2 == 0:
            l.append(a[i])
        else:
            r.append(a[i])
    
    #print(l, r)
    tl = [0] * len(l) + [0]
    tr = [0] * len(r) + [0]
    tl[0] = l[0]
    tr[0] = r[0]
    for i in range(1, len(l)):
        tl[i] = tl[i - 1] + l[i]
    for i in range(len(r)):
        tr[i] = tr[i - 1] + r[i]
    #print(tl, tr)
    
    cnt = 0
    for i in range(len(r)):
        if tl[i - 1] + (tr[-2] - tr[i - 1]) == tr[i - 1] + (tl[-2] - tl[i]):
            cnt += 1
    if len(l) > len(r) and tl[-3] == tr[-2]:
        cnt += 1
        
    for i in range(len(r)):
        if i == 1:
            pass#print(tr[i - 1], (tl[-2] - tl[i]), tl[i - 1], (tr[-2] - tr[i]))
        if tr[i - 1] + (tl[-2] - tl[i]) == tl[i] + (tr[-2] - tr[i]):
            cnt += 1
            
    print(cnt)
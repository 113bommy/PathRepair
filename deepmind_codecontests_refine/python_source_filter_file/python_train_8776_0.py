for _ in range(int(input())):
    print('YES')
    n, h, k = map(int, input().split())
    s = map(int, input().split())
    ar = [[] for i in range(h)]
    dc = sorted(enumerate(s), key= lambda x:(x[1],x[0]), reverse= True)
    # dc = sorted(enumerate(s))
    # print('dc:',dc)

    x = 0
    c = 0
 
    while  c < n:
        if x % 2 == 0:
            for i in range(h):
                ar[i].append(dc[c][0])
                c += 1
                if c == n:
                    break
            

        else:
            for i in range(h-1, -1, -1):
                ar[i].append(dc[c][0])
                c += 1
                if c == n:
                    break
        x += 1
    l = [0 for i in range(n)]
    print(ar)
    for i in range(h):
        for j in range(len(ar[i])):
            l[ar[i][j]] = i+1
    
    print(*l)

            





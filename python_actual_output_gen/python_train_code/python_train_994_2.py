for _ in range (int(input())):
    n, m = map(int, input().split())
    l = []
    for i in range(n):
        l.append(list(map(int, input().split())))
    rows = [0] * n
    cols = [0] * m
    pos = []
    for i in range(n):
        for j in range(m):
            if l[i][j] == 1:
                rows[i] == 1
                cols[j] == 1
            else:
                pos.append([i, j])
    
    c = 0;
    for i in pos:
        if rows[i[0]] == 0 and cols[i[1]] == 0:
            c += 1
            rows[i[0]] = 1
            cols[i[1]] = 1
    
    if c % 2 == 0:
        print("Vivek")
    else:
        print("Ashish")
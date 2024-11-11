while True:
    n = int(input())
    if n == 0:
        break
    s = []
    for i in range(n):
        s.append([int(i) for i in input().split()])
    
    p, q, r, c = [int(i) for i in input().split()]

    possible = []
    for i in range(n):
        if (s[i][1] <= p) & (s[i][2] <= q) & (s[i][3] <= r) & ((4 * (s[i][1] + s[i][3]) + 9 * s[i][2]) <= c):
            possible.append(s[i][0])

    if possible == []:
        print('NA')
    else:
        for i in possible:
            print(i)
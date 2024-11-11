t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    ans = ''
    count = 0
    robot_cord = [0, 0]
    for i in range(n):
        a.append(list(map(int, input().split())))
    need_y = 0
    while robot_cord[0] < 100 and count < n:
        for i in range(n):
            if a[i][0] == robot_cord[0]:
                if robot_cord[1] < a[i][1]:
                    count += 1
                if a[i][1] > need_y:
                    need_y = a[i][1]
        if need_y > robot_cord[1]:
            ans += 'U' * (need_y - robot_cord[1])
            robot_cord[1] = need_y
        if count < n:
            robot_cord[0] += 1
            ans += 'R'
            if robot_cord in a:
                count += 1
    if count == n:
        print('YES')
        print(ans)
    else:
        print('NO')

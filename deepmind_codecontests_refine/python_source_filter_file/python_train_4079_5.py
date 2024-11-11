from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    n = int(input())
    r = [list(map(int, input().split())) for _ in range(n)]
    pos = [[r[0][0], r[0][1]], [r[0][0], r[0][1]]]
    if r[0][2]:
        pos[0][0] = -10000
    if r[0][4]:
        pos[1][0] = 10000
    if r[0][3]:
        pos[1][1] = 10000
    if r[0][5]:
        pos[0][1] = -10000
    for robot in r[1:]:
        robot_pos = [robot[0], robot[1]], [robot[0], robot[1]]
        if robot[2]:
            robot_pos[0][0] = -10000
        if robot[4]:
            robot_pos[1][0] = 10000
        if robot[3]:
            robot_pos[1][1] = 10000
        if robot[5]:
            robot_pos[0][1] = -10000
        if robot_pos[1][0] < pos[0][0] or robot_pos[0][0] > pos[1][0] or robot_pos[1][1] < pos[0][1] or robot_pos[0][1] > pos[1][1]:
            print(0)
            break
        else:
            pos[0][0] = max(robot_pos[0][0], pos[0][0])
            pos[0][1] = max(robot_pos[0][1], pos[0][1])
            pos[1][0] = min(robot_pos[1][0], pos[1][0])
            pos[1][1] = min(robot_pos[1][1], pos[1][1])
    else:
        print(1, pos[0][0], pos[0][1])
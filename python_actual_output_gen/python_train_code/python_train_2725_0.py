n = int(input())
pt = []
for i in range(n):
    a, b = input().split()
    pt.append((int(a), int(b)))
cnt = 0
for i in range(n):
    up, dwn, lft, rt = 0, 0, 0, 0
    for j in range(n):
        if i == j:
            continue
        if pt[i][0] == pt[j][0] and pt[i][1] < pt[j][1]:
            rt = 1
        if pt[i][0] == pt[j][0] and pt[i][1] < pt[j][1]:
            lft = 1
        if pt[i][0] > pt[j][0] and pt[i][1] == pt[j][1]:
            dwn = 1
        if pt[i][0] < pt[j][0] and pt[i][1] == pt[j][1]:
            up = 1
    if up and dwn and lft and rt:
        cnt += 1
print(cnt)
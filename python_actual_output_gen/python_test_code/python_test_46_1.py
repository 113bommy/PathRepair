n = int(input())
a = [[0, 0] for i in range(n)]
for i in range(n):
    x, y = map(int, input().split())
    a[i][0] = x
    a[i][1] = y
b = [[0, 0] for i in range(n)]
for i in range(n):
    x, y = map(int, input().split())
    b[i][0] = x
    b[i][1] = y
ans = dict()
for i in range(n):
    for j in range(n):
        try:
            ans[(a[i][0] + b[j][0], a[i][1] + b[j][1])] += 1
        except:
            ans[(a[i][0] + b[j][0], a[i][1] + b[j][1])] = 1
for i in ans:
    if ans[i] >= 2:
        print(i[0], i[1])
        exit(0)

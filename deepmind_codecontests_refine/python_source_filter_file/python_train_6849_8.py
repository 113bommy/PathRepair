h, w, k = map(int, input().split())
s = [input() for i in range(h)]

cnt = 0
ans = [[-1]*w for i in range(h)]

for i in range(h):
    cnt += 1
    ans[i][0] = cnt
    ichigo_cnt = 0

    for j in range(w):
        ans[i][j] = cnt
        if s[i][j] == "#":
            if ichigo_cnt != 0:
                cnt += 1
                ans[i][j] = cnt
            ichigo_cnt += 1

    if ichigo_cnt == 0:
        for j in range(w):
            ans[i][j] = -1
        cnt -= 1

for i in range(0,h-1):
    for j in range(w):
        if ans[i][j] == -1:
            ans[i][j] = ans[i+1][j]

for i in range(1,h):
    for j in range(w):
        if ans[i][j] == -1:
            ans[i][j] = ans[i-1][j]

for i in ans:
    print(*i)

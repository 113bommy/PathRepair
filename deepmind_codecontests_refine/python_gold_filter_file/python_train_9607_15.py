def f(c):
    if c == '1':
        return '0'
    else:
        return '1'


t = int(input())
for _ in range(t):
    h, w = map(int, input().split())
    s = [list(input()) for _ in range(h)]
    ans = []
    for i in range(h - 1):
        for j in range(0, w, 2):
            if j == w - 1:
                j -= 1
            if s[i][j] == s[i][j + 1] == '0':
                continue
            elif s[i][j] == s[i][j + 1] == '1':
                s[i][j] = '0'
                s[i][j + 1] = '0'
                s[i + 1][j] = f(s[i + 1][j])
                ans.append((i, j, i, j + 1, i + 1, j))
            elif s[i][j] == '1':
                s[i][j] = '0'
                s[i + 1][j] = f(s[i + 1][j])
                s[i + 1][j + 1] = f(s[i + 1][j + 1])
                ans.append((i, j, i + 1, j, i + 1, j + 1))
            else:
                s[i][j + 1] = '0'
                s[i + 1][j] = f(s[i + 1][j])
                s[i + 1][j + 1] = f(s[i + 1][j + 1])
                ans.append((i, j + 1, i + 1, j, i + 1, j + 1))
    for j in range(0, w, 2):
        if j == w - 1:
            j -= 1
        if s[-1][j] == s[-1][j + 1] == '0':
            continue
        elif s[-1][j] == s[-1][j + 1] == '1':
            s[-1][j] = '0'
            s[-1][j + 1] = '0'
            ans.append((h - 1, j, h - 2, j, h - 2, j + 1))
            ans.append((h - 1, j + 1, h - 2, j, h - 2, j + 1))
        elif s[-1][j] == '1':
            s[-1][j] = '0'
            ans.append((h - 1, j, h - 2, j, h - 2, j + 1))
            ans.append((h - 2, j, h - 1, j, h - 1, j + 1))
            ans.append((h - 2, j + 1, h - 1, j, h - 1, j + 1))
        else:
            s[-1][j + 1] = '0'
            ans.append((h - 1, j + 1, h - 2, j, h - 2, j + 1))
            ans.append((h - 2, j, h - 1, j, h - 1, j + 1))
            ans.append((h - 2, j + 1, h - 1, j, h - 1, j + 1))
    print(len(ans))
    for row in ans:
        print(*map(lambda x: x+1, row))

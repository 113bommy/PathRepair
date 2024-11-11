r, c = map(int, input().split())
s = []
error = False
for i in range(r):
    s.append(input())
    s[i] = s[i].replace('.','D')
    if s[i].count('SW') >= 1 or s[i].count('WS') >= 1:
        error = True
if error == True:
    print('NO')
elif r >= 2:
    for i in range(r):
        for j in range(c):
            if s[i][j] == 'S':
                if 0 < i-1 and i+1 < r:
                    if s[i+1][j] == 'W':
                        error = True
                    if s[i-1][j] == 'W':
                        error = True
                elif i == 0:
                    if s[i+1][j] == 'W':
                        error = True
                elif i == c-1:
                    if s[-1][j] == 'W':
                        error = True
    if error == True:
        print('NO')
    else:
        print('YES')
        for i in range(r):
            print(*s[i], sep='')
else:
    print('YES')
    print(*s, sep='')

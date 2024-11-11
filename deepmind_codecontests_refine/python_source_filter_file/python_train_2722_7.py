n = int(input())
s = []
for i in range(n):
    a = list(input())
    s.append(a)
count = 0
for i in range(n-2):
    for j in range(n-2):
        if s[i][j+1] == s[i+1][j] == s[i+1][j+1] == s[i+1][j+2] == s[i+2][j+1] == '.':
            s[i][j+1] = '#'
            s[i+1][j] = '#'
            s[i+1][j+1] = '#'
            s[i+1][j+2] = '#'
            s[i+2][j+1] = '#'
for i in range(n):
    for j in range(n):
        if s[i][j] == '.':
            count += 1
            break
    if count > 0:
        print('N0')
        break
else:
    print('YES')

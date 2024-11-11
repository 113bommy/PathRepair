h, w = map(int, input().split())

s = [input() for _ in range(h)]

ans = 'Yes'

for i in range(1, h):
    for j in range(1, w):
        if s[i][j] == '#' and s[i-1][j] == '.' and s[i+1][j] == '.' and s[i][j-1] == '.' and s[i][j+1] == '.':
            ans = 'No'

print(ans)

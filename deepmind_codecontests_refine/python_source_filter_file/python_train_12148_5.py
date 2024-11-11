
n, m = map(int,input().split())

mp = []

for i in range(n):
    mp.append(input())


x = 0

while x < n:
    y = 0
    while y < m:
        # print('xx', x, y, mp[x][y])
        if mp[x][y] == '*':
            y += 1
            continue
        num = 0
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                tx = x + dx
                ty = y + dy
                if tx < 0 or tx >= n or ty < 0 or ty >= m:
                    continue
                if mp[tx][ty] == '*':
                    # print(tx, ty, mp[tx][ty])
                    num += 1
        if mp[x][y] == '.': mp[x] =mp[x][:y]  + '0' +mp[x][y:]
        # print(num,mp[x][y])
        if num != int(mp[x][y]):
            print('NO')
            quit(0)
        y += 1
    x += 1

print('YES')